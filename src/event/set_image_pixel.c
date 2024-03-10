/*
** EPITECH PROJECT, 2024
** set_pixel_image
** File description:
** set_pixel_image
*/

#include <math.h>
#include "button_state.h"
#include "my_paint.h"
#include "define.h"
#include "button.h"
#include "texture.h"

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

    (void)event;
    if (check_collision(paint, mouse, &tools) == sfFalse)
        return;
    if (tools.tool == ERASER)
        tools.color = sfWhite;
    if (tools.shape == SQUARE)
        return draw_square(paint, mouse, tools);
    else if (tools.shape == CIRCLE)
        return;
    return;
}
