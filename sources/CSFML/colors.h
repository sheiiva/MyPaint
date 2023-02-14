/* File: colors.h
**
** Description: Color palette for CSFML
**
** 2023, February 09
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef COLORS_H_
    #define COLORS_H_

    #include <SFML/Graphics.h>
    #include <string.h>

    #define TRANSPARENT (sfColor){0, 0, 0, 0}

    #define BLACK (sfColor){0, 0, 0, 255}

    #define WHITE (sfColor){255, 255, 255, 255}

    #define RED (sfColor){255, 0, 0, 255}
    #define DARK_RED (sfColor){139, 0, 0, 255}
    #define LIGHT_RED (sfColor){255, 182, 193, 255}

    #define GREEN (sfColor){0, 255, 0, 255}
    #define DARK_GREEN (sfColor){0, 100, 0, 255}
    #define LIGHT_GREEN (sfColor){144, 238, 144, 255}

    #define BLUE (sfColor){0, 0, 255, 255}
    #define DARK_BLUE (sfColor){0, 0, 139, 255}
    #define LIGHT_BLUE (sfColor){173, 216, 230, 255}

    #define YELLOW (sfColor){255, 255, 0, 255}
    #define DARK_YELLOW (sfColor){139, 139, 0, 255}
    #define LIGHT_YELLOW (sfColor){255, 255, 224, 255}

    #define MAGENTA (sfColor){255, 0, 255, 255}
    #define DARK_MAGENTA (sfColor){139, 0, 139, 255}
    #define LIGHT_MAGENTA (sfColor){255, 192, 203, 255}

    #define CYAN (sfColor){0, 255, 255, 255}
    #define DARK_CYAN (sfColor){0, 139, 139, 255}
    #define LIGHT_CYAN (sfColor){224, 255, 255, 255}

    #define BROWN (sfColor){139, 69, 19, 255}
    #define DARK_BROWN (sfColor){139, 69, 19, 255}
    #define LIGHT_BROWN (sfColor){139, 69, 19, 255}

    #define FUSHIA (sfColor){255, 255, 0, 255}
    #define DARK_FUSHIA (sfColor){255, 0, 255, 255}
    #define LIGHT_FUSHIA (sfColor){255, 0, 255, 255}

    #define ORANGE (sfColor){255, 165, 0, 255}
    #define DARK_ORANGE (sfColor){255, 140, 0, 255}
    #define LIGHT_ORANGE (sfColor){255, 165, 0, 255}

    #define PURPLE (sfColor){128, 0, 128, 255}
    #define DARK_PURPLE (sfColor){128, 0, 128, 255}
    #define LIGHT_PURPLE (sfColor){128, 0, 128, 255}

    #define GRAY (sfColor){128, 128, 128, 255}
    #define DARK_GRAY (sfColor){169, 169, 169, 255}
    #define LIGHT_GRAY (sfColor){211, 211, 211, 255}

    #define MAROON (sfColor){128, 0, 0, 255}

    #define OLIVE (sfColor){128, 128, 0, 255}
    #define DARK_OLIVE (sfColor){85, 107, 47, 255}
    #define LIGHT_OLIVE (sfColor){107, 142, 35, 255}

    #define LIME (sfColor){0, 255, 0, 255}
    #define DARK_LIME (sfColor){50, 205, 50, 255}
    #define LIGHT_LIME (sfColor){144, 238, 144, 255}

    #define TEAL (sfColor){0, 128, 128, 255}
    #define DARK_TEAL (sfColor){0, 128, 128, 255}
    #define LIGHT_TEAL (sfColor){0, 128, 128, 255}

    #define NAVY (sfColor){0, 0, 128, 255}

    typedef struct color_s
    {
        char*       name;
        sfColor     value;
    } color_t;

    static color_t COLORS[] = {
        {"transparent", TRANSPARENT},
        {"black", BLACK},
        {"white", WHITE},
        {"red", RED},
        {"dark_red", DARK_RED},
        {"light_red", LIGHT_RED},
        {"green", GREEN},
        {"dark_green", DARK_GREEN},
        {"light_green", LIGHT_GREEN},
        {"blue", BLUE},
        {"dark_blue", DARK_BLUE},
        {"light_blue", LIGHT_BLUE},
        {"yellow", YELLOW},
        {"dark_yellow", DARK_YELLOW},
        {"light_yellow", LIGHT_YELLOW},
        {"magenta", MAGENTA},
        {"dark_magenta", DARK_MAGENTA},
        {"light_magenta", LIGHT_MAGENTA},
        {"cyan", CYAN},
        {"dark_cyan", DARK_CYAN},
        {"light_cyan", LIGHT_CYAN},
        {"brown", BROWN},
        {"dark_brown", DARK_BROWN},
        {"light_brown", LIGHT_BROWN},
        {"fushia", FUSHIA},
        {"dark_fushia", DARK_FUSHIA},
        {"light_fushia", LIGHT_FUSHIA},
        {"orange", ORANGE},
        {"dark_orange", DARK_ORANGE},
        {"light_orange", LIGHT_ORANGE},
        {"purple", PURPLE},
        {"dark_purple", DARK_PURPLE},
        {"light_purple", LIGHT_PURPLE},
        {"gray", GRAY},
        {"dark_gray", DARK_GRAY},
        {"light_gray", LIGHT_GRAY},
        {"maroon", MAROON},
        {"olive", OLIVE},
        {"dark_olive", DARK_OLIVE},
        {"light_olive", LIGHT_OLIVE},
        {"lime", LIME},
        {"dark_lime", DARK_LIME},
        {"light_lime", LIGHT_LIME},
        {"teal", TEAL},
        {"dark_teal", DARK_TEAL},
        {"light_teal", LIGHT_TEAL},
        {"navy", NAVY},
        {NULL, {0, 0, 0, 0}}
    };

    #define GET_COLOR(color) \
    ({ \
        sfColor value = WHITE; \
        for (int i = 0; COLORS[i].name != NULL; i++) { \
            if (strcmp(COLORS[i].name, color) == 0) { \
                value = COLORS[i].value; \
                break; \
            } \
        } \
        value; \
    })

#endif /* !COLORS _H_ */