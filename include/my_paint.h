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
button_t **create_buttons(paint_t *paint, int menu);
void set_window_entities(paint_t *paint, sfSprite *background);
drop_menu_t *init_drop_menu(paint_t *paint, int i);
button_t *init_button(paint_t *paint, const init_buttons_t *);
sfSprite *init_drawing(paint_t *paint);

// print

void draw_entities(sfRenderWindow *, sfSprite *, paint_t *);
void draw_pixels(sfRenderWindow *, sfSprite *);

// events

void set_pixel(sfRenderWindow *, paint_t *, graphical_tool_t);
void are_buttons_hover(sfEvent *event, paint_t *paint);
void drop_menu_action(void *, graphical_tool_t *);
void action_test(void *, graphical_tool_t *);
sfBool analyze_events(sfRenderWindow *, sfEvent *, paint_t *,
    graphical_tool_t *);
void handle_pressed_button(sfEvent *, paint_t *, graphical_tool_t *,
sfRenderWindow *);

// destroy and free

void free_array(char **array);
void destroy_variable(sfRenderWindow *window, paint_t *paint);

// save

void save_drawing(const sfImage *image, const char *name);

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

#endif /* !PAINT */
