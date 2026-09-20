/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   postagem.h - Define a estrutura de dados e protótipos
*/
#ifndef POSTAGEM_H
#define POSTAGEM_H

#include <time.h>

#define MAX_POSTS 100

typedef struct {
    int id;
    char titulo[100];
    char autor[40];
    int matricula;
    char palavras_chave[3][30];
    time_t data_publicacao;
    int tipo_rede; // 1-Instagram; 2-TikTok; 3-LinkedIn
    char observacao[200];
} Postagem;

void cadastrar_postagem(Postagem *posts, int *total);
void exibir_postagem(Postagem p);
void editar_postagem(Postagem *posts, int total);

#endif