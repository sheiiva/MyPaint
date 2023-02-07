/*
** Description:
** Button's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "button.h"
#include "system.h"
#include "window.h"

static void Button_draw(ButtonClass *this, WindowClass *window)
{
    sfRenderWindow_drawRectangleShape(window->_window, this->_shape, NULL);
}

static void Button_processButton(ButtonClass *this, SystemClass *system)
{
    if (isButtonClicked(this, system))
        onButtonClick(this, system);
    else if (isButtonHover(this, system))
        onButtonHover(this, system);
    else
        onButtonDefault(this, system);
}

static void Button_onClick(ButtonClass *this, __UNUSED__ SystemClass *system)
{
    // Change button color
    setButtonFillColor(this, this->_clickColor);
}

static void Button_onHover(ButtonClass *this, __UNUSED__ SystemClass *system)
{
    // Change button color
    setButtonFillColor(this, this->_hoverColor);
}

static void Button_onDefault(ButtonClass *this, __UNUSED__ SystemClass *system)
{
    // Change button color
    setButtonFillColor(this, this->_defaultColor);
}

static sfBool Button_isClicked(ButtonClass *this, SystemClass *system)
{
    this->_state = isButtonHover(this, system) && sfMouse_isButtonPressed(sfMouseLeft) ? CLICK : DEFAULT;
    return (this->_state == CLICK);
}

static sfBool Button_isHover(ButtonClass *this, SystemClass *system)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(system->_window->_window);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(this->_shape);

    this->_state = sfFloatRect_contains(&rect, mousePos.x, mousePos.y) ? HOVER : DEFAULT;
    return (this->_state == HOVER);
}

static void Button_ctor(ButtonClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->_shape = sfRectangleShape_create()))
        raise("Cannot create button.");

    setButtonPosition(this, va_arg(*args, sfVector2f));
    setButtonSize(this, va_arg(*args, sfVector2f));
    this->_defaultColor = va_arg(*args, sfColor);
    this->_hoverColor = va_arg(*args, sfColor);
    this->_clickColor = va_arg(*args, sfColor);

    printf("Button()\n");
}

static void Button_dtor(ButtonClass *this)
{
    // Release internal resources
    if (this->_shape)
        sfRectangleShape_destroy(this->_shape);

    printf("~Button()\n");
}

static const ButtonClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ButtonClass),
        .__name__ = "Button",
        .__ctor__ = (ctor_t)&Button_ctor,
        .__dtor__ = (dtor_t)&Button_dtor,
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
    ._state = DEFAULT,
    /* Methods definitions */
    .__draw__ = &Button_draw,
    .__process__ = &Button_processButton,
    .__onClick__ = &Button_onClick,
    .__onHover__ = &Button_onHover,
    .__onDefault__ = &Button_onDefault,
    .__isClicked__ = &Button_isClicked,
    .__isHover__ = &Button_isHover,
};

const Class *Button = (const Class *)&_description;