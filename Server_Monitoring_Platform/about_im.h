#ifndef ABOUT_IM_H
#define ABOUT_IM_H

#include <QWidget>
#include <QPalette>
#include <QImage>
#include <QBrush>

#include "typelist.h"

namespace Ui {
class About_IM;
}

class About_IM : public QWidget
{
    Q_OBJECT

public:
    explicit About_IM(QWidget *parent = nullptr);
    ~About_IM();

    void Init_UI(void);

private:
    Ui::About_IM *ui;
};

#endif // ABOUT_IM_H
