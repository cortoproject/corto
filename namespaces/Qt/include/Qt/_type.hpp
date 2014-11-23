/* include/Qt/_type.hpp
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C++ language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt__type_HPP
#define Qt__type_HPP

#include "hyve.hpp"
#include "hyve/def.hpp"

namespace QT {
    class AbstractButton;
    class Application;
    class Brush;
    class CheckBox;
    class ComboBox;
    class ConicalGradient;
    class CustomPlot;
    class EnumComboBox;
    class Font;
    class Gradient;
    class GridLayout;
    class GroupBox;
    class InputEvent_t;
    class Label;
    class LinearGradient;
    class LineEdit;
    class ListWidget;
    class MainWindow;
    class MouseEvent_t;
    class Object;
    class ObjectBrowse;
    class ObjectTile;
    class ObjectTree;
    class ObjectView;
    class PaintDevice;
    class Painter;
    class PaintEvent_t;
    class Pen;
    class ProgressBar;
    class PushButton;
    class RadialGradient;
    class RadioButton;
    class Slider;
    class Slot;
    class Splitter;
    class TabWidget;
    class Tile;
    class Widget;
    
    /*  ::Qt::Object */
    DB_CLASS(object);
    DB_CLASS_DEF(object) {
        ::hyve::lang::word qhandle;
    };
    
    /*  ::Qt::PaintDevice */
    DB_INTERFACE(paintDevice);
    
    /*  ::Qt::Color */
    typedef struct Color Color;
    struct Color {
        ::hyve::lang::uint8 r;
        ::hyve::lang::uint8 g;
        ::hyve::lang::uint8 b;
        ::hyve::lang::uint8 alpha;
    };
    
    /* ::Qt::GradientKind */
    typedef enum GradientKind {
        Linear = 0,
        Radial = 1,
        Conical = 2
    } GradientKind;
    typedef ::hyve::lang::float64 real;
    
    /*  ::Qt::GradientStop */
    typedef struct GradientStop GradientStop;
    struct GradientStop {
        QT::real pos;
        QT::Color color;
    };
    DB_SEQUENCE(GradientStop_seq, QT::GradientStop,/* No postfix */);
    
    /* ::Qt::GradientCoordinateMode */
    typedef enum GradientCoordinateMode {
        LogicalMode = 0,
        StretchToDeviceMode = 1,
        ObjectBoundingMode = 2
    } GradientCoordinateMode;
    
    /* ::Qt::GradientSpread */
    typedef enum GradientSpread {
        PadSpead = 0,
        ReflectSpread = 1,
        RepeatSpread = 2
    } GradientSpread;
    
    /*  ::Qt::Gradient */
    DB_CLASS(gradient);
    DB_CLASS_DEF(gradient) {
        DB_EXTEND(QT::object);
        QT::GradientKind kind;
        QT::GradientStop_seq stops;
        QT::GradientCoordinateMode coordinateMode;
        QT::GradientSpread spread;
    };
    
    /*  ::Qt::Brush */
    DB_CLASS(brush);
    DB_CLASS_DEF(brush) {
        DB_EXTEND(QT::object);
        QT::Color color;
        QT::gradient gradient;
    };
    
    /*  ::Qt::Pen */
    DB_CLASS(pen);
    DB_CLASS_DEF(pen) {
        DB_EXTEND(QT::object);
        QT::Color color;
        ::hyve::lang::uint32 width;
    };
    
    /*  ::Qt::Painter */
    DB_CLASS(painter);
    DB_CLASS_DEF(painter) {
        DB_EXTEND(QT::object);
        QT::paintDevice device;
        QT::brush brush;
        QT::pen pen;
    };
    
    /*  ::Qt::paintEvent_t */
    DB_CLASS(paintEvent_t);
    DB_CLASS_DEF(paintEvent_t) {
        QT::painter painter;
    };
    
    /* ::Qt::KeyboardModifiers */
    DB_BITMASK(KeyboardModifiers);
    extern int32_t NoModifier;
    extern int32_t ShiftModifier;
    extern int32_t ControlModifier;
    extern int32_t AltModifier;
    extern int32_t MetaModifier;
    extern int32_t KeypadModifier;
    extern int32_t GroupSwitchModifier;
    
    /*  ::Qt::inputEvent_t */
    DB_CLASS(inputEvent_t);
    DB_CLASS_DEF(inputEvent_t) {
        QT::KeyboardModifiers modifiers;
    };
    
    /* ::Qt::MouseButton */
    DB_BITMASK(MouseButton);
    extern int32_t NoButton;
    extern int32_t LeftButton;
    extern int32_t RightButton;
    extern int32_t MidButton;
    extern int32_t MiddleButton;
    extern int32_t XButton1;
    extern int32_t XButton2;
    
    /*  ::Qt::mouseEvent_t */
    DB_CLASS(mouseEvent_t);
    DB_CLASS_DEF(mouseEvent_t) {
        DB_EXTEND(QT::inputEvent_t);
        ::hyve::lang::int32 x;
        ::hyve::lang::int32 y;
        QT::MouseButton buttons;
    };
    
    /*  ::Qt::Widget */
    DB_CLASS(widget);
    DB_CLASS_DEF(widget) {
        DB_EXTEND(QT::object);
        QT::paintEvent_t paintEvent;
        QT::mouseEvent_t mousePressEvent;
        ::hyve::lang::int32 x;
        ::hyve::lang::int32 y;
        ::hyve::lang::int32 width;
        ::hyve::lang::int32 height;
        ::hyve::lang::_bool enabled;
        ::hyve::lang::_bool visible;
        ::hyve::lang::string styleSheet;
        QT::painter painter;
        ::hyve::lang::word qslots;
    };
    
    /*  ::Qt::AbstractButton */
    DB_CLASS(abstractButton);
    DB_CLASS_DEF(abstractButton) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::string text;
        ::hyve::lang::_bool checkable;
        ::hyve::lang::_bool down;
        ::hyve::lang::_bool checked;
    };
    
    /* ::Qt::Alignment */
    typedef enum Alignment {
        AlignLeft = 1,
        AlignRight = 2,
        AlignHCenter = 4,
        AlignJustify = 8,
        AlignTop = 32,
        AlignBottom = 64,
        AlignVCenter = 128,
        AlignCenter = 132
    } Alignment;
}
namespace hyve {
    namespace lang {
        DB_SEQUENCE(string_seq, ::hyve::lang::string,/* No postfix */);
    }
}
namespace QT {
    
