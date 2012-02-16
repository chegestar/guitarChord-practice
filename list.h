#ifndef LIST_H
#define LIST_H

class QDomDocument;
class Item;

void randomize(QList<Item *> * org);
QDomDocument * const readXML(QString fileName = "configure.xml");
void writeXML(QDomDocument &doc, QString fileName = "configure.xml");
bool readConfiguration(QList<Item *> *itemList, QString fileName = "configure.xml");
void printList(QList<Item *> &list);

#endif // LIST_H
