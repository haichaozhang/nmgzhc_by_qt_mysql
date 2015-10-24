#ifndef THESQDWORKERINFORMATION_H
#define THESQDWORKERINFORMATION_H

#include <QWidget>

namespace Ui {
class TheSQDWorkerInformation;
}

class TheSQDWorkerInformation : public QWidget
{
    Q_OBJECT

public:
    explicit TheSQDWorkerInformation(QWidget *parent = 0);
    ~TheSQDWorkerInformation();

private:
    Ui::TheSQDWorkerInformation *ui;
};

#endif // THESQDWORKERINFORMATION_H
