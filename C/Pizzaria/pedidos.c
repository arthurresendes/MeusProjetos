#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// Permite apenas números
int apenasNumeros(const char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit((unsigned char)str[i]))
            return 0;
    return 1;
}

// Permite apenas letras e espaços
int apenasLetras(const char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        if (!isalpha((unsigned char)str[i]) && str[i] != ' ')
            return 0;
    return 1;
}

// Permite emails válidos (simplificado)
int apenasEmail(const char *str) {
    int arroba = 0, ponto = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '@') arroba = 1;
        if (arroba && str[i] == '.') ponto = 1;
    }
    return arroba && ponto;
}

// Limpa buffer de entrada
void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Limpa tela
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

typedef struct {
    char email[50];
    char senha[50];
} Usuario;

int main() {
    int menu;
    Usuario usuario = {"", ""};
    char menustr[10];

    char nomePizza[2][50] = {"", ""}, nomeBebida[2][50] = {"", ""}, nomeDoce[2][50] = {"", ""};
    int escolhaPizza[2] = {0, 0}, quantidadePizza[2] = {0, 0};
    int escolhaBebida[2] = {0, 0}, quantidadeBebida[2] = {0, 0};
    int escolhaDoce[2] = {0, 0}, quantidadeDoce[2] = {0, 0};
    float precoPizza[2] = {0.0, 0.0}, precoBebida[2] = {0.0, 0.0}, precoDoce[2] = {0.0, 0.0};
    char email[50], senha[50], confirma[50];
    char complemento[50], cep[10], cpf[15];
    char quantidadePizzaStr[10], quantidadeBebidaStr[10], quantidadeDoceStr[10];
    int querSalgada = 2, querBebida = 2, querDoce = 2, pagamento = 0;
    char nomePagamento[50];
    float total = 0.0;
    int i, n_pizza = 0, n_bebida = 0, n_doce = 0;

    while (1) {
        // Menu principal
        do {
            printf("----------------- \n");
            printf("| 1-Cadastro    | \n");
            printf("| 2-Login       | \n");
            printf("| 3-Cardapio    | \n");
            printf("| 4-Sair        | \n");
            printf("----------------- \n");
            printf("Escolha uma opcao: ");
            fgets(menustr, sizeof(menustr), stdin);
            menustr[strcspn(menustr, "\n")] = '\0';
        } while (!apenasNumeros(menustr) || strlen(menustr) == 0);
        menu = atoi(menustr);

        switch (menu) {
        case 1: // Cadastro
            limparTela();
            // E-mail
            do {
                printf("Digite seu e-mail: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';
                if (!apenasEmail(email) || strlen(email) == 0)
                    printf("Email inválido! Tente novamente.\n");
            } while (strlen(email) == 0 || !apenasEmail(email));
            strcpy(usuario.email, email);

            // CPF
            do {
                printf("Digite seu CPF (11 digitos): ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
                if (strlen(cpf) != 11 || !apenasNumeros(cpf))
                    printf("CPF inválido! Tente novamente.\n");
            } while (strlen(cpf) != 11 || !apenasNumeros(cpf));

            // CEP
            do {
                printf("Digite seu CEP (8 digitos sem traço): ");
                fgets(cep, sizeof(cep), stdin);
                cep[strcspn(cep, "\n")] = '\0';
                if (strlen(cep) != 8 || !apenasNumeros(cep))
                    printf("CEP inválido! Tente novamente.\n");
            } while (strlen(cep) != 8 || !apenasNumeros(cep));

            // Complemento
            do {
                printf("Digite complemento do endereço (pontos populares): ");
                fgets(complemento, sizeof(complemento), stdin);
                complemento[strcspn(complemento, "\n")] = '\0';
                if (strlen(complemento) == 0 || !apenasLetras(complemento))
                    printf("Complemento inválido! Apenas letras e espaços.\n");
            } while (strlen(complemento) == 0 || !apenasLetras(complemento));

            // Senha e confirmação
            do {
                printf("Digite sua senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0';
                printf("Confirme sua senha: ");
                fgets(confirma, sizeof(confirma), stdin);
                confirma[strcspn(confirma, "\n")] = '\0';
                if (strcmp(senha, confirma) != 0 || strlen(senha) == 0 || strlen(confirma) == 0)
                    printf("Senhas diferentes ou campo vazio. Tente novamente.\n\n");
            } while (strcmp(senha, confirma) != 0 || strlen(senha) == 0);
            strcpy(usuario.senha, senha);

            printf("Cadastro realizado com sucesso! Bem-vindo ao PizzaControl, %s!\n", usuario.email);
            break;

        case 2: // Login e pedido
            limparTela();
            // Login
            do {
                printf("Digite seu e-mail: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';
            } while (strlen(email) == 0);

            do {
                printf("Digite sua senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0';
            } while (strlen(senha) == 0);

            // Validação simples (apenas um usuário em memória)
            if (strcmp(usuario.email, email) != 0 || strcmp(usuario.senha, senha) != 0) {
                printf("Email ou senha inválidos! Faça o cadastro ou tente novamente.\n");
                break;
            }
            printf("Bom ter voce de volta ao PizzaControl, %s!\n", usuario.email);

            // Escolha de pizzas salgadas (até 2 diferentes)
            do {
                printf("Deseja Pizza salgada? (1-Sim / 2-Nao): ");
                fgets(menustr, sizeof(menustr), stdin);
                menustr[strcspn(menustr, "\n")] = '\0';
                querSalgada = atoi(menustr);
            } while (querSalgada < 1 || querSalgada > 2 || strlen(menustr) == 0 || !apenasNumeros(menustr));

            n_pizza = 0;
            if (querSalgada == 1) {
                for (i = 0; i < 2; i++) {
                    printf("---------------------------- \n");
                    printf("| 1-Frango catupiry--50 R$ | \n");
                    printf("| 2-Calabresa--50 R$       | \n");
                    printf("| 3-Mussarela--50 R$       | \n");
                    printf("| 4-Quatro queijos--50 R$  | \n");
                    printf("| 5-Portuguesa--50 R$      | \n");
                    printf("---------------------------- \n");
                    printf("Escolha sua pizza salgada %d (0 para parar): ", i + 1);
                    fgets(menustr, sizeof(menustr), stdin);
                    menustr[strcspn(menustr, "\n")] = '\0';
                    escolhaPizza[i] = atoi(menustr);
                    if (escolhaPizza[i] == 0) break;
                    if (escolhaPizza[i] < 1 || escolhaPizza[i] > 5) {
                        printf("Opção inválida.\n");
                        i--;
                        continue;
                    }
                    switch (escolhaPizza[i]) {
                        case 1: strcpy(nomePizza[i], "Frango com catupiry"); break;
                        case 2: strcpy(nomePizza[i], "Calabresa"); break;
                        case 3: strcpy(nomePizza[i], "Mussarela"); break;
                        case 4: strcpy(nomePizza[i], "Quatro queijos"); break;
                        case 5: strcpy(nomePizza[i], "Portuguesa"); break;
                    }
                    do {
                        printf("Quantas %s voce deseja? ", nomePizza[i]);
                        fgets(quantidadePizzaStr, sizeof(quantidadePizzaStr), stdin);
                        quantidadePizzaStr[strcspn(quantidadePizzaStr, "\n")] = '\0';
                    } while (strlen(quantidadePizzaStr) == 0 || !apenasNumeros(quantidadePizzaStr));
                    quantidadePizza[i] = atoi(quantidadePizzaStr);
                    precoPizza[i] = 50.0 * quantidadePizza[i];
                    n_pizza++;
                }
            } else {
                quantidadePizza[0] = quantidadePizza[1] = 0;
                precoPizza[0] = precoPizza[1] = 0.0;
            }

            // Escolha de bebidas (até 2 diferentes)
            do {
                printf("Deseja bebida? (1-Sim / 2-Nao): ");
                fgets(menustr, sizeof(menustr), stdin);
                menustr[strcspn(menustr, "\n")] = '\0';
                querBebida = atoi(menustr);
            } while (querBebida < 1 || querBebida > 2 || strlen(menustr) == 0 || !apenasNumeros(menustr));

            n_bebida = 0;
            if (querBebida == 1) {
                for (i = 0; i < 2; i++) {
                    printf("----------------------------- \n");
                    printf("| 1-Coca-Cola--12 R$        | \n");
                    printf("| 2-Guarana--11 R$          | \n");
                    printf("| 3-Suco de laranja--10 R$  | \n");
                    printf("| 4-Agua--8 R$              | \n");
                    printf("----------------------------- \n");
                    printf("Escolha sua bebida %d (0 para parar): ", i + 1);
                    fgets(menustr, sizeof(menustr), stdin);
                    menustr[strcspn(menustr, "\n")] = '\0';
                    escolhaBebida[i] = atoi(menustr);
                    if (escolhaBebida[i] == 0) break;
                    if (escolhaBebida[i] < 1 || escolhaBebida[i] > 4) {
                        printf("Opção inválida.\n");
                        i--;
                        continue;
                    }
                    switch (escolhaBebida[i]) {
                        case 1: strcpy(nomeBebida[i], "Coca-Cola"); precoBebida[i] = 12.0; break;
                        case 2: strcpy(nomeBebida[i], "Guarana"); precoBebida[i] = 11.0; break;
                        case 3: strcpy(nomeBebida[i], "Suco de laranja"); precoBebida[i] = 10.0; break;
                        case 4: strcpy(nomeBebida[i], "Agua"); precoBebida[i] = 8.0; break;
                    }
                    do {
                        printf("Quantas %s voce deseja? ", nomeBebida[i]);
                        fgets(quantidadeBebidaStr, sizeof(quantidadeBebidaStr), stdin);
                        quantidadeBebidaStr[strcspn(quantidadeBebidaStr, "\n")] = '\0';
                    } while (strlen(quantidadeBebidaStr) == 0 || !apenasNumeros(quantidadeBebidaStr));
                    quantidadeBebida[i] = atoi(quantidadeBebidaStr);
                    precoBebida[i] = precoBebida[i] * quantidadeBebida[i];
                    n_bebida++;
                }
            } else {
                quantidadeBebida[0] = quantidadeBebida[1] = 0;
                precoBebida[0] = precoBebida[1] = 0.0;
            }

            // Escolha de doces (até 2 diferentes)
            do {
                printf("Deseja Pizza doce? (1-Sim / 2-Nao): ");
                fgets(menustr, sizeof(menustr), stdin);
                menustr[strcspn(menustr, "\n")] = '\0';
                querDoce = atoi(menustr);
            } while (querDoce < 1 || querDoce > 2 || strlen(menustr) == 0 || !apenasNumeros(menustr));

            n_doce = 0;
            if (querDoce == 1) {
                for (i = 0; i < 2; i++) {
                    printf("----------------------------- \n");
                    printf("| 1-Chocolate--50 R$        | \n");
                    printf("| 2-Prestigio--55 R$        |\n");
                    printf("| 3-RomeuJulieta--55 R$     | \n");
                    printf("| 4-Brigadeiro--50 R$       |\n");
                    printf("----------------------------- \n");
                    printf("Escolha sua pizza doce %d (0 para parar): ", i + 1);
                    fgets(menustr, sizeof(menustr), stdin);
                    menustr[strcspn(menustr, "\n")] = '\0';
                    escolhaDoce[i] = atoi(menustr);
                    if (escolhaDoce[i] == 0) break;
                    if (escolhaDoce[i] < 1 || escolhaDoce[i] > 4) {
                        printf("Opção inválida.\n");
                        i--;
                        continue;
                    }
                    switch (escolhaDoce[i]) {
                        case 1: strcpy(nomeDoce[i], "Chocolate"); precoDoce[i] = 50.0; break;
                        case 2: strcpy(nomeDoce[i], "Prestigio"); precoDoce[i] = 55.0; break;
                        case 3: strcpy(nomeDoce[i], "RomeuJulieta"); precoDoce[i] = 55.0; break;
                        case 4: strcpy(nomeDoce[i], "Brigadeiro"); precoDoce[i] = 50.0; break;
                    }
                    do {
                        printf("Quantas %s voce deseja? ", nomeDoce[i]);
                        fgets(quantidadeDoceStr, sizeof(quantidadeDoceStr), stdin);
                        quantidadeDoceStr[strcspn(quantidadeDoceStr, "\n")] = '\0';
                    } while (strlen(quantidadeDoceStr) == 0 || !apenasNumeros(quantidadeDoceStr));
                    quantidadeDoce[i] = atoi(quantidadeDoceStr);
                    precoDoce[i] = precoDoce[i] * quantidadeDoce[i];
                    n_doce++;
                }
            } else {
                quantidadeDoce[0] = quantidadeDoce[1] = 0;
                precoDoce[0] = precoDoce[1] = 0.0;
            }

            if ((n_pizza == 0) && (n_bebida == 0) && (n_doce == 0)) {
                printf("Nenhum pedido registrado.\n");
                break;
            }

            // Pagamento
            do {
                printf("Metodo de pagamento\n");
                printf("---------------- \n");
                printf("| 1--Credito   | \n");
                printf("| 2--Debito    | \n");
                printf("| 3--PIX       | \n");
                printf("| 4--Dinheiro  | \n");
                printf("---------------- \n");
                fgets(menustr, sizeof(menustr), stdin);
                menustr[strcspn(menustr, "\n")] = '\0';
                pagamento = atoi(menustr);
            } while (pagamento < 1 || pagamento > 4 || strlen(menustr) == 0 || !apenasNumeros(menustr));
            switch (pagamento) {
                case 1: strcpy(nomePagamento, "Credito"); break;
                case 2: strcpy(nomePagamento, "Debito"); break;
                case 3: strcpy(nomePagamento, "PIX"); break;
                case 4: strcpy(nomePagamento, "Dinheiro"); break;
            }

            // Resumo
            printf("\n--- RESUMO DO PEDIDO ---\n");
            printf("Email: %s\n", usuario.email);
            total = 0;
            for (i = 0; i < n_pizza; i++)
                printf("Pizza salgada: %d %s, preco = %.2f\n", quantidadePizza[i], nomePizza[i], precoPizza[i]), total += precoPizza[i];
            if (n_pizza == 0) printf("Sem pizza salgada.\n");
            for (i = 0; i < n_bebida; i++)
                printf("Bebida: %d %s, preco = %.2f\n", quantidadeBebida[i], nomeBebida[i], precoBebida[i]), total += precoBebida[i];
            if (n_bebida == 0) printf("Sem bebida.\n");
            for (i = 0; i < n_doce; i++)
                printf("Pizza doce: %d %s, preco = %.2f\n", quantidadeDoce[i], nomeDoce[i], precoDoce[i]), total += precoDoce[i];
            if (n_doce == 0) printf("Sem pizza doce.\n");
            printf("Total do pedido: %.2f\n", total);
            printf("Metodo de pagamento: %s\n", nomePagamento);
            printf("------------------------\n");
            break;

        case 3:
            printf("Pizza salgada: \n");
            printf("---------------------------- \n");
            printf("| 1-Frango catupiry--50 R$ | \n");
            printf("| 2-Calabresa--50 R$       | \n");
            printf("| 3-Mussarela--50 R$       | \n");
            printf("| 4-Quatro queijos--50 R$  | \n");
            printf("| 5-Portuguesa--50 R$      | \n");
            printf("---------------------------- \n");
            printf("Pizza doce: \n");
            printf("----------------------------- \n");
            printf("| 1-Chocolate--50 R$        | \n");
            printf("| 2-Prestigio--55 R$        |\n");
            printf("| 3-RomeuJulieta--55 R$     | \n");
            printf("| 4-Brigadeiro--50 R$       |\n");
            printf("----------------------------- \n");
            printf("Bebidas: \n");
            printf("----------------------------- \n");
            printf("| 1-Coca-Cola--12 R$        | \n");
            printf("| 2-Guarana--11 R$          | \n");
            printf("| 3-Suco de laranja--10 R$  | \n");
            printf("| 4-Agua--8 R$              | \n");
            printf("----------------------------- \n");
            printf("Esse é nosso cardápio, se quiser fazer o pedido faça login ou se cadastre-se. (1-Menu para pedido / 2-Sair)\n");
            fgets(menustr, sizeof(menustr), stdin);
            if (atoi(menustr) != 1) {
                printf("Obrigado por visitar a PizzaControl!\n");
                return 0;
            }
            break;

        case 4:
            printf("Obrigado por visitar a PizzaControl!\n");
            return 0;
        default:
            printf("Opção inválida.\n");
        }
    }
    return 0;
}