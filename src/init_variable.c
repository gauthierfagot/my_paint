/*
** EPITECH PROJECT, 2024
** init_variable
** File description:
** init_variable
*/
#include "my_paint.h"
#include "array_texture.h"
#include "texture.h"
#include "button.h"
#include "button_state.h"
#include "drop_menu.h"

struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *drop_menu)
{
    struct s_gui_options *new_option = malloc(sizeof(struct s_gui_options));
    sfVector2f position = sfRectangleShape_getPosition(
        drop_menu->button->rect);
    sfVector2f size = sfRectangleShape_getSize(drop_menu->button->rect);
    sfVector2f option_position = {position.x + size.x, position.y + size.y};
    sfVector2f option_size = {size.x, size.y};

    new_option->option = init_button(option_position, option_size);
    new_option->next = drop_menu->options;
    drop_menu->options = new_option;
    return drop_menu;
}

struct s_gui_drop_menu *create_drop_menu(sfVector2f position, sfVector2f size)
{
    struct s_gui_drop_menu *drop_menu = malloc(sizeof(struct s_gui_drop_menu));

    drop_menu->button = init_button(position, size);
    drop_menu->options = NULL;
    return drop_menu;
}

button_t *init_button(sfVector2f position, sfVector2f size)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    button->is_clicked = is_button_clicked;
    button->is_hover = is_button_hover;
    button->state = CLICKED;
    return button;
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
