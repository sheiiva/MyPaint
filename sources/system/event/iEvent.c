/*
** Description:
** Event's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "iEvent.h"

static const IEventClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IEventClass),
        .__name__ = "IEvent",
        .__ctor__ = NULL,
        .__dtor__ = NULL,
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
    .__run__ = NULL,
};

const Class *IEvent = (const Class *)&_description;