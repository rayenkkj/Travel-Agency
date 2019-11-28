#ifndef TYPEDEGESTION_H
#define TYPEDEGESTION_H

#include <QDialog>
#include "reclamation.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>

namespace Ui {
class Typedegestion;
}

class Typedegestion : public QDialog
{
    Q_OBJECT

public:
    explicit Typedegestion(QWidget *parent = nullptr);
    ~Typedegestion();

private slots:

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_Rechercher_2_clicked();

    void on_pb_trier_clicked();

private:
    Ui::Typedegestion *ui;
    Rec2 tmpreclamation2;
};

#endif // TYPEDEGESTION_H
