/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** button_action
*/

#include "my_paint.h"

void action_test(drop_menu_t *menu, button_t *, graphical_tool_t *tools)
{
    tools->color = sfRed;
    menu->menu_button->hide = sfTrue;
}

void drop_menu_action(drop_menu_t *menu, button_t *, graphical_tool_t *)
{
    if (menu->menu_button->hide == sfTrue)
        menu->menu_button->hide = sfFalse;
    else
        menu->menu_button->hide = sfTrue;
}
