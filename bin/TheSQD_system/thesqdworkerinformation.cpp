#include "thesqdworkerinformation.h"
#include "ui_thesqdworkerinformation.h"

TheSQDWorkerInformation::TheSQDWorkerInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheSQDWorkerInformation)
{
    ui->setupUi(this);
}

TheSQDWorkerInformation::~TheSQDWorkerInformation()
{
    delete ui;
}
