#include "menu_agent.h"
#include "ui_menu_agent.h"
#include "menu_departement.h"
#include "agent.h"
#include "agent_type.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

Menu_agent::Menu_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_agent)
{
    ui->setupUi(this);
    ui->tabagent->setModel(tmpagent.afficher_ag());
}

Menu_agent::~Menu_agent()
{
    delete ui;
}


void Menu_agent::on_pb_ajouter_clicked()
{

    QString idagent = ui->idagent->text();
    QString nom = ui->nomagent->text();
    QString prenom = ui->prenomagent->text();
    int age = ui->age->text().toInt();
    int iddep = ui->iddep->text().toInt();
    QString poste = ui->poste->currentText();
    QString adresse = ui->adresse->text();
    QString mdp = ui->mdp->text();



  Agent a(idagent, nom, prenom,age,iddep,poste,adresse,mdp);
  bool test=a.ajouter_ag();
  if(test){

      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }


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

void Menu_agent::on_pb_supprimer_clicked()
{

    QString numagent = ui->idagent_supp->text();



bool test=tmpagent.supprimer_ag(numagent);
if(test){
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
    }
    ui->tabagent->setModel(tmpagent.afficher_ag());//refresh
    QMessageBox::information(this, QObject::tr("Supprimer un Agent"),
                QObject::tr("Agent supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(this, QObject::tr("Supprimer un Agent"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
void Menu_agent :: on_pb_modifier_clicked()
{
    QString idagent = ui->idagent_4->text();
    QString nom = ui->nomagent_4->text();
    QString prenom = ui->prenomagent_4->text();
    int age = ui->age_4->text().toInt();
    int iddep = ui->iddep_4->text().toInt();
    QString poste = ui->poste_4->currentText();
    QString adresse = ui->adresse_4->text();
    QString mdp = ui->mdp_4->text();


    Agent a(idagent, nom, prenom,age,iddep,poste,adresse,mdp);
    bool test=a.modifier_ag(idagent);
    if(test){
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }

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







void Menu_agent::on_show_clicked()
{
    ui->tabagent->setModel(tmpagent.afficher_ag());
}


void Menu_agent::on_Rechercher_clicked()
{
    QString numagent = ui->lineEdit_rechercher->text();
      ui->tabrechercher->setModel(tmpagent.rechercher(numagent));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher un agent"),
      QObject::tr("agent recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_agent::on_affichertri_clicked()
{
    ui->tabaffiche->setModel(tmpagent.trier_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Rechercher une departement"),
    QObject::tr("Departement trié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_agent::on_Load_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT POSTE FROM AGENT_ROLE");
    query->exec();
    modal->setQuery(*query);
    ui->poste->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void Menu_agent::on_Load_2_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT POSTE FROM AGENT_ROLE");
    query->exec();
    modal->setQuery(*query);
    ui->poste_4->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void Menu_agent::on_pb_ajouter_type_clicked()
{
    QString desp = ui->textEdit->toPlainText();
    QString poste = ui->lineEdit_poste->text();


  Agent_type type(poste, desp);
  bool test=type.ajouter_type();


  if(test){

      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }

      foreach(QTextEdit* te, findChildren<QTextEdit*>()) {
          te->clear();
      }

    QMessageBox::information(this, QObject::tr("Ajouter un type d'annonce"),
    QObject::tr("Type ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un type d'annonce"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_agent::on_pb_supprimer_type_clicked()
{
    QString idagent= ui->idagent_supp->text();
    bool test=tmpagent_type.supprimer_type(idagent);

    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer un role d'agent"),
                QObject::tr("type supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer un role d'agent"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_agent::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void Menu_agent::on_next_clicked()
{
    this->close();
    Menu_departement * m = new Menu_departement(this);
    m->show();
}
