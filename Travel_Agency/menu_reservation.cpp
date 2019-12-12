#include "menu_reservation.h"
#include "ui_menu_reservation.h"
#include "menu_paiement.h"
#include "reservation.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>


Menu_reservation::Menu_reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_reservation)
{
    ui->setupUi(this);
}

Menu_reservation::~Menu_reservation()
{
    delete ui;
}




void Menu_reservation::on_pb_ajouter_2_clicked(){


    int numres = ui->idreservation->text().toInt();
    QString destination= ui->destination->text();
    QString datedep= ui->datede->text();
    int idclient = ui->idclient->text().toInt();
    int codean = ui->codean->text().toInt();
    QString datearr = ui->datear->text();

     reservation r(numres,destination,datedep,idclient,codean,datearr);
     bool test=r.ajouter_res();
     ui->tabreservation->setModel(tmpreservation.afficher_res());   //refresh

    if(test){
      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }
    QMessageBox::information(this, QObject::tr("Ajouter un reservation"),
    QObject::tr("reservation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Menu_reservation::on_pb_supprimer_2_clicked()
{


int numres = ui->lineEdit->text().toInt();
bool test=tmpreservation.supprimer_res(numres);//refresh



    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}

    QMessageBox::information(this, QObject::tr("Supprimer un reservation"),
                QObject::tr("reservation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(this, QObject::tr("Supprimer un reservation "),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void Menu_reservation::on_pb_afficher_2_clicked(){
    ui->tabreservation->setModel(tmpreservation.afficher_res());
}


void Menu_reservation::on_pb_rechercher_2_clicked()
{

    int numres = ui->lineEdit_rechercher_2->text().toInt();
     ui->tabreservation_3->setModel(tmpreservation.recherche_res(numres));   //refresh

}

void Menu_reservation::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}


void Menu_reservation::on_pb_modifer_2_clicked()
{
    int numres = ui->idreservation2->text().toInt();
    QString destination= ui->destination2->text();
    QString datedep = ui->datede2->text();
    int idclient = ui->idclient2->text().toInt();
    int codean = ui->codean2->text().toInt();
    QString datearr = ui->datear2->text();

    reservation r(numres,destination,datedep,idclient,codean,datearr);
    bool test=r.modifier_res(numres);
    if(test)
    {ui->tabreservation->setModel(tmpreservation.afficher_res());


    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }
    QMessageBox::information(this, QObject::tr("modifer un reservation"),
                      QObject::tr("reservation modife.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(this, QObject::tr("modifier un reservation"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void Menu_reservation::on_next_clicked()
{
    this->close();
    Menu_paiement * m = new Menu_paiement(this);
    m->show();
}
