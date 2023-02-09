/* File: Rectangle.h
**
** Description: Rectangle's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef RECTANGLE_H_
    #define RECTANGLE_H_

    #include <SFML/Graphics.h>

    #include "object.h"

    #include "CSFMLTypes.h"

    typedef struct s_RectangleClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfRectangleShape*  _shape;

    } RectangleClass;

    extern const Class *Rectangle;

    #define drawRect(t, w)                  sfRenderWindow_drawRectangleShape(((WindowClass*)w)->_window, ((RectangleClass*)t)->_shape, NULL);

    #define setRectPosition(r, p)           sfRectangleShape_setPosition(((RectangleClass*)r)->_shape, p)
    #define setRectSize(r, s)               sfRectangleShape_setSize(((RectangleClass*)r)->_shape, s)
    #define setRectFillColor(r, c)          sfRectangleShape_setFillColor(((RectangleClass*)r)->_shape, c)
    #define setRectOutlineColor(r, c)       sfRectangleShape_setOutlineColor(((RectangleClass*)r)->_shape, c)
    #define setRectOutlineThickness(r, t)   sfRectangleShape_setOutlineThickness(((RectangleClass*)r)->_shape, t)

    #define getRectPosition(r)              sfRectangleShape_getPosition(((RectangleClass*)r)->_shape)
    #define getRectSize(r)                  sfRectangleShape_getSize(((RectangleClass*)r)->_shape)
    #define getRectFillColor(r)             sfRectangleShape_getFillColor(((RectangleClass*)r)->_shape)
    #define getRectOutlineColor(r)          sfRectangleShape_getOutlineColor(((RectangleClass*)r)->_shape)
    #define getRectOutlineThickness(r)      sfRectangleShape_getOutlineThickness(((RectangleClass*)r)->_shape)

    #define getRectGlobalBounds(r)          sfRectangleShape_getGlobalBounds(((RectangleClass*)r)->_shape)

#endif /* !RECTANGLE_H_ */