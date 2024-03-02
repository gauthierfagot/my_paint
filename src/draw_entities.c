/*
** EPITECH PROJECT, 2024
** draw_entities
** File description:
** draw_entities
*/

#include "my_paint.h"

void draw_entities(sfRenderWindow *window, sfSprite *background,
    button_t *button)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
}

void draw_a_pixel(graphical_tool_t *brush, sfUint8 *rgba,
    sfRenderWindow *window)
{
    sfSprite *sprite = init_pixel(brush, rgba);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return;
}
