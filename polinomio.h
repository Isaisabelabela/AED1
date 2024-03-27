#ifndef UNTITLED4_POLINOMIO_H
#define UNTITLED4_POLINOMIO_H

struct termo{
    int indice;
    int coeficiente;
};

struct noPolinomio{
    struct termo termo;
    struct noPolinomio* prox;
};

typedef struct noPolinomio *Polinomio;

Polinomio criaPolinomio();
int insere(Polinomio* l, struct termo* termo);
int insereIncrementa(Polinomio l, struct termo* termo);
int insereSubstitui(Polinomio l, struct termo* termo);
int eliminar(Polinomio l, int indice);

#endif
