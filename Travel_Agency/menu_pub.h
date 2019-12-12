#ifndef MENU_PUB_H
#define MENU_PUB_H
#include "pub.h"
#include <QDialog>

namespace Ui {
class Menu_pub;
}

class Menu_pub : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_pub(QWidget *parent = nullptr);
    ~Menu_pub();

private slots:
    void on_pushButton_4_clicked();
    void on_pb_supprimer_3_clicked();
    void on_pb_back_clicked();
    void on_next_clicked();


private:
    Ui::Menu_pub *ui;
    pub tmpp ;
};

#endif // MENU_PUB_H
