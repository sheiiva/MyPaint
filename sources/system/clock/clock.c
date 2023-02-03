/*
** Description:
** System's Clock Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "clock.h"

static void Clock_ctor(ClockClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->clock = sfClock_create();
    if (!this->clock)
        raise("Cannot create system's clock.");

    printf("Clock()\n");
}

static void Clock_dtor(ClockClass *this)
{
    // Release internal resources
    sfClock_destroy(this->clock);

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
    .clock = NULL
};

const Class *Clock = (const Class *)&_description;