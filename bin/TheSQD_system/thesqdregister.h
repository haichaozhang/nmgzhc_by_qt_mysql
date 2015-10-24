#ifndef THESQDREGISTER_H
#define THESQDREGISTER_H

#include <QMainWindow>

namespace Ui {
class TheSQDregister;
}

class TheSQDregister : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheSQDregister(QWidget *parent = 0);
    ~TheSQDregister();

private slots:
    void on_REG_pushButton_Quit_clicked();

    void on_REG_pushButton_Clear_clicked();

    void on_REG_pushButton_Enter_clicked();



    void on_REG_pushButton_Database_clicked();

private:
    Ui::TheSQDregister *ui;
};

#endif // THESQDREGISTER_H
