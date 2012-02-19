#ifndef ELEMENT_H
#define ELEMENT_H
#include <QWidget>
#include <QGraphicsItem>
#include <QString>
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>

class Item: public QWidget
{
public:

    Item(QString chordName, QString path, int order, QWidget* parent = 0) ;
    Item();
    // redraw in new postion
    void reDraw();
    // draw the item
    void draw();
    // toggle to show or hide the figure
    void toggle(int i = 1);
    // customize the appearance of item
    void customizeItem();

    // access funtions
    const QString getName();
    const QString getFigPath();
    int getIndex();
    void setIndex(int);

    //QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // mouse event handler
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    // chrod name
    QString name;
    // figure file path
    QString figPath;
    // the index in database
    int index;
    int nextIndex;
    // painter
    QPainter painter;
    QLabel *nameLabel;
    QLabel *imageLabel;
    QFont *font;
    QVBoxLayout *layout;
};

#endif // ELEMENT_H
