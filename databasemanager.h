#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DatabaseManager
{
public:
    static QSqlDatabase& getDatabase();
    static void closeDatabase();
};

#endif // DATABASEMANAGER_H
