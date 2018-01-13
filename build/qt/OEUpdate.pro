#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T14:47:10
#
#-------------------------------------------------


win32 {
    RootPath = $$PWD/../..
    SrcPath = $$RootPath/src
    IncPath = $$RootPath/include/oeupdate

    INCLUDEPATH += $$IncPath

    DESTDIR = $$RootPath/bin/

}
unix {
    target.path = /usr/lib
    INSTALLS += target
}

QT       -= gui

CONFIG += c++11

TARGET = OEUpdate

DEFINES += OEUPDATE_LIBRARY

Debug:TEMPLATE = app
Release:TEMPLATE = lib


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$SrcPath/update.cpp \
    $$SrcPath/server.cpp \
    $$SrcPath/client.cpp \
    $$SrcPath/main.cpp \
    $$SrcPath/file.cpp \
    $$SrcPath/downloader.cpp \
    $$SrcPath/host.cpp

HEADERS += \
    $$IncPath/update.h \
    $$IncPath/update_global.h \
    $$IncPath/server.h \
    $$IncPath/client.h \
    $$IncPath/file.h \
    $$IncPath/update_define.h \
    $$IncPath/downloader.h \
    $$IncPath/host.h
