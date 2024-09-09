#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "custommessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page);
    connect(ui->btnInscription, &QPushButton::clicked, this, &MainWindow::on_btnInscription_clicked);
    connect(ui->btnConnexion_2, &QPushButton::clicked, this, &MainWindow::on_btnConnexion_2_clicked);
    connect(ui->btnConnexion, &QPushButton::clicked, this, &MainWindow::on_btnConnexion_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnInscription_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void MainWindow::on_btnConnexion_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void MainWindow::on_btnConnexion_clicked()
{
    static bool msgShown = false;
    if (!msgShown) {
        CustomMessageBox msgBox;
        msgBox.showInformation("Succès", "Connecté");
        msgShown = true;  // Assure que le message ne s'affiche qu'une seule fois
    }
}

