#include "Add.h"
#include "start.h"
#include "tpp.h"
#include "ui_Add.h"
#include "xml_parse_generate.h"
#include <optional>

#include <QFile>
#include <QTextStream>
#include <QRadioButton>
#include <QXmlStreamReader>
#include <QDebug>
#include <QCheckBox>

using namespace std;
int argcount = 1;
int funccount= 1;
TPP *tpp = new TPP();
Add::Add(QWidget *parent, QString ontPath) :
    QMainWindow(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);   
    this->ontPath = ontPath;
    QComboBox *box = ui->ChooseTPPComboBox;
    QPushButton *m_button1 = ui->addArgButton;
    QPushButton *m_button2 = ui->addFuncButton;
    QPushButton *m_button3 = ui->backButton;
    QPushButton *m_button4 = ui->addButton;

    QCheckBox *argCheckBox = ui->argIsRuntimecheckBox1;
    argCheckBox->hide();

    QCheckBox *funcCheckBox = ui->funcIsRuntimecheckBox1;
    funcCheckBox->hide();


    connect(m_button1, SIGNAL (clicked()), this, SLOT (addNewArg()));
    connect(m_button2, SIGNAL (clicked()), this, SLOT (addNewFunc()));
    connect(m_button3, SIGNAL (clicked()), this, SLOT (homePage()));
    connect(m_button4, SIGNAL (clicked()), this, SLOT (newRUC())); 
    connect(box,SIGNAL (currentIndexChanged(QString)),this, SLOT (addMode()));

    box->addItem(tpp->getTPP(TPP::TPPs::TPP_Static));
    box->addItem(tpp->getTPP(TPP::TPPs::TPP_Dinamic));
    box->addItem(tpp->getTPP(TPP::TPPs::TPP_Tutoring));
}

void Add::addMode()
{
    QGridLayout *layout = ui->gridLayout;
    if(ui->ChooseTPPComboBox->currentText() == tpp->getTPP(TPP::TPPs::TPP_Tutoring))
    {
        foreach(QObject *const obj,layout->parent()->children())
        {
            if(obj->objectName().contains("argIsRuntimecheckBox") || obj->objectName().contains("funcIsRuntimecheckBox"))
            {
                qobject_cast<QWidget*>(obj)->setVisible(true);
            }
        }
    }
    else
    {
        foreach(QObject *const obj,layout->parent()->children())
        {
            if(obj->objectName().contains("argIsRuntimecheckBox") || obj->objectName().contains("funcIsRuntimecheckBox"))
            {
                qobject_cast<QWidget*>(obj)->setVisible(false);
            }
        }
    }
}
void Add::addNewArg()
{
    QGridLayout *layout = ui->gridLayout;
    QLineEdit *editline  = new QLineEdit();
    QCheckBox *cbutton = new QCheckBox();
    layout->addWidget(editline,2+argcount,1);
    layout->parent()->children().last()->setObjectName("RUCArgumentInput"+QString().setNum(argcount+1));
    layout->addWidget(cbutton,2+argcount,2);
    layout->parent()->children().last()->setProperty("text","Is Runtime");
    layout->parent()->children().last()->setObjectName("argIsRuntimecheckBox"+QString().setNum(funccount+1));
    if(ui->ChooseTPPComboBox->currentText() != "tutoring")
    {
        cbutton->setVisible(false);
    }
    argcount++;
}
void Add::addNewFunc()
{
    QGridLayout *layout = ui->gridLayout;
    QLineEdit *editline  = new QLineEdit();
    QCheckBox *cbutton = new QCheckBox();
    layout->addWidget(editline,2+funccount,5);
    layout->parent()->children().last()->setObjectName("RUCFunctionInput"+QString().setNum(funccount+1));
    layout->addWidget(cbutton,2+funccount,6);
    layout->parent()->children().last()->setProperty("text","Is Runtime");
    layout->parent()->children().last()->setObjectName("funcIsRuntimecheckBox"+QString().setNum(funccount+1));
    if(ui->ChooseTPPComboBox->currentText() != "tutoring")
    {
        cbutton->setVisible(false);
    }
    funccount++;
}
void Add::homePage()
{
    Start *start = new Start(nullptr,ontPath);
    start->show();
    hide();
}
void Add::newRUC()
{
    XML_parse_generate xml;
    Node *node1 = new Node(ui->RUCNameInput->property("text").toString(),{},{},{},tpp->getObject(ui->ChooseTPPComboBox->currentText()));
    QGridLayout *layout = ui->gridLayout;
    foreach(QObject *const obj1,layout->parent()->children())
    {
        foreach(QObject *const obj2,layout->parent()->children())
        {
            if(obj1->objectName().contains("RUCArgumentInput") && obj2->objectName().contains("argIsRuntimecheckBox") && obj1->objectName().right(1) == obj2->objectName().right(1))
            {
                node1->add_arg(obj2->property("checked").toBool(),obj1->property("text").toString());
            }
            else if(obj1->objectName().contains("RUCFunctionInput") && obj2->objectName().contains("funcIsRuntimecheckBox") && obj1->objectName().right(1) == obj2->objectName().right(1))
            {
                node1->add_func(obj2->property("checked").toBool(),obj1->property("text").toString());
            }
        }
    }
    QDomDocument domDoc;
    QFile existxmlFile(ontPath);
    if(existxmlFile.open(QIODevice::ReadWrite)) {
           if(domDoc.setContent(&existxmlFile)) {
               QDomElement domElement= domDoc.documentElement();
               Ontology *ontlg = xml.traverseNode(domElement);
               ontlg->addNode(node1);
              domDoc.appendChild(domElement);
               QDomElement contact1 =
               xml.contact(domDoc,node1->node_name,node1->runtime_func_arr,node1->runtime_arg_arr,node1->runtime_link_arr,node1->designtime_link_arr, node1->designtime_func_arr,node1->designtime_arg_arr,node1->tpp);
               domElement.appendChild(contact1);
               existxmlFile.resize(0);
               QTextStream(&existxmlFile) << domDoc.toString();
           }
           existxmlFile.close();
       }
}

Add::~Add()
{
    delete ui;
}
