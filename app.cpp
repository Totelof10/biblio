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
    afficherEmprunt();
    ajoutBtnTableauEmprunt();
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
    connect(ui->btnImporter, &QPushButton::clicked, this, &App::importerCsv);

    //Gestion Membre
    connect(ui->btnEnregistrerMembre, &QPushButton::clicked, this, &App::enregistrerMembre);
    connect(ui->lineRecherche, &QLineEdit::textChanged, this, &App::rechercheMembres);
    connect(ui->lineEditRechercheMembres, &QLineEdit::textChanged, this, &App::filtrageComboMembre);
    connect(ui->lineEditRechercheLivres, &QLineEdit::textChanged, this, &App::filtrageComboLivre);
    connect(ui->btnEnregistrerEmprunt, &QPushButton::clicked, this, &App::ajoutEmprunt);

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
    QDate currentDate = QDate::currentDate();
    ui->dateEditDebut->setDate(currentDate);
    ui->dateEditFin->setDate(currentDate);
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
    if (!query.exec("SELECT identifiant, titre, genre, auteur, maison_edition, proprietes, quantite, armoire FROM livres")) {
        msgBox.showError("Erreur", "Échec de l'exécution de la requête.");
        return;
    }

    // Vider le QTableWidget avant d'insérer les nouvelles données
    ui->tableWidget->setRowCount(0);

    // Configuration du QTableWidget (nombre de colonnes et labels des en-têtes)
    ui->tableWidget->setColumnCount(8); // 6 colonnes : titre, genre, auteur, maison_edition, proprietes, quantite
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"Identifiant"<< "Titre" << "Genre" << "Auteur"
                                                             << "Maison d'édition" << "Propriétés" << "Quantité"<<"Armoire");

    // Insertion des données dans le QTableWidget
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Récupération des données (sans l'ID)
        QString titre = query.value(1).toString();
        QString genre = query.value(2).toString();
        QString auteur = query.value(3).toString();
        QString maison_edition = query.value(4).toString();
        QString proprietes = query.value(5).toString();
        int quantite = query.value(6).toInt();
        QString armoire = query.value(7).toString();
        QString identifiant = query.value(0).toString();

        // Insertion des données dans le QTableWidget sans l'ID
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(titre));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(genre));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(auteur));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(maison_edition));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(proprietes));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(quantite)));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(armoire));
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(identifiant));

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
    QTableWidgetItem *identifiantItem = ui->tableWidget->item(selectedRow, 0); // Le titre est dans la première colonne
    if (!identifiantItem) {
        msgBox.showWarning("Erreur", "Impossible de récupérer le titre du livre.");
        return;
    }

    QString identifiant = identifiantItem->text();
    QTableWidgetItem *titre = ui->tableWidget->item(selectedRow, 1);
    QString tiTre = titre->text();
    QMessageBox confirmationBox;
    confirmationBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    confirmationBox.setText("Voulez-vous vraiment supprimer " +tiTre + " de la liste ?");
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

    // Connexion à la base de données
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();

    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'accéder à la base de données");
        return;
    }

    // Préparer la requête de suppression
    QSqlQuery query(sqlitedb);
    query.prepare("DELETE FROM livres WHERE identifiant = :identifiant");
    query.bindValue(":identifiant", identifiant);

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
    QString titre = ui->tableWidget->item(selectedRow, 1)->text();
    QString genre = ui->tableWidget->item(selectedRow, 2)->text();
    QString auteur = ui->tableWidget->item(selectedRow, 3)->text();
    QString maison_edition = ui->tableWidget->item(selectedRow, 4)->text();
    QString proprietes = ui->tableWidget->item(selectedRow, 5)->text();
    int quantite = ui->tableWidget->item(selectedRow, 6)->text().toInt();
    QString armoire = ui->tableWidget->item(selectedRow, 7)->text();
    QString identifiant = ui->tableWidget->item(selectedRow, 0)->text();

    ModifierLivreForm *modifLivre = new ModifierLivreForm(titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant, nullptr);
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

    ui->tableWidget->setItem(ligne, 1, new QTableWidgetItem(titre));
    ui->tableWidget->setItem(ligne, 2, new QTableWidgetItem(genre));
    ui->tableWidget->setItem(ligne, 3, new QTableWidgetItem(auteur));
    ui->tableWidget->setItem(ligne, 4, new QTableWidgetItem(maisonEdition));
    ui->tableWidget->setItem(ligne, 5, new QTableWidgetItem(proprietes));
    ui->tableWidget->setItem(ligne, 6, new QTableWidgetItem(QString::number(quantite)));
    ui->tableWidget->setItem(ligne, 7, new QTableWidgetItem(armoire));
}

