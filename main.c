#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_circular.h"

int menu()
{
	printf("1. Inserir n elementos na fila.\n");
	printf("2. Remover n elementos na fila.\n");
	printf("3. Imprimir a fila.\n");
	printf("4. Reiniciar a fila.\n");
	printf("5. Sair.\n");

	int opcao = 0;
	for(;;)
	{
		scanf("%d", &opcao);
		if(opcao < 1 || opcao > 5)
		{
			printf("Opcao invalida, selecione novamente:\n");
		}
		else
		{
			return opcao;
		}
	}
}

//main para testes, posteriormente alterar a interface
int main()
{
	int verificacao = 0;

	cria_fila();

	///////////////////////////////////

	int sair = 0;

	do
	{
		int opcao = menu();

		// inserir elemento
		if(opcao == 1)
		{
			int qtdsElements = -1;
			printf("Digite quantos elementos voce deseja inserir: \n");
			scanf("%d", &qtdsElements);

			int i;
			for (i = 0; i < qtdsElements; i++)
			{
				int valor = -1;

				do
				{
					scanf("%i", &valor);
				} while (valor < 0 || valor > 999);

				if (insere_elemento(valor) == 0)
					verificacao++;
			}

			if (verificacao > 0) printf("%d elementos tentaram ser inseridos na fila, mas %d nao couberam\n", qtdsElements, verificacao);
		}
		else if(opcao == 2)	// remover elemento
		{
			printf("Digite quantos elementos voce deseja remover: \n");

			int qtdRemover = 0;
			scanf("%d", &qtdRemover);
			printf("\n");

			int i;
			for (i = 0; i < qtdRemover; i++)
			{
				int valor = -1;

				if (remove_elemento(&valor) == 0)
				{
					printf("Nao e possivel mais remover pois a fila ficou vazia.\n");
					break;
				}
				else
				{
					printf("Elemento removido: %d\n", valor);
				}
			}
			printf("\n");
		}
		else if(opcao == 3) // imprimir a fila
		{
			if(!fila_vazia()) imprime_fila();
			else printf("\nsua fila esta vazia. adicione elementos antes de tentar imprimi-la.\n\n");	
		}
		else if(opcao == 4) // reiniciar a fila
		{
			if (fila_vazia() == 0)
			{
				int i;
				int lixo = -1;

				int qtd = tamanho_fila();

				for (i = 0; i < qtd; i++)
				{
					remove_elemento(&lixo);
				}

				cria_fila();
				
				printf("\nFila reiniciada.\n");
			}
		}
		else // sair
		{
			sair = 1;
		}
	} while (sair == 0);

	return 0;
}
