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

static drop_menu_t **create_menus(paint_t *paint)
{
    drop_menu_t **menus = malloc(sizeof(drop_menu_t *) *
    (INIT_DROP_MENU_SIZE + 1));

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
    tools.shape = SQUARE;
    tools.color = sfBlack;
    tools.opacity = 1;
    return tools;
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
    return sfTrue;
}
