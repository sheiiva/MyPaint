/*
** Description:
** Window's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "window.h"

void Window_clear(WindowClass *this)
{
    sfRenderWindow_clear(this->_window, sfBlack);
}

static void Window_close(WindowClass *this)
{
    sfRenderWindow_close(this->_window);
}

void Window_display(WindowClass *this)
{
    sfRenderWindow_display(this->_window);
}

static sfBool Window_isOpen(WindowClass *this)
{
    return sfRenderWindow_isOpen(this->_window);
}

static void Window_ctor(WindowClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_mode = (sfVideoMode){1920, 1080, 32};
    this->_window = sfRenderWindow_create(this->_mode, "Untitled - MyPaint", sfResize | sfClose, sfNone);
    if (!this->_window)
        raise("Cannot create window.");

    sfRenderWindow_setFramerateLimit(this->_window, FRAMERATE);

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
    /* Methods definitions */
    .__clear__ =    &Window_clear,
    .__close__ =    &Window_close,
    .__display__ =  &Window_display,
    .__isOpen__ =   &Window_isOpen,
};

const Class *Window = (const Class *)&_description;