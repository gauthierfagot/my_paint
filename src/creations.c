/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** creations
*/

#include "array_textures.h"
#include "drop_menu.h"
#include "my_paint.h"
#include "define.h"

struct s_gui_drop_menu *create_drop_menu(sfVector2f position, sfVector2f size,
    char *picture)
{
    struct s_gui_drop_menu *drop_menu = malloc(sizeof(struct s_gui_drop_menu));

    drop_menu->button = init_button(position, size, picture);
    drop_menu->options = NULL;
    return drop_menu;
}

int create_game(game_t *game)
{
    game->textures = malloc(sizeof(sfTexture *) * ARRAY_TEXTURE_SIZE);
    for (int i = 0; i < ARRAY_TEXTURE_SIZE; i ++) {
        game->textures[i] = sfTexture_createFromFile(ARRAY_TEXTURE[i], NULL);
        if (game->textures[i] == NULL)
            return 84;
    }
    return 0;
}
