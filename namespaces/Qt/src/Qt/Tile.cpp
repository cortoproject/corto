/* src/Qt/Tile.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Tile.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Tile.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "Qt/Application.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "hyve/lang/Observer.hpp"
#include "Qt/Painter.hpp"
#include <QPropertyAnimation>
#include "math.h"

#define TILE_SIZE 60
#define TILE_SPACING 1
#define TILE_SPACING_SMALL 1
#define TILE_MARGIN 1
#define TILE_MARGIN_SMALL 1
#define TILE_TOPBAR_HEIGHT 22
#define TILE_TITLEBAR_HEIGHT 1
#define PUSH_MARGIN 3

#define ANIMATION_DURATION (300)

namespace QT {
    QTTile::QTTile(tile widget, QWidget *parent, QParallelAnimationGroup *animGroup) : QWidget(parent) {
        this->widget = widget;

        if (widget && hyve::checkAttr(widget, hyve::ATTR_SCOPED)) {
            if (hyve::instanceof((hyve::lang::_typedef)QT::Tile_h, hyve::parentof(widget))) {
                this->parent = (QTTile*)(((QT::tile)(hyve::parentof(widget)))->_parent._parent.qhandle);
            } else {
                this->parent = NULL;
            }
        } else {
            this->parent = NULL;
        }

        if (widget->isRoot) {
            this->hyveLogo = new QImage("hyveicon.png");
        } else {
            this->hyveLogo = this->parent->hyveLogo;
        }

        this->resizeTimer.setInterval(200);

        // Animate size and position
        this->animGeometry = new QPropertyAnimation(this, "geometry");
        this->animGeometry->setDuration(ANIMATION_DURATION);
        this->animGeometry->setEasingCurve(QEasingCurve::InOutExpo);

        // Animate fader variable (to keep track of animation progress)
        this->animFader = new QPropertyAnimation(this, "fader");
        this->animFader->setDuration(ANIMATION_DURATION);
        this->animFader->setEasingCurve(QEasingCurve::InOutExpo);

        // Animate color (for hover & selection of tile)
        this->animColor = new QPropertyAnimation(this, "actualColor");
        this->animColor->setDuration(200);
        this->animColor->setEasingCurve(QEasingCurve::InOutCubic);
        this->animTitleColor = new QPropertyAnimation(this, "actualTitleBarColor");
        this->animTitleColor->setDuration(200);
        this->animTitleColor->setEasingCurve(QEasingCurve::InOutCubic);
        this->animTextColor = new QPropertyAnimation(this, "actualTextColor");
        this->animTextColor->setDuration(200);
        this->animTextColor->setEasingCurve(QEasingCurve::InOutCubic);
        this->animColorGroup = new QParallelAnimationGroup();
        this->animColorGroup->addAnimation(animColor);
        this->animColorGroup->addAnimation(animTitleColor);
        this->animColorGroup->addAnimation(animTextColor);

        // Set animationgroup for animating multiple tiles at once
        if (animGroup) {
            this->animGroup = animGroup;
        } else {
            this->animGroup = new QParallelAnimationGroup();
        }

        // Set titlefont
        this->titleFont.setFamily("Arial");
        this->titleFont.setPointSize(10);
        this->titleFontSmall.setFamily("Arial");
        this->titleFontSmall.setPointSize(8);

        this->actualColor = this->frontColor = QColor(0x36, 0x33, 0x30, 0xff);
        this->actualTitleBarColor = this->titleBarColor = QColor(
                    this->widget->backgroundColor.r,
                    this->widget->backgroundColor.g,
                    this->widget->backgroundColor.b,
                    this->widget->backgroundColor.alpha);
        this->actualTextColor = this->textColor = QColor(0,0,0,0xff);
        this->highlightColor = QColor(0xff, 0xff, 0xff, 0xff);
        this->shadowColor = QColor(0x44,0x44,0x44,0xff);
        this->shadowOnBar = false;

        this->fading = QTTile::FadeNone;
        this->pushed = false;
        this->animating = false;
        this->fader = 1.0;
        this->previousMode = QT::TileNone;

        // Connect slots
        QObject::connect(&this->resizeTimer, SIGNAL(timeout()), this, SLOT(resizeTimeout()));
        QObject::connect(this->animGroup, SIGNAL(finished()), this, SLOT(finishedMoveAnim()));
        QObject::connect(this->animColorGroup, SIGNAL(finished()), this, SLOT(finishedColorAnim()));
    }

    QTTile::~QTTile() {
        if (this->animating) {
            this->animGroup->removeAnimation(this->animGeometry);
            this->animGroup->removeAnimation(this->animFader);
        }
        delete this->animGeometry;
        delete this->animColor;
        delete this->animTextColor;
        delete this->animTitleColor;
        delete this->animColorGroup;
        delete this->animFader;
    }

    void QTTile::resetColor() {
        this->actualTitleBarColor = this->titleBarColor = QColor(
                    this->widget->backgroundColor.r,
                    this->widget->backgroundColor.g,
                    this->widget->backgroundColor.b,
                    this->widget->backgroundColor.alpha);
        this->repaint();
    }

    void QTTile::animate() {
        this->animGroup->start();
    }

    void QTTile::finishedColorAnim() {
        if (this->fading == QTTile::FadeOut) {
            this->hide();
        }
        this->fading = QTTile::FadeNone;
    }

    void QTTile::pulse(QColor color) {
        animColor->stop();
        animColor->setStartValue(this->actualColor);
        animColor->setEndValue(this->actualColor);
        animTitleColor->setStartValue(color);
        animTitleColor->setEndValue(this->actualTitleBarColor);
        animTextColor->setStartValue(this->actualTextColor);
        animTextColor->setEndValue(this->actualTextColor);
        this->animColor->setDuration(800);
        this->animTitleColor->setDuration(800);
        animColorGroup->start();
    }

    void QTTile::finishedMoveAnim() {
        if (this->animating) {
            this->animGroup->removeAnimation(this->animGeometry);
            this->animGroup->removeAnimation(this->animFader);
            this->previousMode = this->widget->mode;
            this->animating = false;
            this->repaint();
        }
    }

    void QTTile::zoomIn() {
        if (parent && parent->widget->mode == QT::TileLarge) {
            if (hyve::scopeSize(this->widget)) {
                // Maximize the to zoom-tile
                this->widget->mode = QT::TileLarge;

                // Set scope of root to tile that will be zoomed into
                this->parent->widget->scope = (hyve::lang::word)this->widget;

                QT::Tile::positionTiles(widget->rootTile, true);
            }
        } else if (parent){
            this->parent->zoomIn();
        }
    }

    void QTTile::zoomOut() {
        if (parent && (this->widget->mode == QT::TileLarge)) {
            this->widget->mode = QT::TileNormal;

            // Set scope of root to parent
            this->parent->widget->scope = 0;
            QT::Tile::positionTiles(widget->rootTile, true);
        } else if (parent){
            this->parent->zoomOut();
        }
    }

    QRect QTTile::getChildRect() {
        return this->childArea;
    }

    void QTTile::resizeTimeout() {
        this->resizeTimer.stop();
        if (this->widget->isRoot) {
            this->widget->_parent.width = this->width();
            this->widget->_parent.height = this->height();
            this->determineChildArea();
        }
        QT::Tile::positionTiles(this->widget->rootTile);
    }

    void QTTile::moveTo(int x, int y, int width, int height, hyve::lang::_bool animate) {
        if (animate) {
            animGeometry->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
            animGeometry->setEndValue(QRect(x, y, width, height));
            animFader->setStartValue(0);
            animFader->setEndValue(1.0);
            this->animating = true;
            this->animGroup->addAnimation(this->animGeometry);
            this->animGroup->addAnimation(this->animFader);
        } else {
            this->move(x, y);
            this->resize(width, height);
            this->repaint();
        }

        this->widget->_parent.x = x;
        this->widget->_parent.y = y;
        this->widget->_parent.width = width;
        this->widget->_parent.height = height;

        if ((this->widget->mode != QT::TileLarge) && (this->widget->mode != QT::TileNone)) {
            if (this->parent->widget->mode == QT::TileLarge) {
                this->widget->mode = QT::TileNormal;
            } else {
                if (hyve::scopeSize(this->parent->widget) <= 2) {
                    this->widget->mode = QT::TileNormal;
                } else {
                    this->widget->mode = QT::TileSmall;
                }
            }

            if ((width <= TILE_SIZE*2) || (height <= TILE_SIZE*2)) {
                this->widget->mode = QT::TileSmall;
            } else {
                int childs = hyve::scopeSize(this->widget);

                if ((float)(height-TILE_TOPBAR_HEIGHT) < (((float)childs / (float)(width / TILE_SIZE)) * (float)TILE_SIZE)) {
                    this->widget->mode = QT::TileSmall;
                } else {
                    this->widget->mode = QT::TileNormal;
                }
            }
        }

        determineChildArea();
    }

    void QTTile::showTile(bool show) {
        if (show) {
            this->show();
        } else {
            this->hide();
        }
    }

    // Calculate area for drawing children
    void QTTile::determineChildArea() {
        if (this->widget->mode == QT::TileLarge) {
            this->childArea.setX(1 + TILE_MARGIN);
            this->childArea.setY(TILE_MARGIN + TILE_TOPBAR_HEIGHT- 1);
            this->childArea.setWidth(this->widget->_parent.width - TILE_MARGIN * 2);
            this->childArea.setHeight(this->widget->_parent.height - 1 - TILE_MARGIN * 2 - TILE_TOPBAR_HEIGHT);
        } else if (this->widget->mode == QT::TileNormal){
            this->childArea.setX(1 + TILE_MARGIN_SMALL);
            this->childArea.setY(TILE_MARGIN_SMALL + TILE_TOPBAR_HEIGHT);
            this->childArea.setWidth(this->widget->_parent.width - 1 - TILE_MARGIN_SMALL * 2);
            this->childArea.setHeight(this->widget->_parent.height - 2 - TILE_MARGIN_SMALL * 2 - TILE_TOPBAR_HEIGHT);
        }
    }

    // Render small tile
    void QTTile::renderSmall(QPainter *painter, QRect rect, float alpha) {
        QBrush brush;
        QPen pen;
        QTextOption textOptions;

        pen.setWidth(0);
        pen.setColor(QColor(0x33,0x33,0x33,0x0));
        brush.setColor(QColor(
                           this->actualTitleBarColor.red(),
                           this->actualTitleBarColor.green(),
                           this->actualTitleBarColor.blue(),
                           alpha * 255));
        brush.setStyle(Qt::SolidPattern);
        painter->setPen(pen);
        painter->setBrush(brush);

        if (this->pushed) {
            painter->drawRect(rect.x() + PUSH_MARGIN, rect.y() + PUSH_MARGIN, rect.width() - PUSH_MARGIN*2, rect.height() - PUSH_MARGIN*2);
        } else {
            painter->drawRect(rect);
        }

        // Draw triangle when object has childs
        if (hyve::scopeSize(this->widget)) {
            QPainterPath path;
            QPoint p1 = QPoint(rect.width()-10, 0);
            QPoint p2 = QPoint(rect.width(), 0);
            QPoint p3 = QPoint(rect.width(), 10);

            brush.setColor(QColor(0x55,0xcc,0xee,alpha * this->actualColor.alpha()));
            path.moveTo (p1);
            path.lineTo (p2);
            path.lineTo (p3);
            path.lineTo (p1);
            painter->fillPath (path, brush);
        }

        // Draw title
        pen.setWidth(1);
        pen.setColor(QColor(
             this->actualTextColor.red(),
             this->actualTextColor.green(),
             this->actualTextColor.blue(),
             alpha * 255));
        painter->setPen(pen);
        if (!this->pushed) {
            painter->setFont(this->titleFontSmall);
        } else {
            painter->setFont(QFont(this->titleFontSmall.family(), this->titleFontSmall.pointSize() - PUSH_MARGIN/2));
        }
        textOptions.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        textOptions.setAlignment(Qt::AlignCenter);
        painter->drawText(QRect(rect.left() + 3, rect.top() + 3, rect.width() - 6, rect.height() - 6),
                          QString(this->widget->title), textOptions);
    }

    // Render normal tile
    void QTTile::renderNormal(QPainter *painter, QRect rect, float _alpha) {
        QPen pen;
        float alpha = _alpha * ((float)this->actualColor.alpha() / 255.0);

        // Calculate properties of bounding rectangle. Compensate for pen-width
        int left = rect.left() + 1;
        int top = rect.top() + 1;
        int width = rect.width() - 2;
        int height = rect.height() - 2;

        // Draw bounding box
        pen.setWidth(2);
        pen.setColor(this->actualTitleBarColor);
        QLinearGradient grad(0,0,0,1);
        grad.setCoordinateMode(QGradient::ObjectBoundingMode);
        grad.setColorAt(0.0, QColor(0,0,0,0xaa * alpha));
        grad.setColorAt(0.3, QColor(this->actualColor.red(), this->actualColor.green(), this->actualColor.blue(), 0x66 * alpha));
        grad.setColorAt(1.0, QColor(this->actualColor.red(), this->actualColor.green(), this->actualColor.blue(), 0x66 * alpha));
        QBrush boxGrad(grad);
        painter->setPen(pen);
        painter->setBrush(boxGrad);
        painter->drawRect(QRect(left, top, width, height));

        // Draw topbar
        pen.setWidth(0);
        pen.setColor(QColor(0,0,0,0));
        painter->setPen(pen);

        if (this->shadowOnBar) {
            QLinearGradient titleGrad(0,0,0,1);
            titleGrad.setCoordinateMode(QGradient::ObjectBoundingMode);
            titleGrad.setColorAt(0.0, this->actualTitleBarColor);
            titleGrad.setColorAt(0.7, this->actualTitleBarColor);
            titleGrad.setColorAt(1.0, QColor(0xee,0xee,0xee,0xff));
            painter->setBrush(QBrush(titleGrad));
        } else {
            painter->setBrush(QBrush(QColor(
                                         this->actualTitleBarColor.red(),
                                         this->actualTitleBarColor.green(),
                                         this->actualTitleBarColor.blue(),
                                         alpha * 255)));
        }

        if (hyve::scopeSize(this->widget)) {
            painter->drawRect(QRect(left+1, top, width-2, TILE_TOPBAR_HEIGHT));
        } else {
            painter->drawRect(QRect(left+1, top, width-2, height));
        }

        // Draw title
        pen.setWidth(1);
        pen.setColor(QColor(
                         this->actualTextColor.red(),
                         this->actualTextColor.green(),
                         this->actualTextColor.blue(),
                         alpha * 255));
        painter->setPen(pen);
        painter->setFont(this->titleFont);

        painter->drawText(QRect(left+5, top, width-2, height), widget->title);
    }

    // Render large tile
    void QTTile::renderLarge(QPainter *painter, QRect rect, float alpha) {
        QPen pen;
        QLinearGradient grad(0,0,0,1);
        QColor bgColorAlpha(this->frontColor.red(), this->frontColor.green(), this->frontColor.blue(), 0xdd);
        grad.setCoordinateMode(QGradient::StretchToDeviceMode);
        grad.setColorAt(0.0, bgColorAlpha);
        grad.setColorAt(0.7, bgColorAlpha);
        grad.setColorAt(1.0, QColor(this->frontColor.red() / 2, this->frontColor.green() / 2, this->frontColor.blue() / 2, this->frontColor.alpha()));
        QBrush brush(grad);
        QString title;

        // Calculate rect for image
        int width = rect.width();
        int height = rect.height();

        if (width > height) width = height;
        if (height > width) height = width;
        int left = (rect.width() - width) / 2;
        int top = (rect.height() - height) / 2;
        if (!animating) {
            painter->drawImage(QRect(left,top,width,height), *this->hyveLogo);
        }

        // Calculate properties of bounding rectangle. Compensate for pen-width
        left = rect.left() + 1;
        top = rect.top();
        width = rect.width() - 2;
        height = rect.height();

        // Draw bounding box
        pen.setWidth(1);
        pen.setColor(this->titleBarColor);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(QRect(left, top, width, height));

        // Draw topbar
        pen.setWidth(0);
        pen.setColor(QColor(0,0,0,0));
        painter->setPen(pen);
       /* if (this->shadowOnBar) {*/
            QLinearGradient titleGrad(0,0,0,1);
            titleGrad.setCoordinateMode(QGradient::ObjectBoundingMode);
            titleGrad.setColorAt(1.0, this->titleBarColor);
            titleGrad.setColorAt(0.7, QColor(0xee,0xee,0xee,0xff));
            titleGrad.setColorAt(0.0, QColor(0xee,0xee,0xee,0xff));
            painter->setBrush(QBrush(titleGrad));
        /*} else {
            painter->setBrush(QBrush(this->titleBarColor));
        }*/

        painter->drawRect(QRect(left, top, width, TILE_TOPBAR_HEIGHT));

        // Draw title
        pen.setWidth(1);
        pen.setColor(this->actualTextColor);
        painter->setPen(pen);
        painter->setFont(this->titleFont);

        QT::tile parent = this->widget;
        while(parent) {
            if (title.length()) {
                title = QString(parent->title) + QString(" / ") + title;
            } else {
                title = QString(parent->title);
            }
            if (!parent->isRoot) {
                parent = (QT::tile)hyve::parentof(parent);
            } else {
                parent = NULL;
            }
        }

        painter->drawText(QRect(left, top, width, TILE_TOPBAR_HEIGHT), Qt::AlignHCenter, title);
    }

    void QTTile::renderTile(QPainter *painter, QT::TileMode mode, float fader) {
        QRect logicalRect = QRect(0, 0, this->width(), this->height());
        if (mode == QT::TileSmall) {
            renderSmall(painter, logicalRect, fader);
        } else if (mode == QT::TileNormal) {
            renderNormal(painter, logicalRect, fader);
        } else if (mode == QT::TileLarge) {
            renderLarge(painter, logicalRect, fader);
        }
    }

    QParallelAnimationGroup *QTTile::getAnimGroup() {
        return this->animGroup;
    }

    void QTTile::paintEvent(QPaintEvent *event) {
        QPainter *painter;
        QT::painter _painter;

        /* Get hyve and Qt painter object */
        _painter = widget->_parent.painter;
        painter = (QPainter*)_painter->_parent.qhandle;

        /* Begin drawing */
        painter->begin(this);
        // painter->setRenderHint(QPainter::Antialiasing);
        if (this->animating && (this->previousMode != this->widget->mode)) {
            this->renderTile(painter, this->previousMode, 1.0 - this->fader);
            this->renderTile(painter, this->widget->mode, this->fader);
        } else {
            this->renderTile(painter, this->widget->mode, 1.0);
        }

        painter->end();
    }

    void QTTile::mousePressEvent(QMouseEvent *event) {
        if (event->buttons() == Qt::RightButton) {
            this->zoomOut();
        } else if (event->buttons() == Qt::LeftButton){
            this->pushed = true;
            this->repaint();
        }
    }

    void QTTile::mouseReleaseEvent(QMouseEvent *event) {
        if (this->pushed) {
            hyve::update(this->widget);
        }
        this->pushed = false;
        this->repaint();
    }

    // Zoom events
    void QTTile::mouseDoubleClickEvent(QMouseEvent *event) {
        this->zoomIn();
    }

    void QTTile::resizeEvent(QResizeEvent *event) {
        if ((this->widget->mode == QT::TileLarge) && (this->animGeometry->state() != QPropertyAnimation::Running)) {
            this->resizeTimer.start();
        }
    }

    void QTTile::enterEvent(QEvent *event) {
        animColorGroup->stop();
        this->actualColor = QColor(0x0, 0x0, 0x0, 0xff);
        this->actualTitleBarColor = QColor(0xff, 0xbb, 0x99, 0xff);
        this->repaint();
    }

    void QTTile::leaveEvent(QEvent *event) {
        animColor->setStartValue(this->actualColor);
        animColor->setEndValue(this->frontColor);
        animTitleColor->setStartValue(this->actualTitleBarColor);
        animTitleColor->setEndValue(this->titleBarColor);
        animTextColor->setStartValue(this->actualTextColor);
        animTextColor->setEndValue(this->textColor);
        this->animColor->setDuration(200);
        this->animTitleColor->setDuration(200);
        animColorGroup->start();
    }

    void QTTile::wheelEvent(QWheelEvent *event) {
    }

    float QTTile::getFader() {
        return this->fader;
    }

    void QTTile::setFader(float fader) {
        this->fader = fader;
    }

    QColor QTTile::getActualColor() {
        return this->actualColor;
    }

    void QTTile::setActualColor(QColor color) {
        this->actualColor = color;
        this->repaint();
    }

    QColor QTTile::getActualTitleBarColor() {
        return this->actualTitleBarColor;
    }

    void QTTile::setActualTitleBarColor(QColor color) {
        this->actualTitleBarColor = color;
        // this->repaint(); -- will change together with actualColor, so no extra repaint required
    }

    QColor QTTile::getActualTextColor() {
        return this->actualTextColor;
    }

    void QTTile::setActualTextColor(QColor color) {
        this->actualTextColor = color;
    }
}

