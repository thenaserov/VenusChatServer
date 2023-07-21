#include <QCoreApplication>
#include "chatservercontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChatServerController controller;
    controller.StartJoinThread();
    return a.exec();
}
