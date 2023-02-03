/*
** Description:
** System's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "system.h"
#include "scene.h"

static void System_display(SystemClass *this)
{
    this->_scene->__display__(this->_scene, this->_window->_window);
    // displayScene(this->_scene, this->_window->_window)
    displayWindow(this->_window);
}

static void System_gloop(SystemClass *this)
{
    this->_running = true;

    while (isWindowOpen(this->_window) && this->_running) {
        handleEvents(this->_eventManager, this);
        processScene(this->_scene, this);
        clearWindow(this->_window);
        displaySystem(this);
    }
}

static void System_ctor(SystemClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_clock = new(Clock);
    this->_eventManager = new(EventManager);
    this->_scene = new(Scene);
    this->_window = new(Window);

    printf("System()\n");
}

static void System_dtor(SystemClass *this)
{
    delete(this->_clock);
    delete(this->_eventManager);
    delete(this->_scene);
    delete(this->_window);

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
    ._clock = NULL,
    ._eventManager = NULL,
    ._scene = NULL,
    ._window = NULL,
    /* Methods definitions */
    .__display__ = &System_display,
    .__gameLoop__ = &System_gloop,
};

const Class *System = (const Class *)&_description;