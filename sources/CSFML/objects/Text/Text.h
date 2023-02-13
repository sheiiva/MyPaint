/* File: Text.h
**
** Description: Text's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Graphics.h>

    #include "object.h"

    #include "fonts.h"
    #include "CSFMLTypes.h"

    typedef struct s_TextClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfText*         _text;
        sfFont*         _font;

        /* Methods Definition */
        void (*__set__)(struct s_TextClass*, ...);

    } TextClass;

    extern const Class *Text;

    #define setText(t, ...)                 ((TextClass*)t)->__set__(t, __VA_ARGS__)

    #define drawText(t, w)                  sfRenderWindow_drawText(((WindowClass*)w)->_window, ((TextClass*)t)->_text, NULL);

    #define setTextString(t, s)             sfText_setString(((TextClass*)t)->_text, s)
    #define setTextSize(t, s)               sfText_setCharacterSize(((TextClass*)t)->_text, s)
    #define setTextPosition(t, p)           sfText_setPosition(((TextClass*)t)->_text, p)
    #define setTextColor(t, c)              sfText_setColor(((TextClass*)t)->_text, c)
    #define setTextFont(t, f)               sfText_setFont(((TextClass*)t)->_text, f)

    #define getTextString(t)                sfText_getString(((TextClass*)t)->_text)    
    #define getTextSize(t)                  sfText_getCharacterSize(((TextClass*)t)->_text)
    #define getTextPosition(t)              sfText_getPosition(((TextClass*)t)->_text)
    #define getTextColor(t)                 sfText_getColor(((TextClass*)t)->_text)
    #define getTextFont(t)                  sfText_getFont(((TextClass*)t)->_text)

    #define getTextGlobalBounds(t)          sfText_getGlobalBounds(((TextClass*)t)->_text)

#endif /* !TEXT_H_ */