void App::rechercheDeLivre(){
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineEditRecherche->text();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant FROM livres WHERE titre LIKE :recherche OR genre LIKE :recherche OR auteur LIKE :recherche OR maison_edition LIKE :recherche OR proprietes LIKE :recherche OR armoire LIKE :recherche OR identifiant LIKE :recherche");
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
        QTableWidgetItem *identifiant = new QTableWidgetItem(query.value("identifiant").toString());


        ui->tableWidget->setItem(row, 1, titre);
        ui->tableWidget->setItem(row, 2, genre);
        ui->tableWidget->setItem(row, 3, auteur);
        ui->tableWidget->setItem(row, 4, maison_edition);
        ui->tableWidget->setItem(row, 5, proprietes);
        ui->tableWidget->setItem(row, 6, quantite);
        ui->tableWidget->setItem(row, 7, armoire);
        ui->tableWidget->setItem(row, 0, identifiant);


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
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant FROM livres");
    } else {
        // Requête pour filtrer les livres selon l'armoire sélectionnée
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant FROM livres WHERE armoire = :armoire");
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
        QTableWidgetItem *identifiant = new QTableWidgetItem(query.value("identifiant").toString());

        ui->tableWidget->setItem(row, 1, titre);
        ui->tableWidget->setItem(row, 2, genre);
        ui->tableWidget->setItem(row, 3, auteur);
        ui->tableWidget->setItem(row, 4, maison_edition);
        ui->tableWidget->setItem(row, 5, proprietes);
        ui->tableWidget->setItem(row, 6, quantite);
        ui->tableWidget->setItem(row, 7, armoire);
        ui->tableWidget->setItem(row, 0, identifiant);


        row++;
    }
}

