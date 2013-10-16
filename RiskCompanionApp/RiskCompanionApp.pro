#-------------------------------------------------
#
# Project created by QtCreator 2013-10-15T22:47:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RiskCompanionApp
TEMPLATE = app


SOURCES += \
    src/source/RiskCompanion.cpp \
    src/source/Controller.cpp \
    src/source/Main.cpp \

HEADERS  += \
    src/header/RiskCompanion.h \
    src/header/Controller.h

FORMS    += \
    src/ui/RiskCompanion.ui

OTHER_FILES    += \
    ../UpdateLog.txt \
    ../README.md
