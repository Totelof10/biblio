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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QCalendarWidget *calendarWidget;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnHistorique;
    QPushButton *btnFinance;
    QSpacerItem *horizontalSpacer_3;
    QWidget *pageLivre;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEditRecherche;
    QPushButton *btnRecherche;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QComboBox *comboBoxChoixArmoir;
    QLabel *label_2;
    QComboBox *comboBoxChoixGenre;
    QTableWidget *tableWidget;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAjouterLivre;
    QPushButton *btnModifierLivre;
    QPushButton *btnSupprimerLivre;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExporter;
    QPushButton *btnImporter;
    QWidget *pageMembre;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_4;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *lineEditNom;
    QLabel *label_5;
    QLineEdit *lineEditPrenoms;
    QLabel *label_6;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioAdulte;
    QRadioButton *radioEnfant;
    QLabel *label_8;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioSexeHomme;
    QRadioButton *radioSexeFemme;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_7;
    QPushButton *btnEnregistrerMembre;
    QLineEdit *lineEditContact;
    QLabel *label_13;
    QDateEdit *dateTimeEditDebut;
    QDateEdit *dateTimeEditFin;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineRecherche;
    QTableWidget *tableWidget_2;
    QWidget *pageEmprunt;
    QHBoxLayout *horizontalLayout_11;
    QFrame *frame_13;
    QFormLayout *formLayout_2;
    QLabel *label_14;
    QComboBox *comboBoxMembres;
    QLabel *label_15;
    QComboBox *comboBoxLivres;
    QLabel *label_16;
    QLabel *label_17;
    QDateEdit *dateEditDebut;
    QDateEdit *dateEditFin;
    QPushButton *btnEnregistrerEmprunt;
    QLineEdit *lineEditRechercheMembres;
    QLineEdit *lineEditRechercheLivres;
    QFrame *frame_14;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QLineEdit *lineEditRechercheEmprunt;
    QTableWidget *tableWidget_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnParametre;
    QPushButton *btnDeconnexion;

    void setupUi(QWidget *App)
    {
        if (App->objectName().isEmpty())
            App->setObjectName("App");
        App->resize(529, 445);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/CartoBMW/img/FRK.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        App->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(App);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(App);
        frame->setObjectName("frame");
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(29, 46, 62);\n"
"}\n"
"QPushButton{\n"
"	padding: 10px 10px;\n"
"	border:none;\n"
"	color:white;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(45, 66, 75);\n"
"}\n"
"QPushButton:focus{\n"
"	background-color:#00CCDD;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnAccueil = new QPushButton(frame);
        btnAccueil->setObjectName("btnAccueil");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        btnAccueil->setFont(font);
        btnAccueil->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnAccueil);

        btnLivre = new QPushButton(frame);
        btnLivre->setObjectName("btnLivre");
        btnLivre->setFont(font);
        btnLivre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnLivre->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnLivre);

        btnMembre = new QPushButton(frame);
        btnMembre->setObjectName("btnMembre");
        btnMembre->setFont(font);
        btnMembre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnMembre);

        btnEmprunt = new QPushButton(frame);
        btnEmprunt->setObjectName("btnEmprunt");
        btnEmprunt->setFont(font);
        btnEmprunt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnEmprunt);


        verticalLayout->addWidget(frame);

        stackedWidget = new QStackedWidget(App);
        stackedWidget->setObjectName("stackedWidget");
        pageAccueil = new QWidget();
        pageAccueil->setObjectName("pageAccueil");
        verticalLayout_6 = new QVBoxLayout(pageAccueil);
        verticalLayout_6->setObjectName("verticalLayout_6");
        frame_9 = new QFrame(pageAccueil);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_9);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_3 = new QLabel(frame_9);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_7->addWidget(label_3);


        verticalLayout_6->addWidget(frame_9);

        calendarWidget = new QCalendarWidget(pageAccueil);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout_6->addWidget(calendarWidget);

        frame_10 = new QFrame(pageAccueil);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_10);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        btnHistorique = new QPushButton(frame_10);
        btnHistorique->setObjectName("btnHistorique");
        QFont font1;
        font1.setBold(true);
        btnHistorique->setFont(font1);
        btnHistorique->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnHistorique->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #419197;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #78D6C6;\n"