void App::filtreGenre(){
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString selectedGenre = ui->comboBoxChoixGenre->currentText();
    QSqlQuery query(sqlitedb);
    if (selectedGenre == "Tous") {
        // Requête pour afficher tous les livres
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant FROM livres");
    } else {
        // Requête pour filtrer les livres selon l'armoire sélectionnée
        query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant FROM livres WHERE genre = :genre");
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
        QTableWidgetItem *identifiant = new QTableWidgetItem(query.value("identifiant").toString());


        ui->tableWidget->setItem(row, 1, titre);
        ui->tableWidget->setItem(row, 2, genre);
        ui->tableWidget->setItem(row, 3, auteur);
        ui->tableWidget->setItem(row, 4, maison_edition);
        ui->tableWidget->setItem(row, 5, proprietes);
        ui->tableWidget->setItem(row, 6, quantite);
        ui->tableWidget->setItem(row, 7, armoire);
        ui->tableWidget->setItem(row, 0, identifiant);


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

void App::importerCsv(){
    CustomMessageBox msgBox;
    QString fichier = QFileDialog::getOpenFileName(this, tr("Ouvrir fichier CSV"), "", tr("Fichiers CSV(*.csv)"));
    if(fichier.isEmpty()){
        return;
    }
    QFile file(fichier);
    if(!file.open(QIODevice::ReadOnly)){
        msgBox.showWarning("Erreur", "Impossible d'ouvrir le fichier");
        return;
    }

    QTextStream in(&file);
    int ligne = 0;

    while (!in.atEnd()) {
        QString ligneTexte = in.readLine();
        qDebug() << "Ligne lue:" << ligneTexte;  // Affiche la ligne lue

        QStringList valeurs = ligneTexte.split(";");  // Assurez-vous d'utiliser "\t" si c'est le délimiteur
        qDebug() << "Valeurs extraites:" << valeurs;  // Affiche les valeurs extraites



        if (valeurs.size() != 8) {
            msgBox.showWarning("Erreur", QString("Format CSV incorrect à la ligne %1: %2 (attendu: 8 colonnes, obtenu: %3)")
                                             .arg(ligne + 1)
                                             .arg(ligneTexte)
                                             .arg(valeurs.size()));
            return;
        }

        // Assurez-vous de n'accéder à valeurs[] que si la taille est correcte
        QString titre = valeurs[1].trimmed();
        QString genre = valeurs[2].trimmed();
        QString auteur = valeurs[3].trimmed();
        QString maison_edition = valeurs[4].trimmed();
        QString proprietes = valeurs[5].trimmed();
        int quantite = valeurs[6].toInt();
        QString armoire = valeurs[7].trimmed();
        QString identifiant = valeurs[0].trimmed();
        qDebug() << "Insertion des données:" << identifiant << titre << genre << auteur << maison_edition << proprietes << quantite << armoire;


        DatabaseManager::enregistrerLivre(titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant);
        ligne++;
    }
    file.close();
    msgBox.showInformation("Succes", "Importation terminée");
    afficherLivreDansTableau();
}
//Gestion Membre
void App::enregistrerMembre(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString nom = ui->lineEditNom->text();
    QString prenoms = ui->lineEditPrenoms->text();
    QString statut = ui->radioAdulte->isChecked()? "Adulte":"Enfant";
    QString sexe = ui->radioSexeHomme->isChecked()?"Homme":"Femme";
    QString debut = ui->dateTimeEditDebut->date().toString("dd-MM-yyyy");
    QString fin = ui->dateTimeEditFin->date().toString("dd-MM-yyyy");
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

    // Récupérer le statut et le prénom du membre pour la ligne actuelle
    QString statutMembre = ui->tableWidget_2->item(row, 2)->text();
    QString prenoms = ui->tableWidget_2->item(row, 1)->text();

    // Calculer les nouvelles dates en fonction du statut
    QDate currentDate = QDate::currentDate();
    QDate newDateFin;

    if (statutMembre == "Adulte") {
        newDateFin = currentDate.addYears(1);
    } else if (statutMembre == "Enfant") {
        newDateFin = currentDate.addMonths(3);
    }

    // Demander confirmation avant de procéder à la modification
    QMessageBox confirmationBox;
    confirmationBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    confirmationBox.setText("Voulez-vous vraiment modifier les dates et le montant pour " + prenoms + " ?");
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

    // Si l'utilisateur a cliqué sur "OUI", continuer avec la modification des dates
    ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(currentDate.toString("dd-MM-yyyy")));
    ui->tableWidget_2->setItem(row, 5, new QTableWidgetItem(newDateFin.toString("dd-MM-yyyy")));

    // Récupérer le montant correspondant au statut dans la table statut_montants
    int montantStatut = 0;
    QSqlQuery queryStatutMontant(sqlitedb);
    queryStatutMontant.prepare("SELECT montant FROM statut_montants WHERE statut = :statut");
    queryStatutMontant.bindValue(":statut", statutMembre);

    if (queryStatutMontant.exec() && queryStatutMontant.next()) {
        // Si le statut dans membres correspond au statut dans statut_montants
        montantStatut = queryStatutMontant.value(0).toInt();
    } else {
        // Si aucun montant n'a été trouvé pour ce statut, afficher une erreur
        msgBox.showError("Erreur", "Aucun montant trouvé pour ce statut.");
        return;
    }

    // Récupérer le montant actuel du membre dans la table membres
    QSqlQuery queryMontant(sqlitedb);
    queryMontant.prepare("SELECT montant FROM membres WHERE prenoms = :prenoms AND statut = :statut");
    queryMontant.bindValue(":prenoms", prenoms);
    queryMontant.bindValue(":statut", statutMembre);

    int montantActuel = 0;
    if (queryMontant.exec() && queryMontant.next()) {
        montantActuel = queryMontant.value(0).toInt();
    } else {
        msgBox.showError("Erreur", "Erreur lors de la récupération du montant actuel.");
        qDebug() << queryMontant.lastError();
        return;
    }

    // Calculer le nouveau montant en ajoutant le montant récupéré pour le statut
    int nouveauMontant = montantActuel + montantStatut;

    // Mettre à jour le montant dans la table membres
    QSqlQuery queryUpdateMontant(sqlitedb);
    queryUpdateMontant.prepare("UPDATE membres SET montant = :montant WHERE prenoms = :prenoms AND statut = :statut");
    queryUpdateMontant.bindValue(":montant", nouveauMontant);
    queryUpdateMontant.bindValue(":prenoms", prenoms);
    queryUpdateMontant.bindValue(":statut", statutMembre);

    if (!queryUpdateMontant.exec()) {
        msgBox.showError("Erreur", "Erreur lors de la mise à jour du montant.");
        qDebug() << queryUpdateMontant.lastError();
        return;
    }

    // Mettre à jour la colonne Montant dans le QTableWidget
    ui->tableWidget_2->setItem(row, 8, new QTableWidgetItem(QString::number(nouveauMontant)));

    // Mettre à jour les dates dans la base de données
    QSqlQuery queryUpdateDates(sqlitedb);
    queryUpdateDates.prepare("UPDATE membres SET debut = :debut, fin = :fin WHERE prenoms = :prenoms AND statut = :statut");
    queryUpdateDates.bindValue(":debut", currentDate.toString("dd-MM-yyyy"));
    queryUpdateDates.bindValue(":fin", newDateFin.toString("dd-MM-yyyy"));
    queryUpdateDates.bindValue(":prenoms", prenoms);
    queryUpdateDates.bindValue(":statut", statutMembre);

    if (!queryUpdateDates.exec()) {
        msgBox.showError("Erreur", "Erreur lors de la mise à jour des dates.");
        qDebug() << queryUpdateDates.lastError();
    }

    // Mettre à jour la colonne "Validité" après modification des dates
    if (newDateFin >= currentDate) {
        ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::green));  // Valide
    } else {
        ui->tableWidget_2->item(row, 7)->setBackground(QBrush(Qt::red));    // Non valide
    }
}





