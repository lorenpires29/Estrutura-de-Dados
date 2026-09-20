/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   postagem.c - Implementa o cadastro e exibição das postagens
*/
#include <stdio.h>
#include <string.h>
#include "postagem.h"
#include "arquivo.h"

void cadastrar_postagem(Postagem *posts, int *total) {
    if (*total >= MAX_POSTS) {
        printf("\nLimite máximo de postagens atingido!\n");
        return;
    }

    Postagem p;
    p.id = *total + 1;

    printf("\n--- Cadastro de Postagem ---\n");
    printf("Título da postagem (max 100 chars): ");
    scanf(" %[^\n]", p.titulo);

    printf("Nome do autor (max 40 chars): ");
    scanf(" %[^\n]", p.autor);

    printf("Matrícula do autor (inteiro): ");
    scanf("%d", &p.matricula);

    for (int i = 0; i < 3; i++) {
        printf("Palavra-chave %d: ", i + 1);
        scanf(" %[^\n]", p.palavras_chave[i]);
    }

    printf("Tipo de rede social (1-Instagram, 2-TikTok, 3-LinkedIn): ");
    scanf("%d", &p.tipo_rede);

    printf("Observação sobre o conteúdo: ");
    scanf(" %[^\n]", p.observacao);

    p.data_publicacao = time(NULL);

    posts[*total] = p;
    (*total)++;

    salvar_em_arquivo(posts, *total);

    printf("\nPostagem cadastrada e salva com sucesso! ID único: %d\n", p.id);
}

void exibir_postagem(Postagem p) {
    char data_str[26];
    struct tm *tm_info = localtime(&p.data_publicacao);
    strftime(data_str, 26, "%d/%m/%Y %H:%M:%S", tm_info);

    char *redes[] = {"", "Instagram", "TikTok", "LinkedIn"};

    printf("\n----------------------------------------\n");
    printf("ID: %d\n", p.id);
    printf("Título: %s\n", p.titulo);
    printf("Autor: %s (Matrícula: %d)\n", p.autor, p.matricula);
    printf("Palavras-chave: %s, %s, %s\n", p.palavras_chave[0], p.palavras_chave[1], p.palavras_chave[2]);
    printf("Rede Social: %s\n", (p.tipo_rede >= 1 && p.tipo_rede <= 3) ? redes[p.tipo_rede] : "Desconhecida");
    printf("Data de Publicação: %s\n", data_str);
    printf("Observação: %s\n", p.observacao);
    printf("----------------------------------------\n");
}