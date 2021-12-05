#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c = new client();

    // Client setup
    connect(c, SIGNAL(lineReaded()), this, SLOT(updateWindow()));

    connect(ui->v1, SIGNAL(clicked()), this, SLOT(updateWindow()));
    
    connect(this, SIGNAL(updateVelocitySignal()), this, SLOT(updateVelocity()));

    updateVelocity1();
    // Button setup
    connect(ui->v4, SIGNAL(clicked()), this, SLOT(updateVelocity4()));
    connect(ui->v3, SIGNAL(clicked()), this, SLOT(updateVelocity3()));
    connect(ui->v2, SIGNAL(clicked()), this, SLOT(updateVelocity2()));
    connect(ui->v1, SIGNAL(clicked()), this, SLOT(updateVelocity1()));

    connect(c,SIGNAL(connectedSignal()),this,SLOT(connected()));
   

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connected(){
    ui->listWidget->addItem(QString("Server is connected"));
    ui->listWidget->scrollToBottom();
}

void MainWindow::updateVelocity1()
{
    velocity=1;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:#ffffff;"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:#ffffff;"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:#ffffff;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity2()
{
    velocity=2;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:#ffffff;"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:#ffffff;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity3()
{
    velocity=3;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:#ffffff;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity4()
{
    velocity=4;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:rgb(187,187,187);"
                          "}");
    emit updateVelocitySignal();
}


void MainWindow::updateVelocity(){
    // c->line
    ui->listWidget->addItem(QString("velocity Changed -> %1").arg(velocity));
    ui->listWidget->scrollToBottom();
    ui->lbVelocityC->setText(QString("%1").arg(velocity));
}

void MainWindow::updateStateLocation(){
    Location stateLocation=HOME;

    ui->home->setStyleSheet("QLabel{"
                          "background-color:url(:/transparent.png);;"
                          "}");

    ui->moving->setStyleSheet("QLabel{"
                          "background-color:url(:/transparent.png);;"
                          "}");

    ui->table->setStyleSheet("QLabel{"
                          "background-color:url(:/transparent.png);;"
                          "}");
    switch(stateLocation){
    case HOME:
        ui->home->setStyleSheet("QLabel{"
                              "background-color:rgb(187,187,187);"
                              "}");
        break;
    case MOVING:
        ui->moving->setStyleSheet("QLabel{"
                              "background-color:rgb(187,187,187);"
                              "}");
        break;
    default:
        ui->table->setStyleSheet("QLabel{"
                              "background-color:rgb(187,187,187);"
                              "}");
        break;

    }
}

void MainWindow::updateWindow(){
    ui->listWidget->addItem(QString("stateLocation:%1").arg(c->m.stateLocation));
    ui->listWidget->addItem(QString("stateLocation:%1").arg(c->m.stateLocation));
    ui->listWidget->scrollToBottom();
}


