#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tarefa {
    char descricao[100];
};

void bordaMenu() {
    printf("====================================\n");
}

int main() {
    struct tarefa *lista = NULL;
    int i, quantidade = 0, totalTarefas = 0, opcao;

    do {
        bordaMenu();
        printf("Bem-vindo ao To-Do List\n");
        printf("1 -- Anotar tarefas\n");
        printf("2 -- Remover tarefas\n");
        printf("3 -- Mostrar tarefas\n");
        printf("0 -- Sair\n");
        bordaMenu();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar '\n'

        switch (opcao) {
            case 1:
                printf("Quantas tarefas deseja adicionar? ");
                scanf("%d", &quantidade);
                getchar();

                lista = realloc(lista, (totalTarefas + quantidade) * sizeof(struct tarefa));
                if (lista == NULL) {
                    printf("Erro ao alocar memória!\n");
                    return 1;
                }

                for (i = 0; i < quantidade; i++) {
                    printf("Digite a tarefa %d: ", totalTarefas + 1);
                    fgets(lista[totalTarefas].descricao, 100, stdin);
                    lista[totalTarefas].descricao[strcspn(lista[totalTarefas].descricao, "\n")] = '\0';
                    totalTarefas++;
                }
                break;

            case 2:
                if (totalTarefas == 0) {
                    printf("Nenhuma tarefa para remover.\n");
                    break;
                }

                printf("Tarefas atuais:\n");
                for (i = 0; i < totalTarefas; i++) {
                    printf("%d. %s\n", i + 1, lista[i].descricao);
                }

                int remover;
                printf("Digite o número da tarefa que deseja remover: ");
                scanf("%d", &remover);
                getchar();

                if (remover < 1 || remover > totalTarefas) {
                    printf("Número inválido.\n");
                } else {
                    // Move os elementos para "tapar o buraco"
                    for (i = remover - 1; i < totalTarefas - 1; i++) {
                        lista[i] = lista[i + 1];
                    }
                    totalTarefas--;

                    // Realoca para reduzir o tamanho
                    lista = realloc(lista, totalTarefas * sizeof(struct tarefa));
                    printf("Tarefa removida com sucesso!\n");
                }
                break;

            case 3:
                if (totalTarefas == 0) {
                    printf("Nenhuma tarefa cadastrada.\n");
                } else {
                    printf("\nTarefas:\n");
                    for (i = 0; i < totalTarefas; i++) {
                        printf("%d. %s\n", i + 1, lista[i].descricao);
                    }
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    free(lista);
    return 0;
}
