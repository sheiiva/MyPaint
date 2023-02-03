/*
** Description:
** Window's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>

    #include "object.h"

    #define FRAMERATE 60

    typedef struct s_WindowClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfVideoMode         _mode;
        sfRenderWindow*     _window;

        /* Methods Pointers*/
        void    (*__clear__)(struct s_WindowClass*);
        void    (*__display__)(struct s_WindowClass*);
        sfBool  (*__isOpen__)(struct s_WindowClass*);

    } WindowClass;

    extern const Class *Window;

    #define clearWindow(c)           ((WindowClass*)c)->__clear__(c)
    #define displayWindow(c)         ((WindowClass*)c)->__display__(c)
    #define isWindowOpen(c)          ((WindowClass*)c)->__isOpen__(c)

#endif /* !WINDOW_H_ */