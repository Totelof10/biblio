/********************************************************************************
** Form generated from reading UI file 'parametre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parametre
{
public:
    QVBoxLayout *verticalLayout;
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
    QPushButton *btnAnnulerParametre;

    void setupUi(QWidget *Parametre)
    {
        if (Parametre->objectName().isEmpty())
            Parametre->setObjectName("Parametre");
        Parametre->resize(400, 300);
        verticalLayout = new QVBoxLayout(Parametre);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(Parametre);
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


        verticalLayout->addWidget(frame);

        reinitialisation = new QPushButton(Parametre);
        reinitialisation->setObjectName("reinitialisation");

        verticalLayout->addWidget(reinitialisation);

        frame_2 = new QFrame(Parametre);
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


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(Parametre);
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

        btnAnnulerParametre = new QPushButton(frame_3);
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

        horizontalLayout_2->addWidget(btnAnnulerParametre);


        verticalLayout->addWidget(frame_3);


        retranslateUi(Parametre);

        QMetaObject::connectSlotsByName(Parametre);
    } // setupUi

    void retranslateUi(QWidget *Parametre)
    {
        Parametre->setWindowTitle(QCoreApplication::translate("Parametre", "Form", nullptr));
        label->setText(QCoreApplication::translate("Parametre", "Parametre", nullptr));
        reinitialisation->setText(QCoreApplication::translate("Parametre", "Reinitialiser les donn\303\251es", nullptr));
        label_2->setText(QCoreApplication::translate("Parametre", "Armoire :", nullptr));
        label_3->setText(QCoreApplication::translate("Parametre", "Genre :", nullptr));
        btnEnregistrerParametre->setText(QCoreApplication::translate("Parametre", "Enregistrer les modifications", nullptr));
        btnAnnulerParametre->setText(QCoreApplication::translate("Parametre", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parametre: public Ui_Parametre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRE_H
