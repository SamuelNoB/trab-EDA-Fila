#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"
#define N 5

typedef struct fila{
	int fila[N];
	int p,u;
}fila;

void cria_fila(fila *f){
	f->p=0;
	f->u=0;
}

int insere_elemento(fila *f, int x){
	if(!fila_cheia(f)){
		f->fila[f->u] = x;
		f->u++;
		return 1;
	}
	return 0;
} 

int remove_elemento(fila *f, int *valor){
    if (!fila_vazia(f)){
        *valor = f->fila[f->p++];
        return 1;
    }
    return 0;
}

int fila_vazia(fila *f){
    if (f->p == f->u)
    {
        f->u = 0;
        f->p = 0;
        return 1;
    }
    return 0;
}

int fila_cheia(fila *f){return f->u == N;}

int tamanho_fila(fila *f){ return f->u - f->p;}

void imprime_fila(fila *f){
    int i;
    printf("|");
    for(i = f->p; i < f->u; i++){
        printf(" %d |", f->fila[i]);
    }
    printf("\n");
}
