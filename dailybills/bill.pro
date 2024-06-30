pQT       += core gui
QT       +=charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addone.cpp \
    calendar.cpp \
    data.cpp \
    detail_of_data.cpp \
    main.cpp \
    mainwindow.cpp \
    showonedata.cpp \
    statistics.cpp \
    view_all_data.cpp \
    viewdata.cpp

HEADERS += \
    addone.h \
    calendar.h \
    data.h \
    detail_of_data.h \
    mainwindow.h \
    showonedata.h \
    statistics.h \
    view_all_data.h \
    viewdata.h

FORMS += \
    addone.ui \
    calendar.ui \
    detail_of_data.ui \
    mainwindow.ui \
    showonedata.ui \
    statistics.ui \
    view_all_data.ui \
    viewdata.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RC_ICONS=myico.ico

RESOURCES += \
    images.qrc \
    images.qrc
