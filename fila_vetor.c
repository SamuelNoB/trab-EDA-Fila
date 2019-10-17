#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"
#define N 5

typedef struct fila{
	int fila[N];
	int p,u;
}fila;

fila *f;

void cria_fila(){
    f = malloc(sizeof(fila));
	f->p=0;
	f->u=0;
}

int insere_elemento(int x){
	if(!fila_cheia(f)){
		f->fila[f->u] = x;
		f->u++;
		return 1;
	}
	return 0;
} 

int remove_elemento(int *valor){
    if (!fila_vazia(f)){
        *valor = f->fila[f->p];
        f->p++;
        return 1;
    }
    return 0;
}

int fila_vazia(){
    if (f->p == f->u)
    {
        f->u = 0;
        f->p = 0;
        return 1;
    }
    return 0;
}

int fila_cheia(){return f->u == N;}

int tamanho_fila(){ return f->u - f->p;}

void imprime_fila(){
    int i;
    if (!fila_vazia())
    {
        
        printf("|");
        for(i = f->p; i < f->u; i++){
            printf(" %d |", f->fila[i]);
        }
        printf("\n");
    }
    else printf("nao ha itens na sua fila :(\n");
    
}
