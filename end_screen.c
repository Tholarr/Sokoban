/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** end_screen
*/
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/struct.h"
#include "./include/define.h"

void win_screen(global_t *sk)
{
    int rows;
    int cols;

    getmaxyx(stdscr, rows, cols);
    while (1) {
        clear();
        mvprintw((rows / 2), (cols / 2) - (9 / 2), "YOU WIN !");
        refresh();
        if (getch()) {
            endwin();
            exit(0);
        }
    }
}

void lose_screen(global_t *sk)
{
    int rows;
    int cols;

    getmaxyx(stdscr, rows, cols);
    while (1) {
        clear();
        mvprintw((rows / 2), (cols / 2) - (11 / 2), "YOU LOSE...");
        refresh();
        if (getch()) {
            endwin();
            exit(0);
        }
    }
}

int win_cond(global_t *sk, int y, int x, int fill)
{
    if (MAP_S[y][x] == 'O' && MAP[y][x] == 'X')
        fill++;

    return fill;
}

int lose_cond(global_t *sk, int y, int x, int lose_cmp)
{
    if (MAP[y][x] == 'X') {
        if ((MAP[y - 1][x] == '#' || MAP[y - 1][x] == 'X' ||
            MAP[y + 1][x] == '#' || MAP[y + 1][x] == 'X') &&
            (MAP[y][x - 1] == '#' || MAP[y][x - 1] == 'X' ||
            MAP[y][x + 1] == '#' || MAP[y][x + 1] == 'X'))
            lose_cmp++;
    }
    return lose_cmp;
}

int conditions(global_t *sk)
{
    int fill = 0;
    int lose_cmp = 0;
    int x = 0;

    for (int y = 0; sk->front_map[y][x] != '\0'; y++) {
        for (x = 0; MAP_S[y][x] != '\n'; x++) {
            fill = win_cond(sk, y, x, fill);
            lose_cmp = lose_cond(sk, y, x, lose_cmp);
        }
    }

    if (fill == sk->box_nb)
        return 1;
    else if (lose_cmp == sk->box_nb)
        return 2;
    else
        return 0;
}
