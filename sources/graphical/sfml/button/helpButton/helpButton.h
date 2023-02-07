/*
** Description:
** Help Button's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef HELPBUTTON_H_
    #define HELPBUTTON_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"

    #include "colors.h"
    #include "fonts.h"

    typedef struct s_ButtonClass ButtonClass;
    typedef struct s_SystemClass SystemClass;

    void HelpButton_onClick(ButtonClass *this, SystemClass *system);

    #define HELPBUTTON_I    1

    #define HELPBUTTON_POS              (sfVector2f){50, 0}
    #define HELPBUTTON_SIZE             (sfVector2f){50, 30}
    #define HELPBUTTON_DEFAULT_COLOR    LIGHT_GRAY
    #define HELPBUTTON_HOVER_COLOR      DARK_GRAY
    #define HELPBUTTON_CLICK_COLOR      GRAY

    #define HELPBUTTON_TEXT_STRING          "Help"
    #define HELPBUTTON_TEXT_SIZE            20
    #define HELPBUTTON_TEXT_DEFAULT_COLOR   BLACK
    #define HELPBUTTON_TEXT_HOVER_COLOR     BLACK
    #define HELPBUTTON_TEXT_CLICK_COLOR     LIGHT_GRAY
    #define HELPBUTTON_TEXT_FONT            OpenSansRegular

#endif /* !HELPBUTTON_H_ */