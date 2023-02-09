/* File: eventManager.h
**
** Description: EventManager's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef EVENTMANAGER_H_
    #define EVENTMANAGER_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>

    #include "object.h"
    #include "array.h"

    #include "CSFMLTypes.h"

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

    #define handleEvents(e, s)      ((EventManagerClass*)e)->__handleEvents__(e, s)

    #define getEvent(e, i)          getitem(((EventManagerClass*)e)->_eventArray, i)

#endif /* !EVENTMANAGER_H_ */