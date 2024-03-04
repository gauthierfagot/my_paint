/*
** EPITECH PROJECT, 2024
** draw_entities
** File description:
** draw_entities
*/

#include "my_paint.h"

void draw_pixels(sfRenderWindow *window, sfSprite *drawing)
{
    if (drawing == NULL)
        return;
    sfRenderWindow_drawSprite(window, drawing, NULL);
}

void draw_buttons(sfRenderWindow *window, button_t **buttons)
{
    for (size_t i = 0; buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window, buttons[i]->rect, NULL);
    }
}

void draw_entities(sfRenderWindow *window, sfSprite *background,
    game_t *game)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    draw_pixels(window, game->drawing);
    draw_buttons(window, game->buttons);
}
