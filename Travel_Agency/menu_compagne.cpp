#include "menu_compagne.h"
#include "ui_menu_compagne.h"
#include "menu_pub.h"
#include "compagne.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QMediaPlaylist>

menu_compagne::menu_compagne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_compagne)
{
    ui->setupUi(this);
    ui->tabmedia_2->setModel(tmpc.afficher());
    ui->tri2->setModel(tmpc.trier()) ;
}

menu_compagne::~menu_compagne()
{
    delete ui;
}


void menu_compagne::on_ajouter_clicked()
{
    int id_compagne = ui->lineEdit_4->text().toInt();
       QString nom_compagne= ui->lineEdit_5->text();
       int telephone= ui->lineEdit_6->text().toInt();
     compagne c(id_compagne,nom_compagne,telephone);
     bool test=c.ajouter();
     if(test)
   {ui->tabmedia_2->setModel(tmpc.afficher());//refresh
   QMessageBox::information(this, QObject::tr("Ajouter une compagne"),
                     QObject::tr("compagne ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(this, QObject::tr("Ajouter un compagne"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu_compagne::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    bool test=tmpc.supprimer(id);
    if(test)
    {ui->tabmedia_2->setModel(tmpc.afficher());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer un compagne"),
                    QObject::tr("compagne supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer un compagne"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu_compagne::on_pushButton_clicked()
{
    QString nom_comp = ui->lineEdit_id_5->text();
   int id_comp=ui->lineEdit_id_4->text().toInt();
   int tel=ui->lineEdit_id_6->text().toInt();
   tmpc = compagne(id_comp,nom_comp,tel);
   bool test=tmpc.Modifier(id_comp);
   if(test)
   {ui->tabmedia_2->setModel(tmpc.afficher());
       QMessageBox::information(this, QObject::tr("Modifier Un compagne"),
                         QObject::tr("compagne Modifié\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(this, QObject::tr("Modifier Un compagne"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}



void menu_compagne::on_pb_back_clicked()
{
    this->close();
    MainWindow * m = new MainWindow(this);
    m->show();
}

void menu_compagne::on_next_clicked()
{
    this->close();
    Menu_pub * m = new Menu_pub(this);
    m->show();
}
