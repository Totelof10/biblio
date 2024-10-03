#include "app.h"
#include "ui_app.h"
#include "ajoutlivreform.h"
#include "databasemanager.h"
#include "custommessagebox.h"
#include "modifierlivreform.h"
#include "parametre.h"
#include "deconnexion.h"

App::App(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);

    comboArmoireAfficher();
    comboBoxEmprunt();
    afficherLivreDansTableau();
    afficherMembreDansTableau();
    ajoutBtnTableau();
    ui->stackedWidget->setCurrentWidget(ui->pageAccueil);
    connect(ui->btnDeconnexion, &QPushButton::clicked, this, &App::deconnexion);
    connect(ui->btnAccueil, &QPushButton::clicked, this, &App::handleAccueil);
    connect(ui->btnLivre, &QPushButton::clicked, this, &App::handleLivre);
    connect(ui->btnMembre, &QPushButton::clicked, this, &App::handleMembre);
    connect(ui->btnEmprunt, &QPushButton::clicked, this, &App::handleEmprunt);
    connect(ui->btnAjouterLivre, &QPushButton::clicked, this, &App::handleAfficherAjoutLivreForm);
    connect(ui->btnSupprimerLivre, &QPushButton::clicked, this, &App::supprimerLivre);
    connect(ui->btnModifierLivre, &QPushButton::clicked, this, &App::afficherFormulaireModif);
    connect (ui->btnRecherche, &QPushButton::clicked, this, &App::rechercheDeLivre);
    connect (ui->lineEditRecherche, &QLineEdit::textChanged, this, &App::rechercheDeLivre);
    connect(ui->comboBoxChoixArmoir, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &App::filtreArmoire);
    connect(ui->btnParametre, &QPushButton::clicked, this, &App::handleAfficheParam);
    connect(ui->comboBoxChoixGenre, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &App::filtreGenre);

    //Gestion Membre
    connect(ui->btnEnregistrerMembre, &QPushButton::clicked, this, &App::enregistrerMembre);
    connect(ui->lineRecherche, &QLineEdit::textChanged, this, &App::rechercheMembres);
    connect(ui->lineEditRechercheMembres, &QLineEdit::textChanged, this, &App::filtrageComboMembre);
    connect(ui->lineEditRechercheLivres, &QLineEdit::textChanged, this, &App::filtrageComboLivre);

}

App::~App()
{
    delete ui;
}

void App::handleAccueil(){
    ui->stackedWidget->setCurrentWidget(ui->pageAccueil);
}
//Auth
void App::deconnexion(){
    Deconnexion *deconnexion = new Deconnexion(this, this);  // 'this' est la fenêtre parent, 'appWindow' est l'instance de App
    deconnexion->show();

}
//Gestion Livre
void App::handleLivre(){
    ui->stackedWidget->setCurrentWidget(ui->pageLivre);

}

void App::handleMembre(){
    ui->stackedWidget->setCurrentWidget(ui->pageMembre);
}

