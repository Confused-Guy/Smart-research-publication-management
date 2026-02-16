#ifndef COLLABORATION_H
#define COLLABORATION_H

#include "mainwindow.h"


class collaboration
{
public:
    collaboration();

private:
    int collaborationId;
    QString title;
    QString description;
    int authorId;
    int publicationId;
};

#endif
