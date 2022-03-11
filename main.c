// Micu Alexandru - 311CCb
// Game Tree

#include "gametrees.h"
#include "minimax.h"

// Rezolva prima cerinta
void task1(FILE *input, FILE *output) {
    char AI;
    Grid grid = init_grid();
    fscanf(input, "%c\n", &AI);
    read_grid(&grid, input);
    Node *root = init_node_tree(grid);
    build_game_tree(root, AI, AI, output);
    print_game(root, 0, output);
    remove_tree(root);
    free(root);
}

// Rezolva a doua cerinta
void task2(FILE *input, FILE *output) {
    char AI;
    Grid grid = init_grid();
    fscanf(input, "%c\n", &AI);
    read_grid(&grid, input);
    Node *root = init_node_tree(grid);
    build_game_tree(root, AI, AI, output);
    print_and_or(root, 0, output);
    remove_tree(root);
    free(root);
}

// Rezolva a treia cerinta
void task3(FILE *input, FILE *output) {
    MinMaxNode *root = min_max_tree(input);
    root->value = min_max(root, 0);
    print_min_max(root, 0, output);
    remove_min_max_tree(root);
    free(root);
}

// Primeste cerinta, fisierele si returneaza in fisiere informatiile necesare
// pentru rezolvarea cerintei respective
int main(int argc, char *argv[]) {
	FILE *input, *output;
    input = fopen(argv[2], "r");
    output = fopen(argv[3], "w");
    if (strcmp(argv[1], "-c1") == 0) {
        task1(input, output);
    }
    else if (strcmp(argv[1], "-c2") == 0) {
        task2(input, output);
    }
    else {
        task3(input, output);
    }
	fclose(input);
    fclose(output);
	return 0;
}
