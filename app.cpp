#include "app.h"
#include "ui_app.h"
#include "ajoutlivreform.h"
#include "databasemanager.h"
#include "custommessagebox.h"

App::App(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
    afficherLivreDansTableau();
    ui->stackedWidget->setCurrentWidget(ui->pageAccueil);
    ui->stackedWidget_2->setCurrentWidget(ui->pageEtudiant);
    connect(ui->btnAccueil, &QPushButton::clicked, this, &App::handleAccueil);
    connect(ui->btnLivre, &QPushButton::clicked, this, &App::handleLivre);
    connect(ui->btnMembre, &QPushButton::clicked, this, &App::handleMembre);
    connect(ui->btnEmprunt, &QPushButton::clicked, this, &App::handleEmprunt);
    connect(ui->btnMembreEtudiant, &QPushButton::clicked, this, &App::handleEtudiant);
    connect(ui->btnMembreAdulte, &QPushButton::clicked, this, &App::handleAdulte);
    connect(ui->btnAjouterLivre, &QPushButton::clicked, this, &App::handleAfficherAjoutLivreForm);
    connect(ui->btnSupprimerLivre, &QPushButton::clicked, this, &App::supprimerLivre);

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
    connect(formLivre, &AjoutLivreForm::ajoutLivre, this, &App::afficherLivreDansTableau);
    formLivre->show();
}

void App::afficherLivreDansTableau(){
    CustomMessageBox msgBox;

    // Récupère la base de données via DatabaseManager
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    // Préparation et exécution de la requête SQL
    QSqlQuery query(sqlitedb);
    if (!query.exec("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres")) {
        msgBox.showError("Erreur", "Échec de l'exécution de la requête.");
        return;
    }

    // Vider le QTableWidget avant d'insérer les nouvelles données
    ui->tableWidget->setRowCount(0);

    // Configuration du QTableWidget (nombre de colonnes et labels des en-têtes)
    ui->tableWidget->setColumnCount(7); // 6 colonnes : titre, genre, auteur, maison_edition, proprietes, quantite
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Titre" << "Genre" << "Auteur"
                                                             << "Maison d'édition" << "Propriétés" << "Quantité"<<"Armoire");

    // Insertion des données dans le QTableWidget
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Récupération des données (sans l'ID)
        QString titre = query.value(0).toString();
        QString genre = query.value(1).toString();
        QString auteur = query.value(2).toString();
        QString maison_edition = query.value(3).toString();
        QString proprietes = query.value(4).toString();
        int quantite = query.value(5).toInt();
        QString armoire = query.value(6).toString();

        // Insertion des données dans le QTableWidget sans l'ID
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(titre));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(genre));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(auteur));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(maison_edition));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(proprietes));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(quantite)));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(armoire));

        row++;
    }
}

void App::supprimerLivre() {
    CustomMessageBox msgBox;
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow < 0) {
        msgBox.showWarning("Attention", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    // Récupérer le titre du livre à supprimer
    QTableWidgetItem *titreItem = ui->tableWidget->item(selectedRow, 0); // Le titre est dans la première colonne
    if (!titreItem) {
        msgBox.showWarning("Erreur", "Impossible de récupérer le titre du livre.");
        return;
    }

    QString titre = titreItem->text();

    // Connexion à la base de données
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'accéder à la base de données");
        return;
    }

    // Préparer la requête de suppression
    QSqlQuery query(sqlitedb);
    query.prepare("DELETE FROM livres WHERE titre = :titre");
    query.bindValue(":titre", titre);

    if (query.exec()) {
        // Supprimer la ligne du tableau
        ui->tableWidget->removeRow(selectedRow);
        msgBox.showInformation("Succès", "Le livre a été supprimé avec succès");
    } else {
        msgBox.showError("Erreur", "Échec de la suppression du livre de la base de données");
    }
}


