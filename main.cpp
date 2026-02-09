#include "collabswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    collabsWindow w;
    w.show();
    return a.exec();
}
