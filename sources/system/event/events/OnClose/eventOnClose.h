/*
** Description:
** Event OnClose structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef EVENTONCLOSE_H_
    #define EVENTONCLOSE_H_

    #include "iEvent.h"

    typedef struct s_EventOnCloseClass {

        /* Inheritance */
        IEventClass iEvent;

        /* Special Definition*/

    } EventOnCloseClass;

    extern const Class *EventOnClose;

#endif /* !EVENTONCLOSE_H_ */