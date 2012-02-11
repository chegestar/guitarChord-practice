#include "element.h"
#include <QMessageBox>
#include <QDebug>
#include <QImage>


Item::Item( QString chordName,
        QString path, int order,
        QWidget * parent):QWidget(parent)
{
    name = chordName;
    figPath = path;
    index = order;
    qDebug() << name << figPath;

    nameLabel = new QLabel(name);
    imageLabel = new QLabel();
    layout = new QVBoxLayout();

    nameLabel->setAlignment(Qt::AlignCenter);
    if( !figPath.isEmpty())
    {
        QImage image(figPath);
        if(image.isNull())
            QMessageBox::information(this, tr("oops!"), tr("Cannot load %1 image.").arg(name));
        else imageLabel->setPixmap(QPixmap::fromImage(image));
        qDebug() << tr("load image");
    }

    layout->addWidget( nameLabel);
    layout->addWidget( imageLabel);

    setLayout(layout);
    resize(QWidget::minimumSizeHint());

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
