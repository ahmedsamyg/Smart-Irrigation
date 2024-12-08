/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
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
    QPushButton *pbpumpmax;
    QPushButton *pbpumpmed;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QListWidget *lwData;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QListWidget *lwPump;
    QPushButton *pbpumplow;
    QGroupBox *gbSystem;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *Lip;
    QLineEdit *lEip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Lport;
    QLineEdit *lEport;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbconnect;
    QPushButton *pbdisconnect;
    QVBoxLayout *verticalLayout;
    QLabel *LMassage;
    QPushButton *pbsenddata;
    QLineEdit *lEMassage;
    QPushButton *pbexit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QListWidget *lwConsle;
    QPushButton *pushButton;
    QPushButton *pbpumpoff;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QListWidget *lwMoisture;
    QListWidget *lwRain;
    QListWidget *lwHumidity;
    QListWidget *lwTemp;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1289, 692);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 1011, 541));
        pbpumpmax = new QPushButton(centralwidget);
        pbpumpmax->setObjectName("pbpumpmax");
        pbpumpmax->setGeometry(QRect(20, 470, 83, 29));
        pbpumpmed = new QPushButton(centralwidget);
        pbpumpmed->setObjectName("pbpumpmed");
        pbpumpmed->setGeometry(QRect(20, 430, 111, 29));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(870, 10, 411, 551));
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
        pushButton_3->setGeometry(QRect(20, 510, 83, 29));
        lwPump = new QListWidget(centralwidget);
        lwPump->setObjectName("lwPump");
        lwPump->setGeometry(QRect(590, 430, 121, 31));
        pbpumplow = new QPushButton(centralwidget);
        pbpumplow->setObjectName("pbpumplow");
        pbpumplow->setGeometry(QRect(20, 390, 83, 29));
        gbSystem = new QGroupBox(centralwidget);
        gbSystem->setObjectName("gbSystem");
        gbSystem->setGeometry(QRect(0, 0, 441, 341));
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

        layoutWidget_4 = new QWidget(gbSystem);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(100, 110, 241, 221));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pbconnect = new QPushButton(layoutWidget_4);
        pbconnect->setObjectName("pbconnect");

        verticalLayout_2->addWidget(pbconnect);

        pbdisconnect = new QPushButton(layoutWidget_4);
        pbdisconnect->setObjectName("pbdisconnect");

        verticalLayout_2->addWidget(pbdisconnect);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        LMassage = new QLabel(layoutWidget_4);
        LMassage->setObjectName("LMassage");
        LMassage->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(LMassage);

        pbsenddata = new QPushButton(layoutWidget_4);
        pbsenddata->setObjectName("pbsenddata");

        verticalLayout->addWidget(pbsenddata);

        lEMassage = new QLineEdit(layoutWidget_4);
        lEMassage->setObjectName("lEMassage");

        verticalLayout->addWidget(lEMassage);

        pbexit = new QPushButton(layoutWidget_4);
        pbexit->setObjectName("pbexit");

        verticalLayout->addWidget(pbexit);


        verticalLayout_4->addLayout(verticalLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(440, 0, 261, 251));
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

        pbpumpoff = new QPushButton(centralwidget);
        pbpumpoff->setObjectName("pbpumpoff");
        pbpumpoff->setGeometry(QRect(20, 350, 83, 29));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(470, 320, 351, 91));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lwMoisture = new QListWidget(widget);
        lwMoisture->setObjectName("lwMoisture");

        gridLayout_2->addWidget(lwMoisture, 1, 1, 1, 1);

        lwRain = new QListWidget(widget);
        lwRain->setObjectName("lwRain");

        gridLayout_2->addWidget(lwRain, 1, 0, 1, 1);

        lwHumidity = new QListWidget(widget);
        lwHumidity->setObjectName("lwHumidity");

        gridLayout_2->addWidget(lwHumidity, 0, 1, 1, 1);

        lwTemp = new QListWidget(widget);
        lwTemp->setObjectName("lwTemp");

        gridLayout_2->addWidget(lwTemp, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1289, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pbpumpmax->setText(QCoreApplication::translate("MainWindow", "pump max", nullptr));
        pbpumpmed->setText(QCoreApplication::translate("MainWindow", "pump medium", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Data", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Automatic", nullptr));
        pbpumplow->setText(QCoreApplication::translate("MainWindow", "pump low", nullptr));
        gbSystem->setTitle(QCoreApplication::translate("MainWindow", "System", nullptr));
        Lip->setText(QCoreApplication::translate("MainWindow", "IP  =>", nullptr));
        lEip->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000", nullptr));
        Lport->setText(QCoreApplication::translate("MainWindow", "PORT  =>", nullptr));
        lEport->setInputMask(QString());
        pbconnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pbdisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        LMassage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Enter Massage</span></p></body></html>", nullptr));
        pbsenddata->setText(QCoreApplication::translate("MainWindow", "Send Data", nullptr));
        lEMassage->setInputMask(QString());
        pbexit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Consle", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pbpumpoff->setText(QCoreApplication::translate("MainWindow", "pump off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
