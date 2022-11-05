#include "VIntegerRangeSelector.h"
#include "ui_VIntegerRangeSelector.h"

VIntegerRangeSelector::VIntegerRangeSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VIntegerRangeSelector)
{
    ui->setupUi(this);
}

VIntegerRangeSelector::~VIntegerRangeSelector()
{
    delete ui;
}
