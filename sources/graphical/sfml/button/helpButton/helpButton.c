/*
** Description:
** Help Button's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#include "button.h"
#include "system.h"

void HelpButton_onClick(ButtonClass *this, __UNUSED__ SystemClass *system)
{
    // Change button color
    setButtonFillColor(this, this->_clickColor);
    if (this->_text)
        setTextColor(this->_text, this->_text->_clickColor);
}