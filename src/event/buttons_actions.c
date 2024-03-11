/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** button_action
*/

#include "color.h"

void action_test(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLUE];
    return;
}

void set_blue(void *, graphical_tool_t *tools)
{
    tools->color = color_tab[BLUE];
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
