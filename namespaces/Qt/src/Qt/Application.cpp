/* src/Qt/Application.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Application.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Application.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Event.hpp"
#include "hyve/lang/Object.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/ObservableEvent.hpp"

/* $begin($header) */
#include "hyve.hpp"
#include "QApplication"
#include "QEvent"
#include "QThread"
#include "QFile"
#include "hyve/lang/Observer.hpp"

/* Singleton application */
static hyve::lang::int32 used = 0;
static int FractalEventType;
static bool aboutToQuit = false;

static int __argc;
static char ** __argv;

static int eventsWaiting = 0;

static QT::QTApplication *app = NULL;

namespace QT {
    /* FractalEvent */
    class FractalEvent : public QEvent {
    public:
        FractalEvent(hyve::lang::event event) : QEvent((QEvent::Type)FractalEventType) {
            this->event = event;
        }
        hyve::lang::event event;
    };

    /* Subclass QApplication to catch events from Qt eventloop */

    QTApplication::QTApplication(QT::application app) : QApplication(__argc, __argv) {
        this->app = app;
        QObject::connect(this, SIGNAL(aboutToQuit()), this, SLOT(quitting()));
    }

    // Catch events
    bool QTApplication::event(QEvent *e) {
        bool result;
        if (e->type() == (QEvent::Type)FractalEventType) {
            QT::Application app(this->app,false);
            hyve::lang::Event event(((FractalEvent*)e)->event);

            /* Because we're now in the Qt mainthread, this event will be handled
             * synchronously. */
            app.post(event);

            hyve::adec(&eventsWaiting);

            /* Free event */
            result = true;
        } else {
            result = QApplication::event(e);
        }
        return result;
    }

    QT::application QTApplication::_app() {
        return this->app;
    }

    void QTApplication::quitting() {
        ::aboutToQuit = true;
    }
}

namespace QT{
    /* Provide access to hyve-application object */
    application app() {
        if (::app) {
            return ::app->_app();
        } else {
            return NULL;
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    Application::Application( ::hyve::lang::string_seq arg,
             ::hyve::lang::string stylesheet) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Application_h);
        this->arg(arg);
        this->stylesheet(stylesheet);
        this->define();
    }
    
