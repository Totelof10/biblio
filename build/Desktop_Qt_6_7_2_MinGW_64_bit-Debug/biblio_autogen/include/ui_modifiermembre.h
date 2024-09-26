/********************************************************************************
** Form generated from reading UI file 'modifiermembre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERMEMBRE_H
#define UI_MODIFIERMEMBRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_ModifierMembre
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ModifierMembre)
    {
        if (ModifierMembre->objectName().isEmpty())
            ModifierMembre->setObjectName("ModifierMembre");
        ModifierMembre->resize(400, 300);
        buttonBox = new QDialogButtonBox(ModifierMembre);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(ModifierMembre);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ModifierMembre, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ModifierMembre, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ModifierMembre);
    } // setupUi

    void retranslateUi(QDialog *ModifierMembre)
    {
        ModifierMembre->setWindowTitle(QCoreApplication::translate("ModifierMembre", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifierMembre: public Ui_ModifierMembre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERMEMBRE_H
