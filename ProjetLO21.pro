#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T13:10:25
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetLO21
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tache.cpp \
    tacheunitaire.cpp \
    tachecomposite.cpp \
    manager.tpp \
    projet.cpp \
    projetmanager.cpp \
    programmation.cpp \
    model.cpp \
    tachemanager.cpp \
    programmationmanager.cpp \
    window_addproject.cpp \
    window_addtacheunaire.cpp \
    window_arbo.cpp \
    window_addprog.cpp

HEADERS  += mainwindow.h \
    tache.h \
    calendarexception.h \
    tacheunitaire.h \
    tachecomposite.h \
    singleton.h \
    manager.h \
    projet.h \
    projetmanager.h \
    programmation.h \
    model.h \
    tachemanager.h \
    programmationmanager.h \
    window_addproject.h \
    window_addtacheunaire.h \
    window_arbo.h \
    window_addprog.h

FORMS    += mainwindow.ui \
    window_addproject.ui \
    window_addtacheunaire.ui \
    window_arbo.ui \
    window_addprog.ui
