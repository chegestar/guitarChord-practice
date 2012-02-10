#ifndef LIST_H
#define LIST_H

#include "element.h"

void randomize(QList<Item *> * org);
bool readConfiguration(QList<Item *> *itemList, QString fileName = "configure.xml");
void printList(QList<Item *> &list);

#endif // LIST_H
