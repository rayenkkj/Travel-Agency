#include "affectation.h"
#include "ui_affectation.h"
#include "song.h"
#include <iostream>
#include <QMessageBox>


Affectation::Affectation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Affectation)
{
    ui->setupUi(this);
}

Affectation::~Affectation()
{
    delete ui;
}

void Affectation::on_pb_Rechercher_clicked()
{
    int numrec = ui->lineEdit_rechercher1->text().toInt();
    if(ui->lineEdit_rechercher1->text().isEmpty())
    {
        errorsound();
        QMessageBox::critical(this, QObject::tr("Rechercher une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        buttonsound();
      ui->tabreclamation_3->setModel(tmpreclamation1.recherche_rec(numrec));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
      QObject::tr("Réclamation recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void Affectation::on_pb_Rechercher_2_clicked()
{
    int cin = ui->lineEdit_rechercher_3->text().toInt();
    if(ui->lineEdit_rechercher_3->text().isEmpty())
    {
        errorsound();
        QMessageBox::critical(this, QObject::tr("Supprimer une reclamation"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
            buttonsound();
        ui->tabreclamation_6->setModel(tmpreclamation3.recherche_rec2(cin));   //refresh
        QMessageBox::information(this, QObject::tr("Rechercher un type de reclamation"),
        QObject::tr("Type Réclamation recherché.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}





void Affectation::on_pb_Affecter_clicked()
{
    int numrec = ui->lineEdit_rechercher1->text().toInt();
    int cin = ui->lineEdit_rechercher_3->text().toInt();
    if((ui->lineEdit_rechercher_3->text().isEmpty()) || (ui->lineEdit_rechercher1->text().isEmpty()))
    {
        errorsound();
        QMessageBox::critical(this, QObject::tr("Supprimer une reclamation"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        buttonsound();
        ui->tabreclamation_7->setModel(tmpreclamation3.recherche_affect(numrec,cin));
    }

}
