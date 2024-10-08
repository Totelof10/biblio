#include "modifierlivreform.h"
#include "ui_modifierlivreform.h"
#include "databasemanager.h"
#include "custommessagebox.h"
ModifierLivreForm::ModifierLivreForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::ModifierLivreForm)
{
    ui->setupUi(this);
}

ModifierLivreForm::ModifierLivreForm(QString titre, QString genre, QString auteur, QString maison_edition, QString proprietes, int quantite, QString armoire, QString identifiant, QWidget *parent)
    : QWidget(parent), ancienTitre(titre)
    , ui(new Ui::ModifierLivreForm)
{
    ui->setupUi(this);
    comboArmoireAfficher();
    comboGenreAfficher();
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    ui->lineEditTitre->setText(titre);
    ui->comboBoxGenre->setCurrentText(genre);
    ui->lineEditAuteur->setText(auteur);
    ui->lineEditMaisonEdition->setText(maison_edition);
    ui->textEditPropriete->setText(proprietes);
    ui->spinBoxQuantite->setValue(quantite);
    ui->comboBoxArmoire->setCurrentText(armoire);
    connect(ui->btnEnregistrer, &QPushButton::clicked, this, &ModifierLivreForm::modifierLivre);
    connect(ui->btnAnnuler, &QPushButton::clicked, this, &ModifierLivreForm::annulerModif);
}

ModifierLivreForm::~ModifierLivreForm()
{
    delete ui;
}

void ModifierLivreForm::modifierLivre() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();    // Récupérer les nouvelles valeurs des champs
    QString nouveauTitre = ui->lineEditTitre->text();
    QString nouveauGenre = ui->comboBoxGenre->currentText();
    QString nouvelAuteur = ui->lineEditAuteur->text();
    QString nouvelleMaisonEdition = ui->lineEditMaisonEdition->text();
    QString nouvellesProprietes = ui->textEditPropriete->toPlainText();
    int nouvelleQuantite = ui->spinBoxQuantite->value();
    QString nouvelleArmoire = ui->comboBoxArmoire->currentText();

    // Mise à jour de la base de données
    QSqlQuery query(sqlitedb);
    query.prepare("UPDATE livres SET titre = :titre, genre = :genre, auteur = :auteur, maison_edition = :maison_edition, "
                  "proprietes = :proprietes, quantite = :quantite, armoire = :armoire WHERE titre = :ancienTitre");
    query.bindValue(":titre", nouveauTitre);
    query.bindValue(":genre", nouveauGenre);
    query.bindValue(":auteur", nouvelAuteur);
    query.bindValue(":maison_edition", nouvelleMaisonEdition);
    query.bindValue(":proprietes", nouvellesProprietes);
    query.bindValue(":quantite", nouvelleQuantite);
    query.bindValue(":armoire", nouvelleArmoire);
    query.bindValue(":ancienTitre", ancienTitre);

    if (query.exec()) {
        msgBox.showInformation("Succès", "Les informations du livre ont été modifiées.");
        // Mettez à jour l'affichage du tableau dans la fenêtre App
        emit modifieLivre(nouveauTitre, nouveauGenre, nouvelAuteur, nouvelleMaisonEdition, nouvellesProprietes, nouvelleQuantite, nouvelleArmoire);
        close();
    } else {
        msgBox.showError("Erreur", "Échec de la modification des informations du livre.");
    }

}

void ModifierLivreForm::annulerModif(){
    this->close();
}

void ModifierLivreForm::comboArmoireAfficher() {
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

void ModifierLivreForm::comboGenreAfficher(){
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
