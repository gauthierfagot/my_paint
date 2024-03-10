/*
** EPITECH PROJECT, 2024
** buttons_clicked
** File description:
** buttons_clicked
*/

#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"

void action_test(drop_menu_t *menu, button_t *button, graphical_tool_t *tools)
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

sfBool is_button_clicked(drop_menu_t *menu, button_t *button,
    graphical_tool_t *tools, sfMouseButtonEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (button->state == INVALID)
        return sfFalse;
    if (mouse_event->x >= rect.left &&
    mouse_event->x <= rect.left + rect.width
    && mouse_event->y >= rect.top &&
    mouse_event->y <= rect.top + rect.height) {
        button->state = CLICKED;
        button->function(menu, button, tools);
        return sfTrue;
    }
    button->state = NONE;
    return sfFalse;
}

sfBool is_menu_button_clicked(drop_menu_t *menu, button_t *button,
    graphical_tool_t *tools, sfMouseButtonEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (button->state == INVALID)
        return sfFalse;
    if (mouse_event->x >= rect.left &&
    mouse_event->x <= rect.left + rect.width
    && mouse_event->y >= rect.top &&
    mouse_event->y <= rect.top + rect.height) {
        button->state = CLICKED;
        button->function(menu, button, tools);
        return sfTrue;
    }
    button->state = NONE;
    return sfFalse;
}

void is_buttons_clicked(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    for (size_t i = 0; paint->menus[i] != NULL; i++) {
        is_menu_button_clicked(paint->menus[i], paint->menus[i]->menu_button,
            tools, &event->mouseButton);
        for (size_t j = 0; paint->menus[i]->buttons[j] != NULL &&
        paint->menus[i]->menu_button->hide == sfFalse; j++) {
            is_button_clicked(paint->menus[i], paint->menus[i]->buttons[j],
                tools, &event->mouseButton);
        }
    }
}
