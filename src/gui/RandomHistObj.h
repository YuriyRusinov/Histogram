#ifndef _RandomHistObject_H
#define _RandomHistObject_H

#include <QObject>
#include "src_config.h"

class _HIST_EXPORT_ RandomHistObject : public QObject
{
public:
    static RandomHistObject * getRandomHistObject (QObject * parent=0);
private:
    //
    // Functions
    //
    RandomHistObject (QObject * parent=0);
    virtual ~RandomHistObject (void);

private:
    //
    // Variables
    //
    static RandomHistObject * self;
private:
    Q_OBJECT
};

#endif
