#ifndef MENU_DEPARTEMENT_H
#define MENU_DEPARTEMENT_H
#include "departement.h"
#include <QDialog>

namespace Ui {
class Menu_departement;
}

class Menu_departement : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_departement(QWidget *parent = nullptr);
    ~Menu_departement();

private slots:

    void on_Supprimer2_clicked();

    void on_Ajouter2_clicked();

    void on_Modifier2_clicked();

    void on_rechercherd_clicked();

    void on_afficherdepartement_clicked();

    void on_pb_back_clicked();

    void on_affichertrie2_clicked();

    void on_next_clicked();

private:
    Ui::Menu_departement *ui;
    departement tmpdepartement;
};

#endif // MENU_DEPARTEMENT_H













