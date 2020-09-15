#include "anothertest.h"
#include "ui_anothertest.h"

// main window class

anothertest::anothertest(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::anothertest)
{
    ui->setupUi(this);
}

anothertest::~anothertest()
{
    delete ui;
}

void anothertest::on_btnHello_clicked()
{
    // execute function here
    static int count = 0;
    QString strCount;

    // display text message in first label
    ui->lblHello->setText("Hello, world");

    // display button clicked count insecond label
    count++;
    strCount.asprintf("%d", count);
    ui->lblCount->setText(strCount);
}

//git test
