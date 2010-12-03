#-------------------------------------------------
#
# Project created by QtCreator 2010-11-27T15:23:52
#
#-------------------------------------------------

QT       += network \
    script

TARGET = source
TEMPLATE = app
DESTDIR = bin

# 3td party libs
include(src/qtsingleapplication/qtsingleapplication.pri)

# Anti-trash ;)
OBJECTS_DIR = temp
MOC_DIR = temp
UI_DIR = temp
RCC_DIR = temp


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
        src/translate.cpp \
    src/jsonstreamreader.cpp \



HEADERS  += src/mainwindow.h \
            src/translate.h \
    src/jsonstreamreader.h \


FORMS    += src/mainwindow.ui \



RESOURCES += \
    src/resources.qrc

# Some defines for Windows
win:RC_FILE = src/images/win.rc

# Other
CODECFORTR = UTF-8
