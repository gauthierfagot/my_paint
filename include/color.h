/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** color
*/

#ifndef COLOR_H_
    #define COLOR_H_
    #include "my_paint.h"

enum colors {
    RED = 0,
    GREEN,
    BLUE,
    CYAN,
    YELLOW,
    ORANGE,
    PURPLE,
    PINK,
    BEIGE,
    BROWN,
    GREY,
    WHITE,
    BLACK,
    NB_COLORS
};

static const sfColor color_tab[NB_COLORS] = {
    {.r = 255, .g = 0, .b = 0, .a = 255},
    {.r = 0, .g = 255, .b = 0, .a = 255},
    {.r = 0, .g = 0, .b = 255, .a = 255},
    {.r = 0, .g = 255, .b = 255, .a = 255},
    {.r = 255, .g = 255, .b = 0, .a = 255},
    {.r = 255, .g = 128, .b = 0, .a = 255},
    {.r = 127, .g = 0, .b = 255, .a = 255},
    {.r = 255, .g = 102, .b = 178, .a = 255},
    {.r = 255, .g = 204, .b = 153, .a = 255},
    {.r = 153, .g = 76, .b = 0, .a = 255},
    {.r = 192, .g = 192, .b = 192, .a = 255},
    {.r = 0, .g = 0, .b = 0, .a = 255},
    {.r = 255, .g = 255, .b = 255, .a = 255},
};

#endif /* !COLOR_H_ */
