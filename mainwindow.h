#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "annonce.h"
#include "annonce_type.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include<QTimer>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_ajouter_type_clicked();
    void on_pb_modifier_clicked();

    void on_load_clicked();

    void on_pushButton_clicked();

    void on_load_2_clicked();

    void on_pb_asc_tri_clicked();

    void on_pb_desc_tri_clicked();

    void on_pb_aff_pays_clicked();

    void on_pb_supprimer_type_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void timefct();

private:

    Ui::MainWindow *ui;
    Annonce tmpannonce;
    Annonce_type tmpannonce_type;
    QMediaPlayer* player;
    QTimer *timer;

};

#endif // MAINWINDOW_H
