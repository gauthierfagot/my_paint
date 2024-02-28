/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/
#include "my_paint.h"
#include "button.h"
#include "button_state.h"

sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (mouse_event->x >= rect.left && mouse_event->x <= rect.left + rect.width
    && mouse_event->y >= rect.top && mouse_event->y <= rect.top + rect.height){
        button->state = PRESSED;
        return sfTrue;
    }
    button->state = CLICKED;
    return sfFalse;
}

sfBool is_button_hover(button_t *button, sfMouseMoveEvent *mouse_event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
        button->state = HOVER;
        return sfTrue;
    }
    button->state = CLICKED;
    return sfFalse;
}

int analyze_events(sfRenderWindow *window, sfEvent *event, button_t *button)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return 1;
        if (event->type == sfEvtMouseButtonPressed) {
            if (button->is_clicked(button, &event->mouseButton))
                printf("Hello\n");
        }
        if (button->is_hover(button, &event->mouseMove))
            sfRectangleShape_setFillColor(button->rect, sfGreen);
        else
            sfRectangleShape_setFillColor(button->rect, sfWhite);
    }
    return 0;
}