void App::handleEmprunt(){
    ui->stackedWidget->setCurrentWidget(ui->pageEmprunt);
    comboBoxEmprunt();
    //afficherLivreDansTableau();
    //afficherMembreDansTableau();
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

void App::filtreGenre(){
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString selectedGenre = ui->comboBoxChoixGenre->currentText();
    QSqlQuery query(sqlitedb);
    if (selectedGenre == "Tous") {
        // Requête pour afficher tous les livres
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres");
    } else {
        // Requête pour filtrer les livres selon l'armoire sélectionnée
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres WHERE genre = :genre");
        query.bindValue(":genre", selectedGenre);
    }
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:";
        return;
    }

    // Vider le tableau avant d'ajouter les nouveaux résultats
    ui->tableWidget->setRowCount(0);
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

//Gestion Membre
void App::enregistrerMembre(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString nom = ui->lineEditNom->text();
    QString prenoms = ui->lineEditPrenoms->text();
    QString statut = ui->radioAdulte->isChecked()? "Adulte":"Enfant";
    QString sexe = ui->radioSexeHomme->isChecked()?"Homme":"Femme";
    QString debut = ui->dateTimeEditDebut->dateTime().toString("dd-MM-yyyy");
    QString fin = ui->dateTimeEditFin->dateTime().toString("dd-MM-yyyy");
    QString contact = ui->lineEditContact->text();

    if(nom.isEmpty()||prenoms.isEmpty()){
        msgBox.showWarning("Erreur", "Veuillez remplir les champs");
    }else{
        QSqlQuery query(sqlitedb);
        query.prepare("INSERT INTO membres (nom, prenoms, statut, sexe, debut, fin, contact) VALUES(:nom, :prenoms, :statut, :sexe, :debut, :fin, :contact)");
        query.bindValue(":nom", nom);
        query.bindValue(":prenoms", prenoms);
        query.bindValue(":statut", statut);
        query.bindValue(":sexe", sexe);
        query.bindValue(":debut", debut);
        query.bindValue(":fin", fin);
        query.bindValue(":contact", contact);

        if(!query.exec()){
            msgBox.showError("Erreur", "Erreur lors de l'ajout du membre");
            qDebug() <<query.lastError();
        }else{
            msgBox.showInformation("Succes", "Ajout réussi!!");
            qDebug() <<"okk";
            clearForm();
        }
        emit ajoutMemebre();
        afficherMembreDansTableau();
        ajoutBtnTableau();
    }


}

void App::afficherMembreDansTableau() {
    CustomMessageBox msgBox;

    // Récupère la base de données via DatabaseManager
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    // Préparation et exécution de la requête SQL
    QSqlQuery query(sqlitedb);
    if (!query.exec("SELECT nom, prenoms, statut, sexe, debut, fin , montant, contact FROM membres")) {
        msgBox.showError("Erreur", "Échec de l'exécution de la requête.");
        return;
    }

    // Vider le QTableWidget avant d'insérer les nouvelles données
    ui->tableWidget_2->setRowCount(0);

    // Insertion des données dans le QTableWidget
    int row = 0;
    while (query.next()) {
        ui->tableWidget_2->insertRow(row);

        // Récupération des données (sans l'ID)
        QString nom = query.value(0).toString();
        QString prenoms = query.value(1).toString();
        QString statut = query.value(2).toString();
        QString sexe = query.value(3).toString();
        QString debut = query.value(4).toString();
        QString fin = query.value(5).toString();
        QString montant = query.value(6).toString();
        QString contact = query.value(7).toString();

        // Insertion des données dans le QTableWidget
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(nom));        // Colonne 0: nom
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(prenoms));    // Colonne 1: prenoms
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(statut));     // Colonne 2: statut
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(sexe));       // Colonne 3: sexe
        ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(debut));      // Colonne 4: debut
        ui->tableWidget_2->setItem(row, 5, new QTableWidgetItem(fin));         // Colonne 5: fin
        ui->tableWidget_2->setItem(row, 6, new QTableWidgetItem(contact));     // Colonne 6: contact
        ui->tableWidget_2->setItem(row, 7, new QTableWidgetItem(""));          // Colonne 7: validité (champ vide)
        ui->tableWidget_2->setItem(row, 8, new QTableWidgetItem(montant));     // Colonne 8: montant


        // Convertir les dates de début et de fin
        //QDate dateDebut = QDate::fromString(debut, "dd-MM-yyyy");
        QDate dateFin = QDate::fromString(fin, "dd-MM-yyyy");
        QDate currentDate = QDate::currentDate();

        // Vérifier si la date actuelle est dans la plage
        if (/*dateDebut.isValid() &&*/dateFin.isValid()) {
            if (/*currentDate >= dateDebut && */currentDate <= dateFin) {
                // Colorer en vert (validité)
                ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::green));
            } else {
                // Colorer en rouge (non valide)
                ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));
            }
        } else {
            // Si la date est invalide, colorer en rouge également
            ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));
        }

        row++;
    }
}


