/*
** EPITECH PROJECT, 2024
** paint.h
** File description:
** paint.h
*/

#ifndef PAINT
    #define PAINT
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "button.h"

    #define WIDTH 1920
    #define HEIGHT 1080
    #define FRAME 30

    #define IS_HOVER(button)
    #define IS_PRESSED(button)
    #define IS_RELEASED(button)

typedef struct game_s {
    sfTexture **textures;
} game_t;


int create_game(game_t *game);
button_t *init_button(sfVector2f position, sfVector2f size);

void set_window_entities(game_t *game, sfSprite *background);

void draw_entities(sfRenderWindow *window, sfSprite *background,
    button_t *button);

int analyze_events(sfRenderWindow *window, sfEvent *event,
    button_t *button);
sfBool is_button_clicked(button_t *button, sfMouseButtonEvent
    *mouse_event);
sfBool is_button_hover(button_t *button, sfMouseMoveEvent
    *mouse_event);

void destroy_variable(sfRenderWindow *window, game_t *game);
void free_array(char **array);

#endif /* !PAINT */
