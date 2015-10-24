#include "thesqdregister.h"
#include "ui_thesqdregister.h"
#include"connectiondatabases.h"
#include<QSqlQuery>
#include<QMessageBox>
#include"thesqdmonitoring.h"
#include"databasesconfiguration.h"

extern int thepanduan ;//打开数据库的身份判别

TheSQDregister::TheSQDregister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheSQDregister)
{
    ui->setupUi(this);
}

TheSQDregister::~TheSQDregister()
{
    delete ui;
}


void TheSQDregister::on_REG_pushButton_Quit_clicked()//退出系统
{
    this->close();
}

void TheSQDregister::on_REG_pushButton_Clear_clicked()//重置登录名和用户密码
{
    ui->REG_lineEdit_MameID->clear();
    ui->REG_lineEdit_Password->clear();
    ui->REG_lineEdit_MameID->setFocus();
}

void TheSQDregister::on_REG_pushButton_Enter_clicked()//进行用户与登录的验证
{
    if(!connectiondatabases::open())//进行打开数据库操作
    {
        QMessageBox::warning(this,tr("提示"),tr("打开数据库失败，请配置数据库"),QMessageBox::Ok);
        return ;        
    }
    else
    {
        QSqlQuery query;
        if (ui->REG_radioButton_Admin->isChecked())//以管理员身份验证
        {
            if(ui->REG_lineEdit_MameID->text().isEmpty()||ui->REG_lineEdit_Password->text().isEmpty())
            {
                QMessageBox::information(this,tr("提示"),tr("用户名或密码为空"),QMessageBox::Ok);
                return;                
            }
            else
            {

                QString REG_NameID = ui->REG_lineEdit_MameID->text().trimmed();
                QString REG_Password = ui->REG_lineEdit_Password->text().trimmed();

                query.prepare("select * from  kintadmin where TheAdminID=:TheAdminID and TheAdminIDpassword=:TheAdminIDpassword");
                query.bindValue(":TheAdminID",REG_NameID);
                query.bindValue(":TheAdminIDpassword",REG_Password);
                query.exec();
                if(query.next())
                {
                    thepanduan = 1;
                    TheSQDMonitoring*openTheSQDMonitoring = new TheSQDMonitoring;
                    openTheSQDMonitoring->show();
                    this->hide();
                    qDebug("Connect to theadmin");
                    return;

                 }
                 else
                 {
                    QMessageBox::warning(this,tr("提示"),tr("请输入正确的用户名和密码!"),QMessageBox::Ok);
                    ui->REG_lineEdit_MameID->clear();
                    ui->REG_lineEdit_Password->clear();
                    ui->REG_lineEdit_MameID->setFocus();
                 }
            }
        }
        else if(ui->REG_radioButton_user->isChecked())//以一般身份用户验证
        {
            if(ui->REG_lineEdit_MameID->text().isEmpty()||ui->REG_lineEdit_Password->text().isEmpty())
            {
                QMessageBox::information(this,tr("提示"),tr("用户名或密码为空"),QMessageBox::Ok);
                return;
            }
            else
            {
                QString REG_NameID = ui->REG_lineEdit_MameID->text().trimmed();
                QString REG_Password = ui->REG_lineEdit_Password->text().trimmed();
                query.prepare("select *from  kintauser where TheUserID=:TheUserID and TheUserIDpassword=:TheUserIDpassword");
                query.bindValue(":TheUserID",REG_NameID);
                query.bindValue(":TheUserIDpassword",REG_Password);
                query.exec();
                if(query.next())//判断数据库包括此人后
                {
                    thepanduan = 0;
                    TheSQDMonitoring*openTheSQDMonitoring = new TheSQDMonitoring;
                    openTheSQDMonitoring->show();
                    this->hide();
                    qDebug("Connect to theuser");
                    return;

                }
                else
                {
                    QMessageBox::warning(this,tr("提示"),tr("请输入正确的用户名和密码!"),QMessageBox::Ok);
                    ui->REG_lineEdit_MameID->clear();
                    ui->REG_lineEdit_Password->clear();
                    ui->REG_lineEdit_MameID->setFocus();
                }
            }
        }
        else
        {
            QMessageBox::warning(this,tr("提示"),tr("您没有选择登录类型!"),QMessageBox::Ok);
        }
    }

}

void TheSQDregister::on_REG_pushButton_Database_clicked()//打开配置数据库的界面
{
    databasesconfiguration*opendatabasesconfiguration=new databasesconfiguration;
    opendatabasesconfiguration->show();
    return;
}
