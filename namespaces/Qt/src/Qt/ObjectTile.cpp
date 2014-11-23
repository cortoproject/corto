/* src/Qt/ObjectTile.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ObjectTile.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ObjectTile.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "Qt/Application.hpp"
/* $end */

namespace QT {
    
    // Constructor
    ObjectTile::ObjectTile(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string title,
             QT::Color textColor,
             QT::Color foregroundColor,
             QT::Color backgroundColor,
             QT::TileMode mode,
             ::hyve::lang::string scope,
             ::hyve::lang::word scopeCache) : QT::Tile((QT::tile)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ObjectTile_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->title(title);
        this->textColor(textColor);
        this->foregroundColor(foregroundColor);
        this->backgroundColor(backgroundColor);
        this->mode(mode);
        this->scope(scope);
        this->scopeCache(scopeCache);
        this->define();
    }
    
    // Constructor (declare & define)
    ObjectTile::ObjectTile(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string title,
             QT::Color textColor,
             QT::Color foregroundColor,
             QT::Color backgroundColor,
             QT::TileMode mode,
             ::hyve::lang::string scope,
             ::hyve::lang::word scopeCache) : QT::Tile((QT::tile)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ObjectTile_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->title(title);
        this->textColor(textColor);
        this->foregroundColor(foregroundColor);
        this->backgroundColor(backgroundColor);
        this->mode(mode);
        this->scope(scope);
        this->scopeCache(scopeCache);
        this->define();
    }
    
    // Construct from handle
    ObjectTile::ObjectTile(QT::objectTile handle, bool owner) : QT::Tile((QT::tile)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::objectTile ObjectTile::_handle() const {
        return (QT::objectTile)this->__handle;
    }
    
    // ::hyve::lang::string scope
    ::hyve::lang::string ObjectTile::scope() const {
        return ((QT::objectTile)this->__handle)->scope;
    }
    void ObjectTile::scope( ::hyve::lang::string v) const {
        if (((QT::objectTile)this->__handle)->scope) {
            hyve::dealloc(((QT::objectTile)this->__handle)->scope);
        };
        ((QT::objectTile)this->__handle)->scope = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::word scopeCache
    ::hyve::lang::word ObjectTile::scopeCache() const {
        return ((QT::objectTile)this->__handle)->scopeCache;
    }
    void ObjectTile::scopeCache( ::hyve::lang::word v) const {
        ((QT::objectTile)this->__handle)->scopeCache = v;
    }
    
    /* ::Qt::ObjectTile::construct(::Qt::ObjectTile object) */
    ::hyve::lang::int16 ObjectTile::construct(const QT::ObjectTile &object) {
    /* $begin(::Qt::ObjectTile::construct(::Qt::ObjectTile object)) */
        hyve::lang::Observer onNew(QT::ObjectTile_onNew_h);
        hyve::lang::Observer onDestruct(QT::ObjectTile_onDestruct_h);
        hyve::id title;
        hyve::lang::word cache = (hyve::lang::word)hyve::resolve(::root_h, object.scope());
        hyve::free((hyve::lang::object)cache);
        hyve::lang::Object scope((hyve::lang::object)cache);

        if (!object.title()) {
            if (scope._handle() == ::root_h) {
                sprintf(title, "root");
            } else {
                sprintf(title, "%s %s", scope._typeof().nameof(), scope.nameof());
            }
            object.title(title);
        }

        hyve::lang::Dispatcher dispatcher(QT::app(),false);
        onNew.listen(scope, object);
        onNew.setDispatcher(dispatcher);

        onDestruct.listen(scope, object);
        onDestruct.setDispatcher(dispatcher);

        return Tile::construct(object);
    /* $end */
    }
    
    /* ::Qt::ObjectTile::createTile(::hyve::lang::object obj) */
    QT::ObjectTile ObjectTile::createTile_v(const ::hyve::lang::Object &obj) const {
    /* $begin(::Qt::ObjectTile::createTile(::hyve::lang::object obj)) */
        QT::objectTile tile;
        hyve::id namebuff;
        sprintf(namebuff, "tile_%s", obj.nameof());
        tile = (QT::objectTile)hyve::declare((hyve::lang::object)this->_handle(), namebuff, (hyve::lang::_typedef)QT::ObjectTile_h);
        return QT::ObjectTile(tile);
    /* $end */
    }
    
    /* virtual ::Qt::ObjectTile::createTile(::hyve::lang::object obj) */
    QT::ObjectTile ObjectTile::createTile(const ::hyve::lang::Object &obj) const {
        hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
        static hyve::lang::uint32 _actualMethodId;
        
        if (!_actualMethodId) {
            _actualMethodId = _type.resolveMethodId((hyve::lang::string)"createTile(::hyve::lang::object obj)");
        }
        hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
        QT::objectTile _result;
        ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,obj._handle());
        QT::ObjectTile __result(_result);
        return __result;
    }
    
    /* ::Qt::ObjectTile::destruct(::Qt::ObjectTile object) */
    ::hyve::lang::_void ObjectTile::destruct(const QT::ObjectTile &object) {
    /* $begin(::Qt::ObjectTile::destruct(::Qt::ObjectTile object)) */

        QT::Tile::destruct(object); // Call parent destructor

    /* $end */
    }
    
    /* ::Qt::ObjectTile::onDestruct */
    ::hyve::lang::_void ObjectTile::onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectTile::onDestruct) */

        // If scope of tile is destructed, destruct tile
        ((hyve::lang::Object*)this)->destruct();

    /* $end */
    }
    
    /* ::Qt::ObjectTile::onNew */
    ::hyve::lang::_void ObjectTile::onNew(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectTile::onNew) */
        QT::objectTile tile;
        bool createTile = true;

        // Prevent creating tiles for tiles as this would result in endless recursion
        if (hyve::instanceof((hyve::lang::_typedef)QT::ObjectTile_h, source._handle())) {
            createTile = false;
        }

        if (createTile) {
            hyve::id id;
            tile = this->createTile(source)._handle();
            tile->scope = hyve::strdup(source.fullname(id));
            hyve::define(tile);
        }

    /* $end */
    }
}

