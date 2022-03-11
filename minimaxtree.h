// Header-ul pentru structura de data de tip arbore MinMax si functiile
// necesare

#ifndef _MINIMAXTREE_H__
#define _MINIMAXTREE_H__

#include "tictactoe.h"
#include "queue.h"

#define MAX_BUFFER 100

// Initializarea unui nod care are copii din arborele MinMax
MinMaxNode *init_min_max_node() {
    MinMaxNode *root = (MinMaxNode*)calloc(1, sizeof(MinMaxNode));
    root->nrChild = 0;
    root->value = 0;
    return root;
}

// Initializeaza copii pentru un nod din arborele MinMax
MinMaxNode *init_children(MinMaxNode *root, Queue *queue, int nrChild) {
    root->nrChild = nrChild;
    root->children = (MinMaxNode**)calloc(nrChild, sizeof(MinMaxNode*));
    int i;
    for (i = 0; i < nrChild; i++) {
        root->children[i] = init_min_max_node(); 
        push_queue(queue, root->children[i]);
    }
    return root;
}

// Atribuie nodului valoarea sau numarul de copii in functie de paranteza
void brackets(MinMaxNode *root, Queue *queue, int value, char bracket) {
    if (bracket == '[')
        root->value = value;
    else 
        root = init_children(root, queue, value);
}

// Stergerea arborelui MinMax
void remove_min_max_tree(MinMaxNode *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->nrChild; i++) {
            remove_min_max_tree(root->children[i]);
            free(root->children[i]);
        }
        free(root->children);
        root->children = NULL;
        root = NULL;
    }
}

// Afiseaza arborele MinMax
void print_min_max(MinMaxNode *root, int tabs, FILE *output) {
    int i;
    for (i = 1; i <= tabs; i++)
        fprintf(output, "\t");
    fprintf(output, "%d\n", root->value);
    for (i = 0; i < root->nrChild; i++)
        print_min_max(root->children[i], tabs + 1, output);
}

#endif