    // Constructor (declare & define)
    Application::Application(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             ::hyve::lang::string_seq arg,
             ::hyve::lang::string stylesheet) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Application_h);
        this->arg(arg);
        this->stylesheet(stylesheet);
        this->define();
    }
    
    // Construct from handle
    Application::Application(QT::application handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::application Application::_handle() const {
        return (QT::application)this->__handle;
    }
    
    // <0x8145480> arg
    ::hyve::lang::string_seq Application::arg() const {
        return ((QT::application)this->__handle)->arg;
    }
    void Application::arg( ::hyve::lang::string_seq v) const {
        ((QT::application)this->__handle)->arg = v;
    }
    
    // ::hyve::lang::string stylesheet
    ::hyve::lang::string Application::stylesheet() const {
        return ((QT::application)this->__handle)->stylesheet;
    }
    void Application::stylesheet( ::hyve::lang::string v) const {
        if (((QT::application)this->__handle)->stylesheet) {
            hyve::dealloc(((QT::application)this->__handle)->stylesheet);
        };
        ((QT::application)this->__handle)->stylesheet = v ? hyve::strdup(v) : NULL;
    }
    
    /* ::Qt::Application::construct(::Qt::Application object) */
    ::hyve::lang::int16 Application::construct(const QT::Application &object) {
    /* $begin(::Qt::Application::construct(::Qt::Application object)) */
        (void)object;

        if (object._handle()->stylesheet) {
            QFile file(object._handle()->stylesheet);
            if (file.open(QFile::ReadOnly)) {
                QString styleSheet = QLatin1String(file.readAll());
                ::app->setStyleSheet(styleSheet);
            } else {
                hyve::error("Qt::Application::construct: stylesheet '%s' not found.", object._handle()->stylesheet);
            }
        }

        return 0;
    /* $end */
    }
    
    /* ::Qt::Application::destruct(::Qt::Application object) */
    ::hyve::lang::_void Application::destruct(const QT::Application &object) {
    /* $begin(::Qt::Application::destruct(::Qt::Application object)) */
        (void)object;

        if (!hyve::adec(&used)) {
            delete ::app;
        }
    /* $end */
    }
    
    /* ::Qt::Application::exec() */
    ::hyve::lang::_void Application::exec() const {
    /* $begin(::Qt::Application::exec()) */
	
        /* Execute application */
        ::app->exec();

        /* If there are still threads in the post-method, wait for them to finish. Without this
         * timeout, the mainthread may finish before the threads get the chance to finish their
         * processing in the post-method, causing potential resource-leaks. */
        hyve::sleep(0,100000000); /* Twice the value of the timeout in the wait-to-post loop */

    /* $end */
    }
    
    /* ::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
    ::hyve::lang::ObservableEvent Application::getEvent(const ::hyve::lang::Observer &observer, const ::hyve::lang::Object &me, const ::hyve::lang::Object &observable, const ::hyve::lang::Object &src) const {
    /* $begin(::Qt::Application::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)) */
        ::hyve::lang::observableEvent event;

        event = (hyve::lang::observableEvent)hyve::_new((hyve::lang::_typedef)hyve::lang::observableEvent_h,0);
        event->_parent.kind = 1;
        event->observable = observable._handle(); hyve::keep(observable._handle());
        event->observer = observer._handle(); hyve::keep(observer._handle());
        event->me = me._handle();
        if (event->me) {
            hyve::keep(me._handle());
        }
        event->source = src._handle();
        if (event->source) {
            hyve::keep(src._handle());
        }

        hyve::lang::ObservableEvent result(event);
        return result;
    /* $end */
    }
    
    /* ::Qt::Application::init(::Qt::Application object) */
    ::hyve::lang::int16 Application::init(const QT::Application &object) {
    /* $begin(::Qt::Application::init(::Qt::Application object)) */
        if (hyve::ainc(&used) == 1) {
            __argc = object.arg().length;
            __argv = (char**)object.arg().buffer;
            ::app = new QTApplication(object._handle());
        }

        /* Get qEventId */
        FractalEventType = QEvent::registerEventType();

        return 0;
    /* $end */
    }
    
    /* ::Qt::Application::post(::hyve::lang::event event) */
    ::hyve::lang::_void Application::post(const ::hyve::lang::Event &event) const {
    /* $begin(::Qt::Application::post(::hyve::lang::event event)) */

        /* Fractal observable event - check whether to execute in current contex, or to forward */
        if (::app->instance()->thread() == QThread::currentThread()) {
            if (!::aboutToQuit) {
                if (event.kind() == 1) {
                    ::hyve::lang::observableEvent e;
                    e = (hyve::lang::observableEvent)event._handle();
                    if (e->me) {
                        hyve::call((hyve::lang::function)e->observer, NULL, e->me, e->observable, e->source);
                    } else {
                        hyve::call((hyve::lang::function)e->observer, NULL, e->observable, e->source);
                    }
                }
            }

            /* Mark event as processed, used for handling synchronous events. */
            event.processed();

            /* Free event */
            hyve::free(event._handle(), event._handle(), "Free dispatcher event.");
        } else {
            /* Post asynchronous event */
            if (!::aboutToQuit) {
                while(eventsWaiting > 20) {
                    hyve::sleep(0,50000000);
                    if (::aboutToQuit) {
                        break;
                    }
                }

                if (!::aboutToQuit) {
                    FractalEvent *e = new FractalEvent(event._handle());
                    hyve::ainc(&eventsWaiting);
                    ::app->postEvent(::app, e);
                } else {
                    hyve::free(event._handle(), event._handle(), "Free dispatcher event.");
                }
            } else {
                hyve::free(event._handle(), event._handle(), "Free dispatcher event.");
            }
        }
    /* $end */
    }
}

