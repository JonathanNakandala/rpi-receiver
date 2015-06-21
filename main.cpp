#include <globalVar.h>

#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>

#include <QObject>

qint8 deviceStatusArray [NUMBER_OF_PINS] = {};
#include "receiver.h"
#include "transmitter.h"
#include "control.h"
int main(int argc, char *argv[])
{


    QCoreApplication app(argc, argv);
    qDebug() << "Start of Program" << endl;

    receiver lol;

    lol.receive();
    qDebug() << "END HERE PLZ" << endl << endl;

   control control;
   control.setWrite(NUMBER_OF_PINS);
    return app.exec();
}
