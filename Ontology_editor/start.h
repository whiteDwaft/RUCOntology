#ifndef START_H
#define START_H

#include <QMainWindow>

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    QString ontPath;
    explicit Start(QWidget *parent = nullptr,QString ontpath = "null");
    ~Start();

private:
    Ui::Start *ui;
private slots:
 void addRUC();
 void editRUC();
};

#endif // START_H
