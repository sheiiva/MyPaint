/*
** Description:
** Scene's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "scene.h"

static void Scene_display(__UNUSED__ SceneClass *this, __UNUSED__ sfRenderWindow* window)
{
    // for (size_t i = 0; i < len(this->images); i++)
    //     displayImage(getitem(this->images, i), window);
    // for (size_t i = 0; i < len(this->texts); i++)
    //     displayText(getitem(this->texts, i), window);
}

static void Scene_process(__UNUSED__ SceneClass *this, SystemClass *system)
{
    sfTime time = sfClock_getElapsedTime(system->_clock->_clock);

    if ((time.microseconds / 1000000.0) > TIMEREFRESH) {
        // PROCESS ACTIONS
        // [...]
        sfClock_restart(system->_clock->_clock);
    }
}

static void Scene_ctor(__UNUSED__ SceneClass *this, __UNUSED__ va_list *args)
{
    printf("Scene()\n");
}

static void Scene_dtor(__UNUSED__ SceneClass *this)
{
    // Release internal resources

    printf("~Scene()\n");
}

static const SceneClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SceneClass),
        .__name__ = "Scene",
        .__ctor__ = (ctor_t)&Scene_ctor,
        .__dtor__ = (dtor_t)&Scene_dtor,
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
    .__display__ = &Scene_display,
    .__process__ = &Scene_process,
};

const Class *Scene = (const Class *)&_description;