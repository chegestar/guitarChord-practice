#include "configure.h"
#include "ui_configure.h"
#include "list.h"
#include "adddialog.h"

#include <QDomElement>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QDebug>

configure::configure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configure)
{

    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    QStringList HorizontalHeaderLabels;
    HorizontalHeaderLabels << "Name"<< "Figure";
    ui->tableWidget->setHorizontalHeaderLabels(HorizontalHeaderLabels);
    //ui->tableWidget->resizeColumnToContents(1);


    addItem();
    update = false;
    //ui->tableWidget->show();

}

configure::~configure()
{
    delete ui;
}

void configure::addItem()
{

    QDomElement docElem = readXML()->documentElement();
    //QDomElement docElem = readXML()->documentElement();
    QDomNodeList nodeList = docElem.elementsByTagName("item").at(0).toElement().elementsByTagName("Chord");

    if(nodeList.count() > 0)
    {
        ui->tableWidget->setRowCount(nodeList.count());
        for(int iDx = 0; iDx < nodeList.count(); iDx++)
        {
            QString name(nodeList.at(iDx).attributes().namedItem("Name").nodeValue());
            QString figPath(nodeList.at(iDx).attributes().namedItem("Figure").nodeValue());
            QTableWidgetItem *nameItem = new QTableWidgetItem(name);
            QTableWidgetItem *pathItem = new QTableWidgetItem(figPath);
            ui->tableWidget->setItem(iDx, 0, nameItem );
            ui->tableWidget->setItem(iDx, 1, pathItem );
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
    add = boost::shared_ptr<addDialog>(new addDialog(this));
    add->setWindowTitle("Add new");
    add->exec();
    add->raise();
    //qDebug() << " Add clicked";

    connect(add.get(), SIGNAL(returnInfo(QString , QString )),
            this, SLOT(AddDone(QString , QString )));
}

void configure::on_Delete_clicked()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
    update = true;

}
void configure::on_OK_clicked()
{
    //qDebug()<< "OK";

    if(update)
    {
        int i = 0;
        QDomDocument doc("configure");
        QDomElement root = doc.createElement("configure");
        doc.appendChild(root);
        QDomElement item = doc.createElement("item");
        root.appendChild(item);

        int num =  ui->tableWidget->rowCount();
        //qDebug() << ui->tableWidget->rowCount();
        for(i = 0; i < num; i++)
        {
            QTableWidgetItem * nameItem = ui->tableWidget->item(i, 0);
            QTableWidgetItem * pathItem = ui->tableWidget->item(i, 1);
            QString name = nameItem->text();
            QString path = pathItem->text();

            QDomElement node = doc.createElement("Chord");
            node.setAttribute( "Name", name);
            node.setAttribute( "Figure", path);
            item.appendChild(node);
        }

        writeXML(doc);
        emit reload();
    }
    close();
}

void configure::AddDone(QString name, QString path)
{
    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *pathItem = new QTableWidgetItem(path);
    int last = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(last);
    ui->tableWidget->setItem(last, 0, nameItem);
    ui->tableWidget->setItem(last, 1, pathItem);

    //qDebug() << name << path;

    update = true;
}
