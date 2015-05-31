#include <QCoreApplication>
#include <QDebug>
#include <QtNetwork>

#include <QApplication>

#include <QObject>
#include "receiver.h"

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);
    qDebug() << "hello beautiful world!" << endl << endl;

    receiver lol;

    lol.receive();

//    receiver::receive();

    return app.exec();
}
