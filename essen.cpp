#include <typeinfo>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGridLayout>
#include "essen.h"
#include "monster.h"
#include "paccy.h"
#include "zeichenfeld.h"



extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

setRect(0,0,10,50);

QTimer * timer = new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(move()));

timer->start(50);
}

void Bullet::move(){

QList<QGraphicsItem *> colliding_items = collidingItems();

for (int i = 0, n = colliding_items.size(); i < n; ++i){
if (typeid(*(colliding_items[i])) == typeid(Enemy)){

game->score->increase();

scene()->removeItem(colliding_items[i]);
scene()->removeItem(this);

delete colliding_items[i];
delete this;
return;
}
}
setPos(x(),y()-10);
if (pos().y() + rect().height() < 0){
scene()->removeItem(this);
delete this;
}
}
