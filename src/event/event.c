/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/
#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"
#include "texture.h"

sfBool analyze_events(sfRenderWindow *window, sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return sfFalse;
        is_buttons_hover(event, paint);
        if (event->type == sfEvtMouseButtonPressed) {
            is_buttons_clicked(event, paint, tools);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            set_pixel(window, paint, event, *tools);
        }
    }
    return sfTrue;
}
