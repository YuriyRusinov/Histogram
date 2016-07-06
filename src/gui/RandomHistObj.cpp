#include "RandomHistObj.h"

_HIST_EXPORT_ RandomHistObject * RandomHistObject :: self = 0;

RandomHistObject :: RandomHistObject (QObject * parent)
    : QObject (parent)
{
    if (self)
        qFatal("There should be only one RandomHist object");
    self = this;
}

RandomHistObject :: ~RandomHistObject (void)
{
    self = 0;
}

RandomHistObject * RandomHistObject :: getRandomHistObject (QObject * parent)
{
    if (!self)
        self = new RandomHistObject (parent);

    return self;
}
