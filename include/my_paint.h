/*
** EPITECH PROJECT, 2024
** paint.h
** File description:
** paint.h
*/

#ifndef PAINT
    #define PAINT
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

enum {
    HOVER,
    CLICKED,
    PRESSED,
};

typedef struct button_s {
    int status;
} button_t;

#endif /* !PAINT */
