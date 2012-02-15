#ifndef LIST_H
#define LIST_H

#include "element.h"
#include <QDomDocument>

void randomize(QList<Item *> * org);
QDomDocument * const readXML(QString fileName = "configure.xml");
bool readConfiguration(QList<Item *> *itemList, QString fileName = "configure.xml");
void printList(QList<Item *> &list);

#endif // LIST_H
