/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   gerenciamento.h - Adicionei edição e exclusão
*/
#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include "postagem.h"

void editar_postagem(Postagem *posts, int total);
void excluir_postagem(Postagem *posts, int *total);

#endif