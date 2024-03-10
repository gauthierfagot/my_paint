/*
** EPITECH PROJECT, 2024
** drop_menu
** File description:
** drop_menu
*/

#ifndef DROP_MENU_H
    #define DROP_MENU_H
    #include "button.h"

typedef struct drop_menu_s {
    struct button_s *menu_button;
    struct button_s **buttons;
} drop_menu_t;

typedef enum e_drop_menu {
    BUTTON = -1,
    FILE,
    EDITION,
    INFO
} e_drop_menu;

#endif /* !DROP_MENU_H */
