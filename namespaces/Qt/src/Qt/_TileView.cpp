/* src/Qt/TileView.cpp
 *
 *  Generated on Nov 11 2013
 *    C++ implementationfile for ::Qt::TileView.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/TileView.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Tile.hpp"

/* $begin($header) */
#include "Qt/Painter.hpp"
#include "math.h"

namespace QT {
    QTTileView::QTTileView(QT::tileView widget, QWidget *parent) : QWidget(parent) {
        this->widget = widget;
        this->timer.setInterval(20);
        QObject::connect(&this->timer, SIGNAL(timeout()), this, SLOT(timeout()));
        t = 1.1;
        scopeMove = 0;
        activatingTile = NULL;
        activeTile = -1;
    }

    void QTTileView::timeout() {
        if (t >= 1.0) {
            this->timer.stop();
            t = 1.0;
            if (scopeMove && activatingTile) {
                hyve::set((void**)&this->widget->currentTile, activatingTile);
                activeTile = -1;
            }
            scopeMove = 0;
            activatingTile = NULL;
        }
        if (activatingTile && (activatingTile != this->widget->selectedTile)) {
            if (scopeMove != -1) {
                hyve::updateBegin(this->widget);
                hyve::set((void**)&this->widget->selectedTile, activatingTile);
                hyve::updateEnd(this->widget);
            }
        }
        if (scopeMove) {
            activeTile = -1;
        }
        this->repaint();
        t += 0.1;
    }

    void QTTileView::startAnimation() {
        if (t >= 1.1) {
            t = 0;
            scopeMove = 0;
        }
        this->timer.start();
    }

    void QTTileView::paintTileSet(QPainter *painter, QRect drawArea, hyve::ll tiles, QT::TileFadeKind fadeOut, bool setActivating) {
        int tileId = 0;
        int numTiles = hyve::ll(tiles).size();
        if (!numTiles) {
            return;
        }
        float surface = drawArea.width() * drawArea.height();
        float tileSurface = surface / numTiles;
        float sqrTileSurface = sqrt(tileSurface);

        drawArea.setWidth(drawArea.width() - widget->separation);
        drawArea.setHeight(drawArea.height() - widget->separation);
        tileCount.setX(drawArea.width() / sqrTileSurface);
        if (!tileCount.x()) {
            tileCount.setX(1);
        }
        tileCount.setY(numTiles / tileCount.x());
        if (numTiles % tileCount.x()) {
            tileCount.setY(tileCount.y() + 1);
        }
        tileSize.setX((float)drawArea.width() / (float)tileCount.x());
        tileSize.setY((float)drawArea.height() / (float)tileCount.y());
        if (tileSize.y() > tileSize.x()) {
            tileSize.setY(tileSize.x());
        }

        for(int y=0; y<tileCount.y(); y++) {
            for(int x=0; x<tileCount.x(); x++) {
                QT::Tile tile( (QT::tile)tiles.get(tileId) );
                QT::Painter p(widget->_parent.painter); p.qhandle((hyve::lang::word)painter);
                QT::RectF size;
                size.left = ceil(x*tileSize.x() + widget->separation);
                size.top = ceil(y*tileSize.y() + widget->separation);
                size.width = ceil(tileSize.x() - widget->separation);
                size.height = ceil(tileSize.y() - widget->separation);

                if (activeTile == tileId) {
                    tile.render(&p, this->t, size, QT::TileFlagsHover, fadeOut);
                    if (setActivating) {
                        activatingTile = tile._handle();
                    }
                } else {
                    tile.render(&p, this->t, size, 0, fadeOut);
                }

                tileId++;
                if (tileId == numTiles) {
                    break;
                }
            }
            if (tileId == numTiles) {
                break;
            }
        }
    }

    void QTTileView::paintTiles(QPainter *painter, QRect drawArea) {
        QT::tile current = this->widget->currentTile;
        hyve::ll tiles(current->children);

        if (!scopeMove) {
            paintTileSet(painter, drawArea, tiles, QT::TileFadeNone, true);
        } else {
            paintTileSet(painter, drawArea, tiles, QT::TileFadeOut, true);
            if (scopeMove == 1) {
                if (activatingTile) {
                    if (!activatingTile->children) {
                        activatingTile = NULL;
                    }
                }
            } else if (scopeMove == -1) {
                activatingTile = current->parent;
            }
            if (activatingTile) {
                hyve::ll tiles(activatingTile->children);
                if (scopeMove == -1) {
                    paintTileSet(painter, drawArea, tiles, QT::TileFadeInAndUp, false);
                } else {
                    paintTileSet(painter, drawArea, tiles, QT::TileFadeInAndDown, false);
                }
            }
        }
    }

    void QTTileView::paintEvent(QPaintEvent *event) {
        QPainter *painter;
        QT::painter _painter;

        /* Get hyve and Qt painter object */
        _painter = widget->_parent.painter;
        painter = (QPainter*)_painter->_parent.qhandle;

        /* Begin drawing */
        painter->begin(this);
        painter->setRenderHint(QPainter::Antialiasing);
        paintTiles(painter, event->rect());
        painter->end();
    }

