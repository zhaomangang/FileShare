#ifndef SERVE_H
#define SERVE_H


#include <QTcpServer>
#include <QObject>
#include "tcpclientsocket.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,quint16 port=0);
    ~Server();
    QList<TcpClientSocket*> tcpClientSocketList;
signals:
    void updateServer(QString,int);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
//    void incomingConnection(int socketDescriptor);
    void incomingConnection(qintptr socketDescriptor);
};


#endif // SERVE_H
