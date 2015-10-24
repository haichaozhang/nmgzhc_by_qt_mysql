#include "connectiondatabases.h"
#include<QSqlQuery>
#include<QMessageBox>
extern QString MySQLHostNme;
extern int MySQLPort;
extern QString MySQLUserName;
extern QString MySQLPassword ;
extern QString MySQLDatabaseName;

connectiondatabases::connectiondatabases()
{

}

connectiondatabases::~connectiondatabases()
{

}
/**
 * 数据库连接文件
 *
 */
QSqlDatabase connectiondatabases::db=QSqlDatabase::addDatabase("QMYSQL");

/************************

布尔函数，数据库打开
************************/

bool connectiondatabases::open()
{

    db.setHostName (MySQLHostNme);
    db.setPort(MySQLPort);
    db.setUserName (MySQLUserName);
    db.setPassword (MySQLPassword);
    db.setDatabaseName(MySQLDatabaseName);
    //QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");
    //db.setDatabaseName("thesqdt");

     if(db.open())
    {
        qDebug("Connect to Mysql Sourcesuccessfully");
     }
    else
    {
        qDebug("Open The Mysql database failed");        
    }
    return true;

}
void connectiondatabases::close()
{
    db.close();
}

