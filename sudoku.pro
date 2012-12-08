#-------------------------------------------------
#
# Project created by QtCreator 2012-11-29T11:37:43
#
#-------------------------------------------------

QT       += core gui sql

TARGET = sudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sudokuform.cpp \
    numberselectiondialog.cpp \
    sudoku.cpp \
    aboutdialog.cpp \
    recordsdialog.cpp

HEADERS  += mainwindow.h \
    sudokuform.h \
    numberselectiondialog.h \
    sudoku.h \
    aboutdialog.h \
    recordsdialog.h

FORMS    += mainwindow.ui \
    sudokuform.ui \
    numberselectiondialog.ui \
    aboutdialog.ui \
    recordsdialog.ui