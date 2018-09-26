#include <QtGui>
#include <QMessageBox>
#include "zeichenFeld.h"
#include "paccy.h"


zeichenFeld::zeichenFeld(QWidget *parent){

//setPalette(QPalette(QColor(5000,5000,5000)));
//setAutoFillBackground(true);
setMouseTracking(false);

timer=new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(update()));

lastX=100;
lastY=100;
increment=0;
phase=0;
}
zeichenFeld::~zeichenFeld()
{
}

void zeichenFeld::serialize(QFile &file)
{
QTextStream out(&file);

out << "p " <<lastX;

}

void zeichenFeld::deserialize(QFile &file)
{
char c;
QTextStream in(&file);
while (in.status() == QTextStream::Ok)
{
in >> c;
if (in.status() == QTextStream::ReadPastEnd) break;

if (c!='p')
{
QMessageBox::warning(this, tr("FEHLER"),
tr(" Unbekannter Fehler: ") + c,QMessageBox::Ok);
return;
}

in >> lastX;
in >> c;
}

}
