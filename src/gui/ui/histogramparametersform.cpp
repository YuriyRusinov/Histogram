#include <QValidator>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>

#include "histogramparametersform.h"
#include "ui_histogram_parameters_form.h"

HistogramParametersForm :: HistogramParametersForm (QWidget * parent, Qt::WindowFlags flags)
    : QDialog (parent, flags),
    UI (new Ui::histogram_parameters_form)
{
    UI->setupUi (this);

    QValidator * minVal = new QDoubleValidator (this);
    UI->lEMinimum->setValidator (minVal);
    UI->lEMinimum->setText (QString::number (0.0));

    QValidator * maxVal = new QDoubleValidator (this);
    UI->lEMaximum->setValidator (maxVal);
    UI->lEMaximum->setText (QString::number (0.0));

    QValidator * numbVal = new QIntValidator (1, 10000, this);
    UI->lEBinsNumber->setValidator (numbVal);
    UI->lEBinsNumber->setText (QString::number (100));

    connect (UI->modalButtonsBox, SIGNAL (accepted ()), this, SLOT (hist_accepted()) );
    connect (UI->modalButtonsBox, SIGNAL (rejected ()), this, SLOT (reject()) );
}

HistogramParametersForm :: ~HistogramParametersForm (void)
{
    delete UI;
}

double HistogramParametersForm :: getXMin (void) const
{
    return UI->lEMinimum->text ().toDouble ();
}

double HistogramParametersForm :: getXMax (void) const
{
    return UI->lEMaximum->text ().toDouble ();
}

int HistogramParametersForm :: getNumb (void) const
{
    return UI->lEBinsNumber->text ().toInt();
}

bool HistogramParametersForm :: is_logscale (void) const
{
    return (UI->chLogarithmic->checkState() == Qt::Checked);
}

void HistogramParametersForm :: hist_accepted (void)
{
    if (this->getXMin() >= this->getXMax())
    {
        QMessageBox::warning (this, tr("Histogram parameters"), tr ("Minimal value has to be less than maximal value"), QMessageBox::Ok);
        return;
    }
    accept();
}

