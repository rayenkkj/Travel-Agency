#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "typedegestion.h"
#include <QMessageBox>
#include "song.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());

    QPixmap pix("C:/Users/hamed/Desktop/SUMMER FILES/pictures/blue_moon1.jpg");
    ui->label_pic->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin = ui->lineEdit_cin->text().toInt();
    int age = ui->lineEdit_age->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Rec a(cin, age, nom,prenom);
  bool test=a.ajouter_rec();
  buttonsound();
  if(test){
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter une reclamation"),
    QObject::tr("reclamation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_supprimer_clicked()
{
int cin = ui->lineEdit_codean_2->text().toInt();
bool test=tmpreclamation.supprimer_rec(cin);
buttonsound();
if(test)
{ui->tabreclamation->setModel(tmpreclamation.afficher_rec());//refresh
    QMessageBox::information(this, QObject::tr("Supprimer une reclamation"),
                QObject::tr("reclamation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(this, QObject::tr("Supprimer une reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_modifier_clicked()
{
    int cin = ui->lineEdit_2->text().toInt();
    int age = ui->lineEdit_3->text().toInt();
    QString nom= ui->lineEdit_4->text();
    QString prenom= ui->lineEdit_5->text();
  Rec a(cin, age, nom,prenom);
  bool test=a.modifier_rec();
  buttonsound();
  if(test){
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());   //refresh
    QMessageBox::information(this, QObject::tr("Modifier une reclamation"),
    QObject::tr("Réclamation modifié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Modifier une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_Rechercher_clicked()
{
    buttonsound();
    int numrec = ui->lineEdit_rechercher->text().toInt();
      ui->tabreclamation_2->setModel(tmpreclamation.recherche_rec(numrec));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
      QObject::tr("Réclamation recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_TRI_clicked()
{
    buttonsound();
    ui->tabreclamation_3->setModel(tmpreclamation.trier_rec());   //refresh
    QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
    QObject::tr("Réclamation recherché.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}
