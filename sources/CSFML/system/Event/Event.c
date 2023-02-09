/* File: Event.c
**
** Description: Event's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Event.h"

void Event_run(__UNUSED__ EventClass *this, __UNUSED__ sfEvent event, __UNUSED__ SystemClass* system)
{
    return;
}

static void Event_ctor(__UNUSED__ EventClass *this, __UNUSED__ va_list *args)
{
    printf("~Event()\n");
}

static void Event_dtor(__UNUSED__ EventClass *this)
{
    printf("~Event()\n");
}

static const EventClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(EventClass),
        .__name__ = "Event",
        .__ctor__ = (ctor_t)&Event_ctor,
        .__dtor__ = (dtor_t)&Event_dtor,
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
    .__run__ = &Event_run,
};

const Class *Event = (const Class *)&_description;