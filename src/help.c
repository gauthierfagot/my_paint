/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** help
*/

#include "my_paint.h"

void analyse_close(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (sfEvtClosed == event.type)
            sfRenderWindow_close(window);
    return;
}

sfText *help_text(void)
{
    sfFont *font = sfFont_createFromFile("font/Edosz.ttf");
    sfText *instru = sfText_create();
    char *help = "You can choose your tool in the second drop menu,\nand so "
    "can you with color, shape and thickness on the right side of drop menus."
    "\n\nThe chosen color/size/shape/tool is outlined with magenta.\n\nYou can"
    " click the trash to erase all your drawing.\n\nThe drip tool will allow "
    "you to pick up a color. Once your done with the drip,\ntake back the "
    "pencil or brush.\n\nThe first menu allow to save, open a file or import "
    "an image.\n\n\t\t\t\tEnjoy and have fun :)";

    sfText_setString(instru, help);
    sfText_setCharacterSize(instru, 15);
    sfText_setColor(instru, sfWhite);
    sfText_setFont(instru, font);
    return instru;
}

sfSprite *background_help(void)
{
    sfSprite *background = sfSprite_create();
    sfImage *image = sfImage_createFromColor(600, 400, sfBlack);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);

    sfSprite_setTexture(background, texture, sfTrue);
    return background;
}

sfRenderWindow *create_window(char *name)
{
    sfVideoMode mode = {600, 400, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, name,
    sfDefaultStyle, NULL);

    return window;
}

void help(void *, graphical_tool_t *)
{
    sfRenderWindow *window = create_window("Help");
    sfSprite *background = background_help();
    sfText *instru = help_text();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawText(window, instru, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfWhite);
        analyse_close(window);
    }
    sfText_destroy(instru);
    sfSprite_destroy(background);
    sfRenderWindow_destroy(window);
    return;
}
