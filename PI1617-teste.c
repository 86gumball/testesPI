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

// 2
void transposta(int N, float m[N][N]){
    int i, j;
    float n[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            n[i][j] = m[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = n[j][i];
        }
    }
}

// 3
LInt cloneL(LInt head){
    if (head == NULL) {
        return NULL;    
    }
    LInt start = newLInt(head->valor, NULL);
    LInt current = start;
    while (head != NULL) {
        LInt new = newLInt(head->valor, NULL);
        current->prox = new;
        current = current->prox;
        head = head->prox;
    }
    return start;
}

void removeMaiorA(ABin *root){
    if (*root == NULL) {
        return;
    }
    if ((*root)->dir == NULL) {
        :q
    }
}

int main(void){
    
    return 0;
}
