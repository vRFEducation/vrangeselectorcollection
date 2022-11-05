#include "VFloatRangeSelector.h"
#include "VFloatRangeSelectorPlugin.h"
#include "VFloatRangeSelectorTaskMenu.h"

#include <QDesignerFormEditorInterface>
#include <QExtensionManager>
#include <QtPlugin>

VFloatRangeSelectorPlugin::VFloatRangeSelectorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void VFloatRangeSelectorPlugin::initialize(QDesignerFormEditorInterface *  core )
{
    if (m_initialized)
        return;

    QExtensionManager *manager = core->extensionManager();
    manager->registerExtensions(
                new VFloatRangeSelectorTaskMenuFactory(manager),
                Q_TYPEID(QDesignerTaskMenuExtension));

    m_initialized = true;
}

bool VFloatRangeSelectorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *VFloatRangeSelectorPlugin::createWidget(QWidget *parent)
{
    return new VFloatRangeSelector(parent);
}

QString VFloatRangeSelectorPlugin::name() const
{
    return QLatin1String("VFloatRangeSelector");
}

QString VFloatRangeSelectorPlugin::group() const
{
    return QLatin1String("vSelectors");
}

QIcon VFloatRangeSelectorPlugin::icon() const
{
    return QIcon(QLatin1String(":/float.png"));
}

QString VFloatRangeSelectorPlugin::toolTip() const
{
    return QLatin1String("");
}

QString VFloatRangeSelectorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool VFloatRangeSelectorPlugin::isContainer() const
{
    return false;
}

QString VFloatRangeSelectorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"VFloatRangeSelector\" name=\"vFloatRangeSelector\">\n</widget>\n");
}

QString VFloatRangeSelectorPlugin::includeFile() const
{
    return QLatin1String("VFloatRangeSelector.h");
}

