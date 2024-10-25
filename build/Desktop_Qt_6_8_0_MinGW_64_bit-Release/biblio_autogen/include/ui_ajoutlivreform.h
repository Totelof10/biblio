/********************************************************************************
** Form generated from reading UI file 'ajoutlivreform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTLIVREFORM_H
#define UI_AJOUTLIVREFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutLivreForm
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditTitre;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditAuteur;
    QLabel *label_4;
    QLineEdit *lineEditMaisonEdition;
    QLabel *label_5;
    QTextEdit *textEditPropriete;
    QLabel *label_6;
    QSpinBox *spinBoxQuantite;
    QLabel *label_8;
    QComboBox *comboBoxArmoire;
    QComboBox *comboBoxGenre;
    QLabel *label_9;
    QLineEdit *lineEditIdentifiant;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *AjoutLivreForm)
    {
        if (AjoutLivreForm->objectName().isEmpty())
            AjoutLivreForm->setObjectName("AjoutLivreForm");
        AjoutLivreForm->resize(426, 384);
        AjoutLivreForm->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(AjoutLivreForm);
        verticalLayout->setObjectName("verticalLayout");
        frame_2 = new QFrame(AjoutLivreForm);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        QFont font;
        font.setBold(true);
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(AjoutLivreForm);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineEditTitre = new QLineEdit(frame);
        lineEditTitre->setObjectName("lineEditTitre");
        QFont font1;
        font1.setKerning(true);
        lineEditTitre->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditTitre);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        lineEditAuteur = new QLineEdit(frame);
        lineEditAuteur->setObjectName("lineEditAuteur");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditAuteur);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        lineEditMaisonEdition = new QLineEdit(frame);
        lineEditMaisonEdition->setObjectName("lineEditMaisonEdition");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditMaisonEdition);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        textEditPropriete = new QTextEdit(frame);
        textEditPropriete->setObjectName("textEditPropriete");

        formLayout->setWidget(5, QFormLayout::FieldRole, textEditPropriete);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        spinBoxQuantite = new QSpinBox(frame);
        spinBoxQuantite->setObjectName("spinBoxQuantite");

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxQuantite);

        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        comboBoxArmoire = new QComboBox(frame);
        comboBoxArmoire->setObjectName("comboBoxArmoire");

        formLayout->setWidget(7, QFormLayout::FieldRole, comboBoxArmoire);

        comboBoxGenre = new QComboBox(frame);
        comboBoxGenre->setObjectName("comboBoxGenre");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxGenre);

        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        lineEditIdentifiant = new QLineEdit(frame);
        lineEditIdentifiant->setObjectName("lineEditIdentifiant");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditIdentifiant);


        verticalLayout->addWidget(frame);

        frame_3 = new QFrame(AjoutLivreForm);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAjouter = new QPushButton(frame_3);
        btnAjouter->setObjectName("btnAjouter");
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        btnAjouter->setFont(font2);
        btnAjouter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        horizontalLayout_2->addWidget(btnAjouter);

        btnAnnuler = new QPushButton(frame_3);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setFont(font);
        btnAnnuler->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #821131;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #C7253E;\n"
"}"));

        horizontalLayout_2->addWidget(btnAnnuler);


        verticalLayout->addWidget(frame_3);


        retranslateUi(AjoutLivreForm);

        QMetaObject::connectSlotsByName(AjoutLivreForm);
    } // setupUi

    void retranslateUi(QWidget *AjoutLivreForm)
    {
        AjoutLivreForm->setWindowTitle(QCoreApplication::translate("AjoutLivreForm", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("AjoutLivreForm", "Ajout de nouveau livre", nullptr));
        label->setText(QCoreApplication::translate("AjoutLivreForm", "Titre", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutLivreForm", "Genre", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutLivreForm", "Auteur", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutLivreForm", "Maison d'\303\251dition", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutLivreForm", "Propri\303\251t\303\251s", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutLivreForm", "Quantit\303\251", nullptr));
        label_8->setText(QCoreApplication::translate("AjoutLivreForm", "Armoire", nullptr));
        label_9->setText(QCoreApplication::translate("AjoutLivreForm", "Cote", nullptr));
        btnAjouter->setText(QCoreApplication::translate("AjoutLivreForm", "Ajouter", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("AjoutLivreForm", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutLivreForm: public Ui_AjoutLivreForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTLIVREFORM_H
