#include "parametre.h"
#include "ui_parametre.h"
#include "databasemanager.h"
#include "custommessagebox.h"

Parametre::Parametre(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Parametre)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    connect(ui->btnEnregistrerParametre, &QPushButton::clicked, this, &Parametre::enregistrerParametre);
    connect(ui->btnAnnulerParametre, &QPushButton::clicked, this, &Parametre::fermerFenetre);
    connect(ui->reinitialisation, &QPushButton::clicked, this, &Parametre::reinitialiser);
}

Parametre::~Parametre()
{
    delete ui;
}

void Parametre::enregistrerParametre() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    // Récupération des valeurs des QLineEdit
    QString armoire = ui->lineEditArmoire->text();
    QString genre = ui->lineEditGenre->text();

    // Vérification si les champs ne sont pas vides
    if (armoire.isEmpty() && genre.isEmpty()) {
        msgBox.showWarning("Attention", "Veuillez entrer des données pour l'armoire et/ou le genre.");
        return;
    }

    QSqlQuery query(sqlitedb);

    // Insertion dans la table "armoires" si le champ armoire n'est pas vide
    if (!armoire.isEmpty()) {
        query.prepare("INSERT INTO armoires (armoire) VALUES (:armoire)");
        query.bindValue(":armoire", armoire);
        if (!query.exec()) {
            msgBox.showError("Erreur", "Erreur lors de l'ajout de l'armoire");
            return;
        }
    }

    // Insertion dans la table "genres" si le champ genre n'est pas vide
    if (!genre.isEmpty()) {
        query.prepare("INSERT INTO genres (genre) VALUES (:genre)");
        query.bindValue(":genre", genre);
        if (!query.exec()) {
            msgBox.showError("Erreur", "Erreur lors de l'ajout du genre");
            return;
        }
    }

    // Si tout s'est bien passé, afficher un message de succès
    msgBox.showInformation("Succès", "Modifications effectuées avec succès.");

    // Vider les QLineEdit après ajout
    ui->lineEditArmoire->clear();
    ui->lineEditGenre->clear();

    // Émettre le signal après l'ajout
    emit ajoutArmoir();
}


void Parametre::fermerFenetre(){
    this->close();
}

void Parametre::reinitialiser(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QMessageBox confirmationBox;
    confirmationBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    confirmationBox.setText("Voulez-vous vraiment reinitialiser les données? ATTENTION!!!, cette action est irreversible");
    confirmationBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirmationBox.setIcon(QMessageBox::Question);
    confirmationBox.setStyleSheet("QMessageBox {"
                                  "   background-color: white;"
                                  "   border: 1px outset grey;"
                                  "   border-radius: 10px;"
                                  "   padding: 0px;"               // Retirer le débordement
                                  "   margin: 0px;"                // Ajuster les marges pour éviter tout débordement
                                  "}"
                                  "QLabel {"
                                  "   color: black;"
                                  "   font-size: 14px;"
                                  "}"
                                  "QPushButton {"
                                  "   background-color: white;"
                                  "   color: black;"
                                  "   padding: 5px 10px;"
                                  "   border-radius: 4px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "   background-color: #81DAE3;"
                                  "}"
                                  "QPushButton:pressed {"
                                  "   background-color: #6CBEC7;"
                                  "}");

    int ret = confirmationBox.exec();

    if (ret == QMessageBox::No) {
        // Si l'utilisateur a cliqué sur "NON", annuler l'opération
        return;
    }
    QSqlQuery query(sqlitedb);
    query.exec("PRAGMA foreign_keys = OFF;");

    // Récupérer toutes les tables
    query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%';");

    // Vérifier s'il y a une erreur lors de la récupération des tables
    if (query.lastError().isValid()) {
        qWarning() << "Erreur lors de la récupération des tables:" << query.lastError().text();
        return;
    }

    // Supprimer les données de chaque table
    while (query.next()) {
        QString tableName = query.value(0).toString();

        // Exclure les tables "login" et "statut_montants" de la suppression
        if (tableName != "login" && tableName != "statut_montants") {
            QString deleteQuery = QString("DELETE FROM %1;").arg(tableName);
            QSqlQuery delQuery(sqlitedb);
            if (!delQuery.exec(deleteQuery)) {
                qWarning() << "Erreur lors de la suppression des données de la table" << tableName << ":"
                           << delQuery.lastError().text();
            }
        }
    }

    // Réinitialiser l'auto-incrémentation
    QSqlQuery resetSeqQuery(sqlitedb);
    if (!resetSeqQuery.exec("DELETE FROM sqlite_sequence;")) {
        qWarning() << "Erreur lors de la réinitialisation des séquences:" << resetSeqQuery.lastError().text();
    }

    // Réactiver les contraintes de clé étrangère
    query.exec("PRAGMA foreign_keys = ON;");
    this->close();
}
