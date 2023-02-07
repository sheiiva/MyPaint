/*
** Description:
** File Button's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef FILEBUTTON_H_
    #define FILEBUTTON_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"

    #include "colors.h"
    #include "fonts.h"

    typedef struct s_ButtonClass ButtonClass;
    typedef struct s_SystemClass SystemClass;

    void FileButton_onClick(ButtonClass *this, SystemClass *system);

    #define FILEBUTTON_I    0

    #define FILEBUTTON_POS              (sfVector2f){0, 0}
    #define FILEBUTTON_SIZE             (sfVector2f){50, 30}
    #define FILEBUTTON_DEFAULT_COLOR    LIGHT_GRAY
    #define FILEBUTTON_HOVER_COLOR      DARK_GRAY
    #define FILEBUTTON_CLICK_COLOR      GRAY

    #define FILEBUTTON_TEXT_STRING          "File"
    #define FILEBUTTON_TEXT_SIZE            20
    #define FILEBUTTON_TEXT_DEFAULT_COLOR   BLACK
    #define FILEBUTTON_TEXT_HOVER_COLOR     BLACK
    #define FILEBUTTON_TEXT_CLICK_COLOR     LIGHT_GRAY
    #define FILEBUTTON_TEXT_FONT            OpenSansRegular

#endif /* !FILEBUTTON_H_ */