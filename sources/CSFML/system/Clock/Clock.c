/* File: clock.c
**
** Description: Clock's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Clock.h"

static float Clock_getElapsedTime_asSeconds(ClockClass *this)
{
    return sfTime_asSeconds(sfClock_getElapsedTime(this->_clock));
}

static void Clock_ctor(ClockClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_clock = sfClock_create();
    if (!this->_clock)
        raise("Cannot create system's clock.");

    printf("Clock()\n");
}

static void Clock_dtor(ClockClass *this)
{
    // Release internal resources
    if (this->_clock)
        sfClock_destroy(this->_clock);

    printf("~Clock()\n");
}

static const ClockClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ClockClass),
        .__name__ = "Clock",
        .__ctor__ = (ctor_t)&Clock_ctor,
        .__dtor__ = (dtor_t)&Clock_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._clock = NULL,
    // Methods
    .__getElapsedTime_asSeconds__ = &Clock_getElapsedTime_asSeconds
};

const Class *Clock = (const Class *)&_description;