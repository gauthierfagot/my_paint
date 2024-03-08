/*
** EPITECH PROJECT, 2024
** drop_menu
** File description:
** drop_menu
*/

#ifndef DROP_MENU_H
    #define DROP_MENU_H

typedef struct drop_menu_s {
    button_t *menu_button;
    button_t **buttons;
} drop_menu_t;

typedef enum e_drop_menu {
    BUTTON = -1,
    FILE,
    EDITION,
    INFO
} e_drop_menu;

#endif /* !DROP_MENU_H */
