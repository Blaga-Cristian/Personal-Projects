#include "picture.h"

Picture::Picture(QString const& filePath) :
    Picture(QUrl::fromLocalFile(filePath))
{
}

Picture::Picture(QUrl const& fileUrl) :
    mId(-1),
    mAlbumId(-1),
    mFileUrl(fileUrl)
{
}

int Picture::id() const {return mId;}
void Picture::setId(int id){mId = id;}

int Picture::albumId() const {return mAlbumId;}
void Picture::setAlbumId(int albumId) {mAlbumId = albumId;}

QUrl Picture::fileUrl() const {return mFileUrl;}
void Picture::setFileUrl(QUrl const& fileUrl) {mFileUrl = fileUrl;}
