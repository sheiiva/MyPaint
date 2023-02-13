/* File: scene.h
**
** Description: Scene's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"
    #include "array.h"

    #include "CSFMLTypes.h"

    typedef struct s_SceneClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*         _rects;
        Object*         _buttons;
        Object*         _texts;
        // Object*     _images;
        // Object*     _sounds;

        EventManagerClass*  _eventManager;

        /* Methods definitions */
        void    (*__draw__)(struct s_SceneClass*, WindowClass*);
        void    (*__process__)(struct s_SceneClass*, SystemClass*);

        void    (*__init__)(struct s_SceneClass*, char const*);

    } SceneClass;

    extern const Class *Scene;

    #define drawScene(s, w)         ((SceneClass*)s)->__draw__(s, w)
    #define processScene(s, sys)    ((SceneClass*)s)->__process__(s, sys)

    #define initScene(s, p)         ((SceneClass*)s)->__init__(s, p)

#endif /* !SCENE_H_ */