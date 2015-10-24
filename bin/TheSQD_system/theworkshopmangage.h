#ifndef THEWORKSHOPMANGAGE_H
#define THEWORKSHOPMANGAGE_H

#include <QMainWindow>

namespace Ui {
class theworkshopmangage;
}

class theworkshopmangage : public QMainWindow
{
    Q_OBJECT

public:
    explicit theworkshopmangage(QWidget *parent = 0);
    ~theworkshopmangage();

private slots:
    void on_TWM_Comback_pushButton_clicked();

private:
    Ui::theworkshopmangage *ui;
};

#endif // THEWORKSHOPMANGAGE_H
