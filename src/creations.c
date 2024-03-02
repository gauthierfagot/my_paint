/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** creations
*/

#include "array_texture.h"
#include "drop_menu.h"
#include "my_paint.h"
#include "texture.h"
#include "define.h"

static struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *
    drop_menu, char *picture)
{
    struct s_gui_options *new_option = malloc(sizeof(struct s_gui_options));
    sfVector2f position = sfRectangleShape_getPosition(
        drop_menu->button->rect);
    sfVector2f size = sfRectangleShape_getSize(drop_menu->button->rect);
    sfVector2f option_position = {position.x + size.x, position.y + size.y};
    sfVector2f option_size = {size.x, size.y};

    new_option->option = init_button(option_position, option_size, picture);
    new_option->next = drop_menu->options;
    drop_menu->options = new_option;
    return drop_menu;
}

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
