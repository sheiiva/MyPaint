/*
** Description:
** Button's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"
    #include "gui_state.h"

    typedef struct s_SystemClass SystemClass;
    typedef struct s_WindowClass WindowClass;

    typedef struct s_ButtonClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfRectangleShape*  _shape;
        gui_state          _state;
        sfColor            _defaultColor;
        sfColor            _clickColor;
        sfColor            _hoverColor;

        /* Methods Pointers*/
        void    (*__draw__)(struct s_ButtonClass*, WindowClass*);
        void    (*__process__)(struct s_ButtonClass*, SystemClass*);

        void    (*__onClick__)(struct s_ButtonClass*, SystemClass*);
        void    (*__onHover__)(struct s_ButtonClass*, SystemClass*);
        void    (*__onDefault__)(struct s_ButtonClass*, SystemClass*);

        sfBool  (*__isClicked__)(struct s_ButtonClass*, SystemClass*);
        sfBool  (*__isHover__)(struct s_ButtonClass*, SystemClass*);

    } ButtonClass;

    extern const Class *Button;

    #define drawButton(b, w)                ((ButtonClass*)b)->__draw__(b, w)
    #define processButton(b, s)             ((ButtonClass*)b)->__process__(b, s)

    #define onButtonClick(b, s)             ((ButtonClass*)b)->__onClick__(b, s)
    #define onButtonHover(b, s)             ((ButtonClass*)b)->__onHover__(b, s)
    #define onButtonDefault(b, s)           ((ButtonClass*)b)->__onDefault__(b, s)

    #define isButtonHover(b, e)             ((ButtonClass*)b)->__isHover__(b, e)
    #define isButtonClicked(b, e)           ((ButtonClass*)b)->__isClicked__(b, e)

    #define setButtonPosition(b, p)          sfRectangleShape_setPosition(((ButtonClass*)b)->_shape, p)
    #define setButtonSize(b, s)              sfRectangleShape_setSize(((ButtonClass*)b)->_shape, s)
    #define setButtonFillColor(b, c)         sfRectangleShape_setFillColor(((ButtonClass*)b)->_shape, c)
    #define setButtonOutlineColor(b, c)      sfRectangleShape_setOutlineColor(((ButtonClass*)b)->_shape, c)
    #define setButtonOutlineThickness(b, t)  sfRectangleShape_setOutlineThickness(((ButtonClass*)b)->_shape, t)

#endif /* !BUTTON_H_ */