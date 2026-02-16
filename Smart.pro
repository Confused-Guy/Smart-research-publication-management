QT += core gui sql widgets printsupport network
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    collaboration.cpp \
    conference.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    collaboration.h \
    conference.h \
    mainwindow.h \
    review.h

FORMS += \
    mainwindow.ui
