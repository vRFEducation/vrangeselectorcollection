#include "VFloatRangeSelectorEditDialog.h"
#include "VFloatRangeSelectorTaskMenu.h"

VFloatRangeSelectorTaskMenu::VFloatRangeSelectorTaskMenu(VFloatRangeSelector *widget, QObject *parent)
    : QObject{parent},
      _widget(widget),
      _resetAction(new QAction("Reset Widget", this))
{
    _showEditDialogAction = new QAction("Edit", this);
    connect(_resetAction, &QAction::triggered, this, &VFloatRangeSelectorTaskMenu::reset);
    connect(_showEditDialogAction, &QAction::triggered, this, &VFloatRangeSelectorTaskMenu::showEditDialog);
}

void VFloatRangeSelectorTaskMenu::reset()
{

}

void VFloatRangeSelectorTaskMenu::showEditDialog()
{
    VFloatRangeSelectorEditDialog dlg(_widget);
    dlg.exec();
}

QAction *VFloatRangeSelectorTaskMenu::preferredEditAction() const
{
    return _showEditDialogAction;
}

QList<QAction *> VFloatRangeSelectorTaskMenu::taskActions() const
{
    return QList<QAction *>{_showEditDialogAction, _resetAction};
}

VFloatRangeSelectorTaskMenuFactory::VFloatRangeSelectorTaskMenuFactory(QExtensionManager *parent)
    :QExtensionFactory(parent)
{

}

QObject *VFloatRangeSelectorTaskMenuFactory::createExtension(QObject *object, const QString &iid, QObject *parent) const
{
    if (iid != Q_TYPEID(QDesignerTaskMenuExtension)) {
        return nullptr;
    }
    if (VFloatRangeSelector *w = qobject_cast<VFloatRangeSelector *>(object)){
        return new VFloatRangeSelectorTaskMenu(w, parent);

    }
}
