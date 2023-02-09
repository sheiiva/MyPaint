/* File: Text.c
**
** Description: Text's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Text.h"

static void Text_ctor(TextClass *this, va_list *args)
{
    // Initialize internal resources
    this->_text = sfText_create();
    if (!this->_text)
        raise("Can't create sfText");

    setTextString(this, va_arg(*args, char*));
    setTextSize(this, va_arg(*args, unsigned int));
    setTextPosition(this, va_arg(*args, sfVector2f));
    setTextColor(this, va_arg(*args, sfColor));

    // Set font
    this->_font = sfFont_createFromFile(va_arg(*args, char*));
    if (!this->_font)
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
};

const Class *Text = (const Class *)&_description;