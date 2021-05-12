QT       += core gui svg svgwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    document.cpp \
    exceptions.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    non_linear_resistor.cpp \
    source_of_constant_voltage.cpp

HEADERS += \
    document.h \
    element.h \
    exceptions.h \
    line.h \
    mainwindow.h \
    mytypes.h \
    non_linear_resistor.h \
    resistor.h \
    source_of_constant_voltage.h \
    source_of_voltage.h

FORMS += \
    exceptions.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
