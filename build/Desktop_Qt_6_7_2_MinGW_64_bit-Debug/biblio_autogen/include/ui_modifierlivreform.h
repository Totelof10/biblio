/********************************************************************************
** Form generated from reading UI file 'modifierlivreform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERLIVREFORM_H
#define UI_MODIFIERLIVREFORM_H

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

class Ui_ModifierLivreForm
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *lineEditTitre;
    QLabel *label_2;
    QLineEdit *lineEditGenre;
    QLabel *label_4;
    QLineEdit *lineEditAuteur;
    QLabel *label_5;
    QLineEdit *lineEditMaisonEdition;
    QLabel *label_7;
    QSpinBox *spinBoxQuantite;
    QComboBox *comboBoxArmoire;
    QTextEdit *textEditPropriete;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEnregistrer;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *ModifierLivreForm)
    {
        if (ModifierLivreForm->objectName().isEmpty())
            ModifierLivreForm->setObjectName("ModifierLivreForm");
        ModifierLivreForm->resize(426, 403);
        verticalLayout = new QVBoxLayout(ModifierLivreForm);
        verticalLayout->setObjectName("verticalLayout");
        frame_2 = new QFrame(ModifierLivreForm);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(ModifierLivreForm);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        formLayout->setWidget(7, QFormLayout::LabelRole, label);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditTitre = new QLineEdit(frame);
        lineEditTitre->setObjectName("lineEditTitre");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditTitre);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditGenre = new QLineEdit(frame);
        lineEditGenre->setObjectName("lineEditGenre");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditGenre);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEditAuteur = new QLineEdit(frame);
        lineEditAuteur->setObjectName("lineEditAuteur");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditAuteur);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEditMaisonEdition = new QLineEdit(frame);
        lineEditMaisonEdition->setObjectName("lineEditMaisonEdition");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditMaisonEdition);

        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        spinBoxQuantite = new QSpinBox(frame);
        spinBoxQuantite->setObjectName("spinBoxQuantite");

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxQuantite);

        comboBoxArmoire = new QComboBox(frame);
        comboBoxArmoire->addItem(QString());
        comboBoxArmoire->addItem(QString());
        comboBoxArmoire->addItem(QString());
        comboBoxArmoire->addItem(QString());
        comboBoxArmoire->setObjectName("comboBoxArmoire");

        formLayout->setWidget(8, QFormLayout::FieldRole, comboBoxArmoire);

        textEditPropriete = new QTextEdit(frame);
        textEditPropriete->setObjectName("textEditPropriete");

        formLayout->setWidget(4, QFormLayout::FieldRole, textEditPropriete);


        verticalLayout->addWidget(frame);

        frame_3 = new QFrame(ModifierLivreForm);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnEnregistrer = new QPushButton(frame_3);
        btnEnregistrer->setObjectName("btnEnregistrer");
        QFont font;
        font.setBold(true);
        btnEnregistrer->setFont(font);
        btnEnregistrer->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        horizontalLayout->addWidget(btnEnregistrer);

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

        horizontalLayout->addWidget(btnAnnuler);


        verticalLayout->addWidget(frame_3);


        retranslateUi(ModifierLivreForm);

        QMetaObject::connectSlotsByName(ModifierLivreForm);
    } // setupUi

    void retranslateUi(QWidget *ModifierLivreForm)
    {
        ModifierLivreForm->setWindowTitle(QCoreApplication::translate("ModifierLivreForm", "Form", nullptr));
        label_8->setText(QCoreApplication::translate("ModifierLivreForm", "Modification des inforamtions du livre", nullptr));
        label->setText(QCoreApplication::translate("ModifierLivreForm", "Quantit\303\251", nullptr));
        label_6->setText(QCoreApplication::translate("ModifierLivreForm", "Armoire", nullptr));
        label_3->setText(QCoreApplication::translate("ModifierLivreForm", "Titre", nullptr));
        label_2->setText(QCoreApplication::translate("ModifierLivreForm", "Genre", nullptr));
        label_4->setText(QCoreApplication::translate("ModifierLivreForm", "Auteur", nullptr));
        label_5->setText(QCoreApplication::translate("ModifierLivreForm", "Maison d'\303\251dition", nullptr));
        label_7->setText(QCoreApplication::translate("ModifierLivreForm", "Propri\303\251t\303\251s", nullptr));
        comboBoxArmoire->setItemText(0, QCoreApplication::translate("ModifierLivreForm", "A", nullptr));
        comboBoxArmoire->setItemText(1, QCoreApplication::translate("ModifierLivreForm", "B", nullptr));
        comboBoxArmoire->setItemText(2, QCoreApplication::translate("ModifierLivreForm", "C", nullptr));
        comboBoxArmoire->setItemText(3, QCoreApplication::translate("ModifierLivreForm", "D", nullptr));

        btnEnregistrer->setText(QCoreApplication::translate("ModifierLivreForm", "Enregistrer", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("ModifierLivreForm", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifierLivreForm: public Ui_ModifierLivreForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERLIVREFORM_H
