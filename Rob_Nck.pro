#-------------------------------------------------
#
# Project created by QtCreator 2018-04-13T18:23:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rob_Nck
TEMPLATE = app


SOURCES += main.cpp\
    robot/auto.cpp \
    robot/bus.cpp \
    robot/math_base.cpp \
    robot/nck.cpp \
    robot/robot.cpp \
    robot/moveabsj.cpp \
    robot/movel.cpp \
    robot/movec.cpp \
    robot/poseconversion.cpp \
    robot/tool.cpp

HEADERS  += \
    robot/auto.h \
    robot/bus.h \
    robot/linuxtypes.h \
    robot/math_base.h \
    robot/nck.h \
    robot/robot.h \
    robot/moveabsj.h \
    robot/movel.h \
    robot/movec.h \
    robot/poseconversion.h \
    robot/tool.h
