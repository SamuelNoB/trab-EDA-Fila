#define TAMANHO_FILA	5

typedef struct celula{
	int dado;
	struct celula *prox;
}celula;

void cria_fila();

int insere_elemento(int x);

int remove_elemento(int *valor);

int fila_cheia(celula* fila);

int fila_vazia();

int tamanho_fila();

void imprime_fila();
