/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** initializations
*/

#include "my_paint.h"
#include "define.h"
#include "init_button.h"
#include "texture.h"

sfSprite *init_drawing(game_t *game)
{
    sfSprite *drawing = sfSprite_create();
    sfVector2u size_image = sfImage_getSize(game->image);
    sfVector2f position = {(WIDTH - size_image.x) / 2.0,
    (HEIGHT - size_image.y) * (2.0 / 3.0)};

    sfSprite_setTexture(drawing, game->textures[DRAWING], sfFalse);
    sfSprite_setPosition(drawing, position);
    return drawing;
}

button_t *init_button(game_t *game, int i)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, INIT_BUTTON[i].size);
    sfRectangleShape_setPosition(button->rect, INIT_BUTTON[i].position);
    button->function = INIT_BUTTON[i].function;
    sfRectangleShape_setTexture(button->rect,
        game->textures[INIT_BUTTON[i].texture], sfFalse);
    button->state = INIT_BUTTON[i].state;
    return button;
}
