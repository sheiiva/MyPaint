/*
** Description:
** Scene's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "scene.h"
#include "system.h"
#include "window.h"

#include "fileButton.h"

static void Scene_draw(SceneClass *this, WindowClass* window)
{
    // for (size_t i = 0; i < len(this->images); i++)
    //     displayImage(getitem(this->images, i), window);
    // for (size_t i = 0; i < len(this->texts); i++)
    //     displayText(getitem(this->texts, i), window);
    drawButtons(this->_mbuttons, window);
}

static void Scene_process(__UNUSED__ SceneClass *this, SystemClass *system)
{
    sfTime time = sfClock_getElapsedTime(system->_clock->_clock);

    // No need to refresh the scene
    if ((time.microseconds / 1000000.0) <= TIMEREFRESH)
        return;

    processButtons(this->_mbuttons, system);
    sfClock_restart(system->_clock->_clock);
}

static void Scene_ctor(SceneClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_mbuttons = new(ButtonManager, BUTTONNUMBER);

    setButton(this->_mbuttons, FILEBUTTON_I, FILEBUTTON_POS, FILEBUTTON_SIZE, FILEBUTTON_DEFAULT_COLOR, FILEBUTTON_HOVER_COLOR, FILEBUTTON_CLICK_COLOR, &FileButton_onClick);

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
    ._mbuttons = NULL,
    /* Methods definitions */
    .__draw__ = &Scene_draw,
    .__process__ = &Scene_process,
};

const Class *Scene = (const Class *)&_description;