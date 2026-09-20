/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   busca.c - Implementa as buscas por matrícula, rede e datas
*/
#include <stdio.h>
#include "busca.h"

void buscar_por_matricula(Postagem *posts, int total, int matricula) {
    int encontrados = 0;
    printf("\n--- Resultados para a Matrícula %d ---\n", matricula);
    for (int i = 0; i < total; i++) {
        if (posts[i].matricula == matricula) {
            exibir_postagem(posts[i]);
            encontrados++;
        }
    }
    if (!encontrados) printf("Nenhuma postagem encontrada para esta matrícula.\n");
}

void buscar_por_tipo_rede(Postagem *posts, int total, int tipo) {
    int encontrados = 0;
    printf("\n--- Títulos das Postagens na Rede %d ---\n", tipo);
    for (int i = 0; i < total; i++) {
        if (posts[i].tipo_rede == tipo) {
            printf("- %s\n", posts[i].titulo);
            encontrados++;
        }
    }
    if (!encontrados) printf("Nenhuma postagem encontrada para esta rede social.\n");
}

void buscar_por_intervalo_datas(Postagem *posts, int total, time_t inicio, time_t fim) {
    int encontrados = 0;
    printf("\n--- Postagens no Intervalo de Datas ---\n");
    for (int i = 0; i < total; i++) {
        // Comparação direta de segundos (time_t) - rápida e sem lag
        if (posts[i].data_publicacao >= inicio && posts[i].data_publicacao <= fim) {
            exibir_postagem(posts[i]);
            encontrados++;
        }
    }
    if (!encontrados) printf("Nenhuma postagem encontrada neste intervalo de datas.\n");
}