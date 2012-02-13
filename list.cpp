#include <QtGlobal>
#include <QTime>
#include <QPair>
#include <QGraphicsItem>
#include <QFile>
#include <QString>
#include <QDomDocument>
#include <QDomNodeList>
#include <QDebug>
#include "list.h"

// get a new random orderd list from the original one

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
        //tmp->append(slectedItem);
        
        org->at(org->indexOf(selectedItem))->setIndex(next);
        tmp.removeAt(rIndex);
        //org->at(rIndex)->setIndex(next);
        ++next;


    }while(!tmp.empty());

    //org->append(*tmp);

}

bool readConfiguration(QList<Item *> *itemList, QString fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << QString("Error: cannot read file %1%2").arg(fileName).arg(file.errorString());
        return false;
    }

    QDomDocument doc;
    if( !doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();

    QDomElement docElem = doc.documentElement();
    QDomNodeList nodeList = docElem.elementsByTagName("item").at(0).toElement().elementsByTagName("Type");

    if(nodeList.count() > 0)
    {
        for(int iDx = 0; iDx < nodeList.count(); iDx++)
        {
            bool bOK = false;
            int iD = nodeList.at(iDx).attributes().namedItem("Id").nodeValue().toInt(&bOK,10);
            QString name(nodeList.at(iDx).attributes().namedItem("Name").nodeValue());
            QString figPath(nodeList.at(iDx).attributes().namedItem("Figure").nodeValue());
            Item *tmp = new Item(name, figPath, iD);
            itemList->append( tmp );
        }
    }
    //qDebug()<< itemList->size();
    randomize(itemList);
    //printList(*itemList);
    return true;
}

void printList(QList<Item *> & list)
{
    QList<Item *>::iterator i;
    for(i = list.begin(); i != list.end(); ++i)
        qDebug()<< (*i)->getIndex() << (*i)->getName();
}
