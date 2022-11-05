#ifndef VFLOATRANGESELECTOREDITDIALOG_H
#define VFLOATRANGESELECTOREDITDIALOG_H

#include "VFloatRangeSelector.h"

#include <QDialog>

namespace Ui {
class VFloatRangeSelectorEditDialog;
}

class VFloatRangeSelectorEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VFloatRangeSelectorEditDialog(VFloatRangeSelector *widget, QWidget *parent = nullptr);
    ~VFloatRangeSelectorEditDialog();

private slots:
    void accept();

    void on_btnValidationColor_clicked();

private:
    Ui::VFloatRangeSelectorEditDialog *ui;
    VFloatRangeSelector *_widget;
    QColor _selectedColor;

private:    //methods
    void updateButtonColor();
};

#endif // VFLOATRANGESELECTOREDITDIALOG_H
