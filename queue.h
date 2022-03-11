// Header-ul corespunzator structurii de date coada

#ifndef _QUEUE_H__
#define _QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

// Structura unui nod MinMax
typedef struct MinMaxNode {
    struct MinMaxNode **children;
    int nrChild;
    int value;
} MinMaxNode;

// Structura unui nod de coada
typedef struct QueueNode {
    MinMaxNode *value;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    int size;
    QueueNode *front, *back;
} Queue;

// Initializeaza coada
Queue *init_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->back = NULL;
    queue->size = 0;
    return queue;
}

// Verifica daca coada este goala
int empty_queue(Queue *queue) {
    if (queue && queue->front != NULL && queue->back != NULL) 
        return 0;
    return 1;
}

// Pune elemente in coada
void push_queue(Queue *queue, MinMaxNode *value) {
    QueueNode *aux = (QueueNode*)malloc(sizeof(QueueNode));
    aux->value = value;
    aux->next = NULL;
    if (empty_queue(queue))
    {
        queue->front = queue->back = aux;
        queue->size = 1;
        return;
    }
    queue->back->next = aux;
    queue->back = aux;
    queue->size++;
}

// Elimina primul element din coada
int pop_queue(Queue *queue) {
    QueueNode *aux = queue->front;
    if (queue->size == 1)
    {   
        queue->front = queue->back = NULL;
        free(aux);
        queue->size = 0;
        return 1;
    }
    if (aux)
    {
        queue->front = aux->next;        
        free(aux);
        queue->size--;
        return 1;
    }
    return 0;
}

// Afiseaza primul element din coada
MinMaxNode *get_front_queue(Queue *queue) {
    if (queue) return queue->front->value;
    return 0;
}

#endif
