#include "son.h"
#include "ui_son.h"
void mettreMusique()
{
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/button-19.mp3"));
    music->play();
}
