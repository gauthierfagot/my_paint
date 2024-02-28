/*
** EPITECH PROJECT, 2024
** drop_menu
** File description:
** drop_menu
*/

#ifndef DROP_MENU_H
    #define DROP_MENU_H
    #include "button.h"

struct s_gui_options {
    struct button_s *option;
    struct s_gui_options *next;
};

struct s_gui_drop_menu {
    button_t *button;
    struct s_gui_options *options;
};

#endif /* !DROP_MENU_H */
