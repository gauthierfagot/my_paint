/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "my_paint.h"
#include "graphical_tool.h"
#include "define.h"
#include "color.h"

void central_loop(sfRenderWindow *window, paint_t *paint)
{
    sfEvent event;
    graphical_tool_t tools = create_tools();
    sfRectangleShape *background = sfRectangleShape_create();

    if (background == NULL)
        return;
    set_window_entities(background);
    while (sfRenderWindow_isOpen(window)) {
        if (analyze_events(window, &event, paint, &tools) == sfFalse)
            break;
        draw_entities(window, background, paint);
        sfTexture_updateFromImage(paint->textures[DRAWING],
            paint->image, 0, 0);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, color_tab[BACKGROUND_COLOR]);
    }
    sfRectangleShape_destroy(background);
}

int main(int argc, char **argv, char **env)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = NULL;
    paint_t paint = {0};

    (void)argv;
    if (check_env(env) == sfFalse || argc != 1)
        return 84;
    window = sfRenderWindow_create(mode, "Paint", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    if (create_paint(&paint) == sfFalse) {
        sfRenderWindow_destroy(window);
        return 84;
    }
    sfRenderWindow_setFramerateLimit(window, FRAME);
    central_loop(window, &paint);
    sfRenderWindow_close(window);
    destroy_variable(window, &paint);
    return 0;
}
