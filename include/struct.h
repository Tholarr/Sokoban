/*
** EPITECH PROJECT, 2022
** BTTF_sokoban
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct verif {
        int wrong_char;
        int great;
        int p;
        int x;
        int o;
    } verif_t;

    typedef struct global {
        verif_t verif;
        char *filepath;
        char **front_map;
        char **back_map;
        int map_lines;
        int map_cols;
        int scr_lines;
        int scr_cols;
        int player_pos_x;
        int player_pos_y;
        int box_nb;
    } global_t;

#endif /* !STRUCT_H_ */
