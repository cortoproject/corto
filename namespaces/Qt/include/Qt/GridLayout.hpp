/* include/Qt/GridLayout.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::GridLayout.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_GridLayout_H
#define Qt_GridLayout_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"

namespace QT {
    class GridLayout : public QT::Object {
        
        // Constructor (new,define)
        public: GridLayout( QT::GridRow_seq rows,
                 QT::GridColumn_seq columns,
                 QT::GridWidget_seq widgets);
        
        // Scoped constructor (declare,define)
        public: GridLayout(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::GridRow_seq rows,
                 QT::GridColumn_seq columns,
                 QT::GridWidget_seq widgets);
        
        // Handle constructor
        public: GridLayout(QT::gridLayout handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::gridLayout _handle() const;
        
        // <0x816ffa8> columns
        public: QT::GridColumn_seq columns() const;
        public: void columns( QT::GridColumn_seq v) const;
        
        // <0x816f668> rows
        public: QT::GridRow_seq rows() const;
        public: void rows( QT::GridRow_seq v) const;
        
        // <0x81708d0> widgets
        public: QT::GridWidget_seq widgets() const;
        public: void widgets( QT::GridWidget_seq v) const;
        
        // construct(::Qt::GridLayout object)
        public: static ::hyve::lang::int16 construct(const QT::GridLayout &object);
        
        // destruct(::Qt::GridLayout object)
        public: static ::hyve::lang::_void destruct(const QT::GridLayout &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

