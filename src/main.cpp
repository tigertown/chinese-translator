
#include <QtSingleApplication>
#include <QtCore/qtextcodec.h>
#include <QtGui/qmessagebox.h>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QtSingleApplication a(argc, argv);


    a.setQuitOnLastWindowClosed(false);

        if (a.isRunning())
            return 0;
    MainWindow w;

    a.setActivationWindow(&w, true);
    w.show();

    return a.exec();
}
