/* File: Button.h
**
** Description: Button's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"

    #include "CSFMLTypes.h"
    #include "gui_state.h"

    typedef struct s_ButtonClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        RectangleClass*     _rectangle;
        TextClass*          _text;
        // ImageClass*        _image;

        gui_state          _state;
        sfColor         _colors[3];
        sfColor         _textColors[3];

        /* Methods Pointers*/
        void    (*__draw__)(struct s_ButtonClass*, WindowClass*);
        void    (*__process__)(struct s_ButtonClass*, SystemClass*);

        void    (*__updateColors__)(struct s_ButtonClass*);
        void    (*__updateState__)(struct s_ButtonClass*, WindowClass*);

        sfBool  (*__isHover__)(struct s_ButtonClass*, WindowClass*);
        sfBool  (*__isClicked__)(struct s_ButtonClass*, WindowClass*);
        void    (*__onClick__)(struct s_ButtonClass*, SystemClass*);
        void    (*__setOnClick__)(struct s_ButtonClass*, void (*)(struct s_ButtonClass*, SystemClass*));

        void    (*__setText__)(struct s_ButtonClass*, ...);
        // void    (*__setImage__)(struct s_ButtonClass*, ...);

    } ButtonClass;

    extern const Class *Button;

    #define drawButton(b, w)                ((ButtonClass*)b)->__draw__(b, w)
    #define processButton(b, s)             ((ButtonClass*)b)->__process__(b, s)

    #define updateButtonColors(b)           ((ButtonClass*)b)->__updateColors__(b)
    #define updateButtonState(b, w)         ((ButtonClass*)b)->__updateState__(b, w)

    #define isButtonHover(b, w)             ((ButtonClass*)b)->__isHover__(b, w)
    #define isButtonClicked(b, w)           ((ButtonClass*)b)->__isClicked__(b, w)
    #define onButtonClick(b, s)             ((ButtonClass*)b)->__onClick__(b, s)
    #define setButtonOnClick(b, f)          ((ButtonClass*)b)->__setOnClick__(b, f)

    #define setButtonText(b, ...)            ((ButtonClass*)b)->__setText__(b, __VA_ARGS__)
    // #define setButtonImage(b, ...)            ((ButtonClass*)b)->__setImage__(b, __VA_ARGS__)

    #define setButtonPosition(b, p)          setRectPosition(((ButtonClass*)b)->_rectangle, p)
    #define setButtonSize(b, s)              setRectSize(((ButtonClass*)b)->_rectangle, s)
    #define setButtonFillColor(b, c)         setRectFillColor(((ButtonClass*)b)->_rectangle, c)
    #define setButtonOutlineColor(b, c)      setRectOutlineColor(((ButtonClass*)b)->_rectangle, c)
    #define setButtonOutlineThickness(b, t)  setRectOutlineThickness(((ButtonClass*)b)->_rectangle, t)

    #define getButtonPosition(b)             getRectPosition(((ButtonClass*)b)->_rectangle)
    #define getButtonSize(b)                 getRectSize(((ButtonClass*)b)->_rectangle)
    #define getButtonFillColor(b)            getRectFillColor(((ButtonClass*)b)->_rectangle)
    #define getButtonOutlineColor(b)         getRectOutlineColor(((ButtonClass*)b)->_rectangle)
    #define getButtonOutlineThickness(b)     getRectOutlineThickness(((ButtonClass*)b)->_rectangle)

#endif /* !BUTTON_H_ */