/*
** EPITECH PROJECT, 2024
** draw_entities
** File description:
** draw_entities
*/
#include <stdio.h>
#include "button.h"
#include "my_paint.h"

void draw_entities(sfRenderWindow *window, sfSprite *background,
    button_t *button)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
}
