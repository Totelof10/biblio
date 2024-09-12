#include "deconnexion.h"
#include "ui_deconnexion.h"
#include "mainwindow.h"


Deconnexion::Deconnexion(QWidget *parent, App *appWindow)
    : QWidget(parent), appWindow(appWindow)
    , ui(new Ui::Deconnexion)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    connect(ui->btnOui, &QPushButton::clicked, this, &Deconnexion::oui);
    connect(ui->btnNon, &QPushButton::clicked, this, &Deconnexion::non);
}

Deconnexion::~Deconnexion()
{
    delete ui;
}

void Deconnexion::oui() {
    MainWindow *main = new MainWindow(nullptr);
    main->show();

    // Fermer la fenêtre "App"
    if (appWindow) {
        appWindow->close();
    }

    this->close();  // Ferme la fenêtre Deconnexion
}
void Deconnexion::non(){
    this->close();
}
