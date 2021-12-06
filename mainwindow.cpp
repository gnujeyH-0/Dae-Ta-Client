#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c = new client();

    // Client setup
    connect(c, SIGNAL(lineReaded()), this, SLOT(updateWindow()));

    connect(this, SIGNAL(updateVelocitySignal()), this, SLOT(updateVelocity()));

    // Button setup
    connect(ui->v4, SIGNAL(clicked()), this, SLOT(updateVelocity4()));
    connect(ui->v3, SIGNAL(clicked()), this, SLOT(updateVelocity3()));
    connect(ui->v2, SIGNAL(clicked()), this, SLOT(updateVelocity2()));
    connect(ui->v1, SIGNAL(clicked()), this, SLOT(updateVelocity1()));

    connect(c, SIGNAL(connectedSignal()), this, SLOT(connected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connected()
{
    ui->listWidget->addItem(QString("Server is connected"));
    ui->listWidget->scrollToBottom();

    updateVelocity1();
}

void MainWindow::updateVelocity1()
{
    velocity = 1;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169); " 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity2()
{
    velocity = 2;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity3()
{
    velocity = 3;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity4()
{
    velocity = 4;
    ui->v1->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v2->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v3->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    ui->v4->setStyleSheet("QPushButton{"
                          "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                          "}");
    emit updateVelocitySignal();
}

void MainWindow::updateVelocity()
{
    ui->listWidget->addItem(QString("velocity Changed -> %1").arg(velocity));
    ui->listWidget->scrollToBottom();
    ui->lbVelocityC->setText(QString("%1").arg(velocity));
    c->sendMessage();
}

void MainWindow::updateWindow()
{

    // Debug Console
    ui->listWidget->addItem(QString("stateLocation:%1").arg(c->m.stateLocation));
    ui->listWidget->addItem(QString("bettery:%1").arg(c->m.bettery));
    ui->listWidget->addItem(QString("velocity:%1").arg(c->m.velocity));
    ui->listWidget->addItem(QString("moving:%1").arg(c->m.moving));
    ui->listWidget->addItem(QString("card:%1").arg(c->m.card));
    ui->listWidget->addItem(QString("work:%1").arg(c->m.work));

    ui->listWidget->scrollToBottom();

    // Location Status

    ui->home->setStyleSheet("QLabel{"
                            "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                            "}");

    ui->moving->setStyleSheet("QLabel{"
                            "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                              "}");

    ui->table->setStyleSheet("QLabel{"
                                                         "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                             "}");
    switch (c->m.stateLocation)
    {
    case HOME:
        ui->home->setStyleSheet("QLabel{"
                                                            "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                "}");
        break;
    case MOVING:
        ui->moving->setStyleSheet("QLabel{"
                                                              "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                  "}");
        break;
    default:
        ui->table->setStyleSheet("QLabel{"
                                                             "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                 "}");
        break;
    }

    // Location Status
    ui->mmoving->setStyleSheet("QLabel{"
                                                           "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                               "}");

    ui->stopped->setStyleSheet("QLabel{"
                                                           "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                               "}");

    ui->interrupted->setStyleSheet("QLabel{"
                                                               "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                   "}");
    switch (c->m.moving)
    {
    case 0:
        ui->stopped->setStyleSheet("QLabel{"
                                                               "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                   "}");
        break;
    case 1:
        ui->mmoving->setStyleSheet("QLabel{"
                                                               "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                   "}");
        break;
    case 2:
        ui->interrupted->setStyleSheet("QLabel{"
                                                                   "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                       "}");
        break;
    }

    // Cart Status
    ui->succeeded->setStyleSheet("QLabel{"
                                                             "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                 "}");

    ui->failed->setStyleSheet("QLabel{"
                                                          "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                              "}");

    switch (c->m.card)
    {
    case 0:
        ui->failed->setStyleSheet("QLabel{"
                                                              "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                  "}");
        break;
    case 1:
        ui->succeeded->setStyleSheet("QLabel{"
                                                                 "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                     "}");
        break;
    }

    // Work Status
    ui->rest->setStyleSheet("QLabel{"
                                                        "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                            "}");

    ui->admin->setStyleSheet("QLabel{"
                                                         "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                             "}");

    ui->order->setStyleSheet("QLabel{"
                                                         "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                             "}");
    ui->serve->setStyleSheet("QLabel{"
                                                         "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#FFFFFF;"
                            "font-size:20px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                             "}");
    switch (c->m.work)
    {
    case 0:
        ui->admin->setStyleSheet("QLabel{"
                                                             "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                 "}");
        break;
    case 1:
        ui->rest->setStyleSheet("QLabel{"
                                                            "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                "}");
        break;
    case 2:
        ui->serve->setStyleSheet("QLabel{"
                                                             "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                 "}");
        break;
    case 3:
        ui->order->setStyleSheet("QLabel{"
                                                             "background-color:#B2CCFF; "
                            "border-radius:20px;"
                            "color:#000000;"
                            "font-size:23px;"
                            "font: 45 oblique 20px 'URW Gothic L';"
                                 "}");
        break;
    }

    // Battery Status
    ui->lbBetteryC->setText(QString("%1").arg(c->m.bettery));
    if (c->m.bettery > 75)
    {
        ui->bettery1->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery2->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery3->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery4->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
    }
    else if (c->m.bettery > 50)
    {
        ui->bettery1->setStyleSheet("QPushButton{"
                                    "background-color:rgb(187,187,187);;"
                                    "}");
        ui->bettery2->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery3->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery4->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
    }
    else if (c->m.bettery > 25)
    {
        ui->bettery1->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery2->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery3->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery4->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
    }
    else if (c->m.bettery > 10)
    {
        ui->bettery1->setStyleSheet("QPushButton{"
                                    "background-color:rgb(99, 255, 169);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery2->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery3->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery4->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
    }
    else
    {
        ui->bettery1->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery2->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery3->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
        ui->bettery4->setStyleSheet("QPushButton{"
                                    "background-color:rgb(199, 199, 199);" 
                            "border: 4px solid #FFFFFF;"
                                    "}");
    }

    //
}
