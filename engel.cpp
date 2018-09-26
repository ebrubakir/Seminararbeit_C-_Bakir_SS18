#include <QFont>
#include "paccy.h"
#include "engel.h"
#include "zeichenfeld.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
health = 3;

setPlainText(QString("Health: ") + QString::number(health));
setDefaultTextColor(Qt::white);
setFont(QFont("times",16));
}

void Health::decrease(){
health--;
setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
return health;
}
