#ifndef DATABASESCONFIGURATION_H
#define DATABASESCONFIGURATION_H

#include <QDialog>

namespace Ui {
class databasesconfiguration;
}

class databasesconfiguration : public QDialog
{
    Q_OBJECT

public:
    explicit databasesconfiguration(QWidget *parent = 0);
    ~databasesconfiguration();

private slots:


    void on_CON_Quit_pushbutton_clicked();

    void on_CON_Clear_pushbutton_clicked();

    void on_CON_Apply_pushbutton_clicked();

private:
    Ui::databasesconfiguration *ui;
};

#endif // DATABASESCONFIGURATION_H
