/*
** EPITECH PROJECT, 2023
** free_variable
** File description:
** free_variable
*/
#include "my_paint.h"
#include "texture.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

static void destroy_textures(game_t *game)
{
    if (game->textures == NULL)
        return;
    for (int i = 0; i < ARRAY_TEXTURE_SIZE; i++) {
        sfTexture_destroy(game->textures[i]);
    }
    free(game->textures);
}

static void destroy_buttons(game_t *game)
{
    if (game->buttons == NULL)
        return;
    for (int i = 0; game->buttons[i] != NULL ; i++) {
        sfRectangleShape_destroy(game->buttons[i]->rect);
        free(game->buttons[i]);
    }
    free(game->buttons);
}

void destroy_variable(sfRenderWindow *window, game_t *game)
{
    destroy_buttons(game);
    destroy_textures(game);
    sfRenderWindow_destroy(window);
}
