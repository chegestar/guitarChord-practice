#ifndef ELEMENT_H
#define ELEMENT_H
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QTimer>

class Item: public QWidget
{
    Q_OBJECT
public:

    Item(QString chordName, QString path, int order, QWidget *parent = 0) ;
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
    const QString getName() const;
    const QString getFigPath() const;
    int getIndex() const;
    void setIndex(int);
    void fireProgressBar(int);

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
    // painter
    QLabel *nameLabel;
    QLabel *imageLabel;
    QFont *font;
    QVBoxLayout *layout;
    QProgressBar *progressBar;
    QTimer *timer;

private slots:
    void timeout();

};

#endif // ELEMENT_H
