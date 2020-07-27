#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QTreeView>
#include <QInputDialog>
#include <QLabel>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui
{
  class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_actionUndo_triggered();

  void on_actionDelete_triggered();

  void on_actionNew_triggered();

  void on_actionOpen_triggered();

  void on_actionSave_triggered();

  void on_actionSave_as_triggered();

  void on_actionClose_triggered();

  void on_actionCut_triggered();

  void on_actionPaste_triggered();

  void on_actionRedo_triggered();

  void on_actionZoom_in_triggered();

  void on_actionZoom_out_triggered();

  void on_actionZoom_to_fit_triggered();

  void on_actionInfo_triggered();

  void on_actionCopy_triggered();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_toolButton_triggered(QAction *arg1);

private:
  Ui::MainWindow *ui;
  QString currentFile;
  QDirModel *model;
  QLabel *imageLabel;
  QScrollArea *scrollArea;
  QImage image;
  scaleFactor = 1;

  void setImage(const QImage &newImage);
};
#endif // MAINWINDOW_H
