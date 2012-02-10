#include "element.h"

Item::Item( QString chordName,\
        QString path, int order,\
        QGraphicsItem * parent):QGraphicsWidget(parent)
{
    name = chordName;
    figPath = path;
    index = order;
}

Item::Item()
{

}

void Item::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    toggle();
}

QRectF Item::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  50 + penWidth, 50 + penWidth);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(-10, -10, 50, 50, 5, 5);
}

void Item::reDraw()
{
}

void Item::toggle()
{
}

void Item::draw()
{
}

void Item::customizeItem()
{
}

const QString Item::getName()
{
    return name;
}

const QString Item::getFigPath()
{
    return figPath;
}

int Item::getNextPosition()
{
    return nextPosition;
}

int Item::returnIndex()
{
    return index;
}
