#ifndef VCOMBORANGESELECTOR_H
#define VCOMBORANGESELECTOR_H

#include <QWidget>

namespace Ui {
class VComboRangeSelector;
}

class VComboRangeSelector : public QWidget
{
    Q_OBJECT

public:
    explicit VComboRangeSelector(QWidget *parent = nullptr);
    ~VComboRangeSelector();

private:
    Ui::VComboRangeSelector *ui;
};

#endif // VCOMBORANGESELECTOR_H
