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

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*function)(struct button_s **);
    enum e_state state;
} button_t;

#endif /* !BUTTON_H */
