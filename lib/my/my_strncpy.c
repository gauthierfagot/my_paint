/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** strncpy
*/

#include "lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_dest = my_strlen(dest) - 1;

    while (n != 0) {
        dest[i] = src[i];
        i ++;
        n --;
    }
    if (n > len_dest) {
        dest[i] = '\0';
    }
    return dest;
}
