/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_App
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAccueil;
    QPushButton *btnLivre;
    QPushButton *btnMembre;
    QPushButton *btnEmprunt;
    QStackedWidget *stackedWidget;
    QWidget *pageAccueil;
    QWidget *pageLivre;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAjouterLivre;
    QPushButton *btnModifierLivre;
    QPushButton *btnSupprimerLivre;
    QSpacerItem *horizontalSpacer;
    QWidget *pageMembre;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnMembreEtudiant;
    QPushButton *btnMembreAdulte;
    QStackedWidget *stackedWidget_2;
    QWidget *pageEtudiant;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnAjouterEtudiant;
    QPushButton *btnModifierEtudiant;
    QPushButton *btnSupprimerEtudiant;
    QSpacerItem *horizontalSpacer_3;
    QWidget *pageAdulte;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_3;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnAjouterAdulte;
    QPushButton *btnModifierAdulte;
    QPushButton *btnSupprimerAdulte;
    QSpacerItem *horizontalSpacer_4;
    QWidget *pageEmprunt;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnParametre;
    QPushButton *btnDeconnexion;

    void setupUi(QWidget *App)
    {
        if (App->objectName().isEmpty())
            App->setObjectName("App");
        App->resize(529, 431);
        verticalLayout = new QVBoxLayout(App);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(App);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        btnAccueil = new QPushButton(frame);
        btnAccueil->setObjectName("btnAccueil");

        horizontalLayout->addWidget(btnAccueil);

        btnLivre = new QPushButton(frame);
        btnLivre->setObjectName("btnLivre");

        horizontalLayout->addWidget(btnLivre);

        btnMembre = new QPushButton(frame);
        btnMembre->setObjectName("btnMembre");

        horizontalLayout->addWidget(btnMembre);

        btnEmprunt = new QPushButton(frame);
        btnEmprunt->setObjectName("btnEmprunt");

        horizontalLayout->addWidget(btnEmprunt);


        verticalLayout->addWidget(frame);

        stackedWidget = new QStackedWidget(App);
        stackedWidget->setObjectName("stackedWidget");
        pageAccueil = new QWidget();
        pageAccueil->setObjectName("pageAccueil");
        stackedWidget->addWidget(pageAccueil);
        pageLivre = new QWidget();
        pageLivre->setObjectName("pageLivre");
        verticalLayout_2 = new QVBoxLayout(pageLivre);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableWidget = new QTableWidget(pageLivre);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_2->addWidget(tableWidget);

        frame_2 = new QFrame(pageLivre);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnAjouterLivre = new QPushButton(frame_2);
        btnAjouterLivre->setObjectName("btnAjouterLivre");

        horizontalLayout_2->addWidget(btnAjouterLivre);

        btnModifierLivre = new QPushButton(frame_2);
        btnModifierLivre->setObjectName("btnModifierLivre");

        horizontalLayout_2->addWidget(btnModifierLivre);

        btnSupprimerLivre = new QPushButton(frame_2);
        btnSupprimerLivre->setObjectName("btnSupprimerLivre");

        horizontalLayout_2->addWidget(btnSupprimerLivre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(frame_2);

        stackedWidget->addWidget(pageLivre);
        pageMembre = new QWidget();
        pageMembre->setObjectName("pageMembre");
        verticalLayout_3 = new QVBoxLayout(pageMembre);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_5 = new QFrame(pageMembre);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8("/*QPushButton:focus{\n"
"	background-color:blue;\n"
"}*/"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnMembreEtudiant = new QPushButton(frame_5);
        btnMembreEtudiant->setObjectName("btnMembreEtudiant");

        horizontalLayout_5->addWidget(btnMembreEtudiant);

        btnMembreAdulte = new QPushButton(frame_5);
        btnMembreAdulte->setObjectName("btnMembreAdulte");

        horizontalLayout_5->addWidget(btnMembreAdulte);


        verticalLayout_3->addWidget(frame_5);

        stackedWidget_2 = new QStackedWidget(pageMembre);
        stackedWidget_2->setObjectName("stackedWidget_2");
        pageEtudiant = new QWidget();
        pageEtudiant->setObjectName("pageEtudiant");
        verticalLayout_4 = new QVBoxLayout(pageEtudiant);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tableWidget_2 = new QTableWidget(pageEtudiant);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        tableWidget_2->setObjectName("tableWidget_2");

        verticalLayout_4->addWidget(tableWidget_2);

        frame_4 = new QFrame(pageEtudiant);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnAjouterEtudiant = new QPushButton(frame_4);
        btnAjouterEtudiant->setObjectName("btnAjouterEtudiant");

        horizontalLayout_4->addWidget(btnAjouterEtudiant);

        btnModifierEtudiant = new QPushButton(frame_4);
        btnModifierEtudiant->setObjectName("btnModifierEtudiant");

        horizontalLayout_4->addWidget(btnModifierEtudiant);

        btnSupprimerEtudiant = new QPushButton(frame_4);
        btnSupprimerEtudiant->setObjectName("btnSupprimerEtudiant");

        horizontalLayout_4->addWidget(btnSupprimerEtudiant);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(frame_4);

        stackedWidget_2->addWidget(pageEtudiant);
        pageAdulte = new QWidget();
        pageAdulte->setObjectName("pageAdulte");
        verticalLayout_5 = new QVBoxLayout(pageAdulte);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tableWidget_3 = new QTableWidget(pageAdulte);
        if (tableWidget_3->columnCount() < 7)
            tableWidget_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        tableWidget_3->setObjectName("tableWidget_3");

        verticalLayout_5->addWidget(tableWidget_3);

        frame_6 = new QFrame(pageAdulte);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btnAjouterAdulte = new QPushButton(frame_6);
        btnAjouterAdulte->setObjectName("btnAjouterAdulte");

        horizontalLayout_6->addWidget(btnAjouterAdulte);

        btnModifierAdulte = new QPushButton(frame_6);
        btnModifierAdulte->setObjectName("btnModifierAdulte");

        horizontalLayout_6->addWidget(btnModifierAdulte);

        btnSupprimerAdulte = new QPushButton(frame_6);
        btnSupprimerAdulte->setObjectName("btnSupprimerAdulte");

        horizontalLayout_6->addWidget(btnSupprimerAdulte);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_5->addWidget(frame_6);

        stackedWidget_2->addWidget(pageAdulte);

        verticalLayout_3->addWidget(stackedWidget_2);

        stackedWidget->addWidget(pageMembre);
        pageEmprunt = new QWidget();
        pageEmprunt->setObjectName("pageEmprunt");
        stackedWidget->addWidget(pageEmprunt);

        verticalLayout->addWidget(stackedWidget);

        frame_3 = new QFrame(App);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnParametre = new QPushButton(frame_3);
        btnParametre->setObjectName("btnParametre");

        horizontalLayout_3->addWidget(btnParametre);

        btnDeconnexion = new QPushButton(frame_3);
        btnDeconnexion->setObjectName("btnDeconnexion");

        horizontalLayout_3->addWidget(btnDeconnexion);


        verticalLayout->addWidget(frame_3);


        retranslateUi(App);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(App);
    } // setupUi

    void retranslateUi(QWidget *App)
    {
        App->setWindowTitle(QCoreApplication::translate("App", "Form", nullptr));
        btnAccueil->setText(QCoreApplication::translate("App", "Accueil", nullptr));
        btnLivre->setText(QCoreApplication::translate("App", "Livres", nullptr));
        btnMembre->setText(QCoreApplication::translate("App", "Membres", nullptr));
        btnEmprunt->setText(QCoreApplication::translate("App", "Emprunts", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("App", "Titre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("App", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("App", "Auteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("App", "Maison d'\303\251dition", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("App", "Propri\303\251t\303\251s", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("App", "Quantit\303\251", nullptr));
        btnAjouterLivre->setText(QCoreApplication::translate("App", "Nouveau", nullptr));
        btnModifierLivre->setText(QCoreApplication::translate("App", "Modifier", nullptr));
        btnSupprimerLivre->setText(QCoreApplication::translate("App", "Supprimer", nullptr));
        btnMembreEtudiant->setText(QCoreApplication::translate("App", "Etudiants", nullptr));
        btnMembreAdulte->setText(QCoreApplication::translate("App", "Adultes", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("App", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("App", "Pr\303\251nom(s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("App", "Date de naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("App", "Niveau d'\303\251tude", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("App", "Sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("App", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("App", "Num\303\251ro de t\303\251l\303\251phone", nullptr));
        btnAjouterEtudiant->setText(QCoreApplication::translate("App", "Nouveau", nullptr));
        btnModifierEtudiant->setText(QCoreApplication::translate("App", "Modifier", nullptr));
        btnSupprimerEtudiant->setText(QCoreApplication::translate("App", "Supprimer", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("App", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("App", "Pr\303\251nom(s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("App", "Date de naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("App", "Fonction", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("App", "Sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("App", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("App", "Num\303\251ro de t\303\251l\303\251phone", nullptr));
        btnAjouterAdulte->setText(QCoreApplication::translate("App", "Nouveau", nullptr));
        btnModifierAdulte->setText(QCoreApplication::translate("App", "Modifier", nullptr));
        btnSupprimerAdulte->setText(QCoreApplication::translate("App", "Supprimer", nullptr));
        btnParametre->setText(QCoreApplication::translate("App", "Parametre", nullptr));
        btnDeconnexion->setText(QCoreApplication::translate("App", "D\303\251connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class App: public Ui_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
