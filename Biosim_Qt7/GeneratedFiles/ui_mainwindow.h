/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Staerke;
    QLineEdit *lineEdit_Staerke;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Geschwindigkeit;
    QLineEdit *lineEdit_Geschwindigkeit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Lebensdauer;
    QLineEdit *lineEdit_Lebensdauer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Eigenschaften;
    QLineEdit *lineEdit_Eigenschaften;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Platzieren;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Simulationssteuerung;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Pause;
    QPushButton *pushButton_Schritt;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuBiosim;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(632, 393);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Staerke = new QLabel(groupBox);
        label_Staerke->setObjectName(QStringLiteral("label_Staerke"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Staerke->sizePolicy().hasHeightForWidth());
        label_Staerke->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_Staerke);

        lineEdit_Staerke = new QLineEdit(groupBox);
        lineEdit_Staerke->setObjectName(QStringLiteral("lineEdit_Staerke"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_Staerke->sizePolicy().hasHeightForWidth());
        lineEdit_Staerke->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_Staerke);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Geschwindigkeit = new QLabel(groupBox);
        label_Geschwindigkeit->setObjectName(QStringLiteral("label_Geschwindigkeit"));
        sizePolicy.setHeightForWidth(label_Geschwindigkeit->sizePolicy().hasHeightForWidth());
        label_Geschwindigkeit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_Geschwindigkeit);

        lineEdit_Geschwindigkeit = new QLineEdit(groupBox);
        lineEdit_Geschwindigkeit->setObjectName(QStringLiteral("lineEdit_Geschwindigkeit"));
        sizePolicy1.setHeightForWidth(lineEdit_Geschwindigkeit->sizePolicy().hasHeightForWidth());
        lineEdit_Geschwindigkeit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_Geschwindigkeit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Lebensdauer = new QLabel(groupBox);
        label_Lebensdauer->setObjectName(QStringLiteral("label_Lebensdauer"));
        sizePolicy.setHeightForWidth(label_Lebensdauer->sizePolicy().hasHeightForWidth());
        label_Lebensdauer->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_Lebensdauer);

        lineEdit_Lebensdauer = new QLineEdit(groupBox);
        lineEdit_Lebensdauer->setObjectName(QStringLiteral("lineEdit_Lebensdauer"));
        sizePolicy1.setHeightForWidth(lineEdit_Lebensdauer->sizePolicy().hasHeightForWidth());
        lineEdit_Lebensdauer->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_Lebensdauer);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_Eigenschaften = new QLabel(groupBox);
        label_Eigenschaften->setObjectName(QStringLiteral("label_Eigenschaften"));
        sizePolicy.setHeightForWidth(label_Eigenschaften->sizePolicy().hasHeightForWidth());
        label_Eigenschaften->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_Eigenschaften);

        lineEdit_Eigenschaften = new QLineEdit(groupBox);
        lineEdit_Eigenschaften->setObjectName(QStringLiteral("lineEdit_Eigenschaften"));
        sizePolicy1.setHeightForWidth(lineEdit_Eigenschaften->sizePolicy().hasHeightForWidth());
        lineEdit_Eigenschaften->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_Eigenschaften);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_Platzieren = new QPushButton(groupBox);
        pushButton_Platzieren->setObjectName(QStringLiteral("pushButton_Platzieren"));
        sizePolicy1.setHeightForWidth(pushButton_Platzieren->sizePolicy().hasHeightForWidth());
        pushButton_Platzieren->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(pushButton_Platzieren);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_Simulationssteuerung = new QLabel(groupBox_2);
        label_Simulationssteuerung->setObjectName(QStringLiteral("label_Simulationssteuerung"));

        verticalLayout_3->addWidget(label_Simulationssteuerung);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_Start = new QPushButton(groupBox_2);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));

        horizontalLayout_2->addWidget(pushButton_Start);

        pushButton_Pause = new QPushButton(groupBox_2);
        pushButton_Pause->setObjectName(QStringLiteral("pushButton_Pause"));

        horizontalLayout_2->addWidget(pushButton_Pause);

        pushButton_Schritt = new QPushButton(groupBox_2);
        pushButton_Schritt->setObjectName(QStringLiteral("pushButton_Schritt"));

        horizontalLayout_2->addWidget(pushButton_Schritt);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
        menuBiosim = new QMenu(menuBar);
        menuBiosim->setObjectName(QStringLiteral("menuBiosim"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuBiosim->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QString());
        label_Staerke->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_Geschwindigkeit->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_Lebensdauer->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_Eigenschaften->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_Platzieren->setText(QApplication::translate("MainWindow", "PushButton", 0));
        groupBox_2->setTitle(QString());
        label_Simulationssteuerung->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_Pause->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_Schritt->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuBiosim->setTitle(QApplication::translate("MainWindow", "Biosim", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
