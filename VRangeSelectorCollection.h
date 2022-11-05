#ifndef VRANGESELECTORCOLLECTION_H
#define VRANGESELECTORCOLLECTION_H

#include <QtDesigner>
#include <qplugin.h>

class VRangeSelectorCollection : public QObject, public QDesignerCustomWidgetCollectionInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
#endif // QT_VERSION >= 0x050000

public:
    explicit VRangeSelectorCollection(QObject *parent = 0);

    virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;

private:
    QList<QDesignerCustomWidgetInterface*> m_widgets;
};

#endif // VRANGESELECTORCOLLECTION_H
