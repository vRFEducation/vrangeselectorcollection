#ifndef VFLOATRANGESELECTOR_H
#define VFLOATRANGESELECTOR_H

#include <QWidget>

namespace Ui{
class VFloatRangeSelector;
}

class VFloatRangeSelector : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
    Q_PROPERTY(double min READ min WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(double max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(double from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(double to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(int percisionCount READ percisionCount WRITE setPercisionCount NOTIFY percisionCountChanged)
    Q_PROPERTY(bool isValidationEnabled READ isValidationEnabled WRITE setIsValidationEnabled NOTIFY isValidationEnabledChanged)
    Q_PROPERTY(QColor validationColor READ validationColor WRITE setValidationColor NOTIFY validationColorChanged)

public:
    VFloatRangeSelector(QWidget *parent = 0);
    ~VFloatRangeSelector();

    const QString &caption() const;
    void setCaption(const QString &newCaption);

    double min() const;
    void setMin(double newMin);

    double max() const;
    void setMax(double newMax);

    double from() const;
    void setFrom(double newFrom);

    double to() const;
    void setTo(double newTo);

    int percisionCount() const;
    void setPercisionCount(int newPercisionCount);

    bool isValidationEnabled() const;
    void setIsValidationEnabled(bool newIsValidationEnabled);

    const QColor &validationColor() const;
    void setValidationColor(const QColor &newValidationColor);

signals:
    void captionChanged();

    void minChanged();

    void maxChanged();

    void fromChanged();

    void toChanged();

    void percisionCountChanged();

    void isValidationEnabledChanged();

    void validationColorChanged();

private:
    Ui::VFloatRangeSelector *ui;
    QString _caption;
    double _min;
    double _max;
    double _from;
    double _to;
    int _percisionCount;
    bool _isValidationEnabled;
    QColor _validationColor;

private:    //methods
    void setDefualts();

private slots:
    void validate();

};

#endif // VFLOATRANGESELECTOR_H
