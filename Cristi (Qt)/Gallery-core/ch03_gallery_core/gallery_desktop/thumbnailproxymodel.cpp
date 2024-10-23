#include "thumbnailproxymodel.h"
#include "picturemodel.h"

const unsigned int THUMBNAIL_SIZE = 350;

ThumbnailProxyModel::ThumbnailProxyModel()
{}

void ThumbnailProxyModel::generateThumbnails(QModelIndex const& startIndex, int count)
{
    if(!startIndex.isValid()) {
        return;
    }

    QAbstractItemModel const* model = startIndex.model();
    int lastIndex = startIndex.row() + count;
    for(int row = startIndex.row(); row < lastIndex; ++row) {
        QString filepath = model->data(model->index(row, 0),
            PictureModel::Roles::FilePathRole).toString();
        QPixmap pixmap(filepath);
        auto thumbnail = new QPixmap(pixmap.scaled(
            THUMBNAIL_SIZE, THUMBNAIL_SIZE,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));
        mThumbnails.insert(filepath, thumbnail);
    }
}

void ThumbnailProxyModel::reloadThumbnails()
{
    qDeleteAll(mThumbnails);
    mThumbnails.clear();
    generateThumbnails(index(0, 0), rowCount());
}

void ThumbnailProxyModel::setSourceModel(QAbstractItemModel* sourceModel)
{
    QIdentityProxyModel::setSourceModel(sourceModel);
    if(!sourceModel) {
        return;
    }

    connect(sourceModel, &QAbstractItemModel::rowsInserted,
            [this] (QModelIndex const& parent, int first, int last) {
        generateThumbnails(index(first, 0), last - first + 1);});
}
