#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"


MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect = new MainWindow(this);
}

MainMenu::~MainMenu()
{
    delete ui;
    delete connect;
}

void MainMenu::on_pushButton_clicked()
{
   this->hide();
   this->connect->show();

}
