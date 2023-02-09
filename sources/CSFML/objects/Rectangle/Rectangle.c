/* File: Rectangle.c
**
** Description: Rectangle's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Rectangle.h"

static void Rectangle_ctor(RectangleClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->_shape = sfRectangleShape_create()))
        raise("Can't create sfRectangleShape");

    setRectPosition(this, va_arg(*args, sfVector2f));
    setRectSize(this, va_arg(*args, sfVector2f));
    setRectFillColor(this, va_arg(*args, sfColor));
    setRectOutlineThickness(this, va_arg(*args, double));
    setRectOutlineColor(this, va_arg(*args, sfColor));

    printf("Rect()\n");
}

static void Rectangle_dtor(RectangleClass *this)
{
    // Release internal resources
    if (this->_shape)
        sfRectangleShape_destroy(this->_shape);

    printf("~Rect()\n");
}

static const RectangleClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(RectangleClass),
        .__name__ = "Rect",
        .__ctor__ = (ctor_t)&Rectangle_ctor,
        .__dtor__ = (dtor_t)&Rectangle_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._shape = NULL,
};

const Class *Rectangle = (const Class *)&_description;