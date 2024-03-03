/*
** EPITECH PROJECT, 2024
** paint.h
** File description:
** paint.h
*/

#ifndef PAINT
    #define PAINT
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
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
    button_t **buttons;
} game_t;

sfBool check_env(char **env);

// create, initialize and set

sfBool create_game(game_t *game);
void set_window_entities(game_t *game, sfSprite *background);
sfSprite *init_pixel(graphical_tool_t *brush, sfUint8 *rgba);
button_t *init_button(game_t *game, int i);

// add

void add_new_pixel(sfSprite **pixels, graphical_tool_t *brush, sfUint8 *rgba);

// print

void draw_entities(sfRenderWindow *, sfSprite *, button_t **);
void draw_pixels_array(graphical_tool_t *, sfUint8 *, sfRenderWindow *,
    sfSprite **);

// events

sfBool action_test(button_t **);
sfBool is_button_hover(button_t *, sfMouseMoveEvent *);
sfBool is_button_clicked(button_t *, sfMouseButtonEvent *);
sfBool analyze_events(sfRenderWindow *, sfEvent *, button_t **, sfSprite **);

// destroy and free

void free_array(char **array);
void destroy_variable(sfRenderWindow *window, game_t *game);

// save

void save_drawing(const sfImage *image, const char *name);

#endif /* !PAINT */
