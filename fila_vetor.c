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
    int j, i, contaDigitos=0, numero;

    for (j = 0; j < N; j++)
    {
        numero = f->fila[j];
        while (numero!=0)
        {
            contaDigitos++;
            numero= numero / 10;
        }
    }

    printf(" ");
    for (i = 0; i < f->u*3+contaDigitos; i++) printf("-");
    
        printf("\n|");
        for(i = f->p; i < f->u; i++){
            printf(" %d |", f->fila[i]);
        }
        printf("\n ");

    for (i = 0; i <  f->u*3+contaDigitos; i++) printf("-");
    printf("\n");
    
}