#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "monster.h"
#include "paccy.h"
#include "zeichenfeld.h"

#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGui>

Game::Game(QWidget *parent){

QPushButton *quit = new QPushButton(tr("Ende"));
quit->setFont(QFont("Times", 20, QFont::Bold));
connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
QPushButton *start = new QPushButton(tr("Start"));
start->setFont(QFont("Times", 20, QFont::Bold));
connect(start, SIGNAL(clicked()), this, SLOT(start()));
QPushButton *stop = new QPushButton(tr("Stop"));
stop->setFont(QFont("Times", 20, QFont::Bold));
connect(stop, SIGNAL(clicked()), this, SLOT(stop()));
QPushButton *speichern = new QPushButton(tr("Speichern"));
speichern->setFont(QFont("Times", 20, QFont::Bold));
connect(speichern, SIGNAL(clicked()), this, SLOT(saveFile()));
QPushButton *laden = new QPushButton(tr("Laden"));
laden->setFont(QFont("Times", 20, QFont::Bold));
connect(laden, SIGNAL(clicked()), this, SLOT(loadFile()));

meinZeichenFeld = new zeichenFeld;

QGridLayout *gridLayout = new QGridLayout;
gridLayout->addWidget(quit, 0, 0);
gridLayout->addWidget(start, 1, 0);
gridLayout->addWidget(stop, 2, 0);
gridLayout->addWidget(speichern, 3, 0);
gridLayout->addWidget(laden, 4, 0);
gridLayout->addWidget(meinZeichenFeld, 0, 1, 3, 1);
gridLayout->setColumnStretch(1, 10);
setLayout(gridLayout);

scene = new QGraphicsScene();
scene->setSceneRect(0,0,800,600);

setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(800,600);
setPalette(QPalette(QColor(Qt::black)));
player = new Player();
player->setPos(400,500);
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
scene->addItem(player);
score = new Score();
scene->addItem(score);
health = new Health();
health->setPos(health->x(),health->y()+25);
scene->addItem(health);
timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
show();
}

void Game::start(void)
{
timer->start(2000);
}

void Game::stop(void)
{
timer->stop();

}
void Game::saveFile(void)
{
QFileDialog dialog(this);
QString fileName;
QFile file;

dialog.setFileMode(QFileDialog::AnyFile);
fileName = dialog.getSaveFileName(this,
tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

if (fileName.isNull()==false)
{
file.setFileName(fileName);
if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
{
QMessageBox::warning(this, tr("Fehler"),
tr("Folgende Datei funktionert nicht: ") + fileName,QMessageBox::Ok);
}
meinZeichenFeld->serialize(file);
file.close();
return;
}
}

void Game::loadFile(void)
{
QFileDialog dialog(this);
QString fileName;
QFile file;

dialog.setFileMode(QFileDialog::AnyFile);
fileName = dialog.getOpenFileName(this,
tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

if (!fileName.isNull())
{
file.setFileName(fileName);
if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
{
QMessageBox::warning(this, tr("Fehler"),
tr("Folgende Datei funktioniert nicht: ") + fileName,QMessageBox::Ok);
}
meinZeichenFeld->deserialize(file);
file.close();
return;
}
}
