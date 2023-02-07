/*
** Description:
** Text's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "raise.h"

#include "text.h"
#include "window.h"

static void Text_draw(TextClass *this, WindowClass *window)
{
    sfRenderWindow_drawText(window->_window, this->_text, NULL);
}

static void Text_ctor(TextClass *this, va_list *args)
{
    if (!(this->_text = sfText_create()))
        raise("Can't create sfText");
    // Initialize internal resources
    setTextString(this, va_arg(*args, char*));
    setTextSize(this, va_arg(*args, unsigned int));
    setTextPosition(this, va_arg(*args, sfVector2f));

    // Set colors
    this->_defaultColor = va_arg(*args, sfColor);
    this->_clickColor = va_arg(*args, sfColor);
    this->_hoverColor = va_arg(*args, sfColor);
    setTextColor(this, this->_defaultColor);

    // Set font
    if (!(this->_font = sfFont_createFromFile(va_arg(*args, char*))))
        raise("Can't create sfFont");
    setTextFont(this, this->_font);

    printf("Text()\n");
}

static void Text_dtor(TextClass *this)
{
    // Release internal resources
    if (this->_text)
        sfText_destroy(this->_text);
    if (this->_font)
        sfFont_destroy(this->_font);

    printf("~Text()\n");
}

static const TextClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(TextClass),
        .__name__ = "Text",
        .__ctor__ = (ctor_t)&Text_ctor,
        .__dtor__ = (dtor_t)&Text_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._text = NULL,
    ._font = NULL,
    ._state = DEFAULT,
    /* Methods definitions */
    .__draw__ = &Text_draw,
};

const Class *Text = (const Class *)&_description;