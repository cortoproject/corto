/* src/Qt/ObjectTileView.cpp
 *
 *  Generated on Nov 11 2013
 *    C++ implementationfile for ::Qt::ObjectTileView.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ObjectTileView.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Type.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "Qt/Application.hpp"
#include "Qt/Tile.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Dispatcher.hpp"

namespace QT {
	struct scopeWalk_t {
		ObjectTileView *_this;
		hyve::lang::object parent;
	};
};
/* $end */

namespace QT {
    
    // Constructor
    ObjectTileView::ObjectTileView(QT::PaintEvent_t *paintEvent,
            QT::MouseEvent_t *mousePressEvent,
            ::hyve::lang::int32 x,
            ::hyve::lang::int32 y,
            ::hyve::lang::int32 width,
            ::hyve::lang::int32 height,
            ::hyve::lang::_bool enabled,
            ::hyve::lang::_bool visible,
            ::hyve::lang::string styleSheet,
            QT::Tile *currentTile,
            QT::Tile *selectedTile,
            QT::Tile *rootTile,
            QT::PointF maxTileSize,
            QT::PointF minTileSize,
            ::hyve::lang::uint32 separation,
            ::hyve::lang::Object *root,
            ::hyve::lang::Type *tileType) : QT::TileView((QT::tileView)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ObjectTileView_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->currentTile(currentTile);
        this->selectedTile(selectedTile);
        this->rootTile(rootTile);
        this->maxTileSize(maxTileSize);
        this->minTileSize(minTileSize);
        this->separation(separation);
        this->root(root);
        this->tileType(tileType);
        this->define();
    }
    
    // Constructor (declare & define)
    ObjectTileView::ObjectTileView(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            QT::PaintEvent_t *paintEvent,
            QT::MouseEvent_t *mousePressEvent,
            ::hyve::lang::int32 x,
            ::hyve::lang::int32 y,
            ::hyve::lang::int32 width,
            ::hyve::lang::int32 height,
            ::hyve::lang::_bool enabled,
            ::hyve::lang::_bool visible,
            ::hyve::lang::string styleSheet,
            QT::Tile *currentTile,
            QT::Tile *selectedTile,
            QT::Tile *rootTile,
            QT::PointF maxTileSize,
            QT::PointF minTileSize,
            ::hyve::lang::uint32 separation,
            ::hyve::lang::Object *root,
            ::hyve::lang::Type *tileType) : QT::TileView((QT::tileView)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ObjectTileView_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->currentTile(currentTile);
        this->selectedTile(selectedTile);
        this->rootTile(rootTile);
        this->maxTileSize(maxTileSize);
        this->minTileSize(minTileSize);
        this->separation(separation);
        this->root(root);
        this->tileType(tileType);
        this->define();
    }
    
