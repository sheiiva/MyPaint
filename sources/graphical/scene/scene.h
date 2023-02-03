/*
** Description:
** Scene structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"
    #include "new.h"
    #include "array.h"

    // #include "image.h"
    // #include "text.h"

    #include "system.h"

    typedef struct s_SceneClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        // Object*     images;
        // Object*     texts;
        // Object*     sounds;

        /* Methods definitions */
        void    (*__display__)(struct s_SceneClass*, sfRenderWindow*);
        void    (*__process__)(struct s_SceneClass*, SystemClass*);

    } SceneClass;

    extern const Class *Scene;

    #define displayScene(s, w)      ((SceneClass*)s)->__display__(s, w)
    #define processScene(s, sys)    ((SceneClass*)s)->__process__(s, sys)

    /* IMAGES */
    #define IMAGENUMBER    0

    /* TEXTS */
    #define TEXTNUMBER     0

    /* SOUNDS */
    #define SOUNDNUMBER    0

#endif /* !SCENE_H_ */