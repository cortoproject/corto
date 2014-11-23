/* include/Qt/Tile.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Tile.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Tile_H
#define Qt_Tile_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QWidget"
#include "QPainter"
#include "QPaintEvent"
#include "QTimer"
#include "QPropertyAnimation"
#include "QGraphicsDropShadowEffect"
#include "QParallelAnimationGroup"

namespace QT {
    class QTTile : public QWidget {
        Q_OBJECT
    public:
        QTTile(QT::tile widget, QWidget *parent, QParallelAnimationGroup *animGroup = NULL);
        ~QTTile();
        void moveTo(int x, int y, int width, int height, hyve::lang::_bool animate);
        void showTile(bool show);
        void animate();
        void pulse(QColor color);
        void resetColor();

        // Getters
        QParallelAnimationGroup *getAnimGroup();
        QRect getChildRect();

        // Overloaded widget events
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *);
        void mouseDoubleClickEvent(QMouseEvent *event);
        void resizeEvent(QResizeEvent *event);
        void wheelEvent(QWheelEvent *event);
        void enterEvent(QEvent *event);
        void leaveEvent(QEvent *event);

        // Properties
        float getFader();
        void setFader(float fader);

        QColor getActualColor();
        void setActualColor(QColor color);

        QColor getActualTitleBarColor();
        void setActualTitleBarColor(QColor color);

        QColor getActualTextColor();
        void setActualTextColor(QColor color);

        Q_PROPERTY(float fader READ getFader WRITE setFader)
        Q_PROPERTY(QColor actualTextColor READ getActualTextColor WRITE setActualTextColor)
        Q_PROPERTY(QColor actualColor READ getActualColor WRITE setActualColor)
        Q_PROPERTY(QColor actualTitleBarColor READ getActualTitleBarColor WRITE setActualTitleBarColor)

    public slots:
        void resizeTimeout();
        void finishedMoveAnim();
        void finishedColorAnim();

    private:
        QTimer resizeTimer;
        QPropertyAnimation *animGeometry;
        QPropertyAnimation *animFader;
        QPropertyAnimation *animColor;
        QPropertyAnimation *animTitleColor;
        QPropertyAnimation *animTextColor;
        QParallelAnimationGroup *animGroup;
        QParallelAnimationGroup *animColorGroup;

        // Animated colors
        QColor actualColor;
        QColor actualTitleBarColor;
        QColor actualTextColor;

        // Configurated colors
        QColor frontColor;
        QColor shadowColor;
        QColor highlightColor;
        QColor titleBarColor;
        QColor textColor;
        QFont titleFont;
        QFont titleFontSmall;
        bool shadowOnBar;

        // Area designated for children
        QRect childArea;

        // Parent widget
        QTTile *parent;

        // Is tile being pushed (by mouse)
        bool pushed;
        bool animating;
        float fader;
        QT::TileMode previousMode;
        QImage *hyveLogo;

        void renderTile(QPainter *painter, TileMode mode, float fader);
        void renderSmall(QPainter *painter, QRect rect, float alpha);
        void renderNormal(QPainter *painter, QRect rect, float _alpha);
        void renderLarge(QPainter *painter, QRect rect, float alpha);

        void zoomIn();
        void zoomOut();

        void determineChildArea();

        enum {
            FadeNone,
            FadeIn,
            FadeOut
        }fading;

    public:
        QT::tile widget;
    };
}
/* $end */

namespace QT {
    class Tile : public QT::Widget {
        
        // Constructor (new,define)
        public: Tile(const QT::PaintEvent_t &paintEvent,
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
                 QT::TileMode mode);
        
        // Scoped constructor (declare,define)
        public: Tile(::hyve::lang::Object *_parent,
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
                 QT::TileMode mode);
        
        // Handle constructor
        public: Tile(QT::tile handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::tile _handle() const;
        
        // ::Qt::Color backgroundColor
        public: QT::Color backgroundColor() const;
        public: void backgroundColor( QT::Color v) const;
        
        // ::Qt::Color foregroundColor
        public: QT::Color foregroundColor() const;
        public: void foregroundColor( QT::Color v) const;
        
        // ::hyve::lang::bool isRoot
        public: ::hyve::lang::_bool isRoot() const;
        public: void isRoot( ::hyve::lang::_bool v) const;
        
        // ::Qt::TileMode mode
        public: QT::TileMode mode() const;
        public: void mode( QT::TileMode v) const;
        
        // ::Qt::Tile rootTile
        public: QT::Tile rootTile() const;
        public: void rootTile(const QT::Tile &v) const;
        
        // ::hyve::lang::word scope
        public: ::hyve::lang::word scope() const;
        public: void scope( ::hyve::lang::word v) const;
        
        // ::Qt::Color textColor
        public: QT::Color textColor() const;
        public: void textColor( QT::Color v) const;
        
        // ::hyve::lang::string title
        public: ::hyve::lang::string title() const;
        public: void title( ::hyve::lang::string v) const;
        
        // construct(::Qt::Tile object)
        public: static ::hyve::lang::int16 construct(const QT::Tile &object);
        
        // destruct(::Qt::Tile object)
        public: static ::hyve::lang::_void destruct(const QT::Tile &object);
        
        // init(::Qt::Tile object)
        public: static ::hyve::lang::int16 init(const QT::Tile &object);
        
        // onDefine
        public: ::hyve::lang::_void onDefine(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // pulse(::hyve::lang::uint8 r,::hyve::lang::uint8 g,::hyve::lang::uint8 b,::hyve::lang::uint8 alpha)
        public: ::hyve::lang::_void pulse(::hyve::lang::uint8 r, ::hyve::lang::uint8 g, ::hyve::lang::uint8 b, ::hyve::lang::uint8 alpha) const;
        /* $begin($classfooter) */
        struct positionTilesData {
            int current;
            hyve::lang::_bool animate;
            QT::tile me;
            QRect drawArea;
            int rows;
            int columns;
            int xSize;
            int ySize;
            int margin;
            int spacing;
            bool show;
        };

        static int hideTilesAction(hyve::lang::object o, void *userData);
        static int maximizeTileAction(hyve::lang::object o, void *userData);
        static int collapseTileAction(hyve::lang::object o, void *userData);
        static int positionTilesAction(hyve::lang::object o, void *userData);
        static void positionTiles(tile me, hyve::lang::_bool animate = true);
        static void positionTilesNormal(tile me, hyve::lang::_bool animate = true);
        static void positionTilesLarge(tile me, hyve::lang::_bool animate = true);
        void moveTo(int x, int y, int width, int height, hyve::lang::_bool animate);
        /* $end */
    };
}

#endif

