#include "VComboRangeSelector.h"
#include "VComboRangeSelectorPlugin.h"

#include <QtPlugin>

VComboRangeSelectorPlugin::VComboRangeSelectorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void VComboRangeSelectorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool VComboRangeSelectorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *VComboRangeSelectorPlugin::createWidget(QWidget *parent)
{
    return new VComboRangeSelector(parent);
}

QString VComboRangeSelectorPlugin::name() const
{
    return QLatin1String("VComboRangeSelector");
}

QString VComboRangeSelectorPlugin::group() const
{
    return QLatin1String("vSelectors");
}

QIcon VComboRangeSelectorPlugin::icon() const
{
    return QIcon(QLatin1String(":/alpha.png"));
}

QString VComboRangeSelectorPlugin::toolTip() const
{
    return QLatin1String("");
}

QString VComboRangeSelectorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool VComboRangeSelectorPlugin::isContainer() const
{
    return false;
}

QString VComboRangeSelectorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"VComboRangeSelector\" name=\"vComboRangeSelector\">\n</widget>\n");
}

QString VComboRangeSelectorPlugin::includeFile() const
{
    return QLatin1String("VComboRangeSelector.h");
}

