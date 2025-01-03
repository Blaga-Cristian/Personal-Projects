#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include "albumdao.h"
#include "picturedao.h"
#include "qsqlquery.h"

class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static void debugQuery(QSqlQuery const& query);

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(QString const& path = DATABASE_FILENAME);
    DatabaseManager& operator = (const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public:
    const AlbumDao albumDao;
    const PictureDao pictureDao;
};

#endif // DATABASEMANAGER_H
