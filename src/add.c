/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** add
*/

#include "my_paint.h"

static int len(sfSprite **arr)
{
    int size = 0;

    while (arr[size] != NULL)
        size += 1;
    return size;
}

static sfSprite **realloc_sprite_array(sfSprite **array, sfSprite *pixel)
{
    sfSprite **new_array = malloc(sizeof(sfSprite *) * (len(array) + 2));
    int i = 0;

    while (array[i] != NULL) {
        new_array[i] = array[i];
        i++;
    }
    new_array[i] = pixel;
    new_array[i + 1] = NULL;
    return new_array;
}

void add_new_pixel(sfSprite **pixels, graphical_tool_t *brush, sfUint8 *rgba)
{
    sfSprite *sprite = init_pixel(brush, rgba);

    if (sprite == NULL)
        return;
    if (pixels == NULL) {
        pixels = malloc(sizeof(sfSprite *) * 2);
        pixels[0] = sprite;
        pixels[1] = NULL;
        return;
    }
    pixels = realloc_sprite_array(pixels, sprite);
    return;
}
