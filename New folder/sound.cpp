#include "sound.h"
#include "ui_sound.h"

void mettremusic()
{
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/button-19.mp3"));
    music->play();
}
