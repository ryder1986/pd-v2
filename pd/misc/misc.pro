QT += core
QT -= gui

TARGET = misc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    filedatabase.cpp \
    server.cpp tool1.cpp \
    cameramanager.cpp \
    camera.cpp \
    videosource.cpp \
    videoprocessor.cpp

HEADERS += \
    filedatabase.h \
    server.h tool1.h \
    cameramanager.h \
    camera.h \
    videosource.h \
    videoprocessor.h

unix{
    DEFINES +=IS_UNIX
}

win32{
    DEFINES +=IS_WIN32
}
CONFIG +=c++11
message(build $$OUT_PWD/$$TARGET on unix system)
#INSTALL_PATH="/root/repo-github/install-pedestrian-detection"
install_setting.path=$$OUT_PWD/install
install_setting.files=$$OUT_PWD/$$TARGET config.json run.sh hogcascade_pedestrians.xml
message(install ($$install_setting.files) in ($$install_setting.path))
INSTALLS+=install_setting
