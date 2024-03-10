/*
** EPITECH PROJECT, 2024
** button
** File description:
** button
*/

#ifndef BUTTON_H
    #define BUTTON_H
    #include <SFML/Graphics.h>
    #include "my_paint.h"
    #include "button_state.h"
    #include "graphical_tool.h"
    #include "drop_menu.h"

typedef struct button_s {
    sfRectangleShape *rect;
    sfSprite *sprite;
    void (*function)(drop_menu_t *, struct button_s *, graphical_tool_t *);
    enum e_state state;
    sfBool hide;
} button_t;

#endif /* !BUTTON_H */
