#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>


namespace Ui {
    class MainWindow;
}

class aboutDialog;
class configure;
class Item;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int addItem();
    void placement();

protected:
    void changeEvent(QEvent *e);
    void newAction();

private:
    Ui::MainWindow *ui;
    aboutDialog *ab;
    configure *configureDialog;


    QGraphicsScene *scene;
    QGraphicsView *view;
    QList<QGraphicsProxyWidget *> *widgetList;
    QList<Item *> *list;

private slots:
    void actionRandom_triggered();
    void actionAbout_triggered();
    void actionConfigure_triggered();
    void actionTriggerFigure_triggered(int);
    void resizeEvent(QResizeEvent * event);
    void clean_reload();
};

#endif // MAINWINDOW_H
