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

static void Scene_draw(SceneClass *this, WindowClass* window)
{
    // Draw the background
    clearWindow(window);
    for (size_t i = 0; i < len(this->_rects); i++)
        drawRect(getitem(this->_rects, i), window);
    for (size_t i = 0; i < len(this->_buttons); i++)
        drawButton(getitem(this->_buttons, i), window);
    for (size_t i = 0; i < len(this->_texts); i++)
        drawText(getitem(this->_texts, i), window);
}

static void Scene_process(SceneClass *this, SystemClass *system)
{
    // Process buttons
    for (size_t i = 0; i < len(this->_buttons); i++)
        processButton(getitem(this->_buttons, i), system);
}

static void Scene_ctor(SceneClass *this, va_list *args)
{
    // Initialize internal resources

    // Call the initScene function
    (*va_arg(*args, initScene_t))(this);

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
};

const Class *Scene = (const Class *)&_description;