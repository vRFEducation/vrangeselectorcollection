#include "VFloatRangeSelector.h"
#include "ui_VFloatRangeSelector.h"
#include <QStyle>


VFloatRangeSelector::VFloatRangeSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VFloatRangeSelector)
{
    ui->setupUi(this);
    setDefualts();
    connect(ui->spnFrom, &QDoubleSpinBox::editingFinished, this, &VFloatRangeSelector::validate);
    connect(ui->spnTo, &QDoubleSpinBox::editingFinished, this, &VFloatRangeSelector::validate);
}

VFloatRangeSelector::~VFloatRangeSelector()
{
    delete ui;
}

const QString &VFloatRangeSelector::caption() const
{
    return _caption;
}

void VFloatRangeSelector::setCaption(const QString &newCaption)
{
    if (_caption == newCaption)
        return;
    _caption = newCaption;
    ui->lblCaption->setText(_caption);
    emit captionChanged();
}

double VFloatRangeSelector::min() const
{
    return _min;
}

void VFloatRangeSelector::setMin(double newMin)
{
    if (qFuzzyCompare(_min, newMin))
        return;
    _min = newMin;
    ui->spnFrom->setMinimum(_min);
    ui->spnTo->setMinimum(_min);
    emit minChanged();
}

double VFloatRangeSelector::max() const
{
    return _max;
}

void VFloatRangeSelector::setMax(double newMax)
{
    if (qFuzzyCompare(_max, newMax))
        return;
    _max = newMax;
    ui->spnFrom->setMaximum(_max);
    ui->spnTo->setMaximum(_max);

    emit maxChanged();
}

double VFloatRangeSelector::from() const
{
    return ui->spnFrom->value();
}

void VFloatRangeSelector::setFrom(double newFrom)
{
    if (qFuzzyCompare(_from, newFrom))
        return;
    _from = newFrom;
    ui->spnFrom->setValue(newFrom);
    validate();
    emit fromChanged();
}

double VFloatRangeSelector::to() const
{
    return ui->spnTo->value();
}

void VFloatRangeSelector::setTo(double newTo)
{
    if (qFuzzyCompare(_to, newTo))
        return;
    _to = newTo;
    ui->spnTo->setValue(newTo);
    validate();
    emit toChanged();
}

int VFloatRangeSelector::percisionCount() const
{
    return _percisionCount;
}

void VFloatRangeSelector::setPercisionCount(int newPercisionCount)
{
    if (_percisionCount == newPercisionCount)
        return;
    _percisionCount = newPercisionCount;
    ui->spnFrom->setDecimals(_percisionCount);
    ui->spnTo->setDecimals(_percisionCount);

    emit percisionCountChanged();
}

bool VFloatRangeSelector::isValidationEnabled() const
{
    return _isValidationEnabled;
}

void VFloatRangeSelector::setIsValidationEnabled(bool newIsValidationEnabled)
{
    if (_isValidationEnabled == newIsValidationEnabled)
        return;
    _isValidationEnabled = newIsValidationEnabled;
    validate();
    emit isValidationEnabledChanged();
}

const QColor &VFloatRangeSelector::validationColor() const
{
    return _validationColor;
}

void VFloatRangeSelector::setValidationColor(const QColor &newValidationColor)
{
    if (_validationColor == newValidationColor)
        return;
    _validationColor = newValidationColor;
    validate();
    emit validationColorChanged();
}

void VFloatRangeSelector::setDefualts()
{
    setCaption("Value:");
    setMin(0);
    setMax(100);
    setFrom(0);
    setTo(0);
    setPercisionCount(2);
    setIsValidationEnabled(true);
    setValidationColor(Qt::red);
}

void VFloatRangeSelector::validate()
{
    QString stylesheet = "";
    if (isValidationEnabled()) {
        if (ui->spnFrom->value() > ui->spnTo->value()) {
            stylesheet = QString("background-color: %1;").arg(validationColor().name());
        }
    }
    ui->spnFrom->setStyleSheet(stylesheet);
    ui->spnTo->setStyleSheet(stylesheet);

    style()->polish(ui->spnFrom);
    style()->polish(ui->spnTo);
}

