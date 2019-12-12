#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include <QDialog>
#include <QMediaPlaylist>
#include <QMessageBox>


MainMenu::MainMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect = new MainWindow(this);


}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_pb_Connect_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
   if(username=="admin" && password=="admin"){
        this->hide();
        this->connect->show();
   }else{
            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                le->clear();}
            if(username!="admin" && password!="admin"){
                 QMessageBox::critical(this, QObject::tr("Login"),
                             QObject::tr("Wrong username and password !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
             }else if(username!="admin"){
                  QMessageBox::critical(this, QObject::tr("Login"),
                            QObject::tr("Wrong username !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
              }else{
                 QMessageBox::critical(this, QObject::tr("Login"),
                              QObject::tr("Wrong password !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
                }

        }
}