void App::ajoutBtnTableau(){
    int rowCount = ui->tableWidget_2->rowCount();
    for(int row = 0; row < rowCount; ++row){
        QPushButton* btnModifier = new QPushButton("Renouveler", this);
        QPushButton* btnSupprimer = new QPushButton("Supprimer", this);
        QString buttonStyle = "QPushButton{"
                              "border: 1px solid white;"
                              "border-radius: 7px;"
                              "background-color: #FFA823;"
                              "color: white;"
                              "padding: 7px;"
                              "}"
                              "QPushButton:hover{"
                              "background-color: #FFD35A;"
                              "}";
        QString buttonStyle2 = "QPushButton{"
                              "border: 1px solid white;"
                              "border-radius: 7px;"
                              "background-color: #821131;"
                              "color: white;"
                              "padding: 7px;"
                              "}"
                              "QPushButton:hover{"
                              "background-color: #C7253E;"
                              "}";
        btnModifier->setStyleSheet(buttonStyle);
        btnSupprimer->setStyleSheet(buttonStyle2);

        ui->tableWidget_2->setCellWidget(row, 9, btnModifier);
        ui->tableWidget_2->setCellWidget(row, 10, btnSupprimer);

        // Gestion de la modification
        connect(btnModifier, &QPushButton::clicked, this, [this, row]() {
            modifierDates(row);
        });

        // Gestion de la suppression
        connect(btnSupprimer, &QPushButton::clicked, this, [this, row]() {
            supprimerMembre(row);
        });
    }
}

void App::modifierDates(int row) {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    // Récupérer le statut et l'ID du membre pour la ligne actuelle
    QString statut = ui->tableWidget_2->item(row, 2)->text();
    QString prenoms = ui->tableWidget_2->item(row, 1)->text(); // Suppose que l'ID est dans la colonne 0

    // Calculer les nouvelles dates en fonction du statut
    QDate currentDate = QDate::currentDate();
    QDate newDateFin;

    if (statut == "Adulte") {
        // Date actuelle + 1 an pour les adultes
        newDateFin = currentDate.addYears(1);
    } else if (statut == "Enfant") {
        // Date actuelle + 3 mois pour les enfants
        newDateFin = currentDate.addMonths(3);
    }

    // Mettre à jour les valeurs dans le QTableWidget
    ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(currentDate.toString("dd-MM-yyyy")));
    ui->tableWidget_2->setItem(row, 5, new QTableWidgetItem(newDateFin.toString("dd-MM-yyyy")));

    // Récupérer le montant actuel pour ce membre spécifique avec son ID unique
    QSqlQuery queryMontant(sqlitedb);
    queryMontant.prepare("SELECT montant FROM membres WHERE prenoms = :prenoms");
    queryMontant.bindValue(":prenoms", prenoms);  // Utiliser l'ID pour identifier le membre

    int montantActuel = 0;
    if (queryMontant.exec()) {
        if (queryMontant.next()) {
            montantActuel = queryMontant.value(0).toInt();  // Montant actuel du membre en question
        }
    } else {
        msgBox.showError("Erreur", "Erreur lors de la récupération du montant actuel.");
        qDebug() << queryMontant.lastError();
        return;
    }

    // 2. Calculer le nouveau montant (incrémenter en fonction du statut)
    int increment = 0;
    if (statut == "Adulte") {
        increment = 15000;
    } else if (statut == "Enfant") {
        increment = 3000;
    }

    int nouveauMontant = montantActuel + increment;  // Montant spécifique pour ce membre

    // 3. Mettre à jour le champ montant dans la base de données pour ce membre (ligne spécifique)
    QSqlQuery queryUpdateMontant(sqlitedb);
    queryUpdateMontant.prepare("UPDATE membres SET montant = :montant WHERE prenoms = :prenoms");
    queryUpdateMontant.bindValue(":montant", nouveauMontant);
    queryUpdateMontant.bindValue(":prenoms", prenoms);  // Utiliser l'ID pour identifier le membre

    if (!queryUpdateMontant.exec()) {
        msgBox.showError("Erreur", "Erreur lors de la mise à jour du montant.");
        qDebug() << queryUpdateMontant.lastError();
        return;
    }

    // 4. Mettre à jour la colonne Montant dans le QTableWidget (Colonne 8) pour la ligne courante
    ui->tableWidget_2->setItem(row, 8, new QTableWidgetItem(QString::number(nouveauMontant)));

    // Mettre à jour la base de données avec les nouvelles dates
    QSqlQuery query(sqlitedb);
    query.prepare("UPDATE membres SET debut = :debut, fin = :fin WHERE prenoms = :prenoms");
    query.bindValue(":debut", currentDate.toString("dd-MM-yyyy"));
    query.bindValue(":fin", newDateFin.toString("dd-MM-yyyy"));
    query.bindValue(":prenoms", prenoms);  // Utiliser l'ID pour identifier le membre

    if (query.exec()) {
        msgBox.showInformation("Succès", "Les dates et le montant ont été mis à jour.");
    } else {
        msgBox.showError("Erreur", "Erreur lors de la mise à jour des dates.");
        qDebug() << query.lastError();
    }

    // Mettre à jour la colonne "Validité" après modification des dates
    QDate dateFin = QDate::fromString(newDateFin.toString("dd-MM-yyyy"), "dd-MM-yyyy");

    if (dateFin.isValid()) {
        if (currentDate <= dateFin) {
            // Colorer en vert (validité)
            ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::green));
        } else {
            // Colorer en rouge (non valide)
            ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));
        }
    } else {
        // Si la date est invalide, colorer en rouge également
        ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));
    }
}




