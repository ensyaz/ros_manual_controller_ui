#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    hide();
    ptr = new MainWindow(this);
    ptr->show();
    /*
    QString id = ui->lineEdit_3->text();
    QString pass = ui->lineEdit_2->text();

    if(id=="test" && pass =="test"){
        QMessageBox::information(this,"Login","ID and Password are correct");
        hide();
        ptr = new MainWindow(this);
        ptr->show();
    }
    else{
        QMessageBox::warning(this,"Login","ID and Password are incorrect. Try again...");
    }*/
}
