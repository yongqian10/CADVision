#include "anothertest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    anothertest w;
    w.show();
    return a.exec();
}
