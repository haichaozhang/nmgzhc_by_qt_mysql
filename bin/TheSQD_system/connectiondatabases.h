#ifndef CONNECTIONDATABASES_H
#define CONNECTIONDATABASES_H
#include <QMainWindow>
#include<QString>
#include<QtSql/QSqlDatabase>
#include<QSqlQuery>
#include<QtGui>
#include<QSqlTableModel>
#include<QMessageBox>
#include<QSqlError>
#include<QString>
#include<QSqlRelationalTableModel>
#include<QApplication>
#include<QSqlRecord>
#include<QtGui>
#include<QLabel>
#include<QTableWidget>
#include<QSqlTableModel>
#include<QAbstractItemView>
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include<QtSql>
#include<QTextEdit>
#include<QImage>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QFileDialog>
#include <QMainWindow>
#include <QWidget>

class connectiondatabases
{
public:
    connectiondatabases();
    ~connectiondatabases();

    static QSqlDatabase db;
    static bool open();
    static void close();
};

#endif
