/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   menu.c - Executa o loop e as opções do menu principal
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "postagem.h"
#include "ordenacao.h"
#include "busca.h"
#include "arquivo.h"
#include "gerenciamento.h"
#include "menu.h"

void executar_menu() {
    Postagem posts[MAX_POSTS];
    int total = 0;

    total = carregar_do_arquivo(posts);
    int opcao;

    do {
        printf("\n========================================\n");
        printf("      SISTEMA DE REDES SOCIAIS          \n");
        printf("========================================\n");
        printf("1. Cadastrar postagem\n");
        printf("2. Listar postagens\n");
        printf("3. Buscar postagens\n");
        printf("4. Editar postagem\n");
        printf("5. Excluir postagem\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida! Digite um número.\n");
            scanf("%*[^\n]"); // Limpa o buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrar_postagem(posts, &total);
                break;
            case 2: {
                if (total == 0) {
                    printf("\nNenhuma postagem cadastrada.\n");
                    break;
                }
                int sub;
                printf("\n--- LISTAGEM ---\n");
                printf("1. Por Título (Alfabética Crescente)\n");
                printf("2. Por Autor (Alfabética Decrescente)\n");
                printf("3. Por Rede Social e Data (Crescentes)\n");
                printf("Escolha o critério: ");
                scanf("%d", &sub);

                Postagem temp[MAX_POSTS];
                for (int i = 0; i < total; i++) temp[i] = posts[i];

                if (sub == 1) {
                    ordenar_por_titulo_crescente(temp, total);
                    for (int i = 0; i < total; i++) exibir_postagem(temp[i]);
                } else if (sub == 2) {
                    ordenar_por_autor_decrescente(temp, total);
                    for (int i = 0; i < total; i++) exibir_postagem(temp[i]);
                } else if (sub == 3) {
                    ordenar_por_rede_e_data(temp, 0, total - 1);
                    for (int i = 0; i < total; i++) exibir_postagem(temp[i]);
                } else {
                    printf("Opção inválida!\n");
                }
                break;
            }
            case 3: {
                if (total == 0) {
                    printf("\nNenhuma postagem cadastrada.\n");
                    break;
                }
                int sub;
                printf("\n--- BUSCA ---\n");
                printf("1. Por Matrícula do Autor\n");
                printf("2. Por Tipo de Rede Social (Exibe Títulos)\n");
                printf("3. Por Intervalo de Datas (DD/MM/AAAA)\n");
                printf("Escolha o critério: ");
                scanf("%d", &sub);

                if (sub == 1) {
                    int mat;
                    printf("Digite a matrícula: ");
                    scanf("%d", &mat);
                    buscar_por_matricula(posts, total, mat);
                } else if (sub == 2) {
                    int rede;
                    printf("Digite a rede (1-Instagram, 2-TikTok, 3-LinkedIn): ");
                    scanf("%d", &rede);
                    buscar_por_tipo_rede(posts, total, rede);
                } else if (sub == 3) {
                    int d1, m1, a1, d2, m2, a2;
                    printf("Data Inicial (DD MM AAAA): ");
                    scanf("%d %d %d", &d1, &m1, &a1);
                    printf("Data Final (DD MM AAAA): ");
                    scanf("%d %d %d", &d2, &m2, &a2);

                    struct tm tm_ini = {0};
                    tm_ini.tm_mday = d1;
                    tm_ini.tm_mon = m1 - 1;
                    tm_ini.tm_year = a1 - 1900;

                    struct tm tm_fim = {0};
                    tm_fim.tm_mday = d2;
                    tm_fim.tm_mon = m2 - 1;
                    tm_fim.tm_year = a2 - 1900;
                    tm_fim.tm_hour = 23;
                    tm_fim.tm_min = 59;
                    tm_fim.tm_sec = 59;

                    time_t inicio = mktime(&tm_ini);
                    time_t fim = mktime(&tm_fim);

                    buscar_por_intervalo_datas(posts, total, inicio, fim);
                } else {
                    printf("Opção inválida!\n");
                }
                break;
            }
            case 4:
                editar_postagem(posts, total);
                break;
            case 5:
                excluir_postagem(posts, &total);
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}