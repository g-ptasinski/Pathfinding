#include <iostream>
#include <memory>
#include <vector>

#include "mainwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
