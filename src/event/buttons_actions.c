/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** button_action
*/

#include "define.h"
#include "color.h"

void bin_action(void *data, graphical_tool_t *)
{
    paint_t *paint = (paint_t *)data;
    sfVector2u size_image = sfImage_getSize(paint->image);

    sfImage_destroy(paint->image);
    paint->image = sfImage_createFromColor(size_image.x, size_image.y,
        sfTransparent);
    return;
}

void eraser_action(void *, graphical_tool_t *tools)
{
    tools->tool = ERASER;
    return;
}

void brush_action(void *, graphical_tool_t *tools)
{
    tools->tool = BRUSH;
    return;
}

void pencil_action(void *, graphical_tool_t *tools)
{
    tools->tool = PENCIL;
    return;
}

void drop_menu_action(void *data, graphical_tool_t *)
{
    drop_menu_t *menu = (drop_menu_t *)data;

    if (menu->hide == sfTrue)
        menu->hide = sfFalse;
    else
        menu->hide = sfTrue;
}
