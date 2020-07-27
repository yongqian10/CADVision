#include "imageviewerwindow.h"
#include "ui_imageviewerwindow.h"

imageViewerWindow::imageViewerWindow(QWidget *parent) : QWidget(parent),
                                                        ui(new Ui::imageViewerWindow)
{
  ui->setupUi(this);

  ui->scrollArea->setBackgroundRole(QPalette::Dark);

  ui->imageLabel->setParent(this);
  delete ui->scrollArea->takeWidget();
  ui->scrollAreaWidgetContents = nullptr;
  ui->scrollArea->setWidget(ui->imageLabel);
}

imageViewerWindow::~imageViewerWindow()
{
  delete ui;
}

void imageViewerWindow::setFilePath(const QString &filePath)
{
  m_filePath = filePath;
}

QPixmap imageViewerWindow::scaledImage()
{
  QSize scaledSize = getScaledSize();
  QPixmap scaledPixmap;
  if (!m_image.isNull())
  {
    scaledPixmap = m_image.scaled(scaledSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  }
  return scaledPixmap;
}

QSize imageViewerWindow::getScaledSize()
{
  QSize scaledSize = size();
  scaledSize.setHeight(scaledSize.height() - ui->toolbarFrame->height());
  scaledSize *= m_scaleFactor;
  scaledSize.setWidth(scaledSize.width() - 5);
  scaledSize.setHeight(scaledSize.height() - 5);
  return scaledSize;
}

void imageViewerWindow::setScaledImage()
{
  QPixmap scaledPixmap = scaledImage();
  if (!scaledPixmap.isNull())
  {
    ui->imageLabel->setFixedSize(scaledPixmap.size());
    ui->imageLabel->setPixmap(scaledPixmap);
  }
}

bool imageViewerWindow::loadImage()
{
  if (m_filePath.isEmpty())
  {
    return false;
  }

  if (m_image.load(m_filePath))
  {
    m_scaleFactor = 1.0;
    setScaledImage();
    return true;
  }
  return false;
}

void imageViewerWindow::resizeEvent(QResizeEvent *event)
{
  QWidget::resizeEvent(event);
  setScaledImage();
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
