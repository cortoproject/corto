/* include/Qt/Application.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Application.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Application_H
#define Qt_Application_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"
#include "hyve/lang/Dispatcher.hpp"
namespace hyve {
    namespace lang {
        class Event;
        class ObservableEvent;
        class Observer;
    }
}

/* $begin($header) */
#include "QApplication"
namespace QT {
    application app();

    /* Subclass QApplication to catch events from Qt eventloop */
    class QTApplication : public QApplication {
        Q_OBJECT
    public:
        QTApplication(QT::application app);

        // Catch events
        bool event(QEvent *e);
        QT::application _app();

    public slots:
        void quitting();

    private:
        QT::application app;
    };

}
/* $end */

namespace QT {
    class Application : public QT::Object {
        
        // Constructor (new,define)
        public: Application( ::hyve::lang::string_seq arg,
                 ::hyve::lang::string stylesheet);
        
        // Scoped constructor (declare,define)
        public: Application(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::string_seq arg,
                 ::hyve::lang::string stylesheet);
        
        // Handle constructor
        public: Application(QT::application handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::application _handle() const;
        
        // <0x8145480> arg
        public: ::hyve::lang::string_seq arg() const;
        public: void arg( ::hyve::lang::string_seq v) const;
        
        // ::hyve::lang::string stylesheet
        public: ::hyve::lang::string stylesheet() const;
        public: void stylesheet( ::hyve::lang::string v) const;
        
        // construct(::Qt::Application object)
        public: static ::hyve::lang::int16 construct(const QT::Application &object);
        
        // destruct(::Qt::Application object)
        public: static ::hyve::lang::_void destruct(const QT::Application &object);
        
        // exec()
        public: ::hyve::lang::_void exec() const;
        
        // getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)
        public: ::hyve::lang::ObservableEvent getEvent(const ::hyve::lang::Observer &observer, const ::hyve::lang::Object &me, const ::hyve::lang::Object &observable, const ::hyve::lang::Object &src) const;
        
        // init(::Qt::Application object)
        public: static ::hyve::lang::int16 init(const QT::Application &object);
        
        // post(::hyve::lang::event event)
        public: ::hyve::lang::_void post(const ::hyve::lang::Event &event) const;
    };
}

#endif

