#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "typedegestion.h"


MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect = new MainWindow(this);
    connect2 = new Typedegestion(this);
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

void MainMenu::on_pushButton_2_clicked()
{
    this->hide();
    this->connect2->show();
}
