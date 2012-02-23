#include <QtGlobal>
#include <QTime>
#include <QFile>
#include <QString>
#include <QDomNodeList>
#include <QMessageBox>
#include <QDebug>
#include <QDir>

#include "list.h"
#include "element.h"

bool indexLessThan(Item * i1, Item * i2)
{
    return (i1->getIndex() < i2->getIndex());
}

void randomize(QList<Item *> * org)
{
    QList<Item*> tmp; 
    tmp = *org;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int next = 0;
    do
    {
        // generate the random index
        int base = tmp.size();
        int rIndex = qrand()%base;

        Item *selectedItem = new Item();
        selectedItem = tmp.at(rIndex);
        
        org->at(org->indexOf(selectedItem))->setIndex(next);
        tmp.removeAt(rIndex);

        ++next;


    }while(!tmp.empty());
    qSort(org->begin(), org->end(),indexLessThan);


}

QDomDocument * readXML(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << QString("Error: cannot read file %1%2").arg(fileName).arg(file.errorString());

    QDomDocument *doc = new QDomDocument();
    if( !doc->setContent(&file))
        file.close();
    file.close();
    return doc;
}

void writeXML(QDomDocument &doc, QString fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << QString("Error: cannot write file %1%2").arg(fileName).arg(file.errorString());
        return ;
    }

    QTextStream ts(&file);
    ts << doc.toString();
    file.close();
}

bool readConfiguration(QList<Item *> *itemList, QString fileName)
{
    QDomElement docElem = readXML(fileName)->documentElement();
    if(docElem.isNull()) return false;

    QDomNodeList nodeList = docElem.elementsByTagName("item").at(0).toElement().elementsByTagName("Chord");

    if(nodeList.count() > 0)
    {
        for(int iDx = 0; iDx < nodeList.count(); iDx++)
        {
            QString name(nodeList.at(iDx).attributes().namedItem("Name").nodeValue());
            QString figPath(nodeList.at(iDx).attributes().namedItem("Figure").nodeValue());
            Item *tmp = new Item(name, figPath, iDx);
            itemList->append( tmp );
        }
        return true;
    }
    else return false;
    //qDebug()<< itemList->size();
    //randomize(itemList);
    //printList(*itemList);
}

bool scanFolder(QList<Item *> *itemList, QString path)
{
    QDir dir = QDir(path);
    if(!dir.exists())
    {
        QMessageBox::information(0, QObject::tr("OOps!"), QObject::tr(" \"%1\" folder is not found").arg(path));
        return false;
    }
    else
    {
        QFileInfoList list;
        list = dir.entryInfoList( QDir::Files | QDir::NoSymLinks);
        if(list.size() == 0)
        {
            QMessageBox::information(0, QObject::tr("OOps!"), QObject::tr(" \"%1\" folder is empty").arg(path));
            return false;
        }

        for(int i = 0; i< list.size(); ++i) 
        {
            QFileInfo info = list.at(i);
            qDebug() << info.baseName() << info.filePath();
            Item *tmp = new Item(info.baseName(), info.filePath(), i);
            itemList->append(tmp);
        }
        //randomize(itemList);
        return true;
    }

}

void printList(QList<Item *> & list)
{
    QList<Item *>::iterator i;
    for(i = list.begin(); i != list.end(); ++i)
        qDebug()<< (*i)->getIndex() << (*i)->getName();
}

