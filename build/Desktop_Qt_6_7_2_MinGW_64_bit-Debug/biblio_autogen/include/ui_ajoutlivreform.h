/********************************************************************************
** Form generated from reading UI file 'ajoutlivreform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTLIVREFORM_H
#define UI_AJOUTLIVREFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QTextEdit *textEdit;
    QLabel *label_6;
    QSpinBox *spinBox;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *AjoutLivreForm)
    {
        if (AjoutLivreForm->objectName().isEmpty())
            AjoutLivreForm->setObjectName("AjoutLivreForm");
        AjoutLivreForm->resize(426, 355);
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

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName("spinBox");

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox);


        verticalLayout->addWidget(frame);

        frame_3 = new QFrame(AjoutLivreForm);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnAjouter = new QPushButton(frame_3);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout_2->addWidget(btnAjouter);

        btnAnnuler = new QPushButton(frame_3);
        btnAnnuler->setObjectName("btnAnnuler");

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
        btnAjouter->setText(QCoreApplication::translate("AjoutLivreForm", "Ajouter", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("AjoutLivreForm", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutLivreForm: public Ui_AjoutLivreForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTLIVREFORM_H
