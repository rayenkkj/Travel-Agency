#include "menu_departement.h"
#include "ui_menu_departement.h"
#include "menu_media.h"
#include "mainwindow.h"
#include "departement.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

Menu_departement::Menu_departement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_departement)
{
    ui->setupUi(this);
}

Menu_departement::~Menu_departement()
{
    delete ui;
}


void Menu_departement::on_Supprimer2_clicked()
{
    QString iddepartement= ui->id2->text();
    bool test=tmpdepartement.supprimer_dep(iddepartement);
    if(test)
    {   foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
            le->clear();}
        ui->tabdepartement->setModel(tmpdepartement.afficher_dep());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer un Departement"),
                    QObject::tr("Departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer un Departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_departement::on_Ajouter2_clicked()
{

    QString iddepartement = ui->id1->text();
    QString nomdep= ui->lineEdit_nomdep->text();
    QString typedep= ui->lineEdit_typedep->text();
    int nbagent = ui->lineEdit_nbagent->text().toInt();
  departement dep(iddepartement, nomdep, typedep,nbagent);
  bool test=dep.ajouter_dep();
  if(test){
      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();}
    ui->tabdepartement->setModel(tmpdepartement.afficher_dep());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter un departement"),
    QObject::tr("departement ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}
  else
      QMessageBox::critical(this, QObject::tr("modifier Agent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_departement::on_Modifier2_clicked()
{

    QString iddepartement = ui->id3->text();
    QString nomdep= ui->nom3->text();
    QString typedep= ui->type3->text();
    int nbagent = ui->nb3->text().toInt();
  departement dep(iddepartement, nomdep, typedep,nbagent);
  bool test=dep.modifier_dep(iddepartement);
  if(test){
      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();}
    ui->tabdepartement->setModel(tmpdepartement.afficher_dep());//refresh
    QMessageBox::information(this, QObject::tr("modifier un departement"),
    QObject::tr("departement modifier.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("modifier Agent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_departement::on_rechercherd_clicked()
{

    QString idddepartement = ui->chercherdep->text();
       ui->chercherdd->setModel(tmpdepartement.rechercherdep(idddepartement));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher un departement"),
      QObject::tr("Departement recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_departement::on_afficherdepartement_clicked()
{

    ui->tabdepartement->setModel(tmpdepartement.afficher_dep());
}

void Menu_departement::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void Menu_departement::on_affichertrie2_clicked()
{
        ui->tabafficherdep_2->setModel(tmpdepartement.trier_rec3());
        QMessageBox::information(this, QObject::tr("Rechercher une departement"),
        QObject::tr("departement trié.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_departement::on_next_clicked()
{
    this->close();
    Menu_media * m = new Menu_media(this);
    m->show();
}
