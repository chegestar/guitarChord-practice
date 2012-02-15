#include "configure.h"
#include "ui_configure.h"
#include "list.h"
#include <QDomElement>
#include <QDebug>

configure::configure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configure)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    model->setColumnCount(2);
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Figure");
    ui->tableView->setModel(model);

    addItem();

}

configure::~configure()
{
    delete ui;
}

void configure::addItem()
{

    QDomElement docElem = readXML()->documentElement();
    QDomNodeList nodeList = docElem.elementsByTagName("item").at(0).toElement().elementsByTagName("Type");

    if(nodeList.count() > 0)
    {
        for(int iDx = 0; iDx < nodeList.count(); iDx++)
        {
            bool bOK = false;
            int iD = nodeList.at(iDx).attributes().namedItem("Id").nodeValue().toInt(&bOK,10);
            QString name(nodeList.at(iDx).attributes().namedItem("Name").nodeValue());
            QString figPath(nodeList.at(iDx).attributes().namedItem("Figure").nodeValue());
            QStandardItem *nameItem = new QStandardItem(name);
            QStandardItem *pathItem = new QStandardItem(figPath);
            model->setItem(iD, 0, nameItem );
            model->setItem(iD, 1, pathItem );
        }
    }

    //model->setRowCount(nodeList.count());

}

void configure::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void configure::on_Add_clicked()
{
    add = new addDialog();
    add->setWindowTitle("Add new");
    add->show();
    add->raise();
    qDebug() << " Add clicked";

    connect(add, SIGNAL(returnInfo(QString , QString )),
            this, SLOT(AddDone(QString , QString )));
}

void configure::on_OK_clicked()
{
    qDebug()<< "OK";
    // write back xml
    close();
}

void configure::AddDone(QString name, QString path)
{
    QStandardItem *nameItem = new QStandardItem(name);
    QStandardItem *pathItem = new QStandardItem(path);
    QList<QStandardItem *> list;
    list << nameItem << pathItem;

    //qDebug() << name << path;

    model->appendRow( list );
}
