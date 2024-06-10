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

  m_ViewWidth = ui->graphicsView->width();
  m_ViewHeight = ui->graphicsView->height();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::GenerateGridView( void )
{
  m_ViewWidth = ui->graphicsView->width();
  m_ViewHeight = ui->graphicsView->height();

  scene->addRect(0,0,50,50, QPen(Qt::black) , QBrush(Qt::white));
  scene->addRect(100,100,50,50, QPen(Qt::black) , QBrush(Qt::white));

   std::cout<<m_ViewHeight<< "x" << m_ViewWidth<<std::endl;
}

void MainWindow::on_Simulate_clicked()
{
    map->getNodes();
    //TODO ADD SIMULATION
}

void MainWindow::on_GenerateGrid_clicked()
{
  map = std::make_unique<grid>(m_GridHeight,m_GridWidth);

  GenerateGridView();
}

void MainWindow::on_Width_valueChanged(int arg1)
{
    m_GridWidth = arg1;
}

void MainWindow::on_Height_valueChanged(int arg1)
{
    m_GridHeight = arg1;
}