void App::supprimerMembre(int row){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString prenoms = ui->tableWidget_2->item(row, 1)->text();
    QMessageBox confirmationBox;
    confirmationBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    confirmationBox.setText("Voulez-vous vraiment supprimer "+prenoms+" de la liste?");
    confirmationBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirmationBox.setIcon(QMessageBox::Question);

    // Appliquer le style personnalisé
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
    query.prepare("DELETE FROM membres WHERE prenoms = :prenoms");
    query.bindValue(":prenoms", prenoms);
    if(query.exec()){
        msgBox.showInformation("Succes", "Suppression réussie");
        ui->tableWidget_2->removeRow(row);
    }else{
        msgBox.showError("Erreur", "Erreur lors de la suppression"+query.lastError().text());
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
        msgBox.showError("Erreur", "Erreur lors du filtrage: "+query.lastError().text());
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
    query.prepare("SELECT titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant FROM livres WHERE titre LIKE :recherche");
    query.bindValue(":recherche", "%" +recherche+ "%");

    if (!query.exec()) {
        msgBox.showError("Erreur", "Erreur lors du filtrage: "+query.lastError().text());
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

void App::ajoutEmprunt(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString prenoms = ui->comboBoxMembres->currentText();
    QString livreTitre = ui->comboBoxLivres->currentText(); // Le titre du livre
    QString debut = ui->dateEditDebut->date().toString("dd-MM-yyyy");
    QString fin = ui->dateEditFin->date().toString("dd-MM-yyyy");

    // Récupérer l'id du membre
    QSqlQuery queryMembre(sqlitedb);
    queryMembre.prepare("SELECT id FROM membres WHERE prenoms = :prenoms");
    queryMembre.bindValue(":prenoms", prenoms);
    if(!queryMembre.exec()){
        qDebug() << queryMembre.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données du membre: "+queryMembre.lastError().text());
        return;
    }

    int idMembre = -1;
    if(queryMembre.next()){
        idMembre = queryMembre.value(0).toInt();
    }
    if(idMembre == -1){
        qDebug() << "Membre non trouvé";
        msgBox.showError("Erreur", "Membre non trouvé");
        return;
    }

    // Récupérer l'identifiant spécial du livre
    QSqlQuery queryLivre(sqlitedb);
    queryLivre.prepare("SELECT identifiant FROM livres WHERE titre = :titre");
    queryLivre.bindValue(":titre", livreTitre);
    if(!queryLivre.exec()){
        qDebug() << queryLivre.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données du livre: "+queryLivre.lastError().text());
        return;
    }

    QString idLivre;
    if(queryLivre.next()){
        idLivre = queryLivre.value(0).toString();
    }
    if(idLivre.isEmpty()){
        qDebug() << "Livre non trouvé";
        msgBox.showError("Erreur", "Livre non trouvé");
        return;
    }

    // Insertion dans la table emprunt
    QSqlQuery queryInsert(sqlitedb);
    queryInsert.prepare("INSERT INTO emprunt(id_membres, id_livres, debut, fin, emprunteur) VALUES (:id_membres, :id_livres, :debut, :fin, :emprunteur)");
    queryInsert.bindValue(":id_membres", idMembre);
    queryInsert.bindValue(":id_livres", idLivre);  // Utilisation de l'identifiant spécial du livre
    queryInsert.bindValue(":emprunteur", prenoms);
    queryInsert.bindValue(":debut", debut);
    queryInsert.bindValue(":fin", fin);

    if(!queryInsert.exec()){
        qDebug() << queryInsert.lastError();
        msgBox.showError("Erreur", "Erreur lors de l'enregistrement de l'emprunt: "+queryInsert.lastError().text());
    }else{
        msgBox.showInformation("Succès", "Emprunt enregistré avec succès");
    }

    // Nettoyer le formulaire et mettre à jour la table
    clearFormEmprunt();
    afficherEmprunt();
    ajoutBtnTableauEmprunt();
}



void App::clearFormEmprunt(){
    ui->comboBoxMembres->setCurrentIndex(0);
    ui->comboBoxLivres->setCurrentIndex(0);
}

void App::ajoutBtnTableauEmprunt(){
    int rowCount = ui->tableWidget_3->rowCount();
    for(int row = 0; row < rowCount; ++row){
        QPushButton* btnSupprimer = new QPushButton("Supprimer", this);

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
        btnSupprimer->setStyleSheet(buttonStyle2);

        ui->tableWidget_3->setCellWidget(row, 5, btnSupprimer);

        // Utiliser un lambda sans capturer directement 'row'
        connect(btnSupprimer, &QPushButton::clicked, this, [this, btnSupprimer]() {
            // Récupérer dynamiquement l'index de la ligne en fonction du bouton cliqué
            int row = ui->tableWidget_3->indexAt(btnSupprimer->parentWidget()->pos()).row();
            supprimerEmprunt(row);
        });
    }
}


void App::afficherEmprunt(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    if (!sqlitedb.open()) {
        msgBox.showError("Erreur", "Impossible d'ouvrir la base de données");
        return;
    }
    QSqlQuery query(sqlitedb);
    if(!query.exec("SELECT id_livres, debut, fin, emprunteur, id FROM emprunt")){
        msgBox.showError("Erreur", "Erreur lors de la récupération de la base de données"+query.lastError().text());
        qDebug() << query.lastError();
        return;
    }

    ui->tableWidget_3->setRowCount(0);
    int row = 0;
    while(query.next()){
        ui->tableWidget_3->insertRow(row);

        QString idLivre = query.value(0).toString();
        QString debut = query.value(1).toString();
        QString fin = query.value(2).toString();
        QString emprunteur = query.value(3).toString();
        QString id = query.value(4).toString();

        // Récupérer le titre du livre à partir de id_livres
        QSqlQuery queryTitre(sqlitedb);
        queryTitre.prepare("SELECT titre FROM livres WHERE identifiant = :identifiant");
        queryTitre.bindValue(":identifiant", idLivre);
        QString titreLivre;
        if(queryTitre.exec() && queryTitre.next()){
            titreLivre = queryTitre.value(0).toString();
        } else {
            titreLivre = "Inconnu";  // Si le titre n'est pas trouvé
            qDebug() << queryTitre.lastError();
        }

        // Remplir les colonnes du tableau
        ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(titreLivre));  // Affichage du titre
        ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(debut));
        ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(fin));
        ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(emprunteur));
        ui->tableWidget_3->setItem(row, 4, new QTableWidgetItem(""));  // Colonne colorée
        ui->tableWidget_3->setColumnHidden(6, true);  // Masquer la colonne id
        ui->tableWidget_3->setItem(row, 6, new QTableWidgetItem(id));  // Stocker l'id pour référence

        // Vérification de la validité des dates et coloration de la cellule
        QDate dateFin = QDate::fromString(fin, "dd-MM-yyyy");
        QDate currentDate = QDate::currentDate();

        if (dateFin.isValid()) {
            if (currentDate <= dateFin) {
                ui->tableWidget_3->item(row, 4)->setBackground(QBrush(Qt::green));  // Valide
            } else {
                ui->tableWidget_3->item(row, 4)->setBackground(QBrush(Qt::red));    // Non valide
            }
        } else {
            ui->tableWidget_3->item(row, 4)->setBackground(QBrush(Qt::red));        // Date invalide
        }

        row++;
    }
}

