#include "Client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    socket= new QTcpSocket();
    connect(socket,&QTcpSocket::connected,this,&Client::OnConnect);
    connect(socket,&QTcpSocket::disconnected,this,&Client::DisConnect);
    connect(socket,&QTcpSocket::errorOccurred,this,&Client::OnError);
    connect(socket,&QTcpSocket::readyRead,this,&Client::OnReadyread);
    connect(socket,&QTcpSocket::stateChanged,this,&Client::OnStatechange);
}

void Client::ConnectToHost(QString ip, qint32 port)
{
    if(socket->isOpen()){
        if((this->ip==ip)&&(this->port==port)){
            return;
        }
    }
    else
    {
        this->ip=ip;
        this->port=port;
        socket->open(QIODevice::ReadWrite);
        socket->connectToHost(ip,port);
    }
    qDebug()<<"IPpp:>  "<<ip<<Qt::endl;
    qDebug()<<"portppp:>  "<<port<<Qt::endl;

}

void Client::DisconnectFromHost()
{
    if(socket->isOpen())
        socket->close();
}

void Client::SendData(QString Data)
{
    if(socket->isOpen()){
        socket->write(Data.toUtf8());
    }
}

void Client::OnConnect()
{
    emit sendOnConnect();
}

void Client::DisConnect()
{
    if(socket->isOpen())
        socket->close();
    emit sendDisConnect();
}

void Client::OnError(QAbstractSocket::SocketError error)
{
    emit sendOnError(error);
}

void Client::OnReadyread()
{
    if(socket->isOpen()){
        QByteArray data =socket->readAll();
        emit sendOnReadyread(QString(data));

    }

}

void Client::OnStatechange(QAbstractSocket::SocketState state)
{
    emit sendOnStatechange(state);
}
