#include "polinomio.h"

struct no {
    Polinomio poli;
    struct no* prox;
};

typedef struct no* Lista;

Lista criaLista();
int inserir(Lista* l, Polinomio p);
int get_elem_pos(Lista l, int pos, Polinomio* p);
int tamanho(Lista l);