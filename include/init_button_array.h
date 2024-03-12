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

void default_action(void *, graphical_tool_t *);
void eraser_action(void *, graphical_tool_t *tools);
void brush_action(void *, graphical_tool_t *tools);
void pencil_action(void *, graphical_tool_t *tools);

// shades
void set_white(void *, graphical_tool_t *tools);
void set_grey(void *, graphical_tool_t *tools);
void set_brown(void *, graphical_tool_t *tools);
void set_black(void *, graphical_tool_t *tools);

// primary
void set_red(void *, graphical_tool_t *tools);
void set_blue(void *, graphical_tool_t *tools);
void set_green(void *, graphical_tool_t *tools);
void set_yellow(void *, graphical_tool_t *tools);

// others
void set_orange(void *, graphical_tool_t *tools);
void set_purple(void *, graphical_tool_t *tools);
void set_beige(void *, graphical_tool_t *tools);
void set_pink(void *, graphical_tool_t *tools);
void set_cyan(void *, graphical_tool_t *tools);


static const int INIT_BUTTONS_SIZE = 24;

static const init_buttons_t INIT_BUTTONS[] = {
    {{45, 45}, {450, 100}, default_action, NEW_FILE_TEXTURE, DEFAULT,
        FILE, &sfWhite, sfTrue},
    {{45, 45}, {450, 150}, default_action, OPEN_FILE_TEXTURE, DEFAULT,
        FILE, &sfWhite, sfTrue},
    {{45, 45}, {450, 200}, default_action, SAVE_FILE_TEXTURE, DEFAULT,
        FILE, &sfWhite, sfTrue},
    {{45, 45}, {575, 100}, brush_action, BRUSH_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {575, 150}, default_action, DROPPER_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {575, 200}, eraser_action, ERASER_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {575, 250}, pencil_action, PENCIL_TEXTURE, DEFAULT,
        EDITION, &sfWhite, sfTrue},
    {{45, 45}, {700, 100}, default_action, HELP_TEXTURE, DEFAULT,
        INFO, &sfWhite, sfTrue},
    {{45, 45}, {700, 150}, default_action, HELP_TEXTURE, DEFAULT,
        INFO, &sfWhite, sfTrue},
    {{25, 25}, {900, 45}, set_black, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLACK], sfFalse},
    {{25, 25}, {900, 105}, set_grey, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[GREY], sfFalse},
    {{25, 25}, {930, 45}, set_brown, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BROWN], sfFalse},
    {{25, 25}, {960, 45}, set_red, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[RED], sfFalse},
    {{25, 25}, {990, 45}, set_orange, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[ORANGE], sfFalse},
    {{25, 25}, {1020, 45}, set_yellow, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[YELLOW], sfFalse},
    {{25, 25}, {1050, 45}, set_green, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[GREEN], sfFalse},
    {{25, 25}, {1080, 45}, set_blue, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BLUE], sfFalse},
    {{25, 25}, {1110, 45}, set_purple, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[PURPLE], sfFalse},
    {{25, 25}, {900, 75}, set_white, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[WHITE], sfFalse},
    {{25, 25}, {960, 75}, set_pink, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[PINK], sfFalse},
    {{25, 25}, {990, 75}, set_beige, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[BEIGE], sfFalse},
    {{25, 25}, {1080, 75}, set_cyan, HELP_TEXTURE, DEFAULT,
        COLORS, &color_tab[CYAN], sfFalse},
    {{45, 45}, {1250, 90}, set_circle, CIRCLE_TEXTURE, DEFAULT,
        SHAPES, &sfWhite, sfFalse},
    {{45, 45}, {1250, 20}, set_square, SQUARE_TEXTURE, DEFAULT,
        SHAPES, &sfWhite, sfFalse},
};

#endif /* !INIT_BUTTON_ARRAY_H */
