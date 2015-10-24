#include "theserialporttest.h"
#include "ui_theserialporttest.h"
#include"thesqdmonitoring.h"
#include"qwt_thermo.h"
#include"qwt_dial.h"
#include <qwt_dial_needle.h>




TheSerialPortTest::TheSerialPortTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheSerialPortTest)
{
    ui->setupUi(this);
    showthedatabase();
    theqwtshow();
    /*
    禁用窗口上的部分按钮
    */
    ui->SPT_One_ClearReceiveMessage_pushButton->setEnabled(false);
    ui->SPT_One_CloseSerialPort_pushButton->setEnabled(false);
    ui->SPT_One_ClearSendMessage_pushButton->setEnabled(false);
    ui->SPT_Some_CloseDebug_pushButton->setEnabled(false);
    ui->SPT_Some_ClearReceiveMessage_pushButton->setEnabled(false);
    ui->SPT_Some_ClearSendMessage_pushButton->setEnabled(false);
    ui->SPT_One_SendMessage_pushButton->setEnabled(false);
    ui->SPT_Some_refreshDatabases_pushButton->setEnabled(false);
    ui->SPT_Some_SendMessage_pushButton->setEnabled(false);
    //自动获取串口号码
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
     {
         QSerialPort serial;
         serial.setPort(info);
         if (serial.open(QIODevice::ReadWrite))
         {
             ui->SPT_One_SerialCOM_comboBox->addItem(info.portName());
             serial.close();
         }
     }
    TheSerialPort = new QSerialPort();

}

TheSerialPortTest::~TheSerialPortTest()
{
    delete ui;
}

void TheSerialPortTest::on_SPT_Comback_pushButton_clicked()//返回监控主界面
{
    TheSQDMonitoring*openTheSQDMonitoring=new TheSQDMonitoring;
    openTheSQDMonitoring->show();
    this->hide();

}

void TheSerialPortTest::on_SPT_One_OpenSerialPort_pushButton_clicked()//单一调试中的打开串口
{
    TheSerialPortTest::readfromserialport();
    connect(TheSerialPort,SIGNAL(readyRead()),this,SLOT(Thereaduart()));
    ui->SPT_One_CloseSerialPort_pushButton->setEnabled(true);
    ui->SPT_One_ClearSendMessage_pushButton->setEnabled(true);
    ui->SPT_One_ClearReceiveMessage_pushButton->setEnabled(true);
    ui->SPT_One_Baud_comboBox->setEnabled(false);
    ui->SPT_One_SerialCOM_comboBox->setEnabled(false);
    ui->SPT_One_Verify_comboBox->setEnabled(false);
    ui->SPT_One_Stop_comboBox->setEnabled(false);
    ui->SPT_One_SendMessage_pushButton->setEnabled(true);
}
void TheSerialPortTest::readfromserialport()//打开串口函数
{
    TheSerialPort->setPortName(ui->SPT_One_SerialCOM_comboBox->currentText());//设置COM口
    TheSerialPort->open(QIODevice::ReadWrite);//打开串口
    TheSerialPort->setBaudRate(ui->SPT_One_Baud_comboBox->currentText().toInt());//获取波特率
    TheSerialPort->setDataBits(QSerialPort::Data8);//数据位
    if(ui->SPT_One_Verify_comboBox->currentText()==tr("无校验"))
    {
        TheSerialPort->setParity(QSerialPort::NoParity);
    }
    else if (ui->SPT_One_Verify_comboBox->currentText()==tr("奇校验"))
    {
        TheSerialPort->setParity(QSerialPort::OddParity);
    }
    else if (ui->SPT_One_Verify_comboBox->currentText()==tr("偶校验"))
    {
        TheSerialPort->setParity(QSerialPort::EvenParity);
    }
    if(ui->SPT_One_Stop_comboBox->currentText()==tr("1"))
    {
        TheSerialPort->setStopBits(QSerialPort::OneStop);//停止位
    }
    else if(ui->SPT_One_Stop_comboBox->currentText()==tr("1.5"))
    {
        TheSerialPort->setStopBits(QSerialPort::OneAndHalfStop);
    }
    else if(ui->SPT_One_Stop_comboBox->currentText()==tr("2"))
    {
        TheSerialPort->setStopBits(QSerialPort::TwoStop);
    }
    TheSerialPort->setFlowControl(QSerialPort::NoFlowControl);
}