void App::supprimerMembre(int row){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString prenoms = ui->tableWidget_2->item(row, 1)->text();
    QSqlQuery query(sqlitedb);
    query.prepare("DELETE FROM membres WHERE prenoms = :prenoms");
    query.bindValue(":prenoms", prenoms);
    if(query.exec()){
        msgBox.showInformation("Succes", "Suppression réussie");
        ui->tableWidget_2->removeRow(row);
    }else{
        msgBox.showError("Erreur", "Erreur lors de la suppression");
        qDebug()<<"Erreur lors de la suppresion "<<query.lastError();
    }

}
void App::clearForm(){
    ui->lineEditNom->clear();
    ui->lineEditPrenoms->clear();
    ui->lineEditContact->clear();

    // Réinitialise les champs QDateTimeEdit à la date actuelle ou une autre valeur par défaut
    //ui->dateTimeEditDebut->setDateTime(QDateTime::currentDateTime());
    //ui->dateTimeEditFin->setDateTime(QDateTime::currentDateTime());

    // Déselectionner les QRadioButton
    ui->radioAdulte->setAutoExclusive(false);
    ui->radioEnfant->setAutoExclusive(false);
    ui->radioSexeHomme->setAutoExclusive(false);
    ui->radioSexeFemme->setAutoExclusive(false);

    ui->radioAdulte->setChecked(false);
    ui->radioEnfant->setChecked(false);
    ui->radioSexeHomme->setChecked(false);
    ui->radioSexeFemme->setChecked(false);

    // Réactiver le comportement exclusif pour les QRadioButton
    ui->radioAdulte->setAutoExclusive(true);
    ui->radioEnfant->setAutoExclusive(true);
    ui->radioSexeHomme->setAutoExclusive(true);
    ui->radioSexeFemme->setAutoExclusive(true);
}

