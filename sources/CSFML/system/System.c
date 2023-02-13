/* File: system.c
**
** Description: System's methods definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "System.h"

#include "Window.h"
#include "EventManager.h"
#include "Clock.h"
#include "Scene.h"
#include "File.h"

static void System_display(SystemClass *this)
{
    SceneClass *scene = getitem(this->_scenes, this->_currentScene);

    drawScene(scene, this->_window);
    displayWindow(this->_window);
}

static void System_loop(SystemClass *this)
{
    this->_currentScene = 0;

    while (isWindowOpen(this->_window) && this->_currentScene != -1) {
        SceneClass *scene = getitem(this->_scenes, this->_currentScene);
        handleEvents(scene->_eventManager, this);
        processScene(scene, this);
        // Limit FPS
        if (getElapsedTime_asSeconds(this->_clock) > this->_fps/60.0) {
            clearWindow(this->_window);
            displaySystem(this);
        }
    }
}

static void System_ctor(SystemClass *this, va_list *args)
{
    // Initialize internal resources
    FileClass *file = new(File, va_arg(*args, char*));
    fopenFile(file);

    // Init window
    char *windowTitle = readLine(file);
    sfVideoMode mode = {readInt(file), readInt(file), readInt(file)};
    this->_window = new(Window, mode, windowTitle);

    this->_clock = new(Clock);
    this->_fps = readInt(file);

    // Init scenes
    int nbScenes = readInt(file);
    this->_scenes = new(Array, nbScenes, Scene);
    for (int i = 0; i < nbScenes; i++) {
        char *configFile = readLine(file);
        initScene(getitem(this->_scenes, i), configFile);
        free(configFile);
    }

    printf("System()\n");

    free(windowTitle);
    delete(file);
}

static void System_dtor(SystemClass *this)
{
    if (this->_clock)
        delete(this->_clock);
    if (this->_window)
        delete(this->_window);
    if (this->_scenes)
        delete(this->_scenes);

    printf("~System()\n");
}

static const SystemClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SystemClass),
        .__name__ = "System",
        .__ctor__ = (ctor_t)&System_ctor,
        .__dtor__ = (dtor_t)&System_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._clock = NULL,
    ._window = NULL,
    ._currentScene = -1,
    ._scenes = NULL,
    /* Methods definitions */
    .__loop__ = &System_loop,
    .__display__ = &System_display,
};

const Class *System = (const Class *)&_description;