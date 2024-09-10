#include <QGraphicsItem>
#include <QMouseEvent>
#include <iostream>

#include "mainwindow.h"
#include "gridofnodes.h"
#include "graphicalnode.h"
#include "ui_mainwindow.h"
#include "depthfirstsearch.h"

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


  m_RectWidth   = 900/(m_GridWidth);
  m_RectHeight  = 900/(m_GridHeight);
  int linewidth  = 1;
  int rectsize    = m_RectWidth;

  int width=0;
  int height=0;

  QGraphicsScene *scene = new QGraphicsScene;
  ui->graphicsView->setScene(scene);

  int tmpID = 0;

  for (int i = 0; i < m_GridHeight; i++)
    {
    for (int j = 0; j < m_GridWidth; j++)
      {
      GraphicalNode *rec = new GraphicalNode(0, 0, rectsize-linewidth, rectsize-linewidth, tmpID);

        height=i * rectsize;
        width= j * rectsize;

      rec->setPos(i * rectsize, j * rectsize);
      scene->addItem(rec);

      connect(this, &MainWindow::ValueChanged, rec, &GraphicalNode::setValue);
      connect(rec, &GraphicalNode::sendID, this, &MainWindow::ReceiveID);
      connect(rec, &GraphicalNode::sendStart, nodes_grid, &GridOfNodes::getStart);
      connect(rec, &GraphicalNode::sendFinish, nodes_grid, &GridOfNodes::getFinish);

      nodes_grid->WriteNodeIntoGrid(rec);
      tmpID++;
      }
    }

  ui->graphicsView->resize( width+rectsize ,height+rectsize);
    std::cout<<width+rectsize<<std::endl;
}

void MainWindow::on_Simulate_clicked()
{
    std::unique_ptr<PathFindingAlgo> pathfinding = std::make_unique<DepthFirstSearch>();

    pathfinding->Find(nodes_grid);
}

void MainWindow::on_GenerateGrid_clicked()
{
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

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
  if(arg1 == "Start/Finish")
    emit ValueChanged(STARTFINISH);
  else
    emit ValueChanged(NODEBLOCK);
}

void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
  if(arg1 == "Start/Finish")
    emit ValueChanged(STARTFINISH);
  else
    emit ValueChanged(NODEBLOCK);
}

 void MainWindow::ReceiveID( int  m_nodeID)
 {
     ui->lcdNumber->display( m_nodeID);
 }
