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


int tamanho_numero(int numero){ //sub-rotina que conta a quantidade de digitos de um numero
    int tamanho=0;
        while (numero!=0)
        {
            tamanho++;
            numero = numero / 10;
        }
    return tamanho;
}

void imprime_fila(){
    int j, i, contaDigitos=0, numero;

    for (j = 0; j < f->u; j++) contaDigitos+= tamanho_numero(f->fila[j]); //inicio da parte responsavel pela primeira linha

    printf(" ");
    for (i = 0; i < (f->u)*3+contaDigitos-1; i++) printf("-"); //fim da parte responsavel pela primeira linha
    
        printf("\n|");//inicio da parte responsavel pela segunda linha
        for(i = 0; i < f->u; i++){
            printf(" %d |", f->fila[i]);
        }
        printf("\n ");//fim da parte responsavel pela segunda linha

    for (i = 0; i <  (f->u)*3+contaDigitos-1; i++) printf("-"); // parte responsavel pela terceira linha
    printf("\n");

//inicio da parte responsavel pela quarta linha
    if (f->p == 0){
        contaDigitos = tamanho_numero(f->fila[f->p]);
        if (contaDigitos==1) printf("  p");
        else if (contaDigitos==2) printf("  p ");
        else printf("   p ");
        for ( i = 1; i < (f->u); i++)
        {
            printf("   ");
            if(i != f->u-1){
                numero = f->fila[i];
                contaDigitos= tamanho_numero(numero);
                for (j = 0; j < contaDigitos; j++) printf(" ");
            }
        }

        contaDigitos=tamanho_numero(f->fila[f->u-1]);
        if (contaDigitos <= 2) printf("u");
        else if (contaDigitos == 3) printf(" u");
        printf("\n");
        
        
    }
    else
    {
        printf("  ");
        for( i = 0; i < f->u; i++)
        {
            contaDigitos=tamanho_numero(f->fila[i]);

            if (i == f->u-1)
            {
                if (contaDigitos <=2) printf("u");
                else printf(" u");
                break;
            }

            for ( j = 0; j < contaDigitos; j++)
            {
                if(i != f->p) printf(" ");
                else
                {
                    if (contaDigitos <=2) printf("p ");
                    if( contaDigitos == 3) printf(" p ");
                    break;
                }
            }


            printf("   ");

        }
        printf("\n");
    }
    
    
}