#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include "message.h"

class QTcpSocket;

class client:public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    Message m;

signals:
    void lineReaded();
    void connectedSignal();

private slots:
    void readyRead();
    void connected();

public:
    void sendMessage(QString);

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
