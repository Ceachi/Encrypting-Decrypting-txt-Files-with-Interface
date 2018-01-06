/********************************************************************************
** Form generated from reading UI file 'CryptFiles.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRYPTFILES_H
#define UI_CRYPTFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CryptFilesClass
{
public:
    QWidget *centralWidget;
    QPushButton *cryptButton;
    QPushButton *decryptButton;
    QPushButton *browseButton;
    QLabel *label;
    QPushButton *exitButton;
    QLabel *browseLabel;
    QLabel *messageLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CryptFilesClass)
    {
        if (CryptFilesClass->objectName().isEmpty())
            CryptFilesClass->setObjectName(QStringLiteral("CryptFilesClass"));
        CryptFilesClass->resize(446, 288);
        centralWidget = new QWidget(CryptFilesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cryptButton = new QPushButton(centralWidget);
        cryptButton->setObjectName(QStringLiteral("cryptButton"));
        cryptButton->setGeometry(QRect(40, 120, 75, 23));
        decryptButton = new QPushButton(centralWidget);
        decryptButton->setObjectName(QStringLiteral("decryptButton"));
        decryptButton->setGeometry(QRect(130, 120, 75, 23));
        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(210, 90, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 321, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(350, 200, 75, 23));
        browseLabel = new QLabel(centralWidget);
        browseLabel->setObjectName(QStringLiteral("browseLabel"));
        browseLabel->setGeometry(QRect(40, 90, 171, 21));
        browseLabel->setFrameShape(QFrame::Box);
        browseLabel->setFrameShadow(QFrame::Raised);
        browseLabel->setLineWidth(2);
        messageLabel = new QLabel(centralWidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(40, 150, 261, 21));
        CryptFilesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CryptFilesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 446, 21));
        CryptFilesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CryptFilesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CryptFilesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CryptFilesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CryptFilesClass->setStatusBar(statusBar);

        retranslateUi(CryptFilesClass);

        QMetaObject::connectSlotsByName(CryptFilesClass);
    } // setupUi

    void retranslateUi(QMainWindow *CryptFilesClass)
    {
        CryptFilesClass->setWindowTitle(QApplication::translate("CryptFilesClass", "CryptFiles", 0));
        cryptButton->setText(QApplication::translate("CryptFilesClass", "Crypt File", 0));
        decryptButton->setText(QApplication::translate("CryptFilesClass", "Decrypt File", 0));
        browseButton->setText(QApplication::translate("CryptFilesClass", "Browse", 0));
        label->setText(QApplication::translate("CryptFilesClass", "Crypting/Decrypting Application", 0));
        exitButton->setText(QApplication::translate("CryptFilesClass", "EXIT", 0));
        browseLabel->setText(QApplication::translate("CryptFilesClass", "C://", 0));
        messageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CryptFilesClass: public Ui_CryptFilesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRYPTFILES_H
