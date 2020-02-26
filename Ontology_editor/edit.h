#ifndef EDIT_H
#define EDIT_H

#include "ontology.h"

#include <QMainWindow>

namespace Ui {
class Edit;
}

class Edit : public QMainWindow
{
    Q_OBJECT

public:
    QString ontpath;
    Ontology* ontlg;
    explicit Edit(QWidget *parent = nullptr,QString ontpath = "",Ontology *ontlg = nullptr);
    ~Edit();

private:
    Ui::Edit *ui;
private slots:
 void chooseDUC();
};

#endif // EDIT_H
