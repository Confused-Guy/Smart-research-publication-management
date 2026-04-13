QT += core gui sql widgets printsupport network serialport texttospeech
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    publication.cpp \
    collaboration.cpp \
    conference.cpp \
    main.cpp \
    mainwindow.cpp \
    review.cpp \
    submission.cpp \
    user.cpp \
    filepreviewdialog.cpp \
    ollamaintegration.cpp

HEADERS += \
    publication.h \
    collaboration.h \
    conference.h \
    mainwindow.h \
    review.h \
    submission.h \
    user.h \
    filepreviewdialog.h \
    ollamaintegration.h

FORMS += \
    mainwindow.ui
