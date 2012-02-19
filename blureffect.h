#ifndef BLUREFFECT_H
#define BLUREFFECT_H

#include <QGraphicsEffect>
#include <QWidget.h>


class BlurEffect: public QGraphicsBlurEffect
{
public:
    BlurEffect(QWidget widget);
    void setBaseLine(qreal y) {m_baseLine = y;}
    QRectF boundingRect() const;
    void draw(QPainter *painter);
private:
    void adjustForItem();
private:
    qreal m_baseLine;
    QWidget *widget;
};

#endif /* end of include guard: BLUREFFECT_H */
