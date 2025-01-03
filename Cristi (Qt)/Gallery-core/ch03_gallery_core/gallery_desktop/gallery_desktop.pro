QT       += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    albumlistwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    thumbnailproxymodel.cpp

HEADERS += \
    albumlistwidget.h \
    mainwindow.h \
    thumbnailproxymodel.h

FORMS += \
    albumlistwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gallery_core/release/ -lgallery_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gallery_core/debug/ -lgallery_core
else:unix: LIBS += -L$$OUT_PWD/../gallery_core/ -lgallery_core

INCLUDEPATH += $$PWD/../gallery_core
DEPENDPATH += $$PWD/../gallery_core

RESOURCES += \
    resource.qrc
