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

    typedef struct s_ButtonClass ButtonClass;
    typedef struct s_SystemClass SystemClass;

    void FileButton_onClick(ButtonClass *this, SystemClass *system);


#endif /* !FILEBUTTON_H_ */