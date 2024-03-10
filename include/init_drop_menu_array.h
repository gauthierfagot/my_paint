/*
** EPITECH PROJECT, 2024
** init_drop_menu_array
** File description:
** init_drop_menu_array
*/

#ifndef INIT_DROP_MENU_ARRAY_H
    #define INIT_DROP_MENU_ARRAY_H
    #include <SFML/Graphics.h>
    #include "button_state.h"
    #include "button.h"
    #include "texture.h"
    #include "drop_menu.h"

void drop_menu_action(drop_menu_t *, button_t *, graphical_tool_t *);

static const int INIT_DROP_MENU_SIZE = 3;

static const init_buttons_t INIT_DROP_MENU[] = {
    {{45, 45}, {450, 50}, drop_menu_action, FILE_EDITOR_TEXTURE, NONE,
        sfTrue, FILE},
    {{45, 45}, {575, 50}, drop_menu_action, TOOL_MENU_TEXTURE, NONE,
        sfTrue, EDITION},
    {{45, 45}, {700, 50}, drop_menu_action, HELP_TEXTURE, NONE,
        sfTrue, INFO},
};

#endif /* !INIT_DROP_MENU_ARRAY_H */
