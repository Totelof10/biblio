/********************************************************************************
** Form generated from reading UI file 'deconnexion.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECONNEXION_H
#define UI_DECONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deconnexion
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOui;
    QPushButton *btnNon;

    void setupUi(QWidget *Deconnexion)
    {
        if (Deconnexion->objectName().isEmpty())
            Deconnexion->setObjectName("Deconnexion");
        Deconnexion->resize(217, 96);
        verticalLayout = new QVBoxLayout(Deconnexion);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 9, 0, 0);
        frame_2 = new QFrame(Deconnexion);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(frame_2);
        label->setObjectName("label");
        QFont font;
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(Deconnexion);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(217, 43));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnOui = new QPushButton(frame);
        btnOui->setObjectName("btnOui");
        btnOui->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnOui->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        horizontalLayout->addWidget(btnOui);

        btnNon = new QPushButton(frame);
        btnNon->setObjectName("btnNon");
        btnNon->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnNon->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #821131;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #C7253E;\n"
"}"));

        horizontalLayout->addWidget(btnNon);


        verticalLayout->addWidget(frame);


        retranslateUi(Deconnexion);

        QMetaObject::connectSlotsByName(Deconnexion);
    } // setupUi

    void retranslateUi(QWidget *Deconnexion)
    {
        Deconnexion->setWindowTitle(QCoreApplication::translate("Deconnexion", "Form", nullptr));
        label->setText(QCoreApplication::translate("Deconnexion", "Voulez-vous vous d\303\251connecter?", nullptr));
        btnOui->setText(QCoreApplication::translate("Deconnexion", "OUI", nullptr));
        btnNon->setText(QCoreApplication::translate("Deconnexion", "NON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deconnexion: public Ui_Deconnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECONNEXION_H
