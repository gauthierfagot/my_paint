/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "my_paint.h"
#include "define.h"

static sfUint8 *init_default_rgba(void)
{
    sfUint8 *rgba = malloc(sizeof(sfUint8) * 5);

    if (rgba == NULL)
        return NULL;
    rgba[0] = 255;
    rgba[1] = 255;
    rgba[2] = 255;
    rgba[3] = 100;
    rgba[4] = 0;
    return rgba;
}

void central_loop(sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    sfSprite **pix_arr = NULL;
    sfUint8 *rgba = init_default_rgba();
    sfSprite *background = sfSprite_create();

    set_window_entities(game, background);
    while (sfRenderWindow_isOpen(window)) {
        if (analyze_events(window, &event, game->buttons, pix_arr) == sfFalse)
            break;
        draw_pixels_array(NULL, rgba, window, pix_arr);
        draw_entities(window, background, game->buttons);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfSprite_destroy(background);
}

int main(int argc, char **argv, char **env)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = NULL;
    game_t game = {0};

    (void)argv;
    if (check_env(env) == sfFalse || argc != 1)
        return 84;
    if (create_game(&game) == sfFalse)
        return 84;
    window = sfRenderWindow_create(mode, "Radar", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, FRAME);
    central_loop(window, &game);
    sfRenderWindow_close(window);
    destroy_variable(window, &game);
    return 0;
}
