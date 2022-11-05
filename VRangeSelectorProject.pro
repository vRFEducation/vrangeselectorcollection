CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(VRangeSelectorCollectionPlugin)
TEMPLATE    = lib

HEADERS     = VFloatRangeSelectorPlugin.h VIntegerRangeSelectorPlugin.h VComboRangeSelectorPlugin.h VRangeSelectorCollection.h \
    VFloatRangeSelectorEditDialog.h \
    VFloatRangeSelectorTaskMenu.h
SOURCES     = VFloatRangeSelectorPlugin.cpp VIntegerRangeSelectorPlugin.cpp VComboRangeSelectorPlugin.cpp VRangeSelectorCollection.cpp \
    VFloatRangeSelectorEditDialog.cpp \
    VFloatRangeSelectorTaskMenu.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(VIntegerRangeSelector.pri)
include(VFloatRangeSelector.pri)
include(VComboRangeSelector.pri)

FORMS += \
    VFloatRangeSelectorEditDialog.ui

