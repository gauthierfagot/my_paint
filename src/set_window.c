/*
** EPITECH PROJECT, 2024
** set_window
** File description:
** set_window
*/

#include "my_paint.h"
#include "define.h"
#include "color.h"
#include "texture.h"

void set_window_entities(sfRectangleShape *background)
{
    sfVector2f position = {0, 0};
    sfVector2f size = {WIDTH, HEIGHT};

    sfRectangleShape_setSize(background, size);
    sfRectangleShape_setPosition(background, position);
    sfRectangleShape_setFillColor(background, color_tab[GREY]);
    return;
}
