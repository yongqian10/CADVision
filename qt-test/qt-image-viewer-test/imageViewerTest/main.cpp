#include "qtimageviewertest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qtImageViewerTest w;
  w.show();
  return a.exec();
}
