/*
** EPITECH PROJECT, 2024
** set_window
** File description:
** set_window
*/
#include "my_paint.h"
#include "texture.h"

void set_window_entities(game_t *game, sfSprite *background)
{
    sfSprite_setTexture(background, game->textures[BACKGROUND], sfTrue);
}
