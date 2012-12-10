#include <QtGui/QApplication>
#include <QDebug>
#include <QTextCodec>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *utfCodec =QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(utfCodec);
   // QTextCodec::setCodecForCStrings(utfCodec);

    MainWindow w;
    w.show();

    return a.exec();
}
