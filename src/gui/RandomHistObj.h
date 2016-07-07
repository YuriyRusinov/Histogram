#ifndef _RandomHistObject_H
#define _RandomHistObject_H

#include <QObject>
#include <QVector>
#include "src_config.h"

class RandomNumberGen;

class _HIST_EXPORT_ RandomHistObject : public QObject
{
public:
    static RandomHistObject * getRandomHistObject (QObject * parent=0);
    void GUIRandomProc (QWidget * parent=0, Qt::WindowFlags flags=0);
    void GUIHistogramParams (QWidget * parent=0, Qt::WindowFlags flags=0);
    void calcHist (void);
    void GUIViewHist (QWidget * parent=0, Qt::WindowFlags flags=0);

    enum DistrFuncs
    {
        Uniform=0,
        Gaussian=1,
        Exponential=2
    };

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
    RandomNumberGen * rGenerator;
    QVector<double> resNumb;
private:
    Q_OBJECT
};

#endif
