/*
** EPITECH PROJECT, 2024
** button
** File description:
** button
*/

#ifndef BUTTON_H
    #define BUTTON_H
    #include <SFML/Graphics.h>
    #include "button_state.h"

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    enum e_state state;
} button_t;

#endif /* !BUTTON_H */
