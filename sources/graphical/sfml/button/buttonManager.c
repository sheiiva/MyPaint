/*
** Description:
** ButtonManager's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "buttonManager.h"

#include "window.h"
#include "system.h"

static void ButtonManager_drawButtons(ButtonManagerClass *this, WindowClass *window)
{
    for (size_t i = 0; i < len(this->_buttonArray); i++)
        drawButton(getitem(this->_buttonArray, i), window);
}

static void ButtonManager_processButtons(ButtonManagerClass *this, SystemClass *system)
{
    for (size_t i = 0; i < len(this->_buttonArray); i++)
        processButton(getitem(this->_buttonArray, i), system);
}

static void ButtonManager_setButton(ButtonManagerClass *this, ...)
{
    va_list args;
    va_start(args, this);

    size_t index = va_arg(args, size_t);
    ButtonClass *button = getitem(this->_buttonArray, index);

    setButtonPosition(button, va_arg(args, sfVector2f));
    setButtonSize(button, va_arg(args, sfVector2f));
    button->_defaultColor = va_arg(args, sfColor);
    button->_clickColor = va_arg(args, sfColor);
    button->_hoverColor = va_arg(args, sfColor);
    button->__onClick__ = va_arg(args, void (*)(ButtonClass*, SystemClass*));

    va_end(args);
}

static void ButtonManager_ctor(ButtonManagerClass *this, va_list *args)
{
    this->_buttonArray = new(Array, va_arg(*args, size_t), Button);

    printf("ButtonManager()\n");
}

static void ButtonManager_dtor(__UNUSED__ ButtonManagerClass *this)
{
    // Release internal resources
    delete(this->_buttonArray);

    printf("~ButtonManager()\n");
}

static const ButtonManagerClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ButtonManagerClass),
        .__name__ = "ButtonManager",
        .__ctor__ = (ctor_t)&ButtonManager_ctor,
        .__dtor__ = (dtor_t)&ButtonManager_dtor,
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
    .__drawButtons__ = &ButtonManager_drawButtons,
    .__processButtons__ = &ButtonManager_processButtons,
    .__setButton__ = &ButtonManager_setButton
};

const Class *ButtonManager = (const Class *)&_description;