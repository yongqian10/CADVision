#ifndef QTIMAGEVIEWERTEST_H
#define QTIMAGEVIEWERTEST_H

#include <QMainWindow>
#include "imageviewerwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
  class qtImageViewerTest;
}
QT_END_NAMESPACE

class qtImageViewerTest : public QMainWindow
{
  Q_OBJECT

public:
  qtImageViewerTest(QWidget *parent = nullptr);
  ~qtImageViewerTest();

private slots:
  void onOpenFile();

private:
  Ui::qtImageViewerTest *ui;
  imageViewerWindow *m_imageViewerWindow = nullptr;
};
#endif // QTIMAGEVIEWERTEST_H
