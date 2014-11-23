/* src/Qt/Tile.cpp
 *
 *  Generated on Nov 11 2013
 *    C++ implementationfile for ::Qt::Tile.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Tile.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Painter.hpp"

/* $begin($header) */
#include "QPen"
#include "QBrush"
#include "QPainter"
#include "math.h"

float interpolate(float v1, float v2, float t) {
    return (1.0 - t) * v1 + t * v2;
}
/* $end */

namespace QT {
    
    // Constructor
    Tile::Tile(::hyve::lang::string title,
            QT::Tile *parent) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Tile_h);
        this->title(title);
        this->parent(parent);
        this->define();
    }
    
    // Constructor (declare & define)
    Tile::Tile(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            ::hyve::lang::string title,
            QT::Tile *parent) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Tile_h);
        this->title(title);
        this->parent(parent);
        this->define();
    }
    
    // Construct from handle
    Tile::Tile(QT::tile handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::tile Tile::_handle() {
        return (QT::tile)this->__handle;
    }
    
    // ::hyve::lang::string title
    ::hyve::lang::string Tile::title() {
        return ((QT::tile)this->__handle)->title;
    }
    void Tile::title(::hyve::lang::string v) {
        if (((QT::tile)this->__handle)->title) {
            hyve::dealloc(((QT::tile)this->__handle)->title);
        };
        ((QT::tile)this->__handle)->title = v ? hyve::strdup(v) : NULL;
    }
    
    // ::Qt::Tile parent
    QT::Tile *Tile::parent() {
        return new QT::Tile(((QT::tile)this->__handle)->parent);
    }
    void Tile::parent(QT::Tile *v) {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::tile)this->__handle)->parent, v->_handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::tile)this->__handle)->parent, NULL);
        }
    }
    
    // ::Qt::Color colorFrom
    QT::Color Tile::colorFrom() {
        return ((QT::tile)this->__handle)->colorFrom;
    }
    void Tile::colorFrom(QT::Color v) {
        ((QT::tile)this->__handle)->colorFrom = v;
    }
    
    // ::Qt::Color colorTo
    QT::Color Tile::colorTo() {
        return ((QT::tile)this->__handle)->colorTo;
    }
    void Tile::colorTo(QT::Color v) {
        ((QT::tile)this->__handle)->colorTo = v;
    }
    
    // ::Qt::RectF sizeFrom
    QT::RectF Tile::sizeFrom() {
        return ((QT::tile)this->__handle)->sizeFrom;
    }
    void Tile::sizeFrom(QT::RectF v) {
        ((QT::tile)this->__handle)->sizeFrom = v;
    }
    
    // ::Qt::RectF sizeTo
    QT::RectF Tile::sizeTo() {
        return ((QT::tile)this->__handle)->sizeTo;
    }
    void Tile::sizeTo(QT::RectF v) {
        ((QT::tile)this->__handle)->sizeTo = v;
    }
    
    // ::hyve::lang::float32 alphaFrom
    ::hyve::lang::float32 Tile::alphaFrom() {
        return ((QT::tile)this->__handle)->alphaFrom;
    }
    void Tile::alphaFrom(::hyve::lang::float32 v) {
        ((QT::tile)this->__handle)->alphaFrom = v;
    }
    
    // ::hyve::lang::float32 alphaTo
    ::hyve::lang::float32 Tile::alphaTo() {
        return ((QT::tile)this->__handle)->alphaTo;
    }
    void Tile::alphaTo(::hyve::lang::float32 v) {
        ((QT::tile)this->__handle)->alphaTo = v;
    }
    
    // <0x8dd62c8> children
    hyve::ll_h Tile::children() {
        return ((QT::tile)this->__handle)->children;
    }
    void Tile::children(hyve::ll_h v) {
        ((QT::tile)this->__handle)->children = v;
    }
    
    // ::hyve::lang::float32 t
    ::hyve::lang::float32 Tile::t() {
        return ((QT::tile)this->__handle)->t;
    }
    void Tile::t(::hyve::lang::float32 v) {
        ((QT::tile)this->__handle)->t = v;
    }
    
    /* ::Qt::Tile::addChild(::Qt::Tile child) */
    ::hyve::lang::_void Tile::addChild(QT::Tile *child) {
    /* $begin(::Qt::Tile::addChild(::Qt::Tile child)) */
        if (!this->children()) {
            this->children(hyve::ll::_new());
        }

        hyve::ll list(this->children());
        list.append(child->_handle());
        hyve::keep(child->_handle());

    /* $end */
    }
    
    /* ::Qt::Tile::alpha() */
    ::hyve::lang::float32 Tile::alpha() {
    /* $begin(::Qt::Tile::alpha()) */
        return interpolate(this->alphaFrom(), this->alphaTo(), this->t());
    /* $end */
    }
    
    /* ::Qt::Tile::color() */
    QT::Color Tile::color() {
    /* $begin(::Qt::Tile::color()) */
        QT::Color result;
        result.r = interpolate(this->colorFrom().r, this->colorTo().r, this->t());
        result.g = interpolate(this->colorFrom().g, this->colorTo().g, this->t());
        result.b = interpolate(this->colorFrom().b, this->colorTo().b, this->t());
        result.alpha = this->alpha();
        return result;
    /* $end */
    }
    
    /* ::Qt::Tile::draw(::Qt::Painter p) */
    ::hyve::lang::_void Tile::draw(QT::Painter *p) {
    /* $begin(::Qt::Tile::draw(::Qt::Painter p)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Tile::getColor(::Qt::TileFlags flags) */
    QT::Color Tile::getColor(QT::TileFlags flags) {
    /* $begin(::Qt::Tile::getColor(::Qt::TileFlags flags)) */
        QT::Color result;
        if (flags & QT::TileFlagsHover) {
            result.r = 0xbb;
            result.g = 0xdd;
            result.b = 0xdd;
            result.alpha = 0xff;
        } else {
            result.r = 0xdd;
            result.g = 0xdd;
            result.b = 0xdd;
            result.alpha = 0xff;
        }
        return result;
    /* $end */
    }
    
    /* ::Qt::Tile::removeChild(::Qt::Tile child) */
    ::hyve::lang::_void Tile::removeChild(QT::Tile *child) {
    /* $begin(::Qt::Tile::removeChild(::Qt::Tile child)) */
        if (this->_handle()->children) {
            hyve::ll list(this->_handle()->children);
            list.remove(child->_handle());
        }
    /* $end */
    }
    
    /* ::Qt::Tile::render(::Qt::Painter p,::hyve::lang::float32 t,::Qt::RectF size,::Qt::TileFlags flags,::Qt::TileFadeKind fade) */
    ::hyve::lang::_void Tile::render(QT::Painter *p, ::hyve::lang::float32 t, QT::RectF size, QT::TileFlags flags, QT::TileFadeKind fade) {
    /* $begin(::Qt::Tile::render(::Qt::Painter p,::hyve::lang::float32 t,::Qt::RectF size,::Qt::TileFlags flags,::Qt::TileFadeKind fade)) */
        hyve::lang::uint32 borderWidth;
        QT::Color colorTo;

        // Control animation
        if (!t) {
            this->sizeFrom(this->size());
            if (fade == QT::TileFadeOut) {
                this->alphaFrom(0xee);
                this->alphaTo(0);
            } else if (fade == QT::TileFadeInAndUp){
                this->sizeFrom(size);
                this->_handle()->sizeFrom.top -= 50;
                this->alphaFrom(0);
                this->alphaTo(0xee);
            } else if (fade == QT::TileFadeInAndDown){
                this->sizeFrom(size);
                this->_handle()->sizeFrom.top += 50;
                this->alphaFrom(0);
                this->alphaTo(0xee);
            } else {
                this->alphaFrom(this->alpha());
                this->alphaTo(0xee);
            }
            this->colorFrom(this->color());
        }
        this->t(t); // From this point on, values are interpolated according to the current frame

        /* Temporary workaround for calling virtual methods */
        hyve::lang::Class tile_t((hyve::lang::_class)hyve::_typeof(this->_handle()));
        hyve::lang::Method getColor = tile_t.resolveMethod("getColor");
        hyve::call((hyve::lang::function)getColor._handle(), &colorTo, this->_handle(), flags);
        this->colorTo(colorTo);

        this->sizeTo(size);

        // Create gradient brush
        QT::Color interpolated = this->color();
        QColor qinterPolated(interpolated.r, interpolated.g, interpolated.b, interpolated.alpha);

        hyve::lang::uint16 r, g, b;
        r = interpolated.r * 1.3; if (r > 255) r = 255;
        g = interpolated.g * 1.3; if (g > 255) g = 255;
        b = interpolated.b * 1.3; if (b > 255) b = 255;
        QColor qlight(r, g, b, interpolated.alpha);

        QLinearGradient grad(0,0,0,1);
        grad.setCoordinateMode(QGradient::ObjectBoundingMode);
        grad.setColorAt(0.0, QColor(0xee,0xee,0xee,this->alpha()));
        grad.setColorAt(0.1, qlight);
        if (flags & QT::TileFlagsHover) {
            grad.setColorAt(1, qinterPolated);
        } else {
            grad.setColorAt(1, qinterPolated);
        }
        QBrush brush(grad);

        // Grey pen
        borderWidth = this->size().width > this->size().height ? this->size().height : this->size().width;
        borderWidth *= 0.01;
        borderWidth += 2;

        QPen pen;
        pen.setColor(QColor(0xff,0xff,0xff,this->alpha()));
        pen.setWidth(borderWidth);

        // Set pen and brush, draw the rectangle
        QPainter *painter = (QPainter*)p->qhandle();
        painter->setPen(pen);
        painter->setBrush(brush);
        p->drawRoundedRect(this->size(), borderWidth*2);

        pen.setColor(QColor(qinterPolated.red()*0.9,qinterPolated.green()*0.9,qinterPolated.blue()*0.9,this->alpha()));
        pen.setWidth(1);
        brush.setColor(QColor(0,0,0,0));
        painter->setPen(pen);
        painter->setBrush(brush);
        p->drawRoundedRect(
                    this->size().left + borderWidth / 2+1, this->size().top + borderWidth / 2+1,
                    this->size().width - borderWidth-2, this->size().height - borderWidth-2, (float)borderWidth * 1.5);

        /* Temporary workaround for calling virtual methods */
        hyve::lang::Method drawMethod = tile_t.resolveMethod("draw");
        hyve::call((hyve::lang::function)drawMethod._handle(), NULL, this->_handle(), p->_handle(), t);

    /* $end */
    }
    
    /* ::Qt::Tile::size() */
    QT::RectF Tile::size() {
    /* $begin(::Qt::Tile::size()) */
        QT::RectF result;

        result.left = interpolate(this->sizeFrom().left, this->sizeTo().left, this->t());
        result.top = interpolate(this->sizeFrom().top, this->sizeTo().top, this->t());
        result.width = interpolate(this->sizeFrom().width, this->sizeTo().width, this->t());
        result.height = interpolate(this->sizeFrom().height, this->sizeTo().height, this->t());

        return result;
    /* $end */
    }
}

