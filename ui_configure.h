/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created: Sun Feb 12 21:55:12 2012
**      by: Qt User Interface Compiler version 4.6.3
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
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configure
{
public:
    QListView *listView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QFrame *line;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *configure)
    {
        if (configure->objectName().isEmpty())
            configure->setObjectName(QString::fromUtf8("configure"));
        configure->resize(423, 285);
        configure->setFocusPolicy(Qt::ClickFocus);
        listView = new QListView(configure);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 281, 271));
        listView->setSelectionMode(QAbstractItemView::MultiSelection);
        listView->setMovement(QListView::Free);
        listView->setResizeMode(QListView::Adjust);
        listView->setLayoutMode(QListView::Batched);
        gridLayoutWidget = new QWidget(configure);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(300, 10, 111, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 5, 0, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(configure);

        QMetaObject::connectSlotsByName(configure);
    } // setupUi

    void retranslateUi(QDialog *configure)
    {
        configure->setWindowTitle(QApplication::translate("configure", "Configure", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("configure", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("configure", "Cancle", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("configure", "Add...", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("configure", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class configure: public Ui_configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
