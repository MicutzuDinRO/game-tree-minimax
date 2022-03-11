// Header-ul corespunzator tablei de joc X si 0 si a functiilor necesare

#ifndef _TICTACTOE_H__
#define _TICTACTOE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID 3

// Tipul unei table de joc X si 0
typedef struct grid {
    char grid[GRID][GRID];
} Grid;

// Initializeaza tabla de joc
Grid init_grid() {
    Grid grid;
    int i, j;
    for (i = 0; i < GRID; i++)
        for (j = 0; j < GRID; j++)
            grid.grid[i][j] = '-';
    return grid;
}

// Citeste tabla de joc initiala
void read_grid(Grid *grid, FILE *input) {
    int i;
    for (i = 0; i < GRID; i++)
        fscanf(input, "%c %c %c\n",
        &grid->grid[i][0], &grid->grid[i][1], &grid->grid[i][2]);
}

// Efectueaza mutarea si schimba tura
void turn_grid(Grid *grid, char turn, int line, int col) {
    if (turn == 'X') {
        grid->grid[line][col] = 'X';
        turn = 'O';
        return;
    }
    grid->grid[line][col] = 'O';
    turn = 'X';
}

// Printeaza starea actuala a tablei de joc (in functie si de adancimea nodului)
void print_grid(Grid grid, int tabs, FILE *output) {
    int i, j;
    for (i = 0; i < GRID; i++) {
        for (j = 1; j <= tabs; j++) {
            fprintf(output, "\t");
        }
        fprintf(output, "%c %c %c\n",
        grid.grid[i][0], grid.grid[i][1], grid.grid[i][2]);
    }
}

#endif
