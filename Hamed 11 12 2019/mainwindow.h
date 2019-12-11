#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include "typedegestion.h"
#include "arduino.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>


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

    void on_pb_modifier_clicked();
    void on_pb_Rechercher_clicked();

    //void on_tabreclamation_3_activated(const QModelIndex &index);

    //void on_horizontalSlider_3_sliderMoved(int position);

    void on_pb_TRI_clicked();

    void on_pb_afficher_clicked();

    void on_pb_next_clicked();

    void on_pb_back_2_clicked();

    void on_affect_clicked();

    void on_pb_update_clicked();

  //  void on_pushButton_2_clicked();

    //Part arduino:
    void update_label();

    void on_ON_button_clicked();

    void on_OFF_Button_clicked();

    void on_Plus_Button_clicked(int x=0);

    void on_Minus_Button_clicked(int x=0);

private:
    Ui::MainWindow *ui;
    Rec tmpreclamation;
    QMediaPlayer* player;
    Typedegestion* connect0;
    Arduino A;
    QByteArray data;
    int c=0;
};

#endif // MAINWINDOW_H
