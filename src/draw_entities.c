/*
** EPITECH PROJECT, 2024
** draw_entities
** File description:
** draw_entities
*/

#include "my_paint.h"

void draw_pixels(sfRenderWindow *window, sfSprite *drawing)
{
    if (drawing == NULL)
        return;
    sfRenderWindow_drawSprite(window, drawing, NULL);
}

void draw_menu_buttons(sfRenderWindow *window, drop_menu_t *menu)
{
    for (size_t j = 0; menu->buttons[j] != NULL; j++) {
        sfRenderWindow_drawRectangleShape(window,
        menu->buttons[j]->rect, NULL);
        sfRenderWindow_drawSprite(window,
        menu->buttons[j]->sprite, NULL);
    }
}

void draw_drop_menus(sfRenderWindow *window, drop_menu_t **menus)
{
    for (size_t i = 0; menus[i] != 0; i++) {
        sfRenderWindow_drawRectangleShape(window,
        menus[i]->menu_button->rect, NULL);
        sfRenderWindow_drawSprite(window,
        menus[i]->menu_button->sprite, NULL);
        if (menus[i]->menu_button->hide == sfFalse)
            draw_menu_buttons(window, menus[i]);
    }
}

void draw_entities(sfRenderWindow *window, sfSprite *background,
    paint_t *paint)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    draw_pixels(window, paint->drawing);
    draw_drop_menus(window, paint->menus);
}
