/*
** EPITECH PROJECT, 2024
** buttons_clicked
** File description:
** buttons_clicked
*/

#include "button_state.h"
#include "my_paint.h"
#include "define.h"

static void is_button_clicked(drop_menu_t *menu, button_t *button,
    graphical_tool_t *tools, sfMouseButtonEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (button->state == INVALID)
        return;
    if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
        button->function(menu, button, tools);
        button->state = CLICKED;
        return;
    }
    button->state = DEFAULT;
    return;
}

void are_buttons_clicked(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    for (size_t i = 0; paint->menus[i] != NULL; i++) {
        is_button_clicked(paint->menus[i], paint->menus[i]->menu_button,
            tools, &event->mouseButton);
        for (size_t j = 0; paint->menus[i]->buttons[j] != NULL &&
        paint->menus[i]->menu_button->hide == sfFalse; j++) {
            is_button_clicked(paint->menus[i], paint->menus[i]->buttons[j],
                tools, &event->mouseButton);
        }
    }
    return;
}
