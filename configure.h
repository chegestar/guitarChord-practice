#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <boost/shared_ptr.hpp>

namespace Ui {
    class configure;
}

class addDialog;
class QStandardItemModel;

class configure : public QDialog {
    Q_OBJECT
public:
    configure(QWidget *parent = 0);
    ~configure();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::configure *ui;
    boost::shared_ptr<addDialog> add;
    void addItem();
    bool update;
signals:
    void reload();

private slots:
    void on_Add_clicked();
    void on_OK_clicked();
    void on_Delete_clicked();
    void AddDone(QString, QString);
};

#endif // CONFIGURE_H
