/* include/Qt/Painter.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Painter.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Painter_H
#define Qt_Painter_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"
namespace QT {
    class Pen;
    class Font;
    class Brush;
}

namespace QT {
    class Painter : public QT::Object {
        
        // Constructor (new,define)
        public: Painter(const QT::PaintDevice &device,
                const QT::Brush &brush,
                const QT::Pen &pen);
        
        // Scoped constructor (declare,define)
        public: Painter(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const QT::PaintDevice &device,
                const QT::Brush &brush,
                const QT::Pen &pen);
        
        // Handle constructor
        public: Painter(QT::painter handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::painter _handle() const;
        
        // ::Qt::Brush brush
        public: QT::Brush brush() const;
        public: void brush(const QT::Brush &v) const;
        
        // ::Qt::PaintDevice device
        public: QT::PaintDevice device() const;
        public: void device(const QT::PaintDevice &v) const;
        
        // ::Qt::Pen pen
        public: QT::Pen pen() const;
        public: void pen(const QT::Pen &v) const;
        
        // begin()
        public: ::hyve::lang::_void begin() const;
        
        // construct(::Qt::Painter object)
        public: static ::hyve::lang::int16 construct(const QT::Painter &object);
        
        // destruct(::Qt::Painter object)
        public: static ::hyve::lang::_void destruct(const QT::Painter &object);
        
        // drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)
        public: ::hyve::lang::_void drawEllipse(::hyve::lang::float64 x, ::hyve::lang::float64 y, ::hyve::lang::float64 r) const;
        
        // drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)
        public: ::hyve::lang::_void drawEllipse(::hyve::lang::int32 top, ::hyve::lang::int32 left, ::hyve::lang::int32 width, ::hyve::lang::int32 height) const;
        
        // drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)
        public: ::hyve::lang::_void drawEllipse(::hyve::lang::int32 x, ::hyve::lang::int32 y, ::hyve::lang::int32 r) const;
        
        // drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)
        public: ::hyve::lang::_void drawEllipse(QT::real top, QT::real left, QT::real width, QT::real height) const;
        
        // drawEllipse(::Qt::Rect rect)
        public: ::hyve::lang::_void drawEllipse(QT::Rect rect) const;
        
        // drawEllipse(::Qt::RectF rect)
        public: ::hyve::lang::_void drawEllipse(QT::RectF rect) const;
        
        // drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)
        public: ::hyve::lang::_void drawLine(::hyve::lang::int32 x1, ::hyve::lang::int32 y1, ::hyve::lang::int32 x2, ::hyve::lang::int32 y2) const;
        
        // drawLine(::Qt::Line line)
        public: ::hyve::lang::_void drawLine(QT::Line line) const;
        
        // drawLine(::Qt::LineF line)
        public: ::hyve::lang::_void drawLine(QT::LineF line) const;
        
        // drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)
        public: ::hyve::lang::_void drawLine(QT::real x1, QT::real y1, QT::real x2, QT::real y2) const;
        
        // drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)
        public: ::hyve::lang::_void drawLines(QT::Line_seq lines) const;
        
        // drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)
        public: ::hyve::lang::_void drawLines(QT::LineF_seq lines) const;
        
        // drawPoint(::Qt::Point point)
        public: ::hyve::lang::_void drawPoint(QT::Point point) const;
        
        // drawPoint(::Qt::PointF point)
        public: ::hyve::lang::_void drawPoint(QT::PointF point) const;
        
        // drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)
        public: ::hyve::lang::_void drawPoints(QT::Point_seq lines) const;
        
        // drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)
        public: ::hyve::lang::_void drawPoints(QT::PointF_seq lines) const;
        
        // drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)
        public: ::hyve::lang::_void drawRect(::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height) const;
        
        // drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)
        public: ::hyve::lang::_void drawRect(QT::real left, QT::real top, QT::real width, QT::real height) const;
        
        // drawRect(::Qt::Rect rect)
        public: ::hyve::lang::_void drawRect(QT::Rect rect) const;
        
        // drawRect(::Qt::RectF rect)
        public: ::hyve::lang::_void drawRect(QT::RectF rect) const;
        
        // drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)
        public: ::hyve::lang::_void drawRects(QT::Rect_seq rects) const;
        
        // drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)
        public: ::hyve::lang::_void drawRects(QT::RectF_seq rects) const;
        
        // drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)
        public: ::hyve::lang::_void drawRoundedRect(::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height, QT::real radius) const;
        
        // drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)
        public: ::hyve::lang::_void drawRoundedRect(::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height, QT::real xradius, QT::real yradius) const;
        
        // drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)
        public: ::hyve::lang::_void drawRoundedRect(QT::real left, QT::real top, QT::real width, QT::real height, QT::real radius) const;
        
        // drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)
        public: ::hyve::lang::_void drawRoundedRect(QT::real left, QT::real top, QT::real width, QT::real height, QT::real xradius, QT::real yradius) const;
        
        // drawRoundedRect(::Qt::Rect rect,::Qt::real radius)
        public: ::hyve::lang::_void drawRoundedRect(QT::Rect rect, QT::real radius) const;
        
        // drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)
        public: ::hyve::lang::_void drawRoundedRect(QT::Rect rect, QT::real xradius, QT::real yradius) const;
        
        // drawRoundedRect(::Qt::RectF rect,::Qt::real radius)
        public: ::hyve::lang::_void drawRoundedRect(QT::RectF rect, QT::real radius) const;
        
        // drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)
        public: ::hyve::lang::_void drawRoundedRect(QT::RectF rect, QT::real xradius, QT::real yradius) const;
        
        // drawText(::Qt::Point position,::hyve::lang::string text)
        public: ::hyve::lang::_void drawText(QT::Point position, ::hyve::lang::string text) const;
        
        // drawText(::Qt::PointF position,::hyve::lang::string text)
        public: ::hyve::lang::_void drawText(QT::PointF position, ::hyve::lang::string text) const;
        
        // drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)
        public: ::hyve::lang::_void drawText(QT::Rect position, QT::Alignment alignment, ::hyve::lang::string text) const;
        
        // drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)
        public: ::hyve::lang::_void drawText(QT::RectF position, QT::Alignment alignment, ::hyve::lang::string text) const;
        
        // end()
        public: ::hyve::lang::_void end() const;
        
        // restore()
        public: ::hyve::lang::_void restore() const;
        
        // save()
        public: ::hyve::lang::_void save() const;
        
        // scale(::Qt::real sx,::Qt::real sy)
        public: ::hyve::lang::_void scale(QT::real sx, QT::real sy) const;
        
        // setBrush(::Qt::Brush brush)
        public: ::hyve::lang::_void setBrush(const QT::Brush &brush) const;
        
        // setFont(::Qt::Font font)
        public: ::hyve::lang::_void setFont(const QT::Font &font) const;
        
        // setPen(::Qt::Pen pen)
        public: ::hyve::lang::_void setPen(const QT::Pen &pen) const;
        
        // translate(::hyve::lang::int32 x,::hyve::lang::int32 y)
        public: ::hyve::lang::_void translate(::hyve::lang::int32 x, ::hyve::lang::int32 y) const;
        
        // translate(::Qt::Point p)
        public: ::hyve::lang::_void translate(QT::Point p) const;
        
        // translate(::Qt::PointF p)
        public: ::hyve::lang::_void translate(QT::PointF p) const;
        
        // translate(::Qt::real x,::Qt::real y)
        public: ::hyve::lang::_void translate(QT::real x, QT::real y) const;
        
        // viewport()
        public: QT::Rect viewport() const;
    };
}

#endif

