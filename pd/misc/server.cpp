#include "server.h"

Server::Server(FileDatabase *db):database(db),camera_manager(NULL)
{
    QJsonObject config;
    QJsonObject camera_profile;
    database->get_config(config);
    camera_profile=config.value("profile").toObject();
    camera_manager=new CameraManager(camera_profile);
    camera_manager->start();
}

