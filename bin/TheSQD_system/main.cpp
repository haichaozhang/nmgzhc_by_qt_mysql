#include "thesqdregister.h"
#include <QApplication>
#include"connectiondatabases.h"


int thepanduan ;//判断管理员与一般用户身份
QString MySQLHostNme="127.0.0.1";
int MySQLPort=3306;
QString MySQLUserName="zhc";
QString MySQLPassword ="123456";
QString MySQLDatabaseName="thesqd";


int main(int argc, char *argv[])

{

    QApplication a(argc, argv);
    TheSQDregister w;
    w.show();

    return a.exec();
    connectiondatabases::close();
}
