/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** creations
*/
#include "my_paint.h"
#include "array_textures.h"
#include "button.h"
#include "init_button.h"
#include "define.h"

sfBool create_game(game_t *game)
{
    game->textures = malloc(sizeof(sfTexture *) * ARRAY_TEXTURE_SIZE);
    for (int i = 0; i < ARRAY_TEXTURE_SIZE; i++) {
        game->textures[i] = sfTexture_createFromFile(ARRAY_TEXTURE[i], NULL);
        if (game->textures[i] == NULL)
            return sfFalse;
    }
    game->buttons = malloc(sizeof(button_t *) * (INIT_BUTTON_SIZE + 1));
    for (int i = 0; i < INIT_BUTTON_SIZE; i++) {
        game->buttons[i] = init_button(game, i);
        if (game->buttons[i] == NULL)
            return sfFalse;
    }
    game->buttons[INIT_BUTTON_SIZE] = NULL;
    return sfTrue;
}
