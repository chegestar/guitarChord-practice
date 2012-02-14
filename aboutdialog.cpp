#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButton->setFocus(Qt::OtherFocusReason);
    //setFocus(Qt::ActiveWindowFocusReason);
    //setFocusPolicy(Qt::ClickFocus);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

void aboutDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void aboutDialog::focusOutEvent(QFocusEvent *e)
{
    QDialog::focusOutEvent(e);
    //close();
}

