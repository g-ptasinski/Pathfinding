#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  scene = new QGraphicsScene(this);
  scene->addText("Hello, world!");

  ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
  delete ui;
}

