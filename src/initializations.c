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
#include "init_drop_menu_array.h"

sfSprite *init_drawing(paint_t *paint)
{
    sfSprite *drawing = sfSprite_create();
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2f position = {(WIDTH - size_image.x) / 2.0,
    (HEIGHT - size_image.y) * (2.0 / 3.0)};

    sfSprite_setTexture(drawing, paint->textures[DRAWING], sfFalse);
    sfSprite_setPosition(drawing, position);
    return drawing;
}

static void set_button(paint_t *paint,
    const init_buttons_t *init_button_array, button_t *button)
{
    sfVector2u size_texture = sfTexture_getSize(
        paint->textures[init_button_array->texture]);
    sfVector2f scale = {init_button_array->size.x / size_texture.x,
        init_button_array->size.y / size_texture.y};

    sfRectangleShape_setSize(button->rect, init_button_array->size);
    sfRectangleShape_setPosition(button->rect, init_button_array->position);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    sfSprite_setScale(button->sprite, scale);
    sfSprite_setPosition(button->sprite, init_button_array->position);
    sfSprite_setTexture(button->sprite,
        paint->textures[init_button_array->texture], sfFalse);
}

button_t *init_button(paint_t *paint, const init_buttons_t *init_button_array)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL)
        return NULL;
    button->sprite = sfSprite_create();
    if (button->sprite == NULL)
        return NULL;
    button->function = init_button_array->function;
    button->state = init_button_array->state;
    set_button(paint, init_button_array, button);
    return button;
}

drop_menu_t *init_drop_menu(paint_t *paint, int i)
{
    drop_menu_t *menu = malloc(sizeof(drop_menu_t));

    if (menu == NULL)
        return NULL;
    menu->menu_button = init_button(paint, &INIT_DROP_MENU[i]);
    if (menu->menu_button == NULL)
        return NULL;
    menu->buttons = create_buttons(paint, INIT_DROP_MENU[i].menu);
    if (menu->buttons == NULL)
        return NULL;
    menu->hide = sfTrue;
    return menu;
}
