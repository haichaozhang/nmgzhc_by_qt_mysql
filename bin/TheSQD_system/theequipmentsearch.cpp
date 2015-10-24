#include "theequipmentsearch.h"
#include "ui_theequipmentsearch.h"
#include"thesqdmonitoring.h"

theequipmentsearch::theequipmentsearch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::theequipmentsearch)
{
    ui->setupUi(this);
}

theequipmentsearch::~theequipmentsearch()
{
    delete ui;
}

void theequipmentsearch::on_TES_Comback_pushButton_clicked()
{
    TheSQDMonitoring*openTheSQDMonitoring=new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->hide();
}
