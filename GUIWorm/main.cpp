#include "guiworm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIWorm w;
    w.show();

    return a.exec();
}
