#-------------------------------------------------
#
# Project created by QtCreator 2021-12-20T15:49:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PBRT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    Math/gmath.cpp \
    Core/gray.cpp \
    Core/ggeometry.cpp \
    Core/gscene.cpp \
    Integrators/gintegrator.cpp \
    Lights/glight.cpp \
    Core/gprimitive.cpp \
    Shapes/gshape.cpp \
    Materials/gmaterial.cpp \
    Math/gbound3d.cpp \
    Integrators/gsamplerintegrator.cpp \
    Samplers/gsampler.cpp \
    Cameras/gcamera.cpp \
    Integrators/gwhittedintegrator.cpp \
    Core/gspectrum.cpp \
    Core/gcolorspace.cpp \
    Core/gfilm.cpp \
    Core/graydifferential.cpp \
    Core/ganimatedtransform.cpp \
    Interactions/ginteraction.cpp \
    Interactions/gsurfaceinteraction.cpp \
    Shapes/gsphere.cpp

HEADERS  += widget.h \
    Math/gmath.h \
    Core/gray.h \
    Core/ggeometry.h \
    Core/gscene.h \
    Integrators/gintegrator.h \
    Lights/glight.h \
    Core/gprimitive.h \
    Shapes/gshape.h \
    Materials/gmaterial.h \
    Math/gbound3d.h \
    Integrators/gsamplerintegrator.h \
    Samplers/gsampler.h \
    Cameras/gcamera.h \
    Integrators/gwhittedintegrator.h \
    Core/gspectrum.h \
    Core/gcolorspace.h \
    Core/gfilm.h \
    gconstants.h \
    Core/graydifferential.h \
    Core/ganimatedtransform.h \
    Interactions/ginteraction.h \
    Interactions/gsurfaceinteraction.h \
    Shapes/gsphere.h
