#include "picturedao.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "picture.h"
#include "databasemanager.h"
#include <QVariant>

using namespace std;

PictureDao::PictureDao(QSqlDatabase& database) :
    mDatabase(database)
{}

void PictureDao::init() const
{
    if(!mDatabase.tables().contains("pictures")){
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE pictures")
        + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
        + "album_id INTEGER, "
        + "url TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture& picture) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("INSERT INTO pictures)")
        + " (album_id, url)"
        + " VALUES ("
        + ":album_id, "
        + ":url"
        + ")");
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", picture.fileUrl());
    query.exec();
    DatabaseManager::debugQuery(query);
    picture.setId(query.lastInsertId().toInt());
    picture.setAlbumId(albumId);    
}

void PictureDao::removePicture(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM pictures WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void PictureDao::removePictureForAlbum(int albumId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);
}

unique_ptr<vector<unique_ptr<Picture>>> PictureDao::picturesForAlbum(int albumId) const
{
    QSqlQuery query("SELECT * FROM pictures WHERE album_id = :album_id", mDatabase);
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Picture>>> list(new vector<unique_ptr<Picture>>());
    while(query.next()){
        unique_ptr<Picture> picture(new Picture());
        picture->setId(query.value("id").toInt());
        picture->setAlbumId(query.value("album_id").toInt());
        picture->setFileUrl(query.value("url").toString());
        list->push_back(move(picture));
    }
    return list;
}
