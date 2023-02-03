/*
** Description:
** Scene's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "eventOnClose.h"

#include "window.h"
#include "system.h"

void EventOnClose_run(__UNUSED__ IEventClass *this, EventManagerClass *eventManager, SystemClass* system)
{
    if (eventManager->_event.type == sfEvtClosed)
        closeWindow(system->_window);
}

static void EventOnClose_ctor(__UNUSED__ EventOnCloseClass *this, __UNUSED__ va_list *args)
{
    printf("~EventOnClose()\n");
}

static void EventOnClose_dtor(__UNUSED__ EventOnCloseClass *this)
{
    printf("~EventOnClose()\n");
}

static const EventOnCloseClass _description = {
    { /* IEvent struct */
        {   /* Class struct */
            .__size__ = sizeof(EventOnCloseClass),
            .__name__ = "EventOnClose",
            .__ctor__ = (ctor_t)&EventOnClose_ctor,
            .__dtor__ = (dtor_t)&EventOnClose_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL
        },
        /* Methods definitions */
        .__run__ = &EventOnClose_run,
    }
};

const Class *EventOnClose = (const Class *)&_description;