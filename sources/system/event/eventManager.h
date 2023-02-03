/*
** Description:
** EventManagerClass's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef EVENTMANAGER_H_
    #define EVENTMANAGER_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "new.h"
    #include "array.h"

    typedef struct s_SystemClass SystemClass;

    typedef struct s_EventManagerClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfEvent     _event;
        Object*     _eventArray;

        /* Methods definitions */
        void (*__handleEvents__)(struct s_EventManagerClass*,  SystemClass*);

    } EventManagerClass;

    extern const Class *EventManager;

    #define handleEvents(e, s)  ((EventManagerClass*)e)->__handleEvents__(e, s)
    #define createEvent(c, ...) ((Container *)c)->__setitem__(c, __VA_ARGS__)

    #define EVENTNUMBER 1

#endif /* !EVENTMANAGER_H_ */