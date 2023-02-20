/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** inputs_gestion
*/
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/struct.h"
#include "./include/define.h"

void inputs(int ch, global_t *sk)
{
    switch (ch) {
        case 32:
            free(sk->front_map);
            free(sk->back_map);
            init_game(sk);
            break;
        case 'A':
            move_up(sk);
            break;
        case 'B':
            move_dw(sk);
            break;
        case 'C':
            move_rg(sk);
            break;
        case 'D':
            move_lf(sk);
            break;
    }
}
