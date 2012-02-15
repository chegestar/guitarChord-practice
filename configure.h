#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QStandardItemModel>
#include "adddialog.h"

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
    QStandardItemModel *model;
    addDialog *add;
    void addItem();

private slots:
    void on_Add_clicked();
    void on_OK_clicked();
    void AddDone(QString, QString);
};

#endif // CONFIGURE_H
