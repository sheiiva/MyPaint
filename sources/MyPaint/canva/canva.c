/* File: viewButton.c
**
** Description: View Button's onClick function definition
**
** 2023, February 14
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include <math.h>

#include "Button.h"
#include "System.h"
#include "Window.h"
#include "Rectangle.h"
#include "colors.h"

int r = 3;

static void putPixel(sfImage *image, int x, int y, sfVector2f rectSize, sfColor color)
{
    if (x < 0 || x > rectSize.x || y < 0 || y > rectSize.y)
        return;

    for (int j = y - r; j < y + r; j++) {
        for (int i = x - r; i < x + r; i++) {
            if (i >= 0 && i < rectSize.x && j >= 0 && j < rectSize.y) {
                sfImage_setPixel(image, i, j, color);
            }
        }
    }
}

void Canva_onClick(ButtonClass *this, SystemClass *system)
{
    static sfImage *image = NULL;
    static sfVector2i oldMousePos = {0, 0};

    if (!this->_rectangle)
        return;

    // Get Mouse Position
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(system->_window->_window);
    // Get rect info
    sfVector2f rectSize = getRectSize(this->_rectangle);
    sfVector2f rectPos = getRectPosition(this->_rectangle);

    // Set Image for first time
    if (!image) {
        image = sfImage_createFromColor(rectSize.x, rectSize.y, sfWhite);
        oldMousePos = mousePos;
    }

    // Draw point aroud mouse position
    sfVector2i direction = {(mousePos.x - oldMousePos.x), (mousePos.y - oldMousePos.y)};
    int u = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

    // for (int i = 0; i < max; i++) {
    //     oldMousePos.x += direction.x / max;
    //     oldMousePos.y += direction.y / max;
    //     putPixel(image, oldMousePos.x - rectPos.x, oldMousePos.y - rectPos.y, rectSize, sfBlack);
    // }
    // oldMousePos = mousePos;

    // Set Texture
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    // Set new texture
    sfRectangleShape_setTexture(this->_rectangle->_shape, texture, sfTrue);
}
