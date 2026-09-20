/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   arquivo.c - Implementa a persistência salvando e carregando dados
*/
#include <stdio.h>
#include <string.h>
#include "arquivo.h"

#define NOME_ARQUIVO "postagens.txt"

void salvar_em_arquivo(Postagem *posts, int total) {
    FILE *f = fopen(NOME_ARQUIVO, "w");
    if (f == NULL) {
        return;
    }

    fprintf(f, "TOTAL:%d\n", total);
    for (int i = 0; i < total; i++) {
        fprintf(f, "---POST---\n");
        fprintf(f, "%d\n", posts[i].id);
        fprintf(f, "%s\n", posts[i].titulo);
        fprintf(f, "%s\n", posts[i].autor);
        fprintf(f, "%d\n", posts[i].matricula);
        fprintf(f, "%s\n", posts[i].palavras_chave[0]);
        fprintf(f, "%s\n", posts[i].palavras_chave[1]);
        fprintf(f, "%s\n", posts[i].palavras_chave[2]);
        fprintf(f, "%ld\n", (long)posts[i].data_publicacao);
        fprintf(f, "%d\n", posts[i].tipo_rede);
        fprintf(f, "%s\n", posts[i].observacao);
    }
    fclose(f);
}

int carregar_do_arquivo(Postagem *posts) {
    FILE *f = fopen(NOME_ARQUIVO, "r");
    if (f == NULL) {
        return 0; // Arquivo ainda não existe na primeira execução
    }

    int total = 0;
    char buffer[256];

    if (fscanf(f, "TOTAL:%d\n", &total) != 1) {
        fclose(f);
        return 0;
    }

    for (int i = 0; i < total; i++) {
        fgets(buffer, sizeof(buffer), f); // Lê o separador "---POST---"
        
        fscanf(f, "%d\n", &posts[i].id);

        fgets(posts[i].titulo, sizeof(posts[i].titulo), f);
        posts[i].titulo[strcspn(posts[i].titulo, "\r\n")] = 0;

        fgets(posts[i].autor, sizeof(posts[i].autor), f);
        posts[i].autor[strcspn(posts[i].autor, "\r\n")] = 0;

        fscanf(f, "%d\n", &posts[i].matricula);

        fgets(posts[i].palavras_chave[0], sizeof(posts[i].palavras_chave[0]), f);
        posts[i].palavras_chave[0][strcspn(posts[i].palavras_chave[0], "\r\n")] = 0;

        fgets(posts[i].palavras_chave[1], sizeof(posts[i].palavras_chave[1]), f);
        posts[i].palavras_chave[1][strcspn(posts[i].palavras_chave[1], "\r\n")] = 0;

        fgets(posts[i].palavras_chave[2], sizeof(posts[i].palavras_chave[2]), f);
        posts[i].palavras_chave[2][strcspn(posts[i].palavras_chave[2], "\r\n")] = 0;

        long temp_time;
        fscanf(f, "%ld\n", &temp_time);
        posts[i].data_publicacao = (time_t)temp_time;

        fscanf(f, "%d\n", &posts[i].tipo_rede);

        fgets(posts[i].observacao, sizeof(posts[i].observacao), f);
        posts[i].observacao[strcspn(posts[i].observacao, "\r\n")] = 0;
    }
    fclose(f);
    return total;
}