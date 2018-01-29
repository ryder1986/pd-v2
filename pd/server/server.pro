#-------------------------------------------------
#
# Project created by QtCreator 2018-01-29T14:31:10
#
#-------------------------------------------------
include(../misc/misc.pri)
include(../pedestrian-detection.pri)
QT       += core network

QT       -= gui

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp cameramanager.cpp camera.cpp videoprocessor.cpp \
    clientsession.cpp

HEADERS += \
    server.h cameramanager.h camera.h videoprocessor.h \
    clientsession.h
CONFIG +=c++11
message(build $$OUT_PWD/$$TARGET on unix system)
#INSTALL_PATH="/root/repo-github/install-pedestrian-detection"
install_setting.path=$$OUT_PWD/install
install_setting.files=$$OUT_PWD/$$TARGET config.json run.sh hogcascade_pedestrians.xml
message(install ($$install_setting.files) in ($$install_setting.path))
INSTALLS+=install_setting
