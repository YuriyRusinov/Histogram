#ifndef _RandomParametersForm_H
#define _RandomParametersForm_H

#include <QWidget>

namespace Ui
{
    class random_parameters_form;
};

class RandomParametersForm : public QWidget
{
public:
    RandomParametersForm (QWidget * parent=0, Qt::WindowFlags flags=0);
    virtual ~RandomParametersForm (void);

private:
    //
    // Variables
    //
    Ui::random_parameters_form *UI;
private:
    Q_OBJECT
};

#endif
