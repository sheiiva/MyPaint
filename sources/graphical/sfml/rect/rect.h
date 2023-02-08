/*
** Description:
** Rect's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef RECT_H_
    #define RECT_H_

    #include <SFML/Graphics.h>

    #include "object.h"

    typedef struct s_WindowClass WindowClass;

    typedef struct s_RectClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfRectangleShape*  _shape;

        /* Methods definitions */
        void (*__draw__)(struct s_RectClass*, WindowClass*);

    } RectClass;

    extern const Class *Rect;

    #define drawRect(t, w)                  ((RectClass*)t)->__draw__(t, w)

    #define setRectPosition(r, p)           sfRectangleShape_setPosition(((RectClass*)r)->_shape, p)
    #define setRectSize(r, s)               sfRectangleShape_setSize(((RectClass*)r)->_shape, s)
    #define setRectFillColor(r, c)          sfRectangleShape_setFillColor(((RectClass*)r)->_shape, c)
    #define setRectOutlineColor(r, c)       sfRectangleShape_setOutlineColor(((RectClass*)r)->_shape, c)
    #define setRectOutlineThickness(r, t)   sfRectangleShape_setOutlineThickness(((RectClass*)r)->_shape, t)

#endif /* !RECT_H_ */