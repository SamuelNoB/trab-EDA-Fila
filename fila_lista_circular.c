#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_circular.h"

typedef struct celula{
	int dado;
	celula *prox;
}celula;

celula *fila;

void cria_fila(){
	fila = malloc(sizeof(celula));
	fila->prox = fila;
}

int insere_elemento(int x){
	celula *novo;
	novo = malloc(sizeof(celula));
	if(fila_cheia(novo)) return 0;
	novo->prox = fila->prox;
	fila->prox = novo;
	fila->dado = x;
	fila = novo;
	return 1;
}

int remove_elemento(int *valor){
	if (fila_vazia) return 0;	

	celula *lixo = fila ->prox;
	*valor = lixo->dado;
	fila->prox = lixo->prox;
	free(lixo);
	return 1;
}

int fila_cheia(celula *cel){ // se estiver cheia retornara 1, caso contrario retornara 0
	return cel==NULL ? 1:0;
}

int fila_vazia(){ // se estiver vazia retornara 1, caso contrario retornara 0
	return fila->prox==fila ? 1:0;
}

int tamanho_fila(){
	if (fila->prox == NULL) return 0;

	int i=0;
	celula *contagem=fila->prox;
	while (contagem->prox!= fila)
	{
		i++;
		contagem->prox = contagem->prox;
	}
	return i;
	
}

void imprime_fila(){
	celula *imprimir = fila->prox;
	int contaDigitos=0,numero,i, qtdNumeros;

	while (imprimir->prox!= fila)
	{
		numero = imprimir->dado;
		while (numero != 0)
		{
			contaDigitos++;
			numero = numero/10;
		}
		imprimir->prox = imprimir->prox;
	}

	imprimir = fila->prox;
	qtdNumeros = tamanho_fila();

	printf(" ");
	for (i = 0; i < (qtdNumeros*3+contaDigitos); i++) printf("-");

	printf("\n|");
	while (imprimir->prox!= fila)
	{
		printf(" %d |", imprimir->dado);
		imprimir->prox = imprimir->prox;
	}
	printf("\n ");

	for (i = 0; i < (qtdNumeros*3+contaDigitos); i++) printf("-");
	printf("\n");
}
