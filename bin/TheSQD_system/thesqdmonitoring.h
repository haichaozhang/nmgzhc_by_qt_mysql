#ifndef THESQDMONITORING_H
#define THESQDMONITORING_H
#include"theserialporttest.h"

#include <QMainWindow>

namespace Ui {
class TheSQDMonitoring;
}

class TheSQDMonitoring : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheSQDMonitoring(QWidget *parent = 0);
    ~TheSQDMonitoring();
    QSqlRelationalTableModel *SQDMSearchSerialModel;
   // void timerEvent(QTimerEvent *event);

private slots:
    void on_quitsysterms_ation_triggered();

    void on_comebackregister_action_triggered();

    void on_theworker_action_triggered();

    void on_SQDM_Clear_pushbutton_clicked();



    void on_theuserandadmin_action_triggered();

    void on_SerialPort_Action_triggered();

    void on_theequipment_action_triggered();

    void on_workershop_action_triggered();

    void on_searchworker_action_triggered();

    void on_searchequipment_action_triggered();

    void SQDMshowdatabase();

    void on_SQDM_Search_pushbutton_clicked();

    void on_SQDM_Pitchup_pushbutton_clicked();

    void SQDMtimeupdate();//时间事件

    void SQDMupdateSQL();//更新屏幕空间信息

    void SQDMshowqwtplot();//界面上显示变化曲线信息

private:
    Ui::TheSQDMonitoring *ui;
};

#endif // THESQDMONITORING_H
