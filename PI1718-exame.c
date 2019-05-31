#include <stdio.h>
#include "default.h"
#include <ctype.h>
#include <stdlib.h>

// Auxiliares

LInt newLInt(int x, LInt t){
    LInt new = (LInt) malloc(sizeof(struct slist));

    if (new != NULL) {
        new->valor = x;
        new->prox = t;
    }
    return new;
}

ABin newABin(int x, ABin left, ABin right){
    ABin new = (ABin) malloc(sizeof(struct nodo));
    
    if (new != NULL) {
        new->valor = x;
        new->esq = NULL;
        new->dir = NULL;
    }
    return new;
}

void imprimePalavras(Palavras texto){
    for (int i = 0; texto != NULL; i++) {
        printf("Palavra %d: %s - tamanho %d\n", i, texto->palavra, texto->comp);
        texto = texto->prox;
    }
}

// Parte A

// 1

char *strstr(char s1[], char s2[]){
    if (s2[0] == '\0') {
        return s1;
    }
    int i, j, k;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[0]) {
           for (j = 0, k = i; s1[k] == s2[j] && s1[k] != '\0' && s2[j] != '\0'; j++, k++);

           if (s2[j] == '\0') {
                return (s1 + i);
           }
        }
    }
    return NULL;
}

// 2

void truncW(char t[], int n){
    int r, w;
    int len = n;
    for (r = 0, w = 0; t[r] != '\0'; r++) {
        if (!isspace(t[r])) {
            if (len > 0) {
                t[w] = t[r];
                w++;
                len--;
            } 
        } else {
            t[w] = t[r];
            w++;
            len = n;
        }
    }
    t[w] = 0;
}

// 3

int maiscentral(Posicao pos[], int N){
    int i, res = 0, dis;
    if (N == 0) {
        return 0;
    }
    int min = pos[0].x * pos[0].x + pos[0].y * pos[0].y;
    for (i = 0; i < N; i++) {
        dis = pos[i].x * pos[i].x + pos[i].y * pos[i].y;
        if (dis < min) {
            min = dis;
            res = i;
        }
    }
    return res;
}

// 4

LInt somasAcL(LInt head){
    if (head == NULL) {
        return NULL;
    }
    int Ac = head->valor;
    LInt start = newLInt(head->valor, NULL);
    LInt cur = start;
    head = head->prox;
    while (head != NULL) {
        LInt new = newLInt(head->valor + Ac, NULL);
        cur->prox = new;
        cur = cur->prox;
        head = head->prox;
        Ac = new->valor;
    }
    return start;
}

// 5

int addOrd(ABin *root, int x){
    ABin new = newABin(x, NULL, NULL);
    if (*root == NULL) {
        *root = new;
        return 0;
    }
    ABin prev, cur = *root;
    while (cur != NULL) {
        if (cur->valor == x) {
            return 1;
        } else if (cur->valor < x) {
            prev = cur;
            cur = cur->dir;
        } else {
            prev = cur;
            cur = cur->esq;
        }
    }
    if (prev->valor == x) {
        return 1;
    } else if (prev->valor < x) {
        prev->dir = new;
    } else {
        prev->esq = new;
    }
    return 0;
}

// Parte B

// 1

int daPalavra(char *s, int *e){
    int spaces = 0;
    int size = 0;
    int flag = 0;
    int i;
    for (i = 0; s[i] != 0 && !flag ; i++) {
        if (!isspace(s[i])) {
            flag++;
        } else {
            spaces++;
        }
    }
    *e = spaces;
    if (!flag) {
        return 0;
    } else {
        while (s[i] != '\0' && !isspace(s[i])) {
            i++;
            size++;
        }
        return size + 1;
    }
}

// 2
Palavras newPalavra(char *word, int comprimento, Palavras t){
    Palavras new = (Palavras) malloc(sizeof(struct celula));

    if (new != NULL) {
        new->palavra = word;
        new->comp = comprimento;
        new->prox = t;
    }
    return new;
}

Palavras words(char *texto){
    int size;
    int e;
    size = daPalavra(texto, &e);
    int i = e;
    Palavras start = newPalavra(texto + i, size, NULL);
    Palavras cur = start;
    i += e + size + 1;
    while (texto[i-1] != 0) {
        size = daPalavra(texto + i, &e);
        cur->prox = newPalavra(texto + i, size, NULL);
        cur = cur->prox;
        i += e + size + 1;
    }
    return start;
}



// main

int main(void){
    // Teste pergunta 1
    char str1[] = "  hey oh";
    int spaces;
    int x = daPalavra(str1, &spaces);
    printf("A primeira palavra tem %d letras e %d espacos antes\n", x, spaces);
    
    // Teste pergunta 2
    char str2[] = "Isto e uma string grande";
    Palavras teste = words(str2);
    imprimePalavras(teste);
    return 0;
}
