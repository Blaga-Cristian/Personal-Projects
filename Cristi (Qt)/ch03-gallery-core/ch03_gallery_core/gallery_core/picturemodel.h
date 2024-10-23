#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <memory>
#include <vector>
#include <QAbstractListModel>
#include "gallery_core_global.h"
#include "Picture.h"


class Album;
class DatabaseManager;
class AlbumModel;

class GALLERY_CORE_EXPORT PictureModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        UrlRole = Qt::UserRole + 1,
        FilePathRole
    };

    PictureModel(AlbumModel const& AlbumModel, QObject* parent = 0);

    QModelIndex addPicture(Picture const& picture);

    int rowCount(QModelIndex const& parent = QModelIndex()) const override;
    QVariant data(QModelIndex const& index, int role) const override;
    bool removeRows(int row, int count, QModelIndex const& parent)override;
    QHash<int, QByteArray> roleNames() const override;

    void setAlbumId(int albumId);
    void clearAlbum();

public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures(int albumId);
    bool isIndexValid(QModelIndex const& index) const;

private:
    DatabaseManager& mDb;
    int mAlbumId;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> mPictures;
};

#endif // PICTUREMODEL_H
