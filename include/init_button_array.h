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

void action_test(drop_menu_t *, button_t *, graphical_tool_t *);

static const int INIT_BUTTONS_SIZE = 9;

static const init_buttons_t INIT_BUTTONS[] = {
    {{45, 45}, {450, 100}, action_test, NEW_FILE_TEXTURE, NONE,
        sfFalse, FILE},
    {{45, 45}, {450, 150}, action_test, OPEN_FILE_TEXTURE, NONE,
        sfFalse, FILE},
    {{45, 45}, {450, 200}, action_test, SAVE_FILE_TEXTURE, NONE,
        sfFalse, FILE},
    {{45, 45}, {575, 100}, action_test, BRUSH_TEXTURE, NONE,
        sfFalse, EDITION},
    {{45, 45}, {575, 150}, action_test, DROPPER_TEXTURE, NONE,
        sfFalse, EDITION},
    {{45, 45}, {575, 200}, action_test, ERASER_TEXTURE, NONE,
        sfFalse, EDITION},
    {{45, 45}, {575, 250}, action_test, PENCIL_TEXTURE, NONE,
        sfFalse, EDITION},
    {{45, 45}, {700, 100}, action_test, HELP_TEXTURE, NONE,
        sfFalse, INFO},
    {{45, 45}, {700, 150}, action_test, HELP_TEXTURE, NONE,
        sfFalse, INFO}
};

#endif /* !INIT_BUTTON_ARRAY_H */
