/*
** EPITECH PROJECT, 2024
** set_window
** File description:
** set_window
*/
#include "my_paint.h"
#include "texture.h"

void set_window_entities(paint_t *paint, sfSprite *background)
{
    sfSprite_setTexture(background, paint->textures[BACKGROUND_TEXTURE],
        sfTrue);
}
