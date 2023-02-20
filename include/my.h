/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** my
*/
#include "struct.h"

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_putstr(char const *str);
void help(void);
void load_2d_array_from_file(global_t *sk, int map_nb);
int get_line_nb(char * buffer);
int get_col_nb(char *buffer);
void init_game(global_t *sk);
void verif_tab(char *buffer, global_t *sk);
void play(global_t *sk);
void inputs(int ch, global_t *sk);
void move_up(global_t *sk);
void move_dw(global_t *sk);
void move_lf(global_t *sk);
void move_rg(global_t *sk);
int conditions(global_t *sk);
void win_screen(global_t *sk);
void lose_screen(global_t *sk);

#endif /* !MY_H_ */
