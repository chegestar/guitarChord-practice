#include "adddialog.h"
#include "ui_adddialog.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

addDialog::addDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void addDialog::on_OK_clicked()
{
     QString name = ui->NameEdit->text();
     QString path = ui->PathEdit->text();

     if(name.isEmpty() | path.isEmpty()) close();
     else emit returnInfo(name, path);
     //qDebug() << name << path;
     close();
}

void addDialog::on_ChooseFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Image"),
            "~/", tr("Image Files (*.png *.jpg *.bmp *.gif)"));
    if(path.isEmpty()) QMessageBox::warning(this, tr("Choose Image"),
            tr("No file specified"), QMessageBox::Close);
    else ui->PathEdit->setText(path);
}
