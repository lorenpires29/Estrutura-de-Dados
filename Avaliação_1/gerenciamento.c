/*
Loren Pires
14/09/26
Avaliação 1 de Estruturas de Dados
Cadastro de postagem em rede social  -   gerenciamento.c - Implementa a edição flexível e a exclusão por ID/Título
*/
#include <stdio.h>
#include <string.h>
#include "gerenciamento.h"
#include "arquivo.h"

void editar_postagem(Postagem *posts, int total) {
    if (total == 0) {
        printf("\nNenhuma postagem cadastrada para editar.\n");
        return;
    }

    int id_busca, encontrado = -1;
    printf("\n--- Editar Postagem ---\n");
    printf("Digite o ID da postagem que deseja editar: ");
    if (scanf("%d", &id_busca) != 1) {
        printf("Entrada inválida!\n");
        scanf("%*[^\n]");
        return;
    }

    for (int i = 0; i < total; i++) {
        if (posts[i].id == id_busca) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Postagem com ID %d não encontrada!\n", id_busca);
        return;
    }

    int opcao;
    do {
        printf("\n--- Editando Postagem [ID: %d] ---\n", posts[encontrado].id);
        printf("1. Título: %s\n", posts[encontrado].titulo);
        printf("2. Nome do Autor: %s\n", posts[encontrado].autor);
        printf("3. Matrícula: %d\n", posts[encontrado].matricula);
        printf("4. Palavras-chave: %s, %s, %s\n", posts[encontrado].palavras_chave[0], posts[encontrado].palavras_chave[1], posts[encontrado].palavras_chave[2]);
        printf("5. Tipo de Rede Social: %d (1-Instagram, 2-TikTok, 3-LinkedIn)\n", posts[encontrado].tipo_rede);
        printf("6. Observação: %s\n", posts[encontrado].observacao);
        printf("0. Salvar alterações e voltar\n");
        printf("Escolha o campo que deseja alterar: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Opção inválida!\n");
            scanf("%*[^\n]");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Novo Título: ");
                scanf(" %[^\n]", posts[encontrado].titulo);
                break;
            case 2:
                printf("Novo Nome do Autor: ");
                scanf(" %[^\n]", posts[encontrado].autor);
                break;
            case 3:
                printf("Nova Matrícula: ");
                scanf("%d", &posts[encontrado].matricula);
                break;
            case 4:
                for (int i = 0; i < 3; i++) {
                    printf("Nova Palavra-chave %d: ", i + 1);
                    scanf(" %[^\n]", posts[encontrado].palavras_chave[i]);
                }
                break;
            case 5:
                printf("Novo Tipo de Rede Social (1-Instagram, 2-TikTok, 3-LinkedIn): ");
                scanf("%d", &posts[encontrado].tipo_rede);
                break;
            case 6:
                printf("Nova Observação: ");
                scanf(" %[^\n]", posts[encontrado].observacao);
                break;
            case 0:
                salvar_em_arquivo(posts, total);
                printf("\nAlterações salvas no arquivo com sucesso!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void excluir_postagem(Postagem *posts, int *total) {
    if (*total == 0) {
        printf("\nNenhuma postagem cadastrada para excluir.\n");
        return;
    }

    int sub;
    printf("\n--- Excluir Postagem ---\n");
    printf("1. Excluir por ID\n");
    printf("2. Excluir por Título\n");
    printf("Escolha o critério: ");
    if (scanf("%d", &sub) != 1) {
        printf("Opção inválida!\n");
        scanf("%*[^\n]");
        return;
    }

    int encontrado = -1;

    if (sub == 1) {
        int id_busca;
        printf("Digite o ID da postagem: ");
        scanf("%d", &id_busca);

        for (int i = 0; i < *total; i++) {
            if (posts[i].id == id_busca) {
                encontrado = i;
                break;
            }
        }
    } else if (sub == 2) {
        char titulo_busca[100];
        printf("Digite o Título exato da postagem: ");
        scanf(" %[^\n]", titulo_busca);

        for (int i = 0; i < *total; i++) {
            if (strcmp(posts[i].titulo, titulo_busca) == 0) {
                encontrado = i;
                break;
            }
        }
    } else {
        printf("Opção inválida!\n");
        return;
    }

    if (encontrado == -1) {
        printf("Postagem não encontrada!\n");
        return;
    }

    for (int i = encontrado; i < *total - 1; i++) {
        posts[i] = posts[i + 1];
    }

    (*total)--;

    // Salva imediatamente após excluir
    salvar_em_arquivo(posts, *total);

    printf("\nPostagem excluída e alterações salvas no arquivo com sucesso!\n");
}