void App::supprimerEmprunt(int row){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString titre = ui->tableWidget_3->item(row, 0)->text();
    QString debut = ui->tableWidget_3->item(row, 1)->text();
    QString fin = ui->tableWidget_3->item(row, 2)->text();
    QString emprunteur = ui->tableWidget_3->item(row, 3)->text();
    QString id = ui->tableWidget_3->item(row, 6)->text();
    QDate currentDate = QDate::currentDate();
    QMessageBox confirmationBox;
    confirmationBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    confirmationBox.setText("Voulez-vous vraiment supprimer l'emprunt de " + titre + " par "+emprunteur+" et le mettre dans l'historique des emprunts?");
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

    QSqlQuery queryBeforeDelete(sqlitedb);
    queryBeforeDelete.prepare("INSERT INTO historique_emprunt (id_emprunt, emprunteur, livre, debut, fin, date_suppression) VALUES (?,?,?,?,?,?)");
    queryBeforeDelete.addBindValue(id);
    queryBeforeDelete.addBindValue(emprunteur);
    queryBeforeDelete.addBindValue(titre);
    queryBeforeDelete.addBindValue(debut);
    queryBeforeDelete.addBindValue(fin);
    queryBeforeDelete.addBindValue(currentDate);
    if(queryBeforeDelete.exec()){
        QSqlQuery queryDelete(sqlitedb);
        queryDelete.prepare("DELETE FROM emprunt WHERE id = :id");
        queryDelete.bindValue(":id", id);
        if(queryDelete.exec()){
            msgBox.showInformation("Succes", "Suppression réussie");
            ui->tableWidget_3->removeRow(row);
        }else{
            msgBox.showError("Erreur", "Erreur lors de la suppression"+queryDelete.lastError().text());
            qDebug()<<"Erreur lors de la suppresion "<<queryDelete.lastError();
        }
    }else{
        msgBox.showError("Erreur", "Erreur lors de l'insertion dans l'historique:"+queryBeforeDelete.lastError().text());
    }


}


