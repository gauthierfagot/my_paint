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

typedef struct init_buttons_s {
    sfVector2f size;
    sfVector2f position;
    sfBool (*function)(button_t **);
    enum e_texture texture;
    enum e_state state;
} init_buttons_t;

sfBool action_test(button_t **);

static const int INIT_BUTTON_SIZE = 2;

static const init_buttons_t INIT_BUTTON[] = {
    {{100, 100}, {500, 500}, action_test, BRUSH, NONE},
    {{100, 100}, {100, 100}, action_test, BRUSH, NONE}
};

#endif /* !INIT_BUTTON_H */
