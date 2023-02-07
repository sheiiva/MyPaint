/*
** Description:
** Text's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Graphics.h>

    #include "object.h"

    #include "gui_state.h"
    #include "colors.h"
    #include "fonts.h"
    #include "text.h"

    typedef struct s_WindowClass WindowClass;

    typedef struct s_TextClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfText*         _text;
        sfFont*         _font;

        gui_state       _state;
        sfColor         _defaultColor;
        sfColor         _clickColor;
        sfColor         _hoverColor;

        /* Methods definitions */
        void (*__draw__)(struct s_TextClass*, WindowClass*);

    } TextClass;

    extern const Class *Text;

    #define drawText(t, w)      ((TextClass*)t)->__draw__(t, w)

    #define setTextString(t, s)             sfText_setString(((TextClass*)t)->_text, s)
    #define setTextSize(t, s)               sfText_setCharacterSize(((TextClass*)t)->_text, s)
    #define setTextPosition(t, p)           sfText_setPosition(((TextClass*)t)->_text, p)
    #define setTextColor(t, c)              sfText_setColor(((TextClass*)t)->_text, c)
    #define setTextFont(t, f)               sfText_setFont(((TextClass*)t)->_text, f)

#endif /* !TEXT_H_ */