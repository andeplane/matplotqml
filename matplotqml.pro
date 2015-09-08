TEMPLATE = app

QT += qml quick widgets opengl openglextensions

SOURCES += main.cpp \
    plot.cpp \
    matplot.cpp \
    patch.cpp \
    surface.cpp \
    layer.cpp \
    text.cpp \
    line.cpp \
    figure.cpp \
    axes.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    plot.h \
    matplot.h \
    common.h \
    surface.h \
    text.h \
    patch.h \
    line.h \
    axes.h \
    layer.h \
    figure.h
