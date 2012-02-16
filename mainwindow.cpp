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

    ui->statusBar->showMessage(tr("Q(uit), A(bout), R(andom), C(configure)"));
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

    QShortcut *Quit = new QShortcut(Qt::Key_Q,this);

    QShortcut *About = new QShortcut(Qt::Key_A,this);

    QShortcut *Random = new QShortcut(Qt::Key_R,this);

    QShortcut *Configure = new QShortcut(Qt::Key_C,this);

    QCheckBox *checkbox = new QCheckBox(tr("show"),this);
    ui->statusBar->addPermanentWidget(checkbox);


    connect(Quit, SIGNAL(activated()), this, SLOT(close()));
    connect(About, SIGNAL(activated()), this, SLOT(actionAbout_triggered()));
    connect(Configure, SIGNAL(activated()), this, SLOT(actionConfigure_triggered()));
    connect(Random, SIGNAL(activated()), this, SLOT(actionRandom_triggered()));
    connect(checkbox, SIGNAL(stateChanged(int)), this, SLOT(actionTriggerFigure_triggered(int)));

}


int MainWindow::addItem()
{
    widgetList = new QList<QGraphicsProxyWidget *>();
    list = new QList<Item *>();
    readConfiguration(list);

    int i = 0;
    qreal x = 0;
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
    int windowWidth = width();
    int windowHeight = height();
    int widgetWidth = list->first()->size().width();
    int widgetHeight = list->first()->size().height();
    int blank = 5;
    int count = 0;
    int x, y;
    //qDebug() << windowWidth << windowHeight << widgetWidth << widgetHeight;

    //int x = windowWidth % widgetWidth;
    //foreach(QGraphicsProxyWidget *tmp, *widgetList)
    //{
    //    Item *item = dynamic_cast<Item *>(tmp->widget());
    //    count = item->getIndex();
    //    tmp->setPos((blank + (count%4)*widgetWidth), (blank + (int)(count/4)*widgetHeight));
    //}
    foreach(Item *tmp, *list)
    {
        count = tmp->getIndex();
        x = blank + (count%4)*widgetWidth;
        y = blank + (int)(count/4)*widgetHeight;

        QPropertyAnimation *animation = new QPropertyAnimation(tmp, "geometry");
        animation->setDuration(1000);
        //animation->setStartValue(tmp->rect());
        //animation->setEndValue(QPoint(x,y));
        animation->setStartValue(QRect(tmp->x(),tmp->y(),widgetWidth,widgetHeight));
        animation->setEndValue(QRect(x,y,widgetWidth,widgetHeight));
        animation->setEasingCurve(QEasingCurve::InOutCirc);
        animation->start();

        //tmp->move(x, y);
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
    qDebug() << "Good luck!";
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

    qDebug() << "Configure!";
}
void MainWindow::actionTriggerFigure_triggered(int state)
{
    foreach(Item *tmp, *list)
    {
        tmp->toggle(state);
    }
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
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
    addItem();
}
