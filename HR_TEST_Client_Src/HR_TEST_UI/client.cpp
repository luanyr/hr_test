#include "client.h"

client::client(QObject *parent) : QObject(parent)
{
    tcp_client = new QTcpSocket(this);
    qDebug() << "tcp connect";
    connect(tcp_client, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(tcp_client, SIGNAL(readyRead()),this, SLOT(ready_read()));
}

int client::client_connect(QString ip,int port)
{
    tcp_client->connectToHost(ip,port);
    if(tcp_client->waitForConnected(1000))
    {
        socket_status = true;
        return true;
    }
    else
        return false;
}

void client::client_disconnect()
{
    tcp_client->disconnectFromHost();
}

void client::client_send(QByteArray send_data)
{
    tcp_client->write(send_data);
}

void client::disconnect()
{
    socket_status = false;
    qDebug() << "[client]disconnect";
    emit disconnect_signal(socket_status);
}

void client::ready_read()
{
    recv_buf.clear();//clead buf
    recv_buf = tcp_client->readAll();
    emit read_signal();
}

QByteArray client::client_read()
{
    return recv_buf;
}

bool client::get_client_sta()
{
    return socket_status;
}