    /*  ::Qt::Application */
    DB_CLASS(application);
    DB_CLASS_DEF(application) {
        DB_EXTEND(QT::object);
        ::hyve::lang::string_seq arg;
        ::hyve::lang::string stylesheet;
    };
    
    /*  ::Qt::CheckBox */
    DB_CLASS(checkBox);
    DB_CLASS_DEF(checkBox) {
        DB_EXTEND(QT::abstractButton);
    };
    
    /*  ::Qt::ComboBox */
    DB_CLASS(comboBox);
    DB_CLASS_DEF(comboBox) {
        DB_EXTEND(QT::widget);
        hyve::ll_h items;
        ::hyve::lang::uint32 currentIndex;
        ::hyve::lang::string currentText;
    };
    
    /*  ::Qt::PointF */
    typedef struct PointF PointF;
    struct PointF {
        QT::real x;
        QT::real y;
    };
    
    /*  ::Qt::ConicalGradient */
    DB_CLASS(conicalGradient);
    DB_CLASS_DEF(conicalGradient) {
        DB_EXTEND(QT::gradient);
        QT::real angle;
        QT::PointF center;
    };
    
    /*  ::Qt::CustomPlot */
    DB_CLASS(customPlot);
    DB_CLASS_DEF(customPlot) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::object object;
        ::hyve::lang::string expr;
        ::hyve::lang::uint32 autoX;
    };
    
    /*  ::Qt::EnumComboBox */
    DB_CLASS(enumComboBox);
    DB_CLASS_DEF(enumComboBox) {
        DB_EXTEND(QT::comboBox);
        ::hyve::lang::_enum type;
        ::hyve::lang::constant value;
    };
    
    /* ::Qt::FontWeight */
    typedef enum FontWeight {
        Light = 25,
        Normal = 50,
        DemiBold = 63,
        Bold = 75,
        Black = 87
    } FontWeight;
    
    /*  ::Qt::Font */
    DB_CLASS(font);
    DB_CLASS_DEF(font) {
        DB_EXTEND(QT::object);
        ::hyve::lang::string family;
        ::hyve::lang::int32 pointSize;
        QT::FontWeight weight;
        ::hyve::lang::_bool italic;
    };
    
    /*  ::Qt::GridColumn */
    typedef struct GridColumn GridColumn;
    struct GridColumn {
        ::hyve::lang::uint32 stretch;
        ::hyve::lang::uint32 minimumWidth;
    };
    
    /*  ::Qt::GridRow */
    typedef struct GridRow GridRow;
    struct GridRow {
        ::hyve::lang::uint32 stretch;
        ::hyve::lang::uint32 minimumHeight;
    };
    DB_SEQUENCE(GridRow_seq, QT::GridRow,/* No postfix */);
    DB_SEQUENCE(GridColumn_seq, QT::GridColumn,/* No postfix */);
    
    /*  ::Qt::GridWidget */
    typedef struct GridWidget GridWidget;
    struct GridWidget {
        QT::widget widget;
        ::hyve::lang::uint32 row;
        ::hyve::lang::uint32 column;
        ::hyve::lang::uint32 rowspan;
        ::hyve::lang::uint32 columnspan;
    };
    DB_SEQUENCE(GridWidget_seq, QT::GridWidget,/* No postfix */);
    
    /*  ::Qt::GridLayout */
    DB_CLASS(gridLayout);
    DB_CLASS_DEF(gridLayout) {
        DB_EXTEND(QT::object);
        QT::GridRow_seq rows;
        QT::GridColumn_seq columns;
        QT::GridWidget_seq widgets;
    };
    
    /*  ::Qt::GroupBox */
    DB_CLASS(groupBox);
    DB_CLASS_DEF(groupBox) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::string title;
    };
    
    /*  ::Qt::Label */
    DB_CLASS(label);
    DB_CLASS_DEF(label) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::string text;
        QT::Alignment alignment;
    };
    
    /*  ::Qt::Line */
    typedef struct Line Line;
    struct Line {
        ::hyve::lang::uint32 x1;
        ::hyve::lang::uint32 y1;
        ::hyve::lang::uint32 x2;
        ::hyve::lang::uint32 y2;
    };
    
    /*  ::Qt::LinearGradient */
    DB_CLASS(linearGradient);
    DB_CLASS_DEF(linearGradient) {
        DB_EXTEND(QT::gradient);
        QT::PointF start;
        QT::PointF finalStop;
    };
    
    /*  ::Qt::LineEdit */
    DB_CLASS(lineEdit);
    DB_CLASS_DEF(lineEdit) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::string text;
        ::hyve::lang::_bool readonly;
    };
    
    /*  ::Qt::LineF */
    typedef struct LineF LineF;
    struct LineF {
        QT::real x1;
        QT::real y1;
        QT::real x2;
        QT::real y2;
    };
    
    /*  ::Qt::ListWidget */
    DB_CLASS(listWidget);
    DB_CLASS_DEF(listWidget) {
        DB_EXTEND(QT::widget);
        hyve::ll_h items;
        ::hyve::lang::uint32 currentIndex;
        ::hyve::lang::string currentText;
    };
    
    /*  ::Qt::MainWindow */
    DB_CLASS(mainWindow);
    DB_CLASS_DEF(mainWindow) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::string title;
        ::hyve::lang::word cw;
    };
    
    /*  ::Qt::ObjectBrowse */
    DB_CLASS(objectBrowse);
    DB_CLASS_DEF(objectBrowse) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::object object;
        ::hyve::lang::object prevObject;
        ::hyve::lang::string expr;
        ::hyve::lang::_bool showPrimitives;
    };
    
    /* ::Qt::TileMode */
    typedef enum TileMode {
        TileNone = 0,
        TileSmall = 1,
        TileNormal = 2,
        TileLarge = 3
    } TileMode;
    
    /*  ::Qt::Tile */
    DB_CLASS(tile);
    DB_CLASS_DEF(tile) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::string title;
        QT::Color textColor;
        QT::Color foregroundColor;
        QT::Color backgroundColor;
        QT::TileMode mode;
        ::hyve::lang::_bool isRoot;
        QT::tile rootTile;
        ::hyve::lang::word scope;
    };
    
    /*  ::Qt::ObjectTile */
    DB_CLASS(objectTile);
    DB_CLASS_DEF(objectTile) {
        DB_EXTEND(QT::tile);
        ::hyve::lang::string scope;
        ::hyve::lang::word scopeCache;
    };
    
    /*  ::Qt::ObjectTree */
    DB_CLASS(objectTree);
    DB_CLASS_DEF(objectTree) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::object scope;
        ::hyve::lang::object object;
    };
    
    /*  ::Qt::ObjectView */
    DB_CLASS(objectView);
    DB_CLASS_DEF(objectView) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::object object;
        ::hyve::lang::string expr;
        ::hyve::lang::_bool showHeaders;
        ::hyve::lang::string_seq fields;
        ::hyve::lang::string selected;
        ::hyve::lang::uint32 selectedElement;
    };
    
    /* ::Qt::Orientation */
    typedef enum Orientation {
        Horizontal = 1,
        Vertical = 2
    } Orientation;
    DB_SEQUENCE(Line_seq, QT::Line,/* No postfix */);
    DB_SEQUENCE(LineF_seq, QT::LineF,/* No postfix */);
    
    /*  ::Qt::Point */
    typedef struct Point Point;
    struct Point {
        ::hyve::lang::int32 x;
        ::hyve::lang::int32 y;
    };
    DB_SEQUENCE(Point_seq, QT::Point,/* No postfix */);
    DB_SEQUENCE(PointF_seq, QT::PointF,/* No postfix */);
    
    /*  ::Qt::Rect */
    typedef struct Rect Rect;
    struct Rect {
        ::hyve::lang::uint32 left;
        ::hyve::lang::uint32 top;
        ::hyve::lang::uint32 width;
        ::hyve::lang::uint32 height;
    };
    DB_SEQUENCE(Rect_seq, QT::Rect,/* No postfix */);
    
    /*  ::Qt::RectF */
    typedef struct RectF RectF;
    struct RectF {
        QT::real left;
        QT::real top;
        QT::real width;
        QT::real height;
    };
    DB_SEQUENCE(RectF_seq, QT::RectF,/* No postfix */);
    
    /*  ::Qt::ProgressBar */
    DB_CLASS(progressBar);
    DB_CLASS_DEF(progressBar) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::int32 minimum;
        ::hyve::lang::int32 maximum;
        ::hyve::lang::int32 value;
        QT::Orientation orientation;
        ::hyve::lang::string text;
        ::hyve::lang::string format;
    };
    
    /*  ::Qt::PushButton */
    DB_CLASS(pushButton);
    DB_CLASS_DEF(pushButton) {
        DB_EXTEND(QT::abstractButton);
    };
    
    /*  ::Qt::RadialGradient */
    DB_CLASS(radialGradient);
    DB_CLASS_DEF(radialGradient) {
        DB_EXTEND(QT::gradient);
        QT::PointF center;
        QT::PointF focalPoint;
        QT::real radius;
    };
    
    /*  ::Qt::RadioButton */
    DB_CLASS(radioButton);
    DB_CLASS_DEF(radioButton) {
        DB_EXTEND(QT::abstractButton);
    };
    
    /*  ::Qt::Slider */
    DB_CLASS(slider);
    DB_CLASS_DEF(slider) {
        DB_EXTEND(QT::widget);
        ::hyve::lang::int32 value;
        ::hyve::lang::int32 minimum;
        ::hyve::lang::int32 maximum;
        ::hyve::lang::int32 singleStep;
        QT::Orientation orientation;
    };
    
    /*  ::Qt::slot */
    DB_CLASS(slot);
    DB_CLASS_DEF(slot) {
        DB_EXTEND(::hyve::lang::member);
    };
    
    /*  ::Qt::SplitterItem */
    typedef struct SplitterItem SplitterItem;
    struct SplitterItem {
        QT::widget widget;
        ::hyve::lang::uint32 width;
        ::hyve::lang::uint32 stretch;
    };
    DB_SEQUENCE(SplitterItem_seq, QT::SplitterItem,/* No postfix */);
    
    /*  ::Qt::Splitter */
    DB_CLASS(splitter);
    DB_CLASS_DEF(splitter) {
        DB_EXTEND(QT::widget);
        QT::SplitterItem_seq widgets;
        QT::Orientation orientation;
    };
    
    /*  ::Qt::TabWidgetTab */
    typedef struct TabWidgetTab TabWidgetTab;
    struct TabWidgetTab {
        ::hyve::lang::string label;
        QT::widget widget;
    };
    
    /*  ::Qt::TabWidget */
    DB_CLASS(tabWidget);
    DB_CLASS_DEF(tabWidget) {
        DB_EXTEND(QT::widget);
        hyve::ll_h tabs;
        ::hyve::lang::_bool closable;
        ::hyve::lang::_bool movable;
        ::hyve::lang::uint32 currentIndex;
        QT::widget currentWidget;
        ::hyve::lang::uint32 count;
    };
}

#endif

