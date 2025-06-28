#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define esperar(segundos) Sleep((segundos) * 1000)
#else
#include <unistd.h>
#define esperar(segundos) sleep(segundos)
#endif

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int *temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main() {
    menu();
    return 0;
}

void infoProduto(Produto prod) {
    printf("Codigo: %d \nNome: %s \nPreco: %.2f\n", prod.codigo, prod.nome, prod.preco);
}

void menu() {
    printf("============================\n");
    printf("========Bem-vindo(a)========\n");
    printf("=======Market Control=======\n");
    printf("============================\n");

    printf("Selecione uma opcao abaixo: \n");
    printf("1- Cadastrar produto\n");
    printf("2- Listar produto\n");
    printf("3- Comprar produto\n");
    printf("4- Visualizar carrinho\n");
    printf("5- Fechar pedido\n");
    printf("6- Sair\n");

    int opcao;
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            printf("Volte sempre!\n");
            esperar(2);
            exit(0);
        default:
            printf("Opcao invalida!\n");
            esperar(2);
    }
    menu();
}

void cadastrarProduto() {
    printf("Cadastro de produto\n");
    printf("===================\n");
    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);
    produtos[contador_produto].nome[strcspn(produtos[contador_produto].nome, "\n")] = '\0';

    printf("Informe o preco do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);
    getchar();

    produtos[contador_produto].codigo = contador_produto + 1;

    printf("O produto %s foi cadastrado com sucesso.\n", produtos[contador_produto].nome);
    contador_produto++;
    esperar(2);
}

void listarProdutos() {
    if (contador_produto > 0) {
        printf("Listagem de produtos.\n");
        printf("---------------------\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produtos[i]);
            printf("---------------------\n");
            esperar(1);
        }
    } else {
        printf("Nao temos registro de produtos cadastrados.\n");
    }
    esperar(2);
}

void comprarProduto() {
    if (contador_produto > 0) {
        printf("Informe o codigo do produto que deseja adicionar ao carrinho.\n");
        printf("===== Produtos disponiveis =====\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produtos[i]);
            printf("---------------------\n");
            esperar(1);
        }

        int codigo;
        scanf("%d", &codigo);
        getchar();

        int tem_mercado = 0;

        for (int i = 0; i < contador_produto; i++) {
            if (produtos[i].codigo == codigo) {
                tem_mercado = 1;

                if (contador_carrinho > 0) {
                    int *retorno = temNoCarrinho(codigo);
                    if (retorno[0] == 1) {
                        carrinho[retorno[1]].quantidade++;
                        printf("Aumentei a quantidade do produto %s ja existente no carrinho.\n", carrinho[retorno[1]].produto.nome);
                    } else {
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produto = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O produto %s foi adicionado ao carrinho.\n", p.nome);
                    }
                } else {
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi adicionado ao carrinho.\n", p.nome);
                }
                esperar(2);
                return;
            }
        }

        if (!tem_mercado) {
            printf("Nao foi encontrado produto com o codigo %d\n", codigo);
            esperar(2);
        }
    } else {
        printf("Nenhum produto cadastrado.\n");
        esperar(2);
    }
}

void visualizarCarrinho() {
    if (contador_carrinho > 0) {
        printf("Produtos no carrinho.\n");
        printf("---------------------\n");
        for (int i = 0; i < contador_carrinho; i++) {
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("---------------------\n");
            esperar(1);
        }
    } else {
        printf("Nao temos produto no carrinho.\n");
    }
    esperar(2);
}

Produto pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < contador_produto; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i];
        }
    }
    Produto p = {0, "", 0.0};
    return p;
}

int *temNoCarrinho(int codigo) {
    static int retorno[] = {0, 0};
    retorno[0] = 0;
    retorno[1] = 0;

    for (int i = 0; i < contador_carrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            retorno[0] = 1;
            retorno[1] = i;
            break;
        }
    }
    return retorno;
}

void fecharPedido() {
    if (contador_carrinho > 0) {
        float valorTotal = 0.0;
        printf("Produtos carrinho\n");
        printf("---------------------\n");
        for (int i = 0; i < contador_carrinho; i++) {
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade: %d\n", quantidade);
            printf("---------------------\n");
            esperar(1);
        }
        printf("Sua fatura eh R$ %.2f\n", valorTotal);

        contador_carrinho = 0;
        printf("Obrigado pela preferencia\n");
        esperar(5);
    } else {
        printf("Sem produtos no carrinho.\n");
        esperar(3);
    }
}
