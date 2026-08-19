/******************************************************************************

vetor dinâmico

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main()
{
    int k,*v,n;
    printf("Quantos elementos quer guardar? ");
    scanf("%d",&n);
    v=malloc(n*sizeof(int));
    printf("Digite os valores do vetor ");
    leitura(n,v);
    printf("Mostrando os valores lidos no vetor ");
    imprimir(n,v);
    printf("\nQual o valor de k para multiplicar o vetor? ");
    scanf("%d",&k);
    multiplica(n, v, k);
    imprimir(n,v);
    free(v);
    imprimir(n,v);
    return 0;
}
