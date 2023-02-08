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
    drawRect(this->_canva, window);
    // Draw texts
    for (size_t i = 0; i < len(this->_texts); i++)
        drawText(getitem(this->_texts, i), window);
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

    // Buttons
    this->_mbuttons = new(ButtonManager, BUTTONNUMBER);
    // File button
    setButton(this->_mbuttons, FILEBUTTON_I, FILEBUTTON_POS, FILEBUTTON_SIZE, FILEBUTTON_DEFAULT_COLOR, FILEBUTTON_HOVER_COLOR, FILEBUTTON_CLICK_COLOR, &FileButton_onClick);
    setButtonText(getButton(this->_mbuttons, FILEBUTTON_I), FILEBUTTON_TEXT_STRING, FILEBUTTON_TEXT_SIZE, FILEBUTTON_POS, FILEBUTTON_TEXT_DEFAULT_COLOR, FILEBUTTON_TEXT_CLICK_COLOR, FILEBUTTON_TEXT_HOVER_COLOR, FILEBUTTON_TEXT_FONT);
    // Help button
    setButton(this->_mbuttons, HELPBUTTON_I, HELPBUTTON_POS, HELPBUTTON_SIZE, HELPBUTTON_DEFAULT_COLOR, HELPBUTTON_HOVER_COLOR, HELPBUTTON_CLICK_COLOR, &HelpButton_onClick);
    setButtonText(getButton(this->_mbuttons, HELPBUTTON_I), HELPBUTTON_TEXT_STRING, HELPBUTTON_TEXT_SIZE, HELPBUTTON_POS, HELPBUTTON_TEXT_DEFAULT_COLOR, HELPBUTTON_TEXT_CLICK_COLOR, HELPBUTTON_TEXT_HOVER_COLOR, HELPBUTTON_TEXT_FONT);

    // View button
    setButton(this->_mbuttons, 2, (sfVector2f){100, 5}, HELPBUTTON_SIZE, HELPBUTTON_DEFAULT_COLOR, HELPBUTTON_HOVER_COLOR, HELPBUTTON_CLICK_COLOR, &HelpButton_onClick);
    setButtonText(getButton(this->_mbuttons, 2), "View", HELPBUTTON_TEXT_SIZE, HELPBUTTON_POS, HELPBUTTON_TEXT_DEFAULT_COLOR, HELPBUTTON_TEXT_CLICK_COLOR, HELPBUTTON_TEXT_HOVER_COLOR, HELPBUTTON_TEXT_FONT);

    // Rectangle shapes
    this->_arect = new(Array, 10, Rect,
        (sfVector2f){0, 0}, (sfVector2f){1920, 40}, WHITE, WHITE, 0., // Taskbar
        (sfVector2f){0, 40}, (sfVector2f){1920, 100}, WHITE, WHITE, 0., // Toolbar
        // Section separator
        (sfVector2f){90, 7.5}, (sfVector2f){1, 25}, LIGHT_GRAY, WHITE, 0.,
        (sfVector2f){0, 40}, (sfVector2f){1920, 1}, LIGHT_GRAY, WHITE, 0., // Toolbar separator

        (sfVector2f){150, 50}, (sfVector2f){1, 80}, LIGHT_GRAY, WHITE, 0., // Clipboard section
        (sfVector2f){300, 50}, (sfVector2f){1, 80}, LIGHT_GRAY, WHITE, 0., // Image section
        (sfVector2f){450, 50}, (sfVector2f){1, 80}, LIGHT_GRAY, WHITE, 0., // Tools section
        (sfVector2f){550, 50}, (sfVector2f){1, 80}, LIGHT_GRAY, WHITE, 0., // Brushes section
        (sfVector2f){800, 50}, (sfVector2f){1, 80}, LIGHT_GRAY, WHITE, 0., // Shapes section
        (sfVector2f){900, 50}, (sfVector2f){1, 80}, LIGHT_GRAY, WHITE, 0. // Size section
    );

    this->_texts = new(Array, 7, Text,
        "Clipboard", 15, (sfVector2f){50, 110}, BLACK, BLACK, BLACK, OpenSansRegular,
        "Image", 15, (sfVector2f){200, 110}, BLACK, BLACK, BLACK, OpenSansRegular,
        "Tools", 15, (sfVector2f){360, 110}, BLACK, BLACK, BLACK, OpenSansRegular,
        "Brushes", 15, (sfVector2f){475, 110}, BLACK, BLACK, BLACK, OpenSansRegular,
        "Shapes", 15, (sfVector2f){650, 110}, BLACK, BLACK, BLACK, OpenSansRegular,
        "Size", 15, (sfVector2f){840, 110}, BLACK, BLACK, BLACK, OpenSansRegular,
        "Colours", 15, (sfVector2f){1000, 110}, BLACK, BLACK, BLACK, OpenSansRegular
    );

    this->_canva = new(Rect, (sfVector2f){50, 200}, (sfVector2f){1080, 720}, WHITE, WHITE, 0. );

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