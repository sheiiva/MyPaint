/*
** Description:
** Rect's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "raise.h"

#include "rect.h"
#include "window.h"

static void Rect_draw(RectClass *this, WindowClass *window)
{
    sfRenderWindow_drawRectangleShape(window->_window, this->_shape, NULL);
}

static void Rect_ctor(RectClass *this, va_list *args)
{
    if (!(this->_shape = sfRectangleShape_create()))
        raise("Can't create sfRectangleShape");

    // Initialize internal resources
    setRectPosition(this, va_arg(*args, sfVector2f));
    setRectSize(this, va_arg(*args, sfVector2f));
    setRectFillColor(this, va_arg(*args, sfColor));
    setRectOutlineColor(this, va_arg(*args, sfColor));
    setRectOutlineThickness(this, va_arg(*args, double));

    printf("Rect()\n");
}

static void Rect_dtor(RectClass *this)
{
    // Release internal resources
    if (this->_shape)
        sfRectangleShape_destroy(this->_shape);

    printf("~Rect()\n");
}

static const RectClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(RectClass),
        .__name__ = "Rect",
        .__ctor__ = (ctor_t)&Rect_ctor,
        .__dtor__ = (dtor_t)&Rect_dtor,
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
    /* Methods definitions */
    .__draw__ = &Rect_draw,
};

const Class *Rect = (const Class *)&_description;