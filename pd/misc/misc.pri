SOURCES+=\
$$PWD/tool1.cpp\
$$PWD/filedatabase.cpp\
$$PWD/videosource.cpp\
$$PWD/pd.cpp
HEADERS+=\
$$PWD/tool1.h\
$$PWD/filedatabase.h\
$$PWD/videosource.h\
$$PWD/pd.h
unix{
DEFINES +=IS_UNIX
}
win32{
DEFINES +=IS_WIN32
}

INCLUDEPATH+=$$PWD
CONFIG+=c++11
