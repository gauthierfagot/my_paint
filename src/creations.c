/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** creations
*/
#include "my_paint.h"
#include "array_textures.h"
#include "button.h"
#include "init_button.h"
#include "define.h"
#include "init_drop_menu_array.h"
#include "graphical_tool.h"
#include "init_button_array.h"

static drop_menu_t **create_menus(paint_t *paint)
{
    drop_menu_t **menus = malloc(sizeof(drop_menu_t *) *
    (INIT_DROP_MENU_SIZE + 1));

    if (menus == NULL)
        return NULL;
    for (int i = 0; i < INIT_DROP_MENU_SIZE; i++) {
        menus[i] = init_drop_menu(paint, i);
        if (menus[i] == NULL)
            return NULL;
    }
    menus[INIT_DROP_MENU_SIZE] = NULL;
    return menus;
}

static sfTexture **create_textures(paint_t *paint)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * SIZE);

    if (textures == NULL)
        return NULL;
    textures[DRAWING] = sfTexture_createFromImage(paint->image, NULL);
    for (int i = 1; i < SIZE; i++) {
        textures[i] = sfTexture_createFromFile(ARRAY_TEXTURE[i - 1],
        NULL);
        if (textures[i] == NULL)
            return NULL;
    }
    return textures;
}

graphical_tool_t create_tools(void)
{
    graphical_tool_t tools;

    tools.height = 20;
    tools.width = 20;
    tools.tool = MOUSE;
    tools.shape = CIRCLE;
    tools.color = sfBlack;
    return tools;
}

static int search_init_button_size(void)
{
    int size = 0;

    for (int i = 0; i < INIT_BUTTONS_SIZE; i++) {
        if (INIT_BUTTONS[i].drop_menu == sfFalse)
            size++;
    }
    return size;
}

static button_t **create_buttons(paint_t *paint)
{
    int j = 0;
    int size = search_init_button_size();
    button_t **buttons = malloc(sizeof(button_t *) * (size + 1));

    if (buttons == NULL)
        return NULL;
    for (int i = 0; i < INIT_BUTTONS_SIZE; i++) {
        if (INIT_BUTTONS[i].drop_menu == sfFalse) {
            buttons[j] = init_button(paint, &INIT_BUTTONS[i]);
            j++;
        }
        if (INIT_BUTTONS[i].drop_menu == sfFalse && buttons[j - 1] == NULL)
            return NULL;
    }
    buttons[j] = NULL;
    return buttons;
}

sfBool create_paint(paint_t *paint)
{
    paint->image = sfImage_createFromColor(WIDTH_IMAGE,
    HEIGHT_IMAGE, sfWhite);
    paint->textures = create_textures(paint);
    if (paint->textures == NULL)
        return sfFalse;
    paint->drawing = init_drawing(paint);
    paint->menus = create_menus(paint);
    if (paint->menus == NULL)
        return sfFalse;
    paint->buttons = create_buttons(paint);
    if (paint->buttons == NULL)
        return sfFalse;
    return sfTrue;
}
