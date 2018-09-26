#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "monster.h"
#include "paccy.h"
#include "zeichenfeld.h"


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
int random_number = rand() % 700;
setPos(random_number,0);

setPixmap(QPixmap(":/new/prefix1/enny.png"));

QTimer * timer = new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(move()));
timer->start(50);
}

void Enemy::move(){
setPos(x(),y()+5);

if (pos().y() > 600){
game->health->decrease();
scene()->removeItem(this);
delete this;
}
}
