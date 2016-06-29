#include "ui_random_parameters_form.h"
#include "randomparametersform.h"

RandomParametersForm :: RandomParametersForm (QWidget * parent, Qt::WindowFlags flags)
    : QWidget (parent, flags),
    UI (new Ui::random_parameters_form)
{
    UI->setupUi (this);
}

RandomParametersForm :: ~RandomParametersForm (void)
{
}
