#include "theworkersearch.h"
#include "ui_theworkersearch.h"
#include"thesqdmonitoring.h"

theworkersearch::theworkersearch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::theworkersearch)
{
    ui->setupUi(this);
}

theworkersearch::~theworkersearch()
{
    delete ui;
}

void theworkersearch::on_TWS_Comback_pushButton_clicked()
{
    TheSQDMonitoring*openTheSQDMonitoring=new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->hide();
}
