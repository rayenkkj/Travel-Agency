#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtWidgets>
#include <QWidget>
#include <QtDebug>



int main(int argc, char *argv[])
{
    QApplication ab(argc, argv);
    MainWindow w ;
    w.show();
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                              QObject::tr("connection successful .\n"
                                          "Click Cancel to exit."),QMessageBox::Ok );


    }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                              QObject::tr("connection failed .\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel );

    return ab.exec();
}

