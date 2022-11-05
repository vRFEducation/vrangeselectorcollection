#include "VComboRangeSelector.h"
#include "ui_VComboRangeSelector.h"

VComboRangeSelector::VComboRangeSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VComboRangeSelector)
{
    ui->setupUi(this);
}

VComboRangeSelector::~VComboRangeSelector()
{
    delete ui;
}
