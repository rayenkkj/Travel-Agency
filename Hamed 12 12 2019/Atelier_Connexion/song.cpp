#include "song.h"


void mettreMusique()
{
    QMediaPlayer * music=new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/mario.mp3"));
    music->play();
}

void buttonsound()
{
    QMediaPlayer * music1=new QMediaPlayer();
    music1->setMedia(QUrl("qrc:/button-19.mp3"));
    music1->play();
}

void errorsound()
{
    QMediaPlayer * music2=new QMediaPlayer();
    music2->setMedia(QUrl("qrc:/erro.mp3"));
    music2->play();
}
