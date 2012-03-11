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
signals:
    void returnInfo(QString, QString);

private slots:
    void on_ChooseFile_clicked();
    void on_OK_clicked();
};

#endif // ADDDIALOG_H
