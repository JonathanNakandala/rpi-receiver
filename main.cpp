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

    // Starts the listener of the Program
    receiver receiveInstance;
    receiveInstance.receive();

    // Sets the GPIO pins to the output mode
    control control;
    control.setWrite(NUMBER_OF_PINS);

    return app.exec();
}
