/* File: onClick.h
**
** Description: [DESCRIPTION]
**
** 2023, February 14
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef ONCLICK_H_
    #define ONCLICK_H_

    #include "Button.h"
    #include "CSFMLTypes.h"

    // Project related includes
    #include "fileButton.h"
    #include "helpButton.h"
    #include "viewButton.h"

    typedef struct onClick_s {
        char*       name;
        OnClick     onClick;
    } onClick_t;

    static onClick_t FUNCTIONS[] = {
        {"Default", &Button_onClick},
        /* INSERT HERE PROJECT RELATED ONCLICKS */
        {"FileButton", &FileButton_onClick},
        {"HelpButton", &HelpButton_onClick},
        {"ViewButton", &ViewButton_onClick},
        {NULL, NULL}
    };

    #define GET_ONCLICK(functionName) \
    ({ \
        OnClick function = &Button_onClick; \
        for (int i = 0; FUNCTIONS[i].name != NULL; i++) { \
            if (strcmp(FUNCTIONS[i].name, functionName) == 0) { \
                function = FUNCTIONS[i].onClick; \
                break; \
            } \
        } \
        function; \
    })
#endif /* !ONCLICK_H_ */