"}"));

        horizontalLayout_9->addWidget(btnHistorique);

        btnFinance = new QPushButton(frame_10);
        btnFinance->setObjectName("btnFinance");
        btnFinance->setFont(font1);
        btnFinance->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnFinance->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #DC6B19;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #FFAF45;\n"
"}"));

        horizontalLayout_9->addWidget(btnFinance);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_6->addWidget(frame_10);

        stackedWidget->addWidget(pageAccueil);
        pageLivre = new QWidget();
        pageLivre->setObjectName("pageLivre");
        verticalLayout_2 = new QVBoxLayout(pageLivre);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_12 = new QLabel(pageLivre);
        label_12->setObjectName("label_12");
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_12);

        frame_7 = new QFrame(pageLivre);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_7);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEditRecherche = new QLineEdit(frame_7);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid black;\n"
"}"));

        horizontalLayout_7->addWidget(lineEditRecherche);

        btnRecherche = new QPushButton(frame_7);
        btnRecherche->setObjectName("btnRecherche");
        QFont font2;
        font2.setBold(false);
        btnRecherche->setFont(font2);
        btnRecherche->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnRecherche->setMouseTracking(true);
        btnRecherche->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        btnRecherche->setIcon(icon1);

        horizontalLayout_7->addWidget(btnRecherche);


        verticalLayout_2->addWidget(frame_7);

        frame_8 = new QFrame(pageLivre);
        frame_8->setObjectName("frame_8");
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_8);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label = new QLabel(frame_8);
        label->setObjectName("label");

        horizontalLayout_8->addWidget(label);

        comboBoxChoixArmoir = new QComboBox(frame_8);
        comboBoxChoixArmoir->setObjectName("comboBoxChoixArmoir");

        horizontalLayout_8->addWidget(comboBoxChoixArmoir);

        label_2 = new QLabel(frame_8);
        label_2->setObjectName("label_2");

        horizontalLayout_8->addWidget(label_2);

        comboBoxChoixGenre = new QComboBox(frame_8);
        comboBoxChoixGenre->setObjectName("comboBoxChoixGenre");

        horizontalLayout_8->addWidget(comboBoxChoixGenre);


        verticalLayout_2->addWidget(frame_8);

        tableWidget = new QTableWidget(pageLivre);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableWidget);

        frame_2 = new QFrame(pageLivre);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAjouterLivre = new QPushButton(frame_2);
        btnAjouterLivre->setObjectName("btnAjouterLivre");
        btnAjouterLivre->setFont(font1);
        btnAjouterLivre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAjouterLivre->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        horizontalLayout_2->addWidget(btnAjouterLivre);

        btnModifierLivre = new QPushButton(frame_2);
        btnModifierLivre->setObjectName("btnModifierLivre");
        QFont font3;
        font3.setBold(true);
        font3.setUnderline(false);
        btnModifierLivre->setFont(font3);
        btnModifierLivre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnModifierLivre->setMouseTracking(true);
        btnModifierLivre->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #FFA823;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #FFD35A;\n"
"}"));

        horizontalLayout_2->addWidget(btnModifierLivre);

        btnSupprimerLivre = new QPushButton(frame_2);
        btnSupprimerLivre->setObjectName("btnSupprimerLivre");
        btnSupprimerLivre->setFont(font1);
        btnSupprimerLivre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSupprimerLivre->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #821131;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #C7253E;\n"
"}"));

        horizontalLayout_2->addWidget(btnSupprimerLivre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnExporter = new QPushButton(frame_2);
        btnExporter->setObjectName("btnExporter");
        btnExporter->setFont(font1);
        btnExporter->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnExporter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #FEAE6F;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #F6DCAC;\n"
"}"));

        horizontalLayout_2->addWidget(btnExporter);

        btnImporter = new QPushButton(frame_2);
        btnImporter->setObjectName("btnImporter");
        QFont font4;
        font4.setBold(true);
        font4.setItalic(false);
        btnImporter->setFont(font4);
        btnImporter->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnImporter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #03346E;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6EACDA;\n"
