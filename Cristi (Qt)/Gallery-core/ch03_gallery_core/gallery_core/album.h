#ifndef ALBUM_H
#define ALBUM_H

#include "gallery_core_global.h"

#include <QString>

class GALLERY_CORE_EXPORT Album
{
public:
    explicit Album(QString const& name = "");

    int id() const;
    void setId(int id);
    QString name() const;
    void setName(QString const& name);

private:
    int mId;
    QString mName;
};

#endif // ALBUM_H
