#ifndef PACCY_H
#define PACCY_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "gelb.h"
#include "teufel.h"
#include "engel.h"
#include "zeichenFeld.h"

class Game: public QGraphicsView{
Q_OBJECT
public:
Game(QWidget * parent=0);

QGraphicsScene * scene;
Player * player;
Score * score;
Health * health;
QTimer * timer;

private:
zeichenFeld *meinZeichenFeld;

private slots:
void start(void);
void stop(void);
void saveFile(void);
void loadFile(void);
};

#endif
