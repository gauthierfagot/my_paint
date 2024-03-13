/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** flip_image
*/

#include "my_paint.h"

void flip_horizontally(void *img, graphical_tool_t *)
{
    sfImage *image = NULL;

    if (img == NULL)
        return;
    image = (sfImage *)img;
    sfImage_flipHorizontally(image);
    return;
}

void flip_vertically(void *img, graphical_tool_t *)
{
    sfImage *image = NULL;

    if (img == NULL)
        return;
    image = (sfImage *)img;
    sfImage_flipVertically(image);
    return;
}
