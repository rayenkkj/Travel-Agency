#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_menu_annonce.h"
#include "ui_menu_reclamation.h"
#include "ui_menu_reservation.h"
#include "ui_menu_paiement.h"
#include "ui_menu_media.h"
#include "ui_menu_agent.h"
#include "ui_menu_client.h"
#include "ui_menu_departement.h"
#include "ui_menu_pub.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDialog>
#include <QMediaPlaylist>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    annonce = new Menu_annonce(this);
    reclamation = new menu_reclamation(this);
    reservation = new Menu_reservation(this);
    paiement = new Menu_paiement(this);
    media = new Menu_media(this);
    compagne = new menu_compagne(this);
    client = new Menu_client(this);
    agent = new Menu_agent(this);
    departement = new Menu_departement(this);
    pub = new Menu_pub(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_annonce_clicked()
{
    this->close();
    this->annonce->show();
}

void MainWindow::on_pb_reclamation_clicked()
{
    this->close();
    this->reclamation->show();
}

void MainWindow::on_pb_reservation_clicked()
{
   this->close();
   this->reservation->show();
}

void MainWindow::on_pb_paiement_clicked()
{
    this->close();
    this->paiement->show();
}

void MainWindow::on_pb_media_clicked()
{
    this->close();
    this->media->show();
}

void MainWindow::on_pb_compagne_clicked()
{
    this->close();
    this->compagne->show();
}

void MainWindow::on_pb_client_clicked()
{
    this->close();
    this->client->show();
}

void MainWindow::on_pb_agent_clicked()
{
    this->close();
    this->agent->show();
}

void MainWindow::on_pb_departement_clicked()
{
    this->close();
    this->departement->show();
}

void MainWindow::on_pb_pub_clicked()
{
    this->close();
    this->pub->show();
}

void MainWindow::on_pb_back_clicked()
{
    this->close();
    MainMenu * m = new MainMenu(this);
    m->show();
}

