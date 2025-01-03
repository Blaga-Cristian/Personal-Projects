#include "albummodel.h"
using namespace std;

AlbumModel::AlbumModel(QObject* parent) :
    QAbstractListModel(parent),
    mDb(DatabaseManager::instance()),
    mAlbums(mDb.albumDao.albums())
{}

QModelIndex AlbumModel::addAlbum(Album const& album)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Album> newAlbum(new Album(album));
    mDb.albumDao.addAlbum(*newAlbum);
    mAlbums->push_back(move(newAlbum));
    endInsertRows();
    return index(rowIndex, 0);
}

int AlbumModel::rowCount(QModelIndex const& parent) const
{
    return mAlbums->size();
}

QVariant AlbumModel::data(QModelIndex const& index, int role) const
{
    if(!isIndexValid(index)){
        return QVariant();
    }

    const Album& album = *mAlbums->at(index.row());

    switch(role) {
        case Roles::IdRole:
            return album.id();

        case Roles::NameRole:
        case Qt::DisplayRole:
            return album.name();

        default:
            return QVariant();
    }
}

bool AlbumModel::setData(QModelIndex const& index, QVariant const& value, int role)
{
    if(!isIndexValid(index) ||
        role != Roles::NameRole){
        return false;
    }
    Album& album = *mAlbums->at(index.row());
    album.setName(value.toString());
    mDb.albumDao.updateAlbum(album);
    emit dataChanged(index, index);
    return true;
}

bool AlbumModel::removeRows(int row, int count, QModelIndex const& parent)
{
    if(row < 0 ||
        row >= rowCount() ||
        count < 0 ||
        (row + count) > rowCount()){
        return false;
    }
    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while(countLeft --){
        Album const& album = *mAlbums->at(row + countLeft);
        mDb.albumDao.removeAlbum(album.id());
    }
    mAlbums->erase(mAlbums->begin() + row,
                   mAlbums->begin() + row + count);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool AlbumModel::isIndexValid(QModelIndex const& index) const
{
    if(index.row() < 0 ||
        index.row() >= rowCount() ||
        !index.isValid()){
        return false;
    }
    return true;
}
