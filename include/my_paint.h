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

typedef struct pixel_s {
    sfVector2f placement;
    sfUint8 *rgba;
} pixel_t;

typedef struct graphical_tool_s {
    unsigned int height;
    unsigned int width;
    sfUint8 opacity;
} graphical_tool_t;

typedef struct game_s {
    sfTexture **textures;
} game_t;

// create, initialize and set

int create_game(game_t *game);
sfSprite *init_pixel(graphical_tool_t *brush, sfUint8 *rgba);
void set_window_entities(game_t *game, sfSprite *background);
button_t *init_button(sfVector2f position, sfVector2f size, char *picture);

// print

void draw_entities(sfRenderWindow *window, sfSprite *background,
    button_t *button);
void draw_a_pixel(graphical_tool_t *brush, sfUint8 *rgba, sfRenderWindow *
window);

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

// save

void save_drawing(const sfImage *image,const char *name);

#endif /* !PAINT */
