#include "polinomio.h"
#include <stdlib.h>

Polinomio criaPolinomio(){
    Polinomio l = (Polinomio)malloc(sizeof(struct noPolinomio));
    if(l != NULL){
        struct termo* termo = malloc(sizeof(struct termo));
        termo->indice = 0;
        termo->coeficiente = 0;
        l->termo = *termo;
        l->prox = NULL;
    }
    return l;

}

int insere(Polinomio* l, struct termo* termo){
    if (l == NULL) return 0; //falha

    Polinomio novoNo = malloc(sizeof(struct noPolinomio));
    novoNo->termo = *termo;

    if ((*l)->prox == NULL || (*l)->termo.indice < termo->indice) {
        novoNo->prox = *l;
        *l = novoNo;
    } else {
        Polinomio aux = *l;
        while (aux->prox != NULL && aux->prox->termo.indice > termo->indice) {
            aux = aux->prox;
        }
        novoNo->prox = aux->prox;
        aux->prox = novoNo;
    }
    return 1;//sucesso
}

int insereIncrementa(Polinomio l, struct termo* termo){
    if (l == NULL) return 0; //falha

    Polinomio aux = l;
    while(aux != NULL && aux->termo.indice != termo->indice){
        aux = aux->prox;
    }
    if(aux == NULL) return 0; // nao existe

    aux->termo.coeficiente += termo->coeficiente;

    return 1;//sucesso
}

int insereSubstitui(Polinomio l, struct termo* termo){
    if (l == NULL) return 0; //falha

    Polinomio aux = l;
    while(aux != NULL && aux->termo.indice != termo->indice){
        aux = aux->prox;
    }
    if(aux == NULL) return 0; // nao existe

    aux->termo.coeficiente = termo->coeficiente;

    return 1;//sucesso
}

int eliminar(Polinomio l, int k) {
    if (l->termo.indice == k) {
        (*l) = *l->prox;
        return 1;
    }

    Polinomio aux = l;

    while(aux->prox != NULL && aux->prox->termo.indice != k){
        aux = aux->prox;
    }

    if (aux->prox->termo.indice != k) return 0;

    aux->prox = aux->prox->prox;

    return 1;
}