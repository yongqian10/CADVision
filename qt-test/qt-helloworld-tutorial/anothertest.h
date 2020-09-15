#ifndef ANOTHERTEST_H
#define ANOTHERTEST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class anothertest; }
QT_END_NAMESPACE

class anothertest : public QMainWindow
{
    Q_OBJECT

public:
    anothertest(QWidget *parent = nullptr);
    ~anothertest();

private slots:
    void on_btnHello_clicked();

private:
    Ui::anothertest *ui;
};
#endif // ANOTHERTEST_H
