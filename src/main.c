/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "my_paint.h"
#include "button.h"
#include "button_state.h"
#include "drop_menu.h"

void central_loop(sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    sfVector2f size = {50, 50};
    sfVector2f position = {100, 100};
    sfSprite *background = sfSprite_create();
    button_t *button = init_button(position, size, "brush.jpg");

    set_window_entities(game, background);
    while (sfRenderWindow_isOpen(window)) {
        if (analyze_events(window, &event, button) == 1)
            break;
        draw_entities(window, background, button);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfSprite_destroy(background);
}

int main(int argc, char **argv, char **env)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = NULL;
    game_t game;

    (void)argv;
    if (env[0] == NULL || argc != 1)
        return 84;
    if (create_game(&game) == 84)
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
