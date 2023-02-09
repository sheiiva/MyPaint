/* File: gui_state.h
**
** Description: GUI's states
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef GUI_STATE_H_
    #define GUI_STATE_H_

    typedef enum e_gui_state {
        DEFAULT,
        HOVER,
        CLICKED,
        HIDDEN
    } gui_state;

#endif /* !GUI_STATE_H_ */