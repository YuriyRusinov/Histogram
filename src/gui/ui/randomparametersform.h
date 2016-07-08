#ifndef _RandomParametersForm_H
#define _RandomParametersForm_H

#include <QDialog>
#include "src_config.h"

namespace Ui
{
    class random_parameters_form;
};

class _HIST_EXPORT_ RandomParametersForm : public QDialog
{
public:
    RandomParametersForm (QWidget * parent=0, Qt::WindowFlags flags=0);
    virtual ~RandomParametersForm (void);

    void setDistributions (const QMap<int, QString>& distrs);

    double getMathExp (void) const;
    double getDisp (void) const;
    int getFunDistr (void) const;
    int getNumber (void) const;

private slots:
    void setParamsOk (void);

signals:
    void setParams (int fdisps, double math_exp, double disp, int n);

private:
    //
    // Variables
    //
    Ui::random_parameters_form *UI;
private:
    Q_OBJECT
};

#endif
