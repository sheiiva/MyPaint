/* File: viewButton.c
**
** Description: View Button's onClick function definition
**
** 2023, February 14
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#include "Button.h"
#include "System.h"
#include "Window.h"
#include "Rectangle.h"
#include "colors.h"

void Canva_onClick(ButtonClass *this, SystemClass *system)
{
    static sfImage *image = NULL;

    if (!this->_rectangle)
        return;

    sfVector2f rectSize = getRectSize(this->_rectangle);
    sfVector2f rectPos = (sfVector2f)getRectPosition(this->_rectangle);

    // Get Mouse Position
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(system->_window->_window);

    // // Set Image
    if (!image)
        image = sfImage_createFromColor(rectSize.x, rectSize.y, sfWhite);
    sfImage_setPixel(image, (mousePos.x - rectPos.x), (mousePos.y - rectPos.y), RED);

    // Set Texture
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    // Set new texture
    sfRectangleShape_setTexture(this->_rectangle->_shape, texture, sfTrue);
}
