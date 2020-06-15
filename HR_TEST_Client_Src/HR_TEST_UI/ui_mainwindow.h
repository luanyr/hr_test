/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QTabWidget>
#include <QTableWidget>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_8;
    QTabWidget *tabWidget_left;
    QWidget *tab_12;
    QVBoxLayout *verticalLayout_15;
    QTableWidget *tableStatus;
    QTabWidget *tabWidget_left_2;
    QWidget *tab_13;
    QVBoxLayout *verticalLayout_16;
    QTableWidget *tableStatus_2;
    QTabWidget *tabWidget_ribbon;
    QWidget *tab_advanced;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *TcpAddrEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *TcpPortEdit;
    QToolButton *PbConnect;
    QToolButton *PbDisConnect;
    QToolButton *toolFormat;
    QToolButton *PbReset;
    QToolButton *toolUpdate;
    QToolButton *toolSelfDest;
    QToolButton *toolSelfDest_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(843, 785);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/png/Main_OS_002.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tabWidget_left = new QTabWidget(centralWidget);
        tabWidget_left->setObjectName(QString::fromUtf8("tabWidget_left"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_left->sizePolicy().hasHeightForWidth());
        tabWidget_left->setSizePolicy(sizePolicy);
        tabWidget_left->setMinimumSize(QSize(335, 0));
        tabWidget_left->setMaximumSize(QSize(335, 16777215));
        tabWidget_left->setSizeIncrement(QSize(0, 0));
        tabWidget_left->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        verticalLayout_15 = new QVBoxLayout(tab_12);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        tableStatus = new QTableWidget(tab_12);
        tableStatus->setObjectName(QString::fromUtf8("tableStatus"));
        sizePolicy.setHeightForWidth(tableStatus->sizePolicy().hasHeightForWidth());
        tableStatus->setSizePolicy(sizePolicy);
        tableStatus->setMinimumSize(QSize(320, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        tableStatus->setFont(font1);
        tableStatus->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);\n"
"font: 10pt \"\345\256\213\344\275\223\";"));

        verticalLayout_15->addWidget(tableStatus);

        tabWidget_left->addTab(tab_12, QString());

        horizontalLayout_8->addWidget(tabWidget_left);

        tabWidget_left_2 = new QTabWidget(centralWidget);
        tabWidget_left_2->setObjectName(QString::fromUtf8("tabWidget_left_2"));
        sizePolicy.setHeightForWidth(tabWidget_left_2->sizePolicy().hasHeightForWidth());
        tabWidget_left_2->setSizePolicy(sizePolicy);
        tabWidget_left_2->setMinimumSize(QSize(335, 0));
        tabWidget_left_2->setMaximumSize(QSize(335, 16777215));
        tabWidget_left_2->setSizeIncrement(QSize(0, 0));
        tabWidget_left_2->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));
        tab_13 = new QWidget();
        tab_13->setObjectName(QString::fromUtf8("tab_13"));
        verticalLayout_16 = new QVBoxLayout(tab_13);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        tableStatus_2 = new QTableWidget(tab_13);
        tableStatus_2->setObjectName(QString::fromUtf8("tableStatus_2"));
        sizePolicy.setHeightForWidth(tableStatus_2->sizePolicy().hasHeightForWidth());
        tableStatus_2->setSizePolicy(sizePolicy);
        tableStatus_2->setMinimumSize(QSize(320, 0));
        tableStatus_2->setFont(font1);
        tableStatus_2->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);\n"
