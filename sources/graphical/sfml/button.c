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

static void Button_draw(ButtonClass *this, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, this->_shape, NULL);
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
    if (isButtonHover(this, system) && sfMouse_isButtonPressed(sfMouseLeft))
        this->_state = CLICK;
    else
        this->_state = DEFAULT;
    return (this->_state == CLICK);
}

static sfBool Button_isHover(ButtonClass *this, SystemClass *system)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(system->_window->_window);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(this->_shape);

    if (sfFloatRect_contains(&rect, mousePos.x, mousePos.y)) {
        this->_state = HOVER;
    } else {
        this-> _state = DEFAULT;
    }
    return (this->_state == HOVER);
}

static void Button_setPosition(ButtonClass *this, sfVector2f pos)
{
    sfRectangleShape_setPosition(this->_shape, pos);
}

static void Button_setSize(ButtonClass *this, sfVector2f size)
{
    sfRectangleShape_setSize(this->_shape, size);
}

static void Button_setFillColor(ButtonClass *this, sfColor color)
{
    sfRectangleShape_setFillColor(this->_shape, color);
}

static void Button_setOutlineColor(ButtonClass *this, sfColor color)
{
    sfRectangleShape_setOutlineColor(this->_shape, color);
}

static void Button_setOutlineThickness(ButtonClass *this, float thickness)
{
    sfRectangleShape_setOutlineThickness(this->_shape, thickness);
}

static void Button_ctor(ButtonClass *this, va_list *args)
{
    // Initialize internal resources
    this->_shape = sfRectangleShape_create();
    if (!this->_shape)
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
    .__setPosition__ = &Button_setPosition,
    .__setSize__ = &Button_setSize,
    .__setFillColor__ = &Button_setFillColor,
    .__setOutlineColor__ = &Button_setOutlineColor,
    .__setOutlineThickness__ = &Button_setOutlineThickness
};

const Class *Button = (const Class *)&_description;