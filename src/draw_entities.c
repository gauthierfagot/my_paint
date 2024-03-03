/*
** EPITECH PROJECT, 2024
** draw_entities
** File description:
** draw_entities
*/

#include "my_paint.h"

void draw_pixels_array(graphical_tool_t *brush, sfUint8 *rgba,
    sfRenderWindow *window, sfSprite **pixels_array)
{
    if (pixels_array == NULL || brush == NULL || rgba == NULL)
        return;
    for (int i = 0; pixels_array[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, pixels_array[i], NULL);
    return;
}

void draw_buttons(sfRenderWindow *window, button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window, buttons[i]->rect, NULL);
    }
}

void draw_entities(sfRenderWindow *window, sfSprite *background,
    button_t **buttons)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    draw_buttons(window, buttons);
}
