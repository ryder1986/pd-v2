#include <QCoreApplication>
#include "server.h"
#include "filedatabase.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileDatabase database("config.json");
    Server s(&database);
    return a.exec();
}
