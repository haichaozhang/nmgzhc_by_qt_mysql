#ifndef THEWORKERMANAGE_H
#define THEWORKERMANAGE_H

#include <QDialog>

namespace Ui {
class theworkermanage;
}

class theworkermanage : public QDialog
{
    Q_OBJECT

public:
    explicit theworkermanage(QWidget *parent = 0);
    ~theworkermanage();

private slots:
    void on_WM_Insert_WorkerInfor_Comback_pushButton_clicked();

    void on_WM_Repair_comback_pushButton_clicked();

private:
    Ui::theworkermanage *ui;
};

#endif // THEWORKERMANAGE_H
