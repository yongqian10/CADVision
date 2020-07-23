// template for CADVision

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
//#include <QPrinter>
//#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // TODO change model to QFileSystemModel
  ////////////////// Directory window //////////////////////
  // what should do
  // 1. created model
  // 2. populated our model
  // 3. enable modifying file system
  // 4. tied treeview with DirModel
  // create and populate model
  model = new QDirModel(this);

  // enable modifying file system
  model->setReadOnly(false);
  // sort directory
  model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

  // tie treeview with DirModel
  // QTreeView::setModel(QAbstractItemModel * model)
  // Reimplemented from QAbstractItemView::setModel()
  ui->treeView->setModel(model);
  // get current directory index
  QModelIndex index = model->index(QDir::currentPath());
  // set initial directory to current path
  ui->treeView->setRootIndex(index);
  // set initial view of directory
  // for the selected drive as expanded
  ui->treeView->expand(index);
  ui->treeView->scrollTo(index);
  // hightlight the selected
  ui->treeView->setCurrentIndex(index);
  // resizing the column - first column
  ui->treeView->resizeColumnToContents(0);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_actionNew_triggered()
{
  currentFile.clear();
  ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
  QFile file(fileName);
  currentFile = fileName;
  if (!file.open(QIODevice::ReadOnly | QFile::Text))
  {
    QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    return;
  }
  setWindowTitle(fileName);
  QTextStream in(&file);
  QString text = in.readAll();
  ui->textEdit->setText(text);
  file.close();
}

void MainWindow::on_actionSave_triggered()
{
  QString fileName;
  // If we don't have a filename from before, get one.
  if (currentFile.isEmpty())
  {
    fileName = QFileDialog::getSaveFileName(this, "Save");
    currentFile = fileName;
  }
  else
  {
    fileName = currentFile;
  }
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly | QFile::Text))
  {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
  }
  setWindowTitle(fileName);
  QTextStream out(&file);
  QString text = ui->textEdit->toPlainText();
  out << text;
  file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
  QString fileName = QFileDialog::getSaveFileName(this, "Save as");
  QFile file(fileName);

  if (!file.open(QFile::WriteOnly | QFile::Text))
  {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
  }
  currentFile = fileName;
  setWindowTitle(fileName);
  QTextStream out(&file);
  QString text = ui->textEdit->toPlainText();
  out << text;
  file.close();
}

void MainWindow::on_actionClose_triggered()
{
  QCoreApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
#if QT_CONFIG(clipboard)
  ui->textEdit->copy();
#endif
}

void MainWindow::on_actionCut_triggered()
{
#if QT_CONFIG(clipboard)
  ui->textEdit->cut();
#endif
}

void MainWindow::on_actionPaste_triggered()
{
#if QT_CONFIG(clipboard)
  ui->textEdit->paste();
#endif
}

void MainWindow::on_actionRedo_triggered()
{
  ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
  ui->textEdit->undo();
}

void MainWindow::on_actionDelete_triggered()
{
}

void MainWindow::on_actionZoom_in_triggered()
{
}

void MainWindow::on_actionZoom_out_triggered()
{
}

void MainWindow::on_actionZoom_to_fit_triggered()
{
}

void MainWindow::on_actionInfo_triggered()
{
  QMessageBox::about(this, tr("About CADVisionDemo"),
                     tr("Demo purpose"));
}

void MainWindow::on_pushButton_clicked()
{
}

void MainWindow::on_pushButton_2_clicked()
{
}
