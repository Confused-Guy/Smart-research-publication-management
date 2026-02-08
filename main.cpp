#include "conference.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    conference w;
    w.show();
    return a.exec();
}
