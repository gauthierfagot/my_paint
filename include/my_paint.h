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
    #include "define.h"

typedef struct pixel_s {
    sfVector2f placement;
    int r;
    int g;
    int b;
    int a;
} pixel_t;

typedef struct game_s {
    sfTexture **textures;
} game_t;

// create, initialize and set

int create_game(game_t *game);
void set_window_entities(game_t *game, sfSprite *background);
button_t *init_button(sfVector2f position, sfVector2f size, char *picture);

// print

void draw_entities(sfRenderWindow *window, sfSprite *background,
    button_t *button);

// events

int analyze_events(sfRenderWindow *window, sfEvent *event,
    button_t *button);
sfBool is_button_clicked(button_t *button, sfMouseButtonEvent
    *mouse_event);
sfBool is_button_hover(button_t *button, sfMouseMoveEvent
    *mouse_event);

// destroy and free

void destroy_variable(sfRenderWindow *window, game_t *game);
void free_array(char **array);

#endif /* !PAINT */
