#-------------------------------------------------
#
# Project created by QtCreator 2019-05-20T09:51:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ap
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    organizer_footsal.cpp \
    signin.cpp \
    organizer_boxing.cpp \
    organizer_wrestling.cpp \
    footsall_participant.cpp \
    wresteling_participant.cpp \
    boxing_participant.cpp

HEADERS += \
        mainwindow.h \
    mainwindow.h \
    participant.h \
    tournament.h \
    login.h \
    organizer_footsal.h \
    signin.h \
    organizer.h \
    organizer.h \
    organizer_boxing.h \
    organizer_wrestling.h \
    footsall_participant.h \
    wresteling_participant.h \
    boxing_participant.h

FORMS += \
        mainwindow.ui \
    login.ui \
    organizer_footsal.ui \
    signin.ui \
    organizer_boxing.ui \
    organizer_wrestling.ui \
    footsall_participant.ui \
    wresteling_participant.ui \
    boxing_participant.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc
