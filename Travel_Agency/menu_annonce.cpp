#include "menu_annonce.h"
#include "ui_menu_annonce.h"
#include "menu_client.h"
#include "annonce.h"
#include "annonce_type.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

Menu_annonce::Menu_annonce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_annonce)
{
    ui->setupUi(this);
    ui->tabannonce->setModel(tmpannonce.afficher_an());

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefct()));
    timer->start(1000);

}

Menu_annonce::~Menu_annonce()
{
    delete ui;
}




void Menu_annonce::on_pb_ajouter_clicked(){

    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QValidator *validator_int=new QRegExpValidator(QRegExp("[0-9]+"),this);


    int codean = ui->lineEdit_codean->text().toInt();
    ui->lineEdit_codean->setValidator(validator_int);

    int nbplace = ui->lineEdit_nbplace->text().toInt();
    ui->lineEdit_nbplace->setValidator(validator_int);

    QString pays = ui->lineEdit_pays->text();
    ui->lineEdit_codean->setValidator(validator_String);

    QString typean = ui->comboBox_typean->currentText();

    int idcompagne = ui->lineEdit_idcompagne->text().toInt();
    ui->lineEdit_idcompagne->setValidator(validator_int);

    int prix = ui->lineEdit_prix->text().toInt();
    ui->lineEdit_prix->setValidator(validator_int);

  Annonce a(codean, nbplace, pays, typean, idcompagne, prix);
  bool test=a.ajouter_an();
  ui->tabannonce->setModel(tmpannonce.afficher_an());   //refresh


  if(test){
      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }

    QMessageBox::information(this, QObject::tr("Ajouter une annonce"),
    QObject::tr("Annonce ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

  }else
      QMessageBox::critical(this, QObject::tr("Ajouter une annonce"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void Menu_annonce::on_pb_supprimer_clicked(){

    int codean = ui->lineEdit_codean_2->text().toInt();
    bool test=tmpannonce.supprimer_an(codean);
    ui->tabannonce->setModel(tmpannonce.afficher_an());//refresh



        if(test){

            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                 le->clear();}


            QMessageBox::information(this, QObject::tr("Supprimer une annonce"),
                    QObject::tr("Annonce supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

         }else
            QMessageBox::information(this, QObject::tr("Supprimer une annonce"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}





void Menu_annonce::on_pb_ajouter_type_clicked(){

    QString desp = ui->textEdit->toPlainText();
    QString typean = ui->lineEdit_type->text();

    Annonce_type type(typean, desp);
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

void Menu_annonce::on_pb_modifier_clicked(){

    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    QValidator *validator_int=new QRegExpValidator(QRegExp("[0-9]+"),this);


    int codean = ui->lineEdit_codean->text().toInt();
    ui->lineEdit_codean->setValidator(validator_int);

    int nbplace = ui->lineEdit_nbplace->text().toInt();
    ui->lineEdit_nbplace->setValidator(validator_int);

    QString pays = ui->lineEdit_pays->text();
    ui->lineEdit_codean->setValidator(validator_String);

    QString typean = ui->comboBox_typean->currentText();

    int idcompagne = ui->lineEdit_idcompagne->text().toInt();
    ui->lineEdit_idcompagne->setValidator(validator_int);

    int prix = ui->lineEdit_prix->text().toInt();
    ui->lineEdit_prix->setValidator(validator_int);


        Annonce a(codean, nbplace, pays, typean, idcompagne, prix);
        bool test=a.modifier_an(codean);

        ui->tabannonce->setModel(tmpannonce.afficher_an());   //refresh



        if(test && a.search(codean)==true){


            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
               le->clear();
            }

          QMessageBox::information(this, QObject::tr("Modifier une annonce"),
          QObject::tr("Annonce modifiée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);


      }
        else
            QMessageBox::critical(this, QObject::tr("Modifier une annonce"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void Menu_annonce::on_load_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_AN FROM ANNONCE_TYPE");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typean->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void Menu_annonce::on_load_2_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_AN FROM ANNONCE_TYPE");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typean_2->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void Menu_annonce::on_pushButton_clicked(){
    ui->tabannonce->setModel(tmpannonce.afficher_an());
}

void Menu_annonce::on_pb_asc_tri_clicked(){
    ui->tabannonce_tri->setModel(tmpannonce.afficher_asc());
}

void Menu_annonce::on_pb_desc_tri_clicked(){
    ui->tabannonce_tri->setModel(tmpannonce.afficher_desc());
}

void Menu_annonce::on_pb_aff_pays_clicked(){
    QString pays = ui->lineEdit_aff_pays->text();
    ui->tabannonce_aff_pays->setModel(tmpannonce.afficher_pays(pays));
}

void Menu_annonce::on_pb_supprimer_type_clicked(){

    QString typean= ui->lineEdit_typean_supp->text();
    bool test=tmpannonce_type.supprimer_type(typean);

    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer un type d'annonce"),
                QObject::tr("type supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer un type d'annonce"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Menu_annonce::timefct()
{
    QTime time  = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label->setText(time_text);
    ui->label_2->setText(time_text);
    ui->label_3->setText(time_text);
    ui->label_4->setText(time_text);
    ui->label_5->setText(time_text);
    ui->label_6->setText(time_text);
    ui->label_7->setText(time_text);

}

void Menu_annonce::on_pushButton_2_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabannonce->render(&printer);
}

void Menu_annonce::on_pushButton_3_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabannonce->render(&printer);
}

void Menu_annonce::on_pushButton_4_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabannonce->render(&printer);
}

void Menu_annonce::on_pb_modifer_type_clicked()
{
    QString typean = ui->lineEdit_type_modif->text();
    QString typean_nv= ui->lineEdit_type_modif_nv->text();
    QString desp= ui->textEdit_modif->toPlainText();

    Annonce_type a(typean, desp);
    bool test=a.modifier_type(typean, typean_nv);

    ui->tabannonce_aff->setModel(tmpannonce_type.afficher_type());   //refresh



    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }

        foreach(QTextEdit* te, findChildren<QTextEdit*>()) {
            te->clear();
        }

      QMessageBox::information(this, QObject::tr("Modifier un type"),
      QObject::tr("Type modifiée.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);


  }
    else
        QMessageBox::critical(this, QObject::tr("Modifier un type"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_annonce::on_pb_typeaff_clicked()
{
     ui->tabannonce_aff->setModel(tmpannonce_type.afficher_type());
}

void Menu_annonce::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void Menu_annonce::on_next_clicked()
{
    this->close();
    Menu_client * m = new Menu_client(this);
    m->show();
}
