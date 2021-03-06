#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,400,400,this);
    view = new QGraphicsView(this);
    //scene->addRect(QRectF(0, 0, 100, 200),QPen(Qt::black), QBrush(Qt::green));
    //scene->addText("hello world");
    view->setScene(scene);
    setCentralWidget(view);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
    delete scene;
}

int MainWindow::addItem(QList<Item *> &iList)
{
    int i = 0;
    foreach(Item *item, iList)
    {
        QGraphicsProxyWidget *proxy = scene->addWidget(item);
        proxy->setPos(80*i, 40);
        proxy->show();
        ++i;
    }
    view->update();
    return i;
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
