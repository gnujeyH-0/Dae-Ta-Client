#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

class QTcpSocket;

class client:public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);

private slots:
    void readyRead();
    void connected();
    void sendMessage(QString);

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
