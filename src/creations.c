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

static button_t **create_buttons(game_t *game)
{
    button_t **buttons = malloc(sizeof(button_t *) * (INIT_BUTTON_SIZE + 1));

    for (int i = 0; i < INIT_BUTTON_SIZE; i++) {
        buttons[i] = init_button(game, i);
        if (buttons[i] == NULL)
            return NULL;
    }
    buttons[INIT_BUTTON_SIZE] = NULL;
    return buttons;
}

static sfTexture **create_textures(game_t *game)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * SIZE);

    textures[DRAWING] = sfTexture_createFromImage(game->image, NULL);
    for (int i = 1; i < SIZE; i++) {
        textures[i] = sfTexture_createFromFile(ARRAY_TEXTURE[i - 1],
        NULL);
        if (textures[i] == NULL)
            return NULL;
    }
    return textures;
}

sfBool create_game(game_t *game)
{
    game->image = sfImage_createFromColor(WIDTH * (5.0 / 6.0),
    HEIGHT * (4.0 / 5.0), sfWhite);
    game->textures = create_textures(game);
    if (game->textures == NULL)
        return sfFalse;
    game->drawing = init_drawing(game);
    game->buttons = create_buttons(game);
    if (game->buttons == NULL)
        return sfFalse;
    return sfTrue;
}
