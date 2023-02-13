/*
** Description:
** File Button's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef VIEWBUTTON_H_
    #define VIEWBUTTON_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"

    #include "colors.h"
    #include "fonts.h"

    typedef struct s_ButtonClass ButtonClass;
    typedef struct s_SystemClass SystemClass;

    void ViewButton_onClick(ButtonClass *this, SystemClass *system);

    #define VIEWBUTTON_I    2

    #define VIEWBUTTON_POS              (sfVector2f){100, 5}
    #define VIEWBUTTON_SIZE             (sfVector2f){40, 30}
    #define VIEWBUTTON_DEFAULT_COLOR    TRANSPARENT
    #define VIEWBUTTON_HOVER_COLOR      (sfColor){211, 211, 211, 255}
    #define VIEWBUTTON_CLICK_COLOR      (sfColor){211, 211, 211, 150}

    #define VIEWBUTTON_TEXT_STRING          "View"
    #define VIEWBUTTON_TEXT_SIZE            15
    #define VIEWBUTTON_TEXT_DEFAULT_COLOR   BLACK
    #define VIEWBUTTON_TEXT_HOVER_COLOR     BLACK
    #define VIEWBUTTON_TEXT_CLICK_COLOR     GRAY
    #define VIEWBUTTON_TEXT_FONT            OpenSansRegular

#endif /* !VIEWBUTTON_H_ */