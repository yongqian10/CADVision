#include "qtimageviewertest.h"
#include <QFileDialog>
#include "ui_qtimageviewertest.h"

qtImageViewerTest::qtImageViewerTest(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::qtImageViewerTest)
{
  ui->setupUi(this);

  connect(m_imageViewerWindow->ui->openImgButton, SIGNAL(clicked(bool)), SLOT(onOpenFile()));
}

qtImageViewerTest::~qtImageViewerTest()
{
  delete ui;
}

void qtImageViewerTest::onOpenFile()
{
  QString fileName = QFileDialog::getOpenFileName(
      this,
      "Open Tmage File",
      QDir::currentPath(),
      "JPG Files (*.jpg);; PNG files (*.png)");

  if (m_imageViewerWindow == nullptr)
  {
    m_imageViewerWindow = new imageViewerWindow(this);
    ui->imageViewerVLayout->addWidget(m_imageViewerWindow);
  }

  if (m_imageViewerWindow && !fileName.isEmpty())
  {
    m_imageViewerWindow->setFilePath(fileName);
    m_imageViewerWindow->loadImage();
  }
}
