#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "typedegestion.h"
#include "affectation.h"
#include "song.h"
#include <QMessageBox>


MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect = new MainWindow(this);
    connect2 = new Typedegestion(this);
    connect3 = new Affectation(this);
}

MainMenu::~MainMenu()
{
    delete ui;
    delete connect;
    delete connect2;
    delete connect3;
}

void MainMenu::on_firstwindow_clicked()
{
    buttonsound();
   //this->hide();
   this->connect->show();
}

void MainMenu::on_secondwindow_clicked()
{
    buttonsound();
    //this->hide();
    this->connect2->show();
}

void MainMenu::on_Affectation_button_clicked()
{
    buttonsound();
    //this->hide();
    this->connect3->show();
}
