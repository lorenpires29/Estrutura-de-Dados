#include <stdio.h>
#include "func.h"

void leitura(int tam, int *vet)
{
   for(int i=0;i<tam;i++)
   {
       printf("v[%d] ",i+1);
       scanf("%d",&vet[i]);
   }
}
void imprimir(int tam, int *vet){
    for(int i=0;i<tam;i++)
   {
       printf("\nv[%d] = %d",i+1,vet[i]);
   }
}
void multiplica(int tam, int *vet,int k){
    for(int i=0;i<tam;i++){
        vet[i]=vet[i]*k;
    }
}