#include "ajoutlivreform.h"
#include "ui_ajoutlivreform.h"
#include "custommessagebox.h"
#include "databasemanager.h"

AjoutLivreForm::AjoutLivreForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutLivreForm)
{
    ui->setupUi(this);
    connect(ui->btnAnnuler, &QPushButton::clicked, this, &AjoutLivreForm::handleAnnuler);
    connect(ui->btnAjouter, &QPushButton::clicked, this, &AjoutLivreForm::handleAjouterLivre);

}

AjoutLivreForm::~AjoutLivreForm()
{
    delete ui;
}

void AjoutLivreForm::handleAnnuler(){
    this->close();
}

void AjoutLivreForm::handleAjouterLivre(){
    CustomMessageBox msgBox;

    // Vérifier que les champs obligatoires ne sont pas vides
    QString titre = ui->lineEditTitre->text();
    QString genre = ui->lineEditGenre->text();
    QString auteur = ui->lineEditAuteur->text();
    if (titre.isEmpty() || genre.isEmpty() || auteur.isEmpty()) {
        msgBox.showError("Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Récupère la base de données via DatabaseManager
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    if (!sqlitedb.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'accéder à la base de données");
        return;
    }

    QString maison_edition = ui->lineEditMaisonEdition->text();
    QString propriete = ui->textEditPropriete->toPlainText();
    int quantite = ui->spinBoxQuantite->value();

    QSqlQuery query(sqlitedb);
    query.prepare("INSERT INTO Livres (titre, genre, auteur, maison_edition, proprietes, quantite) "
                  "VALUES (:titre, :genre, :auteur, :maison_edition, :propriete, :quantite)");

    query.bindValue(":titre", titre);
    query.bindValue(":genre", genre);
    query.bindValue(":auteur", auteur);
    query.bindValue(":maison_edition", maison_edition);
    query.bindValue(":propriete", propriete);
    query.bindValue(":quantite", quantite);

    if (query.exec()) {
        msgBox.showInformation("Succès", "Ajout réussi");
        clearForm();  // Vider le formulaire après l'ajout
    } else {
        msgBox.showError("Erreur", "Erreur lors de l'ajout du livre");
    }
    emit ajoutLivre();
}


void AjoutLivreForm::clearForm(){
    ui->lineEditTitre->clear();        // Vide le champ Titre
    ui->lineEditGenre->clear();
    ui->lineEditAuteur->clear();       // Vide le champ Auteur
    ui->lineEditMaisonEdition->clear();       // Vide le champ Maison d'édition
    ui->textEditPropriete->clear();   // Vide le champ Propriétés
    ui->spinBoxQuantite->setValue(0);  // Réinitialise la Quantité à 0
}
