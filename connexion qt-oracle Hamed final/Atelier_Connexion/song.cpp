#include "song.h"


void mettreMusique()
{
    QMediaPlayer * music=new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/BOROS.mp3"));
    music->play();
}

void buttonsound()
{
    QMediaPlayer * music1=new QMediaPlayer();
    music1->setMedia(QUrl("qrc:/button-19.mp3"));
    music1->play();
}
