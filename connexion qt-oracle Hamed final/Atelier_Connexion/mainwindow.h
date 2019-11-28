#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include "typedegestion.h"
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

private:
    Ui::MainWindow *ui;
    Rec tmpreclamation;
    QMediaPlayer* player;

};

#endif // MAINWINDOW_H
