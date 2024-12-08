/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QListWidget *lwData;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *gbSystem;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *Lip;
    QLineEdit *lEip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Lport;
    QLineEdit *lEport;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbconnect;
    QPushButton *pbdisconnect;
    QPushButton *pbexit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QListWidget *lwConsle;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *pbpumpoff;
    QPushButton *pbpumplow;
    QPushButton *pbpumpmed;
    QPushButton *pbpumpmax;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QListWidget *lwPump;
    QListWidget *lwTemp;
    QListWidget *lwRain;
    QListWidget *lwMoisture;
    QListWidget *lwHumidity;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1223, 621);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 1011, 541));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(780, 0, 401, 551));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 30, 391, 501));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        lwData = new QListWidget(layoutWidget_2);
        lwData->setObjectName("lwData");
        lwData->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        lwData->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        lwData->setWordWrap(true);

        verticalLayout_6->addWidget(lwData);

        pushButton_2 = new QPushButton(layoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_6->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 250, 301, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"background-color: rgb(25, 191, 200);\n"
"font: 700 18pt \"Segoe UI\";"));
        gbSystem = new QGroupBox(centralwidget);
        gbSystem->setObjectName("gbSystem");
        gbSystem->setGeometry(QRect(0, 0, 451, 241));
        layoutWidget_3 = new QWidget(gbSystem);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(10, 30, 411, 69));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Lip = new QLabel(layoutWidget_3);
        Lip->setObjectName("Lip");
        Lip->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(Lip);

        lEip = new QLineEdit(layoutWidget_3);
        lEip->setObjectName("lEip");

        horizontalLayout->addWidget(lEip);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Lport = new QLabel(layoutWidget_3);
        Lport->setObjectName("Lport");
        Lport->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(Lport);

        lEport = new QLineEdit(layoutWidget_3);
        lEport->setObjectName("lEport");

        horizontalLayout_2->addWidget(lEport);


        verticalLayout_3->addLayout(horizontalLayout_2);

        layoutWidget = new QWidget(gbSystem);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 120, 239, 103));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pbconnect = new QPushButton(layoutWidget);
        pbconnect->setObjectName("pbconnect");

        verticalLayout_2->addWidget(pbconnect);

        pbdisconnect = new QPushButton(layoutWidget);
        pbdisconnect->setObjectName("pbdisconnect");

        verticalLayout_2->addWidget(pbdisconnect);

        pbexit = new QPushButton(layoutWidget);
        pbexit->setObjectName("pbexit");

        verticalLayout_2->addWidget(pbexit);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(490, 20, 261, 251));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lwConsle = new QListWidget(groupBox);
        lwConsle->setObjectName("lwConsle");
        lwConsle->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        lwConsle->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        lwConsle->setWordWrap(true);

        verticalLayout_5->addWidget(lwConsle);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        verticalLayout_5->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(30, 340, 291, 131));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        pbpumpoff = new QPushButton(groupBox_3);
        pbpumpoff->setObjectName("pbpumpoff");

        gridLayout_3->addWidget(pbpumpoff, 0, 0, 1, 1);

        pbpumplow = new QPushButton(groupBox_3);
        pbpumplow->setObjectName("pbpumplow");

        gridLayout_3->addWidget(pbpumplow, 0, 1, 1, 1);

        pbpumpmed = new QPushButton(groupBox_3);
        pbpumpmed->setObjectName("pbpumpmed");

        gridLayout_3->addWidget(pbpumpmed, 1, 0, 1, 1);

        pbpumpmax = new QPushButton(groupBox_3);
        pbpumpmax->setObjectName("pbpumpmax");

        gridLayout_3->addWidget(pbpumpmax, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(370, 280, 391, 291));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 20, 391, 191));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lwPump = new QListWidget(layoutWidget1);
        lwPump->setObjectName("lwPump");

        gridLayout_2->addWidget(lwPump, 2, 0, 1, 2);

        lwTemp = new QListWidget(layoutWidget1);
        lwTemp->setObjectName("lwTemp");

        gridLayout_2->addWidget(lwTemp, 0, 0, 1, 1);

        lwRain = new QListWidget(layoutWidget1);
        lwRain->setObjectName("lwRain");

        gridLayout_2->addWidget(lwRain, 1, 0, 1, 1);

        lwMoisture = new QListWidget(layoutWidget1);
        lwMoisture->setObjectName("lwMoisture");

        gridLayout_2->addWidget(lwMoisture, 1, 1, 1, 1);

        lwHumidity = new QListWidget(layoutWidget1);
        lwHumidity->setObjectName("lwHumidity");

        gridLayout_2->addWidget(lwHumidity, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1223, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, &QPushButton::clicked, lwConsle, qOverload<>(&QListWidget::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, lwData, qOverload<>(&QListWidget::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Data Log", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Automatic Control", nullptr));
        gbSystem->setTitle(QCoreApplication::translate("MainWindow", "Client", nullptr));
        Lip->setText(QCoreApplication::translate("MainWindow", "IP  =>", nullptr));
        lEip->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000", nullptr));
        Lport->setText(QCoreApplication::translate("MainWindow", "PORT  =>", nullptr));
        lEport->setInputMask(QString());
        pbconnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pbdisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pbexit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Consle", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Manual Control", nullptr));
        pbpumpoff->setText(QCoreApplication::translate("MainWindow", "pump off", nullptr));
        pbpumplow->setText(QCoreApplication::translate("MainWindow", "pump low", nullptr));
        pbpumpmed->setText(QCoreApplication::translate("MainWindow", "pump medium", nullptr));
        pbpumpmax->setText(QCoreApplication::translate("MainWindow", "pump max", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Readings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
