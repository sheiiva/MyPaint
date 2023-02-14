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
#include "File.h"

#include "colors.h"
#include "fonts.h"

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

size_t count_n(char const *str, char c)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}

char **strtowordarray(char *str, char *delim)
{
    char *token = strtok(str, delim);
    char **ret = malloc(sizeof(char *));
    size_t i = 0;

    while (token != NULL) {
        ret = realloc(ret, sizeof(char *) * (i + 2));
        ret[i++] = strdup(token);
        token = strtok(NULL, delim);
    }
    ret[i] = NULL;
    return (ret);
}

void free_strtab(char **tab)
{
    for (size_t i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

static void Scene_init(SceneClass *this, char const *path)
{
    char *info = NULL;
    size_t iButton = 0;
    size_t iRect = 0;
    size_t iText = 0;
    FileClass *file = new(File, path);

    fopenFile(file);
    while ((info = readLine(file))) {
        if (!strcmp(info, ".button"))
            this->_buttons = new(Array, readInt(file), Button);
        else if (!strcmp(info, ".rectangle"))
            this->_rects = new(Array, readInt(file), Rectangle);
        else if (!strcmp(info, ".text"))
            this->_texts = new(Array, readInt(file), Text);
        else if (!strcmp(info, ".objects"))
            break;
    }
    while ((info = readLine(file))) {
        // Set value
        char **tab = strtowordarray(info, ";");

        if (tab[0] && strcmp(tab[0], "text") == 0) {
            setText(getitem(this->_texts, iText),
                                            tab[1], atoi(tab[2]),
                                            (sfVector2f){atof(tab[3]), atof(tab[4])},
                                            GET_COLOR(tab[5]), GET_FONT(tab[6]));
            iText++;
        } else if (tab[0] && strcmp(tab[0], "rectangle") == 0) {
            setRect(getitem(this->_rects, iRect),
                                            (sfVector2f){atof(tab[1]), atof(tab[2])},
                                            (sfVector2f){atof(tab[3]), atof(tab[4])},
                                            GET_COLOR(tab[5]), atoi(tab[6]), GET_COLOR(tab[7]));
            iRect++;
        } else if (tab[0] && strcmp(tab[0], "button") == 0) {
            setButtonRect(getitem(this->_buttons, iButton),
                                            (sfVector2f){atof(tab[1]), atof(tab[2])},
                                            (sfVector2f){atof(tab[3]), atof(tab[4])},
                                            GET_COLOR(tab[5]), atoi(tab[6]), GET_COLOR(tab[7]),
                                            GET_COLOR(tab[8]), GET_COLOR(tab[9]));
            if (tab[10]) {
                setButtonText(getitem(this->_buttons, iButton),
                                            tab[10], atoi(tab[11]),
                                            (sfVector2f){atof(tab[12]), atof(tab[13])},
                                            GET_COLOR(tab[14]), GET_FONT(tab[15]),
                                            GET_COLOR(tab[16]), GET_COLOR(tab[17]));
            }
            iButton++;
        }
        free_strtab(tab);
    }

    this->_eventManager = new(EventManager, 0);

    delete(file);
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