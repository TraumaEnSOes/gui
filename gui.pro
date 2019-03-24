QT += core gui widgets

TARGET = gui
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
        src/numkeypad.cpp \
        src/mainwidget.cpp

HEADERS += \
        include/application.hpp \
        include/mainwindow.hpp \
        include/testwindow.hpp \
        include/numkeypad.hpp \
        include/mainwidget.hpp

INCLUDEPATH += include
