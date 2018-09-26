#ifndef ESSEN_H
#define ESSEN_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsRectItem{
Q_OBJECT
public:
Bullet(QGraphicsItem * parent=0);
public slots:
void move();
};

#endif
