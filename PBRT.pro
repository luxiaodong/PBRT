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

CONFIG += sdk_no_version_check

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
#    Integrators/gwhittedintegrator.cpp \
    Core/gspectrum.cpp \
    Core/gcolorspace.cpp \
    Core/gfilm.cpp \
#    Core/graydifferential.cpp \
#    Core/ganimatedtransform.cpp \
    Interactions/ginteraction.cpp \
#    Interactions/gsurfaceinteraction.cpp \
    Shapes/gsphere.cpp \
#    Shapes/gcylinder.cpp \
#    Shapes/gdisk.cpp \
#    Shapes/gcone.cpp \
#    Shapes/gparaboloid.cpp \
#    Shapes/ghyperboloid.cpp \
#    Shapes/gtrianglemesh.cpp \
#    Shapes/gtriangle.cpp \
#    Shapes/gcurve.cpp \
#    Core/goptions.cpp \
#    Medium/gmedium.cpp \
#    Core/gmemoryarena.cpp \
#    Medium/gmediuminterface.cpp \
#    Interactions/gmediuminteraction.cpp \
#    Medium/gphasefunction.cpp \
#    Core/gcreatefactory.cpp \
#    Filter/gfilter.cpp \
#    Filter/gboxfilter.cpp \
#    Core/gparsepbrt.cpp \
    Samplers/gpixelsampler.cpp \
    gpbrt.cpp

HEADERS  += widget.h \
    qtinclude.h \
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
#    Integrators/gwhittedintegrator.h \
    Core/gspectrum.h \
    Core/gcolorspace.h \
    Core/gfilm.h \
#    Core/graydifferential.h \
#    Core/ganimatedtransform.h \
    Interactions/ginteraction.h \
#    Interactions/gsurfaceinteraction.h \
    Shapes/gsphere.h \
#    Shapes/gcylinder.h \
#    Shapes/gdisk.h \
#    Shapes/gcone.h \
#    Shapes/gparaboloid.h \
#    Shapes/ghyperboloid.h \
#    Shapes/gtrianglemesh.h \
#    Shapes/gtriangle.h \
#    Shapes/gcurve.h \
#    Core/goptions.h \
#    Medium/gmedium.h \
#    Core/gmemoryarena.h \
#    Medium/gmediuminterface.h \
#    Interactions/gmediuminteraction.h \
#    Medium/gphasefunction.h \
#    Core/gcreatefactory.h \
#    Filter/gfilter.h \
#    Filter/gboxfilter.h \
#    Core/gparsepbrt.h \
    Samplers/gpixelsampler.h \
    gpbrt.h
