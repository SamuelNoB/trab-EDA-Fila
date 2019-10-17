#ifndef _fila_vetor_H
#define _fila_vetor_H

void cria_fila(fila *f);

int insere_elemento(fila *f, int x);

int remove_elemento(fila *f, int *valor);

int fila_cheia(fila *f);

int fila_vazia(fila *f);

int tamanho_fila(fila *f);

void imprime_fila(fila *f);

#endif