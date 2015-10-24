#include "theequipmentmangage.h"
#include "ui_theequipmentmangage.h"
#include"thesqdmonitoring.h"

theequipmentmangage::theequipmentmangage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::theequipmentmangage)
{
    ui->setupUi(this);
}

theequipmentmangage::~theequipmentmangage()
{
    delete ui;
}

void theequipmentmangage::on_TEM_Comback_pushButton_clicked()
{
    TheSQDMonitoring*openTheSQDMonitoring=new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->hide();
}
