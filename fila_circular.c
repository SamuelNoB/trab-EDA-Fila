// fila circular com redimensionamento
#include <stdio.h>
#include <stdlib.h>

#define N 5

fila_circular* fila;
int qtdsElements;

void cria_fila()
{
	fila = (fila_circular *)malloc(sizeof(fila_circular));
	fila->data = new int[N];
	fila->tamanho = 0;
	fila->capacidade = N;

	// setar todos os valores como 0.
	int i;
	for(i = 0; i < fila->capacidade; i++)
	{
		fila->data[i] = 0;
	}

	fila->p = 0;
	fila->u = 0;

	qtdsElements = 0;
}

int fila_cheia(fila_circular* fila)
{
	return fila->tamanho < fila->capacidade - 1;
}

int fila_vazia()
{
	return (fila->tamanho == 0) ? 1 : 0;
}

int tamanho_fila()
{
	return fila->capacidade;
}

int insere_elemento(int valor)
{
	if (fila->tamanho < fila->capacidade - 1)
	{
		fila->data[fila->u] = valor;
		fila->tamanho++;
		qtdsElements++;
		
		fila->u = (fila->u + 1) % fila->capacidade;
		
		return 0;
	}
	else
	{
		int* tempData = (int*)malloc((fila->capacidade * 2) * sizeof(int));

		// setar todos os valores como 0.
		int i;
		for (i = 0; i < fila->capacidade * 2; i++)
		{
			tempData[i] = 0;
		}

		if ((fila->capacidade - fila->p) > fila->u) // primeiro caso
		{
			int ultimo;
			int pos;

			// terceiro caso
			if ((fila->capacidade - fila->p) == fila->u + 1 && fila->p < fila->u + 1)
			{
				ultimo = fila->p;
				pos = fila->p;

				fila->p = ultimo;
			}
			else
			{
				ultimo = fila->u + 1;
				pos = fila->p;

				fila->p = ultimo;
			}

			int j;
			for (j = 0; j < fila->capacidade - 1; j++)
			{
				tempData[ultimo] = fila->data[pos];
				pos = (pos + 1) % fila->capacidade;
				ultimo = (ultimo + 1) % (fila->capacidade * 2);
			}

			// adiciona o novo valor na fila.
			tempData[ultimo] = valor;
			fila->u = (ultimo + 1) % (fila->capacidade * 2);
		}
		else if ((fila->capacidade - fila->p) <= fila->u) // segundo caso
		{
			int ultimo = (fila->capacidade * 2) - (fila->capacidade - fila->p);
			int pos = fila->p;

			fila->p = ultimo;

			int j;
			for (j = 0; j < fila->capacidade - 1; j++)
			{
				tempData[ultimo] = fila->data[pos];
				pos = (pos + 1) % fila->capacidade;
				ultimo = (ultimo + 1) % (fila->capacidade * 2);
			}

			// adiciona o novo valor na fila.
			tempData[ultimo] = valor;
			fila->u = (ultimo + 1) % (fila->capacidade * 2);
		}
		//else if ((q->_capacity - q->head) == q->tail && q->head < q->tail) // terceiro caso
		//{
		//  int b = 3;
		//}
		else
		{
			printf("Caso invalido!\n");
			return 1;
		}

		fila->capacidade *= 2;
		delete[] fila->data;
		fila->data = tempData;
		tempData = NULL;

		fila->tamanho++;
		qtdsElements++;

		return 0;
	}
}

int remove_elemento(int *valor)
{
	if (fila_vazia() == 1)
	{
		// fila nao tem mais valor
		valor = NULL;
		return 0;
	}
	else
	{
		*valor = fila->data[fila->p];
		fila->tamanho--;
		qtdsElements--;

		fila->data[fila->p] = 0;
		fila->p = (fila->p + 1) % fila->capacidade;
	}

	return 1;
}

int tamanho_numero(int numero)
{ 
	//sub-rotina que conta a quantidade de digitos de um numero
	int tamanho = 0;

	if(numero == 0)
	{
		return 1;
	}
	else
	{
		if (numero < 0)
		{
			tamanho++;
		}

		while (numero != 0)
		{
			tamanho++;
			numero = numero / 10;
		}
	}

	return tamanho;
}

void imprime_fila()
{
	int j, i, contaDigitos = 0, numero;

	int tmpValor = 0;
	int p = fila->p;

	//inicio da parte responsavel pela primeira linha
	for (j = 0; j < fila->capacidade; j++)
	{
		tmpValor = fila->data[p];
		p = (p + 1) % fila->capacidade;

		contaDigitos += tamanho_numero(tmpValor);
	}

	printf(" ");

	//fim da parte responsavel pela primeira linha
	for (i = 0; i < (fila->capacidade) * 3 + contaDigitos - 1; i++) 
	{
		printf("-"); 
	}

	printf("\n|");//inicio da parte responsavel pela segunda linha
	for (i = 0; i < fila->capacidade; i++)
	{
		tmpValor = fila->data[i];
		printf(" %d |", tmpValor);
	}

	printf("\n ");//fim da parte responsavel pela segunda linha

	// parte responsavel pela terceira linha
	for (i = 0; i < (fila->capacidade) * 3 + contaDigitos - 1; i++) 
	{
		printf("-");
	}

	printf("\n");

	if(fila->p > fila->u)
	{
		int i;
		int k;

		for(i = 0; i < fila->u; i++)
		{
			contaDigitos = tamanho_numero(fila->data[i]);

			for (k = 0; k < contaDigitos + 3; k++)
				printf(" ");
		}

		contaDigitos = tamanho_numero(fila->data[fila->u]);
		if (contaDigitos == 1) printf("  u");
		else if (contaDigitos == 2) printf("  u ");
		else printf("   u ");

		int dif = (fila->p - fila->u) - 1;
		if (dif == 0) printf(" ");

		for (i = 0; i < dif; i++)
		{
			contaDigitos = tamanho_numero(fila->data[i]);
		
			for (k = 0; k < contaDigitos + 3; k++)
				printf(" ");
		}
		
		contaDigitos = tamanho_numero(fila->data[fila->p]);
		if (contaDigitos == 1) printf("  p");
		else if (contaDigitos == 2) printf("  p ");
		else printf("   p ");
	}
	else
	{
		int i;
		int k;

		for (i = 0; i < fila->p; i++)
		{
			contaDigitos = tamanho_numero(fila->data[i]);

			for (k = 0; k < contaDigitos + 3; k++)
				printf(" ");
		}

		contaDigitos = tamanho_numero(fila->data[fila->p]);
		if (contaDigitos == 1) printf("  p");
		else if (contaDigitos == 2) printf("  p ");
		else printf("   p ");

		int dif = (fila->u - fila->p) - 1;
		if (dif == 0) printf(" ");

		for (i = 0; i < dif; i++)
		{
			contaDigitos = tamanho_numero(fila->data[i]);

			for (k = 0; k < contaDigitos + 3; k++)
				printf(" ");
		}

		contaDigitos = tamanho_numero(fila->data[fila->u]);
		if (contaDigitos == 1) printf("  u");
		else if (contaDigitos == 2) printf("  u ");
		else printf("   u ");
	}

	printf("\n");
}

/* fila lista circular
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

	//celula *imprimir = fila;
	//int tamanho = 0;
	//
	//do
	//{
	//	imprimir = imprimir->prox;
	//	tamanho++;
	//
	//} while (imprimir->prox != fila);
	//
	//if (tamanho >= TAMANHO_FILA)
	//	return 1;
	//
	//return 0;

	return (cel == NULL) ? 1 : 0;
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
*/
