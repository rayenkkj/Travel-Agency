#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "typedegestion.h"
#include <QMessageBox>
#include "song.h"
#include "mainmenu.h"
#include <iostream>
#include "arduino.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabreclamation->setModel(tmpreclamation.afficher_rec());

    connect0 = new Typedegestion(this);

    QPixmap pix("C:/Users/hamed/Desktop/SUMMER FILES/pictures/blue_moon1.jpg");
    ui->label_pic->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete connect0;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin = ui->lineEdit_cin->text().toInt();
    int age = ui->lineEdit_age->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Rec a(cin, age, nom,prenom);
  bool test=a.ajouter_rec();
  if(test){
      buttonsound();
   // ui->tabreclamation->setModel(tmpreclamation.afficher_rec());   //refresh
    QMessageBox::information(this, QObject::tr("Ajouter une reclamation"),
    QObject::tr("reclamation ajouté.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {
      errorsound();
      QMessageBox::critical(this, QObject::tr("Ajouter une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
}


void MainWindow::on_pb_supprimer_clicked()
{
int cin = ui->lineEdit_codean_2->text().toInt();
bool test=tmpreclamation.supprimer_rec(cin);
if(ui->lineEdit_codean_2->text().isEmpty() )
{
    errorsound();
QMessageBox::critical(this, QObject::tr("Supprimer une reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else if(tmpreclamation.search(cin) == false)
{
    errorsound();
QMessageBox::critical(this, QObject::tr("Supprimer une reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

else if(test)
{
    buttonsound();
        //ui->tabreclamation->setModel(tmpreclamation.afficher_rec());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("reclamation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}



void MainWindow::on_pb_modifier_clicked()
{
    int cin = ui->lineEdit_2->text().toInt();
    int age = ui->lineEdit_3->text().toInt();
    QString nom= ui->lineEdit_4->text();
    QString prenom= ui->lineEdit_5->text();
  Rec a(cin, age, nom,prenom);
  bool test=a.modifier_rec();
  if(test){
        buttonsound();
   // ui->tabreclamation->setModel(tmpreclamation.afficher_rec());   //refresh
    QMessageBox::information(this, QObject::tr("Modifier une reclamation"),
    QObject::tr("Réclamation modifié.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
        errorsound();
      QMessageBox::critical(this, QObject::tr("Modifier une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_Rechercher_clicked()
{
    int numrec = ui->lineEdit_rechercher->text().toInt();
    if(ui->lineEdit_rechercher->text().isEmpty())
    {
        errorsound();
        QMessageBox::critical(this, QObject::tr("Rechercher une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        buttonsound();
      ui->tabreclamation_2->setModel(tmpreclamation.recherche_rec(numrec));   //refresh
      QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
      QObject::tr("Réclamation recherché.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pb_TRI_clicked()
{
    buttonsound();
    ui->tabreclamation_3->setModel(tmpreclamation.trier_rec());   //refresh
    QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
    QObject::tr("Réclamation recherché.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_afficher_clicked()
{
    buttonsound();
ui->tabreclamation->setModel(tmpreclamation.afficher_rec());
int res=5;
cout<<tmpreclamation.test(res)<<endl;
}



void MainWindow::on_pb_next_clicked()
{
     buttonsound();
    this->connect0->show();
}

void MainWindow::on_pb_back_2_clicked()
{
    buttonsound();
    this->hide();
}

void MainWindow::on_affect_clicked()
{
    buttonsound();
 QString thx=ui->lineEdit_cin->text();
             ui->lineEdit_12->setText(thx);
             thx=ui->lineEdit_nom->text();
                          ui->lineEdit_9->setText(thx);
                          thx=ui->lineEdit_prenom->text();
                                       ui->lineEdit_11->setText(thx);
                                       thx=ui->lineEdit_age->text();
                                                    ui->lineEdit_10->setText(thx);
                                                    int i=0;
   do{
      i++;
      ui->horizontalSlider->setValue(i);
      }while(ui->horizontalSlider->value()<99);
                                                    if(ui->horizontalSlider->value() == 99)
                                                    {
                                                        QMessageBox::information(this, QObject::tr("Modifier une reclamation"),
                                                        QObject::tr("Dérnier Réclamation.\n"
                                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                                                    }
}

void MainWindow::on_pb_update_clicked()
{
    buttonsound();
 QString thx=ui->lineEdit_cin->text();
             ui->lineEdit->setText(thx);
             thx=ui->lineEdit_nom->text();
                          ui->lineEdit_6->setText(thx);
                          thx=ui->lineEdit_prenom->text();
                                       ui->lineEdit_7->setText(thx);
                                       thx=ui->lineEdit_age->text();
                                                    ui->lineEdit_8->setText(thx);
}

/*void MainWindow::on_pushButton_2_clicked()
{
    int th=ui->lineEdit_13->text().toInt();
    bool test1=false;
    test1=tmpreclamation.search(th);
    if(test1 == true)
    {
        QMessageBox::information(this, QObject::tr("Rechercher une reclamation"),
        QObject::tr("Réclamation recherché.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if((ui->lineEdit_13->text().isEmpty()) || (test1 == false) || (ui->lineEdit_13->text() != th))
    {
        errorsound();
        QMessageBox::critical(this, QObject::tr("Rechercher une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}*/

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
    {
        ui->label_3->setText("ON");
    }
    else if(data=="0")
    {
        ui->label_3->setText("OFF");
    }
}

void MainWindow::on_ON_button_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_OFF_Button_clicked()
{
    A.write_to_arduino("0");
}


void MainWindow::on_Plus_Button_clicked(int x)
{
    //x=A.arduinoReadData(&x);
    //A.write_to_arduino("2");
    if(c>9)
    {
        c=0;
    }
    x=c;
    c++;
    A.arduinoWriteData(x);
    x=c;
}

void MainWindow::on_Minus_Button_clicked(int x)
{
    //A.write_to_arduino("3");
    //A.arduinoReadData(&x);
    if(c<0)
    {
        c=9;
    }
    c--;
    x=c;
    A.arduinoWriteData(x);
    x=c;
}
