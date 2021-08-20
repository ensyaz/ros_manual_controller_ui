#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitIcons();


}

void MainWindow::InitIcons(){
    QPixmap pix_up("/home/lenovo/QT_Examples/Ders7-Login_App/Icons/up_arrow.jpg");
    QPixmap pix_left("/home/lenovo/QT_Examples/Ders7-Login_App/Icons/left_arrow.jpg");
    QPixmap pix_right("/home/lenovo/QT_Examples/Ders7-Login_App/Icons/right_arrow.jpg");
    QPixmap pix_down("/home/lenovo/QT_Examples/Ders7-Login_App/Icons/down_arrow.jpg");
    QPixmap pix_stop("/home/lenovo/QT_Examples/Ders7-Login_App/Icons/stop.jpg");

    ui->labelUp->setPixmap(pix_up.scaled(100,100,Qt::KeepAspectRatio));
    ui->labelLeft->setPixmap(pix_left.scaled(100,100,Qt::KeepAspectRatio));
    ui->labelRight->setPixmap(pix_right.scaled(100,100,Qt::KeepAspectRatio));
    ui->labelDown->setPixmap(pix_down.scaled(100,100,Qt::KeepAspectRatio));
    ui->labelStop->setPixmap(pix_stop.scaled(100,100,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
