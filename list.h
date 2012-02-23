#ifndef LIST_H
#define LIST_H

class QDomDocument;
class Item;

void randomize(QList<Item *> * org);
bool indexLessThan(Item *i1, Item *i2);
QDomDocument * readXML(QString fileName = "configure.xml");
void writeXML(QDomDocument &doc, QString fileName = "configure.xml");
bool readConfiguration(QList<Item *> *itemList, QString fileName = "configure.xml");
void printList(QList<Item *> &list);
bool scanFolder(QList<Item *> *itemList, QString path = "./figure");

#endif // LIST_H
