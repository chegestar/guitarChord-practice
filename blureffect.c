#include "blureffect.h"

#include <QDebug>

BlurEffect::BlurEffect(QWidget *widget)
    : QGraphicsBlurEffect()
      , m_baseLine(200), widget(widget)
{
}

void BlurEffect::adjustForItem()
{
    qreal y = m_baseLine - item->pos().y();
    qreal radius = qBound(qreal(0,0), y / 32, qreal(16,0));
    setBlurRadius(radius);
}

QRectF BlurEffect::boundingRect() const
{
    const_cast<BlurEffect *>(this)->adjustForItem();
    return QGraphicsBlurEffect::boundingRect();
}

void BlurEffect::draw(QPainter *painter)
{
    adjustForItem();
    QGraphicsBlurEffect::draw(painter);
}
