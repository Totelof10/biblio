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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnClearForm;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *labelTotal;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGraph;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QPushButton *btnRetour;
    QVBoxLayout *verticalLayout_5;

    void setupUi(QWidget *EtatFinance)
    {
        if (EtatFinance->objectName().isEmpty())
            EtatFinance->setObjectName("EtatFinance");
        EtatFinance->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/CartoBMW/img/FRK.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        EtatFinance->setWindowIcon(icon);
        EtatFinance->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(215, 243, 255);\n"
"}\n"
""));
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
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
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
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
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
        label->setStyleSheet(QString::fromUtf8("color: rgb(31, 49, 64);"));

        horizontalLayout_2->addWidget(label);

        dateEdit = new QDateEdit(frame_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(dateEdit);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 48, 63);"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit_2 = new QDateEdit(frame_3);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(dateEdit_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnClearForm = new QPushButton(frame_3);
        btnClearForm->setObjectName("btnClearForm");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::SystemReboot));
        btnClearForm->setIcon(icon1);

        horizontalLayout_2->addWidget(btnClearForm);


        verticalLayout_2->addWidget(frame_3);

        frame_2 = new QFrame(page);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(frame_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

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
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(31, 50, 64);"));

        horizontalLayout_3->addWidget(label_4);

        labelTotal = new QLabel(frame_4);
        labelTotal->setObjectName("labelTotal");
        labelTotal->setFont(font1);
        labelTotal->setStyleSheet(QString::fromUtf8("color: rgb(31, 49, 63);"));

        horizontalLayout_3->addWidget(labelTotal);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(frame_4);

        frame_5 = new QFrame(page);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnGraph = new QPushButton(frame_5);
        btnGraph->setObjectName("btnGraph");
        btnGraph->setFont(font);
        btnGraph->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #102C57;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #1679AB;\n"
"}"));

        horizontalLayout_4->addWidget(btnGraph);


        verticalLayout_2->addWidget(frame_5);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        btnRetour = new QPushButton(page_2);
        btnRetour->setObjectName("btnRetour");
        btnRetour->setFont(font1);
        btnRetour->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #102C57;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #1679AB;\n"
"}"));

        verticalLayout_4->addWidget(btnRetour);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");

        verticalLayout_4->addLayout(verticalLayout_5);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(EtatFinance);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EtatFinance);
    } // setupUi

    void retranslateUi(QWidget *EtatFinance)
    {
        EtatFinance->setWindowTitle(QCoreApplication::translate("EtatFinance", "Etat Finance", nullptr));
        label_3->setText(QCoreApplication::translate("EtatFinance", "RECETTE DES ABONNEMENTS", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("EtatFinance", "Recherche", nullptr));
        label->setText(QCoreApplication::translate("EtatFinance", "Du :", nullptr));
        label_2->setText(QCoreApplication::translate("EtatFinance", "Jusq'au :", nullptr));
        btnClearForm->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EtatFinance", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EtatFinance", "Membres", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EtatFinance", "Montants", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EtatFinance", "Date de paiment", nullptr));
        label_4->setText(QCoreApplication::translate("EtatFinance", "Total :", nullptr));
        labelTotal->setText(QString());
        btnGraph->setText(QCoreApplication::translate("EtatFinance", "Afficher un graphique", nullptr));
        label_5->setText(QCoreApplication::translate("EtatFinance", "DIAGRAMME DES ABONNEMENTS", nullptr));
        btnRetour->setText(QCoreApplication::translate("EtatFinance", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EtatFinance: public Ui_EtatFinance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETATFINANCE_H
