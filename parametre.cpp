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
