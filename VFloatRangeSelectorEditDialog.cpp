#include "VFloatRangeSelectorEditDialog.h"
#include "ui_VFloatRangeSelectorEditDialog.h"

#include <QDesignerFormWindowInterface>
#include <QDesignerFormWindowCursorInterface>
#include <QStyle>
#include <QColorDialog>

VFloatRangeSelectorEditDialog::VFloatRangeSelectorEditDialog(VFloatRangeSelector *widget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VFloatRangeSelectorEditDialog),
    _widget(widget)
{
    ui->setupUi(this);
    ui->lnCaption->setText(_widget->caption());
    ui->dlPercision->setValue(_widget->percisionCount());
    ui->chkRangeValidation->setChecked(_widget->isValidationEnabled());
    _selectedColor = _widget->validationColor();
    updateButtonColor();
}

VFloatRangeSelectorEditDialog::~VFloatRangeSelectorEditDialog()
{
    delete ui;
}

void VFloatRangeSelectorEditDialog::accept()
{
    if (QDesignerFormWindowInterface *formWindow =
            QDesignerFormWindowInterface::findFormWindow(_widget)) {
        formWindow->cursor()->setProperty("caption", ui->lnCaption->text());
        formWindow->cursor()->setProperty("isValidationEnabled", ui->chkRangeValidation->isChecked());
        formWindow->cursor()->setProperty("validationColor", _selectedColor);
        formWindow->cursor()->setProperty("percisionCount", ui->dlPercision->value());
    }
//    _widget->setCaption(ui->lnCaption->text());
//    _widget->setIsValidationEnabled(ui->chkRangeValidation->isChecked());
//    _widget->setValidationColor(_selectedColor);
//    _widget->setPercisionCount(ui->dlPercision->value());
    QDialog::accept();
}

void VFloatRangeSelectorEditDialog::updateButtonColor()
{
    QString stylesheet = QString("background-color: %1").arg(_selectedColor.name());
    ui->btnValidationColor->setStyleSheet(stylesheet);
    style()->polish(ui->btnValidationColor);
}

void VFloatRangeSelectorEditDialog::on_btnValidationColor_clicked()
{
    QColorDialog dlg(_widget->validationColor());
    dlg.exec();
    _selectedColor = dlg.selectedColor();
    updateButtonColor();

}

