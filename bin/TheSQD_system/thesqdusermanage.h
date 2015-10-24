#ifndef THESQDUSERMANAGE_H
#define THESQDUSERMANAGE_H

#include <QMainWindow>

namespace Ui {
class TheSQDUsermanage;
}

class TheSQDUsermanage : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheSQDUsermanage(QWidget *parent = 0);
    ~TheSQDUsermanage();

private slots:
    void on_TUM_comback_pushbutton_clicked();

private:
    Ui::TheSQDUsermanage *ui;
};

#endif // THESQDUSERMANAGE_H
