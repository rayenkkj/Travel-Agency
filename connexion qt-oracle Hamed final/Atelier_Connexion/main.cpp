#include "mainwindow.h"
#include "connection.h"
#include "mainmenu.h"
#include "song.h"
#include <QApplication>
#include <QMessageBox>
#include <QtWidgets>
#include <QWidget>
#include <QtDebug>




int main(int argc, char *argv[])
{
    QApplication ab(argc, argv);
    MainMenu w ;
    Connection c;
    mettreMusique();

    try {
        c.createconnect();
        w.show();
    } catch (QString s) {
        qDebug()<<s;
    }


    return ab.exec();
}
