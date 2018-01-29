#include <QCoreApplication>
#include "server.h"
#include "filedatabase.h"
#include "tool1.h"
int main(int argc, char *argv[])
{
    Tool1::set_debug_level(Tool1::DEBUG);
    QCoreApplication a(argc, argv);
    FileDatabase database("config.json");
    Server s(&database);
    return a.exec();
}
