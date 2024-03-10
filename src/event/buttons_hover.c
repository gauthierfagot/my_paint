/*
** EPITECH PROJECT, 2024
** buttons_hover
** File description:
** buttons_hover
*/

#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"

sfBool is_button_hover(drop_menu_t *menu, button_t *button,
    sfMouseMoveEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
        button->state = HOVER;
        sfRectangleShape_setFillColor(button->rect, sfBlack);
        return sfTrue;
    }
    button->state = NONE;
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    return sfFalse;
}

void is_buttons_hover(sfEvent *event, paint_t *paint)
{
    for (size_t i = 0; paint->menus[i] != NULL; i++) {
        is_button_hover(paint->menus[i], paint->menus[i]->menu_button,
            &event->mouseMove);
        for (size_t j = 0; paint->menus[i]->buttons[j] != NULL &&
        paint->menus[i]->menu_button->hide == sfFalse; j++) {
            is_button_hover(paint->menus[i], paint->menus[i]->buttons[j],
                &event->mouseMove);
        }
    }
}
