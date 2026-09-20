/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   arquivo.h -  manipulação de arquivos
*/
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "postagem.h"

void salvar_em_arquivo(Postagem *posts, int total);
int carregar_do_arquivo(Postagem *posts);

#endif