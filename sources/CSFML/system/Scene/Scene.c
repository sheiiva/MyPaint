/* File: Scene.c
**
** Description: Scene's class definition
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "System.h"
#include "Window.h"
#include "Rectangle.h"
#include "Button.h"
#include "Text.h"
#include "Scene.h"
#include "EventManager.h"

static void Scene_draw(SceneClass *this, WindowClass* window)
{
    // Draw the background
    clearWindow(window);
    for (size_t i = 0; this->_rects && i < len(this->_rects); i++)
        drawRect(getitem(this->_rects, i), window);
    for (size_t i = 0; this->_buttons && i < len(this->_buttons); i++)
        drawButton(getitem(this->_buttons, i), window);
    for (size_t i = 0; this->_texts && i < len(this->_texts); i++)
        drawText(getitem(this->_texts, i), window);
}

static void Scene_process(SceneClass *this, SystemClass *system)
{
    // Process buttons
    for (size_t i = 0; this->_buttons && i < len(this->_buttons); i++)
        processButton(getitem(this->_buttons, i), system);
}

static void Scene_init(__UNUSED__ SceneClass *this, __UNUSED__ char const *path)
{
    // Initialize the scene
    this->_rects = new(Array, 0, sizeof(RectangleClass*));
    this->_buttons = new(Array, 0, sizeof(ButtonClass*));
    this->_texts = new(Array, 0, sizeof(TextClass*));
    this->_eventManager = new(EventManager, 0);

    // Parse from file
}

static void Scene_ctor(__UNUSED__ SceneClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources

    printf("Scene()\n");
}

static void Scene_dtor(__UNUSED__ SceneClass *this)
{
    // Release internal resources

    printf("~Scene()\n");
}

static const SceneClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SceneClass),
        .__name__ = "Scene",
        .__ctor__ = (ctor_t)&Scene_ctor,
        .__dtor__ = (dtor_t)&Scene_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._rects = NULL,
    ._buttons = NULL,
    ._texts = NULL,
    /* Methods definitions */
    .__draw__ = &Scene_draw,
    .__process__ = &Scene_process,
    .__init__ = &Scene_init
};

const Class *Scene = (const Class *)&_description;