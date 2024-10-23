#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "gallery_core_global.h"
#include "Album.h"
#include "DatabaseManager.h"


class GALLERY_CORE_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    AlbumModel(QObject* parent = 0);

    QModelIndex addAlbum(const Album& album);

    int rowCount(QModelIndex const& parent = QModelIndex()) const override;
    QVariant data(QModelIndex const& index, int role = Qt::DisplayRole) const override;
    bool setData(QModelIndex const& index, QVariant const& value, int role) override;
    bool removeRows(int row, int count, QModelIndex const& parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(QModelIndex const& index) const;

private:
    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> mAlbums;
};

#endif // ALBUMMODEL_H
