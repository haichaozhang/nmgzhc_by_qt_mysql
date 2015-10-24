#include "theworkshopmangage.h"
#include "ui_theworkshopmangage.h"
#include"thesqdmonitoring.h"

theworkshopmangage::theworkshopmangage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::theworkshopmangage)
{
    ui->setupUi(this);
}

theworkshopmangage::~theworkshopmangage()
{
    delete ui;
}

void theworkshopmangage::on_TWM_Comback_pushButton_clicked()
{
    TheSQDMonitoring*openTheSQDMonitoring=new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->hide();
}
