QT += sql
QT -= gui

TEMPLATE = lib
DEFINES += GALLERY_CORE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    album.cpp \
    albumdao.cpp \
    albummodel.cpp \
    databasemanager.cpp \
    picture.cpp \
    picturedao.cpp \
    picturemodel.cpp

HEADERS += \
    albumdao.h \
    albummodel.h \
    databasemanager.h \
    gallery_core_global.h \
    album.h \
    picture.h \
    picturedao.h \
    picturemodel.h

!isEmpty(target.path): INSTALLS += target
