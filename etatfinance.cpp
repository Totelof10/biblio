#include "etatfinance.h"
#include "ui_etatfinance.h"
#include "databasemanager.h"
#include "custommessagebox.h"

EtatFinance::EtatFinance(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EtatFinance)
{
    ui->setupUi(this);
    // Initialisez les graphiques et séries
    /*chartGlobal = new QChart();
    seriesGlobal = new QLineSeries();
    chartGlobal->addSeries(seriesGlobal);
    chartGlobal->createDefaultAxes();
    chartGlobal->setTitle("Total des abonnements par date");

    chartMois = new QChart();
    seriesMois = new QBarSeries();
    chartMois->addSeries(seriesMois);
    chartMois->setTitle("Total des abonnements par mois");

    // Créez des vues de graphiques
    QChartView *chartViewGlobal = new QChartView(chartGlobal);
    chartViewGlobal->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_4->addWidget(chartViewGlobal);

    QChartView *chartViewMois = new QChartView(chartMois);
    chartViewMois->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_5->addWidget(chartViewMois); // Assurez-vous d'avoir un autre layout pour le graphique par mois*/
    ui->stackedWidget->setCurrentWidget(ui->page);
    afficherLesAbonnements();
    somme();
    ui->btnGraph->setEnabled(false);
    connect(ui->btnGraph, &QPushButton::clicked, this, &EtatFinance::afficherGraph);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &EtatFinance::recherche);
    // Dans le constructeur ou une méthode d'initialisation
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &EtatFinance::onDateChanged);
    connect(ui->dateEdit_2, &QDateEdit::dateChanged, this, &EtatFinance::onDateChanged);
    connect(ui->btnClearForm, &QPushButton::clicked, this, &EtatFinance::clear);
    //connect(ui->btnRetour, &QPushButton::clicked, this, &EtatFinance::retour);

}

EtatFinance::~EtatFinance()
{
    delete ui;
}

void EtatFinance::clear(){
    ui->lineEdit->clear();
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit_2->setDateTime(QDateTime::currentDateTime());
    afficherLesAbonnements();
    somme();
}
/*void EtatFinance::retour(){
    ui->stackedWidget->setCurrentWidget(ui->page);
    afficherLesAbonnements();
    somme();
}*/

void EtatFinance::afficherLesAbonnements(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT id, membres, montants, date_paiement FROM abonnement");
    if(!query.exec()){
        qDebug()<<query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données "+query.lastError().text());
        return;
    }
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while(query.next()){
        ui->tableWidget->insertRow(row);
        QString id = query.value(0).toString();
        QString membres = query.value(1).toString();
        QString montants = query.value(2).toString();
        QString date_paiement = query.value(3).toString();

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(membres));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(montants));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(date_paiement));

        row++;
    }
}

void EtatFinance::recherche() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineEdit->text();
    if (recherche.isEmpty()) {
        somme();  // Appelle la fonction somme() si lineEdit est vide
        return;    // Sort de la fonction
    }
    QSqlQuery query(sqlitedb);

    // Requête pour récupérer les abonnements correspondant à la recherche
    query.prepare("SELECT id, membres, montants, date_paiement, SUM(montants) "
                  "FROM abonnement WHERE membres LIKE :recherche GROUP BY membres");
    query.bindValue(":recherche", "%" + recherche + "%");

    if (!query.exec()) {
        qDebug() << query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données " + query.lastError().text());
        return;
    }

    ui->tableWidget->setRowCount(0);
    int row = 0;
    QString totalSomme;  // Variable pour stocker la somme totale

    while (query.next()) {
        ui->tableWidget->insertRow(row);
        QString id = query.value(0).toString();
        QString membres = query.value(1).toString();
        QString montants = query.value(2).toString();
        QString date_paiement = query.value(3).toString();

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(membres));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(montants));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(date_paiement));

        // Récupère la somme des montants pour le membre
        totalSomme = query.value(4).toString();
        row++;
    }

    // Affiche la somme totale après avoir rempli le tableau
    if (!totalSomme.isEmpty()) {
        ui->labelTotal->setText(totalSomme + " Ar");  // Affiche la somme avec "Ar"
    } else {
        ui->labelTotal->setText("0 Ar");  // Si aucune somme n'est trouvée
    }
}


