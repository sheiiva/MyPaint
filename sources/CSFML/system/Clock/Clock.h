/* File: clock.h
**
** Description: Clock's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef CLOCK_H_
    #define CLOCK_H_

    #include <SFML/System.h>

    #include "object.h"

    typedef struct s_ClockClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfClock*        _clock;

        /* Methods Pointers*/
        float (*__getElapsedTime_asSeconds__)(struct s_ClockClass*);

    } ClockClass;

    extern const Class *Clock;

    #define getElapsedTime_asSeconds(c)     ((ClockClass*)c)->__getElapsedTime_asSeconds__(c)

#endif /* !CLOCK_H_ */