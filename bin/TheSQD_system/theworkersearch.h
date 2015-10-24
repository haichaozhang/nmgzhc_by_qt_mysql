#ifndef THEWORKERSEARCH_H
#define THEWORKERSEARCH_H

#include <QMainWindow>

namespace Ui {
class theworkersearch;
}

class theworkersearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit theworkersearch(QWidget *parent = 0);
    ~theworkersearch();

private slots:
    void on_TWS_Comback_pushButton_clicked();

private:
    Ui::theworkersearch *ui;
};

#endif // THEWORKERSEARCH_H
