/********************************************************************************
** Form generated from reading UI file 'firstwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTWINDOW_H
#define UI_FIRSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Firstwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *klein;
    QPushButton *mittel;
    QPushButton *gross;

    void setupUi(QWidget *Firstwindow)
    {
        if (Firstwindow->objectName().isEmpty())
            Firstwindow->setObjectName(QStringLiteral("Firstwindow"));
        Firstwindow->resize(400, 290);
        verticalLayout_2 = new QVBoxLayout(Firstwindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(Firstwindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        klein = new QPushButton(Firstwindow);
        klein->setObjectName(QStringLiteral("klein"));

        horizontalLayout_2->addWidget(klein);

        mittel = new QPushButton(Firstwindow);
        mittel->setObjectName(QStringLiteral("mittel"));

        horizontalLayout_2->addWidget(mittel);

        gross = new QPushButton(Firstwindow);
        gross->setObjectName(QStringLiteral("gross"));

        horizontalLayout_2->addWidget(gross);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Firstwindow);

        QMetaObject::connectSlotsByName(Firstwindow);
    } // setupUi

    void retranslateUi(QWidget *Firstwindow)
    {
        Firstwindow->setWindowTitle(QApplication::translate("Firstwindow", "Firstwindow", 0));
        klein->setText(QApplication::translate("Firstwindow", "PushButton", 0));
        mittel->setText(QApplication::translate("Firstwindow", "PushButton", 0));
        gross->setText(QApplication::translate("Firstwindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Firstwindow: public Ui_Firstwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTWINDOW_H