    // Construct from handle
    ObjectTileView::ObjectTileView(QT::objectTileView handle, bool owner) : QT::TileView((QT::tileView)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::objectTileView ObjectTileView::_handle() {
        return (QT::objectTileView)this->__handle;
    }
    
    // ::hyve::lang::object root
    ::hyve::lang::Object *ObjectTileView::root() {
        return new ::hyve::lang::Object(((QT::objectTileView)this->__handle)->root);
    }
    void ObjectTileView::root(::hyve::lang::Object *v) {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectTileView)this->__handle)->root, v->_handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectTileView)this->__handle)->root, NULL);
        }
    }
    
    // ::hyve::lang::type tileType
    ::hyve::lang::Type *ObjectTileView::tileType() {
        return new ::hyve::lang::Type(((QT::objectTileView)this->__handle)->tileType);
    }
    void ObjectTileView::tileType(::hyve::lang::Type *v) {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectTileView)this->__handle)->tileType, v->_handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectTileView)this->__handle)->tileType, NULL);
        }
    }
    
    /* ::Qt::ObjectTileView::construct(::Qt::ObjectTileView object) */
    ::hyve::lang::int16 ObjectTileView::construct(QT::ObjectTileView *object) {
    /* $begin(::Qt::ObjectTileView::construct(::Qt::ObjectTileView object)) */
		scopeWalk_t walkData;
		{
            hyve::lang::Observer observer(QT::ObjectTileView_onNew_h); // Create proxy for template observer
            hyve::lang::Observer onNew = QT::ObjectTileView_o->privateObserver(object, &observer);
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onNew.setDispatcher(&dispatcher);
        }
        {
            hyve::lang::Observer observer(QT::ObjectTileView_onDestruct_h); // Create proxy for template observer
            hyve::lang::Observer onDestruct = QT::ObjectTileView_o->privateObserver(object, &observer);
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onDestruct.setDispatcher(&dispatcher);
        }

        if (!object->_handle()->tileType) {
            hyve::set((void**)&object->_handle()->tileType, (hyve::lang::type)QT::ObjectTile_h);
        }

		walkData._this = object;
        walkData.parent = ((QT::tileView)object)->rootTile;
        hyve::scopeWalk(object->_handle()->root, ObjectTileView::scopeWalk, &walkData);

        return QT::TileView::construct(object);
    /* $end */
    }
    
    /* ::Qt::ObjectTileView::destruct(::Qt::ObjectTileView object) */
    ::hyve::lang::_void ObjectTileView::destruct(QT::ObjectTileView *object) {
    /* $begin(::Qt::ObjectTileView::destruct(::Qt::ObjectTileView object)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::ObjectTileView::init(::Qt::ObjectTileView object) */
    ::hyve::lang::int16 ObjectTileView::init(QT::ObjectTileView *object) {
    /* $begin(::Qt::ObjectTileView::init(::Qt::ObjectTileView object)) */
        return TileView::init(object);
    /* $end */
    }
    
    /* ::Qt::ObjectTileView::onDestruct */
    ::hyve::lang::_void ObjectTileView::onDestruct(::hyve::lang::Object *observable, ::hyve::lang::Object *source) {
    /* $begin(::Qt::ObjectTileView::onDestruct) */
        hyve::lang::object handle = source->_handle();
        QT::tile parentTile;

        if (hyve::parentof(handle) == this->_handle()->root) {
           parentTile = this->_handle()->_parent.rootTile;
        } else {
           parentTile = (QT::tile)this->findTile(hyve::parentof(handle));
        }

        if (parentTile && hyve::checkState(parentTile, hyve::DEFINED) && parentTile->children) {
            hyve::ll children(parentTile->children);
            QT::objectTile tile;

            tile = this->findTile(handle);

            if (tile) {
                if ((QT::tile)tile == this->_handle()->_parent.currentTile) {
                    hyve::set((void**)&this->_handle()->_parent.currentTile, tile->_parent.parent);
                }
                if ((QT::tile)tile == this->_handle()->_parent.selectedTile) {
                    hyve::set((void**)&this->_handle()->_parent.selectedTile, NULL);
                }

                children.remove(tile);
                hyve::free(tile);
            }
        }

        this->repaint();
    /* $end */
    }
    
    /* ::Qt::ObjectTileView::onNew */
    ::hyve::lang::_void ObjectTileView::onNew(::hyve::lang::Object *observable, ::hyve::lang::Object *source) {
    /* $begin(::Qt::ObjectTileView::onNew) */
        hyve::lang::object handle = source->_handle();
        QT::tile parentTile;

        /* Create objectTile */
        if (hyve::parentof(handle) == this->_handle()->root) {
           parentTile = this->_handle()->_parent.rootTile;
        } else {
           parentTile = (QT::tile)this->findTile(hyve::parentof(handle));
        }

        if (parentTile) {
            QT::objectTile t = (QT::objectTile)hyve::_new((hyve::lang::_typedef)this->_handle()->tileType);
            t->object = (hyve::lang::word)handle;
            t->_parent.parent = parentTile; hyve::keep(parentTile);
            hyve::define(t);
            if (!parentTile->children) {
                parentTile->children = hyve::ll::_new();
            }
            hyve::ll children(parentTile->children);
            children.insert(t);
        } else {
            hyve::id id;
            hyve::error("tile for parent '%s' not found", hyve::fullname(hyve::parentof(handle), id));
        }
        this->repaint();
    /* $end */
    }
    
    /* ::Qt::ObjectTileView::scope() */
    ::hyve::lang::Object ObjectTileView::scope() {
    /* $begin(::Qt::ObjectTileView::scope()) */
        return hyve::lang::Object((hyve::lang::object)((QT::objectTile)this->_handle()->_parent.currentTile)->object);
    /* $end */
    }
    
    /* ::Qt::ObjectTileView::selected() */
    ::hyve::lang::Object ObjectTileView::selected() {
    /* $begin(::Qt::ObjectTileView::selected()) */
        hyve::keep((hyve::lang::object)((QT::objectTile)this->_handle()->_parent.selectedTile)->object);
        return hyve::lang::Object((hyve::lang::object)((QT::objectTile)this->_handle()->_parent.selectedTile)->object);
    /* $end */
    }
    /* $begin($classfooter) */
    int ObjectTileView::scopeWalk(hyve::lang::object o, void* userData) {
		scopeWalk_t *data = (scopeWalk_t*)userData;
		scopeWalk_t walkData;

        /* Create objectTile */
        QT::objectTile t = (QT::objectTile)hyve::_new((hyve::lang::_typedef)data->_this->_handle()->tileType);
        t->object = (hyve::lang::word)o;
        ((QT::tile)t)->parent = (QT::tile)data->parent; hyve::keep(data->parent);
        hyve::define(t);
        hyve::ll children(data->parent);
        children.insert(t);
		
		/* Walk childs */
		walkData.parent = o;
		walkData._this = data->_this;
        hyve::scopeWalk(o, ObjectTileView::scopeWalk, &walkData);
		return 1;
    }

    struct findTile_t {
        hyve::lang::object o;
        QT::objectTile tile;
    };

    int ObjectTileView::tileWalk(void* o, void* userData) {
        QT::objectTile tile = (QT::objectTile)o;
        findTile_t *data = (findTile_t*)userData;

        if (hyve::checkState(o, hyve::DEFINED)) {
            if ((hyve::lang::object)tile->object == data->o)
                data->tile = (QT::objectTile)o;
            if (tile->_parent.children) {
                hyve::ll list(tile->_parent.children);
                list.walk(tileWalk, userData);
            }
        }
        return !data->tile;
    }

    QT::objectTile ObjectTileView::findTile(hyve::lang::object o) {
        findTile_t walkData;
        hyve::ll list(this->_handle()->_parent.rootTile->children);
        walkData.o = o;
        walkData.tile = NULL;
        if (hyve::checkState(this->_handle()->_parent.rootTile, hyve::DEFINED)) {
            list.walk(tileWalk, &walkData);
        }
        return walkData.tile;
    }

    /* $end */
}

