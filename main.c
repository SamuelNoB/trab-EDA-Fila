#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

//main para testes, posteriormente alterar a interface
int main(){
    int valor;
    int verificacao;
    //*valor = 0;
    
    cria_fila();

    insere_elemento(1);
    insere_elemento(2);
    insere_elemento(3);
    insere_elemento(4);
    insere_elemento(5);

    verificacao = remove_elemento(&valor);
    printf("%d\n", valor);
    //remove_elemento(&valor);
    printf("%d\n", valor);
    //remove_elemento(&valor);
    printf("%d\n", valor);
    //remove_elemento(&valor);
    printf("%d\n", valor);
    //remove_elemento(&valor);
    printf("%d\n", valor);

    imprime_fila();



    return 0;
}
