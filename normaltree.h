// Header-ul corespunzator structura de date de tip arbore pentru X si 0 +
// functiile necesare

#ifndef _NORMALTREE_H__
#define _NORMALTREE_H__

#include "tictactoe.h"

#define MAX_CHILD 9

// Structura unui nod din arborele de joc
typedef struct Node {
    Grid grid;
    struct Node *children[MAX_CHILD];
    int value;
} Node;

// Initializarea unui nod din arborele de joc
Node *init_node_tree(Grid grid) {
    Node *root = (Node*)malloc(sizeof(Node));
    int i;
    root->grid = grid;
    for (i = 0; i < MAX_CHILD; i++)
        root->children[i] = NULL;
    root->value = 0;
    return root;
}

// Inserarea unui nod in arborele de joc
void insert_node_tree(Node **root, Grid grid) {
    if (*root == NULL) {
        *root = init_node_tree(grid);
        return;
    }
    int help = 0;
    while ((*root)->children[help])
        help++;
    insert_node_tree((&(*root)->children[help]), grid);
}

// Stergerea arborelui de joc
void remove_tree(Node *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < MAX_CHILD; i++)
            if (root->children[i]) {
                remove_tree(root->children[i]);
                free(root->children[i]);
            }
        root = NULL;
    }
}

// Afiseaza arborele de joc
void print_game(Node *root, int tabs, FILE *output) {
    if (root == NULL)
        return;
    print_grid(root->grid, tabs, output);
    fprintf(output, "\n");
    int i;
    for (i = 0; i < MAX_CHILD; i++)
        if (root->children[i] != NULL)
            print_game(root->children[i], tabs + 1, output);
}

// Afiseaza arborele SI/SAU
void print_and_or(Node *root, int tabs, FILE *output) {
    int i;
    for (i = 1; i <= tabs; i++)
        fprintf(output, "\t");
    if (root->value > 0) 
        fprintf(output, "T\n");
    else
        fprintf(output, "F\n");
    for (i = 0; i < MAX_CHILD; i++)
        if (root->children[i] != NULL)
            print_and_or(root->children[i], tabs + 1, output);
}

#endif