    void QTTileView::mousePressEvent(QMouseEvent *event) {
        int row = event->y() / tileSize.y();
        int column = event->x() / tileSize.x();
        activeTile = row * tileCount.x() + column;
        if (this->widget->currentTile != this->widget->rootTile) {
            if (event->button() == Qt::RightButton) {
                scopeMove = -1;
            }
        }
        t = 0;
        this->startAnimation();        
    }

    void QTTileView::mouseDoubleClickEvent(QMouseEvent *event) {
        if (event->button() == Qt::LeftButton) {
            if (this->widget->selectedTile->children) {
                int row = event->y() / tileSize.y();
                int column = event->x() / tileSize.x();
                activeTile = row * tileCount.x() + column;
                scopeMove = 1;
                t = 0;
                this->startAnimation();
            }
        }
    }

    void QTTileView::resizeEvent(QResizeEvent *) {
        this->startAnimation();
    }
}
/* $end */

namespace QT {
    
    // Constructor
    TileView::TileView(QT::PaintEvent_t *paintEvent,
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
            ::hyve::lang::uint32 separation) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::TileView_h);
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
        this->define();
    }
    
    // Constructor (declare & define)
    TileView::TileView(::hyve::lang::Object *_parent,
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
            ::hyve::lang::uint32 separation) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::TileView_h);
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
        this->define();
    }
    
    // Construct from handle
    TileView::TileView(QT::tileView handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::tileView TileView::_handle() {
        return (QT::tileView)this->__handle;
    }
    
    // ::Qt::Tile currentTile
    QT::Tile *TileView::currentTile() {
        return new QT::Tile(((QT::tileView)this->__handle)->currentTile);
    }
    void TileView::currentTile(QT::Tile *v) {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::tileView)this->__handle)->currentTile, v->_handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::tileView)this->__handle)->currentTile, NULL);
        }
    }
    
    // ::Qt::Tile selectedTile
    QT::Tile *TileView::selectedTile() {
        return new QT::Tile(((QT::tileView)this->__handle)->selectedTile);
    }
    void TileView::selectedTile(QT::Tile *v) {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::tileView)this->__handle)->selectedTile, v->_handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::tileView)this->__handle)->selectedTile, NULL);
        }
    }
    
    // ::Qt::Tile rootTile
    QT::Tile *TileView::rootTile() {
        return new QT::Tile(((QT::tileView)this->__handle)->rootTile);
    }
    void TileView::rootTile(QT::Tile *v) {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::tileView)this->__handle)->rootTile, v->_handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::tileView)this->__handle)->rootTile, NULL);
        }
    }
    
    // ::Qt::PointF maxTileSize
    QT::PointF TileView::maxTileSize() {
        return ((QT::tileView)this->__handle)->maxTileSize;
    }
    void TileView::maxTileSize(QT::PointF v) {
        ((QT::tileView)this->__handle)->maxTileSize = v;
    }
    
    // ::Qt::PointF minTileSize
    QT::PointF TileView::minTileSize() {
        return ((QT::tileView)this->__handle)->minTileSize;
    }
    void TileView::minTileSize(QT::PointF v) {
        ((QT::tileView)this->__handle)->minTileSize = v;
    }
    
    // ::hyve::lang::uint32 separation
    ::hyve::lang::uint32 TileView::separation() {
        return ((QT::tileView)this->__handle)->separation;
    }
    void TileView::separation(::hyve::lang::uint32 v) {
        ((QT::tileView)this->__handle)->separation = v;
    }
    
    /* ::Qt::TileView::clear() */
    ::hyve::lang::_void TileView::clear() {
    /* $begin(::Qt::TileView::clear()) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::TileView::construct(::Qt::TileView object) */
    ::hyve::lang::int16 TileView::construct(QT::TileView *object) {
    /* $begin(::Qt::TileView::construct(::Qt::TileView object)) */
        object->qhandle((hyve::lang::word)new QTTileView(object->_handle(),(QWidget*)object->widgetParent()));
        return 0;
    /* $end */
    }
    
    /* ::Qt::TileView::destruct(::Qt::TileView object) */
    ::hyve::lang::_void TileView::destruct(QT::TileView *object) {
    /* $begin(::Qt::TileView::destruct(::Qt::TileView object)) */

        object->_handle()->currentTile = NULL;

    /* $end */
    }
    
    /* ::Qt::TileView::init(::Qt::TileView object) */
    ::hyve::lang::int16 TileView::init(QT::TileView *object) {
    /* $begin(::Qt::TileView::init(::Qt::TileView object)) */

        /* Create rootTile */
        object->rootTile(new QT::Tile("root", NULL));
        object->_handle()->rootTile->children = hyve::ll::_new();
        object->_handle()->currentTile = object->_handle()->rootTile;

        return QT::Widget::init(object);
    /* $end */
    }
    
    /* ::Qt::TileView::repaint() */
    ::hyve::lang::_void TileView::repaint() {
    /* $begin(::Qt::TileView::repaint()) */
        if (this->qhandle()) {
            ((QTTileView*)this->qhandle())->startAnimation();
        }
    /* $end */
    }
}

