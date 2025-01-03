#include "album.h"

Album::Album(QString const& name) :
    mId(-1),
    mName(name)
{}

int Album::id() const {return mId;}

void Album::setId(int id) {mId = id;}

QString Album::name() const {return mName;}

void Album::setName(QString const& name) {mName = name;}
