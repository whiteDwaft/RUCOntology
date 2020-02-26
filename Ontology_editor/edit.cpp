#include "edit.h"
#include "ontology.h"
#include "ui_edit.h"
#include "xml_parse_generate.h"

#include <QDomDocument>
#include <QFile>

Edit::Edit(QWidget *parent,QString ontpath, Ontology *ontlg) :
    QMainWindow(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    this->ontpath = ontpath;
    this->ontlg = ontlg;

    QDomDocument domDoc;
    XML_parse_generate xml;
    QComboBox *box1 = ui->chooseRUCComboBox;
    connect(box1,SIGNAL (currentIndexChanged(QString)),this, SLOT (chooseDUC()));
    QFile existxmlFile(ontpath);
    if(existxmlFile.open(QIODevice::ReadWrite)) {
           if(domDoc.setContent(&existxmlFile)) {
               QDomElement domElement= domDoc.documentElement();
               this->ontlg = xml.traverseNode(domElement);
           }
           existxmlFile.close();
    }
    for(int i = 1; i < this->ontlg->node_arr1.size();i++)
    {
         box1->addItem(this->ontlg->node_arr1[i]->node_name);
    }
    connect(box1,SIGNAL (currentIndexChanged(QString)),this, SLOT (chooseDUC()));

}
void Edit::chooseDUC()
{
    QLineEdit *name = ui->RUCNameInput;
    for(int i = 1; i < this->ontlg->node_arr1.size();i++)
    {
        if(this->ontlg->node_arr1[i]->node_name == ui->chooseRUCComboBox->currentText())
        {
            name->setText(this->ontlg->node_arr1[i]->node_name);
//            foreach(QString node;this->ontlg->node_arr1[i]->fun)
        }
    }
//    name->setText(ui->chooseRUCComboBox->currentText());


}

Edit::~Edit()
{
    delete ui;
}
