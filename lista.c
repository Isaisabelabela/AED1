#include <stdlib.h>
#include "lista.h"

Lista criaLista() {
    return NULL;
}

int inserir(Lista* l, Polinomio p) {
    Lista novoNo = malloc(sizeof(struct no));
    if (novoNo == NULL) {
        return 0;
    }
    novoNo->poli = p;
    if (l == NULL) {
        *l = novoNo;
        return 1;
    } else {
        novoNo->prox = *l;
        *l = novoNo;
        return 1;
    }
}

int get_elem_pos(Lista l, int pos, Polinomio* p) {
    Lista aux = l;
    for (int i = 0; i < pos; ++i) {
        aux = aux->prox;
    }
    *p = aux->poli;
    return 1;
}

int tamanho(Lista l) {
    Lista aux = l;
    int i = 0;
    while (aux != NULL) {
        aux = aux->prox;
        i++;
    }
    return i;
}