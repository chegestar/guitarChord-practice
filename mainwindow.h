#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>
#include "element.h"
#include "aboutdialog.h"
#include "configure.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int addItem(QList<Item *> &iList);
    void placement();

protected:
    void changeEvent(QEvent *e);
    void newAction();

private:
    Ui::MainWindow *ui;
    aboutDialog *ab;


    QGraphicsScene *scene;
    QGraphicsView *view;
    QList<QGraphicsProxyWidget *> *widgetList;
    QList<Item *> *list;

private slots:
    void actionRandom_triggered();
    void actionAbout_triggered();
    void actionConfigure_triggered();
    void actionTriggerFigure_triggered(int);
};

#endif // MAINWINDOW_H
