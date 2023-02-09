/* File: eventOnClose.c
**
** Description: Event's OnClose methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "EventOnClose.h"

#include "Window.h"
#include "System.h"

void EventOnClose_run(__UNUSED__ EventClass *this, sfEvent event, SystemClass* system)
{
    if (event.type == sfEvtClosed)
        closeWindow(system->_window);
}