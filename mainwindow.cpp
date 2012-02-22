#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"
#include "element.h"
#include "aboutdialog.h"
#include "configure.h"

#include <QDebug>
#include <QObject>
#include <QGraphicsProxyWidget>
#include <QPropertyAnimation>
#include <QTimer>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mode = false;
    //sbf->resize(QWidget::minimumSizeHint());
    //sbf->sizePolicy(Qt::)
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);

    newAction();


    //scene->addRect(QRectF(0, 0, 100, 200),QPen(Qt::black), QBrush(Qt::green));
    //scene->addText("hello world");

    addItem();
    placement();
    view->setScene(scene);
    setCentralWidget(view);
    view->setAlignment(Qt::AlignCenter);
    view->show();


    ui->statusBar->showMessage(tr("Q(uit), A(bout), R(andom), C(onfigure), M(ode), SPACE(Auto)"));
    winTitle = "The \"Sweet Sixteen\" Guitar Chords";
    setWindowTitle(winTitle);
    //QMetaObject::connectSlotsByName(this);

    //setFocusPolicy(Qt::StrongFocus);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    //setStyleSheet("QFrame { margin: 0px; border: 2px solid green; padding: 0px; background-color: transparent; } ");
    //timer->start(2000);
}

MainWindow::~MainWindow()
{
    delete view;
    delete scene;
    delete list;
    delete widgetList;
    delete ui;
}

void MainWindow::newAction()
{


    QCheckBox *checkbox1 = new QCheckBox(tr("Show"),this);
    ui->statusBar->addPermanentWidget(checkbox1);
    checkbox1->setCheckState(Qt::Checked);


    time = new QSpinBox();
    time->setSuffix("s");
    ui->statusBar->addPermanentWidget(time);
    time->setDisabled(false);
    time->setRange(0,120);
    time->setSingleStep(5);

    connect(checkbox1, SIGNAL(stateChanged(int)), this, SLOT(actionTriggerFigure_triggered(int)));

}
// bypass the key press event to the mainwindow to handle
void QGraphicsView::keyPressEvent(QKeyEvent *event)
{
     event->ignore();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int delta = 0;
    bool accept = true;
    switch(event->key())
    {
        case Qt::Key_Q:
            close();
            break;
        case Qt::Key_A:
            actionAbout_triggered();
            break;
        case Qt::Key_C:
            actionConfigure_triggered();
            break;
        case Qt::Key_M:
            actionMode_triggered();
            break;
        case Qt::Key_R:
            actionRandom_triggered();
            break;
        case Qt::Key_Space:
            actionControl_triggered();
            break;
        case Qt::Key_Left:
            delta = 1;
            slide(delta);
            break;
        case Qt::Key_Right:
            delta = -1;
            slide(delta);
            break;
        default:
            accept = false;
    }
    if(accept) event->accept();
}

int MainWindow::addItem()
{
    widgetList = new QList<QGraphicsProxyWidget *>();
    list = new QList<Item *>();
    readConfiguration(list);

    int i = 0;
    foreach(Item *item, *list)
    {
        QGraphicsProxyWidget *proxy =  scene->addWidget(item);
        proxy->setZValue(0);
        widgetList->append(proxy);
        QRectF rect = proxy->boundingRect();
        //proxy->setPos(x+10, 10);
        //proxy->show();
        //x += rect.width();
        ++i;
    }
    view->update();
    len = list->size();
    return i;
}

void MainWindow::placement()
{
    int widgetWidth = list->first()->size().width();
    int widgetHeight = list->first()->size().height();
    int count = 0;
    int x, y;

    foreach(Item *tmp, *list)
    {
        //count = tmp->getIndex();
        x = (count%4)*widgetWidth;
        y = (int)(count/4)*widgetHeight;

        //QPropertyAnimation *animation = new QPropertyAnimation(tmp, "geometry");
        QPropertyAnimation *animation = new QPropertyAnimation(tmp, "pos");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::InOutCirc);

        //animation->setStartValue(QRect(tmp->x(),tmp->y(),widgetWidth,widgetHeight));
        //animation->setEndValue(QRect(x,y,widgetWidth,widgetHeight));
        animation->setEndValue(QPoint(x,y));
        animation->start();

        //tmp->move(x, y);
        ++count;
    }

}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::actionControl_triggered()
{
    int value = time->value();
    if(timer->isActive())
    {
        timer->stop();
        time->setDisabled(false);
        setWindowTitle(winTitle+"(Manual)");
        //foreach(Item *item, *list) item->fireProgressBar(-1);
    }
    else if(value == 0) 
        QMessageBox::information(this, tr("oops!"), tr("please set period first!"));
    else
    {
            timer->start(value*1000/len);
            time->setDisabled(true);
            setWindowTitle(winTitle+"(Auto)");
    }
}

