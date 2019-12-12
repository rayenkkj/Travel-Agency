#ifndef AFFECTATION_H
#define AFFECTATION_H

#include <QDialog>
#include "reclamation.h"

namespace Ui {
class Affectation;
}

class Affectation : public QDialog
{
    Q_OBJECT

public:
    explicit Affectation(QWidget *parent = nullptr);
    ~Affectation();

private slots:
    void on_pb_Rechercher_clicked();

    void on_pb_Rechercher_2_clicked();

    void on_pb_Affecter_clicked();


private:
    Ui::Affectation *ui;
    Rec tmpreclamation1;
    Rec2 tmpreclamation3;
};

#endif // AFFECTATION_H
