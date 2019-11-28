#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "media.h"
#include "compagne.h"

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



    void on_pb_ajouter_dep_clicked();



    void on_pb_modif_dep_clicked();



    void on_pb_supp_dep_clicked();

    void on_pb_affecter_conge_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pb_afficher_employe_du_mois_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MEDIA tmp_media;
    COMPAGNE tmp_compagne;

};

#endif // MAINWINDOW_H