void MainWindow::timeout()
{
    static int index = 0;
    if(index < len & index >= 0)
        list->at(index++)->fireProgressBar(time->value()*1000/len);
    else if(index == len)
    {
        index = -1;
        foreach(Item *item, *list) item->fireProgressBar(0);
        actionRandom_triggered();
    }
    else index++;
}

void MainWindow::actionRandom_triggered()
{

        randomize(list);
        placement();
    //printList(*list);
}

void MainWindow::actionAbout_triggered()
{
    ab  = new aboutDialog(this);
    // move to the center to the window
    ab->move((width() - ab->width())/2, (height() - ab->height())/2);
    ab->show();
    ab->raise();
}

void MainWindow::actionConfigure_triggered()
{
    configureDialog = new configure();
    configureDialog->show();
    connect(configureDialog, SIGNAL(reload()), this, SLOT(clean_reload()));

    //qDebug() << "Configure!";
}
void MainWindow::actionTriggerFigure_triggered(int state)
{
    foreach(Item *tmp, *list)
    {
        tmp->toggle(state);
    }
}

void MainWindow::actionMode_triggered()
{
    //scene->clear();
    //addItem();
    mode = !mode;
    disconnect(timer, SIGNAL(timeout()),0,0);
    //time->setDisabled(true);
    if(mode) 
    {
        //scene->setSceneRect(scene->itemsBoundingRect());
        view->adjustSize();
        current = 0;
        slide(0);
        connect(timer, SIGNAL(timeout()), this, SLOT(timeslide()));
    }
    else
    {
        foreach(Item *it, *list) it->show();
        placement();
        connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    }
    qDebug() << " change mode";
}
void MainWindow::timeslide()
{
    slide(1);
}

void MainWindow::slide(int state)
{
    //grabKeyboard();
    int end = list->size() - 1;

    if(current == 0 && state <= 0) {foreach(Item *it, *list) it->move(600, 0);return;}
    if(current == end+2 && state > 0) {randomize(list); foreach(Item *it, *list) it->move(600, 0);current = 0; return;}

    //view->adjustSize();
    //foreach(Item *it, *list) it->hide();

    current += state;

    Item *tmp = new Item();

    if(current >= 0 && current <= end) 
    { 
        tmp = list->at(current); 
        tmp->show();
        //tmp->move(500,30); 
        QPropertyAnimation *animation = new QPropertyAnimation();
        animation->setPropertyName("pos");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::InOutCirc);
        animation->setTargetObject(tmp);
        animation->setStartValue(tmp->pos());
        animation->setEndValue(QPoint(400,0));
        animation->start();
    }
    if(current >= 1 && current <= end+1)
    { 
        tmp = list->at(current-1);
        tmp->show();
        //tmp->move(300,30);
        QPropertyAnimation *animation = new QPropertyAnimation();
        animation->setPropertyName("pos");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::InOutCirc);
        animation->setTargetObject(tmp);
        animation->setStartValue(tmp->pos());
        animation->setEndValue(QPoint(200,0));
        animation->start();
    }
    if(current >= 2 && current <= end+2)
    { 
        tmp = list->at(current-2);
        tmp->show();
        //tmp->move(100,30);
        QPropertyAnimation *animation = new QPropertyAnimation();
        animation->setPropertyName("pos");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::InOutCirc);
        animation->setTargetObject(tmp);
        animation->setStartValue(tmp->pos());
        animation->setEndValue(QPoint(0,0));
        animation->start();
    }

}

void QGraphicsView::wheelEvent(QWheelEvent *event)
{
     event->ignore();
}

void MainWindow::wheelEvent(QWheelEvent * event)
{
    int numDegrees = event->delta() / 8;
    double ratio = (double)numDegrees / 100;
    //if(ratio <= 0.5 || ratio >= -0.5)
    view->scale(ratio+1, ratio+1);
    event->accept();
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QMainWindow::resizeEvent(event);
    QRectF bounding = scene->itemsBoundingRect();
    float widthRatio = (float)size().width() / bounding.width();
    float heightRatio = (float)size().height() / bounding.height();
    qDebug() << bounding.width() << bounding.height();
    qDebug() << size().width() << size().height();
    qDebug() << widthRatio << heightRatio;

    //if(widthRatio <= heightRatio) view->scale(widthRatio, widthRatio);
    //else view->scale(heightRatio, heightRatio);

    // @todo, more sutle way to implement this
    /*
    if(event->oldSize() > size())
        view->scale(0.9, 0.9);
    view->size()
    */
    qDebug()<< " resize me!";
}

void MainWindow::clean_reload()
{
    scene->clear();
    scene->setSceneRect(scene->itemsBoundingRect());

    list->clear();
    widgetList->clear();

    addItem();
    placement();
}

