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

sfSprite *init_pixel(graphical_tool_t *brush, sfUint8 *rgba)
{
    sfImage *image = NULL;
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    if (brush == NULL)
        image = sfImage_createFromPixels(10, 10, rgba);
    else
        image = sfImage_createFromPixels(brush->width, brush->height,
    rgba);
    texture = sfTexture_createFromImage(image, NULL);
    sprite = sfSprite_create();
    if (texture == NULL || sprite == NULL)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

// pixel_t *init_pixel(sfUint8 *rgba, sfVector2f placement)
// {
//     pixel_t *pixel = {0};

//     pixel->r = rgba[RED];
//     pixel->g = rgba[GREEN];
//     pixel->b = rgba[BLUE];
//     pixel->a = rgba[ALPHA];
//     pixel->placement = placement;
//     return pixel;
// }
