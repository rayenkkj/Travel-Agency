#include "menu_media.h"
#include "ui_menu_media.h"
#include "menu_compagne.h"
#include "media.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>
#include "mainwindow.h"

Menu_media::Menu_media(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_media)
{
    ui->setupUi(this);
    ui->tabmedia->setModel(tmpmedia.afficher());

}

Menu_media::~Menu_media()
{
    delete ui;
}




void Menu_media::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
       QString nom= ui->lineEdit_nom->text();
       int nb_abonnees= ui->lineEdit_nb->text().toInt();
     media e(id,nom,nb_abonnees);
     bool test=e.ajouter();
     if(test)
   {ui->tabmedia->setModel(tmpmedia.afficher());//refresh
   QMessageBox::information(this, QObject::tr("Ajouter un media"),
                     QObject::tr("media ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(this, QObject::tr("Ajouter un media"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}

void Menu_media::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpmedia.supprimer(id);
    if(test)
    {ui->tabmedia->setModel(tmpmedia.afficher());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer un media"),
                    QObject::tr("media supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer un media"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Menu_media::on_pb_modifier_clicked()
{

    QString nom = ui->lineEdit_2->text();
   int id=ui->lineEdit->text().toInt();
   int nb_abonnees=ui->lineEdit_3->text().toInt();
   tmpmedia = media(id,nom,nb_abonnees);
   bool test=tmpmedia.Modifier(id);
   if(test)
   {ui->tabmedia->setModel(tmpmedia.afficher());
       QMessageBox::information(this, QObject::tr("Modifier Un media"),
                         QObject::tr("media Modifié\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(this, QObject::tr("Modifier Un media"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}





void Menu_media::on_pushButton_2_clicked()
{
    QString nom= ui->lineEdit_id_7->text();
    int nb_abonnees =ui->lineEdit_id_8->text().toInt() ;
    bool test=tmpmedia.exist(nom,nb_abonnees) ;
    ui->tabmedia->setModel(tmpmedia.afficher()) ;
}

void Menu_media::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void Menu_media::on_next_clicked()
{
    this->close();
    menu_compagne * m = new menu_compagne(this);
    m->show();
}
