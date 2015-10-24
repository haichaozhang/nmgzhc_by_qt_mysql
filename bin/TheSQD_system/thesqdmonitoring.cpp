#include "thesqdmonitoring.h"
#include "ui_thesqdmonitoring.h"
#include"thesqdregister.h"
#include"connectiondatabases.h"
#include<QSqlQuery>
#include<QMessageBox>
#include"theworkermanage.h"
#include"thesqdusermanage.h"
#include"theserialporttest.h"
#include"theequipmentmangage.h"
#include"theworkshopmangage.h"
#include"theworkersearch.h"
#include"theequipmentsearch.h"
#include"QTime"
#include"QTimer"



extern int thepanduan ;//身份的判断
extern QString MySQLHostNme;//服务器名称
extern int MySQLPort;//端口号码
extern QString MySQLUserName;//服务器用户名
extern QString MySQLPassword ;//服务器密码
extern QString MySQLDatabaseName;//服务器数据库名称



TheSQDMonitoring::TheSQDMonitoring(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheSQDMonitoring)
{
    ui->setupUi(this);
    QTimer *SQDMtime=new QTimer(this);
    connect(SQDMtime,SIGNAL(timeout()),this,SLOT(SQDMtimeupdate()));
    SQDMtime->start(1000);
    SQDMSearchSerialModel=new QSqlRelationalTableModel(this);
    SQDMSearchSerialModel->setTable("serialporttest");
    SQDMSearchSerialModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    SQDMSearchSerialModel->select();
    SQDMshowdatabase();

}

TheSQDMonitoring::~TheSQDMonitoring()
{
    delete ui;
}

void TheSQDMonitoring::on_quitsysterms_ation_triggered()//退出系统
{
    this->close();
}

void TheSQDMonitoring::on_comebackregister_action_triggered()//打开登录界面
{
    connectiondatabases::close();
    TheSQDregister*openTheSQDregister=new TheSQDregister;
    openTheSQDregister->show();
    this->hide();

}

void TheSQDMonitoring::on_theworker_action_triggered()//菜单栏打开员工信息管理界面
{
    if(thepanduan)
    {
        theworkermanage*openTheSQDregister=new theworkermanage;
        openTheSQDregister->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("您不是管理员，没有权限管理数据库"),QMessageBox::Ok);
    }
}

void TheSQDMonitoring::on_SQDM_Clear_pushbutton_clicked()//清空搜索框
{
    ui->SQDM_SearchDetail_lineedit->clear();
    ui->SQDM_SearchDetail_lineedit->setFocus();
}

void TheSQDMonitoring::on_theuserandadmin_action_triggered()//打开登录用户管理界面
{
    TheSQDUsermanage*openTheSQDUsermanage= new TheSQDUsermanage;
    openTheSQDUsermanage->show();
    this->hide();
}

void TheSQDMonitoring::on_SerialPort_Action_triggered()//打开串口调试界面
{
    TheSerialPortTest*openTheSerialPortTest= new TheSerialPortTest;
    openTheSerialPortTest->show();
    this->hide();
}

void TheSQDMonitoring::on_theequipment_action_triggered()//打开设备信息管理界面
{
    theequipmentmangage*opentheequipmentmangage= new theequipmentmangage;
    opentheequipmentmangage->show();
    this->hide();
}

void TheSQDMonitoring::on_workershop_action_triggered()//打开车间信息管理界面
{

     theworkshopmangage*opentheworkshopmangage= new theworkshopmangage;
     opentheworkshopmangage->show();
     this->hide();
}

void TheSQDMonitoring::on_searchworker_action_triggered()//打开员工信息查询界面
{
    theworkersearch*opentheworkersearch= new theworkersearch;
    opentheworkersearch->show();
    this->hide();
}

void TheSQDMonitoring::on_searchequipment_action_triggered()//打开设备查询界面
{
    theequipmentsearch*opentheequipmentsearch= new theequipmentsearch;
    opentheequipmentsearch->show();
    this->hide();
}

