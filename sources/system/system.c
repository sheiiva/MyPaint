/*
** Description:
** System's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "system.h"

static void System_display(SystemClass *this)
{
    displayWindow(this->_window);
}

static void System_gloop(SystemClass *this)
{
    this->_running = true;

    while (isWindowOpen(this->_window) && this->_running) {
        // handleEvents(currentScene->eventManager, this);
        // processScene(currentScene, this);
        clearWindow(this->_window);
        displaySystem(this);
    }
}

static void System_ctor(SystemClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_window = new(Window);
    this->_clock = new(Clock);

    printf("System()\n");
}

static void System_dtor(SystemClass *this)
{
    delete(this->_window);
    delete(this->_clock);

    printf("~System()\n");
}

static const SystemClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SystemClass),
        .__name__ = "System",
        .__ctor__ = (ctor_t)&System_ctor,
        .__dtor__ = (dtor_t)&System_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._running = false,
    ._window = NULL,
    ._clock = NULL,
    /* Methods definitions */
    .__display__ = &System_display,
    .__gameLoop__ = &System_gloop,
};

const Class *System = (const Class *)&_description;