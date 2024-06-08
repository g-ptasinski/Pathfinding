#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  scene = new QGraphicsScene(this);


  ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::GenerateGridView( void )
{
  scene->addRect(-400,-20,50,50, QPen(Qt::black) , QBrush(Qt::white));
  scene->addRect(-40,-20,50,50, QPen(Qt::black) , QBrush(Qt::white));
}

void MainWindow::on_Simulate_clicked()
{
    map->getNodes();
    //TODO ADD SIMULATION
}

void MainWindow::on_GenerateGrid_clicked()
{
  map = std::make_unique<grid>(Height,Width);

  GenerateGridView();
}

void MainWindow::on_Width_valueChanged(int arg1)
{
    Width = arg1;
}

void MainWindow::on_Height_valueChanged(int arg1)
{
    Height = arg1;
}

