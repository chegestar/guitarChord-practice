/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created: Wed Feb 15 21:39:21 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *NameEdit;
    QLabel *label_2;
    QLineEdit *PathEdit;
    QPushButton *ChooseFile;
    QPushButton *Cancel;
    QPushButton *OK;

    void setupUi(QWidget *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QString::fromUtf8("addDialog"));
        addDialog->resize(400, 111);
        gridLayout = new QGridLayout(addDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(addDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        NameEdit = new QLineEdit(addDialog);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));

        gridLayout->addWidget(NameEdit, 0, 1, 1, 2);

        label_2 = new QLabel(addDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        PathEdit = new QLineEdit(addDialog);
        PathEdit->setObjectName(QString::fromUtf8("PathEdit"));

        gridLayout->addWidget(PathEdit, 1, 1, 1, 2);

        ChooseFile = new QPushButton(addDialog);
        ChooseFile->setObjectName(QString::fromUtf8("ChooseFile"));

        gridLayout->addWidget(ChooseFile, 1, 3, 1, 1);

        Cancel = new QPushButton(addDialog);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 2, 3, 1, 1);

        OK = new QPushButton(addDialog);
        OK->setObjectName(QString::fromUtf8("OK"));

        gridLayout->addWidget(OK, 2, 2, 1, 1);


        retranslateUi(addDialog);
        QObject::connect(Cancel, SIGNAL(clicked()), addDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QWidget *addDialog)
    {
        addDialog->setWindowTitle(QApplication::translate("addDialog", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addDialog", "Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addDialog", "Figure path:", 0, QApplication::UnicodeUTF8));
        ChooseFile->setText(QApplication::translate("addDialog", "Choose..", 0, QApplication::UnicodeUTF8));
        Cancel->setText(QApplication::translate("addDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("addDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
