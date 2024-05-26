/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameMenu)
    {
        if (GameMenu->objectName().isEmpty())
            GameMenu->setObjectName(QStringLiteral("GameMenu"));
        GameMenu->resize(860, 600);
        GameMenu->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        centralwidget = new QWidget(GameMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(670, 350, 131, 61));
        GameMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 860, 26));
        GameMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(GameMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GameMenu->setStatusBar(statusbar);

        retranslateUi(GameMenu);

        QMetaObject::connectSlotsByName(GameMenu);
    } // setupUi

    void retranslateUi(QMainWindow *GameMenu)
    {
        GameMenu->setWindowTitle(QApplication::translate("GameMenu", "GameMenu", Q_NULLPTR));
        label->setText(QApplication::translate("GameMenu", "music", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameMenu: public Ui_GameMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
