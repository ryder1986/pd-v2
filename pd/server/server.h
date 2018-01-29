#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "pd.h"
#include "filedatabase.h"
#include "cameramanager.h"
#include "clientsession.h"
class Server:public QObject
{
    Q_OBJECT
public:
    Server(FileDatabase *db);
    ~Server()
    {
       delete camera_manager;
    }

public slots:
    void handle_connection()
    {
        QTcpSocket *skt = server->nextPendingConnection();
        connect(skt, SIGNAL(disconnected()),skt, SLOT(deleteLater()));
        QString str(skt->peerAddress().toString());
        prt(info,"client %s:%d connected",str.toStdString().data(),skt->peerPort());
        ClientSession *client=new ClientSession(skt);
        connect(client,SIGNAL(socket_error(ClientSession*)),this,SLOT(delete_client(ClientSession*)));
        connect(client,SIGNAL( session_operation(int,void*,char*,int,int)),this,SLOT(handle_session_op(int,void*,char*,int,int)),Qt::DirectConnection);//important,in case of competition bugs
        connect(skt,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

        clients.append(client);
    }
    void handle_session_op(int req,void *addr,char *buf, int len,int cam_index)
    {
        int idx=clients.indexOf((ClientSession *)addr);
        prt(debug,"client %d msg",idx);
    }

    void delete_client(ClientSession *c)
    {
        prt(info,"client %s disconnected",c->ip().toStdString().data());
        delete c ;
        clients.removeOne(c);
    }
    void  displayError(QAbstractSocket::SocketError socketError)
    {
        //prt(info,"client %s disconnected",c->ip().toStdString().data());
  //      prt(info,"client error");
        switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            prt(info,"client closed");
            break;
        case QAbstractSocket::HostNotFoundError:
           prt(info,"client error");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            prt(info,"client error");
            break;
        default:
            break;
        }
    }
private:
    FileDatabase *database;
    CameraManager *camera_manager;

    char recv_buf[Pd::BUFFER_MAX_LENGTH];
    char send_buf[Pd::BUFFER_MAX_LENGTH];
    QTcpServer *server;//server for reply all clients request ,execute client cmds,like add cam,del cam, reconfigure cam,etc..
    QList <ClientSession *> clients;//client that connected to server
};


#endif // SERVER_H
