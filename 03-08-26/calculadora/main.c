
#include <stdio.h>
#include "func.h"

int main()
{
    float a,b;
    printf("Digite dois valores inteiros: ");
    scanf("%f %f", &a, &b);
    
    int opcao,i; 
    
    
    while(opcao >= 5){
        printf("Selecione a operacao matematica:\n");
        printf("1- Soma\n");
        printf("2- Subtracao\n");
        printf("3- Multiplicacao\n");
        printf("4- Divisao\n");
        printf("Opcao: ");
        
        scanf("%d", &opcao);
        
        if(opcao == 1){
            printf("\n Resultado Soma: %d", soma(a,b));
        }
        else if(opcao == 2){
            printf("\n Resultado Subtração: %d", sub(a,b));
        }
        else if(opcao == 3){
            printf("\n Resultado Multiplicação: %d", mult(a,b));
        }
        else if(opcao == 4){
            printf("\n Resultado Divisão: %.2f", divisao(a,b));
        }
        else{
            printf("\n Essa opção não existe!!  Tente Novamente!!");
        }
    }
    
    return 0;
}
