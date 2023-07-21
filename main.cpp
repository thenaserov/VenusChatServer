#include <QCoreApplication>
#include "chatservercontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChatServerController controller;
    controller.StartJoinThread();
    controller.StopJoinThread();
    return a.exec();
}
