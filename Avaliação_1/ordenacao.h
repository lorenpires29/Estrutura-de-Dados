/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   ordenacao.h - Protótipos dos algoritmos de ordenação
*/
#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "postagem.h"

// Algoritmo básico (Inserção)
void ordenar_por_titulo_crescente(Postagem *posts, int total);

// Algoritmo básico (Seleção)
void ordenar_por_autor_decrescente(Postagem *posts, int total);

// Algoritmo sofisticado (QuickSort)
void ordenar_por_rede_e_data(Postagem *posts, int baixo, int alto);

#endif