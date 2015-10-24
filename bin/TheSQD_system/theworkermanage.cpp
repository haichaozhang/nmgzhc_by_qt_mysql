#include "theworkermanage.h"
#include "ui_theworkermanage.h"
#include"thesqdmonitoring.h"

theworkermanage::theworkermanage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::theworkermanage)
{
    ui->setupUi(this);
}

theworkermanage::~theworkermanage()
{
    delete ui;
}

void theworkermanage::on_WM_Insert_WorkerInfor_Comback_pushButton_clicked()//返回主界面即监控界面
{
    TheSQDMonitoring*openTheSQDMonitoring= new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->close();
}

void theworkermanage::on_WM_Repair_comback_pushButton_clicked()//返回主界面即监控界面
{
    TheSQDMonitoring*openTheSQDMonitoring= new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->close();
}
