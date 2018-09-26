#include <QGraphicsScene>
#include <QKeyEvent>
#include "essen.h"
#include "gelb.h"
#include "monster.h"
#include "paccy.h"
#include "zeichenfeld.h"



Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
setPixmap(QPixmap(":/new/prefix1/paccy.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
if (event->key() == Qt::Key_Left){
if (pos().x() > 0)
setPos(x()-10,y());
}
else if (event->key() == Qt::Key_Right){
if (pos().x() + 100 < 800)
setPos(x()+10,y());
}
else if (event->key() == Qt::Key_Space){
Bullet * bullet = new Bullet();
bullet->setPos(x(),y());
scene()->addItem(bullet);
}
}

void Player::spawn(){
Enemy * enemy = new Enemy();
scene()->addItem(enemy);
}
