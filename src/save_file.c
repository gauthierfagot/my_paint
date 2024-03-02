/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** save_file
*/

#include "my_paint.h"

void save_drawing(const sfImage *image,const char *name) {
    sfImage_saveToFile(image, name);
}