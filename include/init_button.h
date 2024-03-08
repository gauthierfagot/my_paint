/*
** EPITECH PROJECT, 2024
** init_button
** File description:
** init_button
*/

#ifndef INIT_BUTTON_H
    #define INIT_BUTTON_H
    #include <SFML/Graphics.h>
    #include "button_state.h"
    #include "button.h"
    #include "texture.h"
    #include "drop_menu.h"

typedef struct init_buttons_s {
    sfVector2f size;
    sfVector2f position;
    sfBool (*function)(graphical_tool_t *);
    enum e_texture texture;
    enum e_state state;
    sfBool hide;
    enum e_drop_menu menu;
} init_buttons_t;

#endif /* !INIT_BUTTON_H */
