#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <QVector>

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
    AlbumDao(QSqlDatabase& database);
    void init() const;

    void addAlbum(Album& album) const;
    void updateAlbum(Album const& album) const;
    void removeAlbum(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> albums() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // ALBUMDAO_H
