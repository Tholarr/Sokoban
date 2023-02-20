/*
** EPITECH PROJECT, 2022
** BTTF-sokoban
** File description:
** init_map
*/
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/struct.h"
#include "./include/define.h"

void check_char(global_t *sk, int y, int x, int check)
{
    if (check == 0) {
        switch (sk->front_map[y][x]) {
            case 'P':
                sk->player_pos_x = x;
                sk->player_pos_y = y;
                break;
            case 'O':
                sk->box_nb++;
                break;
        }
    }
    if (check == 1) {
        if (sk->back_map[y][x] == 'P' || sk->back_map[y][x] == 'X')
            sk->back_map[y][x] = ' ';
    }
}

void cpy_tab0(char *buffer, global_t *sk)
{
    int line_nb = get_line_nb(buffer);
    int col_nb = get_col_nb(buffer);
    int x = 0;
    int y = 0;
    int i = 0;

    sk->front_map = malloc(sizeof(char *) * (line_nb + 1));

    for (int a = 0; a < line_nb; a++)
        sk->front_map[a] = malloc(sizeof(char) * (col_nb + 1));

    for (i = 0; buffer[i] != '\0'; i++) {
        sk->front_map[y][x] = buffer[i];
        check_char(sk, y, x, 0);
        x++;
        if (buffer[i] == '\n') {
            y++;
            x = 0;
        }
    }
}

void cpy_tab1(char *buffer, global_t *sk)
{
    int x = 0;
    int y = 0;
    int i = 0;
    sk->map_lines = get_line_nb(buffer);
    sk->map_cols = get_col_nb(buffer);

    sk->back_map = malloc(sizeof(char *) * (sk->map_lines + 1));

    for (int a = 0; a < sk->map_lines; a++)
        sk->back_map[a] = malloc(sizeof(char) * (sk->map_cols + 1));

    for (i = 0; buffer[i] != '\0'; i++) {
        sk->back_map[y][x] = buffer[i];
        check_char(sk, y, x, 1);
        x++;
        if (buffer[i] == '\n') {
            y++;
            x = 0;
        }
    }
}

void load_2d_array_from_file(global_t *sk, int map_nb)
{
    struct stat sb;
    stat(sk->filepath, &sb);
    char buffer[sb.st_size + 1];
    int fd = open(sk->filepath, O_RDONLY);

    read(fd, buffer, sb.st_size);
    verif_tab(buffer, sk);
    switch (map_nb) {
        case 0:
            cpy_tab0(buffer, sk);
            break;
        case 1:
            cpy_tab1(buffer, sk);
            break;
    }
    close(fd);
}

void init_game(global_t *sk)
{
    sk->box_nb = 0;

    load_2d_array_from_file(sk, 0);
    load_2d_array_from_file(sk, 1);
    play(sk);
}
