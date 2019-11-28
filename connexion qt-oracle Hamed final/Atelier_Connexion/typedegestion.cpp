#include "typedegestion.h"
#include "ui_typedegestion.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QMessageBox>
#include "song.h"


Typedegestion::Typedegestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Typedegestion)
{
    ui->setupUi(this); 
    ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());
}

Typedegestion::~Typedegestion()
{
    delete ui;
}

void Typedegestion::on_pb_ajouter_2_clicked()
{
    buttonsound();
    int cin = ui->lineEdit_cin_2->text().toInt();
    QString age = ui->lineEdit_nom_2->text();
    QString nom= ui->lineEdit_prenom_2->text();
    QString prenom= ui->lineEdit_age_2->text();
  Rec2 a(cin, age, nom,prenom);
  bool test=a.ajouter_rec2();
  if(test){
    ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter une reclamation"),
    QObject::tr("reclamation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Typedegestion::on_pb_modifier_2_clicked()
{
    buttonsound();
    int cin = ui->lineEdit_9->text().toInt();
    QString age = ui->lineEdit_10->text();
    QString nom= ui->lineEdit_11->text();
    QString prenom= ui->lineEdit_12->text();
  Rec2 a(cin, age, nom,prenom);
  bool test=a.modifier_rec2();
  if(test){
    ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Modifier un type de reclamation"),
    QObject::tr("Réclamation modifié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Modifier un type de reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Typedegestion::on_pb_supprimer_2_clicked()
{
    buttonsound();
    int cin = ui->lineEdit_codean_3->text().toInt();
    bool test=tmpreclamation2.supprimer_rec2(cin);
    if(test)
    {ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer un type de reclamation"),
                    QObject::tr("Type reclamation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer un type de reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void Typedegestion::on_pb_Rechercher_2_clicked()
{
    buttonsound();
    int cin = ui->lineEdit_rechercher_2->text().toInt();
      ui->tabreclamation_5->setModel(tmpreclamation2.recherche_rec2(cin));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher un type de reclamation"),
      QObject::tr("Type Réclamation recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void Typedegestion::on_pb_trier_clicked()
{
    buttonsound();
    ui->tabreclamation_6->setModel(tmpreclamation2.trier_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
    QObject::tr("Réclamation trié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}
