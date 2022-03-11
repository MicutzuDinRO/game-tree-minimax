// Header-ul functiilor necesare rezolvarii task-ului 3 din tema

#ifndef _MINIMAX_H__
#define _MINIMAX_H__ 

#include "minimaxtree.h"

#include <limits.h>
#include <ctype.h>

// Pentru constructia eficienta a arborelui pun nodurile in coada si le atribui
// numarul de copii + adaugarea lor in coada sau valoarea necesara.
// Face si citirea din fisier in acelasi timp
void BFS(MinMaxNode *root, Queue *queue, FILE *input, char buff[]) {
    while (empty_queue(queue) == 0) {
        fscanf(input, "%s", buff);
        int nrChild = atoi(buff + 1);
        MinMaxNode *aux = get_front_queue(queue); 
        pop_queue(queue);
        brackets(aux, queue, nrChild, buff[0]);
    }
}

// Citeste inputul si construieste pe baza acestuia arborele MinMax
// cu ajutorul unei cozi
MinMaxNode* min_max_tree(FILE *input) {
    char buff[MAX_BUFFER];
    MinMaxNode *root = init_min_max_node(); 
    Queue *queue = init_queue();
    int buffer;
    fscanf(input, "%d\n", &buffer);
    push_queue(queue, root); 
    BFS(root, queue, input, buff);
    free(queue);
    return root;
}

// Aplica algoritmul MinMax pe arbore
int min_max(MinMaxNode *root, int height) {
    if (root->nrChild != 0) {
        int i;
        int max = INT_MIN, min = INT_MAX;
        int aux;
        for (i = 0; i < root->nrChild; i++) {
            aux = min_max(root->children[i], height + 1);
            if (aux > max)
                max = aux;
            if (aux < min)
                min = aux;
        }
        if (height % 2 == 1)
            root->value = min;
        else
            root->value = max;
    }
    return root->value;
}

#endif
