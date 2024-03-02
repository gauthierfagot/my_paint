/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** add
*/

#include "my_paint.h"
#include "drop_menu.h"

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

struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *
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
