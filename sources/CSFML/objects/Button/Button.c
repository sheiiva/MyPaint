/* File: Button.c
**
** Description: Button's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Button.h"

#include "gui_state.h"
#include "Rectangle.h"
#include "Text.h"
#include "Window.h"
#include "System.h"

static void Button_draw(ButtonClass *this, WindowClass *window)
{
    drawRect(this->_rectangle, window);
    if (this->_text)
        drawText(this->_text, window);
}

static sfBool Button_isHover(ButtonClass *this, WindowClass *window)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window->_window);
    sfFloatRect rect = getRectGlobalBounds(this->_rectangle);

    return (sfFloatRect_contains(&rect, mousePos.x, mousePos.y));
}

static sfBool Button_isClicked(ButtonClass *this, WindowClass *window)
{
    return (isButtonHover(this, window) && sfMouse_isButtonPressed(sfMouseLeft));
}

static void Button_updateColors(ButtonClass *this)
{
    setRectFillColor(this->_rectangle, this->_colors[this->_state]);
    if (this->_text)
        setTextColor(this->_text, this->_textColors[this->_state]);
}

static void Button_updateState(ButtonClass *this, WindowClass *window)
{
    if (isButtonClicked(this, window))
        this->_state = CLICKED;
    else if (isButtonHover(this, window))
        this->_state = HOVER;
    else
        this->_state = DEFAULT;
}

static void Button_processButton(ButtonClass *this, SystemClass *system)
{
    updateButtonState(this, system->_window);
    updateButtonColors(this);

    if (isButtonClicked(this, system->_window))
        onButtonClick(this, system);
}

static void Button_onClick(__UNUSED__ ButtonClass *this, __UNUSED__ SystemClass *system)
{
    // TO OVERRIDE
}

static void Button_setOnClick(ButtonClass *this, void (*onClick)(ButtonClass *, SystemClass *))
{
    this->__onClick__ = onClick;
}

static void Button_setText(ButtonClass *this, ...)
{
    va_list args;

    if (this->_text)
        delete(this->_text);
    va_start(args, this);
    this->_text = va_new(Text, &args);
    this->_textColors[DEFAULT] = getTextColor(this->_text);
    this->_textColors[HOVER] = va_arg(args, sfColor);
    this->_textColors[CLICKED] = va_arg(args, sfColor);
    va_end(args);

    // Center text
    sfFloatRect textGlobalBounds = getTextGlobalBounds(this->_text);
    unsigned int fontSize = getTextSize(this->_text);

    sfVector2f newPos = {
        .x = getRectPosition(this->_rectangle).x + (getRectSize(this->_rectangle).x / 2) - (textGlobalBounds.width / 2),
        .y = getRectPosition(this->_rectangle).y + (getRectSize(this->_rectangle).y / 2) - (fontSize / 2)
    };

    setTextPosition(this->_text, newPos);
}

static void Button_set(ButtonClass *this, ...)
{
    va_list args;

    va_start(args, this);
    this->_rectangle = va_new(Rectangle, &args);

    printf("Rect created\n");

    this->_colors[DEFAULT] = getRectFillColor(this->_rectangle);
    this->_colors[HOVER] = va_arg(args, sfColor);
    this->_colors[CLICKED] = va_arg(args, sfColor);
    va_end(args);
}

static void Button_ctor(__UNUSED__ ButtonClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources

    printf("Button()\n");
}

static void Button_dtor(ButtonClass *this)
{
    // Release internal resources
    if (this->_rectangle)
        delete(this->_rectangle);
    if (this->_text)
        delete(this->_text);

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
    ._rectangle = NULL,
    ._text = NULL,
    ._state = DEFAULT,
    /* Methods definitions */
    .__set__ = &Button_set,
    .__draw__ = &Button_draw,
    .__process__ = &Button_processButton,
    .__updateColors__ = &Button_updateColors,
    .__updateState__ = &Button_updateState,
    .__isHover__ = &Button_isHover,
    .__isClicked__ = &Button_isClicked,
    .__onClick__ = &Button_onClick,
    .__setOnClick__ = &Button_setOnClick,
    .__setText__ = &Button_setText
};

const Class *Button = (const Class *)&_description;