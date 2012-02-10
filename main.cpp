#include <QtGui/QApplication>
#include "mainwindow.h"
#include "aboutdialog.h"
#include "configure.h"
#include "list.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    aboutDialog ab;
    configure con;
    w.show();
    con.show();
    ab.show();

    QList<Item *> *list = new QList<Item *>();
    readConfiguration(list);
    return a.exec();
}