"}"));

        horizontalLayout_2->addWidget(btnImporter);


        verticalLayout_2->addWidget(frame_2);

        stackedWidget->addWidget(pageLivre);
        pageMembre = new QWidget();
        pageMembre->setObjectName("pageMembre");
        horizontalLayout_4 = new QHBoxLayout(pageMembre);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame_4 = new QFrame(pageMembre);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(frame_4);
        formLayout->setObjectName("formLayout");
        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEditNom = new QLineEdit(frame_4);
        lineEditNom->setObjectName("lineEditNom");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditNom);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName("label_5");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEditPrenoms = new QLineEdit(frame_4);
        lineEditPrenoms->setObjectName("lineEditPrenoms");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditPrenoms);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName("label_6");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        frame_11 = new QFrame(frame_4);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        radioAdulte = new QRadioButton(frame_11);
        radioAdulte->setObjectName("radioAdulte");
        radioAdulte->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_6->addWidget(radioAdulte);

        radioEnfant = new QRadioButton(frame_11);
        radioEnfant->setObjectName("radioEnfant");
        radioEnfant->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_6->addWidget(radioEnfant);


        formLayout->setWidget(4, QFormLayout::FieldRole, frame_11);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName("label_8");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        radioSexeHomme = new QRadioButton(frame_6);
        radioSexeHomme->setObjectName("radioSexeHomme");
        radioSexeHomme->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_5->addWidget(radioSexeHomme);

        radioSexeFemme = new QRadioButton(frame_6);
        radioSexeFemme->setObjectName("radioSexeFemme");
        radioSexeFemme->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_5->addWidget(radioSexeFemme);


        formLayout->setWidget(5, QFormLayout::FieldRole, frame_6);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName("label_9");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName("label_10");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_10);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");

        formLayout->setWidget(12, QFormLayout::LabelRole, label_7);

        btnEnregistrerMembre = new QPushButton(frame_4);
        btnEnregistrerMembre->setObjectName("btnEnregistrerMembre");
        btnEnregistrerMembre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnEnregistrerMembre->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        formLayout->setWidget(12, QFormLayout::FieldRole, btnEnregistrerMembre);

        lineEditContact = new QLineEdit(frame_4);
        lineEditContact->setObjectName("lineEditContact");

        formLayout->setWidget(9, QFormLayout::FieldRole, lineEditContact);

        label_13 = new QLabel(frame_4);
        label_13->setObjectName("label_13");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_13);

        dateTimeEditDebut = new QDateEdit(frame_4);
        dateTimeEditDebut->setObjectName("dateTimeEditDebut");

        formLayout->setWidget(6, QFormLayout::FieldRole, dateTimeEditDebut);

        dateTimeEditFin = new QDateEdit(frame_4);
        dateTimeEditFin->setObjectName("dateTimeEditFin");

        formLayout->setWidget(7, QFormLayout::FieldRole, dateTimeEditFin);


        horizontalLayout_4->addWidget(frame_4);

        frame_5 = new QFrame(pageMembre);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_11 = new QLabel(frame_5);
        label_11->setObjectName("label_11");
        label_11->setFont(font3);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_11);

        frame_12 = new QFrame(frame_5);
        frame_12->setObjectName("frame_12");
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_12);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lineRecherche = new QLineEdit(frame_12);
        lineRecherche->setObjectName("lineRecherche");
        lineRecherche->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid black;\n"
