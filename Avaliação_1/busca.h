/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   busca.h - Protótipos das funções de busca
*/
#ifndef BUSCA_H
#define BUSCA_H

#include "postagem.h"

void buscar_por_matricula(Postagem *posts, int total, int matricula);
void buscar_por_tipo_rede(Postagem *posts, int total, int tipo);
void buscar_por_intervalo_datas(Postagem *posts, int total, time_t inicio, time_t fim);

#endif