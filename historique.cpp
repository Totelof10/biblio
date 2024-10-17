#include "historique.h"
#include "ui_historique.h"
#include "databasemanager.h"
#include "custommessagebox.h"

Historique::Historique(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Historique)
{
    ui->setupUi(this);
    afficherHistoriqueEmprunt();
    connect(ui->lineEditRechercheEmprunt, &QLineEdit::textChanged, this, &Historique::rechercheHistoriqueEmprunt);
    connect(ui->btnVidange, &QPushButton::clicked, this, &Historique::viderHistorique);
}

Historique::~Historique()
{
    delete ui;
}

void Historique::afficherHistoriqueEmprunt(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);
    if(!query.exec("SELECT id, id_emprunt, emprunteur, livre, debut, fin, date_suppression FROM historique_emprunt")){
        qDebug()<<query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données "+query.lastError().text());
        return;
    }
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while(query.next()){
        ui->tableWidget->insertRow(row);
        QString id = query.value(0).toString();
        QString id_emprunt = query.value(1).toString();
        QString emprunteur = query.value(2).toString();
        QString livre = query.value(3).toString();
        QString debut = query.value(4).toString();
        QString fin = query.value(5).toString();
        QString date_suppression = query.value(6).toString();

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(id_emprunt));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(emprunteur));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(livre));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(debut));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(fin));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(date_suppression));

        row++;
    }
}

void Historique::rechercheHistoriqueEmprunt(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QString recherche = ui->lineEditRechercheEmprunt->text();
    QSqlQuery query(sqlitedb);
    query.prepare("SELECT id, id_emprunt, emprunteur, livre, debut, fin, date_suppression FROM historique_emprunt WHERE emprunteur LIKE :recherche");
    query.bindValue(":recherche", "%" +recherche+ "%");
    if(!query.exec()){
        qDebug()<<query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la récupération des données: "+query.lastError().text());
    }
    ui->tableWidget->setRowCount(0);
    int row = 0;
    while(query.next()){
        ui->tableWidget->insertRow(row);
        QString id = query.value(0).toString();
        QString id_emprunt = query.value(1).toString();
        QString emprunteur = query.value(2).toString();
        QString livre = query.value(3).toString();
        QString debut = query.value(4).toString();
        QString fin = query.value(5).toString();
        QString date_suppression = query.value(6).toString();

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(id_emprunt));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(emprunteur));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(livre));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(debut));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(fin));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(date_suppression));

        row++;
    }
}

void Historique::viderHistorique(){
    CustomMessageBox msgBox;
    QSqlDatabase sqlitedb = DatabaseManager::getDatabase();
    QSqlQuery query(sqlitedb);
    QMessageBox confirmationBox;
    confirmationBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
    confirmationBox.setText("Voulez-vous vraiment vider l'historique? Attention cette action est irreversible");
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
    query.prepare("DELETE FROM historique_emprunt");
    if(!query.exec()){
        qDebug()<<query.lastError();
        msgBox.showError("Erreur", "Erreur lors de la suppression des données");
        return;
    }else{
        msgBox.showInformation("Succés", "Suppression effectuée");
    }
    afficherHistoriqueEmprunt();
}
