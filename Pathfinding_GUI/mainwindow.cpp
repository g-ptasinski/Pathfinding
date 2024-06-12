#include <iostream>
#include <QGraphicsItem>
#include <QMouseEvent>

#include "mainwindow.h"
#include "graphicalnode.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_GridHeight = 10;
  m_GridWidth = 10;

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

  m_RectWidth   = 850/(m_GridWidth);
  m_RectHeight  = 850/(m_GridHeight);

  int rectsize    = ( m_RectWidth > m_RectHeight) ? m_RectHeight : m_RectWidth ;
  int linewidth  = 3;

  QGraphicsScene *scene = new QGraphicsScene;
  ui->graphicsView->setScene(scene);

  for (int i = 0; i < m_GridHeight; i++)
    {
    for (int j = 0; j < m_GridWidth; j++)
      {
      GraphicalNode *rec = new GraphicalNode(0, 0, rectsize-linewidth, rectsize-linewidth);
      rec->setBrush(Qt::white);
      rec->setPos(i * rectsize, j * rectsize);
      rec->setAcceptHoverEvents(true);
      scene->addItem(rec);
      RectItemMap.push_back(rec);
      }
    }

  ui->graphicsView->resize( 880, 880 );


}

void MainWindow::on_Simulate_clicked()
{
    RectItemMap[0]->setBrush(Qt::red);
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





