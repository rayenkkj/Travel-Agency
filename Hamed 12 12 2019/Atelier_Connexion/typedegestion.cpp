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
    int type_rec = ui->lineEdit_cin_2->text().toInt();
    QString des = ui->lineEdit_nom_2->text();
  Rec2 a(type_rec, des);
  bool test=a.ajouter_rec2();
  if(test){
      buttonsound();
    //ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter une reclamation"),
    QObject::tr("reclamation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      errorsound();
      QMessageBox::critical(this, QObject::tr("Ajouter une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Typedegestion::on_pb_modifier_2_clicked()
{
    int typerec = ui->lineEdit_9->text().toInt();
    QString des = ui->lineEdit_10->text();
  Rec2 a(typerec, des);
  bool test=a.modifier_rec2();
  if(test){
          buttonsound();
    //ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Modifier un type de reclamation"),
    QObject::tr("Réclamation modifié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {
      errorsound();
  QMessageBox::critical(this, QObject::tr("Modifier un type de reclamation"),
              QObject::tr("Erreur !.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
  }

}

void Typedegestion::on_pb_supprimer_2_clicked()
{
    int cin = ui->lineEdit_codean_3->text().toInt();
    bool test=tmpreclamation2.supprimer_rec2(cin);
    if(ui->lineEdit_codean_3->text().isEmpty())
    {//ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());//refresh
        errorsound();
        QMessageBox::critical(this, QObject::tr("Supprimer un type de reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    if(test)
    {
        buttonsound();

    QMessageBox::information(this, QObject::tr("Supprimer un type de reclamation"),
                QObject::tr("Type reclamation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Typedegestion::on_pb_Rechercher_2_clicked()
{
    int cin = ui->lineEdit_rechercher_2->text().toInt();
    if(ui->lineEdit_rechercher_2->text().isEmpty())
    {
        errorsound();
        QMessageBox::critical(this, QObject::tr("Supprimer une reclamation"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
            buttonsound();
        ui->tabreclamation_5->setModel(tmpreclamation2.recherche_rec2(cin));   //refresh
        QMessageBox::information(this, QObject::tr("Rechercher un type de reclamation"),
        QObject::tr("Type Réclamation recherché.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Typedegestion::on_pb_trier_clicked()
{
    buttonsound();
    ui->tabreclamation_6->setModel(tmpreclamation2.trier_rec2());   //refresh
    QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
    QObject::tr("Réclamation trié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Typedegestion::on_pb_afficher2_clicked()
{
    buttonsound();
    ui->tabreclamation_4->setModel(tmpreclamation2.afficher_rec2());//refresh
}

void Typedegestion::on_pb_back_clicked()
{
    buttonsound();
    this->hide();
}

void Typedegestion::on_affect2_clicked()
{
    buttonsound();
 QString thx=ui->lineEdit_cin_2->text();
             ui->lineEdit_19->setText(thx);
             thx=ui->lineEdit_nom_2->text();
                          ui->lineEdit_17->setText(thx);
}

void Typedegestion::on_pb_update_2_clicked()
{
    buttonsound();
 QString thx=ui->lineEdit_cin_2->text();
             /*ui->lineEdit_13->setText(thx);
             thx=ui->lineEdit_nom_2->text();
                          ui->lineEdit_14->setText(thx);*/
}
