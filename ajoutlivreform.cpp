#include "ajoutlivreform.h"
#include "ui_ajoutlivreform.h"
#include "custommessagebox.h"
#include "databasemanager.h"

AjoutLivreForm::AjoutLivreForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutLivreForm)
{
    ui->setupUi(this);
    comboArmoireAfficher();
    comboGenreAfficher();
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
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
    QString genre = ui->comboBoxGenre->currentText();
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
    QString armoire = ui->comboBoxArmoire->currentText();


    QSqlQuery query(sqlitedb);
    query.prepare("INSERT INTO Livres (titre, genre, auteur, maison_edition, proprietes, quantite, armoire) "
                  "VALUES (:titre, :genre, :auteur, :maison_edition, :propriete, :quantite, :armoire)");

    query.bindValue(":titre", titre);
    query.bindValue(":genre", genre);
    query.bindValue(":auteur", auteur);
    query.bindValue(":maison_edition", maison_edition);
    query.bindValue(":propriete", propriete);
    query.bindValue(":quantite", quantite);
    query.bindValue(":armoire", armoire);

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
    ui->comboBoxGenre->setCurrentIndex(0);
    ui->lineEditAuteur->clear();       // Vide le champ Auteur
    ui->lineEditMaisonEdition->clear();       // Vide le champ Maison d'édition
    ui->textEditPropriete->clear();   // Vide le champ Propriétés
    ui->spinBoxQuantite->setValue(0);  // Réinitialise la Quantité à 0
    ui->comboBoxArmoire->setCurrentIndex(0);
}

void AjoutLivreForm::comboArmoireAfficher() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    // Vérifier l'ouverture de la base de données
    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    QSqlQuery query(sqlitedb);
    query.exec("SELECT armoire FROM armoires");

    // Obtenir la référence au QComboBox
    QComboBox *comboBoxArmoire = ui->comboBoxArmoire;
    comboBoxArmoire->clear();  // Vider le QComboBox avant d'ajouter de nouveaux éléments

    // Exécuter la requête
    if (!query.exec()) {
        msgBox.showError("Erreur", "Erreur lors de l'exécution de la requête");
        return;
    }
    comboBoxArmoire->addItem("");

    // Parcourir les résultats et ajouter chaque armoire au QComboBox
    while (query.next()) {
        QString armoire = query.value("armoire").toString();
        qDebug() << "Ajout de l'armoire:" << armoire;  // Afficher chaque armoire pour déboguer
        comboBoxArmoire->addItem(armoire);
    }

    qDebug() << "Liste des armoires mise à jour avec succès.";
}

void AjoutLivreForm::comboGenreAfficher(){
        CustomMessageBox msgBox;
        QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

        // Vérifier l'ouverture de la base de données
        if (!sqlitedb.open()) {
            msgBox.showError("Erreur", "Impossible d'ouvrir la base de données.");
            return;
        }

        QSqlQuery query(sqlitedb);
        query.prepare("SELECT genre FROM genres");

        // Obtenir la référence au QComboBox
        QComboBox *comboBoxArmoire = ui->comboBoxGenre;
        comboBoxArmoire->clear();  // Vider le QComboBox avant d'ajouter de nouveaux éléments

        // Ajouter une option "Tous" pour afficher tous les livres
        comboBoxArmoire->addItem("");
        // Exécuter la requête
        if (!query.exec()) {
            msgBox.showError("Erreur", "Erreur lors de l'exécution de la requête");
            return;
        }

        // Parcourir les résultats et ajouter chaque armoire au QComboBox
        while (query.next()) {
            QString genre = query.value("genre").toString();
            qDebug() << "Ajout de l'armoire:" << genre;  // Afficher chaque armoire pour déboguer
            comboBoxArmoire->addItem(genre);
        }

        qDebug() << "Liste des armoires mise à jour avec succès.";


}
