/* include/Qt/ObjectTileView.hpp
 *
 *  Generated on Nov 11 2013
 *    C++ definitions for ::Qt::ObjectTileView.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ObjectTileView_H
#define Qt_ObjectTileView_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/TileView.hpp"

namespace QT {
    class ObjectTileView : public QT::TileView {
        
        // Constructor (new,define)
        public: ObjectTileView(QT::PaintEvent_t *paintEvent,
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
                ::hyve::lang::Type *tileType);
        
        // Scoped constructor (declare,define)
        public: ObjectTileView(::hyve::lang::Object *_parent,
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
                ::hyve::lang::Type *tileType);
        
        // Handle constructor
        public: ObjectTileView(QT::objectTileView handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::objectTileView _handle();
        
        // ::hyve::lang::object root
        public: ::hyve::lang::Object *root();
        public: void root(::hyve::lang::Object *v);
        
        // ::hyve::lang::type tileType
        public: ::hyve::lang::Type *tileType();
        public: void tileType(::hyve::lang::Type *v);
        
        // construct(::Qt::ObjectTileView object)
        public: static ::hyve::lang::int16 construct(QT::ObjectTileView *object);
        
        // destruct(::Qt::ObjectTileView object)
        public: static ::hyve::lang::_void destruct(QT::ObjectTileView *object);
        
        // init(::Qt::ObjectTileView object)
        public: static ::hyve::lang::int16 init(QT::ObjectTileView *object);
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(::hyve::lang::Object *observable, ::hyve::lang::Object *source);
        
        // onNew
        public: ::hyve::lang::_void onNew(::hyve::lang::Object *observable, ::hyve::lang::Object *source);
        
        // scope()
        public: ::hyve::lang::Object scope();
        
        // selected()
        public: ::hyve::lang::Object selected();
        /* $begin($classfooter) */
        static int scopeWalk(hyve::lang::object o, void* userData);
        static int tileWalk(void* o, void* userData);
        QT::objectTile findTile(hyve::lang::object o);
        /* $end */
    };
}

#endif

