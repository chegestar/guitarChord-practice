#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>

namespace Ui {
    class configure;
}

class configure : public QDialog {
    Q_OBJECT
public:
    configure(QWidget *parent = 0);
    ~configure();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::configure *ui;
};

#endif // CONFIGURE_H
