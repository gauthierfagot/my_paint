/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/

#include "button_state.h"
#include "my_paint.h"
#include "button.h"
#include "texture.h"

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

sfBool action_test(button_t **)
{
    return sfTrue;
}

sfBool analyze_events(sfRenderWindow *window, sfEvent *event, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return sfFalse;
        if (event->type == sfEvtMouseButtonPressed) {
            sfImage_setPixel(game->image, event->mouseButton.x,
            event->mouseButton.y, sfRed);
            sfTexture_updateFromImage(game->textures[DRAWING], game->image,
            0, 0);
        }
    }
    return sfTrue;
}
