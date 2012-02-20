#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"
#include "element.h"
#include "aboutdialog.h"
#include "configure.h"

#include <QDebug>
#include <QObject>
#include <QGraphicsProxyWidget>
#include <QShortcut>
#include <QCheckBox>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //sbf->resize(QWidget::minimumSizeHint());
    //sbf->sizePolicy(Qt::)
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    newAction();


    //scene->addRect(QRectF(0, 0, 100, 200),QPen(Qt::black), QBrush(Qt::green));
    //scene->addText("hello world");

    addItem();
    view->setScene(scene);
    setCentralWidget(view);
    view->setAlignment(Qt::AlignCenter);
    view->show();

    ui->statusBar->showMessage(tr("Q(uit), A(bout), R(andom), C(onfigure), M(ode)"));
    setWindowTitle("The \"Sweet Sixteen\" Guitar Chords");
    //QMetaObject::connectSlotsByName(this);

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


    QCheckBox *checkbox = new QCheckBox(tr("show"),this);
    ui->statusBar->addPermanentWidget(checkbox);

    connect(checkbox, SIGNAL(stateChanged(int)), this, SLOT(actionTriggerFigure_triggered(int)));

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
        case Qt::Key_Left:
            delta = 1;
            break;
        case Qt::Key_Right:
            delta = -1;
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
        widgetList->append(proxy);
        QRectF rect = proxy->boundingRect();
        //proxy->setPos(x+10, 10);
        //proxy->show();
        //x += rect.width();
        ++i;
    }
    placement();
    view->update();
    return i;
}

void MainWindow::placement()
{
    int widgetWidth = list->first()->size().width();
    int widgetHeight = list->first()->size().height();
    int blank = 5;
    int count = 0;
    int x, y;

    foreach(Item *tmp, *list)
    {
        //count = tmp->getIndex();
        x = blank + (count%4)*widgetWidth;
        y = blank + (int)(count/4)*widgetHeight;

        QPropertyAnimation *animation = new QPropertyAnimation(tmp, "move");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::InOutCirc);

        animation->setStartValue(QRect(tmp->x(),tmp->y(),widgetWidth,widgetHeight));
        animation->setEndValue(QRect(x,y,widgetWidth,widgetHeight));

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

void MainWindow::actionRandom_triggered()
{
    randomize(list);
    placement();
    //printList(*list);
    //qDebug() << "Good luck!";
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
    qDebug() << " change mode";
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QMainWindow::resizeEvent(event);
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
    list->clear();
    widgetList->clear();
    addItem();
}
