#include "VIntegerRangeSelector.h"
#include "VIntegerRangeSelectorPlugin.h"

#include <QtPlugin>

VIntegerRangeSelectorPlugin::VIntegerRangeSelectorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void VIntegerRangeSelectorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool VIntegerRangeSelectorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *VIntegerRangeSelectorPlugin::createWidget(QWidget *parent)
{
    return new VIntegerRangeSelector(parent);
}

QString VIntegerRangeSelectorPlugin::name() const
{
    return QLatin1String("VIntegerRangeSelector");
}

QString VIntegerRangeSelectorPlugin::group() const
{
    return QLatin1String("vSelectors");
}

QIcon VIntegerRangeSelectorPlugin::icon() const
{
    return QIcon(QLatin1String(":/int.png"));
}

QString VIntegerRangeSelectorPlugin::toolTip() const
{
    return QLatin1String("");
}

QString VIntegerRangeSelectorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool VIntegerRangeSelectorPlugin::isContainer() const
{
    return false;
}

QString VIntegerRangeSelectorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"VIntegerRangeSelector\" name=\"vIntegerRangeSelector\">\n</widget>\n");
}

QString VIntegerRangeSelectorPlugin::includeFile() const
{
    return QLatin1String("VIntegerRangeSelector.h");
}

