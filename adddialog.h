#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QWidget>
#include <QString>


namespace Ui {
    class addDialog;
}

class addDialog : public QWidget {
    Q_OBJECT
public:
    addDialog(QWidget *parent = 0);
    ~addDialog();

protected:
    void changeEvent(QEvent *e);
signals:
    void returnInfo(QString Name, QString path);

private:
    Ui::addDialog *ui;
    QString Name;
    QString Path;
private slots:
    void on_OK_clicked();
    void on_ChooseFile_clicked();

};

#endif // ADDDIALOG_H
