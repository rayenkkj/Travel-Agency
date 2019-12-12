#include "menu_reclamation.h"
#include "ui_menu_reclamation.h"
#include "menu_agent.h"
#include "reclamation.h"
#include "reclamation_type.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

menu_reclamation::menu_reclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_reclamation)
{
    ui->setupUi(this);
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());



    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefct()));
    timer->start(1000);

}

menu_reclamation::~menu_reclamation()
{
    delete ui;
}




void menu_reclamation::on_pb_ajouter_clicked(){

    int numrec = ui->lineEdit_numrec->text().toInt();
    int idclient = ui->lineEdit_idclient->text().toInt();
    QString description = ui->lineEdit_description->text();
    QString typerec = ui->comboBox_typerec->currentText();
    QString daterec = ui->lineEdit_date->text();


  Reclamation a(numrec, description, idclient, typerec, daterec);
  bool test=a.ajouter_rec();
  ui->tabreclamation->setModel(tmpreclamation.afficher_rec());   //refresh


  if(test){
      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }

    QMessageBox::information(this, QObject::tr("Ajouter une Reclamation"),
    QObject::tr("Reclamation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

  }else
      QMessageBox::critical(this, QObject::tr("Ajouter une Reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void menu_reclamation::on_pb_supprimer_clicked(){

    int numrec = ui->lineEdit_numrec_2->text().toInt();
    bool test=tmpreclamation.supprimer_rec(numrec);
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());//refresh



    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer une Reclamation"),
                QObject::tr("Reclamation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer une Reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void menu_reclamation::on_pb_ajouter_type_clicked(){

    QString desp = ui->textEdit->toPlainText();
    QString typerec = ui->lineEdit_typerec->text();


  Reclamation_type type(typerec, desp);
  bool test=type.ajouter_type();


  if(test){

      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();
      }

      foreach(QTextEdit* te, findChildren<QTextEdit*>()) {
          te->clear();
      }

    QMessageBox::information(this, QObject::tr("Ajouter un type de reclamation"),
    QObject::tr("Type ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un type de reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void menu_reclamation::on_pb_modifier_clicked(){

        int numrec = ui->lineEdit_numrec_modif->text().toInt();
        int idclient = ui->lineEdit_idclient_modif->text().toInt();
        QString description = ui->lineEdit_description_modif->text();
        QString typerec = ui->comboBox_typerec_2->currentText();
        QString date = ui->lineEdit_date_modif->text();



        Reclamation a(numrec, description, idclient, typerec, date);
        bool test=a.modifier_rec(numrec);

        ui->tabreclamation->setModel(tmpreclamation.afficher_rec());   //refresh



        if(test ){


            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
               le->clear();
            }

          QMessageBox::information(this, QObject::tr("Modifier une reclamation"),
          QObject::tr("Annonce modifiée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);


      }
        else
            QMessageBox::critical(this, QObject::tr("Modifier une reclamation"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void menu_reclamation::on_load_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_REC FROM RECLAMATION_CATEG");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typerec->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void menu_reclamation::on_load_2_clicked(){

    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT TYPE_REC FROM RECLAMATION_CATEG");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_typerec_2->setModel(modal);
    qDebug() <<(modal->rowCount());
}

void menu_reclamation::on_pushButton_clicked(){
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());
}

void menu_reclamation::on_pb_asc_tri_clicked(){
    ui->tabreclamation_tri->setModel(tmpreclamation.trier_rec());
}

void menu_reclamation::on_pb_desc_tri_clicked(){
    ui->tabreclamation_tri->setModel(tmpreclamation.trier_desc_rec());
}

void menu_reclamation::on_pb_aff_pays_clicked(){
    int idclient = ui->lineEdit_aff_pays->text().toInt();
    ui->tabreclamation_aff_pays->setModel(tmpreclamation.recherche_rec(idclient));
}

void menu_reclamation::on_pb_supprimer_type_clicked(){

    QString typerec= ui->lineEdit_typerec_supp->text();
    bool test=tmpreclamation_type.supprimer_type(typerec);

    if(test){

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}


        QMessageBox::information(this, QObject::tr("Supprimer un type de reclamation"),
                QObject::tr("type supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::information(this, QObject::tr("Supprimer un type de reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void menu_reclamation::timefct()
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

void menu_reclamation::on_pushButton_2_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabreclamation->render(&printer);
}

void menu_reclamation::on_pushButton_3_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabreclamation->render(&printer);
}

void menu_reclamation::on_pushButton_4_clicked(){

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return ;
    ui->tabreclamation->render(&printer);
}

void menu_reclamation::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void menu_reclamation::on_next_clicked()
{
    this->close();
    Menu_agent * m = new Menu_agent(this);
    m->show();
}
