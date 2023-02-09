/* File: window.h
**
** Description: Window's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

    #include "object.h"

    typedef struct s_WindowClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfVideoMode         _mode;
        sfRenderWindow*     _window;

    } WindowClass;

    extern const Class *Window;

    #define setFrameRate(c, f)       sfRenderWindow_setFramerateLimit(((WindowClass*)c)->_window, f)
    #define clearWindow(c)           sfRenderWindow_clear(((WindowClass*)c)->_window, sfBlack)
    #define displayWindow(c)         sfRenderWindow_display(((WindowClass*)c)->_window)
    #define isWindowOpen(c)          sfRenderWindow_isOpen(((WindowClass*)c)->_window)
    #define closeWindow(c)           sfRenderWindow_close(((WindowClass*)c)->_window)

#endif /* !WINDOW_H_ */