#ifndef VINTEGERRANGESELECTOR_H
#define VINTEGERRANGESELECTOR_H

#include <QWidget>

namespace Ui {
class VIntegerRangeSelector;
}

class VIntegerRangeSelector : public QWidget
{
    Q_OBJECT

public:
    explicit VIntegerRangeSelector(QWidget *parent = nullptr);
    ~VIntegerRangeSelector();

private:
    Ui::VIntegerRangeSelector *ui;
};

#endif // VINTEGERRANGESELECTOR_H
