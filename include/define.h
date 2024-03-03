/*
** EPITECH PROJECT, 2024
** define
** File description:
** defining Macros
*/

#ifndef _PAINT
    #define _PAINT

    #define WIDTH 1920
    #define HEIGHT 1080
    #define FRAME 30

    #define IS_HOVER(button) (button->state == HOVER)
    #define IS_CLICKED(button) (button->state == CLICKED)
    #define IS_PRESSED(button) (button->state == PRESSED)

#endif /* !_PAINT */
