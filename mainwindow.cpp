#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "custommessagebox.h"
#include "databasemanager.h"
#include "app.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page);
    connect(ui->btnInscription, &QPushButton::clicked, this, &MainWindow::on_btnInscription_clicked);
    connect(ui->btnConnexion_2, &QPushButton::clicked, this, &MainWindow::on_btnConnexion_2_clicked);
    connect(ui->btnConnexion, &QPushButton::clicked, this, &MainWindow::handleConnectionButton);
    connect(ui->btnInscription_2, &QPushButton::clicked, this, &MainWindow::handleInscriptionButton);
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


void MainWindow::handleConnectionButton()
{
    CustomMessageBox msgBox;

    // Récupère la base de données via DatabaseManager
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    if (!sqlitedb.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'accéder à la base de données");
        return;
    }
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditMdp->text();

    QSqlQuery query(sqlitedb);
    query.prepare("SELECT * FROM login WHERE user = :username AND password = :password");

    // Vérifiez que vous liez bien les paramètres
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(query.exec()){
        if(query.next()){
            msgBox.showInformation("Succés", "Accés autorisé");
            App *app = new App(nullptr);
            app->show();
            this->hide();
        }else{
            msgBox.showWarning("Erreur", "Utilisateur ou mot de passe invalide");
        }
    }else{
        msgBox.showError("Erreur", "Erreur de connexion à la base données");
    }

}


void MainWindow::handleInscriptionButton()
{
    qDebug() << "on_btnInscription_2_clicked() called";

    CustomMessageBox msgBox;

    // Récupère la base de données via DatabaseManager
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    QString username = ui->lineEditAddUser->text();
    QString password = ui->lineEditAddMdp->text();
    QString confirmPassword = ui->lineEditConfirmMdp->text();

    if (!sqlitedb.isOpen()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données");
        return;
    }
    if(username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()){
        msgBox.showWarning("Erreur", "Veuillez remplir le formulaire");
        return;
    }

    if (password != confirmPassword) {
        msgBox.showWarning("Erreur", "Veuillez insérer des mots de passe identiques");
        return;
    }

    QSqlQuery query(sqlitedb);
    query.prepare("INSERT INTO login (user, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        // Si l'insertion réussit
        msgBox.showInformation("Succès", "Utilisateur ajouté avec succès !");
        ui->stackedWidget->setCurrentWidget(ui->page); // Redirige vers une autre page
    } else {
        // Si l'insertion échoue, afficher l'erreur et le message spécifique
        msgBox.showError("Erreur", "Échec de l'ajout de l'utilisateur");
    }
}




