/*
** Description:
** ButtonManager Class's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef BUTTONMANAGER_H_
    #define BUTTONMANAGER_H_

    #include "object.h"
    #include "array.h"
    #include "new.h"

    #include "button.h"

    typedef struct s_SystemClass SystemClass;
    typedef struct s_WindowClass WindowClass;

    #define BUTTONNUMBER    1

    typedef struct s_ButtonManagerClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*         _buttonArray;

        /* Methods definitions */
        void (*__drawButtons__)(struct s_ButtonManagerClass*,  WindowClass*);
        void (*__processButtons__)(struct s_ButtonManagerClass*,  SystemClass*);

    } ButtonManagerClass;

    #define drawButtons(b, w)       ((ButtonManagerClass*)b)->__drawButtons__(b, w)
    #define processButtons(b, s)    ((ButtonManagerClass*)b)->__processButtons__(b, s)
    #define createButton(b, ...)    ((Container *)b)->__setitem__(b, __VA_ARGS__)

    extern const Class *ButtonManager;

#endif /* !BUTTONMANAGER_H_ */