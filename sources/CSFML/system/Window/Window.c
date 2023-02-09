/*
** Description:
** Window's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "Window.h"

static void Window_ctor(WindowClass *this, va_list *args)
{
    // Initialize internal resources
    this->_mode = va_arg(*args, sfVideoMode);
    this->_window = sfRenderWindow_create(this->_mode, va_arg(*args, char*), sfResize | sfClose, NULL);
    if (!this->_window)
        raise("Cannot create window.");

    setFrameRate(this, va_arg(*args, unsigned int));

    printf("Window()\n");
}

static void Window_dtor(WindowClass *this)
{
    // Release internal resources
    if (this->_window)
        sfRenderWindow_destroy(this->_window);

    printf("~Window()\n");
}

static const WindowClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(WindowClass),
        .__name__ = "Window",
        .__ctor__ = (ctor_t)&Window_ctor,
        .__dtor__ = (dtor_t)&Window_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._window = NULL,
};

const Class *Window = (const Class *)&_description;