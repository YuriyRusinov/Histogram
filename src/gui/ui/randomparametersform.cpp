#include <QValidator>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QtDebug>

#include "ui_random_parameters_form.h"
#include "randomparametersform.h"

RandomParametersForm :: RandomParametersForm (QWidget * parent, Qt::WindowFlags flags)
    : QDialog (parent, flags),
    UI (new Ui::random_parameters_form)
{
    UI->setupUi (this);

    QValidator * mathVal = new QDoubleValidator (this);
    UI->lEMath->setValidator (mathVal);
    UI->lEMath->setText (QString::number(0.0));

    QValidator * dispVal = new QDoubleValidator (0.0, 10000, 16, this);
    UI->lEDisp->setValidator (dispVal);
    UI->lEDisp->setText (QString::number(1.0));

    QValidator * numbVal = new QIntValidator (1, 1000000, this);
    UI->lENumbers->setValidator (numbVal);
    UI->lENumbers->setText (QString::number (10000));

    connect (UI->pbOk, SIGNAL (clicked()), this, SLOT (setParamsOk()) );
    connect (UI->pbCancel, SIGNAL (clicked()), this, SLOT (reject()) );
}

RandomParametersForm :: ~RandomParametersForm (void)
{
    delete UI;
}

void RandomParametersForm :: setDistributions (const QMap<int, QString>& distrs)
{
    UI->cbDistr->clear ();
    QMap<int, QString>::const_iterator pd = distrs.constBegin();
    for (; pd != distrs.constEnd(); ++pd)
        UI->cbDistr->addItem (pd.value(), pd.key());
}

double RandomParametersForm :: getMathExp (void) const
{
    return UI->lEMath->text().toDouble ();
}

double RandomParametersForm :: getDisp (void) const
{
    return UI->lEDisp->text().toDouble ();
}

int RandomParametersForm :: getFunDistr (void) const
{
    return UI->cbDistr->itemData(UI->cbDistr->currentIndex()).toInt();
}

int RandomParametersForm :: getNumber (void) const
{
    return UI->lENumbers->text().toInt();
}

void RandomParametersForm :: setParamsOk (void)
{
    int fd = getFunDistr();
    double m = getMathExp();
    double d = getDisp ();
    int n = getNumber ();
    qDebug () << __PRETTY_FUNCTION__ << m << d << n;
    emit setParams (fd, m, d, n);
    accept();
}
