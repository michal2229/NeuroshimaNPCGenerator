#-------------------------------------------------
#
# Project created by QtCreator 2018-06-15T20:56:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NeuroshimaNPCGenerator
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


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    NPCEditor/NPCCardEditor.cpp \
    NPCEditor/Section/Personal.cpp \
    NPCEditor/Section/Attributes.cpp \
    NPCEditor/Widget/AttributeWidget.cpp \
    NPCEditor/Widget/AttributeTitleWidget.cpp \
    NPCEditor/Widget/SkillPacksWidget.cpp
    NPCEditor/Widget/PersonalWidget.cpp \
    NPCEditor/Widget/CardWidget.cpp \
    NPCEditor/Widget/AttributeValueWidget.cpp

HEADERS += \
        MainWindow.h \
    NPCEditor/NPCCardEditor.h \
    NPCEditor/Section/Section.h \
    NPCEditor/Section/Personal.h \
    NPCEditor/Section/Attributes.h \
    NPCEditor/Widget/AttributeWidget.h \
    NPCEditor/Widget/AttributeTitleWidget.h \
    NPCEditor/Widget/SkillPacksWidget.h
    NPCEditor/Widget/PersonalWidget.h \
    NPCEditor/Widget/CardWidget.h \
    NPCEditor/Widget/AttributeValueWidget.h

RESOURCES += \
    json/json.qrc

DISTFILES += \
    json/NPCCard.json
    Othres/Concept.txt
