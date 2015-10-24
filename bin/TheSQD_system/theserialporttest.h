#ifndef THESERIALPORTTEST_H
#define THESERIALPORTTEST_H

#include <QMainWindow>
#include"QtSerialPort/qserialport.h"
#include"QtSerialPort/qserialportinfo.h"
#include"connectiondatabases.h"
#include"QTime"
#include"QTimer"

namespace Ui {
class TheSerialPortTest;
}

class TheSerialPortTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheSerialPortTest(QWidget *parent = 0);
    ~TheSerialPortTest();
    QString serialstr;
    QByteArray requestData;
    QString serialEquipName;
    QString serialRFID;



private slots:
    void on_SPT_Comback_pushButton_clicked();

    void on_SPT_One_OpenSerialPort_pushButton_clicked();

    void readfromserialport();//打开串口函数

    void Thereaduart();//读取串口函数

    void insertDatabaseMySQL();//向MySQL数据库存入数据

    void showthedatabase();//在窗口显示数据

    void theqwtshow();//qwt控件显示

private:
    Ui::TheSerialPortTest *ui;
    QSerialPort *TheSerialPort;
    QSqlRelationalTableModel *SearchSerialModel;
    double temper;
    double Thehumidity;
    double LCDNumber;
    double theelect;
};

#endif // THESERIALPORTTEST_H