"}"));

        horizontalLayout_10->addWidget(lineRecherche);


        verticalLayout_3->addWidget(frame_12);

        tableWidget_2 = new QTableWidget(frame_5);
        if (tableWidget_2->columnCount() < 11)
            tableWidget_2->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(10, __qtablewidgetitem17);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget_2);


        horizontalLayout_4->addWidget(frame_5);

        horizontalLayout_4->setStretch(1, 8);
        stackedWidget->addWidget(pageMembre);
        pageEmprunt = new QWidget();
        pageEmprunt->setObjectName("pageEmprunt");
        horizontalLayout_11 = new QHBoxLayout(pageEmprunt);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        frame_13 = new QFrame(pageEmprunt);
        frame_13->setObjectName("frame_13");
        frame_13->setFrameShape(QFrame::Shape::StyledPanel);
        frame_13->setFrameShadow(QFrame::Shadow::Raised);
        formLayout_2 = new QFormLayout(frame_13);
        formLayout_2->setObjectName("formLayout_2");
        label_14 = new QLabel(frame_13);
        label_14->setObjectName("label_14");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_14);

        comboBoxMembres = new QComboBox(frame_13);
        comboBoxMembres->setObjectName("comboBoxMembres");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBoxMembres);

        label_15 = new QLabel(frame_13);
        label_15->setObjectName("label_15");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_15);

        comboBoxLivres = new QComboBox(frame_13);
        comboBoxLivres->setObjectName("comboBoxLivres");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, comboBoxLivres);

        label_16 = new QLabel(frame_13);
        label_16->setObjectName("label_16");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(frame_13);
        label_17->setObjectName("label_17");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_17);

        dateEditDebut = new QDateEdit(frame_13);
        dateEditDebut->setObjectName("dateEditDebut");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, dateEditDebut);

        dateEditFin = new QDateEdit(frame_13);
        dateEditFin->setObjectName("dateEditFin");

        formLayout_2->setWidget(6, QFormLayout::FieldRole, dateEditFin);

        btnEnregistrerEmprunt = new QPushButton(frame_13);
        btnEnregistrerEmprunt->setObjectName("btnEnregistrerEmprunt");
        btnEnregistrerEmprunt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnEnregistrerEmprunt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid white;\n"
"	border-radius: 7px;\n"
"	background-color: #16423C;\n"
"	color:white;\n"
"	padding: 7px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #6A9C89;\n"
"}"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, btnEnregistrerEmprunt);

        lineEditRechercheMembres = new QLineEdit(frame_13);
        lineEditRechercheMembres->setObjectName("lineEditRechercheMembres");
        lineEditRechercheMembres->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid black;\n"
"}"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditRechercheMembres);

        lineEditRechercheLivres = new QLineEdit(frame_13);
        lineEditRechercheLivres->setObjectName("lineEditRechercheLivres");
        lineEditRechercheLivres->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid black;\n"
"}"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEditRechercheLivres);


        horizontalLayout_11->addWidget(frame_13);

        frame_14 = new QFrame(pageEmprunt);
        frame_14->setObjectName("frame_14");
        frame_14->setFrameShape(QFrame::Shape::StyledPanel);
        frame_14->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_14);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_18 = new QLabel(frame_14);
        label_18->setObjectName("label_18");
        label_18->setFont(font1);
        label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_18);

        lineEditRechercheEmprunt = new QLineEdit(frame_14);
        lineEditRechercheEmprunt->setObjectName("lineEditRechercheEmprunt");
        lineEditRechercheEmprunt->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus{\n"
"	border: 1px solid black;\n"
"}"));

        verticalLayout_4->addWidget(lineEditRechercheEmprunt);

        tableWidget_3 = new QTableWidget(frame_14);
        if (tableWidget_3->columnCount() < 7)
            tableWidget_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem24);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(tableWidget_3);


        horizontalLayout_11->addWidget(frame_14);

        horizontalLayout_11->setStretch(1, 6);
        stackedWidget->addWidget(pageEmprunt);

        verticalLayout->addWidget(stackedWidget);

        frame_3 = new QFrame(App);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: rgb(29, 46, 62);\n"
