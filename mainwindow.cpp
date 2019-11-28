#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "annonce.h"
#include "annonce_type.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabannonce->setModel(tmpannonce.afficher_an());

    //loop play
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("C:/Users/RayenKKJ/Desktop/connexion qt-oracle/Atelier_Connexion/Mortified.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    //one time play
   /* QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/RayenKKJ/Desktop/connexion qt-oracle/Atelier_Connexion/Mortified.mp3"));
    music->play();*/

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefct()));
    timer->start(1000);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked(){

    int codean = ui->lineEdit_codean->text().toInt();
    int nbplace = ui->lineEdit_nbplace->text().toInt();
    QString pays = ui->lineEdit_pays->text();
    QString typean = ui->comboBox_typean->currentText();
    int idcompagne = ui->lineEdit_idcompagne->text().toInt();
    int prix = ui->lineEdit_prix->text().toInt();

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



void MainWindow::on_pb_supprimer_clicked(){

    int codean = ui->lineEdit_codean_2->text().toInt();
    bool test=tmpannonce.supprimer_an(codean);
    ui->tabannonce->setModel(tmpannonce.afficher_an());//refresh



    if(test && tmpannonce.search(codean)==true){

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


void MainWindow::on_pb_ajouter_type_clicked(){

    QString desp = ui->textEdit->toPlainText();
    QString typean = ui->lineEdit_type->text();
    ui->comboBox_typean->addItem(typean);

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

void MainWindow::on_pb_modifier_clicked(){

        int codean = ui->lineEdit_codean_modif->text().toInt();
        int nbplace = ui->lineEdit_nbplace_modif->text().toInt();
        QString pays = ui->lineEdit_pays_modif->text();
        QString typean= ui->comboBox_typean_2->currentText();
        int idcompagne= ui->lineEdit_idcompagne_modif->text().toInt();
        int prix = ui->lineEdit_prix_modif->text().toInt();


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



void MainWindow::on_load_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_AN FROM ANNONCE_TYPE");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typean->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void MainWindow::on_load_2_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_AN FROM ANNONCE_TYPE");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typean_2->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void MainWindow::on_pushButton_clicked(){
    ui->tabannonce->setModel(tmpannonce.afficher_an());
}

void MainWindow::on_pb_asc_tri_clicked(){
    ui->tabannonce_tri->setModel(tmpannonce.afficher_asc());
}

void MainWindow::on_pb_desc_tri_clicked(){
    ui->tabannonce_tri->setModel(tmpannonce.afficher_desc());
}

void MainWindow::on_pb_aff_pays_clicked(){
    QString pays = ui->lineEdit_aff_pays->text();
    ui->tabannonce_aff_pays->setModel(tmpannonce.afficher_pays(pays));
}

void MainWindow::on_pb_supprimer_type_clicked(){

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

void MainWindow::timefct()
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

void MainWindow::on_pushButton_2_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabannonce->render(&printer);
}

void MainWindow::on_pushButton_3_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabannonce->render(&printer);
}

void MainWindow::on_pushButton_4_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabannonce->render(&printer);
}
