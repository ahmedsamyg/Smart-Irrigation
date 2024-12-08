#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void ConnectToHost(QString ip,qint32 port);
    void DisconnectFromHost();
    void SendData(QString Data);

signals:
    void sendOnConnect();
    void sendDisConnect();
    void sendOnError(QAbstractSocket::SocketError error);
    void sendOnReadyread(QString data );
    void sendOnStatechange(QAbstractSocket::SocketState state);


public slots:
    void OnConnect();
    void DisConnect();
    void OnError(QAbstractSocket::SocketError error);
    void OnReadyread();
    void OnStatechange(QAbstractSocket::SocketState state);

private:
    QTcpSocket *socket;
    QString ip;
    qint32 port;

};

#endif // CLIENT_H
