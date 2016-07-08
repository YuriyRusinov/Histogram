#ifndef _HistogramParametersForm_H
#define _HistogramParametersForm_H

#include <QDialog>
#include "src_config.h"

namespace Ui
{
    class histogram_parameters_form;
};

class _HIST_EXPORT_ HistogramParametersForm : public QDialog
{
public:
    HistogramParametersForm (QWidget * parent=0, Qt::WindowFlags flags=0);
    virtual ~HistogramParametersForm (void);

    double getXMin (void) const;
    double getXMax (void) const;
    int getNumb (void) const;
    bool is_logscale (void) const;

private slots:
    void hist_accepted (void);

private:
    //
    // Variables
    //
    Ui::histogram_parameters_form * UI;
private:
    Q_OBJECT
};

#endif
