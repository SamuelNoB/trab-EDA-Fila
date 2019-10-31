// circular com redimensionamento

typedef struct fila_circular{
	int* data;
	int tamanho;
	int capacidade;

	int p;
	int u;
}fila_circular;

void cria_fila();

int insere_elemento(int x);

int remove_elemento(int *valor);

int fila_cheia(fila_circular* fila);

int fila_vazia();

int tamanho_fila();

void imprime_fila();


/* fila lista circular
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
*/
