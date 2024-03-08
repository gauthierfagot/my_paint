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

// sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *mouse_event)
// {
//     sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

//     if (mouse_event->x >= rect.left &&
//     mouse_event->x <= rect.left + rect.width
//     && mouse_event->y >= rect.top &&
//     mouse_event->y <= rect.top + rect.height) {
//         button->state = PRESSED;
//         return sfTrue;
//     }
//     button->state = CLICKED;
//     return sfFalse;
// }

// sfBool is_button_hover(button_t *button, sfMouseMoveEvent *mouse_event)
// {
//     sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

//     if (sfFloatRect_contains(&rect, mouse_event->x, mouse_event->y)) {
//         button->state = HOVER;
//         return sfTrue;
//     }
//     button->state = CLICKED;
//     return sfFalse;
// }

void draw_square(paint_t *paint, sfVector2i mouse, graphical_tool_t tools)
{
    sfVector2f position = sfSprite_getPosition(paint->drawing);
    int mouse_x = mouse.x - (tools.width / 2);
    int mouse_y = mouse.y - (tools.height / 2);

    for (int i = 0; i < tools.height; i++) {
        for (int j = 0; j < tools.width; j++) {
            sfImage_setPixel(paint->image, (mouse_x + j) - position.x,
            (mouse_y + i) - position.y, tools.color);
        }
    }
    sfTexture_updateFromImage(paint->textures[DRAWING], paint->image, 0, 0);
}

sfBool check_collision(paint_t *paint, sfVector2i mouse,
    graphical_tool_t *tools)
{
    sfVector2u size_image = sfImage_getSize(paint->image);
    sfVector2f position = {(WIDTH - size_image.x) / 2.0,
    (HEIGHT - size_image.y) * (2.0 / 3.0)};

    if (mouse.x <= position.x || mouse.x >= position.x + size_image.x ||
    mouse.y <= position.y || mouse.y >= position.y + size_image.y)
        return sfFalse;
    if (mouse.x <= position.x + (tools->width / 2))
        tools->width = (mouse.x - position.x) * 2;
    if (mouse.x >= position.x + size_image.x - (tools->width / 2))
        tools->width = (position.x + size_image.x - mouse.x) * 2;
    if (mouse.y <= position.y + (tools->height / 2))
        tools->height = (mouse.y - position.y) * 2;
    if (mouse.y >= position.y + size_image.y - (tools->height / 2))
        tools->height = (position.y + size_image.y - mouse.y) * 2;
    return sfTrue;
}

void set_pixel(sfRenderWindow *window, paint_t *paint, sfEvent *event,
    graphical_tool_t tools)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (check_collision(paint, mouse, &tools) == sfFalse)
        return;
    if (tools.tool == ERASED)
        tools.color = sfWhite;
    if (tools.shape == SQUARE)
        draw_square(paint, mouse, tools);
    if (tools.shape == CIRCLE)
        return;
}

sfBool action_test(graphical_tool_t *)
{
    return sfTrue;
}

sfBool analyze_events(sfRenderWindow *window, sfEvent *event, paint_t *paint,
    graphical_tool_t *tools)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return sfFalse;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            set_pixel(window, paint, event, *tools);
        }
    }
    return sfTrue;
}
