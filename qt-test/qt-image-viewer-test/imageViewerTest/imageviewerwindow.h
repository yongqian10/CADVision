#ifndef IMAGEVIEWERWINDOW_H
#define IMAGEVIEWERWINDOW_H

#include <QWidget>

namespace Ui
{
  class imageViewerWindow;
}

class imageViewerWindow : public QWidget
{
  Q_OBJECT

public:
  explicit imageViewerWindow(QWidget *parent = nullptr);
  ~imageViewerWindow();

  // method
  bool loadImage();
  void setFilePath(const QString &filePath);

  // NOTE moved ui to protected | however qt not allow it
  Ui::imageViewerWindow *ui;

protected:
  void resizeEvent(QResizeEvent *event) override;

private:
  QPixmap scaledImage();
  QSize getScaledSize();
  void setScaledImage();

  QPixmap m_image;
  double m_scaleFactor = 1.0;
  QString m_filePath;
};

#endif // IMAGEVIEWERWINDOW_H
