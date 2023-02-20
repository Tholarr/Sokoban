/*
** EPITECH PROJECT, 2022
** BTTF-sokoban
** File description:
** info_file
*/

int get_col_nb(char *buffer)
{
    int col_nb = 0;
    int i;

    for (i = 0; buffer[i] != '\n'; i++) {
        col_nb++;
    }
    return col_nb + 1;
}

int get_line_nb(char * buffer)
{
    int line_nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            line_nb++;
    }
    return line_nb + 1;
}
