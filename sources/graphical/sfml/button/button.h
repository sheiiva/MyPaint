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

        void    (*__setPosition__)(struct s_ButtonClass*, sfVector2f);
        void    (*__setSize__)(struct s_ButtonClass*, sfVector2f);
        void    (*__setFillColor__)(struct s_ButtonClass*, sfColor);
        void    (*__setOutlineColor__)(struct s_ButtonClass*, sfColor);
        void    (*__setOutlineThickness__)(struct s_ButtonClass*, float);

    } ButtonClass;

    extern const Class *Button;

    #define drawButton(b, w)                ((ButtonClass*)b)->__draw__(b, w)
    #define processButton(b, s)             ((ButtonClass*)b)->__process__(b, s)

    #define onButtonClick(b, s)             ((ButtonClass*)b)->__onClick__(b, s)
    #define onButtonHover(b, s)             ((ButtonClass*)b)->__onHover__(b, s)
    #define onButtonDefault(b, s)           ((ButtonClass*)b)->__onDefault__(b, s)

    #define isButtonHover(b, e)             ((ButtonClass*)b)->__isHover__(b, e)
    #define isButtonClicked(b, e)           ((ButtonClass*)b)->__isClicked__(b, e)

    #define setButtonPosition(b, p)          ((ButtonClass*)b)->__setPosition__(b, p)
    #define setButtonSize(b, s)              ((ButtonClass*)b)->__setSize__(b, s)
    #define setButtonFillColor(b, c)         ((ButtonClass*)b)->__setFillColor__(b, c)
    #define setButtonOutlineColor(b, c)      ((ButtonClass*)b)->__setOutlineColor__(b, c)
    #define setButtonOutlineThickness(b, t)  ((ButtonClass*)b)->__setOutlineThickness__(b, t)

#endif /* !BUTTON_H_ */