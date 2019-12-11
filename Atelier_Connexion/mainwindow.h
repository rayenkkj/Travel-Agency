#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "agent.h"
#include "departement.h"
#include <QMainWindow>
#include "role.h"

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

    void on_Supprimer2_clicked();

    void on_Ajouter2_clicked();

    void on_Modifier2_clicked();

    void on_Rechercher_clicked();



    void on_rechercherd_clicked();

    void on_affichertri_clicked();

    //void on_affichertrie2_clicked();

    void on_show_clicked();

    void on_afficherdepartement_clicked();

    void on_next_clicked();

    void on_previous_clicked();

    void on_role_clicked();




private:
    Ui::MainWindow *ui;
    Agent tmpagent;
    departement tmpdepartement;

};

#endif // MAINWINDOW_H
