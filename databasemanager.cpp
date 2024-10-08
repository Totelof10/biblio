#include "databasemanager.h"

QSqlDatabase& DatabaseManager::getDatabase() {
    static QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "unique_connection_name");
    if (!db.isOpen()) {
        db.setDatabaseName("C:/db_test/login.db");
        if (!db.open()) {
            qDebug() << "Erreur : Impossible d'ouvrir la base de données";
        }
    }
    return db;
}

void DatabaseManager::closeDatabase() {
    QSqlDatabase::removeDatabase("unique_connection_name");
}
void DatabaseManager::enregistrerLivre(const QString &titre, const QString &genre, const QString &auteur, const QString &maison_edition, const QString &proprietes, int quantite, const QString &armoire, const QString &identifiant){
    QSqlDatabase db = getDatabase();  // Obtenez la connexion à la base de données
    if (!db.isOpen()) {
        qDebug() << "Erreur : La base de données n'est pas ouverte";
        return;  // Sortir si la base de données n'est pas ouverte
    }
    QSqlQuery query(db);
    query.prepare("INSERT OR IGNORE INTO livres(titre, genre, auteur, maison_edition, proprietes, quantite, armoire, identifiant) VALUES(?,?,?,?,?,?,?,?)");
    query.addBindValue(titre);
    query.addBindValue(genre);
    query.addBindValue(auteur);
    query.addBindValue(maison_edition);
    query.addBindValue(proprietes);
    query.addBindValue(quantite);
    query.addBindValue(armoire);
    query.addBindValue(identifiant);
    if (!query.exec()) {
        qDebug() << query.lastError();
    }

}
