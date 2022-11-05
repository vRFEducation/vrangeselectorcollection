#include "VFloatRangeSelectorPlugin.h"
#include "VIntegerRangeSelectorPlugin.h"
#include "VComboRangeSelectorPlugin.h"
#include "VRangeSelectorCollection.h"

VRangeSelectorCollection::VRangeSelectorCollection(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new VFloatRangeSelectorPlugin(this));
    m_widgets.append(new VIntegerRangeSelectorPlugin(this));
    m_widgets.append(new VComboRangeSelectorPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> VRangeSelectorCollection::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(VRangeSelectorCollectionPlugin, VRangeSelectorCollection)
#endif // QT_VERSION < 0x050000
