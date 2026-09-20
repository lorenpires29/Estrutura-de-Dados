/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   ordenacao.c - Implementa os métodos de ordenação básica e sofisticada
*/
#include <string.h>
#include "ordenacao.h"

// Ordenação por Título (Ordem Crescente) - Inserção (Básico)
void ordenar_por_titulo_crescente(Postagem *posts, int total) {
    for (int i = 1; i < total; i++) {
        Postagem chave = posts[i];
        int j = i - 1;
        while (j >= 0 && strcmp(posts[j].titulo, chave.titulo) > 0) {
            posts[j + 1] = posts[j];
            j = j - 1;
        }
        posts[j + 1] = chave;
    }
}

// Ordenação por Autor (Ordem Decrescente) - Seleção (Básico)
void ordenar_por_autor_decrescente(Postagem *posts, int total) {
    for (int i = 0; i < total - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < total; j++) {
            if (strcmp(posts[j].autor, posts[max_idx].autor) > 0) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            Postagem temp = posts[i];
            posts[i] = posts[max_idx];
            posts[max_idx] = temp;
        }
    }
}

// Critério para QuickSort: Rede Crescente, depois Data Crescente
int comparar_rede_data(Postagem a, Postagem b) {
    if (a.tipo_rede != b.tipo_rede) {
        return a.tipo_rede - b.tipo_rede;
    }
    if (a.data_publicacao < b.data_publicacao) return -1;
    if (a.data_publicacao > b.data_publicacao) return 1;
    return 0;
}

// QuickSort (Sofisticado)
void ordenar_por_rede_e_data(Postagem *posts, int baixo, int alto) {
    if (baixo < alto) {
        Postagem pivo = posts[alto];
        int i = (baixo - 1);

        for (int j = baixo; j <= alto - 1; j++) {
            if (comparar_rede_data(posts[j], pivo) <= 0) {
                i++;
                Postagem temp = posts[i];
                posts[i] = posts[j];
                posts[j] = temp;
            }
        }
        Postagem temp = posts[i + 1];
        posts[i + 1] = posts[alto];
        posts[alto] = temp;
        
        int pi = i + 1;

        ordenar_por_rede_e_data(posts, baixo, pi - 1);
        ordenar_por_rede_e_data(posts, pi + 1, alto);
    }
}