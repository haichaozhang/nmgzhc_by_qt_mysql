#ifndef THEEQUIPMENTSEARCH_H
#define THEEQUIPMENTSEARCH_H

#include <QMainWindow>

namespace Ui {
class theequipmentsearch;
}

class theequipmentsearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit theequipmentsearch(QWidget *parent = 0);
    ~theequipmentsearch();

private slots:
    void on_TES_Comback_pushButton_clicked();

private:
    Ui::theequipmentsearch *ui;
};

#endif // THEEQUIPMENTSEARCH_H
