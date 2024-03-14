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
    button_t **buttons;
} paint_t;

sfBool check_env(char **env);

// create, initialize and set

sfBool create_paint(paint_t *paint);
graphical_tool_t create_tools(void);
void set_window_entities(sfRectangleShape *background);
drop_menu_t *init_drop_menu(paint_t *paint, int i);
button_t *init_button(paint_t *paint, const init_buttons_t *);
sfSprite *init_drawing(paint_t *paint);

// help

void help(void *, graphical_tool_t *);

// print

void draw_entities(sfRenderWindow *, sfRectangleShape *, paint_t *);
void draw_pixels(sfRenderWindow *, sfSprite *);

// events

void resize_window(sfRenderWindow *);
void set_pixel(sfRenderWindow *, paint_t *, graphical_tool_t *);
void are_buttons_hover(sfEvent *event, paint_t *paint);
void drop_menu_action(void *, graphical_tool_t *);
sfBool analyze_events(sfRenderWindow *, sfEvent *, paint_t *,
    graphical_tool_t *);
void handle_pressed_button(sfEvent *, paint_t *, graphical_tool_t *,
    sfRenderWindow *);
void outline_button(button_t *button);

// destroy and free

void free_array(char **array);
void destroy_variable(sfRenderWindow *window, paint_t *paint);

// save

void save_drawing(void *, graphical_tool_t *);

// colors //

// shades

void set_white(void *, graphical_tool_t *tools);
void set_grey(void *, graphical_tool_t *tools);
void set_brown(void *, graphical_tool_t *tools);
void set_black(void *, graphical_tool_t *tools);

// primary

void set_red(void *, graphical_tool_t *tools);
void set_blue(void *, graphical_tool_t *tools);
void set_green(void *, graphical_tool_t *tools);
void set_yellow(void *, graphical_tool_t *tools);

// others

void set_orange(void *, graphical_tool_t *tools);
void set_purple(void *, graphical_tool_t *tools);
void set_beige(void *, graphical_tool_t *tools);
void set_pink(void *, graphical_tool_t *tools);
void set_cyan(void *, graphical_tool_t *tools);

// blade colors

void set_blade_purple(void *, graphical_tool_t *tools);
void set_blade_yellow(void *, graphical_tool_t *tools);
void set_blade_green(void *, graphical_tool_t *tools);

// set_tools

void set_bin(void *, graphical_tool_t *);
void set_eraser(void *, graphical_tool_t *tools);
void set_brush(void *, graphical_tool_t *tools);
void set_pencil(void *, graphical_tool_t *tools);
void set_dropper(void *, graphical_tool_t *tools);

// set_shapes

void set_circle(void *, graphical_tool_t *tools);
void set_square(void *, graphical_tool_t *tools);

// set_size

void set_small_size(void *, graphical_tool_t *tools);
void set_medium_size(void *, graphical_tool_t *tools);
void set_big_size(void *, graphical_tool_t *tools);


#endif /* !PAINT */
