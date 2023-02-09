/* File: Event.h
**
** Description: Event's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include <SFML/Window.h>

    #include "object.h"

    #include "CSFMLTypes.h"

    typedef void (*runEvent_t)(EventClass*, sfEvent, SystemClass*);

    typedef struct s_EventClass {

        /* Inheritance */
        Class base;

        /* Methods definitions */
        void (*__run__)(struct s_EventClass*, sfEvent, SystemClass*);

    } EventClass;

    extern const Class *Event;

    #define runEvent(i, e, s) ((EventClass*)i)->__run__(i, e, s)

#endif /* !EVENT_H_ */