void TheSQDMonitoring::SQDMshowdatabase()//显示数据库内容
{

    ui->SQDM_ShowDetail_tableview->setModel(SQDMSearchSerialModel);
    this->SQDMSearchSerialModel->removeColumn(this->SQDMSearchSerialModel->fieldIndex("idserialtest"));
    this->SQDMSearchSerialModel->removeColumn(this->SQDMSearchSerialModel->fieldIndex("Thrtestmessage6"));
    this->SQDMSearchSerialModel->setHeaderData(0,Qt::Horizontal,tr("记录日期"));
    this->SQDMSearchSerialModel->setHeaderData(1,Qt::Horizontal,tr("设备ID"));
    this->SQDMSearchSerialModel->setHeaderData(2,Qt::Horizontal,tr("员工RFID"));
    this->SQDMSearchSerialModel->setHeaderData(3,Qt::Horizontal,tr("环境温度"));
    this->SQDMSearchSerialModel->setHeaderData(4,Qt::Horizontal,tr("环境湿度"));
    this->SQDMSearchSerialModel->setHeaderData(5,Qt::Horizontal,tr("电流参数"));
    this->SQDMSearchSerialModel->setHeaderData(6,Qt::Horizontal,tr("计数器个数"));
}

void TheSQDMonitoring::on_SQDM_Search_pushbutton_clicked()//查看存储的信息
{
    //QSqlQuery query;
    QString SQDMsearchthing=ui->SQDM_SearchDetail_lineedit->text();
    if(SQDMsearchthing.isEmpty())
    {
        SQDMSearchSerialModel->setFilter(QObject::tr("ThrtestEquipmentID like '%1'").arg("%"));
        SQDMSearchSerialModel->select();
        SQDMshowdatabase();
    }
    else if(ui->SQDM_SearchOption_combobox->currentText()=="设备ID")
    {
        SQDMSearchSerialModel->setFilter(QObject::tr("ThrtestEquipmentID like '%1'").arg((QString)("%")+SQDMsearchthing+(QString)("%")));
        SQDMSearchSerialModel->select();
        SQDMshowdatabase();
    }
    else if(ui->SQDM_SearchOption_combobox->currentText()=="员工RFID")
    {
        SQDMSearchSerialModel->setFilter(QObject::tr("Thrtestmessage1 like '%1'").arg((QString)("%")+SQDMsearchthing+(QString)("%")));
        SQDMSearchSerialModel->select();
        SQDMshowdatabase();
    }

}

void TheSQDMonitoring::SQDMtimeupdate()
{

    QTime time = QTime::currentTime();
    QString timetext=time.toString("hh:mm");
    //if((time.second()%2)==0) timetext[2]=" ";
    ui->SQDM_CurrentTime_lable->setText(timetext);
    //SQDMshowdatabase();
    SQDMupdateSQL();

}

 void TheSQDMonitoring::SQDMupdateSQL()
 {
     QSqlQuery query;
     query.clear();
     //query.prepare("select LAST_INSERT_ID() from serialporttest");
     query.prepare("select MAX(idserialtest) from serialporttest");
     query.exec();
     if(query.next())
     {
         QString IDVAL=query.value(0).toString();
         query.clear();
         query.prepare("select * from serialporttest where idserialtest=:idserialtest");
         query.bindValue(":idserialtest",IDVAL);
         query.exec();
         if(query.next())
         {
             ui->SQDM_EquipmentID_lable->setText(query.value(2).toString());
             ui->SQDM_EquipmentProductionNumber_LCDNumber->display(query.value(7).toString());
             ui->SQDM_EquipmentTemperture_QwtTherm->setValue(query.value(4).toFloat());
             ui->SQDM_EquipmentHumidity_QwtTherm->setValue(query.value(5).toFloat());
             ui->SQDM_Equipmentelectric_LCDNumber->display(abs((query.value(6).toFloat()-512)/1024*5*100));
         }

     }
 }

 void TheSQDMonitoring::SQDMshowqwtplot()//界面上的qwtplot控件显示
 {
     //曲线
      QwtPlotCurve * curve;
     //X轴
     double time[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     //Y轴
     double val[10] = {3, 5, 8, 7, 2, 0, 7, 9, 1};
     //实例化
     curve = new QwtPlotCurve("Acc_X");
     //加载数据

     curve->setSamples(time, val, 10);
     //加到plot，plot由IDE创建
     ui->SQDM_Equipmentmessage_QwtPlot
 }

void TheSQDMonitoring::on_SQDM_Pitchup_pushbutton_clicked()//查看选中设备的信息
{

}
