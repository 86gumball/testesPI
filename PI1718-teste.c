#include <stdio.h>
#include <stdlib.h>
#include "default.h"

// Auxiliares

LInt newLInt(int x, LInt t){
    LInt new = (LInt) malloc(sizeof(struct slist));

    if (new != NULL) {
        new->valor = x;
        new->prox = t;
    }
    return new;
}

ABin newABin(int x, ABin esq, ABin dir){
    ABin new = (ABin) malloc(sizeof(struct nodo));
    if (new != NULL) {
        new->valor = x;
        new->esq = esq;
        new->dir = dir;
    }
    return new;
}

int biggest(int a, int b){
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int smallest(int a, int b){
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Parte A

// 1
int retiraNeg(int v[], int N){
    int wr = 0;
    int restantes = N;
    for (int rd = 0; rd < N; rd++) {
        if (v[rd] > 0) {
            v[wr] = v[rd];
            wr++;
        } else {
            restantes--;
        }
    }
    return restantes;
}

// 2

int diffConsecutivos(char s[]){
    int max = 0;
    int buffer = 1;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1]) {
            buffer++;
        } else {
            if (buffer > max) {
                max = buffer;
            }
            buffer = 1;
        }
    }
    return max;
}

// 3

int maximo(LInt head){
    int max = head->valor;
    while (head != NULL) {
        if (head->valor > max) {
            max = head->valor;
        }
    }
    return max;
}

// 4

int removeAll(LInt *head, int x){
    int rm = 0;
    while (*head != NULL) {
        if ((*head)->valor == x) {
            rm++;
            LInt tmp = *head;
            *head = (*head)->prox;
            free(tmp);
        } else {
            break;
        }
    }    
    if (*head == NULL) {
        return rm;
    }
    LInt prev = *head;
    LInt current = ((*head)->prox);
    while (current != NULL) {
        if (current->valor == x) {
            rm++;
            prev->prox = current->prox;
            free(current);
            current = prev->prox;
        } else {
            prev = current;
            current = current->prox;
        }
    }
    return rm;
}


// 5

LInt arrayToList(int v[], int N){
    if (N == 0) {
        return NULL;
    }
    LInt start = newLInt(v[0], NULL);
    LInt cur = start;
    int i;
    for (i = 0; i < N; i++) {
        LInt new = newLInt(v[i], NULL);
        cur->prox = new;
        cur = cur->prox;
    }
    return start;
}

// Parte B

// 1

int minheapOK(ABin root){
    if (root == NULL) {
        return 1;
    } else {
        if (root->esq == NULL && root->dir == NULL) {
            return 1;
        } else if (root->esq == NULL && root->dir != NULL) {
            if ((root->dir)->valor < root->valor) {
                return 0;
            } else {
                return (1 * minheapOK(root->dir));
            }
        } else if (root->esq != NULL && root->dir == NULL) {
            if ((root->esq)->valor < root->valor) {
                return 0;
            } else {
                return (1 * minheapOK(root->esq));
            }
        } else {
            if ((root->esq)->valor < root->valor || (root->dir)->valor < root->valor) {
                return 0;
            } else {
                return (1 * minheapOK(root->esq) * minheapOK(root->dir));
            }
        }
    }
}

// 2

int maxHeap(ABin root){
    int max = root->valor;
    if (root->esq == NULL && root->dir == NULL) {
        return max;
    } else if (root->esq == NULL) {
        return maxHeap(root->dir);
    } else if (root->dir == NULL) {
        return maxHeap(root->esq);
    } else {
        return biggest(maxHeap(root->esq), maxHeap(root->dir));
    }
}

// 3


// main (para testar funções)

int main(void){
    // minHeap da imagem
    ABin leaf1 = newABin(80, NULL, NULL);
    ABin leaf2 = newABin(43, NULL, NULL);
    ABin leaf3 = newABin(35, NULL, NULL);
    ABin leaf4 = newABin(23, NULL, NULL);
    ABin left  = newABin(35, leaf1, leaf2);
    ABin right = newABin(22, leaf3, leaf4);
    ABin first = newABin(20, left, right);

    printf("%d\n\n", minheapOK(first));
    printf("%d\n\n", maxHeap(first));
    return 0;
}
