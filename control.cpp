#include "control.h"
#include <qprocess.h>
#include <QDebug>

control::control()

{
}

void control::getStatus(qint8 pin)
{
  QObject *parent;
  //QProcess gpioPi;
  QString program = "./usr/local/bin/gpio";
  QStringList arguments;
  arguments << "read" << "0";
  QProcess *gpioPi = new QProcess(parent);
  gpioPi->start(program,arguments);
  gpioPi->waitForFinished(2000);
  QString output(gpioPi->readAll());
  qDebug() << "This is the output" << output << endl;


}
