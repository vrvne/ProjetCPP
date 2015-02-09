#-------------------------------------------------
#
# Project created by QtCreator 2015-01-22T21:19:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetCPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywindow.cpp \
    resultwindow.cpp \
    simwindow.cpp \
    simulation.cpp\
    guidewindow.cpp \
    uniformgenlc.cpp \
    uniformgen.cpp \
    normaldistribution.cpp \
    deltaneutral.cpp

HEADERS  += mainwindow.h \
    mywindow.h \
    resultwindow.h \
    simwindow.h \
    simulation.h\
    guidewindow.h \
    uniformgenlc.h \
    uniformgen.h \
    normaldistribution.h \
    deltaneutral.h

FORMS    += mainwindow.ui
