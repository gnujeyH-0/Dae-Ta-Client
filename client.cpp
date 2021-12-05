#include "client.h"
#include <QThread>

#include <QRegExp>
#include <QTcpSocket>
#include <QTimer>

client::client(QWidget *parent):
    QWidget(parent)
{
    socket=new QTcpSocket(this);

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    socket->connectToHost("127.0.0.1",8520);
}

void client::readyRead()
{
    while(socket->canReadLine())
    {
        QString line=QString::fromUtf8(socket->readLine());
        line=line.left(line.length()-1);
        printf("read\n");
//        printf("%s\n",line);
    }
}

void client::connected()
{
    printf("connected\n");
    socket->write(QString("/me:hello\n").toUtf8());

    // QString message=QString("hello world!").trimmed();
    // while(true){
        // socket->write(QString(message+"\n").toUtf8());
        // QTextStream(stdout)<<"client message:"<<message<<endl;
    //     QThread::usleep(1000000);
    // }
}

void client::sendMessage(QString message){
     message=QString("hello world!").trimmed();
    if(!message.isEmpty())
    {
        socket->write(QString(message+"\n").toUtf8());
    }
}
