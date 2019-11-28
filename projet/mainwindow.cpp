#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "media.h"
#include <QDebug>
#include <QMessageBox>
#include "compagne.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tab_media->setModel(tmp_MEDIA.afficher());
    QPixmap pic("C:\\Users\\aziz\\Desktop\\pic.png");
    ui->label_pic->setPixmap(pic);
    ui->label_pic2->setPixmap(pic);
    ui->label_pic_3->setPixmap(pic);
    ui->label_pic_4->setPixmap(pic);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    std::string nom_media=ui->lineEdit_nom->text().toStdString();
    int NB_FOLLOWERS=ui->lineEdit_NB_FOLLOWERS->text().toInt();
    MEDIA e(id_media,nom_media,NB_FOLLOWERS);
    bool test=e.ajouter();
    if (test) {qDebug()<<"media ajoute";

    ui->tab_employe->setModel(tmp_media.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un media"),
                      QObject::tr("media ajouté.\n"
                                  "Click OK."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un media"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}}

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->lineEdit_id_supp->text().toInt();
    bool test=tmp_MEDIA.supprimer(id);
    if (test){qDebug()<<"employe supprimer";
       ui->media->setModel(tmp_media.afficher());
       QMessageBox::information(nullptr, QObject::tr("supprimer un media"),
                         QObject::tr("media supprimé.\n"
                                     "Click OK."), QMessageBox::Ok);

       }
         else{
             QMessageBox::critical(nullptr, QObject::tr("supprimer un media"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

   }
}



void MainWindow::on_pb_modifier_clicked()
{
    int id_media=ui->lineEdit_id_a_modifier->text().toInt();
    std::string nom_media=ui->lineEdit_nom_modif->text().toStdString();

    int nb_flowers=ui->nb_flowers_a_modif->text().toInt();
    tmp_MEDIA = media(id_media,nom_media,nb_flowers);

    bool test=tmp_MEDIA.modifier(id);
    if (test){
        ui->media->setModel(tmp_media.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un media"),
                          QObject::tr("media modifié.\n"
                                      "Click OK."), QMessageBox::Ok);

        }
          else{
              QMessageBox::critical(nullptr, QObject::tr("modifier un media"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }

}



void MainWindow::on_pb_ajouter_dep_clicked()
{
    int id_comp=ui->lineEdit_id->text().toInt();
    QString nom_comp=ui->lineEdit_nom_dep->text();
    int telephone=ui->lineEdit_nbr_employe_dep->text().toInt();

    COMPAGNE d(int,QString,int);
    bool test=d.ajouter_comp();
    if (test) qDebug()<<"compagne ajoute";

    ui->tab_departement->setModel(tmp_compagne.afficher_comp());
}



void MainWindow::on_pb_modif_dep_clicked()
{
    int id_comp=ui->id_comp_a_modif->text().toInt();
    QString nom_comp=ui->nom_comp_modif->text();
    int telephone=ui->telephone_a_modif->text().toInt();
    COMPAGNE d(int,QString,int);
    bool test=tmp_compagne.modifier_comp(id);
    if (test) ui->compagne->setModel(tmp_compagne.afficher_comp());
}



void MainWindow::on_pb_supp_dep_clicked()
{
    int id=ui->id_dep_supp->text().toInt();
    bool test=tmp_compagne.supprimer_comp(id);
    if (test)
       ui->compagne->setModel(tmp_compagne.afficher_comp());
}

/*void MainWindow::on_pb_affecter_conge_clicked()
{

    int id=ui->lineEdit_id_conge->text().toInt();
    int conge=set_conge(ui->lineEdit_dure_conge->text().toInt());
    employe e(id,nom,prenom,heures,heures_s,salaire,conge);
    bool test=e.affecter_conge();
}*/

/*void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

}*/

/*void MainWindow::on_pb_afficher_employe_du_mois_clicked()
{
    ui->tab_employe_du_mois->setModel(tmp_employe.select_e());
}*/

void MainWindow::on_pushButton_clicked()
{ MEDIA e(int id,std::string nom_media);
    int id=ui->lineEdit_id->text().toInt();
    std::string nom_media=ui->lineEdit_nom->text().toStdString();
    bool test=e.ajouter();
    if (test) {qDebug()<<"media ajoute";

    ui->tab_media->setModel(tmp_media.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un media"),
                      QObject::tr("media ajouté.\n"
                                  "Click OK."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un media"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}}
