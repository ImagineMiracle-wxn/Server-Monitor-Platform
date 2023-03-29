#include "monitoringplatform_im.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MonitoringPlatform_IM w;
    w.show();
    return a.exec();
}
