/*
** Description:
** Fonts definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/MyPaint
**
*/

#ifndef FONTS_H_
    #define FONTS_H_

    #include <string.h>

    #define OpenSansRegular "assets/fonts/OpenSans-VariableFont.ttf"

    typedef struct s_fonts {
        char*       name;
        char*       path;
    } fonts_t;

    static fonts_t FONTS[] = {
        {"OpenSansRegular", OpenSansRegular},
        {NULL, NULL}
    };

    #define GET_FONT(color) \
    ({ \
        char *path = ""; \
        for (int i = 0; FONTS[i].name != NULL; i++) { \
            if (strcmp(FONTS[i].name, color) == 0) { \
                path = FONTS[i].path; \
                break; \
            } \
        } \
        path; \
    })

#endif /* !FONTS_H_ */