void TheSerialPortTest::Thereaduart()//读取串口函数
{
    requestData= TheSerialPort->readAll();
    if(requestData!=NULL)
    {
        ui->SPT_One_ReceiveMessage_textEdit->append(tr(requestData));
        insertDatabaseMySQL();
    }
    requestData.clear();

}

void TheSerialPortTest::insertDatabaseMySQL()
{
    serialstr=QString(requestData);
    serialEquipName=serialstr.mid(1,6);//设备用户名
    serialRFID=serialstr.mid(7,8);//员工RFID
    QString serialTemperture=serialstr.mid(15,2);//环境温度
    QString serialhumidity=serialstr.mid(17,2);//环境湿度
    QString serialelect=serialstr.mid(19,3);//电流大小
    QString serialNumber=serialstr.mid(22,6);//生产数量

    QSqlQuery query;
    /*
    query.prepare("CALL serialtest(testEquipmentID,testmessage1,testmessage2,testmessage3,testmessage4,testmessage5)values (:testEquipmentID,:testmessage1,:testmessage2,:testmessage3,:testmessage4,:testmessage5)");
    query.bindValue(":testEquipmentID",serialEquipName);
    query.bindValue(":testmessage1",serialRFID);
    query.bindValue(":testmessage2",serialTemperture);
    query.bindValue(":testmessage3",serialhumidity);
    query.bindValue(":testmessage4",serialelect);
    query.bindValue(":testmessage5",serialNumber);
    */
    ///*
    query.prepare("insert into serialporttest(ThetestDaytime,ThrtestEquipmentID,Thrtestmessage1,Thrtestmessage2,Thrtestmessage3,Thrtestmessage4,Thrtestmessage5) values (now(),:ThrtestEquipmentID,:Thrtestmessage1,:Thrtestmessage2,:Thrtestmessage3,:Thrtestmessage4,:Thrtestmessage5)");
    query.bindValue(":ThrtestEquipmentID",serialEquipName);
    query.bindValue(":Thrtestmessage1",serialRFID);
    query.bindValue(":Thrtestmessage2",serialTemperture);
    query.bindValue(":Thrtestmessage3",serialhumidity);
    query.bindValue(":Thrtestmessage4",serialelect);
    query.bindValue(":Thrtestmessage5",serialNumber);
    //*/
    query.exec();
    theqwtshow();
    //showthedatabase();
    temper=serialTemperture.toFloat();
    Thehumidity=serialhumidity.toFloat();
    LCDNumber=serialNumber.toInt();
    theelect=abs((serialhumidity.toFloat()-512)/1024*5*100);

    return;
}

void TheSerialPortTest::showthedatabase()//表格中显示数据
{
    SearchSerialModel=new QSqlRelationalTableModel(this);
    SearchSerialModel->setTable("serialporttest");
    SearchSerialModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    SearchSerialModel->select();
    ui->SPT_Some_ShowDatabases_tableView->setModel(SearchSerialModel);
    this->SearchSerialModel->removeColumn(this->SearchSerialModel->fieldIndex("idserialtest"));
    this->SearchSerialModel->removeColumn(this->SearchSerialModel->fieldIndex("Thrtestmessage6"));
    this->SearchSerialModel->setHeaderData(0,Qt::Horizontal,tr("记录日期"));
    this->SearchSerialModel->setHeaderData(1,Qt::Horizontal,tr("设备ID"));
    this->SearchSerialModel->setHeaderData(2,Qt::Horizontal,tr("员工RFID"));
    this->SearchSerialModel->setHeaderData(3,Qt::Horizontal,tr("环境温度"));
    this->SearchSerialModel->setHeaderData(4,Qt::Horizontal,tr("环境湿度"));
    this->SearchSerialModel->setHeaderData(5,Qt::Horizontal,tr("电流参数"));
    this->SearchSerialModel->setHeaderData(6,Qt::Horizontal,tr("计数器个数"));
}

void TheSerialPortTest::theqwtshow()//界面中显示qwt空间
{

    ui->SPT_Some_EquipmentTemperture_QwtTherm->setValue(temper);
    ui->SPT_Some_EquipmentHumidity_QLCDNumber->display(Thehumidity);
    ui->SPT_Some_EquipmentElectricity_QLCDNumber->display(theelect);
    ui->SPT_Some_ProductionNumber_lcdNumber->display(LCDNumber);
    ui->SPT_Some_EquipmentID_lable->setText(serialEquipName);
    ui->SPT_Some_WorkerRFID_lable->setText(serialRFID);
}