"}\n"
"QPushButton{\n"
"	padding: 10px 10px;\n"
"	border:none;\n"
"	color:white;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(45, 66, 75);\n"
"}\n"
"QPushButton:focus{\n"
"	background-color:#00CCDD;\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnParametre = new QPushButton(frame_3);
        btnParametre->setObjectName("btnParametre");
        btnParametre->setFont(font);
        btnParametre->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_3->addWidget(btnParametre);

        btnDeconnexion = new QPushButton(frame_3);
        btnDeconnexion->setObjectName("btnDeconnexion");
        btnDeconnexion->setFont(font);
        btnDeconnexion->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_3->addWidget(btnDeconnexion);


        verticalLayout->addWidget(frame_3);


        retranslateUi(App);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(App);
    } // setupUi

    void retranslateUi(QWidget *App)
    {
        App->setWindowTitle(QCoreApplication::translate("App", "Biblioth\303\250que FRK", nullptr));
        btnAccueil->setText(QCoreApplication::translate("App", "Accueil", nullptr));
        btnLivre->setText(QCoreApplication::translate("App", "Livres", nullptr));
        btnMembre->setText(QCoreApplication::translate("App", "Membres", nullptr));
        btnEmprunt->setText(QCoreApplication::translate("App", "Emprunts", nullptr));
        label_3->setText(QCoreApplication::translate("App", "\"Tenin'Andriamanitra\"", nullptr));
        btnHistorique->setText(QCoreApplication::translate("App", "Historique des emprunts", nullptr));
        btnFinance->setText(QCoreApplication::translate("App", "Etat financier", nullptr));
        label_12->setText(QCoreApplication::translate("App", "GESTION DES LIVRES", nullptr));
        lineEditRecherche->setPlaceholderText(QCoreApplication::translate("App", "Recherche", nullptr));
        btnRecherche->setText(QString());
        label->setText(QCoreApplication::translate("App", "Trier par armoire", nullptr));
        label_2->setText(QCoreApplication::translate("App", "Trier par genre :", nullptr));
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
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("App", "Armoire", nullptr));
        btnAjouterLivre->setText(QCoreApplication::translate("App", "Nouveau", nullptr));
        btnModifierLivre->setText(QCoreApplication::translate("App", "Modifier", nullptr));
        btnSupprimerLivre->setText(QCoreApplication::translate("App", "Supprimer", nullptr));
        btnExporter->setText(QCoreApplication::translate("App", "Exporter", nullptr));
        btnImporter->setText(QCoreApplication::translate("App", "Importer", nullptr));
        label_4->setText(QCoreApplication::translate("App", "Nom :", nullptr));
        label_5->setText(QCoreApplication::translate("App", "Pr\303\251nom(s) :", nullptr));
        label_6->setText(QCoreApplication::translate("App", "Statut :", nullptr));
        radioAdulte->setText(QCoreApplication::translate("App", "Adulte", nullptr));
        radioEnfant->setText(QCoreApplication::translate("App", "Enfant", nullptr));
        label_8->setText(QCoreApplication::translate("App", "Sexe :", nullptr));
        radioSexeHomme->setText(QCoreApplication::translate("App", "Homme", nullptr));
        radioSexeFemme->setText(QCoreApplication::translate("App", "Femme", nullptr));
        label_9->setText(QCoreApplication::translate("App", "D\303\251but :", nullptr));
        label_10->setText(QCoreApplication::translate("App", "Fin :", nullptr));
        label_7->setText(QString());
        btnEnregistrerMembre->setText(QCoreApplication::translate("App", "Enregistrer", nullptr));
        label_13->setText(QCoreApplication::translate("App", "Contact", nullptr));
        label_11->setText(QCoreApplication::translate("App", "GESTION DES MEMBRES", nullptr));
        lineRecherche->setPlaceholderText(QCoreApplication::translate("App", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("App", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("App", "Pr\303\251nom(s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("App", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("App", "Sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("App", "D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("App", "Fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("App", "Contact", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("App", "Validit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("App", "Montant", nullptr));
        label_14->setText(QCoreApplication::translate("App", "Membres", nullptr));
        label_15->setText(QCoreApplication::translate("App", "Livres", nullptr));
        label_16->setText(QCoreApplication::translate("App", "D\303\251but de l'emprunt", nullptr));
        label_17->setText(QCoreApplication::translate("App", "Fin de l'emprunt", nullptr));
        btnEnregistrerEmprunt->setText(QCoreApplication::translate("App", "Enregistrer", nullptr));
        lineEditRechercheMembres->setPlaceholderText(QCoreApplication::translate("App", "Membres", nullptr));
        lineEditRechercheLivres->setPlaceholderText(QCoreApplication::translate("App", "Livres", nullptr));
        label_18->setText(QCoreApplication::translate("App", "GESTION DES EMPRUNTS", nullptr));
        lineEditRechercheEmprunt->setPlaceholderText(QCoreApplication::translate("App", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("App", "Id de l'emprunt", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("App", "Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("App", "D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("App", "Fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("App", "Emprunteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("App", "Validit\303\251", nullptr));
        btnParametre->setText(QCoreApplication::translate("App", "Param\303\250tre", nullptr));
        btnDeconnexion->setText(QCoreApplication::translate("App", "D\303\251connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class App: public Ui_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
