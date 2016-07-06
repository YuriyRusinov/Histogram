#ifndef _RandomParametersForm_H
#define _RandomParametersForm_H

#include <QDialog>

namespace Ui
{
    class random_parameters_form;
};

class RandomParametersForm : public QDialog
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
