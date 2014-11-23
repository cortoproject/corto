/* include/Qt/TileView.hpp
 *
 *  Generated on Nov 11 2013
 *    C++ definitions for ::Qt::TileView.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_TileView_H
#define Qt_TileView_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QWidget"
#include "QPainter"
#include "QPaintEvent"
#include "QTimer"

namespace QT {
    class QTTileView : QWidget {
        Q_OBJECT
    public:
        QTTileView(QT::tileView widget, QWidget *parent);
        void startAnimation();
        void paintTiles(QPainter *painter, QRect drawArea);
        void paintTileSet(QPainter* painter, QRect drawArea, hyve::ll tileSet, QT::TileFadeKind fadeOut, bool setActivating);
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseDoubleClickEvent(QMouseEvent *event);
        void resizeEvent(QResizeEvent *);

    public slots:
        void timeout();

    private:
        QT::tileView widget;
        QPointF tileSize;
        QPoint tileCount;
        int activeTile;
        QTimer timer;
        float t;
        int scopeMove;
        QT::tile activatingTile;
    };
}
/* $end */

namespace QT {
    class TileView : public QT::Widget {
        
        // Constructor (new,define)
        public: TileView(QT::PaintEvent_t *paintEvent,
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
                ::hyve::lang::uint32 separation);
        
        // Scoped constructor (declare,define)
        public: TileView(::hyve::lang::Object *_parent,
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
                ::hyve::lang::uint32 separation);
        
        // Handle constructor
        public: TileView(QT::tileView handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::tileView _handle();
        
        // ::Qt::Tile currentTile
        public: QT::Tile *currentTile();
        public: void currentTile(QT::Tile *v);
        
        // ::Qt::PointF maxTileSize
        public: QT::PointF maxTileSize();
        public: void maxTileSize(QT::PointF v);
        
        // ::Qt::PointF minTileSize
        public: QT::PointF minTileSize();
        public: void minTileSize(QT::PointF v);
        
        // ::Qt::Tile rootTile
        public: QT::Tile *rootTile();
        public: void rootTile(QT::Tile *v);
        
        // ::Qt::Tile selectedTile
        public: QT::Tile *selectedTile();
        public: void selectedTile(QT::Tile *v);
        
        // ::hyve::lang::uint32 separation
        public: ::hyve::lang::uint32 separation();
        public: void separation(::hyve::lang::uint32 v);
        
        // clear()
        public: ::hyve::lang::_void clear();
        
        // construct(::Qt::TileView object)
        public: static ::hyve::lang::int16 construct(QT::TileView *object);
        
        // destruct(::Qt::TileView object)
        public: static ::hyve::lang::_void destruct(QT::TileView *object);
        
        // init(::Qt::TileView object)
        public: static ::hyve::lang::int16 init(QT::TileView *object);
        
        // repaint()
        public: ::hyve::lang::_void repaint();
    };
}

#endif

