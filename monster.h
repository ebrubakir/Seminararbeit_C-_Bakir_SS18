#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Enemy: public QObject,public QGraphicsPixmapItem{
Q_OBJECT
public:
Enemy(QGraphicsItem * parent=0);
public slots:
void move();
};

#endif
