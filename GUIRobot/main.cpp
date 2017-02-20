#include "guirobot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIRobot w;
    w.show();

    return a.exec();
}
