/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** help
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCCRIPTION\n");
    my_putstr("     map  file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
    return;
}
