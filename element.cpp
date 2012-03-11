#include "element.h"
#include <QMessageBox>
#include <QDebug>
#include <QImage>


Item::Item(QString chordName, QString path, int order, QWidget *parent):
    QWidget(parent),
    name(chordName),
    figPath(path),
    index(order)
{
    //name = chordName;
    //figPath = path;
    //index = order;
    //qDebug() << name << figPath;

    progressBar = new QProgressBar();
    progressBar->setRange(0,9);
    //progressBar->resize(QWidget::minimumSizeHint());
    progressBar->setFixedHeight(4);
    //progressBar->setFixedWidth(size().width());

    progressBar->setValue(0);
    progressBar->setTextVisible(false);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));

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
            QMessageBox::information(this, tr("OOps!"), tr("Cannot load %1 image.").arg(name));
        //else imageLabel->setPixmap(QPixmap::fromImage(image.scaledToWidth(130, Qt::KeepAspectRatio,Qt::FastTransformation)));
        else imageLabel->setPixmap(QPixmap::fromImage(image));
    }

    layout->addWidget( nameLabel);
    layout->addWidget( imageLabel);
    layout->addWidget( progressBar);
    //progressBar->hide();

    setLayout(layout);
    resize(QWidget::minimumSizeHint());

    setWindowFlags(Qt::FramelessWindowHint);
    progressBar->setStyleSheet("QProgressBar:horizontal { border: 0px ; border-radius: 0px; background: transparent; padding: 0px; } QProgressBar::chunk:horizontal { background: red; }");
    //setStyleSheet("QFrame { margin: 0px; border: 0px ; padding: 0px; background-color: transparent; } ");
    //imageLabel->setStyleSheet("QFrame { margin: 0px; border: 0px ; padding: 0px; background-color: transparent; } ");
    //nameLabel->setStyleSheet("QFrame { margin: 0px; border: 0px ; padding: 0px; background-color: transparent; } ");
}

Item::Item()
{
}

Item::~Item()
{
    delete nameLabel;
    delete imageLabel;
    delete font;
    delete layout;
    delete progressBar;
    delete timer;
}

void Item::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget::mouseDoubleClickEvent(event);

    toggle();
    //qDebug() << "hey, what are you doing?";
}
/*
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
*/

void Item::reDraw()
{
}

void Item::fireProgressBar(int msec)
{
    if(msec > 0) 
    {
        int interval =  msec / 10;
        timer->setInterval(interval);
        timer->start();
        progressBar->show();
        //resize(QWidget::minimumSizeHint());
    }
    else 
    {
        if(msec < 0) 
        {
            progressBar->setValue(0);
            progressBar->hide();
            resize(QWidget::minimumSizeHint());
            timer->stop();
        }
        else
        {
            progressBar->setValue(0);
            //progressBar->hide();
            timer->stop();
        }

    }
}

void Item::timeout()
{
    int i = progressBar->value();
    if(i >= 0 && (++i <= progressBar->maximum()))
        progressBar->setValue(i);
    else timer->stop();
}

void Item::toggle(int i)
{
    bool imageVisible = imageLabel->isVisible();
    if( i == 2)
    {
        if(imageVisible) return;
        else
        {
            nameLabel->setFont(*font);
            imageLabel->show();
        }
    }
    if( i == 0)
    {
        if(imageVisible) {
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
        if(imageVisible) {
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

const QString Item::getName() const
{
    return name;
}

const QString Item::getFigPath() const
{
    return figPath;
}

int Item::getIndex() const
{
    return index;
}

void Item::setIndex(int i)
{
    index = i;
}
