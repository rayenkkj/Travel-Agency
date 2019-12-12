#ifndef MENU_ANNONCE_H
#define MENU_ANNONCE_H

#include "annonce.h"
#include "annonce_type.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include <QTimer>
#include <QDialog>


namespace Ui {
class Menu_annonce;
}

class Menu_annonce : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_annonce(QWidget *parent = nullptr);
    ~Menu_annonce();

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

    void on_pb_modifer_type_clicked();

    void on_pb_typeaff_clicked();

    void on_pb_back_clicked();

    void on_next_clicked();

private:
    Ui::Menu_annonce *ui;
    Annonce tmpannonce;
    Annonce_type tmpannonce_type;
    QMediaPlayer* player;
    QTimer *timer;

};

#endif // MENU_ANNONCE_H





