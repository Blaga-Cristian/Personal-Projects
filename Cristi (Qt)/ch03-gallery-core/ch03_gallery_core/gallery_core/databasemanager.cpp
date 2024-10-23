#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

void DatabaseManager::debugQuery(QSqlQuery const& query)
{
    if(query.lastError().type() == QSqlError::ErrorType::NoError){
        qDebug() << "Query OK:" << query.lastQuery();
    } else {
        qWarning() << "Query KO:" << query.lastError().text();
        qWarning() << "Query text:" << query.lastQuery();
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(QString const& path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao(*mDatabase),
    pictureDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);


    bool openStatus = mDatabase->open();
    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

    albumDao.init();
    pictureDao.init();
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    ///unique pointer handles deletion
}
