/*
** Description:
** File Button's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "button.h"
#include "system.h"

void FileButton_onClick(ButtonClass *this, __UNUSED__ SystemClass *system)
{
    // Change button color
    setButtonFillColor(this, this->_clickColor);
}