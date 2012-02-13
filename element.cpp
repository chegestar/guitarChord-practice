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
    //qDebug() << name << figPath;

    nameLabel = new QLabel(name);
    imageLabel = new QLabel();
    layout = new QVBoxLayout();
    font = new QFont();

    nameLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setScaledContents(true);
    *font = nameLabel->font();
    if( !figPath.isEmpty())
    {
        QImage image(figPath);
        if(image.isNull())
            QMessageBox::information(this, tr("oops!"), tr("Cannot load %1 image.").arg(name));
        else imageLabel->setPixmap(QPixmap::fromImage(image.scaled(150, 170, Qt::IgnoreAspectRatio,Qt::FastTransformation)));
        //qDebug() << tr("load image");
    }

    layout->addWidget( nameLabel);
    layout->addWidget( imageLabel);

    setLayout(layout);
    resize(QWidget::minimumSizeHint());

}

Item::Item()
{

}

void Item::mouseDoubleClickEvent(QMouseEvent *event)
{
    toggle();
    qDebug() << "hey, what are you doing?";
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

void Item::toggle(int i)
{
    if( i == 2)
    {
        if(imageLabel->isVisible()) return;
        else
        {
            nameLabel->setFont(*font);
            imageLabel->show();
        }
    }
    if( i == 0)
    {
        if(imageLabel->isVisible()) {
            imageLabel->hide();
            QFont newFont;
            newFont.setPointSize(32);
            newFont.setBold(true);
            nameLabel->setFont(newFont);
        }
        else return;
    }
    if( i == 1)
    {
        if(imageLabel->isVisible()) {
            imageLabel->hide();
            QFont newFont;
            newFont.setPointSize(32);
            newFont.setBold(true);
            nameLabel->setFont(newFont);
        }
        else
        {
            nameLabel->setFont(*font);
            imageLabel->show();
        }
    }

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

int Item::getIndex()
{
    return index;
}

void Item::setIndex(int i)
{
    index = i;
}
