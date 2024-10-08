#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QtCore>
#include <QtGui>

#include <memory>
#include <vector>

#include "gridofnodes.h"
#include "graphicalnode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void ValueChanged(ActionType value);

private slots:

  void ReceiveID( int  m_nodeID );

  void on_Simulate_clicked();

  void on_GenerateGrid_clicked();

  void on_Width_valueChanged(int arg1);

  void on_Height_valueChanged(int arg1);

  void GenerateGridView( void );

  void on_comboBox_currentTextChanged(const QString &arg1);

  void on_comboBox_textActivated(const QString &arg1);

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;

  int m_GridHeight;
  int m_GridWidth;
  int m_ViewHeight;
  int m_ViewWidth;
  int m_RectWidth;
  int m_RectHeight;

  GridOfNodes* nodes_grid = new GridOfNodes();
  std::pair<int,int> StartFinishPair;
};
#endif // MAINWINDOW_H
