#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QtCore>
#include <QtGui>

#include <memory>
#include <vector>

#include "grid.h"
#include "pathnode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void on_Simulate_clicked();

  void on_GenerateGrid_clicked();

  void on_Width_valueChanged(int arg1);

  void on_Height_valueChanged(int arg1);

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;

  int Height;
  int Width;

  std::unique_ptr<grid> map;
};
#endif // MAINWINDOW_H
