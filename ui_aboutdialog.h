/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Wed Feb 22 22:14:34 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->setWindowModality(Qt::WindowModal);
        aboutDialog->resize(243, 97);
        aboutDialog->setFocusPolicy(Qt::ClickFocus);
        aboutDialog->setContextMenuPolicy(Qt::NoContextMenu);
        aboutDialog->setAcceptDrops(true);
        aboutDialog->setAutoFillBackground(true);
        pushButton = new QPushButton(aboutDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 70, 92, 27));
        textBrowser = new QTextBrowser(aboutDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 10, 201, 51));
        textBrowser->setFocusPolicy(Qt::ClickFocus);
        textBrowser->setContextMenuPolicy(Qt::NoContextMenu);
        textBrowser->setAutoFillBackground(true);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Sunken);

        retranslateUi(aboutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), aboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "About", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("aboutDialog", "OK", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("aboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Author: Renlin Li</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">E-mail: lirenlin@gmail.com</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
