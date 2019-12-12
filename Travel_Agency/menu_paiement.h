#ifndef MENU_PAIEMENT_H
#define MENU_PAIEMENT_H
#include "paiement.h"
#include <QDialog>

namespace Ui {
class Menu_paiement;
}

class Menu_paiement : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_paiement(QWidget *parent = nullptr);
    ~Menu_paiement();
private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_asc_tri_clicked();
    void on_pb_afficher_clicked();
    void on_pb_back_clicked();

    void on_next_clicked();

private:
    Ui::Menu_paiement *ui;
    paiement tmppaiement;
};

#endif // MENU_PAIEMENT_H








