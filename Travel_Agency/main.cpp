#include "mainmenu.h"
#include "mainwindow.h"
#include "connection.h"
#include "mainmenu.h"
#include <QMediaPlayer>
#include <QApplication>
#include <QMessageBox>
#include <QtWidgets>
#include <QWidget>
#include <QtDebug>
#include <QDialog>
#include <QMediaPlaylist>



int main(int argc, char *argv[])
{
    //loop play
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("C:/Users/RayenKKJ/Desktop/Travel Agency Integrated/Travel_Agency/Mortified.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    QApplication a(argc, argv);
    MainMenu w;
    Connection c;

    try {
        c.createconnect();
        w.show();
    } catch (QString s) {
        qDebug()<<s;
    }

    return a.exec();
}

