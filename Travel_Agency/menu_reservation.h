#ifndef MENU_RESERVATION_H
#define MENU_RESERVATION_H
#include "reservation.h"
#include <QDialog>

namespace Ui {
class Menu_reservation;
}

class Menu_reservation : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_reservation(QWidget *parent = nullptr);
    ~Menu_reservation();


private slots:
    void on_pb_ajouter_2_clicked();
    void on_pb_supprimer_2_clicked();
    void on_pb_afficher_2_clicked();
    void on_pb_rechercher_2_clicked();
    void on_pb_back_clicked();
    void on_pb_modifer_2_clicked();

    void on_next_clicked();

private:
    Ui::Menu_reservation *ui;
    reservation tmpreservation;
};

#endif // MENU_RESERVATION_H





