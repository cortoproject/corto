#-------------------------------------------------
#
# Project created by QtCreator 2013-11-11T17:37:54
#
#-------------------------------------------------

QT       += widgets opengl gui

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = ../../bin/Qt
TEMPLATE = lib
CONFIG += plugin

DEFINES += QT_LIBRARY

QMAKE_CXXFLAGS_RELEASE += -g
QMAKE_CFLAGS_RELEASE += -g
QMAKE_LFLAGS_RELEASE =

INCLUDEPATH += \
    ../../public/cpp/include \
    include/

LIBS += -L ../../bin -llang4cpp

SOURCES += \
    src/Qt/Widget.cpp \
    src/Qt/Tile.cpp \
    src/Qt/Splitter.cpp \
    src/Qt/Slot.cpp \
    src/Qt/Slider.cpp \
    src/Qt/RadioButton.cpp \
    src/Qt/RadialGradient.cpp \
    src/Qt/qcustomplot.cpp \
    src/Qt/PushButton.cpp \
    src/Qt/ProgressBar.cpp \
    src/Qt/Pen.cpp \
    src/Qt/PaintEvent_t.cpp \
    src/Qt/Painter.cpp \
    src/Qt/PaintDevice.cpp \
    src/Qt/ObjectView.cpp \
    src/Qt/ObjectTree.cpp \
    src/Qt/ObjectBrowse.cpp \
    src/Qt/Object.cpp \
    src/Qt/MouseEvent_t.cpp \
    src/Qt/MainWindow.cpp \
    src/Qt/ListWidget.cpp \
    src/Qt/LineEdit.cpp \
    src/Qt/LinearGradient.cpp \
    src/Qt/Label.cpp \
    src/Qt/InputEvent_t.cpp \
    src/Qt/GroupBox.cpp \
    src/Qt/GridLayout.cpp \
    src/Qt/Gradient.cpp \
    src/Qt/Font.cpp \
    src/Qt/EnumComboBox.cpp \
    src/Qt/CustomPlot.cpp \
    src/Qt/ConicalGradient.cpp \
    src/Qt/ComboBox.cpp \
    src/Qt/CheckBox.cpp \
    src/Qt/Brush.cpp \
    src/Qt/Application.cpp \
    src/Qt/AbstractButton.cpp \
    src/Qt/_type.cpp \
    src/Qt/_meta.cpp \
    qt.cpp \
    src/Qt/slotbase.cpp \
    src/Qt/TabWidget.cpp \
    src/Qt/ObjectTile.cpp

HEADERS += \
    src/Qt/qcustomplot.h \
    include/Qt/Widget.hpp \
    include/Qt/Tile.hpp \
    include/Qt/Splitter.hpp \
    include/Qt/Slot.hpp \
    include/Qt/Slider.hpp \
    include/Qt/RadioButton.hpp \
    include/Qt/RadialGradient.hpp \
    include/Qt/qcustomplot.h \
    include/Qt/PushButton.hpp \
    include/Qt/ProgressBar.hpp \
    include/Qt/Pen.hpp \
    include/Qt/PaintEvent_t.hpp \
    include/Qt/Painter.hpp \
    include/Qt/PaintDevice.hpp \
    include/Qt/ObjectView.hpp \
    include/Qt/ObjectTree.hpp \
    include/Qt/ObjectBrowse.hpp \
    include/Qt/Object.hpp \
    include/Qt/MouseEvent_t.hpp \
    include/Qt/MainWindow.hpp \
    include/Qt/ListWidget.hpp \
    include/Qt/LineEdit.hpp \
    include/Qt/LinearGradient.hpp \
    include/Qt/Label.hpp \
    include/Qt/InputEvent_t.hpp \
    include/Qt/GroupBox.hpp \
    include/Qt/GridLayout.hpp \
    include/Qt/Gradient.hpp \
    include/Qt/Font.hpp \
    include/Qt/EnumComboBox.hpp \
    include/Qt/CustomPlot.hpp \
    include/Qt/ConicalGradient.hpp \
    include/Qt/ComboBox.hpp \
    include/Qt/CheckBox.hpp \
    include/Qt/Brush.hpp \
    include/Qt/Application.hpp \
    include/Qt/AbstractButton.hpp \
    include/Qt/_type.hpp \
    include/Qt/_meta.hpp \
    include/Qt/TabWidget.hpp \
    include/Qt/ObjectTile.hpp

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
