#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu_annonce.h"
#include "menu_reclamation.h"
#include "menu_reservation.h"
#include "menu_paiement.h"
#include "menu_media.h"
#include "menu_compagne.h"
#include "menu_client.h"
#include "menu_agent.h"
#include "menu_departement.h"
#include "menu_pub.h"
#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_annonce_clicked();
    void on_pb_reclamation_clicked();
    void on_pb_reservation_clicked();
    void on_pb_paiement_clicked();
    void on_pb_media_clicked();
    void on_pb_compagne_clicked();
    void on_pb_client_clicked();
    void on_pb_agent_clicked();
    void on_pb_departement_clicked();
    void on_pb_pub_clicked();
    void on_pb_back_clicked();


private:
    Ui::MainWindow *ui;
    Menu_annonce * annonce;
    menu_reclamation * reclamation;
    Menu_reservation * reservation;
    Menu_paiement * paiement;
    Menu_media * media;
    menu_compagne * compagne;
    Menu_client * client;
    Menu_agent * agent;
    Menu_departement * departement;
    Menu_pub * pub;


};

#endif // MAINWINDOW_H
