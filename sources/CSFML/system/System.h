/* File: system.h
**
** Description: System's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include "object.h"
    #include "new.h"

    #include "CSFMLTypes.h"

    typedef void (*initSystem_t)(SystemClass*);

    typedef struct s_SystemClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        WindowClass*        _window;
        ClockClass*         _clock;
        int                 _fps;

        EventManagerClass*  _eventManager;

        ssize_t             _currentScene; // -1 : Exit
        Object*             _scenes;

        /* Methods definitions*/
        void    (*__loop__)(struct s_SystemClass*);
        void    (*__display__)(struct s_SystemClass*);

    } SystemClass;

    extern const Class *System;

    #define displaySystem(c)        ((SystemClass*)c)->__display__(c)
    #define run(c)                  ((SystemClass*)c)->__loop__(c)

#endif /* !SYSTEM_H_ */