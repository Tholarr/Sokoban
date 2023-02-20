/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** verif
*/
#include <ncurses.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/struct.h"

void tab_wrong_display(void)
{
    my_putstr("Map not valid :/\n");
    exit(84);
}

void tab_trial(global_t *sk)
{
    if (sk->verif.wrong_char != 0)
        tab_wrong_display();
    if (sk->verif.p != 1)
        tab_wrong_display();
    if (sk->verif.x != sk->verif.o)
        tab_wrong_display();
    if (sk->verif.x < 1)
        tab_wrong_display();
}

void verif_tab(char *buffer, global_t *sk)
{
    sk->verif.wrong_char = 0;
    sk->verif.p = 0;
    sk->verif.x = 0;
    sk->verif.o = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 'P' && buffer[i] != 'X' && buffer[i] != 'O' &&
            buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != '#')
            sk->verif.wrong_char ++;
        switch (buffer[i]) {
            case 'P' : sk->verif.p++; break;
            case 'X' : sk->verif.x++; break;
            case 'O' : sk->verif.o++; break;
        }
    }
    tab_trial(sk);
}
