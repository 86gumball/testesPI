typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

typedef struct posicao {
    int x, y;
} Posicao;

typedef struct celula {
    char *palavra;
    int comp;
    struct celula *prox;
} *Palavras;
