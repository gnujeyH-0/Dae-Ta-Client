#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include <QApplication>
#include "client.h"
#include <QDesktopWidget>
#include "stateEnum.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int velocity;
    QString line;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
   void updateWindow();
   void updateVelocity();
    void updateVelocity4();
    void updateVelocity3();
    void updateVelocity2();
    void updateVelocity1();
    void connected();

signals:
    void updateVelocitySignal();
    void connectedSignal();
private:
    Ui::MainWindow *ui;
    client *c;
};

#endif // MAINWINDOW_H
