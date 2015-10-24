#include "thesqdusermanage.h"
#include "ui_thesqdusermanage.h"
#include"thesqdmonitoring.h"

TheSQDUsermanage::TheSQDUsermanage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheSQDUsermanage)
{
    ui->setupUi(this);
}

TheSQDUsermanage::~TheSQDUsermanage()
{
    delete ui;
}

void TheSQDUsermanage::on_TUM_comback_pushbutton_clicked()//返回主界面
{
    TheSQDMonitoring*openTheSQDMonitoring= new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->close();
}
