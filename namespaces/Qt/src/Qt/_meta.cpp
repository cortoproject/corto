/* src/Qt/_meta.cpp
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "Qt/_type.hpp"
#include "hyve.hpp"

#include "Qt/Tile.hpp"
#include "Qt/Widget.hpp"
#include "Qt/TabWidget.hpp"
#include "Qt/Splitter.hpp"
#include "Qt/Slot.hpp"
#include "Qt/Slider.hpp"
#include "hyve/lang/Typedef.hpp"
#include "Qt/RadioButton.hpp"
#include "Qt/RadialGradient.hpp"
#include "Qt/PushButton.hpp"
#include "Qt/ProgressBar.hpp"
#include "Qt/PaintEvent_t.hpp"
#include "Qt/Pen.hpp"
#include "Qt/Painter.hpp"
#include "hyve/lang/Interface.hpp"
#include "Qt/PaintDevice.hpp"
#include "Qt/ObjectView.hpp"
#include "Qt/ObjectTree.hpp"
#include "Qt/ObjectTile.hpp"
#include "Qt/ObjectBrowse.hpp"
#include "Qt/Object.hpp"
#include "Qt/MouseEvent_t.hpp"
#include "Qt/MainWindow.hpp"
#include "Qt/ListWidget.hpp"
#include "Qt/LineEdit.hpp"
#include "Qt/LinearGradient.hpp"
#include "Qt/Label.hpp"
#include "hyve/lang/Bitmask.hpp"
#include "Qt/InputEvent_t.hpp"
#include "Qt/GroupBox.hpp"
#include "Qt/GridLayout.hpp"
#include "Qt/Gradient.hpp"
#include "Qt/Font.hpp"
#include "Qt/EnumComboBox.hpp"
#include "Qt/CustomPlot.hpp"
#include "Qt/ConicalGradient.hpp"
#include "Qt/ComboBox.hpp"
#include "hyve/lang/Struct.hpp"
#include "Qt/CheckBox.hpp"
#include "Qt/Brush.hpp"
#include "hyve/lang/Event.hpp"
#include "hyve/lang/ObservableEvent.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Application.hpp"
#include "hyve/lang/Enum.hpp"
#include "hyve/lang/Callback.hpp"
#include "hyve/lang/Member.hpp"
#include "hyve/lang/Class.hpp"
#include "Qt/AbstractButton.hpp"

/* Variable definitions */
::hyve::lang::object QT_h;
namespace QT {
    ::hyve::lang::_class AbstractButton_h;
    ::hyve::lang::Class (*AbstractButton_o);
    ::hyve::lang::member AbstractButton_checkable_h;
    ::hyve::lang::member AbstractButton_checked_h;
    ::hyve::lang::callback AbstractButton_construct_h;
    ::hyve::lang::callback AbstractButton_destruct_h;
    ::hyve::lang::member AbstractButton_down_h;
    ::hyve::lang::member AbstractButton_text_h;
    ::hyve::lang::_enum Alignment_h;
    ::hyve::lang::constant *Alignment_AlignBottom_h;
    ::hyve::lang::constant *Alignment_AlignCenter_h;
    ::hyve::lang::constant *Alignment_AlignHCenter_h;
    ::hyve::lang::constant *Alignment_AlignJustify_h;
    ::hyve::lang::constant *Alignment_AlignLeft_h;
    ::hyve::lang::constant *Alignment_AlignRight_h;
    ::hyve::lang::constant *Alignment_AlignTop_h;
    ::hyve::lang::constant *Alignment_AlignVCenter_h;
    ::hyve::lang::_class Application_h;
    ::hyve::lang::Class (*Application_o);
    ::hyve::lang::member Application_arg_h;
    ::hyve::lang::callback Application_construct_h;
    ::hyve::lang::callback Application_destruct_h;
    ::hyve::lang::method Application_exec_h;
    ::hyve::lang::method Application_getEvent_h;
    ::hyve::lang::callback Application_init_h;
    ::hyve::lang::method Application_post_h;
    ::hyve::lang::member Application_stylesheet_h;
    ::hyve::lang::_class Brush_h;
    ::hyve::lang::Class (*Brush_o);
    ::hyve::lang::member Brush_color_h;
    ::hyve::lang::callback Brush_construct_h;
    ::hyve::lang::callback Brush_destruct_h;
    ::hyve::lang::member Brush_gradient_h;
    ::hyve::lang::_class CheckBox_h;
    ::hyve::lang::Class (*CheckBox_o);
    ::hyve::lang::callback CheckBox_construct_h;
    ::hyve::lang::callback CheckBox_destruct_h;
    ::hyve::lang::observer CheckBox_onSelf_h;
    ::hyve::lang::_struct Color_h;
    ::hyve::lang::member Color_alpha_h;
    ::hyve::lang::member Color_b_h;
    ::hyve::lang::member Color_g_h;
    ::hyve::lang::member Color_r_h;
    ::hyve::lang::_class ComboBox_h;
    ::hyve::lang::Class (*ComboBox_o);
    ::hyve::lang::callback ComboBox_construct_h;
    ::hyve::lang::member ComboBox_currentIndex_h;
    ::hyve::lang::member ComboBox_currentText_h;
    ::hyve::lang::callback ComboBox_destruct_h;
    ::hyve::lang::member ComboBox_items_h;
    ::hyve::lang::observer ComboBox_onSelf_h;
    ::hyve::lang::_class ConicalGradient_h;
    ::hyve::lang::Class (*ConicalGradient_o);
    ::hyve::lang::member ConicalGradient_angle_h;
    ::hyve::lang::member ConicalGradient_center_h;
    ::hyve::lang::callback ConicalGradient_init_h;
    ::hyve::lang::_class CustomPlot_h;
    ::hyve::lang::Class (*CustomPlot_o);
    ::hyve::lang::member CustomPlot_autoX_h;
    ::hyve::lang::callback CustomPlot_construct_h;
    ::hyve::lang::callback CustomPlot_destruct_h;
    ::hyve::lang::member CustomPlot_expr_h;
    ::hyve::lang::callback CustomPlot_init_h;
    ::hyve::lang::member CustomPlot_object_h;
    ::hyve::lang::observer CustomPlot_onDestruct_h;
    ::hyve::lang::observer CustomPlot_onSelf_h;
    ::hyve::lang::observer CustomPlot_onUpdate_h;
    ::hyve::lang::_class EnumComboBox_h;
    ::hyve::lang::Class (*EnumComboBox_o);
    ::hyve::lang::callback EnumComboBox_construct_h;
    ::hyve::lang::callback EnumComboBox_destruct_h;
    ::hyve::lang::member EnumComboBox_type_h;
    ::hyve::lang::member EnumComboBox_value_h;
    ::hyve::lang::_class Font_h;
    ::hyve::lang::Class (*Font_o);
    ::hyve::lang::callback Font_construct_h;
    ::hyve::lang::callback Font_destruct_h;
    ::hyve::lang::member Font_family_h;
    ::hyve::lang::member Font_italic_h;
    ::hyve::lang::member Font_pointSize_h;
    ::hyve::lang::member Font_weight_h;
    ::hyve::lang::_enum FontWeight_h;
    ::hyve::lang::constant *FontWeight_Black_h;
    ::hyve::lang::constant *FontWeight_Bold_h;
    ::hyve::lang::constant *FontWeight_DemiBold_h;
    ::hyve::lang::constant *FontWeight_Light_h;
    ::hyve::lang::constant *FontWeight_Normal_h;
    ::hyve::lang::_class Gradient_h;
    ::hyve::lang::Class (*Gradient_o);
    ::hyve::lang::member Gradient_coordinateMode_h;
    ::hyve::lang::member Gradient_kind_h;
    ::hyve::lang::member Gradient_spread_h;
    ::hyve::lang::member Gradient_stops_h;
    ::hyve::lang::_enum GradientCoordinateMode_h;
    ::hyve::lang::constant *GradientCoordinateMode_LogicalMode_h;
    ::hyve::lang::constant *GradientCoordinateMode_ObjectBoundingMode_h;
    ::hyve::lang::constant *GradientCoordinateMode_StretchToDeviceMode_h;
    ::hyve::lang::_enum GradientKind_h;
    ::hyve::lang::constant *GradientKind_Conical_h;
    ::hyve::lang::constant *GradientKind_Linear_h;
    ::hyve::lang::constant *GradientKind_Radial_h;
    ::hyve::lang::_enum GradientSpread_h;
    ::hyve::lang::constant *GradientSpread_PadSpead_h;
    ::hyve::lang::constant *GradientSpread_ReflectSpread_h;
    ::hyve::lang::constant *GradientSpread_RepeatSpread_h;
    ::hyve::lang::_struct GradientStop_h;
    ::hyve::lang::member GradientStop_color_h;
    ::hyve::lang::member GradientStop_pos_h;
    ::hyve::lang::_struct GridColumn_h;
    ::hyve::lang::member GridColumn_minimumWidth_h;
    ::hyve::lang::member GridColumn_stretch_h;
    ::hyve::lang::_class GridLayout_h;
    ::hyve::lang::Class (*GridLayout_o);
    ::hyve::lang::member GridLayout_columns_h;
    ::hyve::lang::callback GridLayout_construct_h;
    ::hyve::lang::callback GridLayout_destruct_h;
    ::hyve::lang::observer GridLayout_onSelf_h;
    ::hyve::lang::member GridLayout_rows_h;
    ::hyve::lang::member GridLayout_widgets_h;
    ::hyve::lang::_struct GridRow_h;
    ::hyve::lang::member GridRow_minimumHeight_h;
    ::hyve::lang::member GridRow_stretch_h;
    ::hyve::lang::_struct GridWidget_h;
    ::hyve::lang::member GridWidget_column_h;
    ::hyve::lang::member GridWidget_columnspan_h;
    ::hyve::lang::member GridWidget_row_h;
    ::hyve::lang::member GridWidget_rowspan_h;
    ::hyve::lang::member GridWidget_widget_h;
    ::hyve::lang::_class GroupBox_h;
    ::hyve::lang::Class (*GroupBox_o);
    ::hyve::lang::callback GroupBox_construct_h;
    ::hyve::lang::callback GroupBox_destruct_h;
    ::hyve::lang::member GroupBox_title_h;
    ::hyve::lang::_class inputEvent_t_h;
    ::hyve::lang::Class (*inputEvent_t_o);
    ::hyve::lang::member inputEvent_t_modifiers_h;
    ::hyve::lang::bitmask KeyboardModifiers_h;
    ::hyve::lang::constant *KeyboardModifiers_AltModifier_h;
    ::hyve::lang::constant *KeyboardModifiers_ControlModifier_h;
    ::hyve::lang::constant *KeyboardModifiers_GroupSwitchModifier_h;
    ::hyve::lang::constant *KeyboardModifiers_KeypadModifier_h;
    ::hyve::lang::constant *KeyboardModifiers_MetaModifier_h;
    ::hyve::lang::constant *KeyboardModifiers_NoModifier_h;
    ::hyve::lang::constant *KeyboardModifiers_ShiftModifier_h;
    ::hyve::lang::_class Label_h;
    ::hyve::lang::Class (*Label_o);
    ::hyve::lang::member Label_alignment_h;
    ::hyve::lang::callback Label_construct_h;
    ::hyve::lang::callback Label_destruct_h;
    ::hyve::lang::callback Label_init_h;
    ::hyve::lang::observer Label_onSelf_h;
    ::hyve::lang::method Label_setText_h;
    ::hyve::lang::member Label_text_h;
    ::hyve::lang::_struct Line_h;
    ::hyve::lang::member Line_x1_h;
    ::hyve::lang::member Line_x2_h;
    ::hyve::lang::member Line_y1_h;
    ::hyve::lang::member Line_y2_h;
    ::hyve::lang::_class LinearGradient_h;
    ::hyve::lang::Class (*LinearGradient_o);
    ::hyve::lang::member LinearGradient_finalStop_h;
    ::hyve::lang::callback LinearGradient_init_h;
    ::hyve::lang::member LinearGradient_start_h;
    ::hyve::lang::_class LineEdit_h;
    ::hyve::lang::Class (*LineEdit_o);
    ::hyve::lang::callback LineEdit_construct_h;
    ::hyve::lang::callback LineEdit_destruct_h;
    ::hyve::lang::observer LineEdit_onSelf_h;
    ::hyve::lang::member LineEdit_readonly_h;
    ::hyve::lang::member LineEdit_text_h;
    ::hyve::lang::_struct LineF_h;
    ::hyve::lang::member LineF_x1_h;
    ::hyve::lang::member LineF_x2_h;
    ::hyve::lang::member LineF_y1_h;
    ::hyve::lang::member LineF_y2_h;
    ::hyve::lang::_class ListWidget_h;
    ::hyve::lang::Class (*ListWidget_o);
    ::hyve::lang::callback ListWidget_construct_h;
    ::hyve::lang::member ListWidget_currentIndex_h;
    ::hyve::lang::member ListWidget_currentText_h;
    ::hyve::lang::callback ListWidget_destruct_h;
    ::hyve::lang::method ListWidget_insertItem_h;
    ::hyve::lang::member ListWidget_items_h;
    ::hyve::lang::observer ListWidget_onSelf_h;
    ::hyve::lang::_class MainWindow_h;
    ::hyve::lang::Class (*MainWindow_o);
    ::hyve::lang::callback MainWindow_construct_h;
    ::hyve::lang::member MainWindow_cw_h;
    ::hyve::lang::callback MainWindow_destruct_h;
    ::hyve::lang::observer MainWindow_onSelf_h;
    ::hyve::lang::member MainWindow_title_h;
    ::hyve::lang::bitmask MouseButton_h;
    ::hyve::lang::constant *MouseButton_LeftButton_h;
    ::hyve::lang::constant *MouseButton_MidButton_h;
    ::hyve::lang::constant *MouseButton_MiddleButton_h;
    ::hyve::lang::constant *MouseButton_NoButton_h;
    ::hyve::lang::constant *MouseButton_RightButton_h;
    ::hyve::lang::constant *MouseButton_XButton1_h;
    ::hyve::lang::constant *MouseButton_XButton2_h;
    ::hyve::lang::_class mouseEvent_t_h;
    ::hyve::lang::Class (*mouseEvent_t_o);
    ::hyve::lang::member mouseEvent_t_buttons_h;
    ::hyve::lang::member mouseEvent_t_x_h;
    ::hyve::lang::member mouseEvent_t_y_h;
    ::hyve::lang::_class Object_h;
    ::hyve::lang::Class (*Object_o);
    ::hyve::lang::member Object_qhandle_h;
    ::hyve::lang::method Object_widgetParent_h;
    ::hyve::lang::_class ObjectBrowse_h;
    ::hyve::lang::Class (*ObjectBrowse_o);
    ::hyve::lang::callback ObjectBrowse_construct_h;
    ::hyve::lang::callback ObjectBrowse_destruct_h;
    ::hyve::lang::member ObjectBrowse_expr_h;
    ::hyve::lang::member ObjectBrowse_object_h;
    ::hyve::lang::observer ObjectBrowse_onDestruct_h;
    ::hyve::lang::observer ObjectBrowse_onSelf_h;
    ::hyve::lang::observer ObjectBrowse_onUpdate_h;
    ::hyve::lang::member ObjectBrowse_prevObject_h;
    ::hyve::lang::method ObjectBrowse_setObject_h;
    ::hyve::lang::member ObjectBrowse_showPrimitives_h;
    ::hyve::lang::_class ObjectTile_h;
    ::hyve::lang::Class (*ObjectTile_o);
    ::hyve::lang::callback ObjectTile_construct_h;
    ::hyve::lang::method ObjectTile_createTile_h;
    ::hyve::lang::callback ObjectTile_destruct_h;
    ::hyve::lang::observer ObjectTile_onDestruct_h;
    ::hyve::lang::observer ObjectTile_onNew_h;
    ::hyve::lang::member ObjectTile_scope_h;
    ::hyve::lang::member ObjectTile_scopeCache_h;
    ::hyve::lang::_class ObjectTree_h;
    ::hyve::lang::Class (*ObjectTree_o);
    ::hyve::lang::callback ObjectTree_construct_h;
    ::hyve::lang::callback ObjectTree_destruct_h;
    ::hyve::lang::callback ObjectTree_init_h;
    ::hyve::lang::member ObjectTree_object_h;
    ::hyve::lang::observer ObjectTree_onConstruct_h;
    ::hyve::lang::observer ObjectTree_onDestruct_h;
    ::hyve::lang::observer ObjectTree_onNew_h;
    ::hyve::lang::observer ObjectTree_onSelf_h;
    ::hyve::lang::member ObjectTree_scope_h;
    ::hyve::lang::_class ObjectView_h;
    ::hyve::lang::Class (*ObjectView_o);
    ::hyve::lang::callback ObjectView_construct_h;
    ::hyve::lang::callback ObjectView_destruct_h;
    ::hyve::lang::member ObjectView_expr_h;
    ::hyve::lang::member ObjectView_fields_h;
    ::hyve::lang::callback ObjectView_init_h;
    ::hyve::lang::member ObjectView_object_h;
    ::hyve::lang::observer ObjectView_onDestruct_h;
    ::hyve::lang::observer ObjectView_onSelf_h;
    ::hyve::lang::observer ObjectView_onUpdate_h;
    ::hyve::lang::member ObjectView_selected_h;
    ::hyve::lang::member ObjectView_selectedElement_h;
    ::hyve::lang::method ObjectView_setObject_h;
    ::hyve::lang::member ObjectView_showHeaders_h;
    ::hyve::lang::method ObjectView_updateObject_h;
    ::hyve::lang::_enum Orientation_h;
    ::hyve::lang::constant *Orientation_Horizontal_h;
    ::hyve::lang::constant *Orientation_Vertical_h;
    ::hyve::lang::interface PaintDevice_h;
    ::hyve::lang::Interface (*PaintDevice_o);
    ::hyve::lang::_class Painter_h;
    ::hyve::lang::Class (*Painter_o);
    ::hyve::lang::method Painter_begin_h;
    ::hyve::lang::member Painter_brush_h;
    ::hyve::lang::callback Painter_construct_h;
    ::hyve::lang::callback Painter_destruct_h;
    ::hyve::lang::member Painter_device_h;
    ::hyve::lang::method Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h;
    ::hyve::lang::method Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h;
    ::hyve::lang::method Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h;
    ::hyve::lang::method Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawEllipse_QtRect_h;
    ::hyve::lang::method Painter_drawEllipse_QtRectF_h;
    ::hyve::lang::method Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h;
    ::hyve::lang::method Painter_drawLine_QtLine_h;
    ::hyve::lang::method Painter_drawLine_QtLineF_h;
    ::hyve::lang::method Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawLines_hyvelangsequence_QtLine_0_h;
    ::hyve::lang::method Painter_drawLines_hyvelangsequence_QtLineF_0_h;
    ::hyve::lang::method Painter_drawPoint_QtPoint_h;
    ::hyve::lang::method Painter_drawPoint_QtPointF_h;
    ::hyve::lang::method Painter_drawPoints_hyvelangsequence_QtPoint_0_h;
    ::hyve::lang::method Painter_drawPoints_hyvelangsequence_QtPointF_0_h;
    ::hyve::lang::method Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h;
    ::hyve::lang::method Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawRect_QtRect_h;
    ::hyve::lang::method Painter_drawRect_QtRectF_h;
    ::hyve::lang::method Painter_drawRects_hyvelangsequence_QtRect_0_h;
    ::hyve::lang::method Painter_drawRects_hyvelangsequence_QtRectF_0_h;
    ::hyve::lang::method Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_QtRect_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_QtRectF_Qtreal_h;
    ::hyve::lang::method Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_drawText_QtPoint_hyvelangstring_h;
    ::hyve::lang::method Painter_drawText_QtPointF_hyvelangstring_h;
    ::hyve::lang::method Painter_drawText_QtRect_QtAlignment_hyvelangstring_h;
    ::hyve::lang::method Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h;
    ::hyve::lang::method Painter_end_h;
    ::hyve::lang::member Painter_pen_h;
    ::hyve::lang::method Painter_restore_h;
    ::hyve::lang::method Painter_save_h;
    ::hyve::lang::method Painter_scale_h;
    ::hyve::lang::method Painter_setBrush_h;
    ::hyve::lang::method Painter_setFont_h;
    ::hyve::lang::method Painter_setPen_h;
    ::hyve::lang::method Painter_translate_hyvelangint32_hyvelangint32_h;
    ::hyve::lang::method Painter_translate_QtPoint_h;
    ::hyve::lang::method Painter_translate_QtPointF_h;
    ::hyve::lang::method Painter_translate_Qtreal_Qtreal_h;
    ::hyve::lang::method Painter_viewport_h;
    ::hyve::lang::_class paintEvent_t_h;
    ::hyve::lang::Class (*paintEvent_t_o);
    ::hyve::lang::member paintEvent_t_painter_h;
    ::hyve::lang::_class Pen_h;
    ::hyve::lang::Class (*Pen_o);
    ::hyve::lang::member Pen_color_h;
    ::hyve::lang::callback Pen_construct_h;
    ::hyve::lang::callback Pen_destruct_h;
    ::hyve::lang::member Pen_width_h;
    ::hyve::lang::_struct Point_h;
    ::hyve::lang::member Point_x_h;
    ::hyve::lang::member Point_y_h;
    ::hyve::lang::_struct PointF_h;
    ::hyve::lang::member PointF_x_h;
    ::hyve::lang::member PointF_y_h;
    ::hyve::lang::_class ProgressBar_h;
    ::hyve::lang::Class (*ProgressBar_o);
    ::hyve::lang::callback ProgressBar_construct_h;
    ::hyve::lang::callback ProgressBar_destruct_h;
    ::hyve::lang::member ProgressBar_format_h;
    ::hyve::lang::member ProgressBar_maximum_h;
    ::hyve::lang::member ProgressBar_minimum_h;
    ::hyve::lang::observer ProgressBar_onSelf_h;
    ::hyve::lang::member ProgressBar_orientation_h;
    ::hyve::lang::member ProgressBar_text_h;
    ::hyve::lang::member ProgressBar_value_h;
    ::hyve::lang::_class PushButton_h;
    ::hyve::lang::Class (*PushButton_o);
    ::hyve::lang::callback PushButton_construct_h;
    ::hyve::lang::callback PushButton_destruct_h;
    ::hyve::lang::observer PushButton_onSelf_h;
    ::hyve::lang::_class RadialGradient_h;
    ::hyve::lang::Class (*RadialGradient_o);
    ::hyve::lang::member RadialGradient_center_h;
    ::hyve::lang::member RadialGradient_focalPoint_h;
    ::hyve::lang::callback RadialGradient_init_h;
    ::hyve::lang::member RadialGradient_radius_h;
    ::hyve::lang::_class RadioButton_h;
    ::hyve::lang::Class (*RadioButton_o);
    ::hyve::lang::callback RadioButton_construct_h;
    ::hyve::lang::callback RadioButton_destruct_h;
    ::hyve::lang::observer RadioButton_onSelf_h;
    ::hyve::lang::_typedef real_h;
    ::hyve::lang::_struct Rect_h;
    ::hyve::lang::member Rect_height_h;
    ::hyve::lang::member Rect_left_h;
    ::hyve::lang::member Rect_top_h;
    ::hyve::lang::member Rect_width_h;
    ::hyve::lang::_struct RectF_h;
    ::hyve::lang::member RectF_height_h;
    ::hyve::lang::member RectF_left_h;
    ::hyve::lang::member RectF_top_h;
    ::hyve::lang::member RectF_width_h;
    ::hyve::lang::_class Slider_h;
    ::hyve::lang::Class (*Slider_o);
    ::hyve::lang::callback Slider_construct_h;
    ::hyve::lang::callback Slider_destruct_h;
    ::hyve::lang::member Slider_maximum_h;
    ::hyve::lang::member Slider_minimum_h;
    ::hyve::lang::observer Slider_onSelf_h;
    ::hyve::lang::member Slider_orientation_h;
    ::hyve::lang::member Slider_singleStep_h;
    ::hyve::lang::member Slider_value_h;
    ::hyve::lang::_class slot_h;
    ::hyve::lang::Class (*slot_o);
    ::hyve::lang::callback slot_construct_h;
    ::hyve::lang::_class Splitter_h;
    ::hyve::lang::Class (*Splitter_o);
    ::hyve::lang::callback Splitter_construct_h;
    ::hyve::lang::callback Splitter_destruct_h;
    ::hyve::lang::callback Splitter_init_h;
    ::hyve::lang::observer Splitter_onSelf_h;
    ::hyve::lang::member Splitter_orientation_h;
    ::hyve::lang::member Splitter_widgets_h;
    ::hyve::lang::_struct SplitterItem_h;
    ::hyve::lang::member SplitterItem_stretch_h;
    ::hyve::lang::member SplitterItem_widget_h;
    ::hyve::lang::member SplitterItem_width_h;
    ::hyve::lang::_class TabWidget_h;
    ::hyve::lang::Class (*TabWidget_o);
    ::hyve::lang::method TabWidget_addTab_h;
    ::hyve::lang::member TabWidget_closable_h;
    ::hyve::lang::callback TabWidget_construct_h;
    ::hyve::lang::member TabWidget_count_h;
    ::hyve::lang::member TabWidget_currentIndex_h;
    ::hyve::lang::member TabWidget_currentWidget_h;
    ::hyve::lang::callback TabWidget_destruct_h;
    ::hyve::lang::member TabWidget_movable_h;
    ::hyve::lang::member TabWidget_tabs_h;
    ::hyve::lang::_struct TabWidgetTab_h;
    ::hyve::lang::member TabWidgetTab_label_h;
    ::hyve::lang::member TabWidgetTab_widget_h;
    ::hyve::lang::_class Tile_h;
    ::hyve::lang::Class (*Tile_o);
    ::hyve::lang::member Tile_backgroundColor_h;
    ::hyve::lang::callback Tile_construct_h;
    ::hyve::lang::callback Tile_destruct_h;
    ::hyve::lang::member Tile_foregroundColor_h;
    ::hyve::lang::callback Tile_init_h;
    ::hyve::lang::member Tile_isRoot_h;
    ::hyve::lang::member Tile_mode_h;
    ::hyve::lang::observer Tile_onDefine_h;
    ::hyve::lang::observer Tile_onDestruct_h;
    ::hyve::lang::observer Tile_onSelf_h;
    ::hyve::lang::method Tile_pulse_h;
    ::hyve::lang::member Tile_rootTile_h;
    ::hyve::lang::member Tile_scope_h;
    ::hyve::lang::member Tile_textColor_h;
    ::hyve::lang::member Tile_title_h;
    ::hyve::lang::_enum TileMode_h;
    ::hyve::lang::constant *TileMode_TileLarge_h;
    ::hyve::lang::constant *TileMode_TileNone_h;
    ::hyve::lang::constant *TileMode_TileNormal_h;
    ::hyve::lang::constant *TileMode_TileSmall_h;
    ::hyve::lang::_class Widget_h;
    ::hyve::lang::Class (*Widget_o);
    ::hyve::lang::callback Widget_construct_h;
    ::hyve::lang::callback Widget_destruct_h;
    ::hyve::lang::member Widget_enabled_h;
    ::hyve::lang::member Widget_height_h;
    ::hyve::lang::method Widget_hide_h;
    ::hyve::lang::callback Widget_init_h;
    QT::slot Widget_mousePressEvent_h;
    ::hyve::lang::member Widget_painter_h;
    QT::slot Widget_paintEvent_h;
    ::hyve::lang::member Widget_qslots_h;
    ::hyve::lang::method Widget_repaint_h;
    ::hyve::lang::method Widget_show_h;
    ::hyve::lang::member Widget_styleSheet_h;
    ::hyve::lang::member Widget_visible_h;
    ::hyve::lang::member Widget_width_h;
    ::hyve::lang::member Widget_x_h;
    ::hyve::lang::member Widget_y_h;
    ::hyve::lang::int16 __cpp_AbstractButton_construct(QT::abstractButton object) {
        QT::AbstractButton _object(object,FALSE);
        return QT::AbstractButton::construct(_object);
    }
    ::hyve::lang::_void __cpp_AbstractButton_destruct(QT::abstractButton object) {
        QT::AbstractButton _object(object,FALSE);
        QT::AbstractButton::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Application_construct(QT::application object) {
        QT::Application _object(object,FALSE);
        return QT::Application::construct(_object);
    }
    ::hyve::lang::_void __cpp_Application_destruct(QT::application object) {
        QT::Application _object(object,FALSE);
        QT::Application::destruct(_object);
    }
    ::hyve::lang::_void __cpp_Application_exec(QT::application _this) {
        QT::Application proxy(_this,FALSE);
        proxy.exec();
    }
    ::hyve::lang::observableEvent __cpp_Application_getEvent(QT::application _this, ::hyve::lang::observer observer, ::hyve::lang::object me, ::hyve::lang::object observable, ::hyve::lang::object src) {
        QT::Application proxy(_this,FALSE);
        ::hyve::lang::Observer _observer(observer,FALSE);
        ::hyve::lang::Object _me(me,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _src(src,FALSE);
        return proxy.getEvent(_observer, _me, _observable, _src)._handle();
    }
    ::hyve::lang::int16 __cpp_Application_init(QT::application object) {
        QT::Application _object(object,FALSE);
        return QT::Application::init(_object);
    }
    ::hyve::lang::_void __cpp_Application_post(QT::application _this, ::hyve::lang::event event) {
        QT::Application proxy(_this,FALSE);
        ::hyve::lang::Event _event(event,FALSE);
        proxy.post(_event);
    }
    ::hyve::lang::int16 __cpp_Brush_construct(QT::brush object) {
        QT::Brush _object(object,FALSE);
        return QT::Brush::construct(_object);
    }
    ::hyve::lang::_void __cpp_Brush_destruct(QT::brush object) {
        QT::Brush _object(object,FALSE);
        QT::Brush::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_CheckBox_construct(QT::checkBox object) {
        QT::CheckBox _object(object,FALSE);
        return QT::CheckBox::construct(_object);
    }
    ::hyve::lang::_void __cpp_CheckBox_destruct(QT::checkBox object) {
        QT::CheckBox _object(object,FALSE);
        QT::CheckBox::destruct(_object);
    }
    ::hyve::lang::_void __cpp_CheckBox_onSelf(QT::checkBox _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::CheckBox proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_ComboBox_construct(QT::comboBox object) {
        QT::ComboBox _object(object,FALSE);
        return QT::ComboBox::construct(_object);
    }
    ::hyve::lang::_void __cpp_ComboBox_destruct(QT::comboBox object) {
        QT::ComboBox _object(object,FALSE);
        QT::ComboBox::destruct(_object);
    }
    ::hyve::lang::_void __cpp_ComboBox_onSelf(QT::comboBox _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ComboBox proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_ConicalGradient_init(QT::conicalGradient object) {
        QT::ConicalGradient _object(object,FALSE);
        return QT::ConicalGradient::init(_object);
    }
    ::hyve::lang::int16 __cpp_CustomPlot_construct(QT::customPlot object) {
        QT::CustomPlot _object(object,FALSE);
        return QT::CustomPlot::construct(_object);
    }
    ::hyve::lang::int16 __cpp_CustomPlot_destruct(QT::customPlot object) {
        QT::CustomPlot _object(object,FALSE);
        return QT::CustomPlot::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_CustomPlot_init(QT::customPlot object) {
        QT::CustomPlot _object(object,FALSE);
        return QT::CustomPlot::init(_object);
    }
    ::hyve::lang::_void __cpp_CustomPlot_onDestruct(QT::customPlot _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::CustomPlot proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDestruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_CustomPlot_onSelf(QT::customPlot _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::CustomPlot proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::_void __cpp_CustomPlot_onUpdate(QT::customPlot _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::CustomPlot proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onUpdate(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_EnumComboBox_construct(QT::enumComboBox object) {
        QT::EnumComboBox _object(object,FALSE);
        return QT::EnumComboBox::construct(_object);
    }
    ::hyve::lang::_void __cpp_EnumComboBox_destruct(QT::enumComboBox object) {
        QT::EnumComboBox _object(object,FALSE);
        QT::EnumComboBox::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Font_construct(QT::font object) {
        QT::Font _object(object,FALSE);
        return QT::Font::construct(_object);
    }
    ::hyve::lang::_void __cpp_Font_destruct(QT::font object) {
        QT::Font _object(object,FALSE);
        QT::Font::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_GridLayout_construct(QT::gridLayout object) {
        QT::GridLayout _object(object,FALSE);
        return QT::GridLayout::construct(_object);
    }
    ::hyve::lang::_void __cpp_GridLayout_destruct(QT::gridLayout object) {
        QT::GridLayout _object(object,FALSE);
        QT::GridLayout::destruct(_object);
    }
    ::hyve::lang::_void __cpp_GridLayout_onSelf(QT::gridLayout _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::GridLayout proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_GroupBox_construct(QT::groupBox object) {
        QT::GroupBox _object(object,FALSE);
        return QT::GroupBox::construct(_object);
    }
    ::hyve::lang::_void __cpp_GroupBox_destruct(QT::groupBox object) {
        QT::GroupBox _object(object,FALSE);
        QT::GroupBox::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Label_construct(QT::label object) {
        QT::Label _object(object,FALSE);
        return QT::Label::construct(_object);
    }
    ::hyve::lang::_void __cpp_Label_destruct(QT::label object) {
        QT::Label _object(object,FALSE);
        QT::Label::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Label_init(QT::label object) {
        QT::Label _object(object,FALSE);
        return QT::Label::init(_object);
    }
    ::hyve::lang::_void __cpp_Label_onSelf(QT::label _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::Label proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::_void __cpp_Label_setText(QT::label _this, ::hyve::lang::string text) {
        QT::Label proxy(_this,FALSE);
        proxy.setText(text);
    }
    ::hyve::lang::int16 __cpp_LinearGradient_init(QT::linearGradient object) {
        QT::LinearGradient _object(object,FALSE);
        return QT::LinearGradient::init(_object);
    }
    ::hyve::lang::int16 __cpp_LineEdit_construct(QT::lineEdit object) {
        QT::LineEdit _object(object,FALSE);
        return QT::LineEdit::construct(_object);
    }
    ::hyve::lang::_void __cpp_LineEdit_destruct(QT::lineEdit object) {
        QT::LineEdit _object(object,FALSE);
        QT::LineEdit::destruct(_object);
    }
    ::hyve::lang::_void __cpp_LineEdit_onSelf(QT::lineEdit _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::LineEdit proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_ListWidget_construct(QT::listWidget object) {
        QT::ListWidget _object(object,FALSE);
        return QT::ListWidget::construct(_object);
    }
    ::hyve::lang::_void __cpp_ListWidget_destruct(QT::listWidget object) {
        QT::ListWidget _object(object,FALSE);
        QT::ListWidget::destruct(_object);
    }
    ::hyve::lang::_void __cpp_ListWidget_insertItem(QT::listWidget _this, ::hyve::lang::string label) {
        QT::ListWidget proxy(_this,FALSE);
        proxy.insertItem(label);
    }
    ::hyve::lang::_void __cpp_ListWidget_onSelf(QT::listWidget _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ListWidget proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_MainWindow_construct(QT::mainWindow object) {
        QT::MainWindow _object(object,FALSE);
        return QT::MainWindow::construct(_object);
    }
    ::hyve::lang::_void __cpp_MainWindow_destruct(QT::mainWindow object) {
        QT::MainWindow _object(object,FALSE);
        QT::MainWindow::destruct(_object);
    }
    ::hyve::lang::_void __cpp_MainWindow_onSelf(QT::mainWindow _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::MainWindow proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::word __cpp_Object_widgetParent(QT::object _this) {
        QT::Object proxy(_this,FALSE);
        return proxy.widgetParent();
    }
    ::hyve::lang::int16 __cpp_ObjectBrowse_construct(QT::objectBrowse object) {
        QT::ObjectBrowse _object(object,FALSE);
        return QT::ObjectBrowse::construct(_object);
    }
    ::hyve::lang::_void __cpp_ObjectBrowse_destruct(QT::objectBrowse object) {
        QT::ObjectBrowse _object(object,FALSE);
        QT::ObjectBrowse::destruct(_object);
    }
    ::hyve::lang::_void __cpp_ObjectBrowse_onDestruct(QT::objectBrowse _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectBrowse proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDestruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectBrowse_onSelf(QT::objectBrowse _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectBrowse proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectBrowse_onUpdate(QT::objectBrowse _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectBrowse proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onUpdate(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectBrowse_setObject(QT::objectBrowse _this, ::hyve::lang::object object) {
        QT::ObjectBrowse proxy(_this,FALSE);
        ::hyve::lang::Object _object(object,FALSE);
        proxy.setObject(_object);
    }
    ::hyve::lang::int16 __cpp_ObjectTile_construct(QT::objectTile object) {
        QT::ObjectTile _object(object,FALSE);
        return QT::ObjectTile::construct(_object);
    }
    QT::objectTile __cpp_ObjectTile_createTile(QT::objectTile _this, ::hyve::lang::object obj) {
        QT::ObjectTile proxy(_this,FALSE);
        ::hyve::lang::Object _obj(obj,FALSE);
        return proxy.createTile_v(_obj)._handle();
    }
    ::hyve::lang::_void __cpp_ObjectTile_destruct(QT::objectTile object) {
        QT::ObjectTile _object(object,FALSE);
        QT::ObjectTile::destruct(_object);
    }
    ::hyve::lang::_void __cpp_ObjectTile_onDestruct(QT::objectTile _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectTile proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDestruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectTile_onNew(QT::objectTile _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectTile proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onNew(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_ObjectTree_construct(QT::objectTree object) {
        QT::ObjectTree _object(object,FALSE);
        return QT::ObjectTree::construct(_object);
    }
    ::hyve::lang::_void __cpp_ObjectTree_destruct(QT::objectTree object) {
        QT::ObjectTree _object(object,FALSE);
        QT::ObjectTree::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_ObjectTree_init(QT::objectTree object) {
        QT::ObjectTree _object(object,FALSE);
        return QT::ObjectTree::init(_object);
    }
    ::hyve::lang::_void __cpp_ObjectTree_onConstruct(QT::objectTree _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectTree proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onConstruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectTree_onDestruct(QT::objectTree _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectTree proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDestruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectTree_onNew(QT::objectTree _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectTree proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onNew(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectTree_onSelf(QT::objectTree _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectTree proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_ObjectView_construct(QT::objectView object) {
        QT::ObjectView _object(object,FALSE);
        return QT::ObjectView::construct(_object);
    }
    ::hyve::lang::_void __cpp_ObjectView_destruct(QT::objectView object) {
        QT::ObjectView _object(object,FALSE);
        QT::ObjectView::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_ObjectView_init(QT::objectView object) {
        QT::ObjectView _object(object,FALSE);
        return QT::ObjectView::init(_object);
    }
    ::hyve::lang::_void __cpp_ObjectView_onDestruct(QT::objectView _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectView proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDestruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectView_onSelf(QT::objectView _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectView proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectView_onUpdate(QT::objectView _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ObjectView proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onUpdate(_observable, _source);
    }
    ::hyve::lang::_void __cpp_ObjectView_setObject(QT::objectView _this, ::hyve::lang::object object) {
        QT::ObjectView proxy(_this,FALSE);
        ::hyve::lang::Object _object(object,FALSE);
        proxy.setObject(_object);
    }
    ::hyve::lang::_void __cpp_ObjectView_updateObject(QT::objectView _this) {
        QT::ObjectView proxy(_this,FALSE);
        proxy.updateObject();
    }
    ::hyve::lang::_void __cpp_Painter_begin(QT::painter _this) {
        QT::Painter proxy(_this,FALSE);
        proxy.begin();
    }
    ::hyve::lang::int16 __cpp_Painter_construct(QT::painter object) {
        QT::Painter _object(object,FALSE);
        return QT::Painter::construct(_object);
    }
    ::hyve::lang::_void __cpp_Painter_destruct(QT::painter object) {
        QT::Painter _object(object,FALSE);
        QT::Painter::destruct(_object);
    }
    ::hyve::lang::_void __cpp_Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64(QT::painter _this, ::hyve::lang::float64 x, ::hyve::lang::float64 y, ::hyve::lang::float64 r) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawEllipse(x, y, r);
    }
    ::hyve::lang::_void __cpp_Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32(QT::painter _this, ::hyve::lang::int32 top, ::hyve::lang::int32 left, ::hyve::lang::int32 width, ::hyve::lang::int32 height) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawEllipse(top, left, width, height);
    }
    ::hyve::lang::_void __cpp_Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32(QT::painter _this, ::hyve::lang::int32 x, ::hyve::lang::int32 y, ::hyve::lang::int32 r) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawEllipse(x, y, r);
    }
    ::hyve::lang::_void __cpp_Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal(QT::painter _this, QT::real top, QT::real left, QT::real width, QT::real height) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawEllipse(top, left, width, height);
    }
    ::hyve::lang::_void __cpp_Painter_drawEllipse_QtRect(QT::painter _this, QT::Rect rect) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawEllipse(rect);
    }
    ::hyve::lang::_void __cpp_Painter_drawEllipse_QtRectF(QT::painter _this, QT::RectF rect) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawEllipse(rect);
    }
    ::hyve::lang::_void __cpp_Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32(QT::painter _this, ::hyve::lang::int32 x1, ::hyve::lang::int32 y1, ::hyve::lang::int32 x2, ::hyve::lang::int32 y2) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawLine(x1, y1, x2, y2);
    }
    ::hyve::lang::_void __cpp_Painter_drawLine_QtLine(QT::painter _this, QT::Line line) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawLine(line);
    }
    ::hyve::lang::_void __cpp_Painter_drawLine_QtLineF(QT::painter _this, QT::LineF line) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawLine(line);
    }
    ::hyve::lang::_void __cpp_Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal(QT::painter _this, QT::real x1, QT::real y1, QT::real x2, QT::real y2) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawLine(x1, y1, x2, y2);
    }
    ::hyve::lang::_void __cpp_Painter_drawLines_hyvelangsequence_QtLine_0(QT::painter _this, QT::Line_seq lines) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawLines(lines);
    }
    ::hyve::lang::_void __cpp_Painter_drawLines_hyvelangsequence_QtLineF_0(QT::painter _this, QT::LineF_seq lines) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawLines(lines);
    }
    ::hyve::lang::_void __cpp_Painter_drawPoint_QtPoint(QT::painter _this, QT::Point point) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawPoint(point);
    }
    ::hyve::lang::_void __cpp_Painter_drawPoint_QtPointF(QT::painter _this, QT::PointF point) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawPoint(point);
    }
    ::hyve::lang::_void __cpp_Painter_drawPoints_hyvelangsequence_QtPoint_0(QT::painter _this, QT::Point_seq lines) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawPoints(lines);
    }
    ::hyve::lang::_void __cpp_Painter_drawPoints_hyvelangsequence_QtPointF_0(QT::painter _this, QT::PointF_seq lines) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawPoints(lines);
    }
    ::hyve::lang::_void __cpp_Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32(QT::painter _this, ::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRect(left, top, width, height);
    }
    ::hyve::lang::_void __cpp_Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal(QT::painter _this, QT::real left, QT::real top, QT::real width, QT::real height) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRect(left, top, width, height);
    }
    ::hyve::lang::_void __cpp_Painter_drawRect_QtRect(QT::painter _this, QT::Rect rect) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRect(rect);
    }
    ::hyve::lang::_void __cpp_Painter_drawRect_QtRectF(QT::painter _this, QT::RectF rect) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRect(rect);
    }
    ::hyve::lang::_void __cpp_Painter_drawRects_hyvelangsequence_QtRect_0(QT::painter _this, QT::Rect_seq rects) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRects(rects);
    }
    ::hyve::lang::_void __cpp_Painter_drawRects_hyvelangsequence_QtRectF_0(QT::painter _this, QT::RectF_seq rects) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRects(rects);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal(QT::painter _this, ::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height, QT::real radius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(left, top, width, height, radius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal(QT::painter _this, ::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height, QT::real xradius, QT::real yradius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(left, top, width, height, xradius, yradius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal(QT::painter _this, QT::real left, QT::real top, QT::real width, QT::real height, QT::real radius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(left, top, width, height, radius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal(QT::painter _this, QT::real left, QT::real top, QT::real width, QT::real height, QT::real xradius, QT::real yradius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(left, top, width, height, xradius, yradius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_QtRect_Qtreal(QT::painter _this, QT::Rect rect, QT::real radius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(rect, radius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_QtRect_Qtreal_Qtreal(QT::painter _this, QT::Rect rect, QT::real xradius, QT::real yradius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(rect, xradius, yradius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_QtRectF_Qtreal(QT::painter _this, QT::RectF rect, QT::real radius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(rect, radius);
    }
    ::hyve::lang::_void __cpp_Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal(QT::painter _this, QT::RectF rect, QT::real xradius, QT::real yradius) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawRoundedRect(rect, xradius, yradius);
    }
    ::hyve::lang::_void __cpp_Painter_drawText_QtPoint_hyvelangstring(QT::painter _this, QT::Point position, ::hyve::lang::string text) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawText(position, text);
    }
    ::hyve::lang::_void __cpp_Painter_drawText_QtPointF_hyvelangstring(QT::painter _this, QT::PointF position, ::hyve::lang::string text) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawText(position, text);
    }
    ::hyve::lang::_void __cpp_Painter_drawText_QtRect_QtAlignment_hyvelangstring(QT::painter _this, QT::Rect position, QT::Alignment alignment, ::hyve::lang::string text) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawText(position, alignment, text);
    }
    ::hyve::lang::_void __cpp_Painter_drawText_QtRectF_QtAlignment_hyvelangstring(QT::painter _this, QT::RectF position, QT::Alignment alignment, ::hyve::lang::string text) {
        QT::Painter proxy(_this,FALSE);
        proxy.drawText(position, alignment, text);
    }
    ::hyve::lang::_void __cpp_Painter_end(QT::painter _this) {
        QT::Painter proxy(_this,FALSE);
        proxy.end();
    }
    ::hyve::lang::_void __cpp_Painter_restore(QT::painter _this) {
        QT::Painter proxy(_this,FALSE);
        proxy.restore();
    }
    ::hyve::lang::_void __cpp_Painter_save(QT::painter _this) {
        QT::Painter proxy(_this,FALSE);
        proxy.save();
    }
    ::hyve::lang::_void __cpp_Painter_scale(QT::painter _this, QT::real sx, QT::real sy) {
        QT::Painter proxy(_this,FALSE);
        proxy.scale(sx, sy);
    }
    ::hyve::lang::_void __cpp_Painter_setBrush(QT::painter _this, QT::brush brush) {
        QT::Painter proxy(_this,FALSE);
        QT::Brush _brush(brush,FALSE);
        proxy.setBrush(_brush);
    }
    ::hyve::lang::_void __cpp_Painter_setFont(QT::painter _this, QT::font font) {
        QT::Painter proxy(_this,FALSE);
        QT::Font _font(font,FALSE);
        proxy.setFont(_font);
    }
    ::hyve::lang::_void __cpp_Painter_setPen(QT::painter _this, QT::pen pen) {
        QT::Painter proxy(_this,FALSE);
        QT::Pen _pen(pen,FALSE);
        proxy.setPen(_pen);
    }
    ::hyve::lang::_void __cpp_Painter_translate_hyvelangint32_hyvelangint32(QT::painter _this, ::hyve::lang::int32 x, ::hyve::lang::int32 y) {
        QT::Painter proxy(_this,FALSE);
        proxy.translate(x, y);
    }
    ::hyve::lang::_void __cpp_Painter_translate_QtPoint(QT::painter _this, QT::Point p) {
        QT::Painter proxy(_this,FALSE);
        proxy.translate(p);
    }
    ::hyve::lang::_void __cpp_Painter_translate_QtPointF(QT::painter _this, QT::PointF p) {
        QT::Painter proxy(_this,FALSE);
        proxy.translate(p);
    }
    ::hyve::lang::_void __cpp_Painter_translate_Qtreal_Qtreal(QT::painter _this, QT::real x, QT::real y) {
        QT::Painter proxy(_this,FALSE);
        proxy.translate(x, y);
    }
    QT::Rect __cpp_Painter_viewport(QT::painter _this) {
        QT::Painter proxy(_this,FALSE);
        return proxy.viewport();
    }
    ::hyve::lang::int16 __cpp_Pen_construct(QT::pen object) {
        QT::Pen _object(object,FALSE);
        return QT::Pen::construct(_object);
    }
    ::hyve::lang::_void __cpp_Pen_destruct(QT::pen object) {
        QT::Pen _object(object,FALSE);
        QT::Pen::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_ProgressBar_construct(QT::progressBar object) {
        QT::ProgressBar _object(object,FALSE);
        return QT::ProgressBar::construct(_object);
    }
    ::hyve::lang::_void __cpp_ProgressBar_destruct(QT::progressBar object) {
        QT::ProgressBar _object(object,FALSE);
        QT::ProgressBar::destruct(_object);
    }
    ::hyve::lang::_void __cpp_ProgressBar_onSelf(QT::progressBar _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::ProgressBar proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_PushButton_construct(QT::pushButton object) {
        QT::PushButton _object(object,FALSE);
        return QT::PushButton::construct(_object);
    }
    ::hyve::lang::_void __cpp_PushButton_destruct(QT::pushButton object) {
        QT::PushButton _object(object,FALSE);
        QT::PushButton::destruct(_object);
    }
    ::hyve::lang::_void __cpp_PushButton_onSelf(QT::pushButton _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::PushButton proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_RadialGradient_init(QT::radialGradient object) {
        QT::RadialGradient _object(object,FALSE);
        return QT::RadialGradient::init(_object);
    }
    ::hyve::lang::int16 __cpp_RadioButton_construct(QT::radioButton object) {
        QT::RadioButton _object(object,FALSE);
        return QT::RadioButton::construct(_object);
    }
    ::hyve::lang::_void __cpp_RadioButton_destruct(QT::radioButton object) {
        QT::RadioButton _object(object,FALSE);
        QT::RadioButton::destruct(_object);
    }
    ::hyve::lang::_void __cpp_RadioButton_onSelf(QT::radioButton _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::RadioButton proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_Slider_construct(QT::slider object) {
        QT::Slider _object(object,FALSE);
        return QT::Slider::construct(_object);
    }
    ::hyve::lang::_void __cpp_Slider_destruct(QT::slider object) {
        QT::Slider _object(object,FALSE);
        QT::Slider::destruct(_object);
    }
    ::hyve::lang::_void __cpp_Slider_onSelf(QT::slider _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::Slider proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::int16 __cpp_slot_construct(QT::slot object) {
        QT::Slot _object(object,FALSE);
        return QT::Slot::construct(_object);
    }
    ::hyve::lang::int16 __cpp_Splitter_construct(QT::splitter object) {
        QT::Splitter _object(object,FALSE);
        return QT::Splitter::construct(_object);
    }
    ::hyve::lang::_void __cpp_Splitter_destruct(QT::splitter object) {
        QT::Splitter _object(object,FALSE);
        QT::Splitter::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Splitter_init(QT::splitter object) {
        QT::Splitter _object(object,FALSE);
        return QT::Splitter::init(_object);
    }
    ::hyve::lang::_void __cpp_Splitter_onSelf(QT::splitter _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::Splitter proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::_void __cpp_TabWidget_addTab(QT::tabWidget _this, ::hyve::lang::string label, QT::widget widget) {
        QT::TabWidget proxy(_this,FALSE);
        QT::Widget _widget(widget,FALSE);
        proxy.addTab(label, _widget);
    }
    ::hyve::lang::int16 __cpp_TabWidget_construct(QT::tabWidget object) {
        QT::TabWidget _object(object,FALSE);
        return QT::TabWidget::construct(_object);
    }
    ::hyve::lang::_void __cpp_TabWidget_destruct(QT::tabWidget object) {
        QT::TabWidget _object(object,FALSE);
        QT::TabWidget::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Tile_construct(QT::tile object) {
        QT::Tile _object(object,FALSE);
        return QT::Tile::construct(_object);
    }
    ::hyve::lang::_void __cpp_Tile_destruct(QT::tile object) {
        QT::Tile _object(object,FALSE);
        QT::Tile::destruct(_object);
    }
    ::hyve::lang::int16 __cpp_Tile_init(QT::tile object) {
        QT::Tile _object(object,FALSE);
        return QT::Tile::init(_object);
    }
    ::hyve::lang::_void __cpp_Tile_onDefine(QT::tile _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::Tile proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDefine(_observable, _source);
    }
    ::hyve::lang::_void __cpp_Tile_onDestruct(QT::tile _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::Tile proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onDestruct(_observable, _source);
    }
    ::hyve::lang::_void __cpp_Tile_onSelf(QT::tile _this, ::hyve::lang::object observable, ::hyve::lang::object source) {
        QT::Tile proxy(_this,FALSE);
        ::hyve::lang::Object _observable(observable,FALSE);
        ::hyve::lang::Object _source(source,FALSE);
        proxy.onSelf(_observable, _source);
    }
    ::hyve::lang::_void __cpp_Tile_pulse(QT::tile _this, ::hyve::lang::uint8 r, ::hyve::lang::uint8 g, ::hyve::lang::uint8 b, ::hyve::lang::uint8 alpha) {
        QT::Tile proxy(_this,FALSE);
        proxy.pulse(r, g, b, alpha);
    }
    ::hyve::lang::int16 __cpp_Widget_construct(QT::widget object) {
        QT::Widget _object(object,FALSE);
        return QT::Widget::construct(_object);
    }
    ::hyve::lang::_void __cpp_Widget_destruct(QT::widget object) {
        QT::Widget _object(object,FALSE);
        QT::Widget::destruct(_object);
    }
    ::hyve::lang::_void __cpp_Widget_hide(QT::widget _this) {
        QT::Widget proxy(_this,FALSE);
        proxy.hide();
    }
    ::hyve::lang::int16 __cpp_Widget_init(QT::widget object) {
        QT::Widget _object(object,FALSE);
        return QT::Widget::init(_object);
    }
    ::hyve::lang::_void __cpp_Widget_repaint(QT::widget _this) {
        QT::Widget proxy(_this,FALSE);
        proxy.repaint();
    }
    ::hyve::lang::_void __cpp_Widget_show(QT::widget _this) {
        QT::Widget proxy(_this,FALSE);
        proxy.show();
    }
    
    /* Load objects in database */
    void unload(void* udata) {
        (void)udata;
        delete QT::AbstractButton_o;
        delete QT::Application_o;
        delete QT::Brush_o;
        delete QT::CheckBox_o;
        delete QT::ComboBox_o;
        delete QT::ConicalGradient_o;
        delete QT::CustomPlot_o;
        delete QT::EnumComboBox_o;
        delete QT::Font_o;
        delete QT::Gradient_o;
        delete QT::GridLayout_o;
        delete QT::GroupBox_o;
        delete QT::inputEvent_t_o;
        delete QT::Label_o;
        delete QT::LinearGradient_o;
        delete QT::LineEdit_o;
        delete QT::ListWidget_o;
        delete QT::MainWindow_o;
        delete QT::mouseEvent_t_o;
        delete QT::Object_o;
        delete QT::ObjectBrowse_o;
        delete QT::ObjectTile_o;
        delete QT::ObjectTree_o;
        delete QT::ObjectView_o;
        delete QT::PaintDevice_o;
        delete QT::Painter_o;
        delete QT::paintEvent_t_o;
        delete QT::Pen_o;
        delete QT::ProgressBar_o;
        delete QT::PushButton_o;
        delete QT::RadialGradient_o;
        delete QT::RadioButton_o;
        delete QT::Slider_o;
        delete QT::slot_o;
        delete QT::Splitter_o;
        delete QT::TabWidget_o;
        delete QT::Tile_o;
        delete QT::Widget_o;
    }
    
    /* Load objects in database */
    int load(void) {
        ::hyve::lang::object _a_; /* Used for resolving anonymous objects */
        _a_ = NULL;

        /* Declare ::Qt */
        if (!(QT_h = (::hyve::lang::object)::hyve::resolve(NULL, NULL, "::Qt", "load: check if object '::Qt' already exists."))) {
            QT_h = (::hyve::lang::object)::hyve::declare(::root_h, "Qt", ((::hyve::lang::_typedef)::hyve::lang::object_h));
            if (!QT_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt'.");
                goto error;
            }
        } else {
            ::hyve::free(QT_h);
        }

        /* Define ::Qt */
        if (!::hyve::checkState((::hyve::lang::object)QT_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt'.");
                goto error;
            }
        }
        /* Declare ::Qt::AbstractButton */
        if (!(QT::AbstractButton_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton", "load: check if object '::Qt::AbstractButton' already exists."))) {
            QT::AbstractButton_h = (::hyve::lang::_class)::hyve::declare(QT_h, "AbstractButton", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::AbstractButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_h);
        }

        /* Declare ::Qt::AbstractButton::checkable */
        if (!(QT::AbstractButton_checkable_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton::checkable", "load: check if object '::Qt::AbstractButton::checkable' already exists."))) {
            QT::AbstractButton_checkable_h = (::hyve::lang::member)::hyve::declare(QT::AbstractButton_h, "checkable", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::AbstractButton_checkable_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton::checkable'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_checkable_h);
        }

        /* Define ::Qt::AbstractButton::checkable */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_checkable_h, ::hyve::lang::DEFINED)) {
            QT::AbstractButton_checkable_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::AbstractButton_checkable_h->modifiers = 0x0;
            QT::AbstractButton_checkable_h->state = 0x6;
            QT::AbstractButton_checkable_h->weak = FALSE;
            QT::AbstractButton_checkable_h->id = 1;
            if (::hyve::define(QT::AbstractButton_checkable_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton::checkable'.");
                goto error;
            }
        }
        /* Declare ::Qt::AbstractButton::checked */
        if (!(QT::AbstractButton_checked_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton::checked", "load: check if object '::Qt::AbstractButton::checked' already exists."))) {
            QT::AbstractButton_checked_h = (::hyve::lang::member)::hyve::declare(QT::AbstractButton_h, "checked", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::AbstractButton_checked_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton::checked'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_checked_h);
        }

        /* Define ::Qt::AbstractButton::checked */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_checked_h, ::hyve::lang::DEFINED)) {
            QT::AbstractButton_checked_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::AbstractButton_checked_h->modifiers = 0x0;
            QT::AbstractButton_checked_h->state = 0x6;
            QT::AbstractButton_checked_h->weak = FALSE;
            QT::AbstractButton_checked_h->id = 3;
            if (::hyve::define(QT::AbstractButton_checked_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton::checked'.");
                goto error;
            }
        }
        /* Declare ::Qt::AbstractButton::down */
        if (!(QT::AbstractButton_down_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton::down", "load: check if object '::Qt::AbstractButton::down' already exists."))) {
            QT::AbstractButton_down_h = (::hyve::lang::member)::hyve::declare(QT::AbstractButton_h, "down", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::AbstractButton_down_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton::down'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_down_h);
        }

        /* Define ::Qt::AbstractButton::down */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_down_h, ::hyve::lang::DEFINED)) {
            QT::AbstractButton_down_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::AbstractButton_down_h->modifiers = 0x0;
            QT::AbstractButton_down_h->state = 0x6;
            QT::AbstractButton_down_h->weak = FALSE;
            QT::AbstractButton_down_h->id = 2;
            if (::hyve::define(QT::AbstractButton_down_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton::down'.");
                goto error;
            }
        }
        /* Declare ::Qt::AbstractButton::text */
        if (!(QT::AbstractButton_text_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton::text", "load: check if object '::Qt::AbstractButton::text' already exists."))) {
            QT::AbstractButton_text_h = (::hyve::lang::member)::hyve::declare(QT::AbstractButton_h, "text", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::AbstractButton_text_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton::text'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_text_h);
        }

        /* Define ::Qt::AbstractButton::text */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_text_h, ::hyve::lang::DEFINED)) {
            QT::AbstractButton_text_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::AbstractButton_text_h->modifiers = 0x0;
            QT::AbstractButton_text_h->state = 0x6;
            QT::AbstractButton_text_h->weak = FALSE;
            QT::AbstractButton_text_h->id = 0;
            if (::hyve::define(QT::AbstractButton_text_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton::text'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment */
        if (!(QT::Alignment_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::Alignment", "load: check if object '::Qt::Alignment' already exists."))) {
            QT::Alignment_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "Alignment", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::Alignment_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_h);
        }

        /* Declare ::Qt::Alignment::AlignBottom */
        if (!(QT::Alignment_AlignBottom_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignBottom", "load: check if object '::Qt::Alignment::AlignBottom' already exists."))) {
            QT::Alignment_AlignBottom_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignBottom", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignBottom_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignBottom'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignBottom_h);
        }

        /* Define ::Qt::Alignment::AlignBottom */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignBottom_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignBottom_h) = 64;
            if (::hyve::define(QT::Alignment_AlignBottom_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignBottom'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignCenter */
        if (!(QT::Alignment_AlignCenter_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignCenter", "load: check if object '::Qt::Alignment::AlignCenter' already exists."))) {
            QT::Alignment_AlignCenter_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignCenter", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignCenter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignCenter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignCenter_h);
        }

        /* Define ::Qt::Alignment::AlignCenter */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignCenter_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignCenter_h) = 132;
            if (::hyve::define(QT::Alignment_AlignCenter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignCenter'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignHCenter */
        if (!(QT::Alignment_AlignHCenter_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignHCenter", "load: check if object '::Qt::Alignment::AlignHCenter' already exists."))) {
            QT::Alignment_AlignHCenter_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignHCenter", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignHCenter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignHCenter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignHCenter_h);
        }

        /* Define ::Qt::Alignment::AlignHCenter */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignHCenter_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignHCenter_h) = 4;
            if (::hyve::define(QT::Alignment_AlignHCenter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignHCenter'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignJustify */
        if (!(QT::Alignment_AlignJustify_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignJustify", "load: check if object '::Qt::Alignment::AlignJustify' already exists."))) {
            QT::Alignment_AlignJustify_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignJustify", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignJustify_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignJustify'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignJustify_h);
        }

        /* Define ::Qt::Alignment::AlignJustify */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignJustify_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignJustify_h) = 8;
            if (::hyve::define(QT::Alignment_AlignJustify_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignJustify'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignLeft */
        if (!(QT::Alignment_AlignLeft_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignLeft", "load: check if object '::Qt::Alignment::AlignLeft' already exists."))) {
            QT::Alignment_AlignLeft_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignLeft", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignLeft_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignLeft'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignLeft_h);
        }

        /* Define ::Qt::Alignment::AlignLeft */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignLeft_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignLeft_h) = 1;
            if (::hyve::define(QT::Alignment_AlignLeft_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignLeft'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignRight */
        if (!(QT::Alignment_AlignRight_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignRight", "load: check if object '::Qt::Alignment::AlignRight' already exists."))) {
            QT::Alignment_AlignRight_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignRight", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignRight_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignRight'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignRight_h);
        }

        /* Define ::Qt::Alignment::AlignRight */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignRight_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignRight_h) = 2;
            if (::hyve::define(QT::Alignment_AlignRight_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignRight'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignTop */
        if (!(QT::Alignment_AlignTop_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignTop", "load: check if object '::Qt::Alignment::AlignTop' already exists."))) {
            QT::Alignment_AlignTop_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignTop", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignTop_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignTop'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignTop_h);
        }

        /* Define ::Qt::Alignment::AlignTop */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignTop_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignTop_h) = 32;
            if (::hyve::define(QT::Alignment_AlignTop_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignTop'.");
                goto error;
            }
        }
        /* Declare ::Qt::Alignment::AlignVCenter */
        if (!(QT::Alignment_AlignVCenter_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Alignment::AlignVCenter", "load: check if object '::Qt::Alignment::AlignVCenter' already exists."))) {
            QT::Alignment_AlignVCenter_h = (::hyve::lang::constant*)::hyve::declare(QT::Alignment_h, "AlignVCenter", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Alignment_AlignVCenter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Alignment::AlignVCenter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Alignment_AlignVCenter_h);
        }

        /* Define ::Qt::Alignment::AlignVCenter */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_AlignVCenter_h, ::hyve::lang::DEFINED)) {
            (*QT::Alignment_AlignVCenter_h) = 128;
            if (::hyve::define(QT::Alignment_AlignVCenter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment::AlignVCenter'.");
                goto error;
            }
        }
        /* Define ::Qt::Alignment */
        if (!::hyve::checkState((::hyve::lang::object)QT::Alignment_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::Alignment_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Alignment'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application */
        if (!(QT::Application_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Application", "load: check if object '::Qt::Application' already exists."))) {
            QT::Application_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Application", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Application_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_h);
        }

        /* Declare ::Qt::Application::arg */
        if (!(QT::Application_arg_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Application::arg", "load: check if object '::Qt::Application::arg' already exists."))) {
            QT::Application_arg_h = (::hyve::lang::member)::hyve::declare(QT::Application_h, "arg", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Application_arg_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::arg'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_arg_h);
        }

        /* Declare ::Qt::Application::stylesheet */
        if (!(QT::Application_stylesheet_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Application::stylesheet", "load: check if object '::Qt::Application::stylesheet' already exists."))) {
            QT::Application_stylesheet_h = (::hyve::lang::member)::hyve::declare(QT::Application_h, "stylesheet", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Application_stylesheet_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::stylesheet'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_stylesheet_h);
        }

        /* Define ::Qt::Application::stylesheet */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_stylesheet_h, ::hyve::lang::DEFINED)) {
            QT::Application_stylesheet_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::Application_stylesheet_h->modifiers = 0x0;
            QT::Application_stylesheet_h->state = 0x6;
            QT::Application_stylesheet_h->weak = FALSE;
            QT::Application_stylesheet_h->id = 1;
            if (::hyve::define(QT::Application_stylesheet_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::stylesheet'.");
                goto error;
            }
        }
        /* Declare ::Qt::Brush */
        if (!(QT::Brush_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Brush", "load: check if object '::Qt::Brush' already exists."))) {
            QT::Brush_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Brush", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Brush_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Brush'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Brush_h);
        }

        /* Declare ::Qt::Brush::color */
        if (!(QT::Brush_color_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Brush::color", "load: check if object '::Qt::Brush::color' already exists."))) {
            QT::Brush_color_h = (::hyve::lang::member)::hyve::declare(QT::Brush_h, "color", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Brush_color_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Brush::color'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Brush_color_h);
        }

        /* Declare ::Qt::Brush::gradient */
        if (!(QT::Brush_gradient_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Brush::gradient", "load: check if object '::Qt::Brush::gradient' already exists."))) {
            QT::Brush_gradient_h = (::hyve::lang::member)::hyve::declare(QT::Brush_h, "gradient", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Brush_gradient_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Brush::gradient'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Brush_gradient_h);
        }

        /* Declare ::Qt::CheckBox */
        if (!(QT::CheckBox_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::CheckBox", "load: check if object '::Qt::CheckBox' already exists."))) {
            QT::CheckBox_h = (::hyve::lang::_class)::hyve::declare(QT_h, "CheckBox", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::CheckBox_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CheckBox'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CheckBox_h);
        }

        /* Declare ::Qt::Color */
        if (!(QT::Color_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::Color", "load: check if object '::Qt::Color' already exists."))) {
            QT::Color_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "Color", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::Color_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Color'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Color_h);
        }

        /* Declare ::Qt::Color::alpha */
        if (!(QT::Color_alpha_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Color::alpha", "load: check if object '::Qt::Color::alpha' already exists."))) {
            QT::Color_alpha_h = (::hyve::lang::member)::hyve::declare(QT::Color_h, "alpha", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Color_alpha_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Color::alpha'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Color_alpha_h);
        }

        /* Define ::Qt::Color::alpha */
        if (!::hyve::checkState((::hyve::lang::object)QT::Color_alpha_h, ::hyve::lang::DEFINED)) {
            QT::Color_alpha_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint8"));
            QT::Color_alpha_h->modifiers = 0x0;
            QT::Color_alpha_h->state = 0x6;
            QT::Color_alpha_h->weak = FALSE;
            QT::Color_alpha_h->id = 3;
            if (::hyve::define(QT::Color_alpha_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Color::alpha'.");
                goto error;
            }
        }
        /* Declare ::Qt::Color::b */
        if (!(QT::Color_b_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Color::b", "load: check if object '::Qt::Color::b' already exists."))) {
            QT::Color_b_h = (::hyve::lang::member)::hyve::declare(QT::Color_h, "b", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Color_b_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Color::b'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Color_b_h);
        }

        /* Define ::Qt::Color::b */
        if (!::hyve::checkState((::hyve::lang::object)QT::Color_b_h, ::hyve::lang::DEFINED)) {
            QT::Color_b_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint8"));
            QT::Color_b_h->modifiers = 0x0;
            QT::Color_b_h->state = 0x6;
            QT::Color_b_h->weak = FALSE;
            QT::Color_b_h->id = 2;
            if (::hyve::define(QT::Color_b_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Color::b'.");
                goto error;
            }
        }
        /* Declare ::Qt::Color::g */
        if (!(QT::Color_g_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Color::g", "load: check if object '::Qt::Color::g' already exists."))) {
            QT::Color_g_h = (::hyve::lang::member)::hyve::declare(QT::Color_h, "g", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Color_g_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Color::g'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Color_g_h);
        }

        /* Define ::Qt::Color::g */
        if (!::hyve::checkState((::hyve::lang::object)QT::Color_g_h, ::hyve::lang::DEFINED)) {
            QT::Color_g_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint8"));
            QT::Color_g_h->modifiers = 0x0;
            QT::Color_g_h->state = 0x6;
            QT::Color_g_h->weak = FALSE;
            QT::Color_g_h->id = 1;
            if (::hyve::define(QT::Color_g_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Color::g'.");
                goto error;
            }
        }
        /* Declare ::Qt::Color::r */
        if (!(QT::Color_r_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Color::r", "load: check if object '::Qt::Color::r' already exists."))) {
            QT::Color_r_h = (::hyve::lang::member)::hyve::declare(QT::Color_h, "r", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Color_r_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Color::r'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Color_r_h);
        }

        /* Define ::Qt::Color::r */
        if (!::hyve::checkState((::hyve::lang::object)QT::Color_r_h, ::hyve::lang::DEFINED)) {
            QT::Color_r_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint8"));
            QT::Color_r_h->modifiers = 0x0;
            QT::Color_r_h->state = 0x6;
            QT::Color_r_h->weak = FALSE;
            QT::Color_r_h->id = 0;
            if (::hyve::define(QT::Color_r_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Color::r'.");
                goto error;
            }
        }
        /* Define ::Qt::Color */
        if (!::hyve::checkState((::hyve::lang::object)QT::Color_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Color_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Color_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Color_h)->base = NULL;
            QT::Color_h->baseAccess = 0x0;
            if (::hyve::define(QT::Color_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Color'.");
                goto error;
            }
        }
        /* Define ::Qt::Brush::color */
        if (!::hyve::checkState((::hyve::lang::object)QT::Brush_color_h, ::hyve::lang::DEFINED)) {
            QT::Brush_color_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Color"));
            QT::Brush_color_h->modifiers = 0x0;
            QT::Brush_color_h->state = 0x6;
            QT::Brush_color_h->weak = FALSE;
            QT::Brush_color_h->id = 0;
            if (::hyve::define(QT::Brush_color_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Brush::color'.");
                goto error;
            }
        }
        /* Declare ::Qt::ComboBox */
        if (!(QT::ComboBox_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ComboBox", "load: check if object '::Qt::ComboBox' already exists."))) {
            QT::ComboBox_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ComboBox", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ComboBox_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_h);
        }

        /* Declare ::Qt::ComboBox::currentIndex */
        if (!(QT::ComboBox_currentIndex_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ComboBox::currentIndex", "load: check if object '::Qt::ComboBox::currentIndex' already exists."))) {
            QT::ComboBox_currentIndex_h = (::hyve::lang::member)::hyve::declare(QT::ComboBox_h, "currentIndex", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ComboBox_currentIndex_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox::currentIndex'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_currentIndex_h);
        }

        /* Define ::Qt::ComboBox::currentIndex */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_currentIndex_h, ::hyve::lang::DEFINED)) {
            QT::ComboBox_currentIndex_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::ComboBox_currentIndex_h->modifiers = 0x0;
            QT::ComboBox_currentIndex_h->state = 0x6;
            QT::ComboBox_currentIndex_h->weak = FALSE;
            QT::ComboBox_currentIndex_h->id = 1;
            if (::hyve::define(QT::ComboBox_currentIndex_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox::currentIndex'.");
                goto error;
            }
        }
        /* Declare ::Qt::ComboBox::currentText */
        if (!(QT::ComboBox_currentText_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ComboBox::currentText", "load: check if object '::Qt::ComboBox::currentText' already exists."))) {
            QT::ComboBox_currentText_h = (::hyve::lang::member)::hyve::declare(QT::ComboBox_h, "currentText", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ComboBox_currentText_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox::currentText'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_currentText_h);
        }

        /* Define ::Qt::ComboBox::currentText */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_currentText_h, ::hyve::lang::DEFINED)) {
            QT::ComboBox_currentText_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ComboBox_currentText_h->modifiers = 0x5;
            QT::ComboBox_currentText_h->state = 0x6;
            QT::ComboBox_currentText_h->weak = FALSE;
            QT::ComboBox_currentText_h->id = 2;
            if (::hyve::define(QT::ComboBox_currentText_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox::currentText'.");
                goto error;
            }
        }
        /* Declare ::Qt::ComboBox::items */
        if (!(QT::ComboBox_items_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ComboBox::items", "load: check if object '::Qt::ComboBox::items' already exists."))) {
            QT::ComboBox_items_h = (::hyve::lang::member)::hyve::declare(QT::ComboBox_h, "items", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ComboBox_items_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox::items'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_items_h);
        }

        /* Declare ::Qt::ConicalGradient */
        if (!(QT::ConicalGradient_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ConicalGradient", "load: check if object '::Qt::ConicalGradient' already exists."))) {
            QT::ConicalGradient_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ConicalGradient", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ConicalGradient_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ConicalGradient'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ConicalGradient_h);
        }

        /* Declare ::Qt::ConicalGradient::angle */
        if (!(QT::ConicalGradient_angle_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ConicalGradient::angle", "load: check if object '::Qt::ConicalGradient::angle' already exists."))) {
            QT::ConicalGradient_angle_h = (::hyve::lang::member)::hyve::declare(QT::ConicalGradient_h, "angle", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ConicalGradient_angle_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ConicalGradient::angle'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ConicalGradient_angle_h);
        }

        /* Declare ::Qt::ConicalGradient::center */
        if (!(QT::ConicalGradient_center_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ConicalGradient::center", "load: check if object '::Qt::ConicalGradient::center' already exists."))) {
            QT::ConicalGradient_center_h = (::hyve::lang::member)::hyve::declare(QT::ConicalGradient_h, "center", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ConicalGradient_center_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ConicalGradient::center'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ConicalGradient_center_h);
        }

        /* Declare ::Qt::CustomPlot */
        if (!(QT::CustomPlot_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot", "load: check if object '::Qt::CustomPlot' already exists."))) {
            QT::CustomPlot_h = (::hyve::lang::_class)::hyve::declare(QT_h, "CustomPlot", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::CustomPlot_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_h);
        }

        /* Declare ::Qt::CustomPlot::autoX */
        if (!(QT::CustomPlot_autoX_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::autoX", "load: check if object '::Qt::CustomPlot::autoX' already exists."))) {
            QT::CustomPlot_autoX_h = (::hyve::lang::member)::hyve::declare(QT::CustomPlot_h, "autoX", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::CustomPlot_autoX_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::autoX'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_autoX_h);
        }

        /* Define ::Qt::CustomPlot::autoX */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_autoX_h, ::hyve::lang::DEFINED)) {
            QT::CustomPlot_autoX_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::CustomPlot_autoX_h->modifiers = 0x0;
            QT::CustomPlot_autoX_h->state = 0x6;
            QT::CustomPlot_autoX_h->weak = FALSE;
            QT::CustomPlot_autoX_h->id = 2;
            if (::hyve::define(QT::CustomPlot_autoX_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::autoX'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::expr */
        if (!(QT::CustomPlot_expr_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::expr", "load: check if object '::Qt::CustomPlot::expr' already exists."))) {
            QT::CustomPlot_expr_h = (::hyve::lang::member)::hyve::declare(QT::CustomPlot_h, "expr", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::CustomPlot_expr_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::expr'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_expr_h);
        }

        /* Define ::Qt::CustomPlot::expr */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_expr_h, ::hyve::lang::DEFINED)) {
            QT::CustomPlot_expr_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::CustomPlot_expr_h->modifiers = 0x0;
            QT::CustomPlot_expr_h->state = 0x6;
            QT::CustomPlot_expr_h->weak = FALSE;
            QT::CustomPlot_expr_h->id = 1;
            if (::hyve::define(QT::CustomPlot_expr_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::expr'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::object */
        if (!(QT::CustomPlot_object_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::object", "load: check if object '::Qt::CustomPlot::object' already exists."))) {
            QT::CustomPlot_object_h = (::hyve::lang::member)::hyve::declare(QT::CustomPlot_h, "object", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::CustomPlot_object_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::object'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_object_h);
        }

        /* Define ::Qt::CustomPlot::object */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_object_h, ::hyve::lang::DEFINED)) {
            QT::CustomPlot_object_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
            QT::CustomPlot_object_h->modifiers = 0x0;
            QT::CustomPlot_object_h->state = 0x6;
            QT::CustomPlot_object_h->weak = FALSE;
            QT::CustomPlot_object_h->id = 0;
            if (::hyve::define(QT::CustomPlot_object_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::object'.");
                goto error;
            }
        }
        /* Declare ::Qt::EnumComboBox */
        if (!(QT::EnumComboBox_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::EnumComboBox", "load: check if object '::Qt::EnumComboBox' already exists."))) {
            QT::EnumComboBox_h = (::hyve::lang::_class)::hyve::declare(QT_h, "EnumComboBox", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::EnumComboBox_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::EnumComboBox'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::EnumComboBox_h);
        }

        /* Declare ::Qt::EnumComboBox::type */
        if (!(QT::EnumComboBox_type_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::EnumComboBox::type", "load: check if object '::Qt::EnumComboBox::type' already exists."))) {
            QT::EnumComboBox_type_h = (::hyve::lang::member)::hyve::declare(QT::EnumComboBox_h, "type", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::EnumComboBox_type_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::EnumComboBox::type'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::EnumComboBox_type_h);
        }

        /* Define ::Qt::EnumComboBox::type */
        if (!::hyve::checkState((::hyve::lang::object)QT::EnumComboBox_type_h, ::hyve::lang::DEFINED)) {
            QT::EnumComboBox_type_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::enum"));
            QT::EnumComboBox_type_h->modifiers = 0x0;
            QT::EnumComboBox_type_h->state = 0x6;
            QT::EnumComboBox_type_h->weak = FALSE;
            QT::EnumComboBox_type_h->id = 0;
            if (::hyve::define(QT::EnumComboBox_type_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::EnumComboBox::type'.");
                goto error;
            }
        }
        /* Declare ::Qt::EnumComboBox::value */
        if (!(QT::EnumComboBox_value_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::EnumComboBox::value", "load: check if object '::Qt::EnumComboBox::value' already exists."))) {
            QT::EnumComboBox_value_h = (::hyve::lang::member)::hyve::declare(QT::EnumComboBox_h, "value", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::EnumComboBox_value_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::EnumComboBox::value'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::EnumComboBox_value_h);
        }

        /* Define ::Qt::EnumComboBox::value */
        if (!::hyve::checkState((::hyve::lang::object)QT::EnumComboBox_value_h, ::hyve::lang::DEFINED)) {
            QT::EnumComboBox_value_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::constant"));
            QT::EnumComboBox_value_h->modifiers = 0x0;
            QT::EnumComboBox_value_h->state = 0x6;
            QT::EnumComboBox_value_h->weak = FALSE;
            QT::EnumComboBox_value_h->id = 1;
            if (::hyve::define(QT::EnumComboBox_value_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::EnumComboBox::value'.");
                goto error;
            }
        }
        /* Declare ::Qt::Font */
        if (!(QT::Font_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Font", "load: check if object '::Qt::Font' already exists."))) {
            QT::Font_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Font", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Font_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_h);
        }

        /* Declare ::Qt::Font::family */
        if (!(QT::Font_family_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Font::family", "load: check if object '::Qt::Font::family' already exists."))) {
            QT::Font_family_h = (::hyve::lang::member)::hyve::declare(QT::Font_h, "family", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Font_family_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font::family'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_family_h);
        }

        /* Define ::Qt::Font::family */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_family_h, ::hyve::lang::DEFINED)) {
            QT::Font_family_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::Font_family_h->modifiers = 0x0;
            QT::Font_family_h->state = 0x6;
            QT::Font_family_h->weak = FALSE;
            QT::Font_family_h->id = 0;
            if (::hyve::define(QT::Font_family_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font::family'.");
                goto error;
            }
        }
        /* Declare ::Qt::Font::italic */
        if (!(QT::Font_italic_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Font::italic", "load: check if object '::Qt::Font::italic' already exists."))) {
            QT::Font_italic_h = (::hyve::lang::member)::hyve::declare(QT::Font_h, "italic", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Font_italic_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font::italic'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_italic_h);
        }

        /* Define ::Qt::Font::italic */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_italic_h, ::hyve::lang::DEFINED)) {
            QT::Font_italic_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::Font_italic_h->modifiers = 0x0;
            QT::Font_italic_h->state = 0x6;
            QT::Font_italic_h->weak = FALSE;
            QT::Font_italic_h->id = 3;
            if (::hyve::define(QT::Font_italic_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font::italic'.");
                goto error;
            }
        }
        /* Declare ::Qt::Font::pointSize */
        if (!(QT::Font_pointSize_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Font::pointSize", "load: check if object '::Qt::Font::pointSize' already exists."))) {
            QT::Font_pointSize_h = (::hyve::lang::member)::hyve::declare(QT::Font_h, "pointSize", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Font_pointSize_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font::pointSize'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_pointSize_h);
        }

        /* Define ::Qt::Font::pointSize */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_pointSize_h, ::hyve::lang::DEFINED)) {
            QT::Font_pointSize_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Font_pointSize_h->modifiers = 0x0;
            QT::Font_pointSize_h->state = 0x6;
            QT::Font_pointSize_h->weak = FALSE;
            QT::Font_pointSize_h->id = 1;
            if (::hyve::define(QT::Font_pointSize_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font::pointSize'.");
                goto error;
            }
        }
        /* Declare ::Qt::Font::weight */
        if (!(QT::Font_weight_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Font::weight", "load: check if object '::Qt::Font::weight' already exists."))) {
            QT::Font_weight_h = (::hyve::lang::member)::hyve::declare(QT::Font_h, "weight", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Font_weight_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font::weight'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_weight_h);
        }

        /* Declare ::Qt::FontWeight */
        if (!(QT::FontWeight_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::FontWeight", "load: check if object '::Qt::FontWeight' already exists."))) {
            QT::FontWeight_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "FontWeight", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::FontWeight_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::FontWeight'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::FontWeight_h);
        }

        /* Declare ::Qt::FontWeight::Black */
        if (!(QT::FontWeight_Black_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::FontWeight::Black", "load: check if object '::Qt::FontWeight::Black' already exists."))) {
            QT::FontWeight_Black_h = (::hyve::lang::constant*)::hyve::declare(QT::FontWeight_h, "Black", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::FontWeight_Black_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::FontWeight::Black'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::FontWeight_Black_h);
        }

        /* Define ::Qt::FontWeight::Black */
        if (!::hyve::checkState((::hyve::lang::object)QT::FontWeight_Black_h, ::hyve::lang::DEFINED)) {
            (*QT::FontWeight_Black_h) = 87;
            if (::hyve::define(QT::FontWeight_Black_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::FontWeight::Black'.");
                goto error;
            }
        }
        /* Declare ::Qt::FontWeight::Bold */
        if (!(QT::FontWeight_Bold_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::FontWeight::Bold", "load: check if object '::Qt::FontWeight::Bold' already exists."))) {
            QT::FontWeight_Bold_h = (::hyve::lang::constant*)::hyve::declare(QT::FontWeight_h, "Bold", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::FontWeight_Bold_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::FontWeight::Bold'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::FontWeight_Bold_h);
        }

        /* Define ::Qt::FontWeight::Bold */
        if (!::hyve::checkState((::hyve::lang::object)QT::FontWeight_Bold_h, ::hyve::lang::DEFINED)) {
            (*QT::FontWeight_Bold_h) = 75;
            if (::hyve::define(QT::FontWeight_Bold_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::FontWeight::Bold'.");
                goto error;
            }
        }
        /* Declare ::Qt::FontWeight::DemiBold */
        if (!(QT::FontWeight_DemiBold_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::FontWeight::DemiBold", "load: check if object '::Qt::FontWeight::DemiBold' already exists."))) {
            QT::FontWeight_DemiBold_h = (::hyve::lang::constant*)::hyve::declare(QT::FontWeight_h, "DemiBold", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::FontWeight_DemiBold_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::FontWeight::DemiBold'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::FontWeight_DemiBold_h);
        }

        /* Define ::Qt::FontWeight::DemiBold */
        if (!::hyve::checkState((::hyve::lang::object)QT::FontWeight_DemiBold_h, ::hyve::lang::DEFINED)) {
            (*QT::FontWeight_DemiBold_h) = 63;
            if (::hyve::define(QT::FontWeight_DemiBold_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::FontWeight::DemiBold'.");
                goto error;
            }
        }
        /* Declare ::Qt::FontWeight::Light */
        if (!(QT::FontWeight_Light_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::FontWeight::Light", "load: check if object '::Qt::FontWeight::Light' already exists."))) {
            QT::FontWeight_Light_h = (::hyve::lang::constant*)::hyve::declare(QT::FontWeight_h, "Light", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::FontWeight_Light_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::FontWeight::Light'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::FontWeight_Light_h);
        }

        /* Define ::Qt::FontWeight::Light */
        if (!::hyve::checkState((::hyve::lang::object)QT::FontWeight_Light_h, ::hyve::lang::DEFINED)) {
            (*QT::FontWeight_Light_h) = 25;
            if (::hyve::define(QT::FontWeight_Light_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::FontWeight::Light'.");
                goto error;
            }
        }
        /* Declare ::Qt::FontWeight::Normal */
        if (!(QT::FontWeight_Normal_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::FontWeight::Normal", "load: check if object '::Qt::FontWeight::Normal' already exists."))) {
            QT::FontWeight_Normal_h = (::hyve::lang::constant*)::hyve::declare(QT::FontWeight_h, "Normal", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::FontWeight_Normal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::FontWeight::Normal'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::FontWeight_Normal_h);
        }

        /* Define ::Qt::FontWeight::Normal */
        if (!::hyve::checkState((::hyve::lang::object)QT::FontWeight_Normal_h, ::hyve::lang::DEFINED)) {
            (*QT::FontWeight_Normal_h) = 50;
            if (::hyve::define(QT::FontWeight_Normal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::FontWeight::Normal'.");
                goto error;
            }
        }
        /* Define ::Qt::FontWeight */
        if (!::hyve::checkState((::hyve::lang::object)QT::FontWeight_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::FontWeight_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::FontWeight'.");
                goto error;
            }
        }
        /* Define ::Qt::Font::weight */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_weight_h, ::hyve::lang::DEFINED)) {
            QT::Font_weight_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::FontWeight"));
            QT::Font_weight_h->modifiers = 0x0;
            QT::Font_weight_h->state = 0x6;
            QT::Font_weight_h->weak = FALSE;
            QT::Font_weight_h->id = 2;
            if (::hyve::define(QT::Font_weight_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font::weight'.");
                goto error;
            }
        }
        /* Declare ::Qt::Gradient */
        if (!(QT::Gradient_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Gradient", "load: check if object '::Qt::Gradient' already exists."))) {
            QT::Gradient_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Gradient", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Gradient_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Gradient'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Gradient_h);
        }

        /* Declare ::Qt::Gradient::coordinateMode */
        if (!(QT::Gradient_coordinateMode_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Gradient::coordinateMode", "load: check if object '::Qt::Gradient::coordinateMode' already exists."))) {
            QT::Gradient_coordinateMode_h = (::hyve::lang::member)::hyve::declare(QT::Gradient_h, "coordinateMode", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Gradient_coordinateMode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Gradient::coordinateMode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Gradient_coordinateMode_h);
        }

        /* Declare ::Qt::Gradient::kind */
        if (!(QT::Gradient_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Gradient::kind", "load: check if object '::Qt::Gradient::kind' already exists."))) {
            QT::Gradient_kind_h = (::hyve::lang::member)::hyve::declare(QT::Gradient_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Gradient_kind_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Gradient::kind'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Gradient_kind_h);
        }

        /* Declare ::Qt::Gradient::spread */
        if (!(QT::Gradient_spread_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Gradient::spread", "load: check if object '::Qt::Gradient::spread' already exists."))) {
            QT::Gradient_spread_h = (::hyve::lang::member)::hyve::declare(QT::Gradient_h, "spread", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Gradient_spread_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Gradient::spread'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Gradient_spread_h);
        }

        /* Declare ::Qt::Gradient::stops */
        if (!(QT::Gradient_stops_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Gradient::stops", "load: check if object '::Qt::Gradient::stops' already exists."))) {
            QT::Gradient_stops_h = (::hyve::lang::member)::hyve::declare(QT::Gradient_h, "stops", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Gradient_stops_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Gradient::stops'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Gradient_stops_h);
        }

        /* Declare ::Qt::GradientCoordinateMode */
        if (!(QT::GradientCoordinateMode_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::GradientCoordinateMode", "load: check if object '::Qt::GradientCoordinateMode' already exists."))) {
            QT::GradientCoordinateMode_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "GradientCoordinateMode", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::GradientCoordinateMode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientCoordinateMode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientCoordinateMode_h);
        }

        /* Declare ::Qt::GradientCoordinateMode::LogicalMode */
        if (!(QT::GradientCoordinateMode_LogicalMode_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientCoordinateMode::LogicalMode", "load: check if object '::Qt::GradientCoordinateMode::LogicalMode' already exists."))) {
            QT::GradientCoordinateMode_LogicalMode_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientCoordinateMode_h, "LogicalMode", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientCoordinateMode_LogicalMode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientCoordinateMode::LogicalMode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientCoordinateMode_LogicalMode_h);
        }

        /* Define ::Qt::GradientCoordinateMode::LogicalMode */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientCoordinateMode_LogicalMode_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientCoordinateMode_LogicalMode_h) = 0;
            if (::hyve::define(QT::GradientCoordinateMode_LogicalMode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientCoordinateMode::LogicalMode'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientCoordinateMode::ObjectBoundingMode */
        if (!(QT::GradientCoordinateMode_ObjectBoundingMode_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientCoordinateMode::ObjectBoundingMode", "load: check if object '::Qt::GradientCoordinateMode::ObjectBoundingMode' already exists."))) {
            QT::GradientCoordinateMode_ObjectBoundingMode_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientCoordinateMode_h, "ObjectBoundingMode", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientCoordinateMode_ObjectBoundingMode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientCoordinateMode::ObjectBoundingMode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientCoordinateMode_ObjectBoundingMode_h);
        }

        /* Define ::Qt::GradientCoordinateMode::ObjectBoundingMode */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientCoordinateMode_ObjectBoundingMode_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientCoordinateMode_ObjectBoundingMode_h) = 2;
            if (::hyve::define(QT::GradientCoordinateMode_ObjectBoundingMode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientCoordinateMode::ObjectBoundingMode'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientCoordinateMode::StretchToDeviceMode */
        if (!(QT::GradientCoordinateMode_StretchToDeviceMode_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientCoordinateMode::StretchToDeviceMode", "load: check if object '::Qt::GradientCoordinateMode::StretchToDeviceMode' already exists."))) {
            QT::GradientCoordinateMode_StretchToDeviceMode_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientCoordinateMode_h, "StretchToDeviceMode", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientCoordinateMode_StretchToDeviceMode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientCoordinateMode::StretchToDeviceMode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientCoordinateMode_StretchToDeviceMode_h);
        }

        /* Define ::Qt::GradientCoordinateMode::StretchToDeviceMode */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientCoordinateMode_StretchToDeviceMode_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientCoordinateMode_StretchToDeviceMode_h) = 1;
            if (::hyve::define(QT::GradientCoordinateMode_StretchToDeviceMode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientCoordinateMode::StretchToDeviceMode'.");
                goto error;
            }
        }
        /* Define ::Qt::GradientCoordinateMode */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientCoordinateMode_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::GradientCoordinateMode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientCoordinateMode'.");
                goto error;
            }
        }
        /* Define ::Qt::Gradient::coordinateMode */
        if (!::hyve::checkState((::hyve::lang::object)QT::Gradient_coordinateMode_h, ::hyve::lang::DEFINED)) {
            QT::Gradient_coordinateMode_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::GradientCoordinateMode"));
            QT::Gradient_coordinateMode_h->modifiers = 0x0;
            QT::Gradient_coordinateMode_h->state = 0x6;
            QT::Gradient_coordinateMode_h->weak = FALSE;
            QT::Gradient_coordinateMode_h->id = 2;
            if (::hyve::define(QT::Gradient_coordinateMode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Gradient::coordinateMode'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientKind */
        if (!(QT::GradientKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::GradientKind", "load: check if object '::Qt::GradientKind' already exists."))) {
            QT::GradientKind_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "GradientKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::GradientKind_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientKind'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientKind_h);
        }

        /* Declare ::Qt::GradientKind::Conical */
        if (!(QT::GradientKind_Conical_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientKind::Conical", "load: check if object '::Qt::GradientKind::Conical' already exists."))) {
            QT::GradientKind_Conical_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientKind_h, "Conical", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientKind_Conical_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientKind::Conical'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientKind_Conical_h);
        }

        /* Define ::Qt::GradientKind::Conical */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientKind_Conical_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientKind_Conical_h) = 2;
            if (::hyve::define(QT::GradientKind_Conical_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientKind::Conical'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientKind::Linear */
        if (!(QT::GradientKind_Linear_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientKind::Linear", "load: check if object '::Qt::GradientKind::Linear' already exists."))) {
            QT::GradientKind_Linear_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientKind_h, "Linear", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientKind_Linear_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientKind::Linear'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientKind_Linear_h);
        }

        /* Define ::Qt::GradientKind::Linear */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientKind_Linear_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientKind_Linear_h) = 0;
            if (::hyve::define(QT::GradientKind_Linear_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientKind::Linear'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientKind::Radial */
        if (!(QT::GradientKind_Radial_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientKind::Radial", "load: check if object '::Qt::GradientKind::Radial' already exists."))) {
            QT::GradientKind_Radial_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientKind_h, "Radial", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientKind_Radial_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientKind::Radial'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientKind_Radial_h);
        }

        /* Define ::Qt::GradientKind::Radial */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientKind_Radial_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientKind_Radial_h) = 1;
            if (::hyve::define(QT::GradientKind_Radial_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientKind::Radial'.");
                goto error;
            }
        }
        /* Define ::Qt::GradientKind */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientKind_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::GradientKind_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientKind'.");
                goto error;
            }
        }
        /* Define ::Qt::Gradient::kind */
        if (!::hyve::checkState((::hyve::lang::object)QT::Gradient_kind_h, ::hyve::lang::DEFINED)) {
            QT::Gradient_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::GradientKind"));
            QT::Gradient_kind_h->modifiers = 0x5;
            QT::Gradient_kind_h->state = 0x6;
            QT::Gradient_kind_h->weak = FALSE;
            QT::Gradient_kind_h->id = 0;
            if (::hyve::define(QT::Gradient_kind_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Gradient::kind'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientSpread */
        if (!(QT::GradientSpread_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::GradientSpread", "load: check if object '::Qt::GradientSpread' already exists."))) {
            QT::GradientSpread_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "GradientSpread", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::GradientSpread_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientSpread'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientSpread_h);
        }

        /* Declare ::Qt::GradientSpread::PadSpead */
        if (!(QT::GradientSpread_PadSpead_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientSpread::PadSpead", "load: check if object '::Qt::GradientSpread::PadSpead' already exists."))) {
            QT::GradientSpread_PadSpead_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientSpread_h, "PadSpead", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientSpread_PadSpead_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientSpread::PadSpead'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientSpread_PadSpead_h);
        }

        /* Define ::Qt::GradientSpread::PadSpead */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientSpread_PadSpead_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientSpread_PadSpead_h) = 0;
            if (::hyve::define(QT::GradientSpread_PadSpead_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientSpread::PadSpead'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientSpread::ReflectSpread */
        if (!(QT::GradientSpread_ReflectSpread_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientSpread::ReflectSpread", "load: check if object '::Qt::GradientSpread::ReflectSpread' already exists."))) {
            QT::GradientSpread_ReflectSpread_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientSpread_h, "ReflectSpread", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientSpread_ReflectSpread_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientSpread::ReflectSpread'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientSpread_ReflectSpread_h);
        }

        /* Define ::Qt::GradientSpread::ReflectSpread */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientSpread_ReflectSpread_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientSpread_ReflectSpread_h) = 1;
            if (::hyve::define(QT::GradientSpread_ReflectSpread_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientSpread::ReflectSpread'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientSpread::RepeatSpread */
        if (!(QT::GradientSpread_RepeatSpread_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::GradientSpread::RepeatSpread", "load: check if object '::Qt::GradientSpread::RepeatSpread' already exists."))) {
            QT::GradientSpread_RepeatSpread_h = (::hyve::lang::constant*)::hyve::declare(QT::GradientSpread_h, "RepeatSpread", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::GradientSpread_RepeatSpread_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientSpread::RepeatSpread'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientSpread_RepeatSpread_h);
        }

        /* Define ::Qt::GradientSpread::RepeatSpread */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientSpread_RepeatSpread_h, ::hyve::lang::DEFINED)) {
            (*QT::GradientSpread_RepeatSpread_h) = 2;
            if (::hyve::define(QT::GradientSpread_RepeatSpread_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientSpread::RepeatSpread'.");
                goto error;
            }
        }
        /* Define ::Qt::GradientSpread */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientSpread_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::GradientSpread_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientSpread'.");
                goto error;
            }
        }
        /* Define ::Qt::Gradient::spread */
        if (!::hyve::checkState((::hyve::lang::object)QT::Gradient_spread_h, ::hyve::lang::DEFINED)) {
            QT::Gradient_spread_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::GradientSpread"));
            QT::Gradient_spread_h->modifiers = 0x0;
            QT::Gradient_spread_h->state = 0x6;
            QT::Gradient_spread_h->weak = FALSE;
            QT::Gradient_spread_h->id = 3;
            if (::hyve::define(QT::Gradient_spread_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Gradient::spread'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientStop */
        if (!(QT::GradientStop_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::GradientStop", "load: check if object '::Qt::GradientStop' already exists."))) {
            QT::GradientStop_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "GradientStop", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::GradientStop_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientStop'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientStop_h);
        }

        /* Declare ::Qt::GradientStop::color */
        if (!(QT::GradientStop_color_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GradientStop::color", "load: check if object '::Qt::GradientStop::color' already exists."))) {
            QT::GradientStop_color_h = (::hyve::lang::member)::hyve::declare(QT::GradientStop_h, "color", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GradientStop_color_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientStop::color'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientStop_color_h);
        }

        /* Define ::Qt::GradientStop::color */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientStop_color_h, ::hyve::lang::DEFINED)) {
            QT::GradientStop_color_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Color"));
            QT::GradientStop_color_h->modifiers = 0x0;
            QT::GradientStop_color_h->state = 0x6;
            QT::GradientStop_color_h->weak = FALSE;
            QT::GradientStop_color_h->id = 1;
            if (::hyve::define(QT::GradientStop_color_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientStop::color'.");
                goto error;
            }
        }
        /* Declare ::Qt::GradientStop::pos */
        if (!(QT::GradientStop_pos_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GradientStop::pos", "load: check if object '::Qt::GradientStop::pos' already exists."))) {
            QT::GradientStop_pos_h = (::hyve::lang::member)::hyve::declare(QT::GradientStop_h, "pos", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GradientStop_pos_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GradientStop::pos'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GradientStop_pos_h);
        }

        /* Define ::Qt::Gradient::stops */
        if (!::hyve::checkState((::hyve::lang::object)QT::Gradient_stops_h, ::hyve::lang::DEFINED)) {
            QT::Gradient_stops_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::Qt::GradientStop,0}"));
            QT::Gradient_stops_h->modifiers = 0x0;
            QT::Gradient_stops_h->state = 0x6;
            QT::Gradient_stops_h->weak = FALSE;
            QT::Gradient_stops_h->id = 1;
            if (::hyve::define(QT::Gradient_stops_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Gradient::stops'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridColumn */
        if (!(QT::GridColumn_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::GridColumn", "load: check if object '::Qt::GridColumn' already exists."))) {
            QT::GridColumn_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "GridColumn", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::GridColumn_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridColumn'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridColumn_h);
        }

        /* Declare ::Qt::GridColumn::minimumWidth */
        if (!(QT::GridColumn_minimumWidth_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridColumn::minimumWidth", "load: check if object '::Qt::GridColumn::minimumWidth' already exists."))) {
            QT::GridColumn_minimumWidth_h = (::hyve::lang::member)::hyve::declare(QT::GridColumn_h, "minimumWidth", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridColumn_minimumWidth_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridColumn::minimumWidth'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridColumn_minimumWidth_h);
        }

        /* Define ::Qt::GridColumn::minimumWidth */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridColumn_minimumWidth_h, ::hyve::lang::DEFINED)) {
            QT::GridColumn_minimumWidth_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridColumn_minimumWidth_h->modifiers = 0x0;
            QT::GridColumn_minimumWidth_h->state = 0x6;
            QT::GridColumn_minimumWidth_h->weak = FALSE;
            QT::GridColumn_minimumWidth_h->id = 1;
            if (::hyve::define(QT::GridColumn_minimumWidth_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridColumn::minimumWidth'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridColumn::stretch */
        if (!(QT::GridColumn_stretch_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridColumn::stretch", "load: check if object '::Qt::GridColumn::stretch' already exists."))) {
            QT::GridColumn_stretch_h = (::hyve::lang::member)::hyve::declare(QT::GridColumn_h, "stretch", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridColumn_stretch_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridColumn::stretch'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridColumn_stretch_h);
        }

        /* Define ::Qt::GridColumn::stretch */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridColumn_stretch_h, ::hyve::lang::DEFINED)) {
            QT::GridColumn_stretch_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridColumn_stretch_h->modifiers = 0x0;
            QT::GridColumn_stretch_h->state = 0x6;
            QT::GridColumn_stretch_h->weak = FALSE;
            QT::GridColumn_stretch_h->id = 0;
            if (::hyve::define(QT::GridColumn_stretch_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridColumn::stretch'.");
                goto error;
            }
        }
        /* Define ::Qt::GridColumn */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridColumn_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::GridColumn_h)->parentType = NULL;
            ((::hyve::lang::type)QT::GridColumn_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::GridColumn_h)->base = NULL;
            QT::GridColumn_h->baseAccess = 0x0;
            if (::hyve::define(QT::GridColumn_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridColumn'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridLayout */
        if (!(QT::GridLayout_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::GridLayout", "load: check if object '::Qt::GridLayout' already exists."))) {
            QT::GridLayout_h = (::hyve::lang::_class)::hyve::declare(QT_h, "GridLayout", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::GridLayout_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_h);
        }

        /* Declare ::Qt::GridLayout::columns */
        if (!(QT::GridLayout_columns_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridLayout::columns", "load: check if object '::Qt::GridLayout::columns' already exists."))) {
            QT::GridLayout_columns_h = (::hyve::lang::member)::hyve::declare(QT::GridLayout_h, "columns", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridLayout_columns_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout::columns'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_columns_h);
        }

        /* Define ::Qt::GridLayout::columns */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_columns_h, ::hyve::lang::DEFINED)) {
            QT::GridLayout_columns_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::Qt::GridColumn,0}"));
            QT::GridLayout_columns_h->modifiers = 0x0;
            QT::GridLayout_columns_h->state = 0x6;
            QT::GridLayout_columns_h->weak = FALSE;
            QT::GridLayout_columns_h->id = 1;
            if (::hyve::define(QT::GridLayout_columns_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout::columns'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridLayout::rows */
        if (!(QT::GridLayout_rows_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridLayout::rows", "load: check if object '::Qt::GridLayout::rows' already exists."))) {
            QT::GridLayout_rows_h = (::hyve::lang::member)::hyve::declare(QT::GridLayout_h, "rows", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridLayout_rows_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout::rows'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_rows_h);
        }

        /* Declare ::Qt::GridLayout::widgets */
        if (!(QT::GridLayout_widgets_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridLayout::widgets", "load: check if object '::Qt::GridLayout::widgets' already exists."))) {
            QT::GridLayout_widgets_h = (::hyve::lang::member)::hyve::declare(QT::GridLayout_h, "widgets", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridLayout_widgets_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout::widgets'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_widgets_h);
        }

        /* Declare ::Qt::GridRow */
        if (!(QT::GridRow_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::GridRow", "load: check if object '::Qt::GridRow' already exists."))) {
            QT::GridRow_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "GridRow", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::GridRow_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridRow'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridRow_h);
        }

        /* Declare ::Qt::GridRow::minimumHeight */
        if (!(QT::GridRow_minimumHeight_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridRow::minimumHeight", "load: check if object '::Qt::GridRow::minimumHeight' already exists."))) {
            QT::GridRow_minimumHeight_h = (::hyve::lang::member)::hyve::declare(QT::GridRow_h, "minimumHeight", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridRow_minimumHeight_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridRow::minimumHeight'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridRow_minimumHeight_h);
        }

        /* Define ::Qt::GridRow::minimumHeight */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridRow_minimumHeight_h, ::hyve::lang::DEFINED)) {
            QT::GridRow_minimumHeight_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridRow_minimumHeight_h->modifiers = 0x0;
            QT::GridRow_minimumHeight_h->state = 0x6;
            QT::GridRow_minimumHeight_h->weak = FALSE;
            QT::GridRow_minimumHeight_h->id = 1;
            if (::hyve::define(QT::GridRow_minimumHeight_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridRow::minimumHeight'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridRow::stretch */
        if (!(QT::GridRow_stretch_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridRow::stretch", "load: check if object '::Qt::GridRow::stretch' already exists."))) {
            QT::GridRow_stretch_h = (::hyve::lang::member)::hyve::declare(QT::GridRow_h, "stretch", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridRow_stretch_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridRow::stretch'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridRow_stretch_h);
        }

        /* Define ::Qt::GridRow::stretch */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridRow_stretch_h, ::hyve::lang::DEFINED)) {
            QT::GridRow_stretch_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridRow_stretch_h->modifiers = 0x0;
            QT::GridRow_stretch_h->state = 0x6;
            QT::GridRow_stretch_h->weak = FALSE;
            QT::GridRow_stretch_h->id = 0;
            if (::hyve::define(QT::GridRow_stretch_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridRow::stretch'.");
                goto error;
            }
        }
        /* Define ::Qt::GridRow */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridRow_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::GridRow_h)->parentType = NULL;
            ((::hyve::lang::type)QT::GridRow_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::GridRow_h)->base = NULL;
            QT::GridRow_h->baseAccess = 0x0;
            if (::hyve::define(QT::GridRow_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridRow'.");
                goto error;
            }
        }
        /* Define ::Qt::GridLayout::rows */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_rows_h, ::hyve::lang::DEFINED)) {
            QT::GridLayout_rows_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::Qt::GridRow,0}"));
            QT::GridLayout_rows_h->modifiers = 0x0;
            QT::GridLayout_rows_h->state = 0x6;
            QT::GridLayout_rows_h->weak = FALSE;
            QT::GridLayout_rows_h->id = 0;
            if (::hyve::define(QT::GridLayout_rows_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout::rows'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridWidget */
        if (!(QT::GridWidget_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::GridWidget", "load: check if object '::Qt::GridWidget' already exists."))) {
            QT::GridWidget_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "GridWidget", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::GridWidget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridWidget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridWidget_h);
        }

        /* Declare ::Qt::GridWidget::column */
        if (!(QT::GridWidget_column_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridWidget::column", "load: check if object '::Qt::GridWidget::column' already exists."))) {
            QT::GridWidget_column_h = (::hyve::lang::member)::hyve::declare(QT::GridWidget_h, "column", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridWidget_column_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridWidget::column'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridWidget_column_h);
        }

        /* Define ::Qt::GridWidget::column */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridWidget_column_h, ::hyve::lang::DEFINED)) {
            QT::GridWidget_column_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridWidget_column_h->modifiers = 0x0;
            QT::GridWidget_column_h->state = 0x6;
            QT::GridWidget_column_h->weak = FALSE;
            QT::GridWidget_column_h->id = 2;
            if (::hyve::define(QT::GridWidget_column_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridWidget::column'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridWidget::columnspan */
        if (!(QT::GridWidget_columnspan_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridWidget::columnspan", "load: check if object '::Qt::GridWidget::columnspan' already exists."))) {
            QT::GridWidget_columnspan_h = (::hyve::lang::member)::hyve::declare(QT::GridWidget_h, "columnspan", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridWidget_columnspan_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridWidget::columnspan'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridWidget_columnspan_h);
        }

        /* Define ::Qt::GridWidget::columnspan */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridWidget_columnspan_h, ::hyve::lang::DEFINED)) {
            QT::GridWidget_columnspan_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridWidget_columnspan_h->modifiers = 0x0;
            QT::GridWidget_columnspan_h->state = 0x6;
            QT::GridWidget_columnspan_h->weak = FALSE;
            QT::GridWidget_columnspan_h->id = 4;
            if (::hyve::define(QT::GridWidget_columnspan_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridWidget::columnspan'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridWidget::row */
        if (!(QT::GridWidget_row_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridWidget::row", "load: check if object '::Qt::GridWidget::row' already exists."))) {
            QT::GridWidget_row_h = (::hyve::lang::member)::hyve::declare(QT::GridWidget_h, "row", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridWidget_row_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridWidget::row'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridWidget_row_h);
        }

        /* Define ::Qt::GridWidget::row */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridWidget_row_h, ::hyve::lang::DEFINED)) {
            QT::GridWidget_row_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridWidget_row_h->modifiers = 0x0;
            QT::GridWidget_row_h->state = 0x6;
            QT::GridWidget_row_h->weak = FALSE;
            QT::GridWidget_row_h->id = 1;
            if (::hyve::define(QT::GridWidget_row_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridWidget::row'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridWidget::rowspan */
        if (!(QT::GridWidget_rowspan_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridWidget::rowspan", "load: check if object '::Qt::GridWidget::rowspan' already exists."))) {
            QT::GridWidget_rowspan_h = (::hyve::lang::member)::hyve::declare(QT::GridWidget_h, "rowspan", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridWidget_rowspan_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridWidget::rowspan'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridWidget_rowspan_h);
        }

        /* Define ::Qt::GridWidget::rowspan */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridWidget_rowspan_h, ::hyve::lang::DEFINED)) {
            QT::GridWidget_rowspan_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::GridWidget_rowspan_h->modifiers = 0x0;
            QT::GridWidget_rowspan_h->state = 0x6;
            QT::GridWidget_rowspan_h->weak = FALSE;
            QT::GridWidget_rowspan_h->id = 3;
            if (::hyve::define(QT::GridWidget_rowspan_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridWidget::rowspan'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridWidget::widget */
        if (!(QT::GridWidget_widget_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GridWidget::widget", "load: check if object '::Qt::GridWidget::widget' already exists."))) {
            QT::GridWidget_widget_h = (::hyve::lang::member)::hyve::declare(QT::GridWidget_h, "widget", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GridWidget_widget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridWidget::widget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridWidget_widget_h);
        }

        /* Define ::Qt::GridLayout::widgets */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_widgets_h, ::hyve::lang::DEFINED)) {
            QT::GridLayout_widgets_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::Qt::GridWidget,0}"));
            QT::GridLayout_widgets_h->modifiers = 0x0;
            QT::GridLayout_widgets_h->state = 0x6;
            QT::GridLayout_widgets_h->weak = FALSE;
            QT::GridLayout_widgets_h->id = 2;
            if (::hyve::define(QT::GridLayout_widgets_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout::widgets'.");
                goto error;
            }
        }
        /* Declare ::Qt::GroupBox */
        if (!(QT::GroupBox_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::GroupBox", "load: check if object '::Qt::GroupBox' already exists."))) {
            QT::GroupBox_h = (::hyve::lang::_class)::hyve::declare(QT_h, "GroupBox", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::GroupBox_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GroupBox'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GroupBox_h);
        }

        /* Declare ::Qt::GroupBox::title */
        if (!(QT::GroupBox_title_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::GroupBox::title", "load: check if object '::Qt::GroupBox::title' already exists."))) {
            QT::GroupBox_title_h = (::hyve::lang::member)::hyve::declare(QT::GroupBox_h, "title", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::GroupBox_title_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GroupBox::title'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GroupBox_title_h);
        }

        /* Define ::Qt::GroupBox::title */
        if (!::hyve::checkState((::hyve::lang::object)QT::GroupBox_title_h, ::hyve::lang::DEFINED)) {
            QT::GroupBox_title_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::GroupBox_title_h->modifiers = 0x0;
            QT::GroupBox_title_h->state = 0x6;
            QT::GroupBox_title_h->weak = FALSE;
            QT::GroupBox_title_h->id = 0;
            if (::hyve::define(QT::GroupBox_title_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GroupBox::title'.");
                goto error;
            }
        }
        /* Declare ::Qt::inputEvent_t */
        if (!(QT::inputEvent_t_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::inputEvent_t", "load: check if object '::Qt::inputEvent_t' already exists."))) {
            QT::inputEvent_t_h = (::hyve::lang::_class)::hyve::declare(QT_h, "inputEvent_t", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::inputEvent_t_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::inputEvent_t'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::inputEvent_t_h);
        }

        /* Declare ::Qt::inputEvent_t::modifiers */
        if (!(QT::inputEvent_t_modifiers_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::inputEvent_t::modifiers", "load: check if object '::Qt::inputEvent_t::modifiers' already exists."))) {
            QT::inputEvent_t_modifiers_h = (::hyve::lang::member)::hyve::declare(QT::inputEvent_t_h, "modifiers", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::inputEvent_t_modifiers_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::inputEvent_t::modifiers'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::inputEvent_t_modifiers_h);
        }

        /* Declare ::Qt::KeyboardModifiers */
        if (!(QT::KeyboardModifiers_h = (::hyve::lang::bitmask)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers", "load: check if object '::Qt::KeyboardModifiers' already exists."))) {
            QT::KeyboardModifiers_h = (::hyve::lang::bitmask)::hyve::declare(QT_h, "KeyboardModifiers", ((::hyve::lang::_typedef)::hyve::lang::bitmask_h));
            if (!QT::KeyboardModifiers_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_h);
        }

        /* Declare ::Qt::KeyboardModifiers::AltModifier */
        if (!(QT::KeyboardModifiers_AltModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::AltModifier", "load: check if object '::Qt::KeyboardModifiers::AltModifier' already exists."))) {
            QT::KeyboardModifiers_AltModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "AltModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_AltModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::AltModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_AltModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::AltModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_AltModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_AltModifier_h) = 134217728;
            if (::hyve::define(QT::KeyboardModifiers_AltModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::AltModifier'.");
                goto error;
            }
        }
        /* Declare ::Qt::KeyboardModifiers::ControlModifier */
        if (!(QT::KeyboardModifiers_ControlModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::ControlModifier", "load: check if object '::Qt::KeyboardModifiers::ControlModifier' already exists."))) {
            QT::KeyboardModifiers_ControlModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "ControlModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_ControlModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::ControlModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_ControlModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::ControlModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_ControlModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_ControlModifier_h) = 67108864;
            if (::hyve::define(QT::KeyboardModifiers_ControlModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::ControlModifier'.");
                goto error;
            }
        }
        /* Declare ::Qt::KeyboardModifiers::GroupSwitchModifier */
        if (!(QT::KeyboardModifiers_GroupSwitchModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::GroupSwitchModifier", "load: check if object '::Qt::KeyboardModifiers::GroupSwitchModifier' already exists."))) {
            QT::KeyboardModifiers_GroupSwitchModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "GroupSwitchModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_GroupSwitchModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::GroupSwitchModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_GroupSwitchModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::GroupSwitchModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_GroupSwitchModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_GroupSwitchModifier_h) = 1073741824;
            if (::hyve::define(QT::KeyboardModifiers_GroupSwitchModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::GroupSwitchModifier'.");
                goto error;
            }
        }
        /* Declare ::Qt::KeyboardModifiers::KeypadModifier */
        if (!(QT::KeyboardModifiers_KeypadModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::KeypadModifier", "load: check if object '::Qt::KeyboardModifiers::KeypadModifier' already exists."))) {
            QT::KeyboardModifiers_KeypadModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "KeypadModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_KeypadModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::KeypadModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_KeypadModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::KeypadModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_KeypadModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_KeypadModifier_h) = 536870912;
            if (::hyve::define(QT::KeyboardModifiers_KeypadModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::KeypadModifier'.");
                goto error;
            }
        }
        /* Declare ::Qt::KeyboardModifiers::MetaModifier */
        if (!(QT::KeyboardModifiers_MetaModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::MetaModifier", "load: check if object '::Qt::KeyboardModifiers::MetaModifier' already exists."))) {
            QT::KeyboardModifiers_MetaModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "MetaModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_MetaModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::MetaModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_MetaModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::MetaModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_MetaModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_MetaModifier_h) = 268435456;
            if (::hyve::define(QT::KeyboardModifiers_MetaModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::MetaModifier'.");
                goto error;
            }
        }
        /* Declare ::Qt::KeyboardModifiers::NoModifier */
        if (!(QT::KeyboardModifiers_NoModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::NoModifier", "load: check if object '::Qt::KeyboardModifiers::NoModifier' already exists."))) {
            QT::KeyboardModifiers_NoModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "NoModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_NoModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::NoModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_NoModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::NoModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_NoModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_NoModifier_h) = 0;
            if (::hyve::define(QT::KeyboardModifiers_NoModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::NoModifier'.");
                goto error;
            }
        }
        /* Declare ::Qt::KeyboardModifiers::ShiftModifier */
        if (!(QT::KeyboardModifiers_ShiftModifier_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::KeyboardModifiers::ShiftModifier", "load: check if object '::Qt::KeyboardModifiers::ShiftModifier' already exists."))) {
            QT::KeyboardModifiers_ShiftModifier_h = (::hyve::lang::constant*)::hyve::declare(QT::KeyboardModifiers_h, "ShiftModifier", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::KeyboardModifiers_ShiftModifier_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::KeyboardModifiers::ShiftModifier'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::KeyboardModifiers_ShiftModifier_h);
        }

        /* Define ::Qt::KeyboardModifiers::ShiftModifier */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_ShiftModifier_h, ::hyve::lang::DEFINED)) {
            (*QT::KeyboardModifiers_ShiftModifier_h) = 33554432;
            if (::hyve::define(QT::KeyboardModifiers_ShiftModifier_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers::ShiftModifier'.");
                goto error;
            }
        }
        /* Define ::Qt::KeyboardModifiers */
        if (!::hyve::checkState((::hyve::lang::object)QT::KeyboardModifiers_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::KeyboardModifiers_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::KeyboardModifiers'.");
                goto error;
            }
        }
        /* Define ::Qt::inputEvent_t::modifiers */
        if (!::hyve::checkState((::hyve::lang::object)QT::inputEvent_t_modifiers_h, ::hyve::lang::DEFINED)) {
            QT::inputEvent_t_modifiers_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::KeyboardModifiers"));
            QT::inputEvent_t_modifiers_h->modifiers = 0x0;
            QT::inputEvent_t_modifiers_h->state = 0x6;
            QT::inputEvent_t_modifiers_h->weak = FALSE;
            QT::inputEvent_t_modifiers_h->id = 0;
            if (::hyve::define(QT::inputEvent_t_modifiers_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::inputEvent_t::modifiers'.");
                goto error;
            }
        }
        /* Define ::Qt::inputEvent_t */
        if (!::hyve::checkState((::hyve::lang::object)QT::inputEvent_t_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::inputEvent_t_h)->parentType = NULL;
            ((::hyve::lang::type)QT::inputEvent_t_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::inputEvent_t_h)->base = NULL;
            ((::hyve::lang::_struct)QT::inputEvent_t_h)->baseAccess = 0x0;
            QT::inputEvent_t_h->implements.length = 0;
            QT::inputEvent_t_h->implements.buffer = NULL;
            if (::hyve::define(QT::inputEvent_t_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::inputEvent_t'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label */
        if (!(QT::Label_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Label", "load: check if object '::Qt::Label' already exists."))) {
            QT::Label_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Label", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Label_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_h);
        }

        /* Declare ::Qt::Label::alignment */
        if (!(QT::Label_alignment_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Label::alignment", "load: check if object '::Qt::Label::alignment' already exists."))) {
            QT::Label_alignment_h = (::hyve::lang::member)::hyve::declare(QT::Label_h, "alignment", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Label_alignment_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::alignment'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_alignment_h);
        }

        /* Define ::Qt::Label::alignment */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_alignment_h, ::hyve::lang::DEFINED)) {
            QT::Label_alignment_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Alignment"));
            QT::Label_alignment_h->modifiers = 0x0;
            QT::Label_alignment_h->state = 0x6;
            QT::Label_alignment_h->weak = FALSE;
            QT::Label_alignment_h->id = 1;
            if (::hyve::define(QT::Label_alignment_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::alignment'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label::text */
        if (!(QT::Label_text_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Label::text", "load: check if object '::Qt::Label::text' already exists."))) {
            QT::Label_text_h = (::hyve::lang::member)::hyve::declare(QT::Label_h, "text", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Label_text_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::text'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_text_h);
        }

        /* Define ::Qt::Label::text */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_text_h, ::hyve::lang::DEFINED)) {
            QT::Label_text_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::Label_text_h->modifiers = 0x0;
            QT::Label_text_h->state = 0x6;
            QT::Label_text_h->weak = FALSE;
            QT::Label_text_h->id = 0;
            if (::hyve::define(QT::Label_text_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::text'.");
                goto error;
            }
        }
        /* Declare ::Qt::Line */
        if (!(QT::Line_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::Line", "load: check if object '::Qt::Line' already exists."))) {
            QT::Line_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "Line", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::Line_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Line'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Line_h);
        }

        /* Declare ::Qt::Line::x1 */
        if (!(QT::Line_x1_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Line::x1", "load: check if object '::Qt::Line::x1' already exists."))) {
            QT::Line_x1_h = (::hyve::lang::member)::hyve::declare(QT::Line_h, "x1", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Line_x1_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Line::x1'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Line_x1_h);
        }

        /* Define ::Qt::Line::x1 */
        if (!::hyve::checkState((::hyve::lang::object)QT::Line_x1_h, ::hyve::lang::DEFINED)) {
            QT::Line_x1_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Line_x1_h->modifiers = 0x0;
            QT::Line_x1_h->state = 0x6;
            QT::Line_x1_h->weak = FALSE;
            QT::Line_x1_h->id = 0;
            if (::hyve::define(QT::Line_x1_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Line::x1'.");
                goto error;
            }
        }
        /* Declare ::Qt::Line::x2 */
        if (!(QT::Line_x2_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Line::x2", "load: check if object '::Qt::Line::x2' already exists."))) {
            QT::Line_x2_h = (::hyve::lang::member)::hyve::declare(QT::Line_h, "x2", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Line_x2_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Line::x2'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Line_x2_h);
        }

        /* Define ::Qt::Line::x2 */
        if (!::hyve::checkState((::hyve::lang::object)QT::Line_x2_h, ::hyve::lang::DEFINED)) {
            QT::Line_x2_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Line_x2_h->modifiers = 0x0;
            QT::Line_x2_h->state = 0x6;
            QT::Line_x2_h->weak = FALSE;
            QT::Line_x2_h->id = 2;
            if (::hyve::define(QT::Line_x2_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Line::x2'.");
                goto error;
            }
        }
        /* Declare ::Qt::Line::y1 */
        if (!(QT::Line_y1_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Line::y1", "load: check if object '::Qt::Line::y1' already exists."))) {
            QT::Line_y1_h = (::hyve::lang::member)::hyve::declare(QT::Line_h, "y1", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Line_y1_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Line::y1'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Line_y1_h);
        }

        /* Define ::Qt::Line::y1 */
        if (!::hyve::checkState((::hyve::lang::object)QT::Line_y1_h, ::hyve::lang::DEFINED)) {
            QT::Line_y1_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Line_y1_h->modifiers = 0x0;
            QT::Line_y1_h->state = 0x6;
            QT::Line_y1_h->weak = FALSE;
            QT::Line_y1_h->id = 1;
            if (::hyve::define(QT::Line_y1_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Line::y1'.");
                goto error;
            }
        }
        /* Declare ::Qt::Line::y2 */
        if (!(QT::Line_y2_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Line::y2", "load: check if object '::Qt::Line::y2' already exists."))) {
            QT::Line_y2_h = (::hyve::lang::member)::hyve::declare(QT::Line_h, "y2", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Line_y2_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Line::y2'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Line_y2_h);
        }

        /* Define ::Qt::Line::y2 */
        if (!::hyve::checkState((::hyve::lang::object)QT::Line_y2_h, ::hyve::lang::DEFINED)) {
            QT::Line_y2_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Line_y2_h->modifiers = 0x0;
            QT::Line_y2_h->state = 0x6;
            QT::Line_y2_h->weak = FALSE;
            QT::Line_y2_h->id = 3;
            if (::hyve::define(QT::Line_y2_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Line::y2'.");
                goto error;
            }
        }
        /* Define ::Qt::Line */
        if (!::hyve::checkState((::hyve::lang::object)QT::Line_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Line_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Line_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Line_h)->base = NULL;
            QT::Line_h->baseAccess = 0x0;
            if (::hyve::define(QT::Line_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Line'.");
                goto error;
            }
        }
        /* Declare ::Qt::LinearGradient */
        if (!(QT::LinearGradient_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::LinearGradient", "load: check if object '::Qt::LinearGradient' already exists."))) {
            QT::LinearGradient_h = (::hyve::lang::_class)::hyve::declare(QT_h, "LinearGradient", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::LinearGradient_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LinearGradient'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LinearGradient_h);
        }

        /* Declare ::Qt::LinearGradient::finalStop */
        if (!(QT::LinearGradient_finalStop_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LinearGradient::finalStop", "load: check if object '::Qt::LinearGradient::finalStop' already exists."))) {
            QT::LinearGradient_finalStop_h = (::hyve::lang::member)::hyve::declare(QT::LinearGradient_h, "finalStop", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LinearGradient_finalStop_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LinearGradient::finalStop'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LinearGradient_finalStop_h);
        }

        /* Declare ::Qt::LinearGradient::start */
        if (!(QT::LinearGradient_start_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LinearGradient::start", "load: check if object '::Qt::LinearGradient::start' already exists."))) {
            QT::LinearGradient_start_h = (::hyve::lang::member)::hyve::declare(QT::LinearGradient_h, "start", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LinearGradient_start_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LinearGradient::start'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LinearGradient_start_h);
        }

        /* Declare ::Qt::LineEdit */
        if (!(QT::LineEdit_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::LineEdit", "load: check if object '::Qt::LineEdit' already exists."))) {
            QT::LineEdit_h = (::hyve::lang::_class)::hyve::declare(QT_h, "LineEdit", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::LineEdit_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineEdit'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineEdit_h);
        }

        /* Declare ::Qt::LineEdit::readonly */
        if (!(QT::LineEdit_readonly_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LineEdit::readonly", "load: check if object '::Qt::LineEdit::readonly' already exists."))) {
            QT::LineEdit_readonly_h = (::hyve::lang::member)::hyve::declare(QT::LineEdit_h, "readonly", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LineEdit_readonly_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineEdit::readonly'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineEdit_readonly_h);
        }

        /* Define ::Qt::LineEdit::readonly */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineEdit_readonly_h, ::hyve::lang::DEFINED)) {
            QT::LineEdit_readonly_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::LineEdit_readonly_h->modifiers = 0x0;
            QT::LineEdit_readonly_h->state = 0x6;
            QT::LineEdit_readonly_h->weak = FALSE;
            QT::LineEdit_readonly_h->id = 1;
            if (::hyve::define(QT::LineEdit_readonly_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineEdit::readonly'.");
                goto error;
            }
        }
        /* Declare ::Qt::LineEdit::text */
        if (!(QT::LineEdit_text_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LineEdit::text", "load: check if object '::Qt::LineEdit::text' already exists."))) {
            QT::LineEdit_text_h = (::hyve::lang::member)::hyve::declare(QT::LineEdit_h, "text", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LineEdit_text_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineEdit::text'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineEdit_text_h);
        }

        /* Define ::Qt::LineEdit::text */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineEdit_text_h, ::hyve::lang::DEFINED)) {
            QT::LineEdit_text_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::LineEdit_text_h->modifiers = 0x0;
            QT::LineEdit_text_h->state = 0x6;
            QT::LineEdit_text_h->weak = FALSE;
            QT::LineEdit_text_h->id = 0;
            if (::hyve::define(QT::LineEdit_text_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineEdit::text'.");
                goto error;
            }
        }
        /* Declare ::Qt::LineF */
        if (!(QT::LineF_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::LineF", "load: check if object '::Qt::LineF' already exists."))) {
            QT::LineF_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "LineF", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::LineF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineF'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineF_h);
        }

        /* Declare ::Qt::LineF::x1 */
        if (!(QT::LineF_x1_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LineF::x1", "load: check if object '::Qt::LineF::x1' already exists."))) {
            QT::LineF_x1_h = (::hyve::lang::member)::hyve::declare(QT::LineF_h, "x1", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LineF_x1_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineF::x1'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineF_x1_h);
        }

        /* Declare ::Qt::LineF::x2 */
        if (!(QT::LineF_x2_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LineF::x2", "load: check if object '::Qt::LineF::x2' already exists."))) {
            QT::LineF_x2_h = (::hyve::lang::member)::hyve::declare(QT::LineF_h, "x2", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LineF_x2_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineF::x2'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineF_x2_h);
        }

        /* Declare ::Qt::LineF::y1 */
        if (!(QT::LineF_y1_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LineF::y1", "load: check if object '::Qt::LineF::y1' already exists."))) {
            QT::LineF_y1_h = (::hyve::lang::member)::hyve::declare(QT::LineF_h, "y1", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LineF_y1_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineF::y1'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineF_y1_h);
        }

        /* Declare ::Qt::LineF::y2 */
        if (!(QT::LineF_y2_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::LineF::y2", "load: check if object '::Qt::LineF::y2' already exists."))) {
            QT::LineF_y2_h = (::hyve::lang::member)::hyve::declare(QT::LineF_h, "y2", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::LineF_y2_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineF::y2'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineF_y2_h);
        }

        /* Declare ::Qt::ListWidget */
        if (!(QT::ListWidget_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ListWidget", "load: check if object '::Qt::ListWidget' already exists."))) {
            QT::ListWidget_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ListWidget", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ListWidget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_h);
        }

        /* Declare ::Qt::ListWidget::currentIndex */
        if (!(QT::ListWidget_currentIndex_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::currentIndex", "load: check if object '::Qt::ListWidget::currentIndex' already exists."))) {
            QT::ListWidget_currentIndex_h = (::hyve::lang::member)::hyve::declare(QT::ListWidget_h, "currentIndex", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ListWidget_currentIndex_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::currentIndex'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_currentIndex_h);
        }

        /* Define ::Qt::ListWidget::currentIndex */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_currentIndex_h, ::hyve::lang::DEFINED)) {
            QT::ListWidget_currentIndex_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::ListWidget_currentIndex_h->modifiers = 0x0;
            QT::ListWidget_currentIndex_h->state = 0x6;
            QT::ListWidget_currentIndex_h->weak = FALSE;
            QT::ListWidget_currentIndex_h->id = 1;
            if (::hyve::define(QT::ListWidget_currentIndex_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::currentIndex'.");
                goto error;
            }
        }
        /* Declare ::Qt::ListWidget::currentText */
        if (!(QT::ListWidget_currentText_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::currentText", "load: check if object '::Qt::ListWidget::currentText' already exists."))) {
            QT::ListWidget_currentText_h = (::hyve::lang::member)::hyve::declare(QT::ListWidget_h, "currentText", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ListWidget_currentText_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::currentText'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_currentText_h);
        }

        /* Define ::Qt::ListWidget::currentText */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_currentText_h, ::hyve::lang::DEFINED)) {
            QT::ListWidget_currentText_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ListWidget_currentText_h->modifiers = 0x0;
            QT::ListWidget_currentText_h->state = 0x6;
            QT::ListWidget_currentText_h->weak = FALSE;
            QT::ListWidget_currentText_h->id = 2;
            if (::hyve::define(QT::ListWidget_currentText_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::currentText'.");
                goto error;
            }
        }
        /* Declare ::Qt::ListWidget::items */
        if (!(QT::ListWidget_items_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::items", "load: check if object '::Qt::ListWidget::items' already exists."))) {
            QT::ListWidget_items_h = (::hyve::lang::member)::hyve::declare(QT::ListWidget_h, "items", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ListWidget_items_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::items'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_items_h);
        }

        /* Declare ::Qt::MainWindow */
        if (!(QT::MainWindow_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::MainWindow", "load: check if object '::Qt::MainWindow' already exists."))) {
            QT::MainWindow_h = (::hyve::lang::_class)::hyve::declare(QT_h, "MainWindow", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::MainWindow_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MainWindow'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MainWindow_h);
        }

        /* Declare ::Qt::MainWindow::cw */
        if (!(QT::MainWindow_cw_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::MainWindow::cw", "load: check if object '::Qt::MainWindow::cw' already exists."))) {
            QT::MainWindow_cw_h = (::hyve::lang::member)::hyve::declare(QT::MainWindow_h, "cw", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::MainWindow_cw_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MainWindow::cw'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MainWindow_cw_h);
        }

        /* Define ::Qt::MainWindow::cw */
        if (!::hyve::checkState((::hyve::lang::object)QT::MainWindow_cw_h, ::hyve::lang::DEFINED)) {
            QT::MainWindow_cw_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
            QT::MainWindow_cw_h->modifiers = 0x3;
            QT::MainWindow_cw_h->state = 0x6;
            QT::MainWindow_cw_h->weak = FALSE;
            QT::MainWindow_cw_h->id = 1;
            if (::hyve::define(QT::MainWindow_cw_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MainWindow::cw'.");
                goto error;
            }
        }
        /* Declare ::Qt::MainWindow::title */
        if (!(QT::MainWindow_title_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::MainWindow::title", "load: check if object '::Qt::MainWindow::title' already exists."))) {
            QT::MainWindow_title_h = (::hyve::lang::member)::hyve::declare(QT::MainWindow_h, "title", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::MainWindow_title_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MainWindow::title'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MainWindow_title_h);
        }

        /* Define ::Qt::MainWindow::title */
        if (!::hyve::checkState((::hyve::lang::object)QT::MainWindow_title_h, ::hyve::lang::DEFINED)) {
            QT::MainWindow_title_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::MainWindow_title_h->modifiers = 0x0;
            QT::MainWindow_title_h->state = 0x6;
            QT::MainWindow_title_h->weak = FALSE;
            QT::MainWindow_title_h->id = 0;
            if (::hyve::define(QT::MainWindow_title_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MainWindow::title'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton */
        if (!(QT::MouseButton_h = (::hyve::lang::bitmask)::hyve::resolve(NULL, NULL, "::Qt::MouseButton", "load: check if object '::Qt::MouseButton' already exists."))) {
            QT::MouseButton_h = (::hyve::lang::bitmask)::hyve::declare(QT_h, "MouseButton", ((::hyve::lang::_typedef)::hyve::lang::bitmask_h));
            if (!QT::MouseButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_h);
        }

        /* Declare ::Qt::MouseButton::LeftButton */
        if (!(QT::MouseButton_LeftButton_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::LeftButton", "load: check if object '::Qt::MouseButton::LeftButton' already exists."))) {
            QT::MouseButton_LeftButton_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "LeftButton", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_LeftButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::LeftButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_LeftButton_h);
        }

        /* Define ::Qt::MouseButton::LeftButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_LeftButton_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_LeftButton_h) = 1;
            if (::hyve::define(QT::MouseButton_LeftButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::LeftButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton::MidButton */
        if (!(QT::MouseButton_MidButton_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::MidButton", "load: check if object '::Qt::MouseButton::MidButton' already exists."))) {
            QT::MouseButton_MidButton_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "MidButton", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_MidButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::MidButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_MidButton_h);
        }

        /* Define ::Qt::MouseButton::MidButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_MidButton_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_MidButton_h) = 4;
            if (::hyve::define(QT::MouseButton_MidButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::MidButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton::MiddleButton */
        if (!(QT::MouseButton_MiddleButton_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::MiddleButton", "load: check if object '::Qt::MouseButton::MiddleButton' already exists."))) {
            QT::MouseButton_MiddleButton_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "MiddleButton", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_MiddleButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::MiddleButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_MiddleButton_h);
        }

        /* Define ::Qt::MouseButton::MiddleButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_MiddleButton_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_MiddleButton_h) = 4;
            if (::hyve::define(QT::MouseButton_MiddleButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::MiddleButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton::NoButton */
        if (!(QT::MouseButton_NoButton_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::NoButton", "load: check if object '::Qt::MouseButton::NoButton' already exists."))) {
            QT::MouseButton_NoButton_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "NoButton", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_NoButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::NoButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_NoButton_h);
        }

        /* Define ::Qt::MouseButton::NoButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_NoButton_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_NoButton_h) = 0;
            if (::hyve::define(QT::MouseButton_NoButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::NoButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton::RightButton */
        if (!(QT::MouseButton_RightButton_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::RightButton", "load: check if object '::Qt::MouseButton::RightButton' already exists."))) {
            QT::MouseButton_RightButton_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "RightButton", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_RightButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::RightButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_RightButton_h);
        }

        /* Define ::Qt::MouseButton::RightButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_RightButton_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_RightButton_h) = 2;
            if (::hyve::define(QT::MouseButton_RightButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::RightButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton::XButton1 */
        if (!(QT::MouseButton_XButton1_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::XButton1", "load: check if object '::Qt::MouseButton::XButton1' already exists."))) {
            QT::MouseButton_XButton1_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "XButton1", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_XButton1_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::XButton1'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_XButton1_h);
        }

        /* Define ::Qt::MouseButton::XButton1 */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_XButton1_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_XButton1_h) = 8;
            if (::hyve::define(QT::MouseButton_XButton1_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::XButton1'.");
                goto error;
            }
        }
        /* Declare ::Qt::MouseButton::XButton2 */
        if (!(QT::MouseButton_XButton2_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::MouseButton::XButton2", "load: check if object '::Qt::MouseButton::XButton2' already exists."))) {
            QT::MouseButton_XButton2_h = (::hyve::lang::constant*)::hyve::declare(QT::MouseButton_h, "XButton2", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::MouseButton_XButton2_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MouseButton::XButton2'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MouseButton_XButton2_h);
        }

        /* Define ::Qt::MouseButton::XButton2 */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_XButton2_h, ::hyve::lang::DEFINED)) {
            (*QT::MouseButton_XButton2_h) = 16;
            if (::hyve::define(QT::MouseButton_XButton2_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton::XButton2'.");
                goto error;
            }
        }
        /* Define ::Qt::MouseButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::MouseButton_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::MouseButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MouseButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::mouseEvent_t */
        if (!(QT::mouseEvent_t_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::mouseEvent_t", "load: check if object '::Qt::mouseEvent_t' already exists."))) {
            QT::mouseEvent_t_h = (::hyve::lang::_class)::hyve::declare(QT_h, "mouseEvent_t", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::mouseEvent_t_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::mouseEvent_t'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::mouseEvent_t_h);
        }

        /* Declare ::Qt::mouseEvent_t::buttons */
        if (!(QT::mouseEvent_t_buttons_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::mouseEvent_t::buttons", "load: check if object '::Qt::mouseEvent_t::buttons' already exists."))) {
            QT::mouseEvent_t_buttons_h = (::hyve::lang::member)::hyve::declare(QT::mouseEvent_t_h, "buttons", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::mouseEvent_t_buttons_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::mouseEvent_t::buttons'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::mouseEvent_t_buttons_h);
        }

        /* Define ::Qt::mouseEvent_t::buttons */
        if (!::hyve::checkState((::hyve::lang::object)QT::mouseEvent_t_buttons_h, ::hyve::lang::DEFINED)) {
            QT::mouseEvent_t_buttons_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::MouseButton"));
            QT::mouseEvent_t_buttons_h->modifiers = 0x0;
            QT::mouseEvent_t_buttons_h->state = 0x6;
            QT::mouseEvent_t_buttons_h->weak = FALSE;
            QT::mouseEvent_t_buttons_h->id = 2;
            if (::hyve::define(QT::mouseEvent_t_buttons_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::mouseEvent_t::buttons'.");
                goto error;
            }
        }
        /* Declare ::Qt::mouseEvent_t::x */
        if (!(QT::mouseEvent_t_x_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::mouseEvent_t::x", "load: check if object '::Qt::mouseEvent_t::x' already exists."))) {
            QT::mouseEvent_t_x_h = (::hyve::lang::member)::hyve::declare(QT::mouseEvent_t_h, "x", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::mouseEvent_t_x_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::mouseEvent_t::x'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::mouseEvent_t_x_h);
        }

        /* Define ::Qt::mouseEvent_t::x */
        if (!::hyve::checkState((::hyve::lang::object)QT::mouseEvent_t_x_h, ::hyve::lang::DEFINED)) {
            QT::mouseEvent_t_x_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::mouseEvent_t_x_h->modifiers = 0x0;
            QT::mouseEvent_t_x_h->state = 0x6;
            QT::mouseEvent_t_x_h->weak = FALSE;
            QT::mouseEvent_t_x_h->id = 0;
            if (::hyve::define(QT::mouseEvent_t_x_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::mouseEvent_t::x'.");
                goto error;
            }
        }
        /* Declare ::Qt::mouseEvent_t::y */
        if (!(QT::mouseEvent_t_y_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::mouseEvent_t::y", "load: check if object '::Qt::mouseEvent_t::y' already exists."))) {
            QT::mouseEvent_t_y_h = (::hyve::lang::member)::hyve::declare(QT::mouseEvent_t_h, "y", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::mouseEvent_t_y_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::mouseEvent_t::y'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::mouseEvent_t_y_h);
        }

        /* Define ::Qt::mouseEvent_t::y */
        if (!::hyve::checkState((::hyve::lang::object)QT::mouseEvent_t_y_h, ::hyve::lang::DEFINED)) {
            QT::mouseEvent_t_y_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::mouseEvent_t_y_h->modifiers = 0x0;
            QT::mouseEvent_t_y_h->state = 0x6;
            QT::mouseEvent_t_y_h->weak = FALSE;
            QT::mouseEvent_t_y_h->id = 1;
            if (::hyve::define(QT::mouseEvent_t_y_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::mouseEvent_t::y'.");
                goto error;
            }
        }
        /* Define ::Qt::mouseEvent_t */
        if (!::hyve::checkState((::hyve::lang::object)QT::mouseEvent_t_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::mouseEvent_t_h)->parentType = NULL;
            ((::hyve::lang::type)QT::mouseEvent_t_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::mouseEvent_t_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::inputEvent_t"));
            ((::hyve::lang::_struct)QT::mouseEvent_t_h)->baseAccess = 0x0;
            QT::mouseEvent_t_h->implements.length = 0;
            QT::mouseEvent_t_h->implements.buffer = NULL;
            if (::hyve::define(QT::mouseEvent_t_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::mouseEvent_t'.");
                goto error;
            }
        }
        /* Declare ::Qt::Object */
        if (!(QT::Object_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Object", "load: check if object '::Qt::Object' already exists."))) {
            QT::Object_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Object", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Object_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Object'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Object_h);
        }

        /* Declare ::Qt::Object::qhandle */
        if (!(QT::Object_qhandle_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Object::qhandle", "load: check if object '::Qt::Object::qhandle' already exists."))) {
            QT::Object_qhandle_h = (::hyve::lang::member)::hyve::declare(QT::Object_h, "qhandle", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Object_qhandle_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Object::qhandle'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Object_qhandle_h);
        }

        /* Define ::Qt::Object::qhandle */
        if (!::hyve::checkState((::hyve::lang::object)QT::Object_qhandle_h, ::hyve::lang::DEFINED)) {
            QT::Object_qhandle_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
            QT::Object_qhandle_h->modifiers = 0x3;
            QT::Object_qhandle_h->state = 0x6;
            QT::Object_qhandle_h->weak = FALSE;
            QT::Object_qhandle_h->id = 0;
            if (::hyve::define(QT::Object_qhandle_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Object::qhandle'.");
                goto error;
            }
        }
        /* Declare ::Qt::Object::widgetParent() */
        if (!(QT::Object_widgetParent_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Object::widgetParent()", "load: check if object '::Qt::Object::widgetParent()' already exists."))) {
            QT::Object_widgetParent_h = (::hyve::lang::method)::hyve::declare(QT::Object_h, "widgetParent()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Object_widgetParent_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Object::widgetParent()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Object_widgetParent_h);
        }

        /* Define ::Qt::Object::widgetParent() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Object_widgetParent_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Object_widgetParent_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
            QT::Object_widgetParent_h->_virtual = FALSE;
            
            /* Bind QT::Object_widgetParent_h with C++ function */
            ((::hyve::lang::function)QT::Object_widgetParent_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Object_widgetParent_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Object_widgetParent);
            if (::hyve::define(QT::Object_widgetParent_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Object::widgetParent()'.");
                goto error;
            }
        }
        /* Define ::Qt::Object */
        if (!::hyve::checkState((::hyve::lang::object)QT::Object_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Object_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Object_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Object_h)->base = NULL;
            ((::hyve::lang::_struct)QT::Object_h)->baseAccess = 0x0;
            QT::Object_h->implements.length = 0;
            QT::Object_h->implements.buffer = NULL;
            if (::hyve::define(QT::Object_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Object'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application::exec() */
        if (!(QT::Application_exec_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Application::exec()", "load: check if object '::Qt::Application::exec()' already exists."))) {
            QT::Application_exec_h = (::hyve::lang::method)::hyve::declare(QT::Application_h, "exec()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Application_exec_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::exec()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_exec_h);
        }

        /* Define ::Qt::Application::exec() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_exec_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Application_exec_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Application_exec_h->_virtual = FALSE;
            
            /* Bind QT::Application_exec_h with C++ function */
            ((::hyve::lang::function)QT::Application_exec_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Application_exec_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Application_exec);
            if (::hyve::define(QT::Application_exec_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::exec()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
        if (!(QT::Application_getEvent_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)", "load: check if object '::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)' already exists."))) {
            QT::Application_getEvent_h = (::hyve::lang::method)::hyve::declare(QT::Application_h, "getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Application_getEvent_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_getEvent_h);
        }

        /* Define ::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_getEvent_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Application_getEvent_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observableEvent"));
            QT::Application_getEvent_h->_virtual = FALSE;
            
            /* Bind QT::Application_getEvent_h with C++ function */
            ((::hyve::lang::function)QT::Application_getEvent_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Application_getEvent_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Application_getEvent);
            if (::hyve::define(QT::Application_getEvent_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application::post(::hyve::lang::event event) */
        if (!(QT::Application_post_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Application::post(::hyve::lang::event event)", "load: check if object '::Qt::Application::post(::hyve::lang::event event)' already exists."))) {
            QT::Application_post_h = (::hyve::lang::method)::hyve::declare(QT::Application_h, "post(::hyve::lang::event event)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Application_post_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::post(::hyve::lang::event event)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_post_h);
        }

        /* Define ::Qt::Application::post(::hyve::lang::event event) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_post_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Application_post_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Application_post_h->_virtual = FALSE;
            
            /* Bind QT::Application_post_h with C++ function */
            ((::hyve::lang::function)QT::Application_post_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Application_post_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Application_post);
            if (::hyve::define(QT::Application_post_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::post(::hyve::lang::event event)'.");
                goto error;
            }
        }
        /* Define ::Qt::Gradient */
        if (!::hyve::checkState((::hyve::lang::object)QT::Gradient_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Gradient_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Gradient_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Gradient_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Gradient_h)->baseAccess = 0x0;
            QT::Gradient_h->implements.length = 0;
            QT::Gradient_h->implements.buffer = NULL;
            if (::hyve::define(QT::Gradient_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Gradient'.");
                goto error;
            }
        }
        /* Define ::Qt::Brush::gradient */
        if (!::hyve::checkState((::hyve::lang::object)QT::Brush_gradient_h, ::hyve::lang::DEFINED)) {
            QT::Brush_gradient_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Gradient"));
            QT::Brush_gradient_h->modifiers = 0x0;
            QT::Brush_gradient_h->state = 0x6;
            QT::Brush_gradient_h->weak = FALSE;
            QT::Brush_gradient_h->id = 1;
            if (::hyve::define(QT::Brush_gradient_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Brush::gradient'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridLayout::onSelf */
        if (!(QT::GridLayout_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::GridLayout::onSelf", "load: check if object '::Qt::GridLayout::onSelf' already exists."))) {
            QT::GridLayout_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::GridLayout_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::GridLayout_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_onSelf_h);
        }

        /* Define ::Qt::GridLayout::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::GridLayout_onSelf_h->observable = NULL;
            QT::GridLayout_onSelf_h->mask = 0xb0;
            QT::GridLayout_onSelf_h->expression = NULL;
            QT::GridLayout_onSelf_h->_template = 1;
            QT::GridLayout_onSelf_h->dispatcher = NULL;
            QT::GridLayout_onSelf_h->me = NULL;
            
            /* Bind QT::GridLayout_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::GridLayout_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::GridLayout_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_GridLayout_onSelf);
            if (::hyve::define(QT::GridLayout_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse */
        if (!(QT::ObjectBrowse_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse", "load: check if object '::Qt::ObjectBrowse' already exists."))) {
            QT::ObjectBrowse_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ObjectBrowse", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ObjectBrowse_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_h);
        }

        /* Declare ::Qt::ObjectBrowse::expr */
        if (!(QT::ObjectBrowse_expr_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::expr", "load: check if object '::Qt::ObjectBrowse::expr' already exists."))) {
            QT::ObjectBrowse_expr_h = (::hyve::lang::member)::hyve::declare(QT::ObjectBrowse_h, "expr", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectBrowse_expr_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::expr'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_expr_h);
        }

        /* Define ::Qt::ObjectBrowse::expr */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_expr_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_expr_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ObjectBrowse_expr_h->modifiers = 0x0;
            QT::ObjectBrowse_expr_h->state = 0x6;
            QT::ObjectBrowse_expr_h->weak = FALSE;
            QT::ObjectBrowse_expr_h->id = 2;
            if (::hyve::define(QT::ObjectBrowse_expr_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::expr'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::object */
        if (!(QT::ObjectBrowse_object_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::object", "load: check if object '::Qt::ObjectBrowse::object' already exists."))) {
            QT::ObjectBrowse_object_h = (::hyve::lang::member)::hyve::declare(QT::ObjectBrowse_h, "object", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectBrowse_object_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::object'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_object_h);
        }

        /* Define ::Qt::ObjectBrowse::object */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_object_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_object_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
            QT::ObjectBrowse_object_h->modifiers = 0x0;
            QT::ObjectBrowse_object_h->state = 0x6;
            QT::ObjectBrowse_object_h->weak = FALSE;
            QT::ObjectBrowse_object_h->id = 0;
            if (::hyve::define(QT::ObjectBrowse_object_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::object'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::prevObject */
        if (!(QT::ObjectBrowse_prevObject_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::prevObject", "load: check if object '::Qt::ObjectBrowse::prevObject' already exists."))) {
            QT::ObjectBrowse_prevObject_h = (::hyve::lang::member)::hyve::declare(QT::ObjectBrowse_h, "prevObject", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectBrowse_prevObject_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::prevObject'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_prevObject_h);
        }

        /* Define ::Qt::ObjectBrowse::prevObject */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_prevObject_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_prevObject_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
            QT::ObjectBrowse_prevObject_h->modifiers = 0x3;
            QT::ObjectBrowse_prevObject_h->state = 0x6;
            QT::ObjectBrowse_prevObject_h->weak = FALSE;
            QT::ObjectBrowse_prevObject_h->id = 1;
            if (::hyve::define(QT::ObjectBrowse_prevObject_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::prevObject'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::showPrimitives */
        if (!(QT::ObjectBrowse_showPrimitives_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::showPrimitives", "load: check if object '::Qt::ObjectBrowse::showPrimitives' already exists."))) {
            QT::ObjectBrowse_showPrimitives_h = (::hyve::lang::member)::hyve::declare(QT::ObjectBrowse_h, "showPrimitives", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectBrowse_showPrimitives_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::showPrimitives'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_showPrimitives_h);
        }

        /* Define ::Qt::ObjectBrowse::showPrimitives */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_showPrimitives_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_showPrimitives_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::ObjectBrowse_showPrimitives_h->modifiers = 0x0;
            QT::ObjectBrowse_showPrimitives_h->state = 0x6;
            QT::ObjectBrowse_showPrimitives_h->weak = FALSE;
            QT::ObjectBrowse_showPrimitives_h->id = 3;
            if (::hyve::define(QT::ObjectBrowse_showPrimitives_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::showPrimitives'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile */
        if (!(QT::ObjectTile_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile", "load: check if object '::Qt::ObjectTile' already exists."))) {
            QT::ObjectTile_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ObjectTile", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ObjectTile_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_h);
        }

        /* Declare ::Qt::ObjectTile::scope */
        if (!(QT::ObjectTile_scope_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::scope", "load: check if object '::Qt::ObjectTile::scope' already exists."))) {
            QT::ObjectTile_scope_h = (::hyve::lang::member)::hyve::declare(QT::ObjectTile_h, "scope", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectTile_scope_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::scope'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_scope_h);
        }

        /* Define ::Qt::ObjectTile::scope */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_scope_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTile_scope_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ObjectTile_scope_h->modifiers = 0x0;
            QT::ObjectTile_scope_h->state = 0x6;
            QT::ObjectTile_scope_h->weak = FALSE;
            QT::ObjectTile_scope_h->id = 0;
            if (::hyve::define(QT::ObjectTile_scope_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::scope'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile::scopeCache */
        if (!(QT::ObjectTile_scopeCache_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::scopeCache", "load: check if object '::Qt::ObjectTile::scopeCache' already exists."))) {
            QT::ObjectTile_scopeCache_h = (::hyve::lang::member)::hyve::declare(QT::ObjectTile_h, "scopeCache", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectTile_scopeCache_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::scopeCache'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_scopeCache_h);
        }

        /* Define ::Qt::ObjectTile::scopeCache */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_scopeCache_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTile_scopeCache_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
            QT::ObjectTile_scopeCache_h->modifiers = 0x0;
            QT::ObjectTile_scopeCache_h->state = 0x6;
            QT::ObjectTile_scopeCache_h->weak = FALSE;
            QT::ObjectTile_scopeCache_h->id = 1;
            if (::hyve::define(QT::ObjectTile_scopeCache_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::scopeCache'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree */
        if (!(QT::ObjectTree_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree", "load: check if object '::Qt::ObjectTree' already exists."))) {
            QT::ObjectTree_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ObjectTree", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ObjectTree_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_h);
        }

        /* Declare ::Qt::ObjectTree::object */
        if (!(QT::ObjectTree_object_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::object", "load: check if object '::Qt::ObjectTree::object' already exists."))) {
            QT::ObjectTree_object_h = (::hyve::lang::member)::hyve::declare(QT::ObjectTree_h, "object", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectTree_object_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::object'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_object_h);
        }

        /* Define ::Qt::ObjectTree::object */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_object_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTree_object_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
            QT::ObjectTree_object_h->modifiers = 0x0;
            QT::ObjectTree_object_h->state = 0x6;
            QT::ObjectTree_object_h->weak = FALSE;
            QT::ObjectTree_object_h->id = 1;
            if (::hyve::define(QT::ObjectTree_object_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::object'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::scope */
        if (!(QT::ObjectTree_scope_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::scope", "load: check if object '::Qt::ObjectTree::scope' already exists."))) {
            QT::ObjectTree_scope_h = (::hyve::lang::member)::hyve::declare(QT::ObjectTree_h, "scope", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectTree_scope_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::scope'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_scope_h);
        }

        /* Define ::Qt::ObjectTree::scope */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_scope_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTree_scope_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
            QT::ObjectTree_scope_h->modifiers = 0x0;
            QT::ObjectTree_scope_h->state = 0x6;
            QT::ObjectTree_scope_h->weak = FALSE;
            QT::ObjectTree_scope_h->id = 0;
            if (::hyve::define(QT::ObjectTree_scope_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::scope'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView */
        if (!(QT::ObjectView_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ObjectView", "load: check if object '::Qt::ObjectView' already exists."))) {
            QT::ObjectView_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ObjectView", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ObjectView_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_h);
        }

        /* Declare ::Qt::ObjectView::expr */
        if (!(QT::ObjectView_expr_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::expr", "load: check if object '::Qt::ObjectView::expr' already exists."))) {
            QT::ObjectView_expr_h = (::hyve::lang::member)::hyve::declare(QT::ObjectView_h, "expr", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectView_expr_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::expr'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_expr_h);
        }

        /* Define ::Qt::ObjectView::expr */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_expr_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_expr_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ObjectView_expr_h->modifiers = 0x0;
            QT::ObjectView_expr_h->state = 0x6;
            QT::ObjectView_expr_h->weak = FALSE;
            QT::ObjectView_expr_h->id = 1;
            if (::hyve::define(QT::ObjectView_expr_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::expr'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::fields */
        if (!(QT::ObjectView_fields_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::fields", "load: check if object '::Qt::ObjectView::fields' already exists."))) {
            QT::ObjectView_fields_h = (::hyve::lang::member)::hyve::declare(QT::ObjectView_h, "fields", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectView_fields_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::fields'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_fields_h);
        }

        /* Declare ::Qt::ObjectView::object */
        if (!(QT::ObjectView_object_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::object", "load: check if object '::Qt::ObjectView::object' already exists."))) {
            QT::ObjectView_object_h = (::hyve::lang::member)::hyve::declare(QT::ObjectView_h, "object", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectView_object_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::object'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_object_h);
        }

        /* Define ::Qt::ObjectView::object */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_object_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_object_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
            QT::ObjectView_object_h->modifiers = 0x0;
            QT::ObjectView_object_h->state = 0x6;
            QT::ObjectView_object_h->weak = FALSE;
            QT::ObjectView_object_h->id = 0;
            if (::hyve::define(QT::ObjectView_object_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::object'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::selected */
        if (!(QT::ObjectView_selected_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::selected", "load: check if object '::Qt::ObjectView::selected' already exists."))) {
            QT::ObjectView_selected_h = (::hyve::lang::member)::hyve::declare(QT::ObjectView_h, "selected", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectView_selected_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::selected'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_selected_h);
        }

        /* Define ::Qt::ObjectView::selected */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_selected_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_selected_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ObjectView_selected_h->modifiers = 0x4;
            QT::ObjectView_selected_h->state = 0x6;
            QT::ObjectView_selected_h->weak = FALSE;
            QT::ObjectView_selected_h->id = 4;
            if (::hyve::define(QT::ObjectView_selected_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::selected'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::selectedElement */
        if (!(QT::ObjectView_selectedElement_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::selectedElement", "load: check if object '::Qt::ObjectView::selectedElement' already exists."))) {
            QT::ObjectView_selectedElement_h = (::hyve::lang::member)::hyve::declare(QT::ObjectView_h, "selectedElement", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectView_selectedElement_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::selectedElement'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_selectedElement_h);
        }

        /* Define ::Qt::ObjectView::selectedElement */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_selectedElement_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_selectedElement_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::ObjectView_selectedElement_h->modifiers = 0x4;
            QT::ObjectView_selectedElement_h->state = 0x6;
            QT::ObjectView_selectedElement_h->weak = FALSE;
            QT::ObjectView_selectedElement_h->id = 5;
            if (::hyve::define(QT::ObjectView_selectedElement_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::selectedElement'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::showHeaders */
        if (!(QT::ObjectView_showHeaders_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::showHeaders", "load: check if object '::Qt::ObjectView::showHeaders' already exists."))) {
            QT::ObjectView_showHeaders_h = (::hyve::lang::member)::hyve::declare(QT::ObjectView_h, "showHeaders", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ObjectView_showHeaders_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::showHeaders'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_showHeaders_h);
        }

        /* Define ::Qt::ObjectView::showHeaders */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_showHeaders_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_showHeaders_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::ObjectView_showHeaders_h->modifiers = 0x0;
            QT::ObjectView_showHeaders_h->state = 0x6;
            QT::ObjectView_showHeaders_h->weak = FALSE;
            QT::ObjectView_showHeaders_h->id = 2;
            if (::hyve::define(QT::ObjectView_showHeaders_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::showHeaders'.");
                goto error;
            }
        }
        /* Declare ::Qt::Orientation */
        if (!(QT::Orientation_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::Orientation", "load: check if object '::Qt::Orientation' already exists."))) {
            QT::Orientation_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "Orientation", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::Orientation_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Orientation'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Orientation_h);
        }

        /* Declare ::Qt::Orientation::Horizontal */
        if (!(QT::Orientation_Horizontal_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Orientation::Horizontal", "load: check if object '::Qt::Orientation::Horizontal' already exists."))) {
            QT::Orientation_Horizontal_h = (::hyve::lang::constant*)::hyve::declare(QT::Orientation_h, "Horizontal", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Orientation_Horizontal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Orientation::Horizontal'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Orientation_Horizontal_h);
        }

        /* Define ::Qt::Orientation::Horizontal */
        if (!::hyve::checkState((::hyve::lang::object)QT::Orientation_Horizontal_h, ::hyve::lang::DEFINED)) {
            (*QT::Orientation_Horizontal_h) = 1;
            if (::hyve::define(QT::Orientation_Horizontal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Orientation::Horizontal'.");
                goto error;
            }
        }
        /* Declare ::Qt::Orientation::Vertical */
        if (!(QT::Orientation_Vertical_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::Orientation::Vertical", "load: check if object '::Qt::Orientation::Vertical' already exists."))) {
            QT::Orientation_Vertical_h = (::hyve::lang::constant*)::hyve::declare(QT::Orientation_h, "Vertical", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::Orientation_Vertical_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Orientation::Vertical'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Orientation_Vertical_h);
        }

        /* Define ::Qt::Orientation::Vertical */
        if (!::hyve::checkState((::hyve::lang::object)QT::Orientation_Vertical_h, ::hyve::lang::DEFINED)) {
            (*QT::Orientation_Vertical_h) = 2;
            if (::hyve::define(QT::Orientation_Vertical_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Orientation::Vertical'.");
                goto error;
            }
        }
        /* Define ::Qt::Orientation */
        if (!::hyve::checkState((::hyve::lang::object)QT::Orientation_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::Orientation_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Orientation'.");
                goto error;
            }
        }
        /* Declare ::Qt::PaintDevice */
        if (!(QT::PaintDevice_h = (::hyve::lang::interface)::hyve::resolve(NULL, NULL, "::Qt::PaintDevice", "load: check if object '::Qt::PaintDevice' already exists."))) {
            QT::PaintDevice_h = (::hyve::lang::interface)::hyve::declare(QT_h, "PaintDevice", ((::hyve::lang::_typedef)::hyve::lang::interface_h));
            if (!QT::PaintDevice_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PaintDevice'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PaintDevice_h);
        }

        /* Define ::Qt::PaintDevice */
        if (!::hyve::checkState((::hyve::lang::object)QT::PaintDevice_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::PaintDevice_h)->parentType = NULL;
            ((::hyve::lang::type)QT::PaintDevice_h)->parentState = 0x0;
            QT::PaintDevice_h->base = NULL;
            if (::hyve::define(QT::PaintDevice_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PaintDevice'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter */
        if (!(QT::Painter_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Painter", "load: check if object '::Qt::Painter' already exists."))) {
            QT::Painter_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Painter", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Painter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_h);
        }

        /* Declare ::Qt::Painter::begin() */
        if (!(QT::Painter_begin_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::begin()", "load: check if object '::Qt::Painter::begin()' already exists."))) {
            QT::Painter_begin_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "begin()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_begin_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::begin()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_begin_h);
        }

        /* Define ::Qt::Painter::begin() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_begin_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_begin_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_begin_h->_virtual = FALSE;
            
            /* Bind QT::Painter_begin_h with C++ function */
            ((::hyve::lang::function)QT::Painter_begin_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_begin_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_begin);
            if (::hyve::define(QT::Painter_begin_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::begin()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::brush */
        if (!(QT::Painter_brush_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Painter::brush", "load: check if object '::Qt::Painter::brush' already exists."))) {
            QT::Painter_brush_h = (::hyve::lang::member)::hyve::declare(QT::Painter_h, "brush", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Painter_brush_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::brush'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_brush_h);
        }

        /* Declare ::Qt::Painter::device */
        if (!(QT::Painter_device_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Painter::device", "load: check if object '::Qt::Painter::device' already exists."))) {
            QT::Painter_device_h = (::hyve::lang::member)::hyve::declare(QT::Painter_h, "device", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Painter_device_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::device'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_device_h);
        }

        /* Define ::Qt::Painter::device */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_device_h, ::hyve::lang::DEFINED)) {
            QT::Painter_device_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::PaintDevice"));
            QT::Painter_device_h->modifiers = 0x0;
            QT::Painter_device_h->state = 0x6;
            QT::Painter_device_h->weak = FALSE;
            QT::Painter_device_h->id = 0;
            if (::hyve::define(QT::Painter_device_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::device'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r) */
        if (!(QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)", "load: check if object '::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)' already exists."))) {
            QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h);
        }

        /* Define ::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64);
            if (::hyve::define(QT::Painter_drawEllipse_hyvelangfloat64_hyvelangfloat64_hyvelangfloat64_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height) */
        if (!(QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)", "load: check if object '::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)' already exists."))) {
            QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h);
        }

        /* Define ::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32);
            if (::hyve::define(QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r) */
        if (!(QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)", "load: check if object '::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)' already exists."))) {
            QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h);
        }

        /* Define ::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32);
            if (::hyve::define(QT::Painter_drawEllipse_hyvelangint32_hyvelangint32_hyvelangint32_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2) */
        if (!(QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)", "load: check if object '::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)' already exists."))) {
            QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h);
        }

        /* Define ::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32);
            if (::hyve::define(QT::Painter_drawLine_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawLine(::Qt::Line line) */
        if (!(QT::Painter_drawLine_QtLine_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawLine(::Qt::Line line)", "load: check if object '::Qt::Painter::drawLine(::Qt::Line line)' already exists."))) {
            QT::Painter_drawLine_QtLine_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawLine(::Qt::Line line)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawLine_QtLine_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawLine(::Qt::Line line)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawLine_QtLine_h);
        }

        /* Define ::Qt::Painter::drawLine(::Qt::Line line) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawLine_QtLine_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawLine_QtLine_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawLine_QtLine_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawLine_QtLine_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawLine_QtLine_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawLine_QtLine_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawLine_QtLine);
            if (::hyve::define(QT::Painter_drawLine_QtLine_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawLine(::Qt::Line line)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines) */
        if (!(QT::Painter_drawLines_hyvelangsequence_QtLine_0_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)", "load: check if object '::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)' already exists."))) {
            QT::Painter_drawLines_hyvelangsequence_QtLine_0_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawLines_hyvelangsequence_QtLine_0_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawLines_hyvelangsequence_QtLine_0_h);
        }

        /* Define ::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawLines_hyvelangsequence_QtLine_0_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawLines_hyvelangsequence_QtLine_0_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawLines_hyvelangsequence_QtLine_0_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawLines_hyvelangsequence_QtLine_0_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawLines_hyvelangsequence_QtLine_0_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawLines_hyvelangsequence_QtLine_0_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawLines_hyvelangsequence_QtLine_0);
            if (::hyve::define(QT::Painter_drawLines_hyvelangsequence_QtLine_0_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines) */
        if (!(QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)", "load: check if object '::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)' already exists."))) {
            QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h);
        }

        /* Define ::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawLines_hyvelangsequence_QtLineF_0);
            if (::hyve::define(QT::Painter_drawLines_hyvelangsequence_QtLineF_0_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height) */
        if (!(QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)", "load: check if object '::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)' already exists."))) {
            QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h);
        }

        /* Define ::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32);
            if (::hyve::define(QT::Painter_drawRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::end() */
        if (!(QT::Painter_end_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::end()", "load: check if object '::Qt::Painter::end()' already exists."))) {
            QT::Painter_end_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "end()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_end_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::end()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_end_h);
        }

        /* Define ::Qt::Painter::end() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_end_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_end_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_end_h->_virtual = FALSE;
            
            /* Bind QT::Painter_end_h with C++ function */
            ((::hyve::lang::function)QT::Painter_end_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_end_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_end);
            if (::hyve::define(QT::Painter_end_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::end()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::pen */
        if (!(QT::Painter_pen_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Painter::pen", "load: check if object '::Qt::Painter::pen' already exists."))) {
            QT::Painter_pen_h = (::hyve::lang::member)::hyve::declare(QT::Painter_h, "pen", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Painter_pen_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::pen'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_pen_h);
        }

        /* Declare ::Qt::Painter::restore() */
        if (!(QT::Painter_restore_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::restore()", "load: check if object '::Qt::Painter::restore()' already exists."))) {
            QT::Painter_restore_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "restore()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_restore_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::restore()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_restore_h);
        }

        /* Define ::Qt::Painter::restore() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_restore_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_restore_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_restore_h->_virtual = FALSE;
            
            /* Bind QT::Painter_restore_h with C++ function */
            ((::hyve::lang::function)QT::Painter_restore_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_restore_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_restore);
            if (::hyve::define(QT::Painter_restore_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::restore()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::save() */
        if (!(QT::Painter_save_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::save()", "load: check if object '::Qt::Painter::save()' already exists."))) {
            QT::Painter_save_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "save()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_save_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::save()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_save_h);
        }

        /* Define ::Qt::Painter::save() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_save_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_save_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_save_h->_virtual = FALSE;
            
            /* Bind QT::Painter_save_h with C++ function */
            ((::hyve::lang::function)QT::Painter_save_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_save_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_save);
            if (::hyve::define(QT::Painter_save_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::save()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y) */
        if (!(QT::Painter_translate_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y)", "load: check if object '::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y)' already exists."))) {
            QT::Painter_translate_hyvelangint32_hyvelangint32_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "translate(::hyve::lang::int32 x,::hyve::lang::int32 y)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_translate_hyvelangint32_hyvelangint32_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_translate_hyvelangint32_hyvelangint32_h);
        }

        /* Define ::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_translate_hyvelangint32_hyvelangint32_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_translate_hyvelangint32_hyvelangint32_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_translate_hyvelangint32_hyvelangint32_h->_virtual = FALSE;
            
            /* Bind QT::Painter_translate_hyvelangint32_hyvelangint32_h with C++ function */
            ((::hyve::lang::function)QT::Painter_translate_hyvelangint32_hyvelangint32_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_translate_hyvelangint32_hyvelangint32_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_translate_hyvelangint32_hyvelangint32);
            if (::hyve::define(QT::Painter_translate_hyvelangint32_hyvelangint32_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::viewport() */
        if (!(QT::Painter_viewport_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::viewport()", "load: check if object '::Qt::Painter::viewport()' already exists."))) {
            QT::Painter_viewport_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "viewport()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_viewport_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::viewport()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_viewport_h);
        }

        /* Declare ::Qt::paintEvent_t */
        if (!(QT::paintEvent_t_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::paintEvent_t", "load: check if object '::Qt::paintEvent_t' already exists."))) {
            QT::paintEvent_t_h = (::hyve::lang::_class)::hyve::declare(QT_h, "paintEvent_t", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::paintEvent_t_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::paintEvent_t'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::paintEvent_t_h);
        }

        /* Declare ::Qt::paintEvent_t::painter */
        if (!(QT::paintEvent_t_painter_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::paintEvent_t::painter", "load: check if object '::Qt::paintEvent_t::painter' already exists."))) {
            QT::paintEvent_t_painter_h = (::hyve::lang::member)::hyve::declare(QT::paintEvent_t_h, "painter", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::paintEvent_t_painter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::paintEvent_t::painter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::paintEvent_t_painter_h);
        }

        /* Declare ::Qt::Pen */
        if (!(QT::Pen_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Pen", "load: check if object '::Qt::Pen' already exists."))) {
            QT::Pen_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Pen", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Pen_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Pen'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Pen_h);
        }

        /* Declare ::Qt::Pen::color */
        if (!(QT::Pen_color_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Pen::color", "load: check if object '::Qt::Pen::color' already exists."))) {
            QT::Pen_color_h = (::hyve::lang::member)::hyve::declare(QT::Pen_h, "color", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Pen_color_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Pen::color'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Pen_color_h);
        }

        /* Define ::Qt::Pen::color */
        if (!::hyve::checkState((::hyve::lang::object)QT::Pen_color_h, ::hyve::lang::DEFINED)) {
            QT::Pen_color_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Color"));
            QT::Pen_color_h->modifiers = 0x0;
            QT::Pen_color_h->state = 0x6;
            QT::Pen_color_h->weak = FALSE;
            QT::Pen_color_h->id = 0;
            if (::hyve::define(QT::Pen_color_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Pen::color'.");
                goto error;
            }
        }
        /* Declare ::Qt::Pen::width */
        if (!(QT::Pen_width_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Pen::width", "load: check if object '::Qt::Pen::width' already exists."))) {
            QT::Pen_width_h = (::hyve::lang::member)::hyve::declare(QT::Pen_h, "width", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Pen_width_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Pen::width'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Pen_width_h);
        }

        /* Define ::Qt::Pen::width */
        if (!::hyve::checkState((::hyve::lang::object)QT::Pen_width_h, ::hyve::lang::DEFINED)) {
            QT::Pen_width_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Pen_width_h->modifiers = 0x0;
            QT::Pen_width_h->state = 0x6;
            QT::Pen_width_h->weak = FALSE;
            QT::Pen_width_h->id = 1;
            if (::hyve::define(QT::Pen_width_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Pen::width'.");
                goto error;
            }
        }
        /* Declare ::Qt::Point */
        if (!(QT::Point_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::Point", "load: check if object '::Qt::Point' already exists."))) {
            QT::Point_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "Point", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::Point_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Point'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Point_h);
        }

        /* Declare ::Qt::Point::x */
        if (!(QT::Point_x_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Point::x", "load: check if object '::Qt::Point::x' already exists."))) {
            QT::Point_x_h = (::hyve::lang::member)::hyve::declare(QT::Point_h, "x", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Point_x_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Point::x'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Point_x_h);
        }

        /* Define ::Qt::Point::x */
        if (!::hyve::checkState((::hyve::lang::object)QT::Point_x_h, ::hyve::lang::DEFINED)) {
            QT::Point_x_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Point_x_h->modifiers = 0x0;
            QT::Point_x_h->state = 0x6;
            QT::Point_x_h->weak = FALSE;
            QT::Point_x_h->id = 0;
            if (::hyve::define(QT::Point_x_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Point::x'.");
                goto error;
            }
        }
        /* Declare ::Qt::Point::y */
        if (!(QT::Point_y_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Point::y", "load: check if object '::Qt::Point::y' already exists."))) {
            QT::Point_y_h = (::hyve::lang::member)::hyve::declare(QT::Point_h, "y", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Point_y_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Point::y'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Point_y_h);
        }

        /* Define ::Qt::Point::y */
        if (!::hyve::checkState((::hyve::lang::object)QT::Point_y_h, ::hyve::lang::DEFINED)) {
            QT::Point_y_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Point_y_h->modifiers = 0x0;
            QT::Point_y_h->state = 0x6;
            QT::Point_y_h->weak = FALSE;
            QT::Point_y_h->id = 1;
            if (::hyve::define(QT::Point_y_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Point::y'.");
                goto error;
            }
        }
        /* Define ::Qt::Point */
        if (!::hyve::checkState((::hyve::lang::object)QT::Point_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Point_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Point_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Point_h)->base = NULL;
            QT::Point_h->baseAccess = 0x0;
            if (::hyve::define(QT::Point_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Point'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawPoint(::Qt::Point point) */
        if (!(QT::Painter_drawPoint_QtPoint_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawPoint(::Qt::Point point)", "load: check if object '::Qt::Painter::drawPoint(::Qt::Point point)' already exists."))) {
            QT::Painter_drawPoint_QtPoint_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawPoint(::Qt::Point point)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawPoint_QtPoint_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawPoint(::Qt::Point point)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawPoint_QtPoint_h);
        }

        /* Define ::Qt::Painter::drawPoint(::Qt::Point point) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawPoint_QtPoint_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawPoint_QtPoint_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawPoint_QtPoint_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawPoint_QtPoint_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawPoint_QtPoint_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawPoint_QtPoint_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawPoint_QtPoint);
            if (::hyve::define(QT::Painter_drawPoint_QtPoint_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawPoint(::Qt::Point point)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text) */
        if (!(QT::Painter_drawText_QtPoint_hyvelangstring_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text)", "load: check if object '::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text)' already exists."))) {
            QT::Painter_drawText_QtPoint_hyvelangstring_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawText(::Qt::Point position,::hyve::lang::string text)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawText_QtPoint_hyvelangstring_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawText_QtPoint_hyvelangstring_h);
        }

        /* Define ::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawText_QtPoint_hyvelangstring_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawText_QtPoint_hyvelangstring_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawText_QtPoint_hyvelangstring_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawText_QtPoint_hyvelangstring_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawText_QtPoint_hyvelangstring_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawText_QtPoint_hyvelangstring_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawText_QtPoint_hyvelangstring);
            if (::hyve::define(QT::Painter_drawText_QtPoint_hyvelangstring_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::translate(::Qt::Point p) */
        if (!(QT::Painter_translate_QtPoint_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::translate(::Qt::Point p)", "load: check if object '::Qt::Painter::translate(::Qt::Point p)' already exists."))) {
            QT::Painter_translate_QtPoint_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "translate(::Qt::Point p)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_translate_QtPoint_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::translate(::Qt::Point p)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_translate_QtPoint_h);
        }

        /* Define ::Qt::Painter::translate(::Qt::Point p) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_translate_QtPoint_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_translate_QtPoint_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_translate_QtPoint_h->_virtual = FALSE;
            
            /* Bind QT::Painter_translate_QtPoint_h with C++ function */
            ((::hyve::lang::function)QT::Painter_translate_QtPoint_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_translate_QtPoint_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_translate_QtPoint);
            if (::hyve::define(QT::Painter_translate_QtPoint_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::translate(::Qt::Point p)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines) */
        if (!(QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)", "load: check if object '::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)' already exists."))) {
            QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h);
        }

        /* Define ::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawPoints_hyvelangsequence_QtPoint_0);
            if (::hyve::define(QT::Painter_drawPoints_hyvelangsequence_QtPoint_0_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)'.");
                goto error;
            }
        }
        /* Declare ::Qt::PointF */
        if (!(QT::PointF_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::PointF", "load: check if object '::Qt::PointF' already exists."))) {
            QT::PointF_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "PointF", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::PointF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PointF'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PointF_h);
        }

        /* Declare ::Qt::PointF::x */
        if (!(QT::PointF_x_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::PointF::x", "load: check if object '::Qt::PointF::x' already exists."))) {
            QT::PointF_x_h = (::hyve::lang::member)::hyve::declare(QT::PointF_h, "x", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::PointF_x_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PointF::x'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PointF_x_h);
        }

        /* Declare ::Qt::PointF::y */
        if (!(QT::PointF_y_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::PointF::y", "load: check if object '::Qt::PointF::y' already exists."))) {
            QT::PointF_y_h = (::hyve::lang::member)::hyve::declare(QT::PointF_h, "y", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::PointF_y_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PointF::y'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PointF_y_h);
        }

        /* Declare ::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines) */
        if (!(QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)", "load: check if object '::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)' already exists."))) {
            QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h);
        }

        /* Define ::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawPoints_hyvelangsequence_QtPointF_0);
            if (::hyve::define(QT::Painter_drawPoints_hyvelangsequence_QtPointF_0_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar */
        if (!(QT::ProgressBar_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar", "load: check if object '::Qt::ProgressBar' already exists."))) {
            QT::ProgressBar_h = (::hyve::lang::_class)::hyve::declare(QT_h, "ProgressBar", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::ProgressBar_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_h);
        }

        /* Declare ::Qt::ProgressBar::format */
        if (!(QT::ProgressBar_format_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::format", "load: check if object '::Qt::ProgressBar::format' already exists."))) {
            QT::ProgressBar_format_h = (::hyve::lang::member)::hyve::declare(QT::ProgressBar_h, "format", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ProgressBar_format_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::format'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_format_h);
        }

        /* Define ::Qt::ProgressBar::format */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_format_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_format_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ProgressBar_format_h->modifiers = 0x0;
            QT::ProgressBar_format_h->state = 0x6;
            QT::ProgressBar_format_h->weak = FALSE;
            QT::ProgressBar_format_h->id = 5;
            if (::hyve::define(QT::ProgressBar_format_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::format'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::maximum */
        if (!(QT::ProgressBar_maximum_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::maximum", "load: check if object '::Qt::ProgressBar::maximum' already exists."))) {
            QT::ProgressBar_maximum_h = (::hyve::lang::member)::hyve::declare(QT::ProgressBar_h, "maximum", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ProgressBar_maximum_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::maximum'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_maximum_h);
        }

        /* Define ::Qt::ProgressBar::maximum */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_maximum_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_maximum_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::ProgressBar_maximum_h->modifiers = 0x0;
            QT::ProgressBar_maximum_h->state = 0x6;
            QT::ProgressBar_maximum_h->weak = FALSE;
            QT::ProgressBar_maximum_h->id = 1;
            if (::hyve::define(QT::ProgressBar_maximum_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::maximum'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::minimum */
        if (!(QT::ProgressBar_minimum_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::minimum", "load: check if object '::Qt::ProgressBar::minimum' already exists."))) {
            QT::ProgressBar_minimum_h = (::hyve::lang::member)::hyve::declare(QT::ProgressBar_h, "minimum", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ProgressBar_minimum_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::minimum'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_minimum_h);
        }

        /* Define ::Qt::ProgressBar::minimum */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_minimum_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_minimum_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::ProgressBar_minimum_h->modifiers = 0x0;
            QT::ProgressBar_minimum_h->state = 0x6;
            QT::ProgressBar_minimum_h->weak = FALSE;
            QT::ProgressBar_minimum_h->id = 0;
            if (::hyve::define(QT::ProgressBar_minimum_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::minimum'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::orientation */
        if (!(QT::ProgressBar_orientation_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::orientation", "load: check if object '::Qt::ProgressBar::orientation' already exists."))) {
            QT::ProgressBar_orientation_h = (::hyve::lang::member)::hyve::declare(QT::ProgressBar_h, "orientation", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ProgressBar_orientation_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::orientation'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_orientation_h);
        }

        /* Define ::Qt::ProgressBar::orientation */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_orientation_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_orientation_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Orientation"));
            QT::ProgressBar_orientation_h->modifiers = 0x0;
            QT::ProgressBar_orientation_h->state = 0x6;
            QT::ProgressBar_orientation_h->weak = FALSE;
            QT::ProgressBar_orientation_h->id = 3;
            if (::hyve::define(QT::ProgressBar_orientation_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::orientation'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::text */
        if (!(QT::ProgressBar_text_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::text", "load: check if object '::Qt::ProgressBar::text' already exists."))) {
            QT::ProgressBar_text_h = (::hyve::lang::member)::hyve::declare(QT::ProgressBar_h, "text", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ProgressBar_text_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::text'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_text_h);
        }

        /* Define ::Qt::ProgressBar::text */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_text_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_text_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::ProgressBar_text_h->modifiers = 0x0;
            QT::ProgressBar_text_h->state = 0x6;
            QT::ProgressBar_text_h->weak = FALSE;
            QT::ProgressBar_text_h->id = 4;
            if (::hyve::define(QT::ProgressBar_text_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::text'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::value */
        if (!(QT::ProgressBar_value_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::value", "load: check if object '::Qt::ProgressBar::value' already exists."))) {
            QT::ProgressBar_value_h = (::hyve::lang::member)::hyve::declare(QT::ProgressBar_h, "value", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::ProgressBar_value_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::value'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_value_h);
        }

        /* Define ::Qt::ProgressBar::value */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_value_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_value_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::ProgressBar_value_h->modifiers = 0x0;
            QT::ProgressBar_value_h->state = 0x6;
            QT::ProgressBar_value_h->weak = FALSE;
            QT::ProgressBar_value_h->id = 2;
            if (::hyve::define(QT::ProgressBar_value_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::value'.");
                goto error;
            }
        }
        /* Declare ::Qt::PushButton */
        if (!(QT::PushButton_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::PushButton", "load: check if object '::Qt::PushButton' already exists."))) {
            QT::PushButton_h = (::hyve::lang::_class)::hyve::declare(QT_h, "PushButton", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::PushButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PushButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PushButton_h);
        }

        /* Declare ::Qt::RadialGradient */
        if (!(QT::RadialGradient_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::RadialGradient", "load: check if object '::Qt::RadialGradient' already exists."))) {
            QT::RadialGradient_h = (::hyve::lang::_class)::hyve::declare(QT_h, "RadialGradient", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::RadialGradient_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadialGradient'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadialGradient_h);
        }

        /* Declare ::Qt::RadialGradient::center */
        if (!(QT::RadialGradient_center_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RadialGradient::center", "load: check if object '::Qt::RadialGradient::center' already exists."))) {
            QT::RadialGradient_center_h = (::hyve::lang::member)::hyve::declare(QT::RadialGradient_h, "center", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RadialGradient_center_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadialGradient::center'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadialGradient_center_h);
        }

        /* Declare ::Qt::RadialGradient::focalPoint */
        if (!(QT::RadialGradient_focalPoint_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RadialGradient::focalPoint", "load: check if object '::Qt::RadialGradient::focalPoint' already exists."))) {
            QT::RadialGradient_focalPoint_h = (::hyve::lang::member)::hyve::declare(QT::RadialGradient_h, "focalPoint", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RadialGradient_focalPoint_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadialGradient::focalPoint'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadialGradient_focalPoint_h);
        }

        /* Declare ::Qt::RadialGradient::radius */
        if (!(QT::RadialGradient_radius_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RadialGradient::radius", "load: check if object '::Qt::RadialGradient::radius' already exists."))) {
            QT::RadialGradient_radius_h = (::hyve::lang::member)::hyve::declare(QT::RadialGradient_h, "radius", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RadialGradient_radius_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadialGradient::radius'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadialGradient_radius_h);
        }

        /* Declare ::Qt::RadioButton */
        if (!(QT::RadioButton_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::RadioButton", "load: check if object '::Qt::RadioButton' already exists."))) {
            QT::RadioButton_h = (::hyve::lang::_class)::hyve::declare(QT_h, "RadioButton", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::RadioButton_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadioButton'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadioButton_h);
        }

        /* Declare ::Qt::real */
        if (!(QT::real_h = (::hyve::lang::_typedef)::hyve::resolve(NULL, NULL, "::Qt::real", "load: check if object '::Qt::real' already exists."))) {
            QT::real_h = (::hyve::lang::_typedef)::hyve::declare(QT_h, "real", ((::hyve::lang::_typedef)::hyve::lang::_typedef_h));
            if (!QT::real_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::real'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::real_h);
        }

        /* Define ::Qt::real */
        if (!::hyve::checkState((::hyve::lang::object)QT::real_h, ::hyve::lang::DEFINED)) {
            QT::real_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::float64"));
            if (::hyve::define(QT::real_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::real'.");
                goto error;
            }
        }
        /* Define ::Qt::ConicalGradient::angle */
        if (!::hyve::checkState((::hyve::lang::object)QT::ConicalGradient_angle_h, ::hyve::lang::DEFINED)) {
            QT::ConicalGradient_angle_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::ConicalGradient_angle_h->modifiers = 0x0;
            QT::ConicalGradient_angle_h->state = 0x6;
            QT::ConicalGradient_angle_h->weak = FALSE;
            QT::ConicalGradient_angle_h->id = 0;
            if (::hyve::define(QT::ConicalGradient_angle_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ConicalGradient::angle'.");
                goto error;
            }
        }
        /* Define ::Qt::GradientStop::pos */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientStop_pos_h, ::hyve::lang::DEFINED)) {
            QT::GradientStop_pos_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::GradientStop_pos_h->modifiers = 0x0;
            QT::GradientStop_pos_h->state = 0x6;
            QT::GradientStop_pos_h->weak = FALSE;
            QT::GradientStop_pos_h->id = 0;
            if (::hyve::define(QT::GradientStop_pos_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientStop::pos'.");
                goto error;
            }
        }
        /* Define ::Qt::GradientStop */
        if (!::hyve::checkState((::hyve::lang::object)QT::GradientStop_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::GradientStop_h)->parentType = NULL;
            ((::hyve::lang::type)QT::GradientStop_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::GradientStop_h)->base = NULL;
            QT::GradientStop_h->baseAccess = 0x0;
            if (::hyve::define(QT::GradientStop_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GradientStop'.");
                goto error;
            }
        }
        /* Define ::Qt::LineF::x1 */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineF_x1_h, ::hyve::lang::DEFINED)) {
            QT::LineF_x1_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::LineF_x1_h->modifiers = 0x0;
            QT::LineF_x1_h->state = 0x6;
            QT::LineF_x1_h->weak = FALSE;
            QT::LineF_x1_h->id = 0;
            if (::hyve::define(QT::LineF_x1_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineF::x1'.");
                goto error;
            }
        }
        /* Define ::Qt::LineF::x2 */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineF_x2_h, ::hyve::lang::DEFINED)) {
            QT::LineF_x2_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::LineF_x2_h->modifiers = 0x0;
            QT::LineF_x2_h->state = 0x6;
            QT::LineF_x2_h->weak = FALSE;
            QT::LineF_x2_h->id = 2;
            if (::hyve::define(QT::LineF_x2_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineF::x2'.");
                goto error;
            }
        }
        /* Define ::Qt::LineF::y1 */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineF_y1_h, ::hyve::lang::DEFINED)) {
            QT::LineF_y1_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::LineF_y1_h->modifiers = 0x0;
            QT::LineF_y1_h->state = 0x6;
            QT::LineF_y1_h->weak = FALSE;
            QT::LineF_y1_h->id = 1;
            if (::hyve::define(QT::LineF_y1_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineF::y1'.");
                goto error;
            }
        }
        /* Define ::Qt::LineF::y2 */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineF_y2_h, ::hyve::lang::DEFINED)) {
            QT::LineF_y2_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::LineF_y2_h->modifiers = 0x0;
            QT::LineF_y2_h->state = 0x6;
            QT::LineF_y2_h->weak = FALSE;
            QT::LineF_y2_h->id = 3;
            if (::hyve::define(QT::LineF_y2_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineF::y2'.");
                goto error;
            }
        }
        /* Define ::Qt::LineF */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::LineF_h)->parentType = NULL;
            ((::hyve::lang::type)QT::LineF_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::LineF_h)->base = NULL;
            QT::LineF_h->baseAccess = 0x0;
            if (::hyve::define(QT::LineF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineF'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawLine(::Qt::LineF line) */
        if (!(QT::Painter_drawLine_QtLineF_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawLine(::Qt::LineF line)", "load: check if object '::Qt::Painter::drawLine(::Qt::LineF line)' already exists."))) {
            QT::Painter_drawLine_QtLineF_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawLine(::Qt::LineF line)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawLine_QtLineF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawLine(::Qt::LineF line)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawLine_QtLineF_h);
        }

        /* Define ::Qt::Painter::drawLine(::Qt::LineF line) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawLine_QtLineF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawLine_QtLineF_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawLine_QtLineF_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawLine_QtLineF_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawLine_QtLineF_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawLine_QtLineF_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawLine_QtLineF);
            if (::hyve::define(QT::Painter_drawLine_QtLineF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawLine(::Qt::LineF line)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height) */
        if (!(QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)", "load: check if object '::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)' already exists."))) {
            QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawEllipse_Qtreal_Qtreal_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2) */
        if (!(QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)", "load: check if object '::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)' already exists."))) {
            QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawLine_Qtreal_Qtreal_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height) */
        if (!(QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)", "load: check if object '::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)' already exists."))) {
            QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawRect_Qtreal_Qtreal_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius) */
        if (!(QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)", "load: check if object '::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)' already exists."))) {
            QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius) */
        if (!(QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)", "load: check if object '::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)' already exists."))) {
            QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_hyvelangint32_hyvelangint32_hyvelangint32_hyvelangint32_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius) */
        if (!(QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)", "load: check if object '::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)' already exists."))) {
            QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius) */
        if (!(QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)", "load: check if object '::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)' already exists."))) {
            QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::scale(::Qt::real sx,::Qt::real sy) */
        if (!(QT::Painter_scale_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::scale(::Qt::real sx,::Qt::real sy)", "load: check if object '::Qt::Painter::scale(::Qt::real sx,::Qt::real sy)' already exists."))) {
            QT::Painter_scale_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "scale(::Qt::real sx,::Qt::real sy)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_scale_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::scale(::Qt::real sx,::Qt::real sy)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_scale_h);
        }

        /* Define ::Qt::Painter::scale(::Qt::real sx,::Qt::real sy) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_scale_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_scale_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_scale_h->_virtual = FALSE;
            
            /* Bind QT::Painter_scale_h with C++ function */
            ((::hyve::lang::function)QT::Painter_scale_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_scale_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_scale);
            if (::hyve::define(QT::Painter_scale_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::scale(::Qt::real sx,::Qt::real sy)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::translate(::Qt::real x,::Qt::real y) */
        if (!(QT::Painter_translate_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::translate(::Qt::real x,::Qt::real y)", "load: check if object '::Qt::Painter::translate(::Qt::real x,::Qt::real y)' already exists."))) {
            QT::Painter_translate_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "translate(::Qt::real x,::Qt::real y)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_translate_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::translate(::Qt::real x,::Qt::real y)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_translate_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::translate(::Qt::real x,::Qt::real y) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_translate_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_translate_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_translate_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_translate_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_translate_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_translate_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_translate_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_translate_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::translate(::Qt::real x,::Qt::real y)'.");
                goto error;
            }
        }
        /* Define ::Qt::PointF::x */
        if (!::hyve::checkState((::hyve::lang::object)QT::PointF_x_h, ::hyve::lang::DEFINED)) {
            QT::PointF_x_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::PointF_x_h->modifiers = 0x0;
            QT::PointF_x_h->state = 0x6;
            QT::PointF_x_h->weak = FALSE;
            QT::PointF_x_h->id = 0;
            if (::hyve::define(QT::PointF_x_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PointF::x'.");
                goto error;
            }
        }
        /* Define ::Qt::PointF::y */
        if (!::hyve::checkState((::hyve::lang::object)QT::PointF_y_h, ::hyve::lang::DEFINED)) {
            QT::PointF_y_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::PointF_y_h->modifiers = 0x0;
            QT::PointF_y_h->state = 0x6;
            QT::PointF_y_h->weak = FALSE;
            QT::PointF_y_h->id = 1;
            if (::hyve::define(QT::PointF_y_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PointF::y'.");
                goto error;
            }
        }
        /* Define ::Qt::PointF */
        if (!::hyve::checkState((::hyve::lang::object)QT::PointF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::PointF_h)->parentType = NULL;
            ((::hyve::lang::type)QT::PointF_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::PointF_h)->base = NULL;
            QT::PointF_h->baseAccess = 0x0;
            if (::hyve::define(QT::PointF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PointF'.");
                goto error;
            }
        }
        /* Define ::Qt::ConicalGradient::center */
        if (!::hyve::checkState((::hyve::lang::object)QT::ConicalGradient_center_h, ::hyve::lang::DEFINED)) {
            QT::ConicalGradient_center_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::PointF"));
            QT::ConicalGradient_center_h->modifiers = 0x0;
            QT::ConicalGradient_center_h->state = 0x6;
            QT::ConicalGradient_center_h->weak = FALSE;
            QT::ConicalGradient_center_h->id = 1;
            if (::hyve::define(QT::ConicalGradient_center_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ConicalGradient::center'.");
                goto error;
            }
        }
        /* Define ::Qt::LinearGradient::finalStop */
        if (!::hyve::checkState((::hyve::lang::object)QT::LinearGradient_finalStop_h, ::hyve::lang::DEFINED)) {
            QT::LinearGradient_finalStop_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::PointF"));
            QT::LinearGradient_finalStop_h->modifiers = 0x0;
            QT::LinearGradient_finalStop_h->state = 0x6;
            QT::LinearGradient_finalStop_h->weak = FALSE;
            QT::LinearGradient_finalStop_h->id = 1;
            if (::hyve::define(QT::LinearGradient_finalStop_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LinearGradient::finalStop'.");
                goto error;
            }
        }
        /* Define ::Qt::LinearGradient::start */
        if (!::hyve::checkState((::hyve::lang::object)QT::LinearGradient_start_h, ::hyve::lang::DEFINED)) {
            QT::LinearGradient_start_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::PointF"));
            QT::LinearGradient_start_h->modifiers = 0x0;
            QT::LinearGradient_start_h->state = 0x6;
            QT::LinearGradient_start_h->weak = FALSE;
            QT::LinearGradient_start_h->id = 0;
            if (::hyve::define(QT::LinearGradient_start_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LinearGradient::start'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawPoint(::Qt::PointF point) */
        if (!(QT::Painter_drawPoint_QtPointF_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawPoint(::Qt::PointF point)", "load: check if object '::Qt::Painter::drawPoint(::Qt::PointF point)' already exists."))) {
            QT::Painter_drawPoint_QtPointF_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawPoint(::Qt::PointF point)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawPoint_QtPointF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawPoint(::Qt::PointF point)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawPoint_QtPointF_h);
        }

        /* Define ::Qt::Painter::drawPoint(::Qt::PointF point) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawPoint_QtPointF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawPoint_QtPointF_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawPoint_QtPointF_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawPoint_QtPointF_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawPoint_QtPointF_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawPoint_QtPointF_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawPoint_QtPointF);
            if (::hyve::define(QT::Painter_drawPoint_QtPointF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawPoint(::Qt::PointF point)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text) */
        if (!(QT::Painter_drawText_QtPointF_hyvelangstring_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text)", "load: check if object '::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text)' already exists."))) {
            QT::Painter_drawText_QtPointF_hyvelangstring_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawText(::Qt::PointF position,::hyve::lang::string text)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawText_QtPointF_hyvelangstring_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawText_QtPointF_hyvelangstring_h);
        }

        /* Define ::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawText_QtPointF_hyvelangstring_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawText_QtPointF_hyvelangstring_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawText_QtPointF_hyvelangstring_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawText_QtPointF_hyvelangstring_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawText_QtPointF_hyvelangstring_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawText_QtPointF_hyvelangstring_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawText_QtPointF_hyvelangstring);
            if (::hyve::define(QT::Painter_drawText_QtPointF_hyvelangstring_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::translate(::Qt::PointF p) */
        if (!(QT::Painter_translate_QtPointF_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::translate(::Qt::PointF p)", "load: check if object '::Qt::Painter::translate(::Qt::PointF p)' already exists."))) {
            QT::Painter_translate_QtPointF_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "translate(::Qt::PointF p)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_translate_QtPointF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::translate(::Qt::PointF p)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_translate_QtPointF_h);
        }

        /* Define ::Qt::Painter::translate(::Qt::PointF p) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_translate_QtPointF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_translate_QtPointF_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_translate_QtPointF_h->_virtual = FALSE;
            
            /* Bind QT::Painter_translate_QtPointF_h with C++ function */
            ((::hyve::lang::function)QT::Painter_translate_QtPointF_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_translate_QtPointF_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_translate_QtPointF);
            if (::hyve::define(QT::Painter_translate_QtPointF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::translate(::Qt::PointF p)'.");
                goto error;
            }
        }
        /* Define ::Qt::RadialGradient::center */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadialGradient_center_h, ::hyve::lang::DEFINED)) {
            QT::RadialGradient_center_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::PointF"));
            QT::RadialGradient_center_h->modifiers = 0x0;
            QT::RadialGradient_center_h->state = 0x6;
            QT::RadialGradient_center_h->weak = FALSE;
            QT::RadialGradient_center_h->id = 0;
            if (::hyve::define(QT::RadialGradient_center_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadialGradient::center'.");
                goto error;
            }
        }
        /* Define ::Qt::RadialGradient::focalPoint */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadialGradient_focalPoint_h, ::hyve::lang::DEFINED)) {
            QT::RadialGradient_focalPoint_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::PointF"));
            QT::RadialGradient_focalPoint_h->modifiers = 0x0;
            QT::RadialGradient_focalPoint_h->state = 0x6;
            QT::RadialGradient_focalPoint_h->weak = FALSE;
            QT::RadialGradient_focalPoint_h->id = 1;
            if (::hyve::define(QT::RadialGradient_focalPoint_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadialGradient::focalPoint'.");
                goto error;
            }
        }
        /* Define ::Qt::RadialGradient::radius */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadialGradient_radius_h, ::hyve::lang::DEFINED)) {
            QT::RadialGradient_radius_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::RadialGradient_radius_h->modifiers = 0x0;
            QT::RadialGradient_radius_h->state = 0x6;
            QT::RadialGradient_radius_h->weak = FALSE;
            QT::RadialGradient_radius_h->id = 2;
            if (::hyve::define(QT::RadialGradient_radius_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadialGradient::radius'.");
                goto error;
            }
        }
        /* Declare ::Qt::Rect */
        if (!(QT::Rect_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::Rect", "load: check if object '::Qt::Rect' already exists."))) {
            QT::Rect_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "Rect", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::Rect_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Rect'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Rect_h);
        }

        /* Declare ::Qt::Rect::height */
        if (!(QT::Rect_height_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Rect::height", "load: check if object '::Qt::Rect::height' already exists."))) {
            QT::Rect_height_h = (::hyve::lang::member)::hyve::declare(QT::Rect_h, "height", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Rect_height_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Rect::height'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Rect_height_h);
        }

        /* Define ::Qt::Rect::height */
        if (!::hyve::checkState((::hyve::lang::object)QT::Rect_height_h, ::hyve::lang::DEFINED)) {
            QT::Rect_height_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Rect_height_h->modifiers = 0x0;
            QT::Rect_height_h->state = 0x6;
            QT::Rect_height_h->weak = FALSE;
            QT::Rect_height_h->id = 3;
            if (::hyve::define(QT::Rect_height_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Rect::height'.");
                goto error;
            }
        }
        /* Declare ::Qt::Rect::left */
        if (!(QT::Rect_left_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Rect::left", "load: check if object '::Qt::Rect::left' already exists."))) {
            QT::Rect_left_h = (::hyve::lang::member)::hyve::declare(QT::Rect_h, "left", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Rect_left_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Rect::left'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Rect_left_h);
        }

        /* Define ::Qt::Rect::left */
        if (!::hyve::checkState((::hyve::lang::object)QT::Rect_left_h, ::hyve::lang::DEFINED)) {
            QT::Rect_left_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Rect_left_h->modifiers = 0x0;
            QT::Rect_left_h->state = 0x6;
            QT::Rect_left_h->weak = FALSE;
            QT::Rect_left_h->id = 0;
            if (::hyve::define(QT::Rect_left_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Rect::left'.");
                goto error;
            }
        }
        /* Declare ::Qt::Rect::top */
        if (!(QT::Rect_top_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Rect::top", "load: check if object '::Qt::Rect::top' already exists."))) {
            QT::Rect_top_h = (::hyve::lang::member)::hyve::declare(QT::Rect_h, "top", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Rect_top_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Rect::top'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Rect_top_h);
        }

        /* Define ::Qt::Rect::top */
        if (!::hyve::checkState((::hyve::lang::object)QT::Rect_top_h, ::hyve::lang::DEFINED)) {
            QT::Rect_top_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Rect_top_h->modifiers = 0x0;
            QT::Rect_top_h->state = 0x6;
            QT::Rect_top_h->weak = FALSE;
            QT::Rect_top_h->id = 1;
            if (::hyve::define(QT::Rect_top_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Rect::top'.");
                goto error;
            }
        }
        /* Declare ::Qt::Rect::width */
        if (!(QT::Rect_width_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Rect::width", "load: check if object '::Qt::Rect::width' already exists."))) {
            QT::Rect_width_h = (::hyve::lang::member)::hyve::declare(QT::Rect_h, "width", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Rect_width_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Rect::width'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Rect_width_h);
        }

        /* Define ::Qt::Rect::width */
        if (!::hyve::checkState((::hyve::lang::object)QT::Rect_width_h, ::hyve::lang::DEFINED)) {
            QT::Rect_width_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::Rect_width_h->modifiers = 0x0;
            QT::Rect_width_h->state = 0x6;
            QT::Rect_width_h->weak = FALSE;
            QT::Rect_width_h->id = 2;
            if (::hyve::define(QT::Rect_width_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Rect::width'.");
                goto error;
            }
        }
        /* Define ::Qt::Rect */
        if (!::hyve::checkState((::hyve::lang::object)QT::Rect_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Rect_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Rect_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Rect_h)->base = NULL;
            QT::Rect_h->baseAccess = 0x0;
            if (::hyve::define(QT::Rect_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Rect'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawEllipse(::Qt::Rect rect) */
        if (!(QT::Painter_drawEllipse_QtRect_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawEllipse(::Qt::Rect rect)", "load: check if object '::Qt::Painter::drawEllipse(::Qt::Rect rect)' already exists."))) {
            QT::Painter_drawEllipse_QtRect_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawEllipse(::Qt::Rect rect)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawEllipse_QtRect_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawEllipse(::Qt::Rect rect)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawEllipse_QtRect_h);
        }

        /* Define ::Qt::Painter::drawEllipse(::Qt::Rect rect) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawEllipse_QtRect_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawEllipse_QtRect_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawEllipse_QtRect_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawEllipse_QtRect_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawEllipse_QtRect_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawEllipse_QtRect_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawEllipse_QtRect);
            if (::hyve::define(QT::Painter_drawEllipse_QtRect_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawEllipse(::Qt::Rect rect)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRect(::Qt::Rect rect) */
        if (!(QT::Painter_drawRect_QtRect_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRect(::Qt::Rect rect)", "load: check if object '::Qt::Painter::drawRect(::Qt::Rect rect)' already exists."))) {
            QT::Painter_drawRect_QtRect_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRect(::Qt::Rect rect)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRect_QtRect_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRect(::Qt::Rect rect)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRect_QtRect_h);
        }

        /* Define ::Qt::Painter::drawRect(::Qt::Rect rect) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRect_QtRect_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRect_QtRect_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRect_QtRect_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRect_QtRect_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRect_QtRect_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRect_QtRect_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRect_QtRect);
            if (::hyve::define(QT::Painter_drawRect_QtRect_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRect(::Qt::Rect rect)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius) */
        if (!(QT::Painter_drawRoundedRect_QtRect_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius)", "load: check if object '::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius)' already exists."))) {
            QT::Painter_drawRoundedRect_QtRect_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::Qt::Rect rect,::Qt::real radius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_QtRect_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_QtRect_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_QtRect_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRect_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_QtRect_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_QtRect_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRect_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRect_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_QtRect_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_QtRect_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius) */
        if (!(QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)", "load: check if object '::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)' already exists."))) {
            QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_QtRect_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_QtRect_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text) */
        if (!(QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)", "load: check if object '::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)' already exists."))) {
            QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h);
        }

        /* Define ::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawText_QtRect_QtAlignment_hyvelangstring);
            if (::hyve::define(QT::Painter_drawText_QtRect_QtAlignment_hyvelangstring_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)'.");
                goto error;
            }
        }
        /* Define ::Qt::Painter::viewport() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_viewport_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_viewport_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Rect"));
            QT::Painter_viewport_h->_virtual = FALSE;
            
            /* Bind QT::Painter_viewport_h with C++ function */
            ((::hyve::lang::function)QT::Painter_viewport_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_viewport_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_viewport);
            if (::hyve::define(QT::Painter_viewport_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::viewport()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects) */
        if (!(QT::Painter_drawRects_hyvelangsequence_QtRect_0_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)", "load: check if object '::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)' already exists."))) {
            QT::Painter_drawRects_hyvelangsequence_QtRect_0_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRects_hyvelangsequence_QtRect_0_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRects_hyvelangsequence_QtRect_0_h);
        }

        /* Define ::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRects_hyvelangsequence_QtRect_0_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRects_hyvelangsequence_QtRect_0_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRects_hyvelangsequence_QtRect_0_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRects_hyvelangsequence_QtRect_0_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRects_hyvelangsequence_QtRect_0_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRects_hyvelangsequence_QtRect_0_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRects_hyvelangsequence_QtRect_0);
            if (::hyve::define(QT::Painter_drawRects_hyvelangsequence_QtRect_0_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)'.");
                goto error;
            }
        }
        /* Declare ::Qt::RectF */
        if (!(QT::RectF_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::RectF", "load: check if object '::Qt::RectF' already exists."))) {
            QT::RectF_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "RectF", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::RectF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RectF'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RectF_h);
        }

        /* Declare ::Qt::RectF::height */
        if (!(QT::RectF_height_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RectF::height", "load: check if object '::Qt::RectF::height' already exists."))) {
            QT::RectF_height_h = (::hyve::lang::member)::hyve::declare(QT::RectF_h, "height", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RectF_height_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RectF::height'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RectF_height_h);
        }

        /* Define ::Qt::RectF::height */
        if (!::hyve::checkState((::hyve::lang::object)QT::RectF_height_h, ::hyve::lang::DEFINED)) {
            QT::RectF_height_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::RectF_height_h->modifiers = 0x0;
            QT::RectF_height_h->state = 0x6;
            QT::RectF_height_h->weak = FALSE;
            QT::RectF_height_h->id = 3;
            if (::hyve::define(QT::RectF_height_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RectF::height'.");
                goto error;
            }
        }
        /* Declare ::Qt::RectF::left */
        if (!(QT::RectF_left_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RectF::left", "load: check if object '::Qt::RectF::left' already exists."))) {
            QT::RectF_left_h = (::hyve::lang::member)::hyve::declare(QT::RectF_h, "left", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RectF_left_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RectF::left'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RectF_left_h);
        }

        /* Define ::Qt::RectF::left */
        if (!::hyve::checkState((::hyve::lang::object)QT::RectF_left_h, ::hyve::lang::DEFINED)) {
            QT::RectF_left_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::RectF_left_h->modifiers = 0x0;
            QT::RectF_left_h->state = 0x6;
            QT::RectF_left_h->weak = FALSE;
            QT::RectF_left_h->id = 0;
            if (::hyve::define(QT::RectF_left_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RectF::left'.");
                goto error;
            }
        }
        /* Declare ::Qt::RectF::top */
        if (!(QT::RectF_top_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RectF::top", "load: check if object '::Qt::RectF::top' already exists."))) {
            QT::RectF_top_h = (::hyve::lang::member)::hyve::declare(QT::RectF_h, "top", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RectF_top_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RectF::top'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RectF_top_h);
        }

        /* Define ::Qt::RectF::top */
        if (!::hyve::checkState((::hyve::lang::object)QT::RectF_top_h, ::hyve::lang::DEFINED)) {
            QT::RectF_top_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::RectF_top_h->modifiers = 0x0;
            QT::RectF_top_h->state = 0x6;
            QT::RectF_top_h->weak = FALSE;
            QT::RectF_top_h->id = 1;
            if (::hyve::define(QT::RectF_top_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RectF::top'.");
                goto error;
            }
        }
        /* Declare ::Qt::RectF::width */
        if (!(QT::RectF_width_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::RectF::width", "load: check if object '::Qt::RectF::width' already exists."))) {
            QT::RectF_width_h = (::hyve::lang::member)::hyve::declare(QT::RectF_h, "width", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::RectF_width_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RectF::width'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RectF_width_h);
        }

        /* Define ::Qt::RectF::width */
        if (!::hyve::checkState((::hyve::lang::object)QT::RectF_width_h, ::hyve::lang::DEFINED)) {
            QT::RectF_width_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::real"));
            QT::RectF_width_h->modifiers = 0x0;
            QT::RectF_width_h->state = 0x6;
            QT::RectF_width_h->weak = FALSE;
            QT::RectF_width_h->id = 2;
            if (::hyve::define(QT::RectF_width_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RectF::width'.");
                goto error;
            }
        }
        /* Define ::Qt::RectF */
        if (!::hyve::checkState((::hyve::lang::object)QT::RectF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::RectF_h)->parentType = NULL;
            ((::hyve::lang::type)QT::RectF_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::RectF_h)->base = NULL;
            QT::RectF_h->baseAccess = 0x0;
            if (::hyve::define(QT::RectF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RectF'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawEllipse(::Qt::RectF rect) */
        if (!(QT::Painter_drawEllipse_QtRectF_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawEllipse(::Qt::RectF rect)", "load: check if object '::Qt::Painter::drawEllipse(::Qt::RectF rect)' already exists."))) {
            QT::Painter_drawEllipse_QtRectF_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawEllipse(::Qt::RectF rect)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawEllipse_QtRectF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawEllipse(::Qt::RectF rect)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawEllipse_QtRectF_h);
        }

        /* Define ::Qt::Painter::drawEllipse(::Qt::RectF rect) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawEllipse_QtRectF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawEllipse_QtRectF_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawEllipse_QtRectF_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawEllipse_QtRectF_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawEllipse_QtRectF_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawEllipse_QtRectF_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawEllipse_QtRectF);
            if (::hyve::define(QT::Painter_drawEllipse_QtRectF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawEllipse(::Qt::RectF rect)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRect(::Qt::RectF rect) */
        if (!(QT::Painter_drawRect_QtRectF_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRect(::Qt::RectF rect)", "load: check if object '::Qt::Painter::drawRect(::Qt::RectF rect)' already exists."))) {
            QT::Painter_drawRect_QtRectF_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRect(::Qt::RectF rect)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRect_QtRectF_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRect(::Qt::RectF rect)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRect_QtRectF_h);
        }

        /* Define ::Qt::Painter::drawRect(::Qt::RectF rect) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRect_QtRectF_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRect_QtRectF_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRect_QtRectF_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRect_QtRectF_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRect_QtRectF_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRect_QtRectF_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRect_QtRectF);
            if (::hyve::define(QT::Painter_drawRect_QtRectF_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRect(::Qt::RectF rect)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius) */
        if (!(QT::Painter_drawRoundedRect_QtRectF_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius)", "load: check if object '::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius)' already exists."))) {
            QT::Painter_drawRoundedRect_QtRectF_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::Qt::RectF rect,::Qt::real radius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_QtRectF_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_QtRectF_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_QtRectF_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRectF_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_QtRectF_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_QtRectF_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRectF_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRectF_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_QtRectF_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_QtRectF_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius) */
        if (!(QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)", "load: check if object '::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)' already exists."))) {
            QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h);
        }

        /* Define ::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal);
            if (::hyve::define(QT::Painter_drawRoundedRect_QtRectF_Qtreal_Qtreal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text) */
        if (!(QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)", "load: check if object '::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)' already exists."))) {
            QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h);
        }

        /* Define ::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawText_QtRectF_QtAlignment_hyvelangstring);
            if (::hyve::define(QT::Painter_drawText_QtRectF_QtAlignment_hyvelangstring_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects) */
        if (!(QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)", "load: check if object '::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)' already exists."))) {
            QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h);
        }

        /* Define ::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h->_virtual = FALSE;
            
            /* Bind QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h with C++ function */
            ((::hyve::lang::function)QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_drawRects_hyvelangsequence_QtRectF_0);
            if (::hyve::define(QT::Painter_drawRects_hyvelangsequence_QtRectF_0_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider */
        if (!(QT::Slider_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Slider", "load: check if object '::Qt::Slider' already exists."))) {
            QT::Slider_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Slider", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Slider_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_h);
        }

        /* Declare ::Qt::Slider::maximum */
        if (!(QT::Slider_maximum_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Slider::maximum", "load: check if object '::Qt::Slider::maximum' already exists."))) {
            QT::Slider_maximum_h = (::hyve::lang::member)::hyve::declare(QT::Slider_h, "maximum", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Slider_maximum_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::maximum'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_maximum_h);
        }

        /* Define ::Qt::Slider::maximum */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_maximum_h, ::hyve::lang::DEFINED)) {
            QT::Slider_maximum_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Slider_maximum_h->modifiers = 0x0;
            QT::Slider_maximum_h->state = 0x6;
            QT::Slider_maximum_h->weak = FALSE;
            QT::Slider_maximum_h->id = 2;
            if (::hyve::define(QT::Slider_maximum_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::maximum'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::minimum */
        if (!(QT::Slider_minimum_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Slider::minimum", "load: check if object '::Qt::Slider::minimum' already exists."))) {
            QT::Slider_minimum_h = (::hyve::lang::member)::hyve::declare(QT::Slider_h, "minimum", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Slider_minimum_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::minimum'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_minimum_h);
        }

        /* Define ::Qt::Slider::minimum */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_minimum_h, ::hyve::lang::DEFINED)) {
            QT::Slider_minimum_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Slider_minimum_h->modifiers = 0x0;
            QT::Slider_minimum_h->state = 0x6;
            QT::Slider_minimum_h->weak = FALSE;
            QT::Slider_minimum_h->id = 1;
            if (::hyve::define(QT::Slider_minimum_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::minimum'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::orientation */
        if (!(QT::Slider_orientation_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Slider::orientation", "load: check if object '::Qt::Slider::orientation' already exists."))) {
            QT::Slider_orientation_h = (::hyve::lang::member)::hyve::declare(QT::Slider_h, "orientation", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Slider_orientation_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::orientation'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_orientation_h);
        }

        /* Define ::Qt::Slider::orientation */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_orientation_h, ::hyve::lang::DEFINED)) {
            QT::Slider_orientation_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Orientation"));
            QT::Slider_orientation_h->modifiers = 0x0;
            QT::Slider_orientation_h->state = 0x6;
            QT::Slider_orientation_h->weak = FALSE;
            QT::Slider_orientation_h->id = 4;
            if (::hyve::define(QT::Slider_orientation_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::orientation'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::singleStep */
        if (!(QT::Slider_singleStep_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Slider::singleStep", "load: check if object '::Qt::Slider::singleStep' already exists."))) {
            QT::Slider_singleStep_h = (::hyve::lang::member)::hyve::declare(QT::Slider_h, "singleStep", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Slider_singleStep_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::singleStep'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_singleStep_h);
        }

        /* Define ::Qt::Slider::singleStep */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_singleStep_h, ::hyve::lang::DEFINED)) {
            QT::Slider_singleStep_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Slider_singleStep_h->modifiers = 0x0;
            QT::Slider_singleStep_h->state = 0x6;
            QT::Slider_singleStep_h->weak = FALSE;
            QT::Slider_singleStep_h->id = 3;
            if (::hyve::define(QT::Slider_singleStep_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::singleStep'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::value */
        if (!(QT::Slider_value_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Slider::value", "load: check if object '::Qt::Slider::value' already exists."))) {
            QT::Slider_value_h = (::hyve::lang::member)::hyve::declare(QT::Slider_h, "value", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Slider_value_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::value'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_value_h);
        }

        /* Define ::Qt::Slider::value */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_value_h, ::hyve::lang::DEFINED)) {
            QT::Slider_value_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Slider_value_h->modifiers = 0x0;
            QT::Slider_value_h->state = 0x6;
            QT::Slider_value_h->weak = FALSE;
            QT::Slider_value_h->id = 0;
            if (::hyve::define(QT::Slider_value_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::value'.");
                goto error;
            }
        }
        /* Declare ::Qt::slot */
        if (!(QT::slot_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::slot", "load: check if object '::Qt::slot' already exists."))) {
            QT::slot_h = (::hyve::lang::_class)::hyve::declare(QT_h, "slot", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::slot_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::slot'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::slot_h);
        }

        /* Declare ::Qt::Splitter */
        if (!(QT::Splitter_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Splitter", "load: check if object '::Qt::Splitter' already exists."))) {
            QT::Splitter_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Splitter", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Splitter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_h);
        }

        /* Declare ::Qt::Splitter::orientation */
        if (!(QT::Splitter_orientation_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Splitter::orientation", "load: check if object '::Qt::Splitter::orientation' already exists."))) {
            QT::Splitter_orientation_h = (::hyve::lang::member)::hyve::declare(QT::Splitter_h, "orientation", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Splitter_orientation_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter::orientation'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_orientation_h);
        }

        /* Define ::Qt::Splitter::orientation */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_orientation_h, ::hyve::lang::DEFINED)) {
            QT::Splitter_orientation_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Orientation"));
            QT::Splitter_orientation_h->modifiers = 0x0;
            QT::Splitter_orientation_h->state = 0x6;
            QT::Splitter_orientation_h->weak = FALSE;
            QT::Splitter_orientation_h->id = 1;
            if (::hyve::define(QT::Splitter_orientation_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter::orientation'.");
                goto error;
            }
        }
        /* Declare ::Qt::Splitter::widgets */
        if (!(QT::Splitter_widgets_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Splitter::widgets", "load: check if object '::Qt::Splitter::widgets' already exists."))) {
            QT::Splitter_widgets_h = (::hyve::lang::member)::hyve::declare(QT::Splitter_h, "widgets", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Splitter_widgets_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter::widgets'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_widgets_h);
        }

        /* Declare ::Qt::SplitterItem */
        if (!(QT::SplitterItem_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::SplitterItem", "load: check if object '::Qt::SplitterItem' already exists."))) {
            QT::SplitterItem_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "SplitterItem", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::SplitterItem_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::SplitterItem'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::SplitterItem_h);
        }

        /* Declare ::Qt::SplitterItem::stretch */
        if (!(QT::SplitterItem_stretch_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::SplitterItem::stretch", "load: check if object '::Qt::SplitterItem::stretch' already exists."))) {
            QT::SplitterItem_stretch_h = (::hyve::lang::member)::hyve::declare(QT::SplitterItem_h, "stretch", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::SplitterItem_stretch_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::SplitterItem::stretch'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::SplitterItem_stretch_h);
        }

        /* Define ::Qt::SplitterItem::stretch */
        if (!::hyve::checkState((::hyve::lang::object)QT::SplitterItem_stretch_h, ::hyve::lang::DEFINED)) {
            QT::SplitterItem_stretch_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::SplitterItem_stretch_h->modifiers = 0x0;
            QT::SplitterItem_stretch_h->state = 0x6;
            QT::SplitterItem_stretch_h->weak = FALSE;
            QT::SplitterItem_stretch_h->id = 2;
            if (::hyve::define(QT::SplitterItem_stretch_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::SplitterItem::stretch'.");
                goto error;
            }
        }
        /* Declare ::Qt::SplitterItem::widget */
        if (!(QT::SplitterItem_widget_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::SplitterItem::widget", "load: check if object '::Qt::SplitterItem::widget' already exists."))) {
            QT::SplitterItem_widget_h = (::hyve::lang::member)::hyve::declare(QT::SplitterItem_h, "widget", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::SplitterItem_widget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::SplitterItem::widget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::SplitterItem_widget_h);
        }

        /* Declare ::Qt::SplitterItem::width */
        if (!(QT::SplitterItem_width_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::SplitterItem::width", "load: check if object '::Qt::SplitterItem::width' already exists."))) {
            QT::SplitterItem_width_h = (::hyve::lang::member)::hyve::declare(QT::SplitterItem_h, "width", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::SplitterItem_width_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::SplitterItem::width'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::SplitterItem_width_h);
        }

        /* Define ::Qt::SplitterItem::width */
        if (!::hyve::checkState((::hyve::lang::object)QT::SplitterItem_width_h, ::hyve::lang::DEFINED)) {
            QT::SplitterItem_width_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::SplitterItem_width_h->modifiers = 0x0;
            QT::SplitterItem_width_h->state = 0x6;
            QT::SplitterItem_width_h->weak = FALSE;
            QT::SplitterItem_width_h->id = 1;
            if (::hyve::define(QT::SplitterItem_width_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::SplitterItem::width'.");
                goto error;
            }
        }
        /* Define ::Qt::Splitter::widgets */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_widgets_h, ::hyve::lang::DEFINED)) {
            QT::Splitter_widgets_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::Qt::SplitterItem,0}"));
            QT::Splitter_widgets_h->modifiers = 0x0;
            QT::Splitter_widgets_h->state = 0x6;
            QT::Splitter_widgets_h->weak = FALSE;
            QT::Splitter_widgets_h->id = 0;
            if (::hyve::define(QT::Splitter_widgets_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter::widgets'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget */
        if (!(QT::TabWidget_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::TabWidget", "load: check if object '::Qt::TabWidget' already exists."))) {
            QT::TabWidget_h = (::hyve::lang::_class)::hyve::declare(QT_h, "TabWidget", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::TabWidget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_h);
        }

        /* Declare ::Qt::TabWidget::closable */
        if (!(QT::TabWidget_closable_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::closable", "load: check if object '::Qt::TabWidget::closable' already exists."))) {
            QT::TabWidget_closable_h = (::hyve::lang::member)::hyve::declare(QT::TabWidget_h, "closable", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidget_closable_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::closable'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_closable_h);
        }

        /* Define ::Qt::TabWidget::closable */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_closable_h, ::hyve::lang::DEFINED)) {
            QT::TabWidget_closable_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::TabWidget_closable_h->modifiers = 0x0;
            QT::TabWidget_closable_h->state = 0x6;
            QT::TabWidget_closable_h->weak = FALSE;
            QT::TabWidget_closable_h->id = 1;
            if (::hyve::define(QT::TabWidget_closable_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::closable'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::count */
        if (!(QT::TabWidget_count_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::count", "load: check if object '::Qt::TabWidget::count' already exists."))) {
            QT::TabWidget_count_h = (::hyve::lang::member)::hyve::declare(QT::TabWidget_h, "count", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidget_count_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::count'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_count_h);
        }

        /* Define ::Qt::TabWidget::count */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_count_h, ::hyve::lang::DEFINED)) {
            QT::TabWidget_count_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::TabWidget_count_h->modifiers = 0x0;
            QT::TabWidget_count_h->state = 0x6;
            QT::TabWidget_count_h->weak = FALSE;
            QT::TabWidget_count_h->id = 5;
            if (::hyve::define(QT::TabWidget_count_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::count'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::currentIndex */
        if (!(QT::TabWidget_currentIndex_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::currentIndex", "load: check if object '::Qt::TabWidget::currentIndex' already exists."))) {
            QT::TabWidget_currentIndex_h = (::hyve::lang::member)::hyve::declare(QT::TabWidget_h, "currentIndex", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidget_currentIndex_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::currentIndex'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_currentIndex_h);
        }

        /* Define ::Qt::TabWidget::currentIndex */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_currentIndex_h, ::hyve::lang::DEFINED)) {
            QT::TabWidget_currentIndex_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
            QT::TabWidget_currentIndex_h->modifiers = 0x0;
            QT::TabWidget_currentIndex_h->state = 0x6;
            QT::TabWidget_currentIndex_h->weak = FALSE;
            QT::TabWidget_currentIndex_h->id = 3;
            if (::hyve::define(QT::TabWidget_currentIndex_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::currentIndex'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::currentWidget */
        if (!(QT::TabWidget_currentWidget_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::currentWidget", "load: check if object '::Qt::TabWidget::currentWidget' already exists."))) {
            QT::TabWidget_currentWidget_h = (::hyve::lang::member)::hyve::declare(QT::TabWidget_h, "currentWidget", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidget_currentWidget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::currentWidget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_currentWidget_h);
        }

        /* Declare ::Qt::TabWidget::movable */
        if (!(QT::TabWidget_movable_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::movable", "load: check if object '::Qt::TabWidget::movable' already exists."))) {
            QT::TabWidget_movable_h = (::hyve::lang::member)::hyve::declare(QT::TabWidget_h, "movable", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidget_movable_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::movable'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_movable_h);
        }

        /* Define ::Qt::TabWidget::movable */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_movable_h, ::hyve::lang::DEFINED)) {
            QT::TabWidget_movable_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::TabWidget_movable_h->modifiers = 0x0;
            QT::TabWidget_movable_h->state = 0x6;
            QT::TabWidget_movable_h->weak = FALSE;
            QT::TabWidget_movable_h->id = 2;
            if (::hyve::define(QT::TabWidget_movable_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::movable'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::tabs */
        if (!(QT::TabWidget_tabs_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::tabs", "load: check if object '::Qt::TabWidget::tabs' already exists."))) {
            QT::TabWidget_tabs_h = (::hyve::lang::member)::hyve::declare(QT::TabWidget_h, "tabs", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidget_tabs_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::tabs'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_tabs_h);
        }

        /* Declare ::Qt::TabWidgetTab */
        if (!(QT::TabWidgetTab_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::Qt::TabWidgetTab", "load: check if object '::Qt::TabWidgetTab' already exists."))) {
            QT::TabWidgetTab_h = (::hyve::lang::_struct)::hyve::declare(QT_h, "TabWidgetTab", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
            if (!QT::TabWidgetTab_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidgetTab'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidgetTab_h);
        }

        /* Declare ::Qt::TabWidgetTab::label */
        if (!(QT::TabWidgetTab_label_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidgetTab::label", "load: check if object '::Qt::TabWidgetTab::label' already exists."))) {
            QT::TabWidgetTab_label_h = (::hyve::lang::member)::hyve::declare(QT::TabWidgetTab_h, "label", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidgetTab_label_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidgetTab::label'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidgetTab_label_h);
        }

        /* Define ::Qt::TabWidgetTab::label */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidgetTab_label_h, ::hyve::lang::DEFINED)) {
            QT::TabWidgetTab_label_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::TabWidgetTab_label_h->modifiers = 0x0;
            QT::TabWidgetTab_label_h->state = 0x6;
            QT::TabWidgetTab_label_h->weak = FALSE;
            QT::TabWidgetTab_label_h->id = 0;
            if (::hyve::define(QT::TabWidgetTab_label_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidgetTab::label'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidgetTab::widget */
        if (!(QT::TabWidgetTab_widget_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::TabWidgetTab::widget", "load: check if object '::Qt::TabWidgetTab::widget' already exists."))) {
            QT::TabWidgetTab_widget_h = (::hyve::lang::member)::hyve::declare(QT::TabWidgetTab_h, "widget", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::TabWidgetTab_widget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidgetTab::widget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidgetTab_widget_h);
        }

        /* Define ::Qt::TabWidget::tabs */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_tabs_h, ::hyve::lang::DEFINED)) {
            QT::TabWidget_tabs_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::list{::Qt::TabWidgetTab,0}"));
            QT::TabWidget_tabs_h->modifiers = 0x0;
            QT::TabWidget_tabs_h->state = 0x6;
            QT::TabWidget_tabs_h->weak = FALSE;
            QT::TabWidget_tabs_h->id = 0;
            if (::hyve::define(QT::TabWidget_tabs_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::tabs'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile */
        if (!(QT::Tile_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Tile", "load: check if object '::Qt::Tile' already exists."))) {
            QT::Tile_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Tile", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Tile_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_h);
        }

        /* Declare ::Qt::Tile::backgroundColor */
        if (!(QT::Tile_backgroundColor_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::backgroundColor", "load: check if object '::Qt::Tile::backgroundColor' already exists."))) {
            QT::Tile_backgroundColor_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "backgroundColor", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_backgroundColor_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::backgroundColor'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_backgroundColor_h);
        }

        /* Define ::Qt::Tile::backgroundColor */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_backgroundColor_h, ::hyve::lang::DEFINED)) {
            QT::Tile_backgroundColor_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Color"));
            QT::Tile_backgroundColor_h->modifiers = 0x0;
            QT::Tile_backgroundColor_h->state = 0x6;
            QT::Tile_backgroundColor_h->weak = FALSE;
            QT::Tile_backgroundColor_h->id = 3;
            if (::hyve::define(QT::Tile_backgroundColor_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::backgroundColor'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::foregroundColor */
        if (!(QT::Tile_foregroundColor_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::foregroundColor", "load: check if object '::Qt::Tile::foregroundColor' already exists."))) {
            QT::Tile_foregroundColor_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "foregroundColor", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_foregroundColor_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::foregroundColor'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_foregroundColor_h);
        }

        /* Define ::Qt::Tile::foregroundColor */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_foregroundColor_h, ::hyve::lang::DEFINED)) {
            QT::Tile_foregroundColor_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Color"));
            QT::Tile_foregroundColor_h->modifiers = 0x0;
            QT::Tile_foregroundColor_h->state = 0x6;
            QT::Tile_foregroundColor_h->weak = FALSE;
            QT::Tile_foregroundColor_h->id = 2;
            if (::hyve::define(QT::Tile_foregroundColor_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::foregroundColor'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::isRoot */
        if (!(QT::Tile_isRoot_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::isRoot", "load: check if object '::Qt::Tile::isRoot' already exists."))) {
            QT::Tile_isRoot_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "isRoot", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_isRoot_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::isRoot'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_isRoot_h);
        }

        /* Define ::Qt::Tile::isRoot */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_isRoot_h, ::hyve::lang::DEFINED)) {
            QT::Tile_isRoot_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::Tile_isRoot_h->modifiers = 0x2;
            QT::Tile_isRoot_h->state = 0x6;
            QT::Tile_isRoot_h->weak = FALSE;
            QT::Tile_isRoot_h->id = 5;
            if (::hyve::define(QT::Tile_isRoot_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::isRoot'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::mode */
        if (!(QT::Tile_mode_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::mode", "load: check if object '::Qt::Tile::mode' already exists."))) {
            QT::Tile_mode_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "mode", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_mode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::mode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_mode_h);
        }

        /* Declare ::Qt::Tile::rootTile */
        if (!(QT::Tile_rootTile_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::rootTile", "load: check if object '::Qt::Tile::rootTile' already exists."))) {
            QT::Tile_rootTile_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "rootTile", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_rootTile_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::rootTile'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_rootTile_h);
        }

        /* Declare ::Qt::Tile::scope */
        if (!(QT::Tile_scope_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::scope", "load: check if object '::Qt::Tile::scope' already exists."))) {
            QT::Tile_scope_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "scope", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_scope_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::scope'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_scope_h);
        }

        /* Define ::Qt::Tile::scope */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_scope_h, ::hyve::lang::DEFINED)) {
            QT::Tile_scope_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
            QT::Tile_scope_h->modifiers = 0x2;
            QT::Tile_scope_h->state = 0x6;
            QT::Tile_scope_h->weak = FALSE;
            QT::Tile_scope_h->id = 7;
            if (::hyve::define(QT::Tile_scope_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::scope'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::textColor */
        if (!(QT::Tile_textColor_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::textColor", "load: check if object '::Qt::Tile::textColor' already exists."))) {
            QT::Tile_textColor_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "textColor", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_textColor_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::textColor'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_textColor_h);
        }

        /* Define ::Qt::Tile::textColor */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_textColor_h, ::hyve::lang::DEFINED)) {
            QT::Tile_textColor_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Color"));
            QT::Tile_textColor_h->modifiers = 0x0;
            QT::Tile_textColor_h->state = 0x6;
            QT::Tile_textColor_h->weak = FALSE;
            QT::Tile_textColor_h->id = 1;
            if (::hyve::define(QT::Tile_textColor_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::textColor'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::title */
        if (!(QT::Tile_title_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Tile::title", "load: check if object '::Qt::Tile::title' already exists."))) {
            QT::Tile_title_h = (::hyve::lang::member)::hyve::declare(QT::Tile_h, "title", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Tile_title_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::title'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_title_h);
        }

        /* Define ::Qt::Tile::title */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_title_h, ::hyve::lang::DEFINED)) {
            QT::Tile_title_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::Tile_title_h->modifiers = 0x0;
            QT::Tile_title_h->state = 0x6;
            QT::Tile_title_h->weak = FALSE;
            QT::Tile_title_h->id = 0;
            if (::hyve::define(QT::Tile_title_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::title'.");
                goto error;
            }
        }
        /* Declare ::Qt::TileMode */
        if (!(QT::TileMode_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::Qt::TileMode", "load: check if object '::Qt::TileMode' already exists."))) {
            QT::TileMode_h = (::hyve::lang::_enum)::hyve::declare(QT_h, "TileMode", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
            if (!QT::TileMode_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TileMode'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TileMode_h);
        }

        /* Declare ::Qt::TileMode::TileLarge */
        if (!(QT::TileMode_TileLarge_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::TileMode::TileLarge", "load: check if object '::Qt::TileMode::TileLarge' already exists."))) {
            QT::TileMode_TileLarge_h = (::hyve::lang::constant*)::hyve::declare(QT::TileMode_h, "TileLarge", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::TileMode_TileLarge_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TileMode::TileLarge'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TileMode_TileLarge_h);
        }

        /* Define ::Qt::TileMode::TileLarge */
        if (!::hyve::checkState((::hyve::lang::object)QT::TileMode_TileLarge_h, ::hyve::lang::DEFINED)) {
            (*QT::TileMode_TileLarge_h) = 3;
            if (::hyve::define(QT::TileMode_TileLarge_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TileMode::TileLarge'.");
                goto error;
            }
        }
        /* Declare ::Qt::TileMode::TileNone */
        if (!(QT::TileMode_TileNone_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::TileMode::TileNone", "load: check if object '::Qt::TileMode::TileNone' already exists."))) {
            QT::TileMode_TileNone_h = (::hyve::lang::constant*)::hyve::declare(QT::TileMode_h, "TileNone", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::TileMode_TileNone_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TileMode::TileNone'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TileMode_TileNone_h);
        }

        /* Define ::Qt::TileMode::TileNone */
        if (!::hyve::checkState((::hyve::lang::object)QT::TileMode_TileNone_h, ::hyve::lang::DEFINED)) {
            (*QT::TileMode_TileNone_h) = 0;
            if (::hyve::define(QT::TileMode_TileNone_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TileMode::TileNone'.");
                goto error;
            }
        }
        /* Declare ::Qt::TileMode::TileNormal */
        if (!(QT::TileMode_TileNormal_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::TileMode::TileNormal", "load: check if object '::Qt::TileMode::TileNormal' already exists."))) {
            QT::TileMode_TileNormal_h = (::hyve::lang::constant*)::hyve::declare(QT::TileMode_h, "TileNormal", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::TileMode_TileNormal_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TileMode::TileNormal'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TileMode_TileNormal_h);
        }

        /* Define ::Qt::TileMode::TileNormal */
        if (!::hyve::checkState((::hyve::lang::object)QT::TileMode_TileNormal_h, ::hyve::lang::DEFINED)) {
            (*QT::TileMode_TileNormal_h) = 2;
            if (::hyve::define(QT::TileMode_TileNormal_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TileMode::TileNormal'.");
                goto error;
            }
        }
        /* Declare ::Qt::TileMode::TileSmall */
        if (!(QT::TileMode_TileSmall_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::Qt::TileMode::TileSmall", "load: check if object '::Qt::TileMode::TileSmall' already exists."))) {
            QT::TileMode_TileSmall_h = (::hyve::lang::constant*)::hyve::declare(QT::TileMode_h, "TileSmall", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
            if (!QT::TileMode_TileSmall_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TileMode::TileSmall'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TileMode_TileSmall_h);
        }

        /* Define ::Qt::TileMode::TileSmall */
        if (!::hyve::checkState((::hyve::lang::object)QT::TileMode_TileSmall_h, ::hyve::lang::DEFINED)) {
            (*QT::TileMode_TileSmall_h) = 1;
            if (::hyve::define(QT::TileMode_TileSmall_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TileMode::TileSmall'.");
                goto error;
            }
        }
        /* Define ::Qt::TileMode */
        if (!::hyve::checkState((::hyve::lang::object)QT::TileMode_h, ::hyve::lang::DEFINED)) {
            if (::hyve::define(QT::TileMode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TileMode'.");
                goto error;
            }
        }
        /* Define ::Qt::Tile::mode */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_mode_h, ::hyve::lang::DEFINED)) {
            QT::Tile_mode_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::TileMode"));
            QT::Tile_mode_h->modifiers = 0x4;
            QT::Tile_mode_h->state = 0x6;
            QT::Tile_mode_h->weak = FALSE;
            QT::Tile_mode_h->id = 4;
            if (::hyve::define(QT::Tile_mode_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::mode'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget */
        if (!(QT::Widget_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::Qt::Widget", "load: check if object '::Qt::Widget' already exists."))) {
            QT::Widget_h = (::hyve::lang::_class)::hyve::declare(QT_h, "Widget", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
            if (!QT::Widget_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_h);
        }

        /* Declare ::Qt::Widget::enabled */
        if (!(QT::Widget_enabled_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::enabled", "load: check if object '::Qt::Widget::enabled' already exists."))) {
            QT::Widget_enabled_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "enabled", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_enabled_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::enabled'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_enabled_h);
        }

        /* Define ::Qt::Widget::enabled */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_enabled_h, ::hyve::lang::DEFINED)) {
            QT::Widget_enabled_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::Widget_enabled_h->modifiers = 0x0;
            QT::Widget_enabled_h->state = 0x6;
            QT::Widget_enabled_h->weak = FALSE;
            QT::Widget_enabled_h->id = 6;
            if (::hyve::define(QT::Widget_enabled_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::enabled'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::height */
        if (!(QT::Widget_height_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::height", "load: check if object '::Qt::Widget::height' already exists."))) {
            QT::Widget_height_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "height", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_height_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::height'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_height_h);
        }

        /* Define ::Qt::Widget::height */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_height_h, ::hyve::lang::DEFINED)) {
            QT::Widget_height_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Widget_height_h->modifiers = 0x0;
            QT::Widget_height_h->state = 0x6;
            QT::Widget_height_h->weak = FALSE;
            QT::Widget_height_h->id = 5;
            if (::hyve::define(QT::Widget_height_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::height'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::hide() */
        if (!(QT::Widget_hide_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Widget::hide()", "load: check if object '::Qt::Widget::hide()' already exists."))) {
            QT::Widget_hide_h = (::hyve::lang::method)::hyve::declare(QT::Widget_h, "hide()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Widget_hide_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::hide()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_hide_h);
        }

        /* Define ::Qt::Widget::hide() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_hide_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Widget_hide_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Widget_hide_h->_virtual = FALSE;
            
            /* Bind QT::Widget_hide_h with C++ function */
            ((::hyve::lang::function)QT::Widget_hide_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Widget_hide_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Widget_hide);
            if (::hyve::define(QT::Widget_hide_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::hide()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::painter */
        if (!(QT::Widget_painter_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::painter", "load: check if object '::Qt::Widget::painter' already exists."))) {
            QT::Widget_painter_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "painter", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_painter_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::painter'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_painter_h);
        }

        /* Declare ::Qt::Widget::qslots */
        if (!(QT::Widget_qslots_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::qslots", "load: check if object '::Qt::Widget::qslots' already exists."))) {
            QT::Widget_qslots_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "qslots", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_qslots_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::qslots'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_qslots_h);
        }

        /* Define ::Qt::Widget::qslots */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_qslots_h, ::hyve::lang::DEFINED)) {
            QT::Widget_qslots_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
            QT::Widget_qslots_h->modifiers = 0x3;
            QT::Widget_qslots_h->state = 0x6;
            QT::Widget_qslots_h->weak = FALSE;
            QT::Widget_qslots_h->id = 10;
            if (::hyve::define(QT::Widget_qslots_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::qslots'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::repaint() */
        if (!(QT::Widget_repaint_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Widget::repaint()", "load: check if object '::Qt::Widget::repaint()' already exists."))) {
            QT::Widget_repaint_h = (::hyve::lang::method)::hyve::declare(QT::Widget_h, "repaint()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Widget_repaint_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::repaint()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_repaint_h);
        }

        /* Define ::Qt::Widget::repaint() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_repaint_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Widget_repaint_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Widget_repaint_h->_virtual = FALSE;
            
            /* Bind QT::Widget_repaint_h with C++ function */
            ((::hyve::lang::function)QT::Widget_repaint_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Widget_repaint_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Widget_repaint);
            if (::hyve::define(QT::Widget_repaint_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::repaint()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::show() */
        if (!(QT::Widget_show_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Widget::show()", "load: check if object '::Qt::Widget::show()' already exists."))) {
            QT::Widget_show_h = (::hyve::lang::method)::hyve::declare(QT::Widget_h, "show()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Widget_show_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::show()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_show_h);
        }

        /* Define ::Qt::Widget::show() */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_show_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Widget_show_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Widget_show_h->_virtual = FALSE;
            
            /* Bind QT::Widget_show_h with C++ function */
            ((::hyve::lang::function)QT::Widget_show_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Widget_show_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Widget_show);
            if (::hyve::define(QT::Widget_show_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::show()'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::styleSheet */
        if (!(QT::Widget_styleSheet_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::styleSheet", "load: check if object '::Qt::Widget::styleSheet' already exists."))) {
            QT::Widget_styleSheet_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "styleSheet", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_styleSheet_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::styleSheet'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_styleSheet_h);
        }

        /* Define ::Qt::Widget::styleSheet */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_styleSheet_h, ::hyve::lang::DEFINED)) {
            QT::Widget_styleSheet_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
            QT::Widget_styleSheet_h->modifiers = 0x0;
            QT::Widget_styleSheet_h->state = 0x6;
            QT::Widget_styleSheet_h->weak = FALSE;
            QT::Widget_styleSheet_h->id = 8;
            if (::hyve::define(QT::Widget_styleSheet_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::styleSheet'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::visible */
        if (!(QT::Widget_visible_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::visible", "load: check if object '::Qt::Widget::visible' already exists."))) {
            QT::Widget_visible_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "visible", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_visible_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::visible'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_visible_h);
        }

        /* Define ::Qt::Widget::visible */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_visible_h, ::hyve::lang::DEFINED)) {
            QT::Widget_visible_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
            QT::Widget_visible_h->modifiers = 0x0;
            QT::Widget_visible_h->state = 0x6;
            QT::Widget_visible_h->weak = FALSE;
            QT::Widget_visible_h->id = 7;
            if (::hyve::define(QT::Widget_visible_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::visible'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::width */
        if (!(QT::Widget_width_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::width", "load: check if object '::Qt::Widget::width' already exists."))) {
            QT::Widget_width_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "width", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_width_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::width'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_width_h);
        }

        /* Define ::Qt::Widget::width */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_width_h, ::hyve::lang::DEFINED)) {
            QT::Widget_width_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Widget_width_h->modifiers = 0x0;
            QT::Widget_width_h->state = 0x6;
            QT::Widget_width_h->weak = FALSE;
            QT::Widget_width_h->id = 4;
            if (::hyve::define(QT::Widget_width_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::width'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::x */
        if (!(QT::Widget_x_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::x", "load: check if object '::Qt::Widget::x' already exists."))) {
            QT::Widget_x_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "x", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_x_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::x'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_x_h);
        }

        /* Define ::Qt::Widget::x */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_x_h, ::hyve::lang::DEFINED)) {
            QT::Widget_x_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Widget_x_h->modifiers = 0x0;
            QT::Widget_x_h->state = 0x6;
            QT::Widget_x_h->weak = FALSE;
            QT::Widget_x_h->id = 2;
            if (::hyve::define(QT::Widget_x_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::x'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::y */
        if (!(QT::Widget_y_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::Qt::Widget::y", "load: check if object '::Qt::Widget::y' already exists."))) {
            QT::Widget_y_h = (::hyve::lang::member)::hyve::declare(QT::Widget_h, "y", ((::hyve::lang::_typedef)::hyve::lang::member_h));
            if (!QT::Widget_y_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::y'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_y_h);
        }

        /* Define ::Qt::Widget::y */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_y_h, ::hyve::lang::DEFINED)) {
            QT::Widget_y_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int32"));
            QT::Widget_y_h->modifiers = 0x0;
            QT::Widget_y_h->state = 0x6;
            QT::Widget_y_h->weak = FALSE;
            QT::Widget_y_h->id = 3;
            if (::hyve::define(QT::Widget_y_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::y'.");
                goto error;
            }
        }
        /* Define ::Qt::Application::arg */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_arg_h, ::hyve::lang::DEFINED)) {
            QT::Application_arg_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::hyve::lang::string,0}"));
            QT::Application_arg_h->modifiers = 0x0;
            QT::Application_arg_h->state = 0x6;
            QT::Application_arg_h->weak = FALSE;
            QT::Application_arg_h->id = 0;
            if (::hyve::define(QT::Application_arg_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::arg'.");
                goto error;
            }
        }
        /* Define ::Qt::ComboBox::items */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_items_h, ::hyve::lang::DEFINED)) {
            QT::ComboBox_items_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::list{::hyve::lang::string,0}"));
            QT::ComboBox_items_h->modifiers = 0x0;
            QT::ComboBox_items_h->state = 0x6;
            QT::ComboBox_items_h->weak = FALSE;
            QT::ComboBox_items_h->id = 0;
            if (::hyve::define(QT::ComboBox_items_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox::items'.");
                goto error;
            }
        }
        /* Define ::Qt::ListWidget::items */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_items_h, ::hyve::lang::DEFINED)) {
            QT::ListWidget_items_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::list{::hyve::lang::string,0}"));
            QT::ListWidget_items_h->modifiers = 0x0;
            QT::ListWidget_items_h->state = 0x6;
            QT::ListWidget_items_h->weak = FALSE;
            QT::ListWidget_items_h->id = 0;
            if (::hyve::define(QT::ListWidget_items_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::items'.");
                goto error;
            }
        }
        /* Define ::Qt::ObjectView::fields */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_fields_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_fields_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::sequence{::hyve::lang::string,0}"));
            QT::ObjectView_fields_h->modifiers = 0x0;
            QT::ObjectView_fields_h->state = 0x6;
            QT::ObjectView_fields_h->weak = FALSE;
            QT::ObjectView_fields_h->id = 3;
            if (::hyve::define(QT::ObjectView_fields_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::fields'.");
                goto error;
            }
        }
        /* Define ::Qt::Tile::rootTile */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_rootTile_h, ::hyve::lang::DEFINED)) {
            QT::Tile_rootTile_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Tile"));
            QT::Tile_rootTile_h->modifiers = 0x2;
            QT::Tile_rootTile_h->state = 0x6;
            QT::Tile_rootTile_h->weak = FALSE;
            QT::Tile_rootTile_h->id = 6;
            if (::hyve::define(QT::Tile_rootTile_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::rootTile'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::construct(::Qt::Widget object) */
        if (!(QT::Widget_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Widget::construct(::Qt::Widget object)", "load: check if object '::Qt::Widget::construct(::Qt::Widget object)' already exists."))) {
            QT::Widget_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Widget_h, "construct(::Qt::Widget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Widget_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::construct(::Qt::Widget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_construct_h);
        }

        /* Define ::Qt::Widget::construct(::Qt::Widget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Widget_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Widget_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Widget_construct_h with C++ function */
            ((::hyve::lang::function)QT::Widget_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Widget_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Widget_construct);
            if (::hyve::define(QT::Widget_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::construct(::Qt::Widget object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::destruct(::Qt::Widget object) */
        if (!(QT::Widget_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Widget::destruct(::Qt::Widget object)", "load: check if object '::Qt::Widget::destruct(::Qt::Widget object)' already exists."))) {
            QT::Widget_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Widget_h, "destruct(::Qt::Widget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Widget_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::destruct(::Qt::Widget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_destruct_h);
        }

        /* Define ::Qt::Widget::destruct(::Qt::Widget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Widget_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Widget_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Widget_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Widget_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Widget_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Widget_destruct);
            if (::hyve::define(QT::Widget_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::destruct(::Qt::Widget object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::init(::Qt::Widget object) */
        if (!(QT::Widget_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Widget::init(::Qt::Widget object)", "load: check if object '::Qt::Widget::init(::Qt::Widget object)' already exists."))) {
            QT::Widget_init_h = (::hyve::lang::callback)::hyve::declare(QT::Widget_h, "init(::Qt::Widget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Widget_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::init(::Qt::Widget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_init_h);
        }

        /* Define ::Qt::Widget::init(::Qt::Widget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Widget_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Widget_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::Widget_init_h with C++ function */
            ((::hyve::lang::function)QT::Widget_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Widget_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Widget_init);
            if (::hyve::define(QT::Widget_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::init(::Qt::Widget object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::slot::construct(::Qt::slot object) */
        if (!(QT::slot_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::slot::construct(::Qt::slot object)", "load: check if object '::Qt::slot::construct(::Qt::slot object)' already exists."))) {
            QT::slot_construct_h = (::hyve::lang::callback)::hyve::declare(QT::slot_h, "construct(::Qt::slot object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::slot_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::slot::construct(::Qt::slot object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::slot_construct_h);
        }

        /* Define ::Qt::slot::construct(::Qt::slot object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::slot_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::slot_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::slot_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::slot_construct_h with C++ function */
            ((::hyve::lang::function)QT::slot_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::slot_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_slot_construct);
            if (::hyve::define(QT::slot_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::slot::construct(::Qt::slot object)'.");
                goto error;
            }
        }
        /* Define ::Qt::slot */
        if (!::hyve::checkState((::hyve::lang::object)QT::slot_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::slot_h)->parentType = NULL;
            ((::hyve::lang::type)QT::slot_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::slot_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::member"));
            ((::hyve::lang::_struct)QT::slot_h)->baseAccess = 0x0;
            QT::slot_h->implements.length = 0;
            QT::slot_h->implements.buffer = NULL;
            if (::hyve::define(QT::slot_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::slot'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::mousePressEvent */
        if (!(QT::Widget_mousePressEvent_h = (QT::slot)::hyve::resolve(NULL, NULL, "::Qt::Widget::mousePressEvent", "load: check if object '::Qt::Widget::mousePressEvent' already exists."))) {
            QT::Widget_mousePressEvent_h = (QT::slot)::hyve::declare(QT::Widget_h, "mousePressEvent", ((::hyve::lang::_typedef)QT::slot_h));
            if (!QT::Widget_mousePressEvent_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::mousePressEvent'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_mousePressEvent_h);
        }

        /* Define ::Qt::Widget::mousePressEvent */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_mousePressEvent_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::member)QT::Widget_mousePressEvent_h)->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::mouseEvent_t"));
            ((::hyve::lang::member)QT::Widget_mousePressEvent_h)->modifiers = 0x4;
            ((::hyve::lang::member)QT::Widget_mousePressEvent_h)->state = 0x6;
            ((::hyve::lang::member)QT::Widget_mousePressEvent_h)->weak = FALSE;
            ((::hyve::lang::member)QT::Widget_mousePressEvent_h)->id = 1;
            if (::hyve::define(QT::Widget_mousePressEvent_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::mousePressEvent'.");
                goto error;
            }
        }
        /* Declare ::Qt::Widget::paintEvent */
        if (!(QT::Widget_paintEvent_h = (QT::slot)::hyve::resolve(NULL, NULL, "::Qt::Widget::paintEvent", "load: check if object '::Qt::Widget::paintEvent' already exists."))) {
            QT::Widget_paintEvent_h = (QT::slot)::hyve::declare(QT::Widget_h, "paintEvent", ((::hyve::lang::_typedef)QT::slot_h));
            if (!QT::Widget_paintEvent_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Widget::paintEvent'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Widget_paintEvent_h);
        }

        /* Declare ::Qt::RadialGradient::init(::Qt::RadialGradient object) */
        if (!(QT::RadialGradient_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::RadialGradient::init(::Qt::RadialGradient object)", "load: check if object '::Qt::RadialGradient::init(::Qt::RadialGradient object)' already exists."))) {
            QT::RadialGradient_init_h = (::hyve::lang::callback)::hyve::declare(QT::RadialGradient_h, "init(::Qt::RadialGradient object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::RadialGradient_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadialGradient::init(::Qt::RadialGradient object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadialGradient_init_h);
        }

        /* Define ::Qt::RadialGradient::init(::Qt::RadialGradient object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadialGradient_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::RadialGradient_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::RadialGradient_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::RadialGradient_init_h with C++ function */
            ((::hyve::lang::function)QT::RadialGradient_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::RadialGradient_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_RadialGradient_init);
            if (::hyve::define(QT::RadialGradient_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadialGradient::init(::Qt::RadialGradient object)'.");
                goto error;
            }
        }
        /* Define ::Qt::RadialGradient */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadialGradient_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::RadialGradient_h)->parentType = NULL;
            ((::hyve::lang::type)QT::RadialGradient_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::RadialGradient_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Gradient"));
            ((::hyve::lang::_struct)QT::RadialGradient_h)->baseAccess = 0x0;
            QT::RadialGradient_h->implements.length = 0;
            QT::RadialGradient_h->implements.buffer = NULL;
            if (::hyve::define(QT::RadialGradient_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadialGradient'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::construct(::Qt::Painter object) */
        if (!(QT::Painter_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Painter::construct(::Qt::Painter object)", "load: check if object '::Qt::Painter::construct(::Qt::Painter object)' already exists."))) {
            QT::Painter_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Painter_h, "construct(::Qt::Painter object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Painter_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::construct(::Qt::Painter object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_construct_h);
        }

        /* Define ::Qt::Painter::construct(::Qt::Painter object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Painter_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Painter_construct_h with C++ function */
            ((::hyve::lang::function)QT::Painter_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_construct);
            if (::hyve::define(QT::Painter_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::construct(::Qt::Painter object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::destruct(::Qt::Painter object) */
        if (!(QT::Painter_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Painter::destruct(::Qt::Painter object)", "load: check if object '::Qt::Painter::destruct(::Qt::Painter object)' already exists."))) {
            QT::Painter_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Painter_h, "destruct(::Qt::Painter object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Painter_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::destruct(::Qt::Painter object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_destruct_h);
        }

        /* Define ::Qt::Painter::destruct(::Qt::Painter object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Painter_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Painter_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_destruct);
            if (::hyve::define(QT::Painter_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::destruct(::Qt::Painter object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Pen::construct(::Qt::Pen object) */
        if (!(QT::Pen_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Pen::construct(::Qt::Pen object)", "load: check if object '::Qt::Pen::construct(::Qt::Pen object)' already exists."))) {
            QT::Pen_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Pen_h, "construct(::Qt::Pen object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Pen_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Pen::construct(::Qt::Pen object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Pen_construct_h);
        }

        /* Define ::Qt::Pen::construct(::Qt::Pen object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Pen_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Pen_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Pen_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Pen_construct_h with C++ function */
            ((::hyve::lang::function)QT::Pen_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Pen_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Pen_construct);
            if (::hyve::define(QT::Pen_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Pen::construct(::Qt::Pen object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Pen::destruct(::Qt::Pen object) */
        if (!(QT::Pen_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Pen::destruct(::Qt::Pen object)", "load: check if object '::Qt::Pen::destruct(::Qt::Pen object)' already exists."))) {
            QT::Pen_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Pen_h, "destruct(::Qt::Pen object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Pen_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Pen::destruct(::Qt::Pen object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Pen_destruct_h);
        }

        /* Define ::Qt::Pen::destruct(::Qt::Pen object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Pen_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Pen_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Pen_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Pen_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Pen_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Pen_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Pen_destruct);
            if (::hyve::define(QT::Pen_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Pen::destruct(::Qt::Pen object)'.");
                goto error;
            }
        }
        /* Define ::Qt::Pen */
        if (!::hyve::checkState((::hyve::lang::object)QT::Pen_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Pen_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Pen_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Pen_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Pen_h)->baseAccess = 0x0;
            QT::Pen_h->implements.length = 0;
            QT::Pen_h->implements.buffer = NULL;
            if (::hyve::define(QT::Pen_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Pen'.");
                goto error;
            }
        }
        /* Define ::Qt::Painter::pen */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_pen_h, ::hyve::lang::DEFINED)) {
            QT::Painter_pen_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Pen"));
            QT::Painter_pen_h->modifiers = 0x0;
            QT::Painter_pen_h->state = 0x6;
            QT::Painter_pen_h->weak = FALSE;
            QT::Painter_pen_h->id = 2;
            if (::hyve::define(QT::Painter_pen_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::pen'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::setPen(::Qt::Pen pen) */
        if (!(QT::Painter_setPen_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::setPen(::Qt::Pen pen)", "load: check if object '::Qt::Painter::setPen(::Qt::Pen pen)' already exists."))) {
            QT::Painter_setPen_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "setPen(::Qt::Pen pen)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_setPen_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::setPen(::Qt::Pen pen)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_setPen_h);
        }

        /* Define ::Qt::Painter::setPen(::Qt::Pen pen) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_setPen_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_setPen_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_setPen_h->_virtual = FALSE;
            
            /* Bind QT::Painter_setPen_h with C++ function */
            ((::hyve::lang::function)QT::Painter_setPen_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_setPen_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_setPen);
            if (::hyve::define(QT::Painter_setPen_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::setPen(::Qt::Pen pen)'.");
                goto error;
            }
        }
        /* Declare ::Qt::LinearGradient::init(::Qt::LinearGradient object) */
        if (!(QT::LinearGradient_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::LinearGradient::init(::Qt::LinearGradient object)", "load: check if object '::Qt::LinearGradient::init(::Qt::LinearGradient object)' already exists."))) {
            QT::LinearGradient_init_h = (::hyve::lang::callback)::hyve::declare(QT::LinearGradient_h, "init(::Qt::LinearGradient object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::LinearGradient_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LinearGradient::init(::Qt::LinearGradient object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LinearGradient_init_h);
        }

        /* Define ::Qt::LinearGradient::init(::Qt::LinearGradient object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::LinearGradient_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::LinearGradient_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::LinearGradient_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::LinearGradient_init_h with C++ function */
            ((::hyve::lang::function)QT::LinearGradient_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::LinearGradient_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_LinearGradient_init);
            if (::hyve::define(QT::LinearGradient_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LinearGradient::init(::Qt::LinearGradient object)'.");
                goto error;
            }
        }
        /* Define ::Qt::LinearGradient */
        if (!::hyve::checkState((::hyve::lang::object)QT::LinearGradient_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::LinearGradient_h)->parentType = NULL;
            ((::hyve::lang::type)QT::LinearGradient_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::LinearGradient_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Gradient"));
            ((::hyve::lang::_struct)QT::LinearGradient_h)->baseAccess = 0x0;
            QT::LinearGradient_h->implements.length = 0;
            QT::LinearGradient_h->implements.buffer = NULL;
            if (::hyve::define(QT::LinearGradient_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LinearGradient'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridLayout::construct(::Qt::GridLayout object) */
        if (!(QT::GridLayout_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::GridLayout::construct(::Qt::GridLayout object)", "load: check if object '::Qt::GridLayout::construct(::Qt::GridLayout object)' already exists."))) {
            QT::GridLayout_construct_h = (::hyve::lang::callback)::hyve::declare(QT::GridLayout_h, "construct(::Qt::GridLayout object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::GridLayout_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout::construct(::Qt::GridLayout object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_construct_h);
        }

        /* Define ::Qt::GridLayout::construct(::Qt::GridLayout object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::GridLayout_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::GridLayout_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::GridLayout_construct_h with C++ function */
            ((::hyve::lang::function)QT::GridLayout_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::GridLayout_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_GridLayout_construct);
            if (::hyve::define(QT::GridLayout_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout::construct(::Qt::GridLayout object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::GridLayout::destruct(::Qt::GridLayout object) */
        if (!(QT::GridLayout_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::GridLayout::destruct(::Qt::GridLayout object)", "load: check if object '::Qt::GridLayout::destruct(::Qt::GridLayout object)' already exists."))) {
            QT::GridLayout_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::GridLayout_h, "destruct(::Qt::GridLayout object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::GridLayout_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GridLayout::destruct(::Qt::GridLayout object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GridLayout_destruct_h);
        }

        /* Define ::Qt::GridLayout::destruct(::Qt::GridLayout object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::GridLayout_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::GridLayout_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::GridLayout_destruct_h with C++ function */
            ((::hyve::lang::function)QT::GridLayout_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::GridLayout_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_GridLayout_destruct);
            if (::hyve::define(QT::GridLayout_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout::destruct(::Qt::GridLayout object)'.");
                goto error;
            }
        }
        /* Define ::Qt::GridLayout */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridLayout_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::GridLayout_h)->parentType = NULL;
            ((::hyve::lang::type)QT::GridLayout_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::GridLayout_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::GridLayout_h)->baseAccess = 0x0;
            QT::GridLayout_h->implements.length = 0;
            QT::GridLayout_h->implements.buffer = NULL;
            if (::hyve::define(QT::GridLayout_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridLayout'.");
                goto error;
            }
        }
        /* Declare ::Qt::Font::construct(::Qt::Font object) */
        if (!(QT::Font_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Font::construct(::Qt::Font object)", "load: check if object '::Qt::Font::construct(::Qt::Font object)' already exists."))) {
            QT::Font_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Font_h, "construct(::Qt::Font object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Font_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font::construct(::Qt::Font object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_construct_h);
        }

        /* Define ::Qt::Font::construct(::Qt::Font object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Font_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Font_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Font_construct_h with C++ function */
            ((::hyve::lang::function)QT::Font_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Font_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Font_construct);
            if (::hyve::define(QT::Font_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font::construct(::Qt::Font object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Font::destruct(::Qt::Font object) */
        if (!(QT::Font_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Font::destruct(::Qt::Font object)", "load: check if object '::Qt::Font::destruct(::Qt::Font object)' already exists."))) {
            QT::Font_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Font_h, "destruct(::Qt::Font object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Font_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Font::destruct(::Qt::Font object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Font_destruct_h);
        }

        /* Define ::Qt::Font::destruct(::Qt::Font object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Font_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Font_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Font_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Font_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Font_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Font_destruct);
            if (::hyve::define(QT::Font_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font::destruct(::Qt::Font object)'.");
                goto error;
            }
        }
        /* Define ::Qt::Font */
        if (!::hyve::checkState((::hyve::lang::object)QT::Font_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Font_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Font_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Font_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Font_h)->baseAccess = 0x0;
            QT::Font_h->implements.length = 0;
            QT::Font_h->implements.buffer = NULL;
            if (::hyve::define(QT::Font_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Font'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::setFont(::Qt::Font font) */
        if (!(QT::Painter_setFont_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::setFont(::Qt::Font font)", "load: check if object '::Qt::Painter::setFont(::Qt::Font font)' already exists."))) {
            QT::Painter_setFont_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "setFont(::Qt::Font font)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_setFont_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::setFont(::Qt::Font font)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_setFont_h);
        }

        /* Define ::Qt::Painter::setFont(::Qt::Font font) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_setFont_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_setFont_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_setFont_h->_virtual = FALSE;
            
            /* Bind QT::Painter_setFont_h with C++ function */
            ((::hyve::lang::function)QT::Painter_setFont_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_setFont_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_setFont);
            if (::hyve::define(QT::Painter_setFont_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::setFont(::Qt::Font font)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ConicalGradient::init(::Qt::ConicalGradient object) */
        if (!(QT::ConicalGradient_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ConicalGradient::init(::Qt::ConicalGradient object)", "load: check if object '::Qt::ConicalGradient::init(::Qt::ConicalGradient object)' already exists."))) {
            QT::ConicalGradient_init_h = (::hyve::lang::callback)::hyve::declare(QT::ConicalGradient_h, "init(::Qt::ConicalGradient object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ConicalGradient_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ConicalGradient::init(::Qt::ConicalGradient object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ConicalGradient_init_h);
        }

        /* Define ::Qt::ConicalGradient::init(::Qt::ConicalGradient object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ConicalGradient_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ConicalGradient_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ConicalGradient_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::ConicalGradient_init_h with C++ function */
            ((::hyve::lang::function)QT::ConicalGradient_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ConicalGradient_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ConicalGradient_init);
            if (::hyve::define(QT::ConicalGradient_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ConicalGradient::init(::Qt::ConicalGradient object)'.");
                goto error;
            }
        }
        /* Define ::Qt::ConicalGradient */
        if (!::hyve::checkState((::hyve::lang::object)QT::ConicalGradient_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ConicalGradient_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ConicalGradient_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ConicalGradient_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Gradient"));
            ((::hyve::lang::_struct)QT::ConicalGradient_h)->baseAccess = 0x0;
            QT::ConicalGradient_h->implements.length = 0;
            QT::ConicalGradient_h->implements.buffer = NULL;
            if (::hyve::define(QT::ConicalGradient_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ConicalGradient'.");
                goto error;
            }
        }
        /* Declare ::Qt::Brush::construct(::Qt::Brush object) */
        if (!(QT::Brush_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Brush::construct(::Qt::Brush object)", "load: check if object '::Qt::Brush::construct(::Qt::Brush object)' already exists."))) {
            QT::Brush_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Brush_h, "construct(::Qt::Brush object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Brush_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Brush::construct(::Qt::Brush object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Brush_construct_h);
        }

        /* Define ::Qt::Brush::construct(::Qt::Brush object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Brush_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Brush_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Brush_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Brush_construct_h with C++ function */
            ((::hyve::lang::function)QT::Brush_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Brush_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Brush_construct);
            if (::hyve::define(QT::Brush_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Brush::construct(::Qt::Brush object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Brush::destruct(::Qt::Brush object) */
        if (!(QT::Brush_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Brush::destruct(::Qt::Brush object)", "load: check if object '::Qt::Brush::destruct(::Qt::Brush object)' already exists."))) {
            QT::Brush_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Brush_h, "destruct(::Qt::Brush object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Brush_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Brush::destruct(::Qt::Brush object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Brush_destruct_h);
        }

        /* Define ::Qt::Brush::destruct(::Qt::Brush object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Brush_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Brush_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Brush_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Brush_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Brush_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Brush_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Brush_destruct);
            if (::hyve::define(QT::Brush_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Brush::destruct(::Qt::Brush object)'.");
                goto error;
            }
        }
        /* Define ::Qt::Brush */
        if (!::hyve::checkState((::hyve::lang::object)QT::Brush_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Brush_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Brush_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Brush_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Brush_h)->baseAccess = 0x0;
            QT::Brush_h->implements.length = 0;
            QT::Brush_h->implements.buffer = NULL;
            if (::hyve::define(QT::Brush_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Brush'.");
                goto error;
            }
        }
        /* Define ::Qt::Painter::brush */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_brush_h, ::hyve::lang::DEFINED)) {
            QT::Painter_brush_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Brush"));
            QT::Painter_brush_h->modifiers = 0x0;
            QT::Painter_brush_h->state = 0x6;
            QT::Painter_brush_h->weak = FALSE;
            QT::Painter_brush_h->id = 1;
            if (::hyve::define(QT::Painter_brush_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::brush'.");
                goto error;
            }
        }
        /* Declare ::Qt::Painter::setBrush(::Qt::Brush brush) */
        if (!(QT::Painter_setBrush_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Painter::setBrush(::Qt::Brush brush)", "load: check if object '::Qt::Painter::setBrush(::Qt::Brush brush)' already exists."))) {
            QT::Painter_setBrush_h = (::hyve::lang::method)::hyve::declare(QT::Painter_h, "setBrush(::Qt::Brush brush)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Painter_setBrush_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Painter::setBrush(::Qt::Brush brush)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Painter_setBrush_h);
        }

        /* Define ::Qt::Painter::setBrush(::Qt::Brush brush) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_setBrush_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Painter_setBrush_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Painter_setBrush_h->_virtual = FALSE;
            
            /* Bind QT::Painter_setBrush_h with C++ function */
            ((::hyve::lang::function)QT::Painter_setBrush_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Painter_setBrush_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Painter_setBrush);
            if (::hyve::define(QT::Painter_setBrush_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter::setBrush(::Qt::Brush brush)'.");
                goto error;
            }
        }
        /* Define ::Qt::Painter */
        if (!::hyve::checkState((::hyve::lang::object)QT::Painter_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Painter_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Painter_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Painter_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Painter_h)->baseAccess = 0x0;
            QT::Painter_h->implements.length = 0;
            QT::Painter_h->implements.buffer = NULL;
            if (::hyve::define(QT::Painter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Painter'.");
                goto error;
            }
        }
        /* Define ::Qt::paintEvent_t::painter */
        if (!::hyve::checkState((::hyve::lang::object)QT::paintEvent_t_painter_h, ::hyve::lang::DEFINED)) {
            QT::paintEvent_t_painter_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Painter"));
            QT::paintEvent_t_painter_h->modifiers = 0x0;
            QT::paintEvent_t_painter_h->state = 0x6;
            QT::paintEvent_t_painter_h->weak = FALSE;
            QT::paintEvent_t_painter_h->id = 0;
            if (::hyve::define(QT::paintEvent_t_painter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::paintEvent_t::painter'.");
                goto error;
            }
        }
        /* Define ::Qt::paintEvent_t */
        if (!::hyve::checkState((::hyve::lang::object)QT::paintEvent_t_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::paintEvent_t_h)->parentType = NULL;
            ((::hyve::lang::type)QT::paintEvent_t_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::paintEvent_t_h)->base = NULL;
            ((::hyve::lang::_struct)QT::paintEvent_t_h)->baseAccess = 0x0;
            QT::paintEvent_t_h->implements.length = 0;
            QT::paintEvent_t_h->implements.buffer = NULL;
            if (::hyve::define(QT::paintEvent_t_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::paintEvent_t'.");
                goto error;
            }
        }
        /* Define ::Qt::Widget::paintEvent */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_paintEvent_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::member)QT::Widget_paintEvent_h)->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::paintEvent_t"));
            ((::hyve::lang::member)QT::Widget_paintEvent_h)->modifiers = 0x4;
            ((::hyve::lang::member)QT::Widget_paintEvent_h)->state = 0x6;
            ((::hyve::lang::member)QT::Widget_paintEvent_h)->weak = FALSE;
            ((::hyve::lang::member)QT::Widget_paintEvent_h)->id = 0;
            if (::hyve::define(QT::Widget_paintEvent_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::paintEvent'.");
                goto error;
            }
        }
        /* Define ::Qt::Widget::painter */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_painter_h, ::hyve::lang::DEFINED)) {
            QT::Widget_painter_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Painter"));
            QT::Widget_painter_h->modifiers = 0x7;
            QT::Widget_painter_h->state = 0x6;
            QT::Widget_painter_h->weak = FALSE;
            QT::Widget_painter_h->id = 9;
            if (::hyve::define(QT::Widget_painter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget::painter'.");
                goto error;
            }
        }
        /* Define ::Qt::Widget */
        if (!::hyve::checkState((::hyve::lang::object)QT::Widget_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Widget_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Widget_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Widget_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Widget_h)->baseAccess = 0x0;
            QT::Widget_h->implements.length = 1;
            QT::Widget_h->implements.buffer = (::hyve::lang::interface*)::hyve::alloc(sizeof(::hyve::lang::interface));
            QT::Widget_h->implements.buffer[0] = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::PaintDevice"));
            if (::hyve::define(QT::Widget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Widget'.");
                goto error;
            }
        }
        /* Declare ::Qt::AbstractButton::construct(::Qt::AbstractButton object) */
        if (!(QT::AbstractButton_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton::construct(::Qt::AbstractButton object)", "load: check if object '::Qt::AbstractButton::construct(::Qt::AbstractButton object)' already exists."))) {
            QT::AbstractButton_construct_h = (::hyve::lang::callback)::hyve::declare(QT::AbstractButton_h, "construct(::Qt::AbstractButton object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::AbstractButton_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton::construct(::Qt::AbstractButton object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_construct_h);
        }

        /* Define ::Qt::AbstractButton::construct(::Qt::AbstractButton object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::AbstractButton_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::AbstractButton_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::AbstractButton_construct_h with C++ function */
            ((::hyve::lang::function)QT::AbstractButton_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::AbstractButton_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_AbstractButton_construct);
            if (::hyve::define(QT::AbstractButton_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton::construct(::Qt::AbstractButton object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::AbstractButton::destruct(::Qt::AbstractButton object) */
        if (!(QT::AbstractButton_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::AbstractButton::destruct(::Qt::AbstractButton object)", "load: check if object '::Qt::AbstractButton::destruct(::Qt::AbstractButton object)' already exists."))) {
            QT::AbstractButton_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::AbstractButton_h, "destruct(::Qt::AbstractButton object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::AbstractButton_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::AbstractButton::destruct(::Qt::AbstractButton object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::AbstractButton_destruct_h);
        }

        /* Define ::Qt::AbstractButton::destruct(::Qt::AbstractButton object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::AbstractButton_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::AbstractButton_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::AbstractButton_destruct_h with C++ function */
            ((::hyve::lang::function)QT::AbstractButton_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::AbstractButton_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_AbstractButton_destruct);
            if (::hyve::define(QT::AbstractButton_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton::destruct(::Qt::AbstractButton object)'.");
                goto error;
            }
        }
        /* Define ::Qt::AbstractButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::AbstractButton_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::AbstractButton_h)->parentType = NULL;
            ((::hyve::lang::type)QT::AbstractButton_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::AbstractButton_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::AbstractButton_h)->baseAccess = 0x0;
            QT::AbstractButton_h->implements.length = 0;
            QT::AbstractButton_h->implements.buffer = NULL;
            if (::hyve::define(QT::AbstractButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::AbstractButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::CheckBox::construct(::Qt::CheckBox object) */
        if (!(QT::CheckBox_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::CheckBox::construct(::Qt::CheckBox object)", "load: check if object '::Qt::CheckBox::construct(::Qt::CheckBox object)' already exists."))) {
            QT::CheckBox_construct_h = (::hyve::lang::callback)::hyve::declare(QT::CheckBox_h, "construct(::Qt::CheckBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::CheckBox_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CheckBox::construct(::Qt::CheckBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CheckBox_construct_h);
        }

        /* Define ::Qt::CheckBox::construct(::Qt::CheckBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::CheckBox_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::CheckBox_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::CheckBox_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::CheckBox_construct_h with C++ function */
            ((::hyve::lang::function)QT::CheckBox_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CheckBox_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CheckBox_construct);
            if (::hyve::define(QT::CheckBox_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CheckBox::construct(::Qt::CheckBox object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::CheckBox::destruct(::Qt::CheckBox object) */
        if (!(QT::CheckBox_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::CheckBox::destruct(::Qt::CheckBox object)", "load: check if object '::Qt::CheckBox::destruct(::Qt::CheckBox object)' already exists."))) {
            QT::CheckBox_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::CheckBox_h, "destruct(::Qt::CheckBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::CheckBox_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CheckBox::destruct(::Qt::CheckBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CheckBox_destruct_h);
        }

        /* Define ::Qt::CheckBox::destruct(::Qt::CheckBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::CheckBox_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::CheckBox_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::CheckBox_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::CheckBox_destruct_h with C++ function */
            ((::hyve::lang::function)QT::CheckBox_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CheckBox_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CheckBox_destruct);
            if (::hyve::define(QT::CheckBox_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CheckBox::destruct(::Qt::CheckBox object)'.");
                goto error;
            }
        }
        /* Define ::Qt::CheckBox */
        if (!::hyve::checkState((::hyve::lang::object)QT::CheckBox_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::CheckBox_h)->parentType = NULL;
            ((::hyve::lang::type)QT::CheckBox_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::CheckBox_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::AbstractButton"));
            ((::hyve::lang::_struct)QT::CheckBox_h)->baseAccess = 0x0;
            QT::CheckBox_h->implements.length = 0;
            QT::CheckBox_h->implements.buffer = NULL;
            if (::hyve::define(QT::CheckBox_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CheckBox'.");
                goto error;
            }
        }
        /* Declare ::Qt::CheckBox::onSelf */
        if (!(QT::CheckBox_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::CheckBox::onSelf", "load: check if object '::Qt::CheckBox::onSelf' already exists."))) {
            QT::CheckBox_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::CheckBox_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::CheckBox_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CheckBox::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CheckBox_onSelf_h);
        }

        /* Define ::Qt::CheckBox::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::CheckBox_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::CheckBox_onSelf_h->observable = NULL;
            QT::CheckBox_onSelf_h->mask = 0xb0;
            QT::CheckBox_onSelf_h->expression = NULL;
            QT::CheckBox_onSelf_h->_template = 1;
            QT::CheckBox_onSelf_h->dispatcher = NULL;
            QT::CheckBox_onSelf_h->me = NULL;
            
            /* Bind QT::CheckBox_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::CheckBox_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CheckBox_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CheckBox_onSelf);
            if (::hyve::define(QT::CheckBox_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CheckBox::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::PushButton::construct(::Qt::PushButton object) */
        if (!(QT::PushButton_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::PushButton::construct(::Qt::PushButton object)", "load: check if object '::Qt::PushButton::construct(::Qt::PushButton object)' already exists."))) {
            QT::PushButton_construct_h = (::hyve::lang::callback)::hyve::declare(QT::PushButton_h, "construct(::Qt::PushButton object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::PushButton_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PushButton::construct(::Qt::PushButton object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PushButton_construct_h);
        }

        /* Define ::Qt::PushButton::construct(::Qt::PushButton object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::PushButton_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::PushButton_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::PushButton_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::PushButton_construct_h with C++ function */
            ((::hyve::lang::function)QT::PushButton_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::PushButton_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_PushButton_construct);
            if (::hyve::define(QT::PushButton_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PushButton::construct(::Qt::PushButton object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::PushButton::destruct(::Qt::PushButton object) */
        if (!(QT::PushButton_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::PushButton::destruct(::Qt::PushButton object)", "load: check if object '::Qt::PushButton::destruct(::Qt::PushButton object)' already exists."))) {
            QT::PushButton_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::PushButton_h, "destruct(::Qt::PushButton object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::PushButton_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PushButton::destruct(::Qt::PushButton object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PushButton_destruct_h);
        }

        /* Define ::Qt::PushButton::destruct(::Qt::PushButton object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::PushButton_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::PushButton_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::PushButton_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::PushButton_destruct_h with C++ function */
            ((::hyve::lang::function)QT::PushButton_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::PushButton_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_PushButton_destruct);
            if (::hyve::define(QT::PushButton_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PushButton::destruct(::Qt::PushButton object)'.");
                goto error;
            }
        }
        /* Define ::Qt::PushButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::PushButton_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::PushButton_h)->parentType = NULL;
            ((::hyve::lang::type)QT::PushButton_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::PushButton_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::AbstractButton"));
            ((::hyve::lang::_struct)QT::PushButton_h)->baseAccess = 0x0;
            QT::PushButton_h->implements.length = 0;
            QT::PushButton_h->implements.buffer = NULL;
            if (::hyve::define(QT::PushButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PushButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::PushButton::onSelf */
        if (!(QT::PushButton_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::PushButton::onSelf", "load: check if object '::Qt::PushButton::onSelf' already exists."))) {
            QT::PushButton_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::PushButton_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::PushButton_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::PushButton::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::PushButton_onSelf_h);
        }

        /* Define ::Qt::PushButton::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::PushButton_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::PushButton_onSelf_h->observable = NULL;
            QT::PushButton_onSelf_h->mask = 0xb0;
            QT::PushButton_onSelf_h->expression = NULL;
            QT::PushButton_onSelf_h->_template = 1;
            QT::PushButton_onSelf_h->dispatcher = NULL;
            QT::PushButton_onSelf_h->me = NULL;
            
            /* Bind QT::PushButton_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::PushButton_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::PushButton_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_PushButton_onSelf);
            if (::hyve::define(QT::PushButton_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::PushButton::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::RadioButton::construct(::Qt::RadioButton object) */
        if (!(QT::RadioButton_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::RadioButton::construct(::Qt::RadioButton object)", "load: check if object '::Qt::RadioButton::construct(::Qt::RadioButton object)' already exists."))) {
            QT::RadioButton_construct_h = (::hyve::lang::callback)::hyve::declare(QT::RadioButton_h, "construct(::Qt::RadioButton object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::RadioButton_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadioButton::construct(::Qt::RadioButton object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadioButton_construct_h);
        }

        /* Define ::Qt::RadioButton::construct(::Qt::RadioButton object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadioButton_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::RadioButton_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::RadioButton_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::RadioButton_construct_h with C++ function */
            ((::hyve::lang::function)QT::RadioButton_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::RadioButton_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_RadioButton_construct);
            if (::hyve::define(QT::RadioButton_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadioButton::construct(::Qt::RadioButton object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::RadioButton::destruct(::Qt::RadioButton object) */
        if (!(QT::RadioButton_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::RadioButton::destruct(::Qt::RadioButton object)", "load: check if object '::Qt::RadioButton::destruct(::Qt::RadioButton object)' already exists."))) {
            QT::RadioButton_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::RadioButton_h, "destruct(::Qt::RadioButton object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::RadioButton_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadioButton::destruct(::Qt::RadioButton object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadioButton_destruct_h);
        }

        /* Define ::Qt::RadioButton::destruct(::Qt::RadioButton object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadioButton_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::RadioButton_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::RadioButton_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::RadioButton_destruct_h with C++ function */
            ((::hyve::lang::function)QT::RadioButton_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::RadioButton_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_RadioButton_destruct);
            if (::hyve::define(QT::RadioButton_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadioButton::destruct(::Qt::RadioButton object)'.");
                goto error;
            }
        }
        /* Define ::Qt::RadioButton */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadioButton_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::RadioButton_h)->parentType = NULL;
            ((::hyve::lang::type)QT::RadioButton_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::RadioButton_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::AbstractButton"));
            ((::hyve::lang::_struct)QT::RadioButton_h)->baseAccess = 0x0;
            QT::RadioButton_h->implements.length = 0;
            QT::RadioButton_h->implements.buffer = NULL;
            if (::hyve::define(QT::RadioButton_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadioButton'.");
                goto error;
            }
        }
        /* Declare ::Qt::RadioButton::onSelf */
        if (!(QT::RadioButton_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::RadioButton::onSelf", "load: check if object '::Qt::RadioButton::onSelf' already exists."))) {
            QT::RadioButton_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::RadioButton_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::RadioButton_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::RadioButton::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::RadioButton_onSelf_h);
        }

        /* Define ::Qt::RadioButton::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::RadioButton_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::RadioButton_onSelf_h->observable = NULL;
            QT::RadioButton_onSelf_h->mask = 0xb0;
            QT::RadioButton_onSelf_h->expression = NULL;
            QT::RadioButton_onSelf_h->_template = 1;
            QT::RadioButton_onSelf_h->dispatcher = NULL;
            QT::RadioButton_onSelf_h->me = NULL;
            
            /* Bind QT::RadioButton_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::RadioButton_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::RadioButton_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_RadioButton_onSelf);
            if (::hyve::define(QT::RadioButton_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::RadioButton::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ComboBox::construct(::Qt::ComboBox object) */
        if (!(QT::ComboBox_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ComboBox::construct(::Qt::ComboBox object)", "load: check if object '::Qt::ComboBox::construct(::Qt::ComboBox object)' already exists."))) {
            QT::ComboBox_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ComboBox_h, "construct(::Qt::ComboBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ComboBox_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox::construct(::Qt::ComboBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_construct_h);
        }

        /* Define ::Qt::ComboBox::construct(::Qt::ComboBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ComboBox_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ComboBox_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ComboBox_construct_h with C++ function */
            ((::hyve::lang::function)QT::ComboBox_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ComboBox_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ComboBox_construct);
            if (::hyve::define(QT::ComboBox_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox::construct(::Qt::ComboBox object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ComboBox::destruct(::Qt::ComboBox object) */
        if (!(QT::ComboBox_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ComboBox::destruct(::Qt::ComboBox object)", "load: check if object '::Qt::ComboBox::destruct(::Qt::ComboBox object)' already exists."))) {
            QT::ComboBox_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ComboBox_h, "destruct(::Qt::ComboBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ComboBox_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox::destruct(::Qt::ComboBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_destruct_h);
        }

        /* Define ::Qt::ComboBox::destruct(::Qt::ComboBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ComboBox_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ComboBox_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ComboBox_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ComboBox_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ComboBox_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ComboBox_destruct);
            if (::hyve::define(QT::ComboBox_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox::destruct(::Qt::ComboBox object)'.");
                goto error;
            }
        }
        /* Define ::Qt::ComboBox */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ComboBox_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ComboBox_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ComboBox_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::ComboBox_h)->baseAccess = 0x0;
            QT::ComboBox_h->implements.length = 0;
            QT::ComboBox_h->implements.buffer = NULL;
            if (::hyve::define(QT::ComboBox_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox'.");
                goto error;
            }
        }
        /* Declare ::Qt::EnumComboBox::construct(::Qt::EnumComboBox object) */
        if (!(QT::EnumComboBox_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::EnumComboBox::construct(::Qt::EnumComboBox object)", "load: check if object '::Qt::EnumComboBox::construct(::Qt::EnumComboBox object)' already exists."))) {
            QT::EnumComboBox_construct_h = (::hyve::lang::callback)::hyve::declare(QT::EnumComboBox_h, "construct(::Qt::EnumComboBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::EnumComboBox_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::EnumComboBox::construct(::Qt::EnumComboBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::EnumComboBox_construct_h);
        }

        /* Define ::Qt::EnumComboBox::construct(::Qt::EnumComboBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::EnumComboBox_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::EnumComboBox_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::EnumComboBox_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::EnumComboBox_construct_h with C++ function */
            ((::hyve::lang::function)QT::EnumComboBox_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::EnumComboBox_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_EnumComboBox_construct);
            if (::hyve::define(QT::EnumComboBox_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::EnumComboBox::construct(::Qt::EnumComboBox object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object) */
        if (!(QT::EnumComboBox_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object)", "load: check if object '::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object)' already exists."))) {
            QT::EnumComboBox_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::EnumComboBox_h, "destruct(::Qt::EnumComboBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::EnumComboBox_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::EnumComboBox_destruct_h);
        }

        /* Define ::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::EnumComboBox_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::EnumComboBox_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::EnumComboBox_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::EnumComboBox_destruct_h with C++ function */
            ((::hyve::lang::function)QT::EnumComboBox_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::EnumComboBox_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_EnumComboBox_destruct);
            if (::hyve::define(QT::EnumComboBox_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object)'.");
                goto error;
            }
        }
        /* Define ::Qt::EnumComboBox */
        if (!::hyve::checkState((::hyve::lang::object)QT::EnumComboBox_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::EnumComboBox_h)->parentType = NULL;
            ((::hyve::lang::type)QT::EnumComboBox_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::EnumComboBox_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::ComboBox"));
            ((::hyve::lang::_struct)QT::EnumComboBox_h)->baseAccess = 0x0;
            QT::EnumComboBox_h->implements.length = 0;
            QT::EnumComboBox_h->implements.buffer = NULL;
            if (::hyve::define(QT::EnumComboBox_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::EnumComboBox'.");
                goto error;
            }
        }
        /* Declare ::Qt::ComboBox::onSelf */
        if (!(QT::ComboBox_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ComboBox::onSelf", "load: check if object '::Qt::ComboBox::onSelf' already exists."))) {
            QT::ComboBox_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::ComboBox_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ComboBox_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ComboBox::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ComboBox_onSelf_h);
        }

        /* Define ::Qt::ComboBox::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::ComboBox_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::ComboBox_onSelf_h->observable = NULL;
            QT::ComboBox_onSelf_h->mask = 0xb0;
            QT::ComboBox_onSelf_h->expression = NULL;
            QT::ComboBox_onSelf_h->_template = 1;
            QT::ComboBox_onSelf_h->dispatcher = NULL;
            QT::ComboBox_onSelf_h->me = NULL;
            
            /* Bind QT::ComboBox_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::ComboBox_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ComboBox_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ComboBox_onSelf);
            if (::hyve::define(QT::ComboBox_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ComboBox::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::construct(::Qt::CustomPlot object) */
        if (!(QT::CustomPlot_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::construct(::Qt::CustomPlot object)", "load: check if object '::Qt::CustomPlot::construct(::Qt::CustomPlot object)' already exists."))) {
            QT::CustomPlot_construct_h = (::hyve::lang::callback)::hyve::declare(QT::CustomPlot_h, "construct(::Qt::CustomPlot object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::CustomPlot_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::construct(::Qt::CustomPlot object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_construct_h);
        }

        /* Define ::Qt::CustomPlot::construct(::Qt::CustomPlot object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::CustomPlot_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::CustomPlot_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::CustomPlot_construct_h with C++ function */
            ((::hyve::lang::function)QT::CustomPlot_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CustomPlot_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CustomPlot_construct);
            if (::hyve::define(QT::CustomPlot_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::construct(::Qt::CustomPlot object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::destruct(::Qt::CustomPlot object) */
        if (!(QT::CustomPlot_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::destruct(::Qt::CustomPlot object)", "load: check if object '::Qt::CustomPlot::destruct(::Qt::CustomPlot object)' already exists."))) {
            QT::CustomPlot_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::CustomPlot_h, "destruct(::Qt::CustomPlot object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::CustomPlot_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::destruct(::Qt::CustomPlot object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_destruct_h);
        }

        /* Define ::Qt::CustomPlot::destruct(::Qt::CustomPlot object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::CustomPlot_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::CustomPlot_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::CustomPlot_destruct_h with C++ function */
            ((::hyve::lang::function)QT::CustomPlot_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CustomPlot_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CustomPlot_destruct);
            if (::hyve::define(QT::CustomPlot_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::destruct(::Qt::CustomPlot object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::init(::Qt::CustomPlot object) */
        if (!(QT::CustomPlot_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::init(::Qt::CustomPlot object)", "load: check if object '::Qt::CustomPlot::init(::Qt::CustomPlot object)' already exists."))) {
            QT::CustomPlot_init_h = (::hyve::lang::callback)::hyve::declare(QT::CustomPlot_h, "init(::Qt::CustomPlot object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::CustomPlot_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::init(::Qt::CustomPlot object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_init_h);
        }

        /* Define ::Qt::CustomPlot::init(::Qt::CustomPlot object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::CustomPlot_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::CustomPlot_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::CustomPlot_init_h with C++ function */
            ((::hyve::lang::function)QT::CustomPlot_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CustomPlot_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CustomPlot_init);
            if (::hyve::define(QT::CustomPlot_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::init(::Qt::CustomPlot object)'.");
                goto error;
            }
        }
        /* Define ::Qt::CustomPlot */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::CustomPlot_h)->parentType = NULL;
            ((::hyve::lang::type)QT::CustomPlot_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::CustomPlot_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::CustomPlot_h)->baseAccess = 0x0;
            QT::CustomPlot_h->implements.length = 0;
            QT::CustomPlot_h->implements.buffer = NULL;
            if (::hyve::define(QT::CustomPlot_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::onDestruct */
        if (!(QT::CustomPlot_onDestruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::onDestruct", "load: check if object '::Qt::CustomPlot::onDestruct' already exists."))) {
            QT::CustomPlot_onDestruct_h = (::hyve::lang::observer)::hyve::declare(QT::CustomPlot_h, "onDestruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::CustomPlot_onDestruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::onDestruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_onDestruct_h);
        }

        /* Define ::Qt::CustomPlot::onDestruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_onDestruct_h, ::hyve::lang::DEFINED)) {
            QT::CustomPlot_onDestruct_h->observable = NULL;
            QT::CustomPlot_onDestruct_h->mask = 0xb0;
            QT::CustomPlot_onDestruct_h->expression = NULL;
            QT::CustomPlot_onDestruct_h->_template = 2;
            QT::CustomPlot_onDestruct_h->dispatcher = NULL;
            QT::CustomPlot_onDestruct_h->me = NULL;
            
            /* Bind QT::CustomPlot_onDestruct_h with C++ function */
            ((::hyve::lang::function)QT::CustomPlot_onDestruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CustomPlot_onDestruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CustomPlot_onDestruct);
            if (::hyve::define(QT::CustomPlot_onDestruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::onDestruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::onSelf */
        if (!(QT::CustomPlot_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::onSelf", "load: check if object '::Qt::CustomPlot::onSelf' already exists."))) {
            QT::CustomPlot_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::CustomPlot_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::CustomPlot_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_onSelf_h);
        }

        /* Define ::Qt::CustomPlot::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::CustomPlot_onSelf_h->observable = NULL;
            QT::CustomPlot_onSelf_h->mask = 0xb0;
            QT::CustomPlot_onSelf_h->expression = NULL;
            QT::CustomPlot_onSelf_h->_template = 3;
            QT::CustomPlot_onSelf_h->dispatcher = NULL;
            QT::CustomPlot_onSelf_h->me = NULL;
            
            /* Bind QT::CustomPlot_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::CustomPlot_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CustomPlot_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CustomPlot_onSelf);
            if (::hyve::define(QT::CustomPlot_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::CustomPlot::onUpdate */
        if (!(QT::CustomPlot_onUpdate_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::CustomPlot::onUpdate", "load: check if object '::Qt::CustomPlot::onUpdate' already exists."))) {
            QT::CustomPlot_onUpdate_h = (::hyve::lang::observer)::hyve::declare(QT::CustomPlot_h, "onUpdate", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::CustomPlot_onUpdate_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::CustomPlot::onUpdate'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::CustomPlot_onUpdate_h);
        }

        /* Define ::Qt::CustomPlot::onUpdate */
        if (!::hyve::checkState((::hyve::lang::object)QT::CustomPlot_onUpdate_h, ::hyve::lang::DEFINED)) {
            QT::CustomPlot_onUpdate_h->observable = NULL;
            QT::CustomPlot_onUpdate_h->mask = 0xb0;
            QT::CustomPlot_onUpdate_h->expression = NULL;
            QT::CustomPlot_onUpdate_h->_template = 1;
            QT::CustomPlot_onUpdate_h->dispatcher = NULL;
            QT::CustomPlot_onUpdate_h->me = NULL;
            
            /* Bind QT::CustomPlot_onUpdate_h with C++ function */
            ((::hyve::lang::function)QT::CustomPlot_onUpdate_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::CustomPlot_onUpdate_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_CustomPlot_onUpdate);
            if (::hyve::define(QT::CustomPlot_onUpdate_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::CustomPlot::onUpdate'.");
                goto error;
            }
        }
        /* Define ::Qt::GridWidget::widget */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridWidget_widget_h, ::hyve::lang::DEFINED)) {
            QT::GridWidget_widget_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Widget"));
            QT::GridWidget_widget_h->modifiers = 0x0;
            QT::GridWidget_widget_h->state = 0x6;
            QT::GridWidget_widget_h->weak = FALSE;
            QT::GridWidget_widget_h->id = 0;
            if (::hyve::define(QT::GridWidget_widget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridWidget::widget'.");
                goto error;
            }
        }
        /* Define ::Qt::GridWidget */
        if (!::hyve::checkState((::hyve::lang::object)QT::GridWidget_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::GridWidget_h)->parentType = NULL;
            ((::hyve::lang::type)QT::GridWidget_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::GridWidget_h)->base = NULL;
            QT::GridWidget_h->baseAccess = 0x0;
            if (::hyve::define(QT::GridWidget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GridWidget'.");
                goto error;
            }
        }
        /* Declare ::Qt::GroupBox::construct(::Qt::GroupBox object) */
        if (!(QT::GroupBox_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::GroupBox::construct(::Qt::GroupBox object)", "load: check if object '::Qt::GroupBox::construct(::Qt::GroupBox object)' already exists."))) {
            QT::GroupBox_construct_h = (::hyve::lang::callback)::hyve::declare(QT::GroupBox_h, "construct(::Qt::GroupBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::GroupBox_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GroupBox::construct(::Qt::GroupBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GroupBox_construct_h);
        }

        /* Define ::Qt::GroupBox::construct(::Qt::GroupBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::GroupBox_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::GroupBox_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::GroupBox_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::GroupBox_construct_h with C++ function */
            ((::hyve::lang::function)QT::GroupBox_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::GroupBox_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_GroupBox_construct);
            if (::hyve::define(QT::GroupBox_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GroupBox::construct(::Qt::GroupBox object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::GroupBox::destruct(::Qt::GroupBox object) */
        if (!(QT::GroupBox_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::GroupBox::destruct(::Qt::GroupBox object)", "load: check if object '::Qt::GroupBox::destruct(::Qt::GroupBox object)' already exists."))) {
            QT::GroupBox_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::GroupBox_h, "destruct(::Qt::GroupBox object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::GroupBox_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::GroupBox::destruct(::Qt::GroupBox object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::GroupBox_destruct_h);
        }

        /* Define ::Qt::GroupBox::destruct(::Qt::GroupBox object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::GroupBox_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::GroupBox_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::GroupBox_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::GroupBox_destruct_h with C++ function */
            ((::hyve::lang::function)QT::GroupBox_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::GroupBox_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_GroupBox_destruct);
            if (::hyve::define(QT::GroupBox_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GroupBox::destruct(::Qt::GroupBox object)'.");
                goto error;
            }
        }
        /* Define ::Qt::GroupBox */
        if (!::hyve::checkState((::hyve::lang::object)QT::GroupBox_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::GroupBox_h)->parentType = NULL;
            ((::hyve::lang::type)QT::GroupBox_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::GroupBox_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::GroupBox_h)->baseAccess = 0x0;
            QT::GroupBox_h->implements.length = 0;
            QT::GroupBox_h->implements.buffer = NULL;
            if (::hyve::define(QT::GroupBox_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::GroupBox'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label::construct(::Qt::Label object) */
        if (!(QT::Label_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Label::construct(::Qt::Label object)", "load: check if object '::Qt::Label::construct(::Qt::Label object)' already exists."))) {
            QT::Label_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Label_h, "construct(::Qt::Label object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Label_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::construct(::Qt::Label object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_construct_h);
        }

        /* Define ::Qt::Label::construct(::Qt::Label object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Label_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Label_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Label_construct_h with C++ function */
            ((::hyve::lang::function)QT::Label_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Label_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Label_construct);
            if (::hyve::define(QT::Label_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::construct(::Qt::Label object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label::destruct(::Qt::Label object) */
        if (!(QT::Label_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Label::destruct(::Qt::Label object)", "load: check if object '::Qt::Label::destruct(::Qt::Label object)' already exists."))) {
            QT::Label_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Label_h, "destruct(::Qt::Label object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Label_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::destruct(::Qt::Label object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_destruct_h);
        }

        /* Define ::Qt::Label::destruct(::Qt::Label object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Label_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Label_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Label_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Label_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Label_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Label_destruct);
            if (::hyve::define(QT::Label_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::destruct(::Qt::Label object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label::init(::Qt::Label object) */
        if (!(QT::Label_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Label::init(::Qt::Label object)", "load: check if object '::Qt::Label::init(::Qt::Label object)' already exists."))) {
            QT::Label_init_h = (::hyve::lang::callback)::hyve::declare(QT::Label_h, "init(::Qt::Label object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Label_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::init(::Qt::Label object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_init_h);
        }

        /* Define ::Qt::Label::init(::Qt::Label object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Label_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Label_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::Label_init_h with C++ function */
            ((::hyve::lang::function)QT::Label_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Label_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Label_init);
            if (::hyve::define(QT::Label_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::init(::Qt::Label object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label::onSelf */
        if (!(QT::Label_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::Label::onSelf", "load: check if object '::Qt::Label::onSelf' already exists."))) {
            QT::Label_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::Label_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::Label_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_onSelf_h);
        }

        /* Define ::Qt::Label::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::Label_onSelf_h->observable = NULL;
            QT::Label_onSelf_h->mask = 0xb0;
            QT::Label_onSelf_h->expression = NULL;
            QT::Label_onSelf_h->_template = 1;
            QT::Label_onSelf_h->dispatcher = NULL;
            QT::Label_onSelf_h->me = NULL;
            
            /* Bind QT::Label_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::Label_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Label_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Label_onSelf);
            if (::hyve::define(QT::Label_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::Label::setText(::hyve::lang::string text) */
        if (!(QT::Label_setText_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Label::setText(::hyve::lang::string text)", "load: check if object '::Qt::Label::setText(::hyve::lang::string text)' already exists."))) {
            QT::Label_setText_h = (::hyve::lang::method)::hyve::declare(QT::Label_h, "setText(::hyve::lang::string text)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Label_setText_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Label::setText(::hyve::lang::string text)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Label_setText_h);
        }

        /* Define ::Qt::Label::setText(::hyve::lang::string text) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_setText_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Label_setText_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Label_setText_h->_virtual = FALSE;
            
            /* Bind QT::Label_setText_h with C++ function */
            ((::hyve::lang::function)QT::Label_setText_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Label_setText_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Label_setText);
            if (::hyve::define(QT::Label_setText_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label::setText(::hyve::lang::string text)'.");
                goto error;
            }
        }
        /* Define ::Qt::Label */
        if (!::hyve::checkState((::hyve::lang::object)QT::Label_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Label_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Label_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Label_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::Label_h)->baseAccess = 0x0;
            QT::Label_h->implements.length = 0;
            QT::Label_h->implements.buffer = NULL;
            if (::hyve::define(QT::Label_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Label'.");
                goto error;
            }
        }
        /* Declare ::Qt::LineEdit::construct(::Qt::LineEdit object) */
        if (!(QT::LineEdit_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::LineEdit::construct(::Qt::LineEdit object)", "load: check if object '::Qt::LineEdit::construct(::Qt::LineEdit object)' already exists."))) {
            QT::LineEdit_construct_h = (::hyve::lang::callback)::hyve::declare(QT::LineEdit_h, "construct(::Qt::LineEdit object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::LineEdit_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineEdit::construct(::Qt::LineEdit object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineEdit_construct_h);
        }

        /* Define ::Qt::LineEdit::construct(::Qt::LineEdit object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineEdit_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::LineEdit_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::LineEdit_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::LineEdit_construct_h with C++ function */
            ((::hyve::lang::function)QT::LineEdit_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::LineEdit_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_LineEdit_construct);
            if (::hyve::define(QT::LineEdit_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineEdit::construct(::Qt::LineEdit object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::LineEdit::destruct(::Qt::LineEdit object) */
        if (!(QT::LineEdit_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::LineEdit::destruct(::Qt::LineEdit object)", "load: check if object '::Qt::LineEdit::destruct(::Qt::LineEdit object)' already exists."))) {
            QT::LineEdit_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::LineEdit_h, "destruct(::Qt::LineEdit object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::LineEdit_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineEdit::destruct(::Qt::LineEdit object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineEdit_destruct_h);
        }

        /* Define ::Qt::LineEdit::destruct(::Qt::LineEdit object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineEdit_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::LineEdit_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::LineEdit_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::LineEdit_destruct_h with C++ function */
            ((::hyve::lang::function)QT::LineEdit_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::LineEdit_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_LineEdit_destruct);
            if (::hyve::define(QT::LineEdit_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineEdit::destruct(::Qt::LineEdit object)'.");
                goto error;
            }
        }
        /* Define ::Qt::LineEdit */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineEdit_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::LineEdit_h)->parentType = NULL;
            ((::hyve::lang::type)QT::LineEdit_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::LineEdit_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::LineEdit_h)->baseAccess = 0x0;
            QT::LineEdit_h->implements.length = 0;
            QT::LineEdit_h->implements.buffer = NULL;
            if (::hyve::define(QT::LineEdit_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineEdit'.");
                goto error;
            }
        }
        /* Declare ::Qt::LineEdit::onSelf */
        if (!(QT::LineEdit_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::LineEdit::onSelf", "load: check if object '::Qt::LineEdit::onSelf' already exists."))) {
            QT::LineEdit_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::LineEdit_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::LineEdit_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::LineEdit::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::LineEdit_onSelf_h);
        }

        /* Define ::Qt::LineEdit::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::LineEdit_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::LineEdit_onSelf_h->observable = NULL;
            QT::LineEdit_onSelf_h->mask = 0xb0;
            QT::LineEdit_onSelf_h->expression = NULL;
            QT::LineEdit_onSelf_h->_template = 1;
            QT::LineEdit_onSelf_h->dispatcher = NULL;
            QT::LineEdit_onSelf_h->me = NULL;
            
            /* Bind QT::LineEdit_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::LineEdit_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::LineEdit_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_LineEdit_onSelf);
            if (::hyve::define(QT::LineEdit_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::LineEdit::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ListWidget::construct(::Qt::ListWidget object) */
        if (!(QT::ListWidget_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::construct(::Qt::ListWidget object)", "load: check if object '::Qt::ListWidget::construct(::Qt::ListWidget object)' already exists."))) {
            QT::ListWidget_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ListWidget_h, "construct(::Qt::ListWidget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ListWidget_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::construct(::Qt::ListWidget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_construct_h);
        }

        /* Define ::Qt::ListWidget::construct(::Qt::ListWidget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ListWidget_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ListWidget_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ListWidget_construct_h with C++ function */
            ((::hyve::lang::function)QT::ListWidget_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ListWidget_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ListWidget_construct);
            if (::hyve::define(QT::ListWidget_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::construct(::Qt::ListWidget object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ListWidget::destruct(::Qt::ListWidget object) */
        if (!(QT::ListWidget_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::destruct(::Qt::ListWidget object)", "load: check if object '::Qt::ListWidget::destruct(::Qt::ListWidget object)' already exists."))) {
            QT::ListWidget_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ListWidget_h, "destruct(::Qt::ListWidget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ListWidget_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::destruct(::Qt::ListWidget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_destruct_h);
        }

        /* Define ::Qt::ListWidget::destruct(::Qt::ListWidget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ListWidget_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ListWidget_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ListWidget_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ListWidget_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ListWidget_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ListWidget_destruct);
            if (::hyve::define(QT::ListWidget_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::destruct(::Qt::ListWidget object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ListWidget::insertItem(::hyve::lang::string label) */
        if (!(QT::ListWidget_insertItem_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::insertItem(::hyve::lang::string label)", "load: check if object '::Qt::ListWidget::insertItem(::hyve::lang::string label)' already exists."))) {
            QT::ListWidget_insertItem_h = (::hyve::lang::method)::hyve::declare(QT::ListWidget_h, "insertItem(::hyve::lang::string label)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::ListWidget_insertItem_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::insertItem(::hyve::lang::string label)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_insertItem_h);
        }

        /* Define ::Qt::ListWidget::insertItem(::hyve::lang::string label) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_insertItem_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ListWidget_insertItem_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ListWidget_insertItem_h->_virtual = FALSE;
            
            /* Bind QT::ListWidget_insertItem_h with C++ function */
            ((::hyve::lang::function)QT::ListWidget_insertItem_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ListWidget_insertItem_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ListWidget_insertItem);
            if (::hyve::define(QT::ListWidget_insertItem_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::insertItem(::hyve::lang::string label)'.");
                goto error;
            }
        }
        /* Define ::Qt::ListWidget */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ListWidget_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ListWidget_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ListWidget_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::ListWidget_h)->baseAccess = 0x0;
            QT::ListWidget_h->implements.length = 0;
            QT::ListWidget_h->implements.buffer = NULL;
            if (::hyve::define(QT::ListWidget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget'.");
                goto error;
            }
        }
        /* Declare ::Qt::ListWidget::onSelf */
        if (!(QT::ListWidget_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ListWidget::onSelf", "load: check if object '::Qt::ListWidget::onSelf' already exists."))) {
            QT::ListWidget_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::ListWidget_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ListWidget_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ListWidget::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ListWidget_onSelf_h);
        }

        /* Define ::Qt::ListWidget::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::ListWidget_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::ListWidget_onSelf_h->observable = NULL;
            QT::ListWidget_onSelf_h->mask = 0xb0;
            QT::ListWidget_onSelf_h->expression = NULL;
            QT::ListWidget_onSelf_h->_template = 1;
            QT::ListWidget_onSelf_h->dispatcher = NULL;
            QT::ListWidget_onSelf_h->me = NULL;
            
            /* Bind QT::ListWidget_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::ListWidget_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ListWidget_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ListWidget_onSelf);
            if (::hyve::define(QT::ListWidget_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ListWidget::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::MainWindow::construct(::Qt::MainWindow object) */
        if (!(QT::MainWindow_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::MainWindow::construct(::Qt::MainWindow object)", "load: check if object '::Qt::MainWindow::construct(::Qt::MainWindow object)' already exists."))) {
            QT::MainWindow_construct_h = (::hyve::lang::callback)::hyve::declare(QT::MainWindow_h, "construct(::Qt::MainWindow object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::MainWindow_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MainWindow::construct(::Qt::MainWindow object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MainWindow_construct_h);
        }

        /* Define ::Qt::MainWindow::construct(::Qt::MainWindow object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::MainWindow_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::MainWindow_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::MainWindow_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::MainWindow_construct_h with C++ function */
            ((::hyve::lang::function)QT::MainWindow_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::MainWindow_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_MainWindow_construct);
            if (::hyve::define(QT::MainWindow_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MainWindow::construct(::Qt::MainWindow object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::MainWindow::destruct(::Qt::MainWindow object) */
        if (!(QT::MainWindow_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::MainWindow::destruct(::Qt::MainWindow object)", "load: check if object '::Qt::MainWindow::destruct(::Qt::MainWindow object)' already exists."))) {
            QT::MainWindow_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::MainWindow_h, "destruct(::Qt::MainWindow object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::MainWindow_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MainWindow::destruct(::Qt::MainWindow object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MainWindow_destruct_h);
        }

        /* Define ::Qt::MainWindow::destruct(::Qt::MainWindow object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::MainWindow_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::MainWindow_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::MainWindow_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::MainWindow_destruct_h with C++ function */
            ((::hyve::lang::function)QT::MainWindow_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::MainWindow_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_MainWindow_destruct);
            if (::hyve::define(QT::MainWindow_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MainWindow::destruct(::Qt::MainWindow object)'.");
                goto error;
            }
        }
        /* Define ::Qt::MainWindow */
        if (!::hyve::checkState((::hyve::lang::object)QT::MainWindow_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::MainWindow_h)->parentType = NULL;
            ((::hyve::lang::type)QT::MainWindow_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::MainWindow_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::MainWindow_h)->baseAccess = 0x0;
            QT::MainWindow_h->implements.length = 0;
            QT::MainWindow_h->implements.buffer = NULL;
            if (::hyve::define(QT::MainWindow_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MainWindow'.");
                goto error;
            }
        }
        /* Declare ::Qt::MainWindow::onSelf */
        if (!(QT::MainWindow_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::MainWindow::onSelf", "load: check if object '::Qt::MainWindow::onSelf' already exists."))) {
            QT::MainWindow_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::MainWindow_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::MainWindow_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::MainWindow::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::MainWindow_onSelf_h);
        }

        /* Define ::Qt::MainWindow::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::MainWindow_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::MainWindow_onSelf_h->observable = NULL;
            QT::MainWindow_onSelf_h->mask = 0xb0;
            QT::MainWindow_onSelf_h->expression = NULL;
            QT::MainWindow_onSelf_h->_template = 1;
            QT::MainWindow_onSelf_h->dispatcher = NULL;
            QT::MainWindow_onSelf_h->me = NULL;
            
            /* Bind QT::MainWindow_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::MainWindow_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::MainWindow_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_MainWindow_onSelf);
            if (::hyve::define(QT::MainWindow_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::MainWindow::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object) */
        if (!(QT::ObjectBrowse_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object)", "load: check if object '::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object)' already exists."))) {
            QT::ObjectBrowse_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectBrowse_h, "construct(::Qt::ObjectBrowse object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectBrowse_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_construct_h);
        }

        /* Define ::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectBrowse_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ObjectBrowse_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ObjectBrowse_construct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectBrowse_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectBrowse_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectBrowse_construct);
            if (::hyve::define(QT::ObjectBrowse_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object) */
        if (!(QT::ObjectBrowse_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object)", "load: check if object '::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object)' already exists."))) {
            QT::ObjectBrowse_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectBrowse_h, "destruct(::Qt::ObjectBrowse object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectBrowse_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_destruct_h);
        }

        /* Define ::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectBrowse_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectBrowse_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ObjectBrowse_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectBrowse_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectBrowse_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectBrowse_destruct);
            if (::hyve::define(QT::ObjectBrowse_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::onDestruct */
        if (!(QT::ObjectBrowse_onDestruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::onDestruct", "load: check if object '::Qt::ObjectBrowse::onDestruct' already exists."))) {
            QT::ObjectBrowse_onDestruct_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectBrowse_h, "onDestruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectBrowse_onDestruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::onDestruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_onDestruct_h);
        }

        /* Define ::Qt::ObjectBrowse::onDestruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_onDestruct_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_onDestruct_h->observable = ((::hyve::lang::object)::hyve::resolve(NULL, "::"));
            QT::ObjectBrowse_onDestruct_h->mask = 0xe4;
            QT::ObjectBrowse_onDestruct_h->expression = NULL;
            QT::ObjectBrowse_onDestruct_h->_template = 2;
            QT::ObjectBrowse_onDestruct_h->dispatcher = NULL;
            QT::ObjectBrowse_onDestruct_h->me = NULL;
            
            /* Bind QT::ObjectBrowse_onDestruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectBrowse_onDestruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectBrowse_onDestruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectBrowse_onDestruct);
            if (::hyve::define(QT::ObjectBrowse_onDestruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::onDestruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::onSelf */
        if (!(QT::ObjectBrowse_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::onSelf", "load: check if object '::Qt::ObjectBrowse::onSelf' already exists."))) {
            QT::ObjectBrowse_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectBrowse_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectBrowse_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_onSelf_h);
        }

        /* Define ::Qt::ObjectBrowse::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_onSelf_h->observable = NULL;
            QT::ObjectBrowse_onSelf_h->mask = 0xb0;
            QT::ObjectBrowse_onSelf_h->expression = NULL;
            QT::ObjectBrowse_onSelf_h->_template = 3;
            QT::ObjectBrowse_onSelf_h->dispatcher = NULL;
            QT::ObjectBrowse_onSelf_h->me = NULL;
            
            /* Bind QT::ObjectBrowse_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::ObjectBrowse_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectBrowse_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectBrowse_onSelf);
            if (::hyve::define(QT::ObjectBrowse_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::onUpdate */
        if (!(QT::ObjectBrowse_onUpdate_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::onUpdate", "load: check if object '::Qt::ObjectBrowse::onUpdate' already exists."))) {
            QT::ObjectBrowse_onUpdate_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectBrowse_h, "onUpdate", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectBrowse_onUpdate_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::onUpdate'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_onUpdate_h);
        }

        /* Define ::Qt::ObjectBrowse::onUpdate */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_onUpdate_h, ::hyve::lang::DEFINED)) {
            QT::ObjectBrowse_onUpdate_h->observable = NULL;
            QT::ObjectBrowse_onUpdate_h->mask = 0xb0;
            QT::ObjectBrowse_onUpdate_h->expression = NULL;
            QT::ObjectBrowse_onUpdate_h->_template = 1;
            QT::ObjectBrowse_onUpdate_h->dispatcher = NULL;
            QT::ObjectBrowse_onUpdate_h->me = NULL;
            
            /* Bind QT::ObjectBrowse_onUpdate_h with C++ function */
            ((::hyve::lang::function)QT::ObjectBrowse_onUpdate_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectBrowse_onUpdate_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectBrowse_onUpdate);
            if (::hyve::define(QT::ObjectBrowse_onUpdate_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::onUpdate'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectBrowse::setObject(::hyve::lang::object object) */
        if (!(QT::ObjectBrowse_setObject_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::ObjectBrowse::setObject(::hyve::lang::object object)", "load: check if object '::Qt::ObjectBrowse::setObject(::hyve::lang::object object)' already exists."))) {
            QT::ObjectBrowse_setObject_h = (::hyve::lang::method)::hyve::declare(QT::ObjectBrowse_h, "setObject(::hyve::lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::ObjectBrowse_setObject_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectBrowse::setObject(::hyve::lang::object object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectBrowse_setObject_h);
        }

        /* Define ::Qt::ObjectBrowse::setObject(::hyve::lang::object object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_setObject_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectBrowse_setObject_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectBrowse_setObject_h->_virtual = FALSE;
            
            /* Bind QT::ObjectBrowse_setObject_h with C++ function */
            ((::hyve::lang::function)QT::ObjectBrowse_setObject_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectBrowse_setObject_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectBrowse_setObject);
            if (::hyve::define(QT::ObjectBrowse_setObject_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse::setObject(::hyve::lang::object object)'.");
                goto error;
            }
        }
        /* Define ::Qt::ObjectBrowse */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectBrowse_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ObjectBrowse_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ObjectBrowse_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ObjectBrowse_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::ObjectBrowse_h)->baseAccess = 0x0;
            QT::ObjectBrowse_h->implements.length = 0;
            QT::ObjectBrowse_h->implements.buffer = NULL;
            if (::hyve::define(QT::ObjectBrowse_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectBrowse'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::construct(::Qt::ObjectTree object) */
        if (!(QT::ObjectTree_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::construct(::Qt::ObjectTree object)", "load: check if object '::Qt::ObjectTree::construct(::Qt::ObjectTree object)' already exists."))) {
            QT::ObjectTree_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectTree_h, "construct(::Qt::ObjectTree object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectTree_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::construct(::Qt::ObjectTree object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_construct_h);
        }

        /* Define ::Qt::ObjectTree::construct(::Qt::ObjectTree object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectTree_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ObjectTree_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ObjectTree_construct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_construct);
            if (::hyve::define(QT::ObjectTree_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::construct(::Qt::ObjectTree object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::destruct(::Qt::ObjectTree object) */
        if (!(QT::ObjectTree_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::destruct(::Qt::ObjectTree object)", "load: check if object '::Qt::ObjectTree::destruct(::Qt::ObjectTree object)' already exists."))) {
            QT::ObjectTree_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectTree_h, "destruct(::Qt::ObjectTree object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectTree_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::destruct(::Qt::ObjectTree object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_destruct_h);
        }

        /* Define ::Qt::ObjectTree::destruct(::Qt::ObjectTree object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectTree_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectTree_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ObjectTree_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_destruct);
            if (::hyve::define(QT::ObjectTree_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::destruct(::Qt::ObjectTree object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::init(::Qt::ObjectTree object) */
        if (!(QT::ObjectTree_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::init(::Qt::ObjectTree object)", "load: check if object '::Qt::ObjectTree::init(::Qt::ObjectTree object)' already exists."))) {
            QT::ObjectTree_init_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectTree_h, "init(::Qt::ObjectTree object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectTree_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::init(::Qt::ObjectTree object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_init_h);
        }

        /* Define ::Qt::ObjectTree::init(::Qt::ObjectTree object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectTree_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ObjectTree_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::ObjectTree_init_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_init);
            if (::hyve::define(QT::ObjectTree_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::init(::Qt::ObjectTree object)'.");
                goto error;
            }
        }
        /* Define ::Qt::ObjectTree */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ObjectTree_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ObjectTree_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ObjectTree_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::ObjectTree_h)->baseAccess = 0x0;
            QT::ObjectTree_h->implements.length = 0;
            QT::ObjectTree_h->implements.buffer = NULL;
            if (::hyve::define(QT::ObjectTree_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::onConstruct */
        if (!(QT::ObjectTree_onConstruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::onConstruct", "load: check if object '::Qt::ObjectTree::onConstruct' already exists."))) {
            QT::ObjectTree_onConstruct_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectTree_h, "onConstruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectTree_onConstruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::onConstruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_onConstruct_h);
        }

        /* Define ::Qt::ObjectTree::onConstruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_onConstruct_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTree_onConstruct_h->observable = ((::hyve::lang::object)::hyve::resolve(NULL, "::"));
            QT::ObjectTree_onConstruct_h->mask = 0xe2;
            QT::ObjectTree_onConstruct_h->expression = NULL;
            QT::ObjectTree_onConstruct_h->_template = 2;
            QT::ObjectTree_onConstruct_h->dispatcher = NULL;
            QT::ObjectTree_onConstruct_h->me = NULL;
            
            /* Bind QT::ObjectTree_onConstruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_onConstruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_onConstruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_onConstruct);
            if (::hyve::define(QT::ObjectTree_onConstruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::onConstruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::onDestruct */
        if (!(QT::ObjectTree_onDestruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::onDestruct", "load: check if object '::Qt::ObjectTree::onDestruct' already exists."))) {
            QT::ObjectTree_onDestruct_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectTree_h, "onDestruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectTree_onDestruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::onDestruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_onDestruct_h);
        }

        /* Define ::Qt::ObjectTree::onDestruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_onDestruct_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTree_onDestruct_h->observable = ((::hyve::lang::object)::hyve::resolve(NULL, "::"));
            QT::ObjectTree_onDestruct_h->mask = 0xe4;
            QT::ObjectTree_onDestruct_h->expression = NULL;
            QT::ObjectTree_onDestruct_h->_template = 3;
            QT::ObjectTree_onDestruct_h->dispatcher = NULL;
            QT::ObjectTree_onDestruct_h->me = NULL;
            
            /* Bind QT::ObjectTree_onDestruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_onDestruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_onDestruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_onDestruct);
            if (::hyve::define(QT::ObjectTree_onDestruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::onDestruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::onNew */
        if (!(QT::ObjectTree_onNew_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::onNew", "load: check if object '::Qt::ObjectTree::onNew' already exists."))) {
            QT::ObjectTree_onNew_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectTree_h, "onNew", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectTree_onNew_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::onNew'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_onNew_h);
        }

        /* Define ::Qt::ObjectTree::onNew */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_onNew_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTree_onNew_h->observable = ((::hyve::lang::object)::hyve::resolve(NULL, "::"));
            QT::ObjectTree_onNew_h->mask = 0xe1;
            QT::ObjectTree_onNew_h->expression = NULL;
            QT::ObjectTree_onNew_h->_template = 1;
            QT::ObjectTree_onNew_h->dispatcher = NULL;
            QT::ObjectTree_onNew_h->me = NULL;
            
            /* Bind QT::ObjectTree_onNew_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_onNew_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_onNew_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_onNew);
            if (::hyve::define(QT::ObjectTree_onNew_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::onNew'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTree::onSelf */
        if (!(QT::ObjectTree_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectTree::onSelf", "load: check if object '::Qt::ObjectTree::onSelf' already exists."))) {
            QT::ObjectTree_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectTree_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectTree_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTree::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTree_onSelf_h);
        }

        /* Define ::Qt::ObjectTree::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTree_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTree_onSelf_h->observable = NULL;
            QT::ObjectTree_onSelf_h->mask = 0xb0;
            QT::ObjectTree_onSelf_h->expression = NULL;
            QT::ObjectTree_onSelf_h->_template = 4;
            QT::ObjectTree_onSelf_h->dispatcher = NULL;
            QT::ObjectTree_onSelf_h->me = NULL;
            
            /* Bind QT::ObjectTree_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTree_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTree_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTree_onSelf);
            if (::hyve::define(QT::ObjectTree_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTree::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::construct(::Qt::ObjectView object) */
        if (!(QT::ObjectView_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::construct(::Qt::ObjectView object)", "load: check if object '::Qt::ObjectView::construct(::Qt::ObjectView object)' already exists."))) {
            QT::ObjectView_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectView_h, "construct(::Qt::ObjectView object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectView_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::construct(::Qt::ObjectView object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_construct_h);
        }

        /* Define ::Qt::ObjectView::construct(::Qt::ObjectView object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectView_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ObjectView_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ObjectView_construct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_construct);
            if (::hyve::define(QT::ObjectView_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::construct(::Qt::ObjectView object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::destruct(::Qt::ObjectView object) */
        if (!(QT::ObjectView_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::destruct(::Qt::ObjectView object)", "load: check if object '::Qt::ObjectView::destruct(::Qt::ObjectView object)' already exists."))) {
            QT::ObjectView_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectView_h, "destruct(::Qt::ObjectView object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectView_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::destruct(::Qt::ObjectView object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_destruct_h);
        }

        /* Define ::Qt::ObjectView::destruct(::Qt::ObjectView object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectView_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectView_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ObjectView_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_destruct);
            if (::hyve::define(QT::ObjectView_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::destruct(::Qt::ObjectView object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::init(::Qt::ObjectView object) */
        if (!(QT::ObjectView_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::init(::Qt::ObjectView object)", "load: check if object '::Qt::ObjectView::init(::Qt::ObjectView object)' already exists."))) {
            QT::ObjectView_init_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectView_h, "init(::Qt::ObjectView object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectView_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::init(::Qt::ObjectView object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_init_h);
        }

        /* Define ::Qt::ObjectView::init(::Qt::ObjectView object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectView_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ObjectView_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::ObjectView_init_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_init);
            if (::hyve::define(QT::ObjectView_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::init(::Qt::ObjectView object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::onDestruct */
        if (!(QT::ObjectView_onDestruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::onDestruct", "load: check if object '::Qt::ObjectView::onDestruct' already exists."))) {
            QT::ObjectView_onDestruct_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectView_h, "onDestruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectView_onDestruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::onDestruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_onDestruct_h);
        }

        /* Define ::Qt::ObjectView::onDestruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_onDestruct_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_onDestruct_h->observable = NULL;
            QT::ObjectView_onDestruct_h->mask = 0xa4;
            QT::ObjectView_onDestruct_h->expression = NULL;
            QT::ObjectView_onDestruct_h->_template = 2;
            QT::ObjectView_onDestruct_h->dispatcher = NULL;
            QT::ObjectView_onDestruct_h->me = NULL;
            
            /* Bind QT::ObjectView_onDestruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_onDestruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_onDestruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_onDestruct);
            if (::hyve::define(QT::ObjectView_onDestruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::onDestruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::onSelf */
        if (!(QT::ObjectView_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::onSelf", "load: check if object '::Qt::ObjectView::onSelf' already exists."))) {
            QT::ObjectView_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectView_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectView_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_onSelf_h);
        }

        /* Define ::Qt::ObjectView::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_onSelf_h->observable = NULL;
            QT::ObjectView_onSelf_h->mask = 0xb0;
            QT::ObjectView_onSelf_h->expression = NULL;
            QT::ObjectView_onSelf_h->_template = 3;
            QT::ObjectView_onSelf_h->dispatcher = NULL;
            QT::ObjectView_onSelf_h->me = NULL;
            
            /* Bind QT::ObjectView_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_onSelf);
            if (::hyve::define(QT::ObjectView_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::onUpdate */
        if (!(QT::ObjectView_onUpdate_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::onUpdate", "load: check if object '::Qt::ObjectView::onUpdate' already exists."))) {
            QT::ObjectView_onUpdate_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectView_h, "onUpdate", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectView_onUpdate_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::onUpdate'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_onUpdate_h);
        }

        /* Define ::Qt::ObjectView::onUpdate */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_onUpdate_h, ::hyve::lang::DEFINED)) {
            QT::ObjectView_onUpdate_h->observable = NULL;
            QT::ObjectView_onUpdate_h->mask = 0xb0;
            QT::ObjectView_onUpdate_h->expression = NULL;
            QT::ObjectView_onUpdate_h->_template = 1;
            QT::ObjectView_onUpdate_h->dispatcher = NULL;
            QT::ObjectView_onUpdate_h->me = NULL;
            
            /* Bind QT::ObjectView_onUpdate_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_onUpdate_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_onUpdate_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_onUpdate);
            if (::hyve::define(QT::ObjectView_onUpdate_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::onUpdate'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::setObject(::hyve::lang::object object) */
        if (!(QT::ObjectView_setObject_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::setObject(::hyve::lang::object object)", "load: check if object '::Qt::ObjectView::setObject(::hyve::lang::object object)' already exists."))) {
            QT::ObjectView_setObject_h = (::hyve::lang::method)::hyve::declare(QT::ObjectView_h, "setObject(::hyve::lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::ObjectView_setObject_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::setObject(::hyve::lang::object object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_setObject_h);
        }

        /* Define ::Qt::ObjectView::setObject(::hyve::lang::object object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_setObject_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectView_setObject_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectView_setObject_h->_virtual = FALSE;
            
            /* Bind QT::ObjectView_setObject_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_setObject_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_setObject_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_setObject);
            if (::hyve::define(QT::ObjectView_setObject_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::setObject(::hyve::lang::object object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectView::updateObject() */
        if (!(QT::ObjectView_updateObject_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::ObjectView::updateObject()", "load: check if object '::Qt::ObjectView::updateObject()' already exists."))) {
            QT::ObjectView_updateObject_h = (::hyve::lang::method)::hyve::declare(QT::ObjectView_h, "updateObject()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::ObjectView_updateObject_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectView::updateObject()'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectView_updateObject_h);
        }

        /* Define ::Qt::ObjectView::updateObject() */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_updateObject_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectView_updateObject_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectView_updateObject_h->_virtual = FALSE;
            
            /* Bind QT::ObjectView_updateObject_h with C++ function */
            ((::hyve::lang::function)QT::ObjectView_updateObject_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectView_updateObject_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectView_updateObject);
            if (::hyve::define(QT::ObjectView_updateObject_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView::updateObject()'.");
                goto error;
            }
        }
        /* Define ::Qt::ObjectView */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectView_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ObjectView_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ObjectView_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ObjectView_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::ObjectView_h)->baseAccess = 0x0;
            QT::ObjectView_h->implements.length = 0;
            QT::ObjectView_h->implements.buffer = NULL;
            if (::hyve::define(QT::ObjectView_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectView'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::construct(::Qt::ProgressBar object) */
        if (!(QT::ProgressBar_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::construct(::Qt::ProgressBar object)", "load: check if object '::Qt::ProgressBar::construct(::Qt::ProgressBar object)' already exists."))) {
            QT::ProgressBar_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ProgressBar_h, "construct(::Qt::ProgressBar object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ProgressBar_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::construct(::Qt::ProgressBar object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_construct_h);
        }

        /* Define ::Qt::ProgressBar::construct(::Qt::ProgressBar object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ProgressBar_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ProgressBar_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ProgressBar_construct_h with C++ function */
            ((::hyve::lang::function)QT::ProgressBar_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ProgressBar_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ProgressBar_construct);
            if (::hyve::define(QT::ProgressBar_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::construct(::Qt::ProgressBar object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::destruct(::Qt::ProgressBar object) */
        if (!(QT::ProgressBar_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::destruct(::Qt::ProgressBar object)", "load: check if object '::Qt::ProgressBar::destruct(::Qt::ProgressBar object)' already exists."))) {
            QT::ProgressBar_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ProgressBar_h, "destruct(::Qt::ProgressBar object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ProgressBar_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::destruct(::Qt::ProgressBar object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_destruct_h);
        }

        /* Define ::Qt::ProgressBar::destruct(::Qt::ProgressBar object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ProgressBar_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ProgressBar_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ProgressBar_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ProgressBar_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ProgressBar_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ProgressBar_destruct);
            if (::hyve::define(QT::ProgressBar_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::destruct(::Qt::ProgressBar object)'.");
                goto error;
            }
        }
        /* Define ::Qt::ProgressBar */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ProgressBar_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ProgressBar_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ProgressBar_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::ProgressBar_h)->baseAccess = 0x0;
            QT::ProgressBar_h->implements.length = 0;
            QT::ProgressBar_h->implements.buffer = NULL;
            if (::hyve::define(QT::ProgressBar_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar'.");
                goto error;
            }
        }
        /* Declare ::Qt::ProgressBar::onSelf */
        if (!(QT::ProgressBar_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ProgressBar::onSelf", "load: check if object '::Qt::ProgressBar::onSelf' already exists."))) {
            QT::ProgressBar_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::ProgressBar_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ProgressBar_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ProgressBar::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ProgressBar_onSelf_h);
        }

        /* Define ::Qt::ProgressBar::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::ProgressBar_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::ProgressBar_onSelf_h->observable = NULL;
            QT::ProgressBar_onSelf_h->mask = 0xb0;
            QT::ProgressBar_onSelf_h->expression = NULL;
            QT::ProgressBar_onSelf_h->_template = 1;
            QT::ProgressBar_onSelf_h->dispatcher = NULL;
            QT::ProgressBar_onSelf_h->me = NULL;
            
            /* Bind QT::ProgressBar_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::ProgressBar_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ProgressBar_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ProgressBar_onSelf);
            if (::hyve::define(QT::ProgressBar_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ProgressBar::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::construct(::Qt::Slider object) */
        if (!(QT::Slider_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Slider::construct(::Qt::Slider object)", "load: check if object '::Qt::Slider::construct(::Qt::Slider object)' already exists."))) {
            QT::Slider_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Slider_h, "construct(::Qt::Slider object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Slider_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::construct(::Qt::Slider object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_construct_h);
        }

        /* Define ::Qt::Slider::construct(::Qt::Slider object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Slider_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Slider_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Slider_construct_h with C++ function */
            ((::hyve::lang::function)QT::Slider_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Slider_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Slider_construct);
            if (::hyve::define(QT::Slider_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::construct(::Qt::Slider object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::destruct(::Qt::Slider object) */
        if (!(QT::Slider_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Slider::destruct(::Qt::Slider object)", "load: check if object '::Qt::Slider::destruct(::Qt::Slider object)' already exists."))) {
            QT::Slider_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Slider_h, "destruct(::Qt::Slider object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Slider_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::destruct(::Qt::Slider object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_destruct_h);
        }

        /* Define ::Qt::Slider::destruct(::Qt::Slider object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Slider_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Slider_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Slider_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Slider_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Slider_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Slider_destruct);
            if (::hyve::define(QT::Slider_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::destruct(::Qt::Slider object)'.");
                goto error;
            }
        }
        /* Define ::Qt::Slider */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Slider_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Slider_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Slider_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::Slider_h)->baseAccess = 0x0;
            QT::Slider_h->implements.length = 0;
            QT::Slider_h->implements.buffer = NULL;
            if (::hyve::define(QT::Slider_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider'.");
                goto error;
            }
        }
        /* Declare ::Qt::Slider::onSelf */
        if (!(QT::Slider_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::Slider::onSelf", "load: check if object '::Qt::Slider::onSelf' already exists."))) {
            QT::Slider_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::Slider_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::Slider_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Slider::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Slider_onSelf_h);
        }

        /* Define ::Qt::Slider::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::Slider_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::Slider_onSelf_h->observable = NULL;
            QT::Slider_onSelf_h->mask = 0xb0;
            QT::Slider_onSelf_h->expression = NULL;
            QT::Slider_onSelf_h->_template = 1;
            QT::Slider_onSelf_h->dispatcher = NULL;
            QT::Slider_onSelf_h->me = NULL;
            
            /* Bind QT::Slider_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::Slider_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Slider_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Slider_onSelf);
            if (::hyve::define(QT::Slider_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Slider::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::Splitter::construct(::Qt::Splitter object) */
        if (!(QT::Splitter_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Splitter::construct(::Qt::Splitter object)", "load: check if object '::Qt::Splitter::construct(::Qt::Splitter object)' already exists."))) {
            QT::Splitter_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Splitter_h, "construct(::Qt::Splitter object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Splitter_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter::construct(::Qt::Splitter object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_construct_h);
        }

        /* Define ::Qt::Splitter::construct(::Qt::Splitter object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Splitter_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Splitter_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Splitter_construct_h with C++ function */
            ((::hyve::lang::function)QT::Splitter_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Splitter_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Splitter_construct);
            if (::hyve::define(QT::Splitter_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter::construct(::Qt::Splitter object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Splitter::destruct(::Qt::Splitter object) */
        if (!(QT::Splitter_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Splitter::destruct(::Qt::Splitter object)", "load: check if object '::Qt::Splitter::destruct(::Qt::Splitter object)' already exists."))) {
            QT::Splitter_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Splitter_h, "destruct(::Qt::Splitter object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Splitter_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter::destruct(::Qt::Splitter object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_destruct_h);
        }

        /* Define ::Qt::Splitter::destruct(::Qt::Splitter object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Splitter_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Splitter_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Splitter_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Splitter_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Splitter_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Splitter_destruct);
            if (::hyve::define(QT::Splitter_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter::destruct(::Qt::Splitter object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Splitter::init(::Qt::Splitter object) */
        if (!(QT::Splitter_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Splitter::init(::Qt::Splitter object)", "load: check if object '::Qt::Splitter::init(::Qt::Splitter object)' already exists."))) {
            QT::Splitter_init_h = (::hyve::lang::callback)::hyve::declare(QT::Splitter_h, "init(::Qt::Splitter object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Splitter_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter::init(::Qt::Splitter object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_init_h);
        }

        /* Define ::Qt::Splitter::init(::Qt::Splitter object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Splitter_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Splitter_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::Splitter_init_h with C++ function */
            ((::hyve::lang::function)QT::Splitter_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Splitter_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Splitter_init);
            if (::hyve::define(QT::Splitter_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter::init(::Qt::Splitter object)'.");
                goto error;
            }
        }
        /* Define ::Qt::Splitter */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Splitter_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Splitter_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Splitter_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::Splitter_h)->baseAccess = 0x0;
            QT::Splitter_h->implements.length = 0;
            QT::Splitter_h->implements.buffer = NULL;
            if (::hyve::define(QT::Splitter_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter'.");
                goto error;
            }
        }
        /* Declare ::Qt::Splitter::onSelf */
        if (!(QT::Splitter_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::Splitter::onSelf", "load: check if object '::Qt::Splitter::onSelf' already exists."))) {
            QT::Splitter_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::Splitter_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::Splitter_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Splitter::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Splitter_onSelf_h);
        }

        /* Define ::Qt::Splitter::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::Splitter_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::Splitter_onSelf_h->observable = NULL;
            QT::Splitter_onSelf_h->mask = 0xb0;
            QT::Splitter_onSelf_h->expression = NULL;
            QT::Splitter_onSelf_h->_template = 1;
            QT::Splitter_onSelf_h->dispatcher = NULL;
            QT::Splitter_onSelf_h->me = NULL;
            
            /* Bind QT::Splitter_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::Splitter_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Splitter_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Splitter_onSelf);
            if (::hyve::define(QT::Splitter_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Splitter::onSelf'.");
                goto error;
            }
        }
        /* Define ::Qt::SplitterItem::widget */
        if (!::hyve::checkState((::hyve::lang::object)QT::SplitterItem_widget_h, ::hyve::lang::DEFINED)) {
            QT::SplitterItem_widget_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Widget"));
            QT::SplitterItem_widget_h->modifiers = 0x0;
            QT::SplitterItem_widget_h->state = 0x6;
            QT::SplitterItem_widget_h->weak = FALSE;
            QT::SplitterItem_widget_h->id = 0;
            if (::hyve::define(QT::SplitterItem_widget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::SplitterItem::widget'.");
                goto error;
            }
        }
        /* Define ::Qt::SplitterItem */
        if (!::hyve::checkState((::hyve::lang::object)QT::SplitterItem_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::SplitterItem_h)->parentType = NULL;
            ((::hyve::lang::type)QT::SplitterItem_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::SplitterItem_h)->base = NULL;
            QT::SplitterItem_h->baseAccess = 0x0;
            if (::hyve::define(QT::SplitterItem_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::SplitterItem'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget) */
        if (!(QT::TabWidget_addTab_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget)", "load: check if object '::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget)' already exists."))) {
            QT::TabWidget_addTab_h = (::hyve::lang::method)::hyve::declare(QT::TabWidget_h, "addTab(::hyve::lang::string label,::Qt::Widget widget)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::TabWidget_addTab_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_addTab_h);
        }

        /* Define ::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget) */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_addTab_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::TabWidget_addTab_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::TabWidget_addTab_h->_virtual = FALSE;
            
            /* Bind QT::TabWidget_addTab_h with C++ function */
            ((::hyve::lang::function)QT::TabWidget_addTab_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::TabWidget_addTab_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_TabWidget_addTab);
            if (::hyve::define(QT::TabWidget_addTab_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget)'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::construct(::Qt::TabWidget object) */
        if (!(QT::TabWidget_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::construct(::Qt::TabWidget object)", "load: check if object '::Qt::TabWidget::construct(::Qt::TabWidget object)' already exists."))) {
            QT::TabWidget_construct_h = (::hyve::lang::callback)::hyve::declare(QT::TabWidget_h, "construct(::Qt::TabWidget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::TabWidget_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::construct(::Qt::TabWidget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_construct_h);
        }

        /* Define ::Qt::TabWidget::construct(::Qt::TabWidget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::TabWidget_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::TabWidget_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::TabWidget_construct_h with C++ function */
            ((::hyve::lang::function)QT::TabWidget_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::TabWidget_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_TabWidget_construct);
            if (::hyve::define(QT::TabWidget_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::construct(::Qt::TabWidget object)'.");
                goto error;
            }
        }
        /* Define ::Qt::TabWidget::currentWidget */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_currentWidget_h, ::hyve::lang::DEFINED)) {
            QT::TabWidget_currentWidget_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Widget"));
            QT::TabWidget_currentWidget_h->modifiers = 0x0;
            QT::TabWidget_currentWidget_h->state = 0x6;
            QT::TabWidget_currentWidget_h->weak = FALSE;
            QT::TabWidget_currentWidget_h->id = 4;
            if (::hyve::define(QT::TabWidget_currentWidget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::currentWidget'.");
                goto error;
            }
        }
        /* Declare ::Qt::TabWidget::destruct(::Qt::TabWidget object) */
        if (!(QT::TabWidget_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::TabWidget::destruct(::Qt::TabWidget object)", "load: check if object '::Qt::TabWidget::destruct(::Qt::TabWidget object)' already exists."))) {
            QT::TabWidget_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::TabWidget_h, "destruct(::Qt::TabWidget object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::TabWidget_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::TabWidget::destruct(::Qt::TabWidget object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::TabWidget_destruct_h);
        }

        /* Define ::Qt::TabWidget::destruct(::Qt::TabWidget object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::TabWidget_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::TabWidget_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::TabWidget_destruct_h with C++ function */
            ((::hyve::lang::function)QT::TabWidget_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::TabWidget_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_TabWidget_destruct);
            if (::hyve::define(QT::TabWidget_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget::destruct(::Qt::TabWidget object)'.");
                goto error;
            }
        }
        /* Define ::Qt::TabWidget */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidget_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::TabWidget_h)->parentType = NULL;
            ((::hyve::lang::type)QT::TabWidget_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::TabWidget_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::TabWidget_h)->baseAccess = 0x0;
            QT::TabWidget_h->implements.length = 0;
            QT::TabWidget_h->implements.buffer = NULL;
            if (::hyve::define(QT::TabWidget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidget'.");
                goto error;
            }
        }
        /* Define ::Qt::TabWidgetTab::widget */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidgetTab_widget_h, ::hyve::lang::DEFINED)) {
            QT::TabWidgetTab_widget_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::Widget"));
            QT::TabWidgetTab_widget_h->modifiers = 0x0;
            QT::TabWidgetTab_widget_h->state = 0x6;
            QT::TabWidgetTab_widget_h->weak = FALSE;
            QT::TabWidgetTab_widget_h->id = 1;
            if (::hyve::define(QT::TabWidgetTab_widget_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidgetTab::widget'.");
                goto error;
            }
        }
        /* Define ::Qt::TabWidgetTab */
        if (!::hyve::checkState((::hyve::lang::object)QT::TabWidgetTab_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::TabWidgetTab_h)->parentType = NULL;
            ((::hyve::lang::type)QT::TabWidgetTab_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::TabWidgetTab_h)->base = NULL;
            QT::TabWidgetTab_h->baseAccess = 0x0;
            if (::hyve::define(QT::TabWidgetTab_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::TabWidgetTab'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::construct(::Qt::Tile object) */
        if (!(QT::Tile_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Tile::construct(::Qt::Tile object)", "load: check if object '::Qt::Tile::construct(::Qt::Tile object)' already exists."))) {
            QT::Tile_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Tile_h, "construct(::Qt::Tile object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Tile_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::construct(::Qt::Tile object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_construct_h);
        }

        /* Define ::Qt::Tile::construct(::Qt::Tile object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Tile_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Tile_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Tile_construct_h with C++ function */
            ((::hyve::lang::function)QT::Tile_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_construct);
            if (::hyve::define(QT::Tile_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::construct(::Qt::Tile object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::destruct(::Qt::Tile object) */
        if (!(QT::Tile_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Tile::destruct(::Qt::Tile object)", "load: check if object '::Qt::Tile::destruct(::Qt::Tile object)' already exists."))) {
            QT::Tile_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Tile_h, "destruct(::Qt::Tile object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Tile_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::destruct(::Qt::Tile object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_destruct_h);
        }

        /* Define ::Qt::Tile::destruct(::Qt::Tile object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Tile_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Tile_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Tile_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Tile_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_destruct);
            if (::hyve::define(QT::Tile_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::destruct(::Qt::Tile object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::init(::Qt::Tile object) */
        if (!(QT::Tile_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Tile::init(::Qt::Tile object)", "load: check if object '::Qt::Tile::init(::Qt::Tile object)' already exists."))) {
            QT::Tile_init_h = (::hyve::lang::callback)::hyve::declare(QT::Tile_h, "init(::Qt::Tile object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Tile_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::init(::Qt::Tile object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_init_h);
        }

        /* Define ::Qt::Tile::init(::Qt::Tile object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Tile_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Tile_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::Tile_init_h with C++ function */
            ((::hyve::lang::function)QT::Tile_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_init);
            if (::hyve::define(QT::Tile_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::init(::Qt::Tile object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::onDefine */
        if (!(QT::Tile_onDefine_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::Tile::onDefine", "load: check if object '::Qt::Tile::onDefine' already exists."))) {
            QT::Tile_onDefine_h = (::hyve::lang::observer)::hyve::declare(QT::Tile_h, "onDefine", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::Tile_onDefine_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::onDefine'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_onDefine_h);
        }

        /* Define ::Qt::Tile::onDefine */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_onDefine_h, ::hyve::lang::DEFINED)) {
            QT::Tile_onDefine_h->observable = NULL;
            QT::Tile_onDefine_h->mask = 0xc2;
            QT::Tile_onDefine_h->expression = NULL;
            QT::Tile_onDefine_h->_template = 2;
            QT::Tile_onDefine_h->dispatcher = NULL;
            QT::Tile_onDefine_h->me = NULL;
            
            /* Bind QT::Tile_onDefine_h with C++ function */
            ((::hyve::lang::function)QT::Tile_onDefine_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_onDefine_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_onDefine);
            if (::hyve::define(QT::Tile_onDefine_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::onDefine'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::onDestruct */
        if (!(QT::Tile_onDestruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::Tile::onDestruct", "load: check if object '::Qt::Tile::onDestruct' already exists."))) {
            QT::Tile_onDestruct_h = (::hyve::lang::observer)::hyve::declare(QT::Tile_h, "onDestruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::Tile_onDestruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::onDestruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_onDestruct_h);
        }

        /* Define ::Qt::Tile::onDestruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_onDestruct_h, ::hyve::lang::DEFINED)) {
            QT::Tile_onDestruct_h->observable = NULL;
            QT::Tile_onDestruct_h->mask = 0xc4;
            QT::Tile_onDestruct_h->expression = NULL;
            QT::Tile_onDestruct_h->_template = 3;
            QT::Tile_onDestruct_h->dispatcher = NULL;
            QT::Tile_onDestruct_h->me = NULL;
            
            /* Bind QT::Tile_onDestruct_h with C++ function */
            ((::hyve::lang::function)QT::Tile_onDestruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_onDestruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_onDestruct);
            if (::hyve::define(QT::Tile_onDestruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::onDestruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::onSelf */
        if (!(QT::Tile_onSelf_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::Tile::onSelf", "load: check if object '::Qt::Tile::onSelf' already exists."))) {
            QT::Tile_onSelf_h = (::hyve::lang::observer)::hyve::declare(QT::Tile_h, "onSelf", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::Tile_onSelf_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::onSelf'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_onSelf_h);
        }

        /* Define ::Qt::Tile::onSelf */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_onSelf_h, ::hyve::lang::DEFINED)) {
            QT::Tile_onSelf_h->observable = NULL;
            QT::Tile_onSelf_h->mask = 0xb0;
            QT::Tile_onSelf_h->expression = NULL;
            QT::Tile_onSelf_h->_template = 1;
            QT::Tile_onSelf_h->dispatcher = NULL;
            QT::Tile_onSelf_h->me = NULL;
            
            /* Bind QT::Tile_onSelf_h with C++ function */
            ((::hyve::lang::function)QT::Tile_onSelf_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_onSelf_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_onSelf);
            if (::hyve::define(QT::Tile_onSelf_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::onSelf'.");
                goto error;
            }
        }
        /* Declare ::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha) */
        if (!(QT::Tile_pulse_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)", "load: check if object '::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)' already exists."))) {
            QT::Tile_pulse_h = (::hyve::lang::method)::hyve::declare(QT::Tile_h, "pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::Tile_pulse_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Tile_pulse_h);
        }

        /* Define ::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_pulse_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Tile_pulse_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Tile_pulse_h->_virtual = FALSE;
            
            /* Bind QT::Tile_pulse_h with C++ function */
            ((::hyve::lang::function)QT::Tile_pulse_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Tile_pulse_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Tile_pulse);
            if (::hyve::define(QT::Tile_pulse_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)'.");
                goto error;
            }
        }
        /* Define ::Qt::Tile */
        if (!::hyve::checkState((::hyve::lang::object)QT::Tile_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Tile_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Tile_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Tile_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Widget"));
            ((::hyve::lang::_struct)QT::Tile_h)->baseAccess = 0x0;
            QT::Tile_h->implements.length = 0;
            QT::Tile_h->implements.buffer = NULL;
            if (::hyve::define(QT::Tile_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Tile'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile::construct(::Qt::ObjectTile object) */
        if (!(QT::ObjectTile_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::construct(::Qt::ObjectTile object)", "load: check if object '::Qt::ObjectTile::construct(::Qt::ObjectTile object)' already exists."))) {
            QT::ObjectTile_construct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectTile_h, "construct(::Qt::ObjectTile object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectTile_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::construct(::Qt::ObjectTile object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_construct_h);
        }

        /* Define ::Qt::ObjectTile::construct(::Qt::ObjectTile object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectTile_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::ObjectTile_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::ObjectTile_construct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTile_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTile_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTile_construct);
            if (::hyve::define(QT::ObjectTile_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::construct(::Qt::ObjectTile object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile::createTile(::hyve::lang::object obj) */
        if (!(QT::ObjectTile_createTile_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::createTile(::hyve::lang::object obj)", "load: check if object '::Qt::ObjectTile::createTile(::hyve::lang::object obj)' already exists."))) {
            QT::ObjectTile_createTile_h = (::hyve::lang::method)::hyve::declare(QT::ObjectTile_h, "createTile(::hyve::lang::object obj)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
            if (!QT::ObjectTile_createTile_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::createTile(::hyve::lang::object obj)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_createTile_h);
        }

        /* Define ::Qt::ObjectTile::createTile(::hyve::lang::object obj) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_createTile_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectTile_createTile_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::Qt::ObjectTile"));
            QT::ObjectTile_createTile_h->_virtual = TRUE;
            
            /* Bind QT::ObjectTile_createTile_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTile_createTile_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTile_createTile_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTile_createTile);
            if (::hyve::define(QT::ObjectTile_createTile_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::createTile(::hyve::lang::object obj)'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile::destruct(::Qt::ObjectTile object) */
        if (!(QT::ObjectTile_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::destruct(::Qt::ObjectTile object)", "load: check if object '::Qt::ObjectTile::destruct(::Qt::ObjectTile object)' already exists."))) {
            QT::ObjectTile_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::ObjectTile_h, "destruct(::Qt::ObjectTile object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::ObjectTile_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::destruct(::Qt::ObjectTile object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_destruct_h);
        }

        /* Define ::Qt::ObjectTile::destruct(::Qt::ObjectTile object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::ObjectTile_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::ObjectTile_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::ObjectTile_destruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTile_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTile_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTile_destruct);
            if (::hyve::define(QT::ObjectTile_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::destruct(::Qt::ObjectTile object)'.");
                goto error;
            }
        }
        /* Define ::Qt::ObjectTile */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::ObjectTile_h)->parentType = NULL;
            ((::hyve::lang::type)QT::ObjectTile_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::ObjectTile_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Tile"));
            ((::hyve::lang::_struct)QT::ObjectTile_h)->baseAccess = 0x0;
            QT::ObjectTile_h->implements.length = 0;
            QT::ObjectTile_h->implements.buffer = NULL;
            if (::hyve::define(QT::ObjectTile_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile::onDestruct */
        if (!(QT::ObjectTile_onDestruct_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::onDestruct", "load: check if object '::Qt::ObjectTile::onDestruct' already exists."))) {
            QT::ObjectTile_onDestruct_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectTile_h, "onDestruct", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectTile_onDestruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::onDestruct'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_onDestruct_h);
        }

        /* Define ::Qt::ObjectTile::onDestruct */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_onDestruct_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTile_onDestruct_h->observable = NULL;
            QT::ObjectTile_onDestruct_h->mask = 0xa4;
            QT::ObjectTile_onDestruct_h->expression = NULL;
            QT::ObjectTile_onDestruct_h->_template = 2;
            QT::ObjectTile_onDestruct_h->dispatcher = NULL;
            QT::ObjectTile_onDestruct_h->me = NULL;
            
            /* Bind QT::ObjectTile_onDestruct_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTile_onDestruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTile_onDestruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTile_onDestruct);
            if (::hyve::define(QT::ObjectTile_onDestruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::onDestruct'.");
                goto error;
            }
        }
        /* Declare ::Qt::ObjectTile::onNew */
        if (!(QT::ObjectTile_onNew_h = (::hyve::lang::observer)::hyve::resolve(NULL, NULL, "::Qt::ObjectTile::onNew", "load: check if object '::Qt::ObjectTile::onNew' already exists."))) {
            QT::ObjectTile_onNew_h = (::hyve::lang::observer)::hyve::declare(QT::ObjectTile_h, "onNew", ((::hyve::lang::_typedef)::hyve::lang::observer_h));
            if (!QT::ObjectTile_onNew_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::ObjectTile::onNew'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::ObjectTile_onNew_h);
        }

        /* Define ::Qt::ObjectTile::onNew */
        if (!::hyve::checkState((::hyve::lang::object)QT::ObjectTile_onNew_h, ::hyve::lang::DEFINED)) {
            QT::ObjectTile_onNew_h->observable = NULL;
            QT::ObjectTile_onNew_h->mask = 0xa1;
            QT::ObjectTile_onNew_h->expression = NULL;
            QT::ObjectTile_onNew_h->_template = 1;
            QT::ObjectTile_onNew_h->dispatcher = NULL;
            QT::ObjectTile_onNew_h->me = NULL;
            
            /* Bind QT::ObjectTile_onNew_h with C++ function */
            ((::hyve::lang::function)QT::ObjectTile_onNew_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::ObjectTile_onNew_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_ObjectTile_onNew);
            if (::hyve::define(QT::ObjectTile_onNew_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::ObjectTile::onNew'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application::construct(::Qt::Application object) */
        if (!(QT::Application_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Application::construct(::Qt::Application object)", "load: check if object '::Qt::Application::construct(::Qt::Application object)' already exists."))) {
            QT::Application_construct_h = (::hyve::lang::callback)::hyve::declare(QT::Application_h, "construct(::Qt::Application object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Application_construct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::construct(::Qt::Application object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_construct_h);
        }

        /* Define ::Qt::Application::construct(::Qt::Application object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_construct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Application_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Application_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
            
            /* Bind QT::Application_construct_h with C++ function */
            ((::hyve::lang::function)QT::Application_construct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Application_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Application_construct);
            if (::hyve::define(QT::Application_construct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::construct(::Qt::Application object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application::destruct(::Qt::Application object) */
        if (!(QT::Application_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Application::destruct(::Qt::Application object)", "load: check if object '::Qt::Application::destruct(::Qt::Application object)' already exists."))) {
            QT::Application_destruct_h = (::hyve::lang::callback)::hyve::declare(QT::Application_h, "destruct(::Qt::Application object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Application_destruct_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::destruct(::Qt::Application object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_destruct_h);
        }

        /* Define ::Qt::Application::destruct(::Qt::Application object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_destruct_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Application_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
            QT::Application_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
            
            /* Bind QT::Application_destruct_h with C++ function */
            ((::hyve::lang::function)QT::Application_destruct_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Application_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Application_destruct);
            if (::hyve::define(QT::Application_destruct_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::destruct(::Qt::Application object)'.");
                goto error;
            }
        }
        /* Declare ::Qt::Application::init(::Qt::Application object) */
        if (!(QT::Application_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::Qt::Application::init(::Qt::Application object)", "load: check if object '::Qt::Application::init(::Qt::Application object)' already exists."))) {
            QT::Application_init_h = (::hyve::lang::callback)::hyve::declare(QT::Application_h, "init(::Qt::Application object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
            if (!QT::Application_init_h) {
                ::hyve::error("Qt_load: failed to declare object '::Qt::Application::init(::Qt::Application object)'.");
                goto error;
            }
        } else {
            ::hyve::free(QT::Application_init_h);
        }

        /* Define ::Qt::Application::init(::Qt::Application object) */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_init_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::function)QT::Application_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
            QT::Application_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
            
            /* Bind QT::Application_init_h with C++ function */
            ((::hyve::lang::function)QT::Application_init_h)->kind = DB_PROCEDURE_CDECL;
            ((::hyve::lang::function)QT::Application_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_Application_init);
            if (::hyve::define(QT::Application_init_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application::init(::Qt::Application object)'.");
                goto error;
            }
        }
        /* Define ::Qt::Application */
        if (!::hyve::checkState((::hyve::lang::object)QT::Application_h, ::hyve::lang::DEFINED)) {
            ((::hyve::lang::type)QT::Application_h)->parentType = NULL;
            ((::hyve::lang::type)QT::Application_h)->parentState = 0x0;
            ((::hyve::lang::interface)QT::Application_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::Qt::Object"));
            ((::hyve::lang::_struct)QT::Application_h)->baseAccess = 0x0;
            QT::Application_h->implements.length = 1;
            QT::Application_h->implements.buffer = (::hyve::lang::interface*)::hyve::alloc(sizeof(::hyve::lang::interface));
            QT::Application_h->implements.buffer[0] = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::dispatcher"));
            if (::hyve::define(QT::Application_h)) {
                ::hyve::error("Qt_load: failed to define object '::Qt::Application'.");
                goto error;
            }
        }
        QT::AbstractButton_o = new ::hyve::lang::Class(QT::AbstractButton_h);
        QT::Application_o = new ::hyve::lang::Class(QT::Application_h);
        QT::Brush_o = new ::hyve::lang::Class(QT::Brush_h);
        QT::CheckBox_o = new ::hyve::lang::Class(QT::CheckBox_h);
        QT::ComboBox_o = new ::hyve::lang::Class(QT::ComboBox_h);
        QT::ConicalGradient_o = new ::hyve::lang::Class(QT::ConicalGradient_h);
        QT::CustomPlot_o = new ::hyve::lang::Class(QT::CustomPlot_h);
        QT::EnumComboBox_o = new ::hyve::lang::Class(QT::EnumComboBox_h);
        QT::Font_o = new ::hyve::lang::Class(QT::Font_h);
        QT::Gradient_o = new ::hyve::lang::Class(QT::Gradient_h);
        QT::GridLayout_o = new ::hyve::lang::Class(QT::GridLayout_h);
        QT::GroupBox_o = new ::hyve::lang::Class(QT::GroupBox_h);
        QT::inputEvent_t_o = new ::hyve::lang::Class(QT::inputEvent_t_h);
        QT::Label_o = new ::hyve::lang::Class(QT::Label_h);
        QT::LinearGradient_o = new ::hyve::lang::Class(QT::LinearGradient_h);
        QT::LineEdit_o = new ::hyve::lang::Class(QT::LineEdit_h);
        QT::ListWidget_o = new ::hyve::lang::Class(QT::ListWidget_h);
        QT::MainWindow_o = new ::hyve::lang::Class(QT::MainWindow_h);
        QT::mouseEvent_t_o = new ::hyve::lang::Class(QT::mouseEvent_t_h);
        QT::Object_o = new ::hyve::lang::Class(QT::Object_h);
        QT::ObjectBrowse_o = new ::hyve::lang::Class(QT::ObjectBrowse_h);
        QT::ObjectTile_o = new ::hyve::lang::Class(QT::ObjectTile_h);
        QT::ObjectTree_o = new ::hyve::lang::Class(QT::ObjectTree_h);
        QT::ObjectView_o = new ::hyve::lang::Class(QT::ObjectView_h);
        QT::PaintDevice_o = new ::hyve::lang::Interface(QT::PaintDevice_h);
        QT::Painter_o = new ::hyve::lang::Class(QT::Painter_h);
        QT::paintEvent_t_o = new ::hyve::lang::Class(QT::paintEvent_t_h);
        QT::Pen_o = new ::hyve::lang::Class(QT::Pen_h);
        QT::ProgressBar_o = new ::hyve::lang::Class(QT::ProgressBar_h);
        QT::PushButton_o = new ::hyve::lang::Class(QT::PushButton_h);
        QT::RadialGradient_o = new ::hyve::lang::Class(QT::RadialGradient_h);
        QT::RadioButton_o = new ::hyve::lang::Class(QT::RadioButton_h);
        QT::Slider_o = new ::hyve::lang::Class(QT::Slider_h);
        QT::slot_o = new ::hyve::lang::Class(QT::slot_h);
        QT::Splitter_o = new ::hyve::lang::Class(QT::Splitter_h);
        QT::TabWidget_o = new ::hyve::lang::Class(QT::TabWidget_h);
        QT::Tile_o = new ::hyve::lang::Class(QT::Tile_h);
        QT::Widget_o = new ::hyve::lang::Class(QT::Widget_h);
        hyve::onunload(unload, NULL);
        if (_a_) {
            ::hyve::free(NULL, _a_, "load: free temporary reference.");
        }

        return 0;
    error:
        return -1;
    }
}
