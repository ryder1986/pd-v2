#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "filedatabase.h"
#include "cameramanager.h"
class Server
{
public:
    Server(FileDatabase *db);
    ~Server()
    {
       delete camera_manager;
    }
private:
    FileDatabase *database;
    CameraManager *camera_manager;
};

#endif // SERVER_H
