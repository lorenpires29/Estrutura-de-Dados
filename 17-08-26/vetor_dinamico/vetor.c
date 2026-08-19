#include<stdio.h>
#include "vetor.h"

void leitura(int tam, int *v){
    for(int i=0; i<tam; i++){
        printf("v[%d] = ", i+1);
        scanf("%d", &v[i]);
    }
}


void escrita(int tam, int *v){
    for(int i=0; i<tam; i++){
        printf("\n v[%d] = %d", i+1, v[i]);
        
    }
}

