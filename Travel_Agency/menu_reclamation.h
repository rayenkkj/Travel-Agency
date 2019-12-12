#ifndef MENU_RECLAMATION_H
#define MENU_RECLAMATION_H
#include "reclamation.h"
#include "reclamation_type.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPrintDialog>
#include <QTimer>
#include <QDialog>

namespace Ui {
class menu_reclamation;
}

class menu_reclamation : public QDialog
{
    Q_OBJECT

public:
    explicit menu_reclamation(QWidget *parent = nullptr);
    ~menu_reclamation();

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

    void on_pb_back_clicked();

    void on_next_clicked();

private:
    Ui::menu_reclamation *ui;
    Reclamation tmpreclamation;
    Reclamation_type tmpreclamation_type;
    QMediaPlayer* player;
    QByteArray data;
    QTimer *timer;
};

#endif // MENU_RECLAMATION_H









