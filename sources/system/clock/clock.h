/*
** Description:
** System's Clock structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef CLOCK_H_
    #define CLOCK_H_

    #include <SFML/System.h>

    # include "object.h"

    typedef struct s_class {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfClock *clock;
    } ClockClass;

    extern const Class *Clock;

#endif /* !CLOCK_H_ */