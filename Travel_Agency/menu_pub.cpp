#include "menu_pub.h"
#include "ui_menu_pub.h"
#include "menu_annonce.h"
#include "pub.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

Menu_pub::Menu_pub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_pub)
{
    ui->setupUi(this);
    ui->tabmedia_3->setModel(tmpp.afficher());

}

Menu_pub::~Menu_pub()
{
    delete ui;
}


void Menu_pub::on_pushButton_4_clicked()
{
     int id_comp = ui->lineEdit_7->text().toInt();
     QString description= ui->lineEdit_9->text();
     int id_media= ui->lineEdit_8->text().toInt();
     pub c(id_media,description,id_comp);
     bool test=c.ajouter();
     if(test){
         ui->tabmedia_3->setModel(tmpp.afficher());//refresh
         QMessageBox::information(this, QObject::tr("Ajouter une pub"),
                     QObject::tr("pub ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(this, QObject::tr("Ajouter un pub"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_pub::on_pb_supprimer_3_clicked()
{
   int id_comp = ui->lineEdit_id_12->text().toInt();
   int id_media= ui->lineEdit_id_13->text().toInt();
   bool test=tmpp.supprimer(id_comp, id_media);
   if(test)
   {ui->tabmedia_3->setModel(tmpp.afficher());//refresh
       QMessageBox::information(this, QObject::tr("Supprimer une pub"),
                   QObject::tr("pub supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(this, QObject::tr("Supprimer une pub"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Menu_pub::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}


void Menu_pub::on_next_clicked()
{
    this->close();
    Menu_annonce * m = new Menu_annonce(this);
    m->show();
}
