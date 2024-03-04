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

// typedef struct pixel_s {
//     sfVector2f placement;
//     sfUint8 *rgba;
// } pixel_t;

typedef struct graphical_tool_s {
    unsigned int height;
    unsigned int width;
    sfUint8 opacity;
} graphical_tool_t;

typedef struct game_s {
    sfImage *image;
    sfTexture **textures;
    sfSprite *drawing;
    button_t **buttons;
} game_t;

sfBool check_env(char **env);

// create, initialize and set

sfBool create_game(game_t *game);
void set_window_entities(game_t *game, sfSprite *background);
button_t *init_button(game_t *game, int i);
sfSprite *init_drawing(game_t *game);

// add


// print

void draw_entities(sfRenderWindow *, sfSprite *, game_t *);
void draw_pixels(sfRenderWindow *, sfSprite *);

// events

sfBool action_test(button_t **);
sfBool is_button_hover(button_t *, sfMouseMoveEvent *);
sfBool is_button_clicked(button_t *, sfMouseButtonEvent *);
sfBool analyze_events(sfRenderWindow *, sfEvent *, game_t *);

// destroy and free

void free_array(char **array);
void destroy_variable(sfRenderWindow *window, game_t *game);

// save

void save_drawing(const sfImage *image, const char *name);

#endif /* !PAINT */
