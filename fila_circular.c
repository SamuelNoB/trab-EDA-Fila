#include <stdio.h>
#include <stdlib.h>

celula *fila;
int qtdsElements = 0;

void cria_fila()
{
	fila = (celula *)malloc(sizeof(celula));
	fila->prox = fila;
}

int insere_elemento(int x)
{
	if (fila_cheia(fila))
		return 0;

	celula* novo;
	novo = (celula*)malloc(sizeof(celula));

	novo->prox = fila->prox;
	fila->prox = novo;
	fila->dado = x;
	fila = novo;

	qtdsElements += 1;

	return 1;
}

int remove_elemento(int *valor)
{
	if (fila_vazia())
		return 0;

	celula *lixo = fila->prox;

	*valor = lixo->dado;

	fila->prox = lixo->prox;

	qtdsElements -= 1;

	free(lixo);
	return 1;
}

int fila_cheia(celula *cel)
{
	// se estiver cheia retornara 1, caso contrario retornara 0

	celula *imprimir = fila;
	int tamanho = 0;

	do
	{
		imprimir = imprimir->prox;
		tamanho++;

	} while (imprimir->prox != fila);

	if (tamanho >= TAMANHO_FILA)
		return 1;

	return 0;
}

int fila_vazia(){ // se estiver vazia retornara 1, caso contrario retornara 0
	return fila->prox == fila ? 1 : 0;
}

int tamanho_fila()
{
	if (fila->prox == NULL)
		return 0;

	int i = 0;
	celula *contagem = fila;

	while (contagem->prox != fila)
	{
		i++;
		contagem = contagem->prox;
	}

	return i;

}

void imprime_fila()
{
	if (fila_vazia())
	{
		printf("Fila esta vazia.\n");
		return;
	}

	celula *imprimir = fila;
	int contaDigitos = 0, numero, i, qtdNumeros;

	do
	{
		imprimir = imprimir->prox;
		numero = imprimir->dado;
		while (numero != 0)
		{
			contaDigitos++;
			numero = numero / 10;
		}

	} while (imprimir->prox != fila);

	imprimir = fila;
	qtdNumeros = tamanho_fila();

	printf(" ");
	for (i = 0; i < ((qtdNumeros)* 3 + contaDigitos - 1); i++) printf("-");

	printf("\n|");
	do
	{
		imprimir = imprimir->prox;
		printf(" %d |", imprimir->dado);

	} while (imprimir->prox != fila);
	printf("\n ");

	for (i = 0; i < ((qtdNumeros)* 3 + contaDigitos - 1); i++) printf("-");
	printf("\n");

	imprimir = fila;
	do
	{
		imprimir = imprimir->prox;
		if (imprimir->dado == fila->prox->dado)
		{

			numero = imprimir->dado;
			contaDigitos = 0;

			while (numero != 0)
			{
				contaDigitos++;
				numero = numero / 10;
			}

			if (contaDigitos <= 2) printf("  p");
			else printf("   p");
		}
		else
		{
			contaDigitos = 0;
			numero = imprimir->dado;
			while (numero != 0)
			{
				contaDigitos++;
				numero = numero / 10;
			}
			printf("   ");
			for (i = 0; i < contaDigitos; i++){
				if (imprimir->prox != fila) printf(" ");
				else
				{
					if (contaDigitos <= 2) printf(" ");
					if (contaDigitos == 3) printf("  ");
					break;
				}

			}

		}
		if (imprimir->prox == fila) printf("u\n");

	} while (imprimir->prox != fila);


}
