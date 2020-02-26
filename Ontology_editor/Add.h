#ifndef ADD_H
#define ADD_H

#include <QMainWindow>

namespace Ui {
class Add;
}

class Add : public QMainWindow
{
    Q_OBJECT

public:
    QString ontPath;
    explicit Add(QWidget *parent = nullptr,QString ontPath = "null");
    ~Add();

private:
    Ui::Add *ui;
private slots:
 void addNewArg();
 void addNewFunc();
 void homePage();
 void newRUC();
 void addMode();

};

#endif // ADD_H
