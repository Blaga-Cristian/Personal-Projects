#ifndef THUMBNAILPROXYMODEL_H
#define THUMBNAILPROXYMODEL_H

#include <QIdentityProxyModel>
#include <QHash>
#include <QPixmap>

class PictureModel;

class ThumbnailProxyModel : public QIdentityProxyModel
{
public:
    ThumbnailProxyModel();

    QVariant data(QModelIndex const& index, int role) const override;
    void setSourceModel(QAbstractItemModel* sourceModel) override;
    PictureModel* pictureModel() const;

private:
    void generateThumbnails(QModelIndex const& startIndex, int count);
    void reloadThumbnails();

private:
    QHash<QString, QPixmap*> mThumbnails;
};

#endif // THUMBNAILPROXYMODEL_H
