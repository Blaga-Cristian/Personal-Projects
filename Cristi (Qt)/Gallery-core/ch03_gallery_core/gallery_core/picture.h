#ifndef PICTURE_H
#define PICTURE_H

#include "gallery_core_global.h"

#include <QUrl>
#include <QString>

class GALLERY_CORE_EXPORT Picture
{
public:
    Picture(QString const& filePath = "");
    Picture(QUrl const& fileUrl);

    int id() const;
    void setId(int id);

    int albumId() const;
    void setAlbumId(int albumId);

    QUrl fileUrl() const;
    void setFileUrl(QUrl const& fileUrl);

private:
    int mId;
    int mAlbumId;
    QUrl mFileUrl;
};

#endif // PICTURE_H
