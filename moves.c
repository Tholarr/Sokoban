/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** moves
*/
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/struct.h"
#include "./include/define.h"

void move_up(global_t *sk)
{
    if (sk->front_map[Py - 1][Px] == 'X' &&
        (sk->back_map[Py - 2][Px] == ' ' ||
        sk->front_map[Py - 2][Px] == 'O')) {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py - 1][Px] = 'P';
        sk->front_map[Py - 2][Px] = 'X';
        Py--;
    } else if (sk->front_map[Py - 1][Px] == ' ' ||
        sk->front_map[Py - 1][Px] == 'O') {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py - 1][Px] = 'P';
        Py--;
    }
}

void move_dw(global_t *sk)
{
    if (sk->front_map[Py + 1][Px] == 'X' &&
        (sk->back_map[Py + 2][Px] == ' ' ||
        sk->front_map[Py + 2][Px] == 'O')) {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py + 1][Px] = 'P';
        sk->front_map[Py + 2][Px] = 'X';
        Py++;
    } else if (sk->front_map[Py + 1][Px] == ' ' ||
        sk->front_map[Py + 1][Px] == 'O') {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py + 1][Px] = 'P';
        Py++;
    }
}

void move_rg(global_t *sk)
{
    if (sk->front_map[Py][Px + 1] == 'X' &&
        (sk->back_map[Py][Px + 2] == ' ' ||
        sk->front_map[Py][Px + 2] == 'O')) {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py][Px + 1] = 'P';
        sk->front_map[Py][Px + 2] = 'X';
        Px++;
    } else if (sk->front_map[Py][Px + 1] == ' ' ||
        sk->front_map[Py][Px + 1] == 'O') {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py][Px + 1] = 'P';
        Px++;
    }
}

void move_lf(global_t *sk)
{
    if (sk->front_map[Py][Px - 1] == 'X' &&
        (sk->back_map[Py][Px - 2] == ' ' ||
        sk->front_map[Py][Px - 2] == 'O')) {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py][Px - 1] = 'P';
        sk->front_map[Py][Px - 2] = 'X';
        Px--;
    } else if (sk->front_map[Py][Px - 1] == ' ' ||
        sk->front_map[Py][Px - 1] == 'O') {
        sk->front_map[Py][Px] = sk->back_map[Py][Px];
        sk->front_map[Py][Px - 1] = 'P';
        Px--;
    }
}