"font: 10pt \"\345\256\213\344\275\223\";"));

        verticalLayout_16->addWidget(tableStatus_2);

        tabWidget_left_2->addTab(tab_13, QString());

        horizontalLayout_8->addWidget(tabWidget_left_2);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        tabWidget_ribbon = new QTabWidget(centralWidget);
        tabWidget_ribbon->setObjectName(QString::fromUtf8("tabWidget_ribbon"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_ribbon->sizePolicy().hasHeightForWidth());
        tabWidget_ribbon->setSizePolicy(sizePolicy1);
        tabWidget_ribbon->setMinimumSize(QSize(0, 150));
        QPalette palette;
        QBrush brush(QColor(221, 221, 221, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(148, 55, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush3(QColor(103, 246, 206, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(112, 112, 112, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush4);
        tabWidget_ribbon->setPalette(palette);
        tabWidget_ribbon->setFont(font);
        tabWidget_ribbon->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget_ribbon->setAutoFillBackground(false);
        tabWidget_ribbon->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));
        tabWidget_ribbon->setTabShape(QTabWidget::Rounded);
        tabWidget_ribbon->setElideMode(Qt::ElideNone);
        tabWidget_ribbon->setUsesScrollButtons(false);
        tabWidget_ribbon->setDocumentMode(false);
        tab_advanced = new QWidget();
        tab_advanced->setObjectName(QString::fromUtf8("tab_advanced"));
        widget = new QWidget(tab_advanced);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 781, 101));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(60, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label);

        TcpAddrEdit = new QLineEdit(widget);
        TcpAddrEdit->setObjectName(QString::fromUtf8("TcpAddrEdit"));
        TcpAddrEdit->setMinimumSize(QSize(140, 0));
        TcpAddrEdit->setMaximumSize(QSize(140, 16777215));
        TcpAddrEdit->setFont(font2);
        TcpAddrEdit->setLayoutDirection(Qt::RightToLeft);
        TcpAddrEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        TcpAddrEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(TcpAddrEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setFont(font2);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(label_2);

        TcpPortEdit = new QLineEdit(widget);
        TcpPortEdit->setObjectName(QString::fromUtf8("TcpPortEdit"));
        TcpPortEdit->setMaximumSize(QSize(140, 16777215));
        TcpPortEdit->setFont(font2);
        TcpPortEdit->setLayoutDirection(Qt::RightToLeft);
        TcpPortEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        TcpPortEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(TcpPortEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        PbConnect = new QToolButton(widget);
        PbConnect->setObjectName(QString::fromUtf8("PbConnect"));
        PbConnect->setMinimumSize(QSize(64, 64));
        PbConnect->setFont(font);
        PbConnect->setCursor(QCursor(Qt::PointingHandCursor));
        PbConnect->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/png/connected-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        PbConnect->setIcon(icon1);
        PbConnect->setIconSize(QSize(40, 40));
        PbConnect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        PbConnect->setAutoRaise(true);

        horizontalLayout->addWidget(PbConnect);

        PbDisConnect = new QToolButton(widget);
        PbDisConnect->setObjectName(QString::fromUtf8("PbDisConnect"));
        PbDisConnect->setMinimumSize(QSize(64, 64));
        PbDisConnect->setFont(font);
        PbDisConnect->setCursor(QCursor(Qt::PointingHandCursor));
        PbDisConnect->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/png/disconnected-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        PbDisConnect->setIcon(icon2);
        PbDisConnect->setIconSize(QSize(40, 40));
        PbDisConnect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        PbDisConnect->setAutoRaise(true);

        horizontalLayout->addWidget(PbDisConnect);

        toolFormat = new QToolButton(widget);
        toolFormat->setObjectName(QString::fromUtf8("toolFormat"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolFormat->sizePolicy().hasHeightForWidth());
        toolFormat->setSizePolicy(sizePolicy2);
        toolFormat->setFont(font);
        toolFormat->setCursor(QCursor(Qt::PointingHandCursor));
        toolFormat->setLayoutDirection(Qt::LeftToRight);
        toolFormat->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/png/sinchronize-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolFormat->setIcon(icon3);
        toolFormat->setIconSize(QSize(40, 40));
        toolFormat->setAutoRepeat(false);
        toolFormat->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolFormat->setAutoRaise(true);

        horizontalLayout->addWidget(toolFormat);

        PbReset = new QToolButton(widget);
        PbReset->setObjectName(QString::fromUtf8("PbReset"));
        PbReset->setMinimumSize(QSize(64, 64));
        PbReset->setFont(font);
        PbReset->setCursor(QCursor(Qt::PointingHandCursor));
        PbReset->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/png/cloud_storage-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        PbReset->setIcon(icon4);
        PbReset->setIconSize(QSize(40, 40));
        PbReset->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        PbReset->setAutoRaise(true);

        horizontalLayout->addWidget(PbReset);

        toolUpdate = new QToolButton(widget);
        toolUpdate->setObjectName(QString::fromUtf8("toolUpdate"));
        sizePolicy2.setHeightForWidth(toolUpdate->sizePolicy().hasHeightForWidth());
        toolUpdate->setSizePolicy(sizePolicy2);
        toolUpdate->setFont(font2);
        toolUpdate->setCursor(QCursor(Qt::PointingHandCursor));
        toolUpdate->setLayoutDirection(Qt::LeftToRight);
        toolUpdate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/png/png/airplane_landing-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolUpdate->setIcon(icon5);
        toolUpdate->setIconSize(QSize(40, 40));
        toolUpdate->setAutoRepeat(false);
        toolUpdate->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolUpdate->setAutoRaise(true);

        horizontalLayout->addWidget(toolUpdate);

        toolSelfDest = new QToolButton(widget);
        toolSelfDest->setObjectName(QString::fromUtf8("toolSelfDest"));
        sizePolicy2.setHeightForWidth(toolSelfDest->sizePolicy().hasHeightForWidth());
        toolSelfDest->setSizePolicy(sizePolicy2);
        toolSelfDest->setFont(font2);
        toolSelfDest->setCursor(QCursor(Qt::PointingHandCursor));
        toolSelfDest->setLayoutDirection(Qt::LeftToRight);
        toolSelfDest->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/png/burn.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolSelfDest->setIcon(icon6);
        toolSelfDest->setIconSize(QSize(40, 40));
        toolSelfDest->setAutoRepeat(false);
        toolSelfDest->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolSelfDest->setAutoRaise(true);

        horizontalLayout->addWidget(toolSelfDest);

        toolSelfDest_2 = new QToolButton(widget);
        toolSelfDest_2->setObjectName(QString::fromUtf8("toolSelfDest_2"));
        sizePolicy2.setHeightForWidth(toolSelfDest_2->sizePolicy().hasHeightForWidth());
        toolSelfDest_2->setSizePolicy(sizePolicy2);
        toolSelfDest_2->setFont(font2);
        toolSelfDest_2->setCursor(QCursor(Qt::PointingHandCursor));
        toolSelfDest_2->setLayoutDirection(Qt::LeftToRight);
        toolSelfDest_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/png/play-128.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolSelfDest_2->setIcon(icon7);
        toolSelfDest_2->setIconSize(QSize(40, 40));
        toolSelfDest_2->setAutoRepeat(false);
        toolSelfDest_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolSelfDest_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolSelfDest_2);

        tabWidget_ribbon->addTab(tab_advanced, QString());

        gridLayout->addWidget(tabWidget_ribbon, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 843, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_left->setCurrentIndex(0);
        tabWidget_left_2->setCurrentIndex(0);
        tabWidget_ribbon->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HR\346\274\224\347\244\272\347\263\273\347\273\237\346\216\247\345\210\266\350\275\257\344\273\266", 0));
        tabWidget_left->setTabText(tabWidget_left->indexOf(tab_12), QApplication::translate("MainWindow", "\346\265\213\350\257\225\347\273\223\346\236\234", 0));
        tabWidget_left_2->setTabText(tabWidget_left_2->indexOf(tab_13), QApplication::translate("MainWindow", "\346\227\245\345\277\227\347\252\227\345\217\243", 0));
        label->setText(QApplication::translate("MainWindow", "IP\345\234\260\345\235\200\357\274\232", 0));
        TcpAddrEdit->setInputMask(QString());
        TcpAddrEdit->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\347\253\257    \345\217\243\357\274\232", 0));
        TcpPortEdit->setInputMask(QString());
        TcpPortEdit->setText(QString());
        PbConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        PbDisConnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200", 0));
        toolFormat->setText(QApplication::translate("MainWindow", "FFT \346\265\213\350\257\225", 0));
        PbReset->setText(QApplication::translate("MainWindow", "CDMA \346\265\213\350\257\225", 0));
        toolUpdate->setText(QApplication::translate("MainWindow", "SRIO \346\265\213\350\257\225", 0));
        toolSelfDest->setText(QApplication::translate("MainWindow", "\345\237\272\347\241\200\346\265\213\350\257\225", 0));
        toolSelfDest_2->setText(QApplication::translate("MainWindow", "ALL \346\265\213\350\257\225", 0));
        tabWidget_ribbon->setTabText(tabWidget_ribbon->indexOf(tab_advanced), QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
