#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
    class addDialog;
}

class addDialog : public QDialog {
    Q_OBJECT
public:
    addDialog(QWidget *parent = 0);
    ~addDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
