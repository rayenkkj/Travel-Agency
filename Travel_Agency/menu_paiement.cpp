#include "menu_paiement.h"
#include "ui_menu_paiement.h"
#include "menu_reclamation.h"
#include "paiement.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

Menu_paiement::Menu_paiement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_paiement)
{
    ui->setupUi(this);
}

Menu_paiement::~Menu_paiement()
{
    delete ui;
}


void Menu_paiement::on_pb_ajouter_clicked()

{
    int codepaie = ui->lineEdit_codepaie->text().toInt();
    int montant = ui->lineEdit_montant->text().toInt();
    int idclient = ui->lineEdit_idclient->text().toInt();
    QString typepaie= ui->lineEdit_typepaie->text();
    paiement a(typepaie,montant,idclient,codepaie);
    bool test=a.ajouter_pa();


  if(test){
    ui->tabpaiement->setModel(tmppaiement.afficher_pa());

    if(test){
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }

    QMessageBox::information(this, QObject::tr("Ajouter un paiement"),
    QObject::tr("paiement ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un paiement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

}

void Menu_paiement::on_pb_supprimer_clicked()
    {

    int codepaie = ui->lineEdit_codean_2->text().toInt();
    bool test=tmppaiement.supprimer_pa(codepaie);//refresh



    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer une paiement"),
                QObject::tr("paiement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer une paiement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}



void Menu_paiement ::on_pb_modifier_clicked()
{

 int codepaie = ui->lineEdit_codepaie2->text().toInt();
 int montant = ui->lineEdit_montant2->text().toInt();
 QString typepaie = ui->lineEdit_typepaie2->text();
 int idclient = ui->lineEdit_idclient2->text().toInt();

 paiement p( typepaie, codepaie, montant, idclient);
 bool test=p.modifier_pa(codepaie,montant,idclient,typepaie);
if(test)
{ui->tabpaiement->setModel(tmppaiement.afficher_pa());
    if(test){
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }

    QMessageBox::information(this, QObject::tr("modifer un paiement"),
                      QObject::tr("paiement modife.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(this, QObject::tr("modifier un paiement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
}
void Menu_paiement::on_pb_asc_tri_clicked(){

    ui->tabpaiement_2->setModel(tmppaiement.afficher_asc());
}



void Menu_paiement::on_pb_afficher_clicked(){
    ui->tabpaiement->setModel(tmppaiement.afficher_pa());
}

void Menu_paiement::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void Menu_paiement::on_next_clicked()
{
    this->close();
    menu_reclamation * m = new menu_reclamation(this);
    m->show();
}
