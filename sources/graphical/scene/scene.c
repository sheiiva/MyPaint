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

#include "rect.h"
#include "fileButton.h"
#include "helpButton.h"
#include "colors.h"
#include "fonts.h"

static void Scene_draw(SceneClass *this, WindowClass* window)
{
    // Draw the background
    sfRenderWindow_clear(window->_window, LIGHT_GRAY);
    for (size_t i = 0; i < len(this->_arect); i++)
        drawRect(getitem(this->_arect, i), window);
    // Draw canvas
    // Draw texts
    // Draw buttons
    drawButtons(this->_mbuttons, window);
}

static void Scene_process(SceneClass *this, SystemClass *system)
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

    // Rectangle shapes
    this->_arect = new(Array, 1, Rect,
        (sfVector2f){0, 0}, (sfVector2f){1920, 50}, WHITE, WHITE, 0
    );

    // Buttons
    this->_mbuttons = new(ButtonManager, BUTTONNUMBER);
    // File button
    setButton(this->_mbuttons, FILEBUTTON_I, FILEBUTTON_POS, FILEBUTTON_SIZE, FILEBUTTON_DEFAULT_COLOR, FILEBUTTON_HOVER_COLOR, FILEBUTTON_CLICK_COLOR, &FileButton_onClick);
    setButtonText(getButton(this->_mbuttons, FILEBUTTON_I), FILEBUTTON_TEXT_STRING, FILEBUTTON_TEXT_SIZE, FILEBUTTON_POS, FILEBUTTON_TEXT_DEFAULT_COLOR, FILEBUTTON_TEXT_CLICK_COLOR, FILEBUTTON_TEXT_HOVER_COLOR, FILEBUTTON_TEXT_FONT);
    // Help button
    setButton(this->_mbuttons, HELPBUTTON_I, HELPBUTTON_POS, HELPBUTTON_SIZE, HELPBUTTON_DEFAULT_COLOR, HELPBUTTON_HOVER_COLOR, HELPBUTTON_CLICK_COLOR, &HelpButton_onClick);
    setButtonText(getButton(this->_mbuttons, HELPBUTTON_I), HELPBUTTON_TEXT_STRING, HELPBUTTON_TEXT_SIZE, HELPBUTTON_POS, HELPBUTTON_TEXT_DEFAULT_COLOR, HELPBUTTON_TEXT_CLICK_COLOR, HELPBUTTON_TEXT_HOVER_COLOR, HELPBUTTON_TEXT_FONT);

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