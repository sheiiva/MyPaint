/* File: eventManager.c
**
** Description: EventManager's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "System.h"
#include "Window.h"
#include "EventManager.h"
#include "Event.h"

static void EventManager_handleEvents(EventManagerClass *this, SystemClass *system)
{
    while (sfRenderWindow_pollEvent(system->_window->_window, &(this->_event))) {
        for (size_t i = 0; this->_eventArray && i < len(this->_eventArray); i++)
            runEvent(getEvent(this, i), this->_event, system);
    }
}

static void EventManager_ctor(EventManagerClass *this, va_list *args)
{
    // Init internal resources
    int nbEvents = va_arg(*args, int);

    // Create the event array
    this->_eventArray = new(Array, nbEvents, Event);
    for (int i = 0; i < nbEvents; i++) {
        ((EventClass*)getEvent(this, i))->__run__ = va_arg(*args, runEvent_t);
    }

    printf("EventManager()\n");
}

static void EventManager_dtor(EventManagerClass *this)
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