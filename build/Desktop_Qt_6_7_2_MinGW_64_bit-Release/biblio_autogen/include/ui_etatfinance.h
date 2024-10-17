/********************************************************************************
** Form generated from reading UI file 'etatfinance.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETATFINANCE_H
#define UI_ETATFINANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EtatFinance
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QDateEdit *dateEdit_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *labelTotal;
    QWidget *page_2;

    void setupUi(QWidget *EtatFinance)
    {
        if (EtatFinance->objectName().isEmpty())
            EtatFinance->setObjectName("EtatFinance");
        EtatFinance->resize(400, 300);
        EtatFinance->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 48, 63);"));
        verticalLayout = new QVBoxLayout(EtatFinance);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(EtatFinance);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        QFont font;
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid black;\n"
"}"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addWidget(frame);

        frame_3 = new QFrame(page);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label);

        dateEdit = new QDateEdit(frame_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(dateEdit);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit_2 = new QDateEdit(frame_3);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(dateEdit_2);


        verticalLayout_2->addWidget(frame_3);

        frame_2 = new QFrame(page);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(frame_2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(tableWidget);


        verticalLayout_2->addWidget(frame_2);

        frame_4 = new QFrame(page);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_4);

        labelTotal = new QLabel(frame_4);
        labelTotal->setObjectName("labelTotal");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        labelTotal->setFont(font1);
        labelTotal->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(labelTotal);


        verticalLayout_2->addWidget(frame_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(EtatFinance);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EtatFinance);
    } // setupUi

    void retranslateUi(QWidget *EtatFinance)
    {
        EtatFinance->setWindowTitle(QCoreApplication::translate("EtatFinance", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("EtatFinance", "RECETTE DES ABONNEMENTS", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("EtatFinance", "Recherche", nullptr));
        label->setText(QCoreApplication::translate("EtatFinance", "Du :", nullptr));
        label_2->setText(QCoreApplication::translate("EtatFinance", "Jusq'au :", nullptr));
        label_4->setText(QCoreApplication::translate("EtatFinance", "Total :", nullptr));
        labelTotal->setText(QCoreApplication::translate("EtatFinance", "1000000 AR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EtatFinance: public Ui_EtatFinance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETATFINANCE_H
