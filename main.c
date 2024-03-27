#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polinomio.h"
#include "lista.h"

void imprime(Polinomio aux) {
    while (aux != NULL) {
        printf("%dx^%d", aux->termo.coeficiente, aux->termo.indice);
        aux = aux->prox;
        if(aux != NULL) printf(" + ");
    }
}

int main() {
    setvbuf (stdout, NULL, _IONBF, 0);

    int op = 0;
    Lista polinomios = criaLista();
    Polinomio pAtual;
    Polinomio pAux, pAux2, pAux3;
    int a = 0;
    int k = 0;

    while (op != 9) {
        printf("[1] Inicializar um termo\n");
        printf("[2] Inserir um novo termo ax^k no termo\n");
        printf("[3] Exibir o termo P(x)\n");
        printf("[4] Eliminar termo associado a k-esima potencia\n");
        printf("[5] Reinicializar termo\n");
        printf("[6] Salvar termo criado\n");
        printf("[7] Somar dois polinomios\n");
        printf("[8] Calcular o valor de P(x)\n");
        printf("[9] SAIR \n");
        printf("Digite a opcao: ");

        scanf("%d", &op);
        printf("\n");

        switch (op) {
            case 1:
                pAtual = criaPolinomio();
                puts("Um novo termo foi iniciado");
                puts("\n");
                break;
            case 2:
                puts("Digite os valores A e K do seu termo");
                scanf("%d", &a);
                scanf("%d", &k);

                struct termo *novoTermo = malloc(sizeof(struct termo));
                novoTermo->indice = k;
                novoTermo->coeficiente = a;

                Polinomio aux = pAtual;
                while (aux != NULL && aux->termo.indice != novoTermo->indice) {
                    aux = aux->prox;
                }

                if (aux != NULL && aux->termo.indice == novoTermo->indice) {
                    printf("Voce digitou dois valores diferentes para o mesmo k");
                    printf("Voce gostaria que fosse [1]incrementado ou [2]substituido");
                    int n;
                    scanf("%d", &n);
                    if (n == 1) {
                        insereIncrementa(pAtual, novoTermo);
                    }
                    if (n == 2) {
                        insereSubstitui(pAtual, novoTermo);
                    }
                }
                else{
                    insere(&pAtual, novoTermo);
                }
                break;
            case 3:
                imprime(pAtual);
                printf("\n");
                break;
            case 4:
                printf("Digite o valor de k: ");
                scanf("%d", &k);
                eliminar(pAtual, k);
                break;
            case 5:
                pAtual = criaPolinomio();
                printf("Polinomio reinicializado.\n");
                break;
            case 6:
                inserir(&polinomios, pAtual);
                printf("Polinomio salvo.\n");
                break;
            case 7:
                for (int i = 0; i < tamanho(polinomios); ++i) {
                    get_elem_pos(polinomios, i, &aux);
                    printf("#%d P(x) = ", i+1);
                    imprime(aux);
                    printf("\n");
                }
                printf("\nEscolha dois polinomios para somar.");
                scanf("%d", &k);
                scanf("%d", &a);
                get_elem_pos(polinomios, k-1, &pAux);
                get_elem_pos(polinomios, a-1, &pAux2);
                pAtual = criaPolinomio();

                while (pAux != NULL) {
                    if (pAux->termo.indice != 0)
                        insere(&pAtual, &pAux->termo);
                    pAux = pAux->prox;
                }
                while (pAux2 != NULL) {
                    pAux3 = pAtual;
                    while (pAux3 != NULL && pAux3->termo.indice != pAux2->termo.indice) pAux3 = pAux3->prox;
                    if (pAux3 != NULL) insereIncrementa(pAtual, &pAux2->termo);
                    else insere(&pAtual, &pAux2->termo);
                    pAux2 = pAux2->prox;
                }
                imprime(pAtual);
                printf("\n");
                break;
            case 8:
                for (int i = 0; i < tamanho(polinomios); ++i) {
                    get_elem_pos(polinomios, i, &aux);
                    printf("#%d P(x) = ", i+1);
                    imprime(aux);
                    printf("\n");
                }

                int x;
                printf("Digite o valor de X: ");
                scanf("%d", &x);
                printf("Digite quais polinomios você deseja calcular, digite FIM quando terminar.");
                while (1) {
                    char in[3];
                    scanf("%s", in);
                    if (strcmp(in, "FIM") == 0) break;
                    k = atoi(in);
                    get_elem_pos(polinomios, k-1, &aux);
                    int r = 0;
                    while (aux != NULL) {
                        r += aux->termo.coeficiente * pow(x, aux->termo.indice);
                        aux = aux->prox;
                    }

                    printf("O valor e %d\n", r);

                }

                break;
            case 9:
                break;
            default:
                printf("Escolha invalida\n");
                break;
        }

    }
}