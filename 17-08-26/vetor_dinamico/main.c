/******************************************************************************
Declare, preencha e imprima um vetor dinâmico de 10 posições do tipo inteiro.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int main()
{
    int tam, *vetor;
    printf("Tamanho do vetor: ");
    scanf("%d", &tam);
    
    
    //Alocaçaõ dinâmica de memoria
    //criar o vetor
    vetor = malloc(tam*sizeof(int));
    
    printf("Digite os valores do vetor: \n");
    leitura(tam,vetor);
    printf("Imprimindo Vetores: \n");
    escrita(tam,vetor);
    

    return 0;
}