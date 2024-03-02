/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** initializations
*/

#include "my_paint.h"
#include "define.h"

button_t *init_button(sfVector2f position, sfVector2f size, char *picture)
{
    (void)picture;
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

sfSprite *init_pixel(graphical_tool_t *brush, sfUint8 *rgba)
{
    sfImage *image = sfImage_createFromPixels(brush->width, brush->height,
    rgba);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfSprite *sprite = sfSprite_create();

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
