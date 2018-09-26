#ifndef GELB_H
#define GELB_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
Player(QGraphicsItem * parent=0);
void keyPressEvent(QKeyEvent * event);
public slots:
void spawn();
};

#endif
