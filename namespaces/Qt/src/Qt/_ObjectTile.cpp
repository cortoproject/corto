/* src/Qt/ObjectTile.cpp
 *
 *  Generated on Nov 11 2013
 *    C++ implementationfile for ::Qt::ObjectTile.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ObjectTile.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Painter.hpp"

/* $begin($header) */
#include "QPainter"
#include "stdio.h"
/* $end */

namespace QT {
    
    // Constructor
    ObjectTile::ObjectTile(::hyve::lang::string title,
            QT::Tile *parent) : QT::Tile((QT::tile)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ObjectTile_h);
        this->title(title);
        this->parent(parent);
        this->define();
    }
    
    // Constructor (declare & define)
    ObjectTile::ObjectTile(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            ::hyve::lang::string title,
            QT::Tile *parent) : QT::Tile((QT::tile)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ObjectTile_h);
        this->title(title);
        this->parent(parent);
        this->define();
    }
    
    // Construct from handle
    ObjectTile::ObjectTile(QT::objectTile handle, bool owner) : QT::Tile((QT::tile)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::objectTile ObjectTile::_handle() {
        return (QT::objectTile)this->__handle;
    }
    
    // ::hyve::lang::word object
    ::hyve::lang::word ObjectTile::object() {
        return ((QT::objectTile)this->__handle)->object;
    }
    void ObjectTile::object(::hyve::lang::word v) {
        ((QT::objectTile)this->__handle)->object = v;
    }
    
    /* ::Qt::ObjectTile::draw(::Qt::Painter p) */
    ::hyve::lang::_void ObjectTile::draw(QT::Painter *p) {
    /* $begin(::Qt::ObjectTile::draw(::Qt::Painter p)) */
        QPen pen;
        QFont font;
        QPainter* painter;
        QT::RectF textPos;
        QT::RectF size = this->size();
        hyve::lang::string heading, title;
        float factor;
        float fontSize;

        /* Temporary workaround for calling virtual methods */
        hyve::lang::Class tile_t((hyve::lang::_class)hyve::_typeof(this->_handle()));
        hyve::lang::Method getHeadingMethod = tile_t.resolveMethod("getHeading");
        hyve::call((hyve::lang::function)getHeadingMethod._handle(), &heading, this->_handle());

        hyve::lang::Method getTitleMethod = tile_t.resolveMethod("getTitle");
        hyve::call((hyve::lang::function)getTitleMethod._handle(), &title, this->_handle());

        pen.setColor(QColor(0x33, 0x33, 0x33,this->alpha()));
        pen.setWidth(1);
        painter = (QPainter*)p->qhandle();
        textPos = this->size();

        fontSize = 48;
        font.setPointSize(fontSize);
        painter->setFont(font);

        /* Draw title */
        factor = textPos.width / painter->fontMetrics().width(title);
        if ((factor < 1) || (factor > 1.25))
        {
            fontSize = font.pointSizeF() * factor * 0.85;
        }
        if (fontSize > 14) {
            fontSize = 14;
        }
        if (fontSize > (textPos.height * 0.2)) {
            fontSize = textPos.height * 0.2;
        }
        if (fontSize > 2) {
            font.setPointSizeF(fontSize);
            painter->setPen(pen);
            painter->setFont(font);
            textPos.top += fontSize * 0.5;
            p->drawText(textPos, QT::AlignCenter, title);

            /* Draw heading */
            fontSize *= 0.6;
            if (fontSize > 2) {
                font.setPointSizeF(fontSize);
                font.setBold(true);
                painter->setFont(font);
                pen.setColor(QColor(0xaa,0xaa,0xaa,this->alpha()));
                painter->setPen(pen);

                textPos.top -= fontSize * 2.5;
                p->drawText(textPos, QT::AlignCenter, heading);
            }
        }

        /* If object contains childs, draw three dots */
        if (hyve::scopeSize((hyve::lang::object)this->_handle()->object)) {
            hyve::lang::float32 x, y;
            QBrush brush(QColor(0x66, 0x66, 0x66, this->alpha()));
            pen.setColor(QColor(0,0,0,0));
            painter->setBrush(brush);
            painter->setPen(pen);
            y = this->size().top + this->size().height / 2 + fontSize * 3;
            x = this->size().left + this->size().width / 2;
            p->drawEllipse(x - 6.0, y, 2.0);
            p->drawEllipse(x, y, 2.0);
            p->drawEllipse(x + 6.0, y, 2.0);
        }
        hyve::dealloc(title);
        hyve::dealloc(heading);
    /* $end */
    }
    
    /* ::Qt::ObjectTile::getHeading() */
    ::hyve::lang::string ObjectTile::getHeading() {
    /* $begin(::Qt::ObjectTile::getHeading()) */
        return hyve::strdup(hyve::nameof(hyve::_typeof((hyve::lang::object)this->_handle()->object)));
    /* $end */
    }
    
    /* ::Qt::ObjectTile::getTitle() */
    ::hyve::lang::string ObjectTile::getTitle() {
    /* $begin(::Qt::ObjectTile::getTitle()) */
        return hyve::strdup(hyve::nameof((hyve::lang::object)this->_handle()->object));
    /* $end */
    }
}