/* $end */

namespace QT {
    
    // Constructor
    Tile::Tile(const QT::PaintEvent_t &paintEvent,
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
             QT::TileMode mode) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Tile_h);
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
        this->define();
    }
    
    // Constructor (declare & define)
    Tile::Tile(::hyve::lang::Object *_parent,
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
             QT::TileMode mode) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Tile_h);
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
        this->define();
    }
    
    // Construct from handle
    Tile::Tile(QT::tile handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::tile Tile::_handle() const {
        return (QT::tile)this->__handle;
    }
    
    // ::hyve::lang::string title
    ::hyve::lang::string Tile::title() const {
        return ((QT::tile)this->__handle)->title;
    }
    void Tile::title( ::hyve::lang::string v) const {
        if (((QT::tile)this->__handle)->title) {
            hyve::dealloc(((QT::tile)this->__handle)->title);
        };
        ((QT::tile)this->__handle)->title = v ? hyve::strdup(v) : NULL;
    }
    
    // ::Qt::Color textColor
    QT::Color Tile::textColor() const {
        return ((QT::tile)this->__handle)->textColor;
    }
    void Tile::textColor( QT::Color v) const {
        ((QT::tile)this->__handle)->textColor = v;
    }
    
    // ::Qt::Color foregroundColor
    QT::Color Tile::foregroundColor() const {
        return ((QT::tile)this->__handle)->foregroundColor;
    }
    void Tile::foregroundColor( QT::Color v) const {
        ((QT::tile)this->__handle)->foregroundColor = v;
    }
    
    // ::Qt::Color backgroundColor
    QT::Color Tile::backgroundColor() const {
        return ((QT::tile)this->__handle)->backgroundColor;
    }
    void Tile::backgroundColor( QT::Color v) const {
        ((QT::tile)this->__handle)->backgroundColor = v;
    }
    
    // ::Qt::TileMode mode
    QT::TileMode Tile::mode() const {
        return ((QT::tile)this->__handle)->mode;
    }
    void Tile::mode( QT::TileMode v) const {
        ((QT::tile)this->__handle)->mode = v;
    }
    
    // ::hyve::lang::bool isRoot
    ::hyve::lang::_bool Tile::isRoot() const {
        return ((QT::tile)this->__handle)->isRoot;
    }
    void Tile::isRoot( ::hyve::lang::_bool v) const {
        ((QT::tile)this->__handle)->isRoot = v;
    }
    
    // ::Qt::Tile rootTile
    QT::Tile Tile::rootTile() const {
        QT::Tile result(((QT::tile)this->__handle)->rootTile);
        return result;
    }
    void Tile::rootTile(const QT::Tile &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::tile)this->__handle)->rootTile, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::tile)this->__handle)->rootTile, NULL);
        }
    }
    
    // ::hyve::lang::word scope
    ::hyve::lang::word Tile::scope() const {
        return ((QT::tile)this->__handle)->scope;
    }
    void Tile::scope( ::hyve::lang::word v) const {
        ((QT::tile)this->__handle)->scope = v;
    }
    
    /* ::Qt::Tile::construct(::Qt::Tile object) */
    ::hyve::lang::int16 Tile::construct(const QT::Tile &object) {
    /* $begin(::Qt::Tile::construct(::Qt::Tile object)) */
        QTTile *tile;
        QWidget *parent_q; /* Parent handle to Qt object */
        QParallelAnimationGroup *animGroup = NULL;
        hyve::lang::Observer onDefine(QT::Tile_onDefine_h);
        hyve::lang::Observer onDestruct(QT::Tile_onDestruct_h);
        hyve::lang::Observer onSelf(QT::Tile_onSelf_h);

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* If parent is a tile, create child-tile. Otherwise create root-tile */
        if (hyve::instanceof((hyve::lang::_typedef)QT::Tile_h, hyve::parentof(object._handle()))) {
            QT::tile parentHandle = (QT::tile)hyve::parentof(object._handle());
            QTTile *rootTile = (QTTile*)parentHandle->_parent._parent.qhandle;
            object._handle()->rootTile = parentHandle->rootTile; hyve::keep(parentHandle->rootTile);
            animGroup = rootTile->getAnimGroup();
            if (parentHandle->mode == QT::TileLarge) {
                object.mode(QT::TileNormal);
            } else {
                object.mode(QT::TileSmall);
            }
            object.isRoot(false);
        } else {
            object.mode(QT::TileLarge);
            object.isRoot(true);
            object._handle()->scope = (hyve::lang::word)object._handle();
            object._handle()->rootTile = object._handle(); hyve::keep(object._handle());
        }

        // Set dispatcher for observer
        hyve::lang::Dispatcher dispatcher(QT::app(), false);
        onDefine.setDispatcher(dispatcher);
        onDestruct.setDispatcher(dispatcher);
        onSelf.setDispatcher(dispatcher);

        /* Create widget */
        tile = new QTTile(object._handle(), parent_q, animGroup);
        if (!tile) {
            hyve::error("Qt::Tile::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)tile);

        /* Call abstractbutton constructor */
        ((QT::Widget)object).construct(object);

        tile->show();

        return 0;
error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::Tile::destruct(::Qt::Tile object) */
    ::hyve::lang::_void Tile::destruct(const QT::Tile &object) {
    /* $begin(::Qt::Tile::destruct(::Qt::Tile object)) */
        QTTile *widget = (QTTile*)object.qhandle();
        delete widget;
    /* $end */
    }
    
    /* ::Qt::Tile::init(::Qt::Tile object) */
    ::hyve::lang::int16 Tile::init(const QT::Tile &object) {
    /* $begin(::Qt::Tile::init(::Qt::Tile object)) */
        object._handle()->backgroundColor.r = 0xee;
        object._handle()->backgroundColor.g = 0xee;
        object._handle()->backgroundColor.b = 0xee;
        object._handle()->backgroundColor.alpha = 0xff;

        object._handle()->textColor.r = 0;
        object._handle()->textColor.g = 0;
        object._handle()->textColor.b = 0;
        object._handle()->textColor.alpha = 0xff;
        return QT::Widget::init(object);
    /* $end */
    }
    
    /* ::Qt::Tile::onDefine */
    ::hyve::lang::_void Tile::onDefine(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::Tile::onDefine) */

        if (this->isRoot()) {
             positionTiles(this->_handle(), true);
        }

    /* $end */
    }
    
    /* ::Qt::Tile::onDestruct */
    ::hyve::lang::_void Tile::onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::Tile::onDestruct) */

        if (this->isRoot()) {
            positionTiles(this->_handle(), true);
        }

    /* $end */
    }
    
    /* ::Qt::Tile::onSelf */
    ::hyve::lang::_void Tile::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::Tile::onSelf) */
        QTTile *widget = (QTTile*)this->qhandle();
        widget->resetColor();
    /* $end */
    }
    
    /* ::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha) */
    ::hyve::lang::_void Tile::pulse(::hyve::lang::uint8 r, ::hyve::lang::uint8 g, ::hyve::lang::uint8 b, ::hyve::lang::uint8 alpha) const {
    /* $begin(::Qt::Tile::pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)) */
        QTTile *widget = (QTTile*)this->qhandle();
        /*widget->pulse(QColor(0x55, 0xee, 0x77, 0xff));*/
    /* $end */
    }
    /* $begin($classfooter) */
    int Tile::positionTilesAction(hyve::lang::object object, void *userData) {
        if (hyve::instanceof((hyve::lang::_typedef)QT::Tile_h, object) &&
                hyve::checkState(object, hyve::DEFINED) &&
                !hyve::checkState(object, hyve::DESTRUCTED)) {
            QT::Tile t = QT::Tile((QT::tile)object);
            Tile::positionTilesData *data = (Tile::positionTilesData*)userData;
            QTTile *widget = (QTTile*)t.qhandle();

            int row = data->current / data->columns;
            int column = data->current % data->columns;
            int x = (column * (data->xSize + data->spacing)) + data->margin + data->drawArea.x();
            int y = (row * (data->ySize + data->spacing)) + data->margin + data->drawArea.y();
            int width = data->xSize;
            int height = data->ySize;

            // Make sure last tile in column never exceeds boundaries. Due to the discreet
            // nature of the widget-coordinates widget-sizes do not always fit exactly
            // within the width of their parent. Therefore sometimes this small correction is
            // necessary.
            if (column == (data->columns-1)) {
                width = data->drawArea.width() - x;
            }

            if (row == (data->rows-1)) {
                height = data->drawArea.height() - (y - data->drawArea.y());
            }

            t.moveTo(x, y, width, height, data->animate);
            widget->lower(); // Make sure tiles are drawn below title-tile
            widget->showTile(true);

            data->current++;

            // If this tile has childs, reposition them as well
            positionTiles((QT::tile)object, data->animate);
        }
        return 1;
    }

    /* Hide all tiles in a scope */
    int Tile::hideTilesAction(hyve::lang::object o, void *userData) {
        if (hyve::instanceof((hyve::lang::_typedef)QT::Tile_h, o)) {
            QT::Tile tile = QT::Tile((QT::tile)o);
            QTTile *widget = (QTTile*)tile.qhandle();

            widget->showTile(false);
        }
        return 1;
    }

    /* Maximize one tile, hide the others */
    int Tile::collapseTileAction(hyve::lang::object o, void *userData) {
        if (hyve::instanceof((hyve::lang::_typedef)QT::Tile_h, o)) {
            QT::Tile tile = QT::Tile((QT::tile)o);
            QTTile *widget = (QTTile*)tile.qhandle();
            QT::Tile parentTile = QT::Tile((QT::tile)hyve::parentof(o));

            tile.moveTo(0, 0, parentTile.width(), parentTile.height(), true);
            widget->showTile(true);

            // Position child-tiles
            positionTiles((QT::tile)o, true);
        }
        return 1;
    }

    /* Maximize one tile, hide the others */
    int Tile::maximizeTileAction(hyve::lang::object o, void *userData) {
        if (hyve::instanceof((hyve::lang::_typedef)QT::Tile_h, o)) {
            QT::Tile tile = QT::Tile((QT::tile)o);
            QTTile *widget = (QTTile*)tile.qhandle();

            if (o == userData) {
                QT::Tile parentTile = QT::Tile((QT::tile)hyve::parentof(o));
                tile.moveTo(parentTile.x(), parentTile.y(), parentTile.width(), parentTile.height(), true);

                // Position child-tiles
                positionTiles((QT::tile)o, true);
            } else {
                widget->showTile(false);
            }
        }
        return 1;
    }

    /* Position child-tiles within a normal tile */
    void Tile::positionTilesNormal(tile me, hyve::lang::_bool animate) {
        QTTile *tile = (QTTile*)me->_parent._parent.qhandle;
        int width = tile->getChildRect().width();
        int height = tile->getChildRect().height();
        int columns=0, rows=0;
        int xSize=0, ySize=0;


        if (width && height) {
            columns = width / TILE_SIZE;
            rows = height / TILE_SIZE;
            if (columns) { // Prevent division by zero
                xSize = (width + TILE_SPACING_SMALL) / columns - TILE_SPACING_SMALL;
                ySize = TILE_SIZE;
            }
        }

        if (columns && rows) {
            positionTilesData walkData = {
                    0, animate,
                    me,
                    tile->getChildRect(),
                    rows,
                    columns,
                    xSize,
                    ySize,
                    TILE_MARGIN_SMALL,
                    TILE_SPACING_SMALL,
                    true
                };

            // Calculate new positions
            hyve::scopeWalk(me, positionTilesAction, &walkData);
        }
    }

    /* Position child-tiles within a large tile */
    void Tile::positionTilesLarge(tile me, hyve::lang::_bool animate) {
        int childsTotal = hyve::scopeSize(me);
        if (me->scope && (me->scope != (hyve::lang::word)me)) {
            hyve::scopeWalk(me, maximizeTileAction, (void*)me->scope);
        } else {
            QTTile *tile = (QTTile*)me->_parent._parent.qhandle;
            int width = tile->getChildRect().width();
            int height = tile->getChildRect().height();
            int columns=0, rows=0;
            int xSize=0, ySize=0;

            if (width && height) {
                if (width > (TILE_SIZE * 2)) {
                    if (height > (TILE_SIZE * 2)) {
                        columns = sqrt(childsTotal);
                    } else {
                        columns = childsTotal;
                    }
                } else {
                    columns = 1;
                }
                if (columns) {
                    rows = ceil((float)childsTotal / (float)columns);
                    if (rows) {
                        xSize = (width + TILE_SPACING) / columns - TILE_SPACING;
                        ySize = (height + TILE_SPACING) / rows - TILE_SPACING;
                    }
                }
            }

            if (columns && rows) {
                positionTilesData walkData = {
                        0, animate,
                        me,
                        tile->getChildRect(),
                        rows,
                        columns,
                        xSize,
                        ySize,
                        TILE_MARGIN,
                        TILE_SPACING,
                        true
                    };

                // Calculate new positions
                hyve::scopeWalk(me, positionTilesAction, &walkData);
            }
        }
    }

    // Position, show and hide child-tiles
    void Tile::positionTiles(QT::tile me, hyve::lang::_bool animate) {

        // Only position child-tiles if I am defined and there are childtiles
        if (hyve::checkState(me, hyve::DEFINED) && hyve::scopeSize(me)) {
            QTTile *tile = (QTTile*)me->_parent._parent.qhandle;

            switch(me->mode) {
            case QT::TileSmall:
                hyve::scopeWalk(me, hideTilesAction, NULL);
                break;
            case QT::TileNormal:
                if (hyve::scopeSize(me) > 2) {
                    positionTilesNormal(me, animate);
                } else {
                    positionTilesLarge(me, animate);
                }
                break;
            case QT::TileLarge:
                positionTilesLarge(me, animate);
                break;
            default:
                break;
            }

            if (animate) {
                if (me->isRoot) {
                    tile->animate();
                }
            } else {
                tile->repaint();
            }
        }
    }

    void Tile::moveTo(int x, int y, int width, int height, hyve::lang::_bool animate) {
        QTTile *w = (QTTile*)this->qhandle();

        if (w) {
            w->moveTo(x,y,width,height,animate);
        }
    }

    /* $end */
}

