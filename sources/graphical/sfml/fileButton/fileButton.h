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

    typedef struct s_ButtonClass ButtonClass;
    typedef struct s_SystemClass SystemClass;

    void FileButton_onClick(ButtonClass *this, SystemClass *system);

    #define FILEBUTTON_I    0

    #define FILEBUTTON_POS              (sfVector2f){0, 0}
    #define FILEBUTTON_SIZE             (sfVector2f){200, 50}
    #define FILEBUTTON_DEFAULT_COLOR    TRANSPARENT
    #define FILEBUTTON_HOVER_COLOR      GRAY
    #define FILEBUTTON_CLICK_COLOR      DARK_GRAY

#endif /* !FILEBUTTON_H_ */