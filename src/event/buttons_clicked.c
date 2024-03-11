/*
** EPITECH PROJECT, 2024
** buttons_clicked
** File description:
** buttons_clicked
*/

#include "button_state.h"
#include "my_paint.h"
#include "define.h"

static sfBool is_button_clicked(void *data, button_t *button,
    graphical_tool_t *tools, sfMouseButtonEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (button->state == INVALID)
        return sfFalse;
    if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
        button->function(data, tools);
        button->state = CLICKED;
        return sfTrue;
    }
    button->state = DEFAULT;
    return sfFalse;
}

static sfBool check_menu_buttons_clicked(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools, int i)
{
    for (size_t j = 0; paint->menus[i]->buttons[j] != NULL &&
    paint->menus[i]->hide == sfFalse; j++) {
        if (is_button_clicked(NULL, paint->menus[i]->buttons[j],
            tools, &event->mouseButton))
            return sfTrue;
    }
    return sfFalse;
}

void are_buttons_clicked(sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    for (size_t i = 0; paint->menus[i] != NULL; i++) {
        is_button_clicked(paint->menus[i], paint->menus[i]->menu_button,
            tools, &event->mouseButton);
        if (check_menu_buttons_clicked(event, paint, tools, i))
            paint->menus[i]->hide = sfTrue;
    }
    for (size_t i = 0; paint->buttons[i] != NULL; i++) {
        is_button_clicked(NULL, paint->buttons[i],
            tools, &event->mouseButton);
    }
}
