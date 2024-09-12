#include "app.h"
#include "ui_app.h"
#include "ajoutlivreform.h"
#include "databasemanager.h"
#include "custommessagebox.h"
#include "modifierlivreform.h"
#include "parametre.h"

App::App(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
    afficherLivreDansTableau();
    comboArmoireAfficher();
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
    connect(ui->btnModifierLivre, &QPushButton::clicked, this, &App::afficherFormulaireModif);
    connect (ui->btnRecherche, &QPushButton::clicked, this, &App::rechercheDeLivre);
    connect (ui->lineEditRecherche, &QLineEdit::textChanged, this, &App::rechercheDeLivre);
    connect(ui->comboBoxChoixArmoir, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &App::filtreArmoire);
    connect(ui->btnParametre, &QPushButton::clicked, this, &App::handleAfficheParam);
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

void App::afficherFormulaireModif(){
    CustomMessageBox msgBox;
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow < 0) {
        msgBox.showWarning("Erreur", "Veuillez sélectionner une ligne à modifier.");
        return;
    }
    QString titre = ui->tableWidget->item(selectedRow, 0)->text();
    QString genre = ui->tableWidget->item(selectedRow, 1)->text();
    QString auteur = ui->tableWidget->item(selectedRow, 2)->text();
    QString maison_edition = ui->tableWidget->item(selectedRow, 3)->text();
    QString proprietes = ui->tableWidget->item(selectedRow, 4)->text();
    int quantite = ui->tableWidget->item(selectedRow, 5)->text().toInt();
    QString armoire = ui->tableWidget->item(selectedRow, 6)->text();

    ModifierLivreForm *modifLivre = new ModifierLivreForm(titre, genre, auteur, maison_edition, proprietes, quantite, armoire, nullptr);
    connect(modifLivre, &ModifierLivreForm::modifieLivre, this, [=](const QString &nouvTitre, const QString &nouvGenre, const QString &nouvAuteur,
                                                                    const QString &nouvMaisonEdition, const QString &nouvProprietes, int nouvQuantite, const QString &nouvArmoire) {
        mettreAJourLigne(selectedRow, nouvTitre, nouvGenre, nouvAuteur, nouvMaisonEdition, nouvProprietes, nouvQuantite, nouvArmoire);
    });

    modifLivre->show();

}

void App::mettreAJourLigne(int ligne, const QString &titre, const QString &genre, const QString &auteur,
                           const QString &maisonEdition, const QString &proprietes, int quantite, const QString &armoire) {
    if (ligne < 0 || ligne >= ui->tableWidget->rowCount()) {
        qWarning() << "Index de ligne invalide:" << ligne;
        return;
    }

    ui->tableWidget->setItem(ligne, 0, new QTableWidgetItem(titre));
    ui->tableWidget->setItem(ligne, 1, new QTableWidgetItem(genre));
    ui->tableWidget->setItem(ligne, 2, new QTableWidgetItem(auteur));
    ui->tableWidget->setItem(ligne, 3, new QTableWidgetItem(maisonEdition));
    ui->tableWidget->setItem(ligne, 4, new QTableWidgetItem(proprietes));
    ui->tableWidget->setItem(ligne, 5, new QTableWidgetItem(QString::number(quantite)));
    ui->tableWidget->setItem(ligne, 6, new QTableWidgetItem(armoire));
}

void App::rechercheDeLivre(){
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineEditRecherche->text();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres WHERE titre LIKE :recherche OR genre LIKE :recherche OR auteur LIKE :recherche OR maison_edition LIKE :recherche OR proprietes LIKE :recherche OR armoire LIKE :recherche");
    query.bindValue(":recherche", "%" +recherche+"%");
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête";
        return;
    }
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Ajouter les résultats dans les colonnes
        QTableWidgetItem *titre = new QTableWidgetItem(query.value("titre").toString());
        QTableWidgetItem *genre = new QTableWidgetItem(query.value("genre").toString());
        QTableWidgetItem *auteur = new QTableWidgetItem(query.value("auteur").toString());
        QTableWidgetItem *maison_edition = new QTableWidgetItem(query.value("maison_edition").toString());
        QTableWidgetItem *proprietes = new QTableWidgetItem(query.value("proprietes").toString());
        QTableWidgetItem *quantite = new QTableWidgetItem(QString::number(query.value("quantite").toInt()));
        QTableWidgetItem *armoire = new QTableWidgetItem(query.value("armoire").toString());


        ui->tableWidget->setItem(row, 0, titre);
        ui->tableWidget->setItem(row, 1, genre);
        ui->tableWidget->setItem(row, 2, auteur);
        ui->tableWidget->setItem(row, 3, maison_edition);
        ui->tableWidget->setItem(row, 4, proprietes);
        ui->tableWidget->setItem(row, 5, quantite);
        ui->tableWidget->setItem(row, 6, armoire);


        row++;
    }
}

