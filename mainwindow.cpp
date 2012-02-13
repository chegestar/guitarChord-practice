#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"

#include <QDebug>
#include <QObject>
#include <QGraphicsProxyWidget>
#include <QShortcut>
#include <QCheckBox>

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

    widgetList = new QList<QGraphicsProxyWidget *>();
    //scene->addRect(QRectF(0, 0, 100, 200),QPen(Qt::black), QBrush(Qt::green));
    //scene->addText("hello world");
    list = new QList<Item *>();
    readConfiguration(list);
    addItem(*list);

    view->setScene(scene);
    setCentralWidget(view);
    view->setAlignment(Qt::AlignCenter);
    view->show();

    ui->statusBar->showMessage(tr("Q(uit), A(bout), R(andom), C(configure)"));

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


int MainWindow::addItem(QList<Item *> &iList)
{
    int i = 0;
    qreal x = 0;
    foreach(Item *item, iList)
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
    int widgetWidth = widgetList->first()->size().width();
    int widgetHeight = widgetList->first()->size().height();
    int blank = 5;
    int count = 0;
    //qDebug() << windowWidth << windowHeight << widgetWidth << widgetHeight;

    int x = windowWidth % widgetWidth;
    foreach(QGraphicsProxyWidget *tmp, *widgetList)
    {
        Item *item = dynamic_cast<Item *>(tmp->widget());
        count = item->getIndex();
        tmp->setPos((blank + (count%4)*widgetWidth), (blank + (int)(count/4)*widgetHeight));
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
    ab  = new aboutDialog();
    ab->show();
}

void MainWindow::actionConfigure_triggered()
{

    qDebug() << "Configure!";
}
void MainWindow::actionTriggerFigure_triggered(int state)
{
    foreach(Item *tmp, *list)
    {
        tmp->toggle(state);
    }
}
