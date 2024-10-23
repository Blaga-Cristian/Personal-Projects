#include "picturemodel.h"
#include "albummodel.h"
#include "databasemanager.h"

using  namespace std;

PictureModel::PictureModel(AlbumModel const& albumModel, QObject* parent) :
    QAbstractListModel(parent),
    mDb(DatabaseManager::instance()),
    mAlbumId(-1),
    mPictures(new vector<unique_ptr<Picture>>())
{
    connect(&albumModel, &AlbumModel::rowsRemoved,
            this, &PictureModel::deletePicturesForAlbum);
}

QModelIndex PictureModel::addPicture(Picture const& picture)
{
    int rows = rowCount();
    beginInsertRows(QModelIndex(), rows, rows);
    unique_ptr<Picture> newPicture(new Picture(picture));
    mDb.pictureDao.addPictureInAlbum(mAlbumId, *newPicture);
    mPictures->push_back(move(newPicture));
    endInsertRows();
    return index(rows, 0);
}

int PictureModel::rowCount(QModelIndex const& parent) const
{
    return mPictures->size();
}

QVariant PictureModel::data(QModelIndex const& index, int role) const
{
    if(!isIndexValid(index)){
        return QVariant();
    }

    Picture const& picture = *mPictures->at(index.row());
    switch (role) {
        case Qt::DisplayRole:
            return picture.fileUrl().fileName();
            break;

        case Roles::UrlRole:
            return picture.fileUrl();
            break;

        case Roles::FilePathRole:
            return picture.fileUrl().toLocalFile();
            break;

        default:
            return QVariant();
    }
}

bool PictureModel::removeRows(int row, int count, QModelIndex const& parent)
{
    if(row < 0
        || row >= rowCount()
        || count < 0
        || (row + count) > rowCount()) {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while(countLeft --) {
        Picture const& picture = *mPictures->at(row + countLeft);
        mDb.pictureDao.removePicture(picture.id());
    }
    mPictures->erase(mPictures->begin() + row,
                     mPictures->begin() + row + count);
    endRemoveRows();

    return true;
}

QHash<int, QByteArray> PictureModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::FilePathRole] = "filepath";
    return roles;
}

void PictureModel::setAlbumId(int albumId)
{
    beginResetModel();
    mAlbumId = albumId;
    loadPictures(mAlbumId);
    endResetModel();
}

void PictureModel::clearAlbum()
{
    setAlbumId(-1);
}

void PictureModel::deletePicturesForAlbum()
{
    mDb.pictureDao.removePictureForAlbum(mAlbumId);
    clearAlbum();
}

void PictureModel::loadPictures(int albumId)
{
    if(albumId <= 0){
        mPictures.reset(new vector<unique_ptr<Picture>>());
        return;
    }

    mPictures = mDb.pictureDao.picturesForAlbum(albumId);
}

bool PictureModel::isIndexValid(QModelIndex const& index) const
{
    if(index.row() < 0
        || index.row() >= rowCount()
        || !index.isValid()) {
        return false;
    }
    return true;
}
