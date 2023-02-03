/*
** Description:
** EventManager's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "eventManager.h"
#include "system.h"

#include "iEvent.h"
#include "eventOnClose.h"

static void EventManager_handleEvents(EventManagerClass *this, SystemClass *system)
{
    while (sfRenderWindow_pollEvent(system->_window->_window, &(this->_event))) {
        for (size_t i = 0; i < len(this->_eventArray); i++)
            runEvent(getitem(this->_eventArray, i), this, system);
    }
}

static void EventManager_ctor(EventManagerClass *this, __UNUSED__ va_list *args)
{
    this->_eventArray = new(Array, EVENTNUMBER, IEvent);

    createEvent(this->_eventArray, 0, EventOnClose);

    printf("EventManager()\n");
}

static void EventManager_dtor(   EventManagerClass *this)
{
    // Release internal resources
    delete(this->_eventArray);

    printf("~EventManager()\n");
}

static const EventManagerClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(EventManagerClass),
        .__name__ = "EventManager",
        .__ctor__ = (ctor_t)&EventManager_ctor,
        .__dtor__ = (dtor_t)&EventManager_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._eventArray = NULL,
    /* Methods definitions */
    .__handleEvents__ = &EventManager_handleEvents,
};

const Class *EventManager = (const Class *)&_description;