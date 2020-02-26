#include "choose.h"
#include "start.h"
#include "ui_choose.h"

#include <QFileDialog>
#include <QPushButton>
#include <ui_start.h>

Choose::Choose(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
    QPushButton *m_button1 = ui->openExistOntologyButton;


    connect(m_button1, SIGNAL (clicked()), this, SLOT (openExistOntology()));
}

void Choose::openExistOntology()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.xml");
    Start *start = new Start(nullptr,str);
    start->show();
    hide();

}

Choose::~Choose()
{
    delete ui;
}
