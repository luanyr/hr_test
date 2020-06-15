#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QObject>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);
    void client_send(QByteArray send_data);
    int  client_connect(QString ip,int port);
    void client_disconnect();
    QByteArray client_read();
    bool get_client_sta();
signals:
    void disconnect_signal(bool);
    void read_signal();
public slots:
    void disconnect();
    void ready_read();
private:
    QTcpSocket *tcp_client;
    bool socket_status;
    QByteArray recv_buf;
};

#endif // CLIENT_H
