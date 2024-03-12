/*
** EPITECH PROJECT, 2024
** init_button_array
** File description:
** init_button_array
*/

#ifndef INIT_BUTTON_ARRAY_H
    #define INIT_BUTTON_ARRAY_H
    #include <SFML/Graphics.h>
    #include "button_state.h"
    #include "button.h"
    #include "texture.h"
    #include "drop_menu.h"
    #include "menu.h"
    #include "color.h"

static const int INIT_BUTTONS_SIZE = 31;

static const init_buttons_t INIT_BUTTONS[] = {
    {{45, 45}, {450, 100}, set_black, NEW_FILE_TEXTURE, DEFAULT,
        FILE, &sfWhite, sfTrue},
    {{45, 45}, {450, 150}, set_black, OPEN_FILE_TEXTURE, DEFAULT,
        FILE, &sfWhite, sfTrue},
    {{45, 45}, {450, 200}, set_black, SAVE_FILE_TEXTURE, DEFAULT,
        FILE, &sfWhite, sfTrue},
    {{45, 45}, {575, 100}, set_brush, BRUSH_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {575, 150}, set_dropper, DROPPER_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {575, 200}, set_eraser, ERASER_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {575, 250}, set_pencil, PENCIL_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {700, 100}, set_black, HELP_TEXTURE, DEFAULT,
        INFO, &sfWhite, sfTrue},
    {{45, 45}, {700, 150}, set_black, HELP_TEXTURE, DEFAULT,
        INFO, &sfWhite, sfTrue},
    {{25, 25}, {900, 45}, set_black, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLACK], sfFalse},
    {{25, 25}, {930, 75}, set_grey, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[GREY], sfFalse},
    {{25, 25}, {930, 45}, set_brown, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BROWN], sfFalse},
    {{25, 25}, {960, 45}, set_red, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[RED], sfFalse},
    {{25, 25}, {990, 45}, set_orange, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[ORANGE], sfFalse},
    {{25, 25}, {1020, 45}, set_yellow, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[YELLOW], sfFalse},
    {{25, 25}, {1020, 75}, set_blade_yellow, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLADE_YELLOW], sfFalse},
    {{25, 25}, {1050, 45}, set_green, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[GREEN], sfFalse},
    {{25, 25}, {1050, 75}, set_blade_green, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLADE_GREEN], sfFalse},
    {{25, 25}, {1080, 45}, set_blue, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLUE], sfFalse},
    {{25, 25}, {1110, 45}, set_purple, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[PURPLE], sfFalse},
    {{25, 25}, {1110, 75}, set_blade_purple, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLADE_PURPLE], sfFalse},
    {{25, 25}, {900, 75}, set_white, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[WHITE], sfFalse},
    {{25, 25}, {960, 75}, set_pink, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[PINK], sfFalse},
    {{25, 25}, {990, 75}, set_beige, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BEIGE], sfFalse},
    {{25, 25}, {1080, 75}, set_cyan, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[CYAN], sfFalse},
    {{45, 45}, {1200, 50}, set_circle, CIRCLE_TEXTURE, DEFAULT,
        SHAPES, &sfWhite, sfFalse},
    {{45, 45}, {1250, 50}, set_square, SQUARE_TEXTURE, DEFAULT,
        SHAPES, &sfWhite, sfFalse},
    {{45, 45}, {1450, 50}, set_small_size, SMALL_SIZE_TEXTURE, DEFAULT,
        THICKNESS, &sfWhite, sfFalse},
    {{45, 45}, {1400, 50}, set_medium_size, MEDIUM_SIZE_TEXTURE, DEFAULT,
        THICKNESS, &sfWhite, sfFalse},
    {{45, 45}, {1350, 50}, set_big_size, BIG_SIZE_TEXTURE, DEFAULT,
        THICKNESS, &sfWhite, sfFalse},
    {{45, 45}, {1550, 50}, set_bin, BIN_TEXTURE, DEFAULT,
        NONE, &sfWhite, sfFalse}
};

#endif /* !INIT_BUTTON_ARRAY_H */