void App::rechercheMembres(){
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineRecherche->text();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT nom, prenoms, statut, sexe, debut, fin, montant FROM membres WHERE (nom || ' ' || prenoms) LIKE :recherche");
    query.bindValue(":recherche", "%" +recherche+ "%");
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête" << query.lastError();
        return;
    }
    ui->tableWidget_2->setRowCount(0);
    int row = 0;
    while(query.next()){
        ui->tableWidget_2->insertRow(row);
        QTableWidgetItem *nom = new QTableWidgetItem(query.value("nom").toString());
        QTableWidgetItem *prenoms = new QTableWidgetItem(query.value("prenoms").toString());
        QTableWidgetItem *statut = new QTableWidgetItem(query.value("statut").toString());
        QTableWidgetItem *sexe = new QTableWidgetItem(query.value("sexe").toString());
        QTableWidgetItem *debut = new QTableWidgetItem(query.value("debut").toString());
        QTableWidgetItem *fin = new QTableWidgetItem(query.value("fin").toString());
        QTableWidgetItem *montant = new QTableWidgetItem(query.value("montant").toString());

        ui->tableWidget_2->setItem(row, 0, nom);
        ui->tableWidget_2->setItem(row, 1, prenoms);
        ui->tableWidget_2->setItem(row, 2, statut);
        ui->tableWidget_2->setItem(row, 3, sexe);
        ui->tableWidget_2->setItem(row, 4, debut);
        ui->tableWidget_2->setItem(row, 5, fin);
        ui->tableWidget_2->setItem(row, 8, montant);

        // Ajouter la colonne "Validité" (colonne 6)
        ui->tableWidget_2->setItem(row, 7, new QTableWidgetItem(""));

        // Convertir les dates de début et de fin
        //QDate dateDebut = QDate::fromString(debut, "dd-MM-yyyy");
        QDate dateFin = QDate::fromString(query.value("fin").toString(), "dd-MM-yyyy");
        QDate currentDate = QDate::currentDate();

        // Vérifier si la date actuelle est dans la plage
        if (/*dateDebut.isValid() &&*/dateFin.isValid()) {
            if (/*currentDate >= dateDebut && */currentDate <= dateFin) {
                // Colorer en vert (validité)
                ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::green));
            } else {
                // Colorer en rouge (non valide)
                ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));
            }
        } else {
            // Si la date est invalide, colorer en rouge également
            ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));
        }

        row++;

    }
    ajoutBtnTableau();
}

void App::comboBoxEmprunt() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    QSqlQuery queryMembre(sqlitedb);
    QSqlQuery queryLivres(sqlitedb);

    if (!queryMembre.exec("SELECT prenoms FROM membres")) {
        msgBox.showError("Erreur", "Erreur lors de l'exécution de la requête pour les membres.");
        qDebug() << queryMembre.lastError();
        return;
    }

    if (!queryLivres.exec("SELECT titre FROM livres WHERE quantite > 0")) {
        msgBox.showError("Erreur", "Erreur lors de l'exécution de la requête pour les livres.");
        qDebug() << queryLivres.lastError();
        return;
    }

    // Clear existing items
    ui->comboBoxMembres->clear();
    ui->comboBoxLivres->clear();

    // Add placeholder items
    ui->comboBoxMembres->addItem("Séléction");
    ui->comboBoxLivres->addItem("Séléction");

    // Populate comboBoxMembres with prenoms
    while (queryMembre.next()) {
        QString membre = queryMembre.value("prenoms").toString();
        ui->comboBoxMembres->addItem(membre);
    }

    // Populate comboBoxLivres with titres
    while (queryLivres.next()) {
        QString livre = queryLivres.value("titre").toString();
        ui->comboBoxLivres->addItem(livre);
    }
}

void App::filtrageComboMembre(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineEditRechercheMembres->text();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT nom, prenoms, statut, sexe, debut, fin, montant FROM membres WHERE (nom || ' ' || prenoms) LIKE :recherche");
    query.bindValue(":recherche", "%" +recherche+ "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête" << query.lastError();
        return;
    }

    // Vider le comboBox avant de le remplir
    ui->comboBoxMembres->clear();

    // Ajouter les résultats au comboBox
    while(query.next()){
        QString nomComplet = query.value("nom").toString() + " " + query.value("prenoms").toString();
        ui->comboBoxMembres->addItem(nomComplet);
    }
}

void App::filtrageComboLivre(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineEditRechercheLivres->text();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres WHERE titre LIKE :recherche");
    query.bindValue(":recherche", "%" +recherche+ "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête" << query.lastError();
        return;
    }

    // Vider le comboBox avant de le remplir
    ui->comboBoxLivres->clear();

    // Ajouter les résultats au comboBox
    while(query.next()){
        QString titre = query.value("titre").toString();
        ui->comboBoxLivres->addItem(titre);
    }
}





