#include <stdio.h>
#include "default.h"

// Parte A

// 1

char *strcat(char s1[], char s2[]){
    int i, j;
    for (i = 0; s1[i] != '\0'; i++);
    for (j = 0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

// 2

int remRep(char x[]){
    if (x[0] == '\0') {
        return 0;
    }
    int r, dif = 1;
    for (r = 0; x[r+dif] != '\0'; r++) {
        if (x[r] == x[r+dif]) {
           r--;
           dif++;
        } else {
            x[r+1] = x[r+dif];
        }
    }
    x[r+1] = '\0';
    return r + 1;
}

// 3

int nivelV(ABin root, int n, int v[]){
    if (root = NULL) {
        return 0;
    }
    if (n == 1) {
        v[0] = root->valor;
        return 1;
    } else {
        int pos = nivelV(root->esq, n-1, v);
        return pos + nivelV(root->dir, n-1, v + pos);
    }
}

// 4

ABin newABin(int x, ABin left, ABin right){
    ABin new = (ABin) malloc(sizeof(struct nodo));

    if (new != NULL) {
        new->valor = x;
        new->esq = NULL;
        new->dir = NULL;
    }
    
    return new;
}

int addOrd(ABin *root, int x){
    if (*root == NULL) {
        *root = newABin(x, NULL, NULL);
        return 0;
    }
    ABin prev, cur = *root;
    while (cur != NULL) {
        if (x == cur->valor) {
            return 1;
        } else if (x < cur->valor) {
            prev = cur;
            cur = cur->esq;
        } else {
            prev = cur;
            cur = cur->dir;
        }
    }
    ABin new = newABin(x, NULL, NULL);
    if (x < cur->valor) {
        prev->esq = new;
    } else {
        prev->dir = new;
    }
    return 0;
}

// Parte B

typedef struct listaC {
    int coluna;
    float valor;
    struct listaC *prox;
} *Colunas;

typedef struct listaL {
    int linha;
    Colunas lcol;
    struct listaL *prox;
} *Mat;

// 1



int main(void){
    char str1[100] = "Hello ";
    char str2[100] = "World!";
    strcat(str1, str2);
    printf("%s", str1);
    return 0;
}
