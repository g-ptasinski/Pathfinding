#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>

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
  void on_widget_customContextMenuRequested(const QPoint &pos);

  void on_Height_textChanged(const QString &arg1);

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
