/*
** Description:
** System's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include "object.h"
    #include "new.h"

    #include "clock.h"
    #include "eventManager.h"
    #include "window.h"

    #define TIMEREFRESH 0.1

    typedef struct s_SceneClass SceneClass;

    typedef struct s_SystemClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        int                 _running;
        ClockClass*         _clock;
        EventManagerClass*  _eventManager;
        SceneClass*         _scene;
        WindowClass*        _window;

        /* Methods definitions*/
        void    (*__gameLoop__)(struct s_SystemClass*);
        void    (*__display__)(struct s_SystemClass*);

    } SystemClass;

    extern const Class *System;

    #define displaySystem(c)       ((SystemClass*)c)->__display__(c)
    #define run(c)              ((SystemClass*)c)->__gameLoop__(c)

#endif /* !SYSTEM_H_ */