#include "menu_client.h"
#include "ui_menu_client.h"
#include "menu_reservation.h"
#include "menu_reservation.h"
#include "connection.h"
#include "client.h"
#include "client_type.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>


Menu_client::Menu_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_client)
{
    ui->setupUi(this);
    ui->tabannonce->setModel(tmpclient.afficher_client());
}

Menu_client::~Menu_client()
{
    delete ui;
}




void Menu_client::on_pb_ajouter_clicked(){

    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QValidator *validator_int=new QRegExpValidator(QRegExp("[0-9]+"),this);


    int idclient = ui->lineEdit_id->text().toInt();
    ui->lineEdit_id->setValidator(validator_int);

    QString nom= ui->lineEdit_nom->text();
    ui->lineEdit_nom->setValidator(validator_String);

    QString prenom = ui->lineEdit_prenom->text();
    ui->lineEdit_prenom->setValidator(validator_String);

    int age = ui->lineEdit_age->text().toInt();
    ui->lineEdit_age->setValidator(validator_int);

    QString typec = ui->comboBox_typec->currentText();


    QString adresse = ui->lineEdit_adresse->text();
    ui->lineEdit_adresse->setValidator(validator_String);



    Client c(idclient, nom, prenom, age, typec, adresse);
      bool test=c.ajouter_client();
      ui->tabannonce->setModel(tmpclient.afficher_client());


      if(test){
          foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();
          }

        QMessageBox::information(this, QObject::tr("Ajouter un client"),
        QObject::tr("Client ajouté.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);

      }else
          QMessageBox::critical(this, QObject::tr("Ajouter un client"),
                      QObject::tr("Vous devez remplir tous les champs correctment \n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }



void Menu_client::on_pb_supprimer_clicked(){

    int idclient = ui->lineEdit_idclient_2->text().toInt();
    bool test=tmpclient.supprimer_client(idclient);
    ui->tabannonce->setModel(tmpclient.afficher_client());



    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer un client"),
                QObject::tr("Client supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void Menu_client::on_pb_ajouter_type_clicked(){

    QString desp = ui->textEdit->toPlainText();
    QString typec = ui->lineEdit_type->text();

  Client_type type(typec, desp);
  bool test=type.ajouter_type();





  if(test){

      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }

      foreach(QTextEdit* te, findChildren<QTextEdit*>()) {
          te->clear();
      }

    QMessageBox::information(this, QObject::tr("Ajouter un type de client"),
    QObject::tr("Type ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un type de client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Menu_client::on_pb_modifier_clicked(){


    int idclient = ui->lineEdit_idclient_modif->text().toInt();
    QString nom= ui->lineEdit_nom_modif->text();
    QString prenom = ui->lineEdit_prenom_modif->text();
    int age = ui->lineEdit_age_modif->text().toInt();
    QString typec = ui->comboBox_typec_2->currentText();
    QString adresse = ui->lineEdit_adresse_modif->text();



        Client c(idclient, nom, prenom, age, typec, adresse);
        bool test=c.modifier_client(idclient);
        ui->tabannonce->setModel(tmpclient.afficher_client());






        if(test){


            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
               le->clear();
            }

          QMessageBox::information(this, QObject::tr("Modifier un client"),
          QObject::tr("Client modifiée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);


      }
        else
            QMessageBox::critical(this, QObject::tr("Modifier un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void Menu_client::on_load_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_C FROM CLIENT_CATEGORY");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typec->setModel(modal);
    qDebug() <<(modal->rowCount());
}


void Menu_client::on_load_2_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_C FROM CLIENT_CATEGORY");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typec_2->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void Menu_client::on_pushButton_clicked(){
    ui->tabannonce->setModel(tmpclient.afficher_client());
}

void Menu_client::on_pb_asc_tri_clicked(){
    ui->tabannonce_tri->setModel(tmpclient.afficher_trie());
}


void Menu_client::on_pb_aff_client_clicked(){
    int idclient = ui->lineEdit_aff_idclient->text().toInt();
    ui->tabannonce_aff_client->setModel(tmpclient.afficher_idclient(idclient));
}

void Menu_client::on_pb_supprimer_type_clicked(){

    QString typec= ui->lineEdit_typec_supp->text();
    bool test=tmpclient_type.supprimer_type(typec);

    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer un type de client"),
                QObject::tr("type supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer un type de client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Menu_client::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}



void Menu_client::on_next_clicked()
{
    this->close();
    Menu_reservation * m = new Menu_reservation(this);
    m->show();
}
