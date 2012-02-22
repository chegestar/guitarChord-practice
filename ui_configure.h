/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created: Wed Feb 22 22:14:34 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_H
#define UI_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_configure
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;
    QPushButton *Cancel;
    QPushButton *OK;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QPushButton *Add;
    QPushButton *Delete;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *configure)
    {
        if (configure->objectName().isEmpty())
            configure->setObjectName(QString::fromUtf8("configure"));
        configure->resize(423, 285);
        configure->setFocusPolicy(Qt::ClickFocus);
        horizontalLayout = new QHBoxLayout(configure);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(configure);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout->addWidget(tableWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        Cancel = new QPushButton(configure);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 7, 0, 1, 1);

        OK = new QPushButton(configure);
        OK->setObjectName(QString::fromUtf8("OK"));

        gridLayout->addWidget(OK, 6, 0, 1, 1);

        line = new QFrame(configure);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Add = new QPushButton(configure);
        Add->setObjectName(QString::fromUtf8("Add"));

        verticalLayout->addWidget(Add);

        Delete = new QPushButton(configure);
        Delete->setObjectName(QString::fromUtf8("Delete"));

        verticalLayout->addWidget(Delete);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 2, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(configure);
        QObject::connect(Cancel, SIGNAL(clicked()), configure, SLOT(close()));

        QMetaObject::connectSlotsByName(configure);
    } // setupUi

    void retranslateUi(QDialog *configure)
    {
        configure->setWindowTitle(QApplication::translate("configure", "Configure", 0, QApplication::UnicodeUTF8));
        Cancel->setText(QApplication::translate("configure", "Cancel", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("configure", "OK", 0, QApplication::UnicodeUTF8));
        Add->setText(QApplication::translate("configure", "Add...", 0, QApplication::UnicodeUTF8));
        Delete->setText(QApplication::translate("configure", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class configure: public Ui_configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
