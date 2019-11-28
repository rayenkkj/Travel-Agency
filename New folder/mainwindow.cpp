#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paiement.h"
#include "reservation.h"
#include <QMessageBox>
#include "sound.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()

{
    int codepaie = ui->lineEdit_codepaie->text().toInt();
    int montant = ui->lineEdit_montant->text().toInt();
    int idclient = ui->lineEdit_idclient->text().toInt();
    QString typepaie= ui->lineEdit_typepaie->text();
  paiement a(typepaie,montant,idclient,codepaie);
  bool test=a.ajouter_pa();
  if(test){
    ui->tabpaiement->setModel(tmppaiement.afficher_pa());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter un paiement"),
    QObject::tr("paiement ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un paiement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int codepaie = ui->lineEdit_codepaie->text().toInt();
bool test=tmppaiement.supprimer_pa(codepaie);
if(test)
{ui->tabpaiement->setModel(tmppaiement.afficher_pa());//refresh
    QMessageBox::information(this, QObject::tr("Supprimer un paiement"),
                QObject::tr("paiement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(this, QObject::tr("Supprimer un paiement "),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow ::on_pb_modifier_clicked()
{

 int codepaie = ui->lineEdit_codepaie2->text().toInt();
 int montant = ui->lineEdit_montant2->text().toInt();
 QString typepaie = ui->lineEdit_typepaie2->text();
 int idclient = ui->lineEdit_idclient2->text().toInt();

 paiement p( typepaie, codepaie, montant, idclient);
 bool test=p.modifier_pa(codepaie,montant,idclient,typepaie);
if(test)
{ui->tabpaiement->setModel(tmppaiement.afficher_pa());
    QMessageBox::information(this, QObject::tr("modifer un paiement"),
                      QObject::tr("paiement modife.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(this, QObject::tr("modifier un paiement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pb_ajouter_2_clicked(){
    int idreservation = ui->idreservation->text().toInt();
    QString destination= ui->destination->text();
    QString datede= ui->datede->text();
    QString datear= ui->datear->text();
    int idclient = ui->idclient->text().toInt();
    int codean = ui->codean->text().toInt();
  reservation r(idreservation,destination,datede,datear,idclient,codean);
  bool test=r.ajouter_res();
  if(test){
    ui->tabreservation->setModel(tmpreservation.afficher_res());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter un reservation"),
    QObject::tr("reservation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_2_clicked()
{
int idreservation = ui->idreservation->text().toInt();
bool test=tmpreservation.supprimer_res(idreservation);
if(test)
{ui->tabreservation->setModel(tmpreservation.afficher_res());//refresh
    QMessageBox::information(this, QObject::tr("Supprimer un reservation"),
                QObject::tr("reservation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(this, QObject::tr("Supprimer un reservation "),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow ::on_pb_modifier_2_clicked()
{

    int idreservation = ui->idreservation->text().toInt();
    QString destination= ui->destination->text();
    QString datede= ui->datede->text();
    QString datear= ui->datear->text();
    int idclient = ui->idclient->text().toInt();
    int codean = ui->codean->text().toInt();

reservation r(idreservation,destination,datede,datear,idclient,codean);
 bool test=r.modifier_res(idreservation,destination,datede,datear,idclient,codean);
if(test)
{ui->tabreservation->setModel(tmpreservation.afficher_res());
    QMessageBox::information(this, QObject::tr("modifer un reservation"),
                      QObject::tr("reservation modife.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(this, QObject::tr("modifier un reservation"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}





