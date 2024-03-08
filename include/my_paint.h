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
    #include "init_button.h"
    #include "graphical_tool.h"

typedef struct paint_s {
    sfImage *image;
    sfTexture **textures;
    sfSprite *drawing;
    drop_menu_t **menus;
} paint_t;

sfBool check_env(char **env);

// create, initialize and set

sfBool create_paint(paint_t *paint);
graphical_tool_t create_tools(void);
void set_window_entities(paint_t *paint, sfSprite *background);
drop_menu_t *init_drop_menu(paint_t *paint, int i);
button_t *init_button(paint_t *paint, const init_buttons_t *);
sfSprite *init_drawing(paint_t *paint);

// print

void draw_entities(sfRenderWindow *, sfSprite *, paint_t *);
void draw_pixels(sfRenderWindow *, sfSprite *);

// events

sfBool action_test(graphical_tool_t *);
sfBool is_button_hover(button_t *, sfMouseMoveEvent *);
sfBool is_button_clicked(button_t *, sfMouseButtonEvent *);
sfBool analyze_events(sfRenderWindow *, sfEvent *, paint_t *,
    graphical_tool_t *);

// destroy and free

void free_array(char **array);
void destroy_variable(sfRenderWindow *window, paint_t *paint);

// save

void save_drawing(const sfImage *image, const char *name);

#endif /* !PAINT */
