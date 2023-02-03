/*
** Description:
** Event Interface structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef IEVENT_H_
    #define IEVENT_H_

    #include "object.h"

    typedef struct s_EventManagerClass EventManagerClass;
    typedef struct s_SystemClass SystemClass;

    typedef struct s_IEventClass {

        /* Inheritance */
        Class base;

        /* Methods definitions */
        void (*__run__)(struct s_IEventClass*, EventManagerClass*, SystemClass*);

    } IEventClass;

    extern const Class *IEvent;

    #define runEvent(e, m, s) ((IEventClass*)e)->__run__(e, m, s)

#endif /* !IEVENT_H_ */