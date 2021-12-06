#include "client.h"
#include <QThread>
#include <QRegExp>
#include <QTcpSocket>
#include <QTimer>

client::client(QWidget *parent) : QWidget(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(connected()), this, SIGNAL(connectedSignal()));
    //  socket->connectToHost("192.168.137.140", 8520);
   socket->connectToHost("127.0.0.1", 8520);
}

void client::readyRead()
{/*
    while (socket->canReadLine())
    {   */
        // line=QString::fromUtf8(socket->readLine());
        // line=line.left(line.length()-1);
        // QTextStream(stdout)<<line;

        QByteArray byte = socket->readAll();

        QDataStream read(&byte, QIODevice::ReadOnly);
        
        read.readRawData(reinterpret_cast<char *>(&m), sizeof(m));
        
        QTextStream(stdout)<<"Got message"<<m.stateLocation<<endl;

        emit lineReaded();
//    }
}

void client::connected()
{
    printf("connected\n");
    socket->write(QString("connected from client\n").toUtf8());
    emit connectedSignal();
}

void client::sendMessage()
{
    QByteArray dat;
    QDataStream out(&dat, QIODevice::WriteOnly);
    // out<<message;
    out.writeRawData(reinterpret_cast<const char*>(&m),sizeof(m));

    printf("write\n");
//    QTextStream(stdout)<<dat;
    
    socket->write(dat);
}
