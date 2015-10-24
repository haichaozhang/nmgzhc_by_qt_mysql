#include "databasesconfiguration.h"
#include "ui_databasesconfiguration.h"
#include"QMessageBox"


extern int thepanduan ;
extern QString MySQLHostNme;//服务器名称
extern int MySQLPort;//端口号码
extern QString MySQLUserName;//服务器用户名
extern QString MySQLPassword ;//服务器密码
extern QString MySQLDatabaseName;//服务器数据库名称


databasesconfiguration::databasesconfiguration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::databasesconfiguration)
{
    ui->setupUi(this);
    ui->CON_ServerName->setText(MySQLHostNme);
    ui->CON_PortNumber->setText(QString::number(MySQLPort,10));
    ui->CON_databasesUserName->setText(MySQLUserName);
    ui->CON_databasesUserPassword->setText(MySQLPassword);
    ui->CON_databasesName->setText(MySQLDatabaseName);
}

databasesconfiguration::~databasesconfiguration()
{
    delete ui;
}


void databasesconfiguration::on_CON_Quit_pushbutton_clicked()
{
    this->close();
}

void databasesconfiguration::on_CON_Clear_pushbutton_clicked()
{
    ui->CON_ServerName->clear();
    ui->CON_PortNumber->clear();
    ui->CON_databasesUserName->clear();
    ui->CON_databasesUserPassword->clear();
    ui->CON_databasesName->clear();
    ui->CON_ServerName->setFocus();
}

void databasesconfiguration::on_CON_Apply_pushbutton_clicked()
{
    MySQLHostNme = ui->CON_ServerName->text();//服务器名称
    MySQLPort = ui->CON_PortNumber->text().toInt();//端口号码
    MySQLUserName = ui->CON_databasesUserName->text();//服务器用户名
    MySQLPassword = ui->CON_databasesUserPassword->text();//服务器密码
    MySQLDatabaseName = ui->CON_databasesName->text();//服务器数据库名称
    QMessageBox::warning(this,tr("提示"),tr("更新成功"),QMessageBox::Ok);
}
