#include <globalVar.h>

#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>

#include <QObject>

qint8 deviceStatusArray [2] = {0,0};
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

//   control lol2;
//    lol2.getStatus(0);
    return app.exec();
}
