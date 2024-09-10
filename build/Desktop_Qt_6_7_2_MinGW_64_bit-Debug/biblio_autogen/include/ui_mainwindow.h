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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEditUser;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditMdp;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnConnexion;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QPushButton *btnInscription;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_8;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEditAddUser;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEditAddMdp;
    QFrame *frame_13;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEditConfirmMdp;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnInscription_2;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QPushButton *btnConnexion_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        frame_5 = new QFrame(page);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(320, 40, 251, 281));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(frame_5);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(frame_2);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEditUser = new QLineEdit(frame_2);
        lineEditUser->setObjectName("lineEditUser");

        verticalLayout->addWidget(lineEditUser);


        verticalLayout_4->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        lineEditMdp = new QLineEdit(frame_3);
        lineEditMdp->setObjectName("lineEditMdp");
        lineEditMdp->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineEditMdp);


        verticalLayout_4->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        btnConnexion = new QPushButton(frame_4);
        btnConnexion->setObjectName("btnConnexion");

        verticalLayout_3->addWidget(btnConnexion);


        verticalLayout_4->addWidget(frame_4);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(frame_6);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        btnInscription = new QPushButton(frame_6);
        btnInscription->setObjectName("btnInscription");

        horizontalLayout_3->addWidget(btnInscription);


        verticalLayout_4->addWidget(frame_6);


        horizontalLayout_2->addWidget(frame);

        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 30, 261, 291));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/Downloads/CartoBMW/img/FRK.jpg);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 30, 261, 291));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/Downloads/CartoBMW/img/FRK.jpg);"));
        frame_8 = new QFrame(page_2);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(330, 20, 231, 321));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_8);
        verticalLayout_5->setObjectName("verticalLayout_5");
        frame_9 = new QFrame(frame_8);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_9);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_5 = new QLabel(frame_9);
        label_5->setObjectName("label_5");

        verticalLayout_6->addWidget(label_5);

        lineEditAddUser = new QLineEdit(frame_9);
        lineEditAddUser->setObjectName("lineEditAddUser");

        verticalLayout_6->addWidget(lineEditAddUser);


        verticalLayout_5->addWidget(frame_9);

        frame_10 = new QFrame(frame_8);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_10);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_6 = new QLabel(frame_10);
        label_6->setObjectName("label_6");

        verticalLayout_7->addWidget(label_6);

        lineEditAddMdp = new QLineEdit(frame_10);
        lineEditAddMdp->setObjectName("lineEditAddMdp");
        lineEditAddMdp->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_7->addWidget(lineEditAddMdp);


        verticalLayout_5->addWidget(frame_10);

        frame_13 = new QFrame(frame_8);
        frame_13->setObjectName("frame_13");
        frame_13->setFrameShape(QFrame::Shape::StyledPanel);
        frame_13->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_13);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_9 = new QLabel(frame_13);
        label_9->setObjectName("label_9");

        verticalLayout_9->addWidget(label_9);

        lineEditConfirmMdp = new QLineEdit(frame_13);
        lineEditConfirmMdp->setObjectName("lineEditConfirmMdp");
        lineEditConfirmMdp->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_9->addWidget(lineEditConfirmMdp);


        verticalLayout_5->addWidget(frame_13);

        frame_11 = new QFrame(frame_8);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_11);
        verticalLayout_8->setObjectName("verticalLayout_8");
        btnInscription_2 = new QPushButton(frame_11);
        btnInscription_2->setObjectName("btnInscription_2");

        verticalLayout_8->addWidget(btnInscription_2);


        verticalLayout_5->addWidget(frame_11);

        frame_12 = new QFrame(frame_8);
        frame_12->setObjectName("frame_12");
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_12);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_7 = new QLabel(frame_12);
        label_7->setObjectName("label_7");

        horizontalLayout_5->addWidget(label_7);

        btnConnexion_2 = new QPushButton(frame_12);
        btnConnexion_2->setObjectName("btnConnexion_2");

        horizontalLayout_5->addWidget(btnConnexion_2);


        verticalLayout_5->addWidget(frame_12);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Utilisateur :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mot de passe :", nullptr));
        btnConnexion->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pas de compte?", nullptr));
        btnInscription->setText(QCoreApplication::translate("MainWindow", "Inscrivez vous!", nullptr));
        label_3->setText(QString());
        label_8->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Utilisateur :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Mot de passe :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Mot de passe :", nullptr));
        btnInscription_2->setText(QCoreApplication::translate("MainWindow", "S'inscrire", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "D\303\251ja inscrit?", nullptr));
        btnConnexion_2->setText(QCoreApplication::translate("MainWindow", "Connectez-vous", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
