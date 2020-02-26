#include "start.h"
#include "Add.h"
#include "ui_start.h"
#include "edit.h"

Start::Start(QWidget *parent, QString ontPath) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    this->ontPath = ontPath;
    ui->ontologyPathLabel->setText(ontPath.split("/").last());
    QPushButton *m_button1 = ui->addRUC;
    QPushButton *m_button2 = ui->editRUC;
    connect(m_button1, SIGNAL (clicked()), this, SLOT (addRUC()));
    connect(m_button2, SIGNAL (clicked()), this, SLOT (editRUC()));
}
void Start::addRUC()
{
    Add *add = new Add(nullptr,ontPath);
    add->show();
    hide();
}
void Start::editRUC()
{
    Ontology *ontlg = new Ontology({});
    Edit *edit = new Edit(nullptr,ontPath,ontlg);
    edit->show();
    hide();
}

Start::~Start()
{
    delete ui;
}