void EtatFinance::afficherGraph(){
    //afficherGraphiqueGlobal(); // Appelle la méthode pour le graphique global
    //afficherGraphiqueParMois(); // Appelle la méthode pour le graphique par mois
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void EtatFinance::somme(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT SUM(montants) FROM abonnement");
    if(!query.exec()){
        qDebug()<<query.lastError();
        msgBox.showError("Erreur", "Erreur de calcul "+query.lastError().text());
        return;
    }
    if (!query.exec()) {
        qDebug() << query.lastError();
        msgBox.showError("Erreur", "Erreur de calcul: " + query.lastError().text());
        return;
    }

    if (query.next()) {  // Vérifie si la requête a renvoyé une ligne
        QString somme = query.value(0).toString();  // Récupère la somme
        ui->labelTotal->setText(somme + " Ar");  // Affiche la somme avec "Ar"
    } else {
        // Cas où il n'y a pas de résultats (s'il n'y a pas de montants ou de lignes correspondantes)
        msgBox.showError("Information", "Aucun montant trouvé.");
        ui->labelTotal->setText("0 Ar");
    }
}

void EtatFinance::onDateChanged(const QDate &date) {
    // Vous pouvez récupérer les dates actuelles des deux QDateEdit et appeler la fonction pour calculer la somme
    QString dateDebut = ui->dateEdit->date().toString("dd-MM-yyyy");
    QString dateFin = ui->dateEdit_2->date().toString("dd-MM-yyyy");

    sommeParDates();  // Appelez la fonction pour mettre à jour la somme en fonction des nouvelles dates
}


void EtatFinance::sommeParDates() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);

    // Récupérer les dates à partir des QDateEdit et les convertir en format dd-MM-yyyy
    QString dateDebut = ui->dateEdit->date().toString("dd-MM-yyyy");
    QString dateFin = ui->dateEdit_2->date().toString("dd-MM-yyyy");

    // Préparer la requête SQL avec les dates au format texte
    query.prepare("SELECT SUM(montants) FROM abonnement WHERE date_paiement >= :dateDebut AND date_paiement <= :dateFin");

    // Assigner les valeurs des dates
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);

    if (!query.exec()) {
        qDebug() << query.lastError();
        msgBox.showError("Erreur", "Erreur de calcul: " + query.lastError().text());
        return;
    }

    if (query.next()) {  // Vérifie si la requête renvoie une ligne
        QString somme = query.value(0).toString();  // Récupère la somme
        ui->labelTotal->setText(somme + " Ar");  // Affiche la somme avec "Ar"
    } else {
        // Cas où il n'y a pas de résultats
        msgBox.showError("Information", "Aucun montant trouvé dans cette période.");
        ui->labelTotal->setText("0 Ar");
    }

    QSqlQuery queryAffichage(sqlitedb);
    queryAffichage.prepare("SELECT id, membres, montants, date_paiement FROM abonnement WHERE date_paiement >= :dateDebut AND date_paiement <= :dateFin");
    queryAffichage.bindValue(":dateDebut", dateDebut);
    queryAffichage.bindValue(":dateFin", dateFin);
    if(!queryAffichage.exec()){
        msgBox.showError("Erreur", "Erreur lors de la récupération des données "+queryAffichage.lastError().text());
        return;
    }
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while(queryAffichage.next()){
        ui->tableWidget->insertRow(row);
        QString id = queryAffichage.value(0).toString();
        QString membres = queryAffichage.value(1).toString();
        QString montants = queryAffichage.value(2).toString();
        QString date_paiement = queryAffichage.value(3).toString();

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(membres));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(montants));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(date_paiement));

        qDebug()<<date_paiement;

        row++;
    }

}

/*void EtatFinance::afficherGraphiqueGlobal() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);

    // Récupérer les abonnements
    query.prepare("SELECT date_paiement, SUM(montants) FROM abonnement GROUP BY date_paiement");
    if (!query.exec()) {
        qDebug() << query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données " + query.lastError().text());
        return;
    }

    seriesGlobal->clear(); // Effacez les données précédentes

    while (query.next()) {
        QString date = query.value(0).toString();
        double montant = query.value(1).toDouble();

        // Convertir la date en format numérique pour l'axe des x
        QDate qdate = QDate::fromString(date, "dd-MM-yyyy");
        if (qdate.isValid()) {
            seriesGlobal->append(qdate.toJulianDay(), montant); // Ajoute le montant à la date
        }
    }

    chartGlobal->createDefaultAxes(); // Mettez à jour les axes
}


void EtatFinance::afficherGraphiqueParMois() {
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);

    // Récupérer les abonnements groupés par mois
    query.prepare("SELECT strftime('%Y-%m', date_paiement) AS month, SUM(montants) FROM abonnement GROUP BY month");
    if (!query.exec()) {
        qDebug() << query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données " + query.lastError().text());
        return;
    }

    seriesMois->clear(); // Effacez les données précédentes

    while (query.next()) {
        QString month = query.value(0).toString();
        double montant = query.value(1).toDouble();

        QBarSet *set = new QBarSet(month);
        *set << montant; // Ajoute le montant pour ce mois
        seriesMois->append(set);
    }

    chartMois->createDefaultAxes(); // Mettez à jour les axes
}*/


