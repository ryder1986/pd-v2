#-------------------------------------------------
#
# Project created by QtCreator 2018-01-29T11:48:18
#
#-------------------------------------------------

include(../misc/misc.pri)
include(../pedestrian-detection.pri)
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
unix{
    DEFINES +=IS_UNIX
}

win32{
    DEFINES +=IS_WIN32
}
TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp  videowidget.cpp
HEADERS  += mainwindow.h \
    client.h videowidget.h

FORMS    += form.ui
INCLUDEPATH +=../misc/
CONFIG+=c++11

INCLUDEPATH +=/root/repo-github/libs/third-party/opencv/opencv-linux-x86/include
CONFIG +=c++11
message(build $$OUT_PWD/$$TARGET on unix system)
#INSTALL_PATH="/root/repo-github/install-pedestrian-detection"
install_setting.path=$$OUT_PWD/install
install_setting.files=$$OUT_PWD/$$TARGET config.json run.sh hogcascade_pedestrians.xml
message(install ($$install_setting.files) in ($$install_setting.path))
INSTALLS+=install_setting