void App::filtreArmoire(){
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString selectedArmoire = ui->comboBoxChoixArmoir->currentText();

    // Préparer la requête SQL pour récupérer les livres en fonction de l'armoire sélectionnée
    QSqlQuery query(sqlitedb);
    if (selectedArmoire == "Tous") {
        // Requête pour afficher tous les livres
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres");
    } else {
        // Requête pour filtrer les livres selon l'armoire sélectionnée
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres WHERE armoire = :armoire");
        query.bindValue(":armoire", selectedArmoire);
    }

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:";
        return;
    }

    // Vider le tableau avant d'ajouter les nouveaux résultats
    ui->tableWidget->setRowCount(0);

    // Afficher les résultats dans le QTableWidget
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        QTableWidgetItem *titre = new QTableWidgetItem(query.value("titre").toString());
        QTableWidgetItem *auteur = new QTableWidgetItem(query.value("auteur").toString());
        QTableWidgetItem *genre = new QTableWidgetItem(query.value("genre").toString());
        QTableWidgetItem *maison_edition = new QTableWidgetItem(query.value("maison_edition").toString());
        QTableWidgetItem *proprietes = new QTableWidgetItem(query.value("proprietes").toString());
        QTableWidgetItem *quantite = new QTableWidgetItem(QString::number(query.value("quantite").toInt()));
        QTableWidgetItem *armoire = new QTableWidgetItem(query.value("armoire").toString());

        ui->tableWidget->setItem(row, 0, titre);
        ui->tableWidget->setItem(row, 2, auteur);
        ui->tableWidget->setItem(row, 1, genre);
        ui->tableWidget->setItem(row, 3, maison_edition);
        ui->tableWidget->setItem(row, 5, quantite);
        ui->tableWidget->setItem(row, 4, proprietes);
        ui->tableWidget->setItem(row, 6, armoire);


        row++;
    }
}

void App::handleAfficheParam(){
    Parametre *parametre = new Parametre(nullptr);
    connect(parametre, &Parametre::ajoutArmoir, this, &App::comboArmoireAfficher);
    parametre->show();
}

void App::comboArmoireAfficher() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    // Vérification de l'ouverture de la base de données
    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    // Préparation des objets QSqlQuery pour chaque requête
    QSqlQuery queryArmoire(sqlitedb);
    QSqlQuery queryGenre(sqlitedb);

    // Exécution de la première requête pour les armoires
    if (!queryArmoire.exec("SELECT armoire FROM armoires")) {
        msgBox.showError("Erreur", "Erreur lors de l'exécution de la requête sur les armoires");
        return;
    }

    // Exécution de la seconde requête pour les genres
    if (!queryGenre.exec("SELECT genre FROM genres")) {
        msgBox.showError("Erreur", "Erreur lors de l'exécution de la requête sur les genres");
        return;
    }

    // Vider les QComboBox
    ui->comboBoxChoixArmoir->clear();
    ui->comboBoxChoixGenre->clear();

    // Ajouter une option "Tous" pour chaque QComboBox
    ui->comboBoxChoixArmoir->addItem("Tous");
    ui->comboBoxChoixGenre->addItem("Tous");

    // Parcourir les résultats des armoires et ajouter chaque armoire au comboBoxChoixArmoir
    while (queryArmoire.next()) {
        QString armoire = queryArmoire.value("armoire").toString();
        ui->comboBoxChoixArmoir->addItem(armoire);
    }

    // Parcourir les résultats des genres et ajouter chaque genre au comboBoxChoixGenre
    while (queryGenre.next()) {
        QString genre = queryGenre.value("genre").toString();
        ui->comboBoxChoixGenre->addItem(genre);
    }
}

