#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  scene = new QGraphicsScene(this);
  scene->addRect(-400,-20,50,50, QPen(Qt::black) , QBrush(Qt::white));
  scene->addRect(-40,-20,50,50, QPen(Qt::black) , QBrush(Qt::white));

  ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    std::cout<<"Pushed"<<std::endl;
}

