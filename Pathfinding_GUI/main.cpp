#include <iostream>
#include <memory>
#include <vector>

#include "mainwindow.h"
#include "grid.h"
#include "pathnode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  auto map = std::make_unique<grid>(100,100);

  w.show();

  return a.exec();
}
