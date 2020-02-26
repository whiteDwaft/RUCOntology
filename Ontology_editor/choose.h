#ifndef CHOOSE_H
#define CHOOSE_H

#include <QMainWindow>

namespace Ui {
class Choose;
}

class Choose : public QMainWindow
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = nullptr);
    ~Choose();

private:
    Ui::Choose *ui;
private slots:
void openExistOntology();
};


#endif // CHOOSE_H
