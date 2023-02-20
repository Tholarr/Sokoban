/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** main
*/
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/struct.h"
#include "./include/define.h"

void display(global_t *sk)
{
    int R = sk->map_lines;
    int C = sk->map_cols;

    if (sk->scr_lines < R || sk->scr_cols < C) {
        clear();
        mvprintw((sk->scr_lines / 2 - 2),
                (sk->scr_cols / 2) - (18 / 2), "terminal too smsk");
        refresh();
    } else {
        for (int i = 0; sk->front_map[i]; i++) {
            mvprintw((sk->scr_lines / 2) - (R - 3),
            (sk->scr_cols / 2) - (C / 2), "%s", sk->front_map[i]);
            R--;
        }
    }
}

void play(global_t *sk)
{
    int ch;
    int set = 0;

    initscr();
    curs_set(false);
    noecho();
    while (set == 0) {
        getmaxyx(stdscr, sk->scr_lines, sk->scr_cols);
        clear();
        display(sk);
        ch = getch();
        inputs(ch, sk);
        set = conditions(sk);
        refresh();
    }
    endwin();
    if (set == 1)
        win_screen(sk);
    if (set == 2)
        lose_screen(sk);
}

int main(int ac, char **av)
{
    global_t sk;
    sk.filepath = av[1];

    if (ac != 2)
        return 84;
    else if (av[1][0] == '-' && av[1][1] == 'h')
        help();
    else {
        init_game(&sk);
    }
    return 0;
}
