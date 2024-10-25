/********************************************************************************
** Form generated from reading UI file 'parametre.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRE_H
#define UI_PARAMETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parametre
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *reinitialisation;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEditArmoire;
    QLabel *label_3;
    QLineEdit *lineEditGenre;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnEnregistrerParametre;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QFrame *frame_4;
    QFormLayout *formLayout_2;
    QLabel *labelAdulte;
    QLineEdit *lineEditAdulte;
    QLabel *labelEnfant;
    QLineEdit *lineEditEnfant;
    QPushButton *btnMontants;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *textBrowser;
    QPushButton *btnAnnulerParametre;

    void setupUi(QWidget *Parametre)
    {
        if (Parametre->objectName().isEmpty())
            Parametre->setObjectName("Parametre");
        Parametre->resize(400, 300);
        verticalLayout = new QVBoxLayout(Parametre);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(Parametre);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Triangular);
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(frame);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(133, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(frame);

        reinitialisation = new QPushButton(tab);
        reinitialisation->setObjectName("reinitialisation");

        verticalLayout_2->addWidget(reinitialisation);

        frame_2 = new QFrame(tab);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEditArmoire = new QLineEdit(frame_2);
        lineEditArmoire->setObjectName("lineEditArmoire");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditArmoire);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEditGenre = new QLineEdit(frame_2);
        lineEditGenre->setObjectName("lineEditGenre");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditGenre);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnEnregistrerParametre = new QPushButton(frame_3);
        btnEnregistrerParametre->setObjectName("btnEnregistrerParametre");
        QFont font1;
        font1.setBold(true);
        btnEnregistrerParametre->setFont(font1);
        btnEnregistrerParametre->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        horizontalLayout_2->addWidget(btnEnregistrerParametre);


        formLayout->setWidget(2, QFormLayout::FieldRole, frame_3);


        verticalLayout_2->addWidget(frame_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(tab_2);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_5);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_4);


        verticalLayout_3->addWidget(frame_5);

        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        formLayout_2 = new QFormLayout(frame_4);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setHorizontalSpacing(0);
        formLayout_2->setVerticalSpacing(9);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        labelAdulte = new QLabel(frame_4);
        labelAdulte->setObjectName("labelAdulte");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelAdulte);

        lineEditAdulte = new QLineEdit(frame_4);
        lineEditAdulte->setObjectName("lineEditAdulte");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditAdulte);

        labelEnfant = new QLabel(frame_4);
        labelEnfant->setObjectName("labelEnfant");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelEnfant);

        lineEditEnfant = new QLineEdit(frame_4);
        lineEditEnfant->setObjectName("lineEditEnfant");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditEnfant);

        btnMontants = new QPushButton(frame_4);
        btnMontants->setObjectName("btnMontants");
        btnMontants->setFont(font1);
        btnMontants->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnMontants->setMouseTracking(true);
        btnMontants->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, btnMontants);


        verticalLayout_3->addWidget(frame_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        textBrowser = new QTextBrowser(tab_3);
        textBrowser->setObjectName("textBrowser");

        verticalLayout_5->addWidget(textBrowser);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        btnAnnulerParametre = new QPushButton(Parametre);
        btnAnnulerParametre->setObjectName("btnAnnulerParametre");
        btnAnnulerParametre->setFont(font1);
        btnAnnulerParametre->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #821131;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #C7253E;\n"
"}"));

        verticalLayout->addWidget(btnAnnulerParametre);


        retranslateUi(Parametre);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Parametre);
    } // setupUi

    void retranslateUi(QWidget *Parametre)
    {
        Parametre->setWindowTitle(QCoreApplication::translate("Parametre", "Parametre", nullptr));
        label->setText(QCoreApplication::translate("Parametre", "Param\303\250tre", nullptr));
        reinitialisation->setText(QCoreApplication::translate("Parametre", "Reinitialiser les donn\303\251es", nullptr));
        label_2->setText(QCoreApplication::translate("Parametre", "Armoire :", nullptr));
        label_3->setText(QCoreApplication::translate("Parametre", "Genre :", nullptr));
        btnEnregistrerParametre->setText(QCoreApplication::translate("Parametre", "Enregistrer les modifications", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Parametre", "Param\303\250tre g\303\251n\303\251ral", nullptr));
        label_4->setText(QCoreApplication::translate("Parametre", "MODIFICATION POUR UN NOUVEAU MONTANT D'ABONNEMENT", nullptr));
        labelAdulte->setText(QCoreApplication::translate("Parametre", "Adulte :", nullptr));
        labelEnfant->setText(QCoreApplication::translate("Parametre", "Enfant :", nullptr));
        btnMontants->setText(QCoreApplication::translate("Parametre", "Enregistrer les nouveaux abonnements", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Parametre", "Ajustement", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Parametre", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700; color:#ff0000;\">Copyright \302\251</span> Rakotonirina Tohaina Manoa 2024.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Tous droits r\303\251serv\303\251s.</span><br />Ce logiciel est une application de gestion de biblioth\303\250que, d\303\251velopp\303"
                        "\251e pour faciliter la gestion des livres, des membres et des emprunts de &quot;Tranom-boky Andriniony&quot; FJKM Ambohitantely. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Aucune partie de ce logiciel ne peut \303\252tre reproduite, distribu\303\251e ou utilis\303\251e sous une forme quelconque sans l'autorisation \303\251crite pr\303\251alable de Rakotonirina Tohaina Manoa.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pour toute demande d'autorisation ou d'informations suppl\303\251mentaires ou pour une collaboration, veuillez contacter rtohainamanoa@gmail.com ou +261345568127.</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Parametre", "Mention l\303\251gale", nullptr));
        btnAnnulerParametre->setText(QCoreApplication::translate("Parametre", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parametre: public Ui_Parametre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRE_H
