#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsWidget>
#include <QString>
#include <QPainter>

class Item: public QGraphicsWidget
{
public:

    Item(QString chordName, QString path, int order, QGraphicsItem* parent = 0) ;
    Item();
    // redraw in new postion
    void reDraw();
    // draw the item
    void draw();
    // toggle to show or hide the figure
    void toggle();
    // customize the appearance of item
    void customizeItem();

    // access funtions
    const QString getName();
    const QString getFigPath();
    int getNextPosition();
    int returnIndex();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // mouse event handler
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    // chrod name
    QString name;
    // figure file path
    QString figPath;
    // the index in database
    int index;
    // next position when refresh
    int nextPosition;

    //QPainter painter;
};

#endif // ELEMENT_H
