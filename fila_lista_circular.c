#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_circular.h"
#define N 5

typedef struct fila{
	int fila[N];
	int p,u;
}fila;


void cria_fila(fila *f){};

int insere_elemento(fila *f, int x){};

int remove_elemento(fila *f, int *valor){};

int fila_cheia(fila *f){};

int fila_vazia(fila *f){};

int tamanho_fila(fila *f){};

void imprime_fila(fila *f){};
