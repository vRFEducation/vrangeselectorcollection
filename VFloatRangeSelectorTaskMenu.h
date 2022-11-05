#ifndef VFLOATRANGESELECTORTASKMENU_H
#define VFLOATRANGESELECTORTASKMENU_H

#include "VFloatRangeSelector.h"

#include <QDesignerTaskMenuExtension>
#include <QExtensionFactory>
#include <QObject>

class VFloatRangeSelectorTaskMenu : public QObject, public QDesignerTaskMenuExtension
{
    Q_OBJECT
    Q_INTERFACES(QDesignerTaskMenuExtension)
public:
    explicit VFloatRangeSelectorTaskMenu(VFloatRangeSelector *widget, QObject *parent = nullptr);

private slots:
    void reset();
    void showEditDialog();

    // QDesignerTaskMenuExtension interface
public:
    QAction *preferredEditAction() const override;
    QList<QAction *> taskActions() const override;

private:
    VFloatRangeSelector *_widget;
    QAction *_resetAction;
    QAction *_showEditDialogAction;
};

class VFloatRangeSelectorTaskMenuFactory : public QExtensionFactory{
    Q_OBJECT
public:
    VFloatRangeSelectorTaskMenuFactory (QExtensionManager *parent = nullptr);

    // QExtensionFactory interface
protected:
    QObject *createExtension(QObject *object, const QString &iid, QObject *parent) const;
};

#endif // VFLOATRANGESELECTORTASKMENU_H
