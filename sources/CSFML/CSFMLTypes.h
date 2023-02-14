/* File: SFMLTypes.h
**
** Description: CSFML types
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef SFMLTYPES_H_
    #define SFMLTYPES_H_

    typedef enum e_gui_state gui_state;

    /// OBJECTS ///////////

    // SFML Object's class
    typedef struct s_SFMLObjectClass SFMLObjectClass;
    // Button's class
    typedef struct s_ButtonClass ButtonClass;
    // Image's class
    typedef struct s_ImageClass ImageClass;
    // Text's class
    typedef struct s_TextClass TextClass;
    // Rectangle's class
    typedef struct s_RectangleClass RectangleClass;

    /// SYSTEM ///////////

    // Clock's class
    typedef struct s_ClockClass ClockClass;
    // Event's class
    typedef struct s_EventClass EventClass;
    // Scene's class
    typedef struct s_SceneClass SceneClass;
    // System's class
    typedef struct s_SystemClass SystemClass;
    // Window's class
    typedef struct s_WindowClass WindowClass;

    /// EVENTS ///////////

    // Event's class
    typedef struct s_EventClass EventClass;
    // EventManager's class
    typedef struct s_EventManagerClass EventManagerClass;
    // EventOnClose's class
    typedef struct s_EventOnCloseClass EventOnCloseClass;

    /// CALLBACKS ///////////
    typedef void (*OnClick)(ButtonClass*, SystemClass*);

#endif /* !SFMLTYPES_H_ */