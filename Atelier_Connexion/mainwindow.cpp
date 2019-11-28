#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agent.h"
#include "departement.h"
#include <QMessageBox>
#include "son.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabagent->setModel(tmpagent.afficher_ag());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    mettreMusique();
    QString numagent = ui->numagent->text();
    int age = ui->age->text().toInt();
    QString prenomagent= ui->prenomagent->text();
    QString nomagent= ui->nomagent->text();
    QString mdp=ui->mdp->text();
    QString adresse=ui->adresse->text();
  Agent a(numagent, nomagent, prenomagent,age,mdp,adresse);
  bool test=a.ajouter_ag();
  if(test){
    ui->tabagent->setModel(tmpagent.afficher_ag());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter un Agent"),
    QObject::tr("Agent ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un Agent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    mettreMusique();
QString numagent = ui->numagent_2->text();
bool test=tmpagent.supprimer_ag(numagent);
if(test)
{ui->tabagent->setModel(tmpagent.afficher_ag());//refresh
    QMessageBox::information(this, QObject::tr("Supprimer un Agent"),
                QObject::tr("Agent supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(this, QObject::tr("Supprimer un Agent"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow :: on_pb_modifier_clicked()
{
    mettreMusique();
    QString numagent = ui->numagent_3->text();
    int age = ui->age_2->text().toInt();
    QString prenomagent= ui->prenomagent_2->text();
    QString nomagent= ui->nomagent_2->text();
    QString mdp=ui->mdp_2->text();
    QString adresse=ui->adresse_2->text();
  Agent a(numagent, nomagent, prenomagent,age,mdp,adresse);
  bool test=a.modifier_ag(numagent);
  if(test){
    ui->tabagent->setModel(tmpagent.afficher_ag());//refresh
    QMessageBox::information(this, QObject::tr("modifier un Agent"),
    QObject::tr("Agent modifier.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("modifier Agent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_Supprimer2_clicked()
{
    mettreMusique();
    QString iddepartement= ui->id2->text();
    bool test=tmpdepartement.supprimer_dep(iddepartement);
    if(test)
    {ui->tabdepartement->setModel(tmpdepartement.afficher_dep());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer un Departement"),
                    QObject::tr("Departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer un Departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Ajouter2_clicked()
{
    mettreMusique();
    QString iddepartement = ui->id1->text();
    QString nomdep= ui->lineEdit_nomdep->text();
    QString typedep= ui->lineEdit_typedep->text();
    int nbagent = ui->lineEdit_nbagent->text().toInt();
  departement dep(iddepartement, nomdep, typedep,nbagent);
  bool test=dep.ajouter_dep();
  if(test){
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

void MainWindow::on_Modifier2_clicked()
{
    mettreMusique();
    QString iddepartement = ui->id3->text();
    QString nomdep= ui->nom3->text();
    QString typedep= ui->type3->text();
    int nbagent = ui->nb3->text().toInt();
  departement dep(iddepartement, nomdep, typedep,nbagent);
  bool test=dep.modifier_dep(iddepartement);
  if(test){
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

void MainWindow::on_Rechercher_clicked()
{
    mettreMusique();
    QString numagent = ui->lineEdit_rechercher->text();
      ui->tabrechercher->setModel(tmpagent.rechercher(numagent));   //refresh
       ui->tabdepartement->setModel(tmpdepartement.afficher_dep());//refresh
      QMessageBox::information(this, QObject::tr("Rechercher un agent"),
      QObject::tr("agent recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_rechercherd_clicked()
{
    mettreMusique();
    QString idddepartement = ui->chercherdep->text();
       ui->chercherdd->setModel(tmpdepartement.rechercherdep(idddepartement));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher un departement"),
      QObject::tr("Departement recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
}
