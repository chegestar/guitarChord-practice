#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>
#include <QSpinBox>
#include <QCheckBox>

#include <boost/shared_ptr.hpp>


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
    void slide(int);


protected:
    void changeEvent(QEvent *e);
    void newAction();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    boost::shared_ptr<aboutDialog> ab;
    boost::shared_ptr<configure> configureDialog;


    QGraphicsScene *scene;
    QGraphicsView *view;
    QList<QGraphicsProxyWidget *> *widgetList;
    QList<Item *> *list;

    int len;
    int current;
    bool mode;
    QString winTitle;

    QTimer *timer;
    QSpinBox *time;



private slots:
    void actionRandom_triggered();
    void actionAbout_triggered();
    void actionConfigure_triggered();
    void actionMode_triggered();
    void actionTriggerFigure_triggered(int);
    void actionControl_triggered();
    void clean_reload();
    void timeslide();
    void resizeEvent(QResizeEvent * event);
    void wheelEvent(QWheelEvent * event);
    void timeout();
};

#endif // MAINWINDOW_H
