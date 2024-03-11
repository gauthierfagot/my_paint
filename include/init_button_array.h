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

void action_test(void *, graphical_tool_t *);

static const int INIT_BUTTONS_SIZE = 11;

static const init_buttons_t INIT_BUTTONS[] = {
    {{45, 45}, {450, 100}, action_test, NEW_FILE_TEXTURE, DEFAULT,
        FILE},
    {{45, 45}, {450, 150}, action_test, OPEN_FILE_TEXTURE, DEFAULT,
        FILE},
    {{45, 45}, {450, 200}, action_test, SAVE_FILE_TEXTURE, DEFAULT,
        FILE},
    {{45, 45}, {575, 100}, action_test, BRUSH_TEXTURE, DEFAULT,
        EDITION},
    {{45, 45}, {575, 150}, action_test, DROPPER_TEXTURE, DEFAULT,
        EDITION},
    {{45, 45}, {575, 200}, action_test, ERASER_TEXTURE, DEFAULT,
        EDITION},
    {{45, 45}, {575, 250}, action_test, PENCIL_TEXTURE, DEFAULT,
        EDITION},
    {{45, 45}, {700, 100}, action_test, HELP_TEXTURE, DEFAULT,
        INFO},
    {{45, 45}, {700, 150}, action_test, HELP_TEXTURE, DEFAULT,
        INFO},
    {{45, 45}, {950, 50}, action_test, HELP_TEXTURE, DEFAULT,
        NONE},
    {{45, 45}, {1050, 50}, action_test, HELP_TEXTURE, DEFAULT,
        NONE}
};

#endif /* !INIT_BUTTON_ARRAY_H */
