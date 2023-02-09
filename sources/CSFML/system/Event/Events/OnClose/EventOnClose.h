/* File: eventOnClose.h
**
** Description: Event's OnClose class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef EVENTONCLOSE_H_
    #define EVENTONCLOSE_H_

    #include <SFML/Window.h>

    #include "CSFMLTypes.h"

    #include "object.h"

    void EventOnClose_run(EventClass*, sfEvent, SystemClass*);

#endif /* !EVENTONCLOSE_H_ */