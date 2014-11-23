/* src/Qt/Painter.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Painter.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Painter.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Font.hpp"
#include "Qt/Pen.hpp"
#include "Qt/PaintDevice.hpp"
#include "Qt/Brush.hpp"

/* $begin($header) */
#include "QPainter"
#include "QBrush"
#include "QFont"
/* $end */

namespace QT {
    
    // Constructor
    Painter::Painter(const QT::PaintDevice &device,
            const QT::Brush &brush,
            const QT::Pen &pen) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Painter_h);
        this->device(device);
        this->brush(brush);
        this->pen(pen);
        this->define();
    }
    
    // Constructor (declare & define)
    Painter::Painter(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            const QT::PaintDevice &device,
            const QT::Brush &brush,
            const QT::Pen &pen) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Painter_h);
        this->device(device);
        this->brush(brush);
        this->pen(pen);
        this->define();
    }
    
    // Construct from handle
    Painter::Painter(QT::painter handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::painter Painter::_handle() const {
        return (QT::painter)this->__handle;
    }
    
    // ::Qt::PaintDevice device
    QT::PaintDevice Painter::device() const {
        QT::PaintDevice result(((QT::painter)this->__handle)->device);
        return result;
    }
    void Painter::device(const QT::PaintDevice &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::painter)this->__handle)->device, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::painter)this->__handle)->device, NULL);
        }
    }
    
    // ::Qt::Brush brush
    QT::Brush Painter::brush() const {
        QT::Brush result(((QT::painter)this->__handle)->brush);
        return result;
    }
    void Painter::brush(const QT::Brush &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::painter)this->__handle)->brush, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::painter)this->__handle)->brush, NULL);
        }
    }
    
    // ::Qt::Pen pen
    QT::Pen Painter::pen() const {
        QT::Pen result(((QT::painter)this->__handle)->pen);
        return result;
    }
    void Painter::pen(const QT::Pen &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::painter)this->__handle)->pen, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::painter)this->__handle)->pen, NULL);
        }
    }
    
    /* ::Qt::Painter::begin() */
    ::hyve::lang::_void Painter::begin() const {
    /* $begin(::Qt::Painter::begin()) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::construct(::Qt::Painter object) */
    ::hyve::lang::int16 Painter::construct(const QT::Painter &object) {
    /* $begin(::Qt::Painter::construct(::Qt::Painter object)) */
        QPainter *painter;

        painter = new QPainter();
        object.qhandle((hyve::lang::word)painter);

        return 0;
    /* $end */
    }
    
    /* ::Qt::Painter::destruct(::Qt::Painter object) */
    ::hyve::lang::_void Painter::destruct(const QT::Painter &object) {
    /* $begin(::Qt::Painter::destruct(::Qt::Painter object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r) */
    ::hyve::lang::_void Painter::drawEllipse(::hyve::lang::float64 x, ::hyve::lang::float64 y, ::hyve::lang::float64 r) const {
    /* $begin(::Qt::Painter::drawEllipse(::hyve::lang::float64 x,::hyve::lang::float64 y,::hyve::lang::float64 r)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawEllipse(x-r,y-r,r*2,r*2);
    /* $end */
    }
    
    /* ::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height) */
    ::hyve::lang::_void Painter::drawEllipse(::hyve::lang::int32 top, ::hyve::lang::int32 left, ::hyve::lang::int32 width, ::hyve::lang::int32 height) const {
    /* $begin(::Qt::Painter::drawEllipse(::hyve::lang::int32 top,::hyve::lang::int32 left,::hyve::lang::int32 width,::hyve::lang::int32 height)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawEllipse(top,left,width,height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r) */
    ::hyve::lang::_void Painter::drawEllipse(::hyve::lang::int32 x, ::hyve::lang::int32 y, ::hyve::lang::int32 r) const {
    /* $begin(::Qt::Painter::drawEllipse(::hyve::lang::int32 x,::hyve::lang::int32 y,::hyve::lang::int32 r)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawEllipse(x-r,y-r,r*2,r*2);
    /* $end */
    }
    
    /* ::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height) */
    ::hyve::lang::_void Painter::drawEllipse(QT::real top, QT::real left, QT::real width, QT::real height) const {
    /* $begin(::Qt::Painter::drawEllipse(::Qt::real top,::Qt::real left,::Qt::real width,::Qt::real height)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawEllipse(top,left,width,height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawEllipse(::Qt::Rect rect) */
    ::hyve::lang::_void Painter::drawEllipse(QT::Rect rect) const {
    /* $begin(::Qt::Painter::drawEllipse(::Qt::Rect rect)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawEllipse(rect.left, rect.top, rect.width, rect.height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawEllipse(::Qt::RectF rect) */
    ::hyve::lang::_void Painter::drawEllipse(QT::RectF rect) const {
    /* $begin(::Qt::Painter::drawEllipse(::Qt::RectF rect)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawEllipse(rect.left, rect.top, rect.width, rect.height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2) */
    ::hyve::lang::_void Painter::drawLine(::hyve::lang::int32 x1, ::hyve::lang::int32 y1, ::hyve::lang::int32 x2, ::hyve::lang::int32 y2) const {
    /* $begin(::Qt::Painter::drawLine(::hyve::lang::int32 x1,::hyve::lang::int32 y1,::hyve::lang::int32 x2,::hyve::lang::int32 y2)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawLine(x1,y1,x2,y2);
    /* $end */
    }
    
    /* ::Qt::Painter::drawLine(::Qt::Line line) */
    ::hyve::lang::_void Painter::drawLine(QT::Line line) const {
    /* $begin(::Qt::Painter::drawLine(::Qt::Line line)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawLine(line.x1,line.y1,line.x2,line.y2);
    /* $end */
    }
    
    /* ::Qt::Painter::drawLine(::Qt::LineF line) */
    ::hyve::lang::_void Painter::drawLine(QT::LineF line) const {
    /* $begin(::Qt::Painter::drawLine(::Qt::LineF line)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawLine(line.x1,line.y1,line.x2,line.y2);
    /* $end */
    }
    
    /* ::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2) */
    ::hyve::lang::_void Painter::drawLine(QT::real x1, QT::real y1, QT::real x2, QT::real y2) const {
    /* $begin(::Qt::Painter::drawLine(::Qt::real x1,::Qt::real y1,::Qt::real x2,::Qt::real y2)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawLine(x1,y1,x2,y2);
    /* $end */
    }
    
    /* ::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines) */
    ::hyve::lang::_void Painter::drawLines(QT::Line_seq lines) const {
    /* $begin(::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::Line,0} lines)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines) */
    ::hyve::lang::_void Painter::drawLines(QT::LineF_seq lines) const {
    /* $begin(::Qt::Painter::drawLines(::hyve::lang::sequence{::Qt::LineF,0} lines)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawPoint(::Qt::Point point) */
    ::hyve::lang::_void Painter::drawPoint(QT::Point point) const {
    /* $begin(::Qt::Painter::drawPoint(::Qt::Point point)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawPoint(::Qt::PointF point) */
    ::hyve::lang::_void Painter::drawPoint(QT::PointF point) const {
    /* $begin(::Qt::Painter::drawPoint(::Qt::PointF point)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines) */
    ::hyve::lang::_void Painter::drawPoints(QT::Point_seq lines) const {
    /* $begin(::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::Point,0} lines)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines) */
    ::hyve::lang::_void Painter::drawPoints(QT::PointF_seq lines) const {
    /* $begin(::Qt::Painter::drawPoints(::hyve::lang::sequence{::Qt::PointF,0} lines)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height) */
    ::hyve::lang::_void Painter::drawRect(::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height) const {
    /* $begin(::Qt::Painter::drawRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRect(left, top, width, height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height) */
    ::hyve::lang::_void Painter::drawRect(QT::real left, QT::real top, QT::real width, QT::real height) const {
    /* $begin(::Qt::Painter::drawRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRect(left, top, width, height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRect(::Qt::Rect rect) */
    ::hyve::lang::_void Painter::drawRect(QT::Rect rect) const {
    /* $begin(::Qt::Painter::drawRect(::Qt::Rect rect)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRect(rect.left, rect.top, rect.width, rect.height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRect(::Qt::RectF rect) */
    ::hyve::lang::_void Painter::drawRect(QT::RectF rect) const {
    /* $begin(::Qt::Painter::drawRect(::Qt::RectF rect)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRect(rect.left, rect.top, rect.width, rect.height);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects) */
    ::hyve::lang::_void Painter::drawRects(QT::Rect_seq rects) const {
    /* $begin(::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::Rect,0} rects)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects) */
    ::hyve::lang::_void Painter::drawRects(QT::RectF_seq rects) const {
    /* $begin(::Qt::Painter::drawRects(::hyve::lang::sequence{::Qt::RectF,0} rects)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius) */
    ::hyve::lang::_void Painter::drawRoundedRect(::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height, QT::real radius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real radius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(left, top, width, height, radius, radius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius) */
    ::hyve::lang::_void Painter::drawRoundedRect(::hyve::lang::int32 left, ::hyve::lang::int32 top, ::hyve::lang::int32 width, ::hyve::lang::int32 height, QT::real xradius, QT::real yradius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::hyve::lang::int32 left,::hyve::lang::int32 top,::hyve::lang::int32 width,::hyve::lang::int32 height,::Qt::real xradius,::Qt::real yradius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(left, top, width, height, xradius, yradius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius) */
    ::hyve::lang::_void Painter::drawRoundedRect(QT::real left, QT::real top, QT::real width, QT::real height, QT::real radius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real radius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(left, top, width, height, radius, radius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius) */
    ::hyve::lang::_void Painter::drawRoundedRect(QT::real left, QT::real top, QT::real width, QT::real height, QT::real xradius, QT::real yradius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::Qt::real left,::Qt::real top,::Qt::real width,::Qt::real height,::Qt::real xradius,::Qt::real yradius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(left, top, width, height, xradius, yradius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius) */
    ::hyve::lang::_void Painter::drawRoundedRect(QT::Rect rect, QT::real radius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real radius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(rect.left, rect.top, rect.width, rect.height, radius, radius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius) */
    ::hyve::lang::_void Painter::drawRoundedRect(QT::Rect rect, QT::real xradius, QT::real yradius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::Qt::Rect rect,::Qt::real xradius,::Qt::real yradius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(rect.left, rect.top, rect.width, rect.height, xradius, yradius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius) */
    ::hyve::lang::_void Painter::drawRoundedRect(QT::RectF rect, QT::real radius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real radius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(rect.left, rect.top, rect.width, rect.height, radius, radius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius) */
    ::hyve::lang::_void Painter::drawRoundedRect(QT::RectF rect, QT::real xradius, QT::real yradius) const {
    /* $begin(::Qt::Painter::drawRoundedRect(::Qt::RectF rect,::Qt::real xradius,::Qt::real yradius)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawRoundedRect(rect.left, rect.top, rect.width, rect.height, xradius, yradius);
    /* $end */
    }
    
    /* ::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text) */
    ::hyve::lang::_void Painter::drawText(QT::Point position, ::hyve::lang::string text) const {
    /* $begin(::Qt::Painter::drawText(::Qt::Point position,::hyve::lang::string text)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawText(QPointF(position.x, position.y), text);
    /* $end */
    }
    
    /* ::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text) */
    ::hyve::lang::_void Painter::drawText(QT::PointF position, ::hyve::lang::string text) const {
    /* $begin(::Qt::Painter::drawText(::Qt::PointF position,::hyve::lang::string text)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawText(QPointF(position.x, position.y), text);
    /* $end */
    }
    
    /* ::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text) */
    ::hyve::lang::_void Painter::drawText(QT::Rect position, QT::Alignment alignment, ::hyve::lang::string text) const {
    /* $begin(::Qt::Painter::drawText(::Qt::Rect position,::Qt::Alignment alignment,::hyve::lang::string text)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawText(QRectF(position.left, position.top, position.width, position.height), (int)alignment, text);
    /* $end */
    }
    
    /* ::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text) */
    ::hyve::lang::_void Painter::drawText(QT::RectF position, QT::Alignment alignment, ::hyve::lang::string text) const {
    /* $begin(::Qt::Painter::drawText(::Qt::RectF position,::Qt::Alignment alignment,::hyve::lang::string text)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->drawText(QRectF(position.left, position.top, position.width, position.height), (int)alignment, text);
    /* $end */
    }
    
    /* ::Qt::Painter::end() */
    ::hyve::lang::_void Painter::end() const {
    /* $begin(::Qt::Painter::end()) */
        QPainter *painter;
        painter = (QPainter*)this->qhandle();
        painter->end();
    /* $end */
    }
    
    /* ::Qt::Painter::restore() */
    ::hyve::lang::_void Painter::restore() const {
    /* $begin(::Qt::Painter::restore()) */
        QPainter *painter;
        painter = (QPainter*)this->qhandle();
        painter->restore();
    /* $end */
    }
    
    /* ::Qt::Painter::save() */
    ::hyve::lang::_void Painter::save() const {
    /* $begin(::Qt::Painter::save()) */
        QPainter *painter;
        painter = (QPainter*)this->qhandle();
        painter->save();
    /* $end */
    }
    
    /* ::Qt::Painter::scale(::Qt::real sx,::Qt::real sy) */
    ::hyve::lang::_void Painter::scale(QT::real sx, QT::real sy) const {
    /* $begin(::Qt::Painter::scale(::Qt::real sx,::Qt::real sy)) */
        QPainter *painter;
        painter = (QPainter*)this->qhandle();
        painter->scale(sx, sy);
    /* $end */
    }
    
    /* ::Qt::Painter::setBrush(::Qt::Brush brush) */
    ::hyve::lang::_void Painter::setBrush(const QT::Brush &brush) const {
    /* $begin(::Qt::Painter::setBrush(::Qt::Brush brush)) */
        QPainter *painter;
        QBrush *qbrush;

        painter = (QPainter*)this->qhandle();
        qbrush = (QBrush*)brush.qhandle();
        painter->setBrush(*qbrush);
    /* $end */
    }
    
    /* ::Qt::Painter::setFont(::Qt::Font font) */
    ::hyve::lang::_void Painter::setFont(const QT::Font &font) const {
    /* $begin(::Qt::Painter::setFont(::Qt::Font font)) */
        QPainter *painter;
        QFont *qfont;

        painter = (QPainter*)this->qhandle();
        qfont = (QFont*)font.qhandle();
        painter->setFont(*qfont);
    /* $end */
    }
    
    /* ::Qt::Painter::setPen(::Qt::Pen pen) */
    ::hyve::lang::_void Painter::setPen(const QT::Pen &pen) const {
    /* $begin(::Qt::Painter::setPen(::Qt::Pen pen)) */
        QPainter *painter;
        QPen *qpen;

        painter = (QPainter*)this->qhandle();
        qpen = (QPen*)pen.qhandle();
        painter->setPen(*qpen);
    /* $end */
    }
    
    /* ::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y) */
    ::hyve::lang::_void Painter::translate(::hyve::lang::int32 x, ::hyve::lang::int32 y) const {
    /* $begin(::Qt::Painter::translate(::hyve::lang::int32 x,::hyve::lang::int32 y)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->translate(x,y);
    /* $end */
    }
    
    /* ::Qt::Painter::translate(::Qt::Point p) */
    ::hyve::lang::_void Painter::translate(QT::Point p) const {
    /* $begin(::Qt::Painter::translate(::Qt::Point p)) */
        QPainter *painter;
        painter = (QPainter*)this->qhandle();
        painter->translate(p.x,p.y);
    /* $end */
    }
    
    /* ::Qt::Painter::translate(::Qt::PointF p) */
    ::hyve::lang::_void Painter::translate(QT::PointF p) const {
    /* $begin(::Qt::Painter::translate(::Qt::PointF p)) */
        QPainter *painter;
        painter = (QPainter*)this->qhandle();
        painter->translate(p.x,p.y);
    /* $end */
    }
    
    /* ::Qt::Painter::translate(::Qt::real x,::Qt::real y) */
    ::hyve::lang::_void Painter::translate(QT::real x, QT::real y) const {
    /* $begin(::Qt::Painter::translate(::Qt::real x,::Qt::real y)) */
        QPainter *p;
        p = (QPainter*)this->qhandle();
        p->translate(x,y);
    /* $end */
    }
    
    /* ::Qt::Painter::viewport() */
    QT::Rect Painter::viewport() const {
    /* $begin(::Qt::Painter::viewport()) */
        QPainter *p;
        QT::Rect r;
        QRect qr;
        p = (QPainter*)this->qhandle();

        qr = p->viewport();
        r.left = qr.left();
        r.top = qr.top();
        r.width = qr.width();
        r.height = qr.height();
        return r;
    /* $end */
    }
}

