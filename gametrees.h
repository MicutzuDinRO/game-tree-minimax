// Header-ul functiilor necesare rezolvarii task-urilor 1 si 2 din tema

#ifndef _GAMETREES_H__
#define _GAMETREES_H__ 

#include "normaltree.h"

// Determina cand s-a terminat un meci si rezultatul acestuia
int is_over(Grid grid, char start) {
    int i, j, count = 0;
    if (grid.grid[0][0] == grid.grid[1][1]
    && grid.grid[0][0] == grid.grid[2][2] && grid.grid[0][0] != '-') {
        if (grid.grid[0][0] == start) {
            return 1;
        }
        else {
            return -1;
        }
    }
    if (grid.grid[0][2] == grid.grid[1][1]
    && grid.grid[0][2] == grid.grid[2][0] && grid.grid[0][2] != '-') {
        if (grid.grid[0][2] == start) {
            return 1;
        }
        else {
            return -1;
        }
    }

    for (i = 0; i < 3; i++) {
        if (grid.grid[i][0] == grid.grid[i][1]
        && grid.grid[i][0] == grid.grid[i][2] && grid.grid[i][0] != '-') {
            if (grid.grid[i][0] == start) {
                return 1;
            }
            else {
                return -1;
            }
        }
        if (grid.grid[0][i] == grid.grid[1][i]
        && grid.grid[0][i] == grid.grid[2][i] && grid.grid[0][i] != '-') {
            if (grid.grid[0][i] == start) {
                return 1;
            }
            else {
                return -1;
            }
        }
        
        for (j = 0; j < 3; j++)
            if (grid.grid[i][j] != '-') count++;
    }
    if (count != MAX_CHILD)
        return 2;
    return 0;
}

// Aplica SI/SAU pe arbore
int value_game(Node *root, char turn, char start) {
    int i;
    if (start == turn) {
        for (i = 0; i < MAX_CHILD && root->children[i] != NULL; i++)
            if (root->children[i]->value == 1)
                return 1;
        return -1;
    }
    for (i = 0; i < MAX_CHILD && root->children[i] != NULL; i++)
        if (root->children[i]->value != 1)
            return -1;
    return 1;
}

// Construieste arborele de joc
void build_game_tree(Node *root, char turn, char start, FILE *output) {
    int i, j, help;
    help = is_over(root->grid, start);
    if (help != 2) {
        root->value = help;
        return;
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            if (root->grid.grid[i][j] == '-') {
                Grid grid = root->grid;
                turn_grid(&grid, turn, i, j);
                insert_node_tree(&root, grid);
                int aux;
                for (aux = 0; root->children[aux] != NULL; aux++);
                if (turn == 'X')
                    build_game_tree(root->children[aux - 1],
                    'O', start, output);
                else if (turn == 'O') 
                    build_game_tree(root->children[aux - 1],
                    'X', start, output);
            }
        }
    root->value = value_game(root, turn, start);
}

#endif
