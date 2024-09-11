#include "app.h"
#include "ui_app.h"
#include "ajoutlivreform.h"

App::App(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageAccueil);
    ui->stackedWidget_2->setCurrentWidget(ui->pageEtudiant);
    connect(ui->btnAccueil, &QPushButton::clicked, this, &App::handleAccueil);
    connect(ui->btnLivre, &QPushButton::clicked, this, &App::handleLivre);
    connect(ui->btnMembre, &QPushButton::clicked, this, &App::handleMembre);
    connect(ui->btnEmprunt, &QPushButton::clicked, this, &App::handleEmprunt);
    connect(ui->btnMembreEtudiant, &QPushButton::clicked, this, &App::handleEtudiant);
    connect(ui->btnMembreAdulte, &QPushButton::clicked, this, &App::handleAdulte);
    connect(ui->btnAjouterLivre, &QPushButton::clicked, this, &App::handleAfficherAjoutLivreForm);

}

App::~App()
{
    delete ui;
}

void App::handleAccueil(){
    ui->stackedWidget->setCurrentWidget(ui->pageAccueil);
}

void App::handleLivre(){
    ui->stackedWidget->setCurrentWidget(ui->pageLivre);

}

void App::handleMembre(){
    ui->stackedWidget->setCurrentWidget(ui->pageMembre);
}

void App::handleEmprunt(){
    ui->stackedWidget->setCurrentWidget(ui->pageEmprunt);
}

void App::handleEtudiant(){
    ui->stackedWidget_2->setCurrentWidget(ui->pageEtudiant);
}

void App::handleAdulte(){
    ui->stackedWidget_2->setCurrentWidget(ui->pageAdulte);
}

void App::handleAfficherAjoutLivreForm(){
    AjoutLivreForm *formLivre = new AjoutLivreForm(nullptr);
    formLivre->show();
}


