/*
** Description:
** ButtonManager Class's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
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

    typedef struct s_ButtonManagerClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*         _buttonArray;

        /* Methods definitions */
        void (*__drawButtons__)(struct s_ButtonManagerClass*,  WindowClass*);
        void (*__processButtons__)(struct s_ButtonManagerClass*,  SystemClass*);
        void (*__setButton__)(struct s_ButtonManagerClass*, ...);

    } ButtonManagerClass;

    #define drawButtons(b, w)       ((ButtonManagerClass*)b)->__drawButtons__(b, w)
    #define processButtons(b, s)    ((ButtonManagerClass*)b)->__processButtons__(b, s)
    #define setButton(b, ...)       ((ButtonManagerClass*)b)->__setButton__(b, __VA_ARGS__)
    #define getButton(b, i)         getitem(((ButtonManagerClass*)b)->_buttonArray, i)

    extern const Class *ButtonManager;

#endif /* !BUTTONMANAGER_H_ */