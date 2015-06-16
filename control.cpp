#include "control.h"
#include <qprocess.h>
#include <QDebug>

QProcess gpioPi;
QString programGpio = "gpio";


control::control()

{
}

int control::getStatus(qint8 pin)
{
  qint8 statusValue;
  //Convert pin to string
  QString pinNumber = QString::number(pin);
   QStringList arguments;


  arguments << "read" << pinNumber;

  gpioPi.start(programGpio,arguments);
  gpioPi.waitForFinished(2000);

  QString output(gpioPi.readAll());
  statusValue = output.toInt();
  arguments.clear();
  return(statusValue);

}

void control::setPin(qint8 pin, qint8 value)
{
    QString pinNumber = QString::number(pin);
    QString pinValue   = QString::number(value);
    QStringList arguments;

    arguments << "write" << pinNumber << pinValue;

    gpioPi.start(programGpio,arguments);
    gpioPi.waitForFinished(2000);

}
