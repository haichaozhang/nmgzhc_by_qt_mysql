#ifndef THEEQUIPMENTMANGAGE_H
#define THEEQUIPMENTMANGAGE_H

#include <QMainWindow>

namespace Ui {
class theequipmentmangage;
}

class theequipmentmangage : public QMainWindow
{
    Q_OBJECT

public:
    explicit theequipmentmangage(QWidget *parent = 0);
    ~theequipmentmangage();

private slots:
    void on_TEM_Comback_pushButton_clicked();

private:
    Ui::theequipmentmangage *ui;
};

#endif // THEEQUIPMENTMANGAGE_H
