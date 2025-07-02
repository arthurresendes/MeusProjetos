#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define esperar(segundos) Sleep((segundos) * 1000)
#else
#include <unistd.h>
#define esperar(segundos) sleep(segundos)
#endif

typedef struct{
    int codigo;
    char nome[50];
    char email[50];
    char cpf[20];
    char dataNascimento[20];
    char dataCadastro[20];
}Cliente; 

typedef struct{
    int numero;
    Cliente cliente;
    float saldo;
    float limite;
    float saldoTotal;
}Conta;

void menu();
void infoCliente(Cliente cliente);
void infoConta(Conta conta);
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTransferencia();
void listarContas();
float atualizaSaldoTotal(Conta conta);
Conta buscarContaPorNumero(int numero);
void sacar(Conta conta , float valor); 
void depositar(Conta conta , float valor); 
void transferir(Conta conta_origem, Conta conta_destino , float valor); 

static Conta contas[50];
static int contador_contas = 0;
static int contador_clientes = 0;




int main(){
    menu();
    return 0;
}


void menu(){
    int opcao = 0;
    printf("============================\n");
    printf("========Bem-vindo(a)========\n");
    printf("============Bank============\n");
    printf("============================\n");

    
    printf("Selecione uma opcao abaixo: \n");
    printf("1- Criar conta\n");
    printf("2- Efetuar saque\n");
    printf("3- Efetuar deposito\n");
    printf("4- Efetuar transferencia\n");
    printf("5- Listar contas\n");
    printf("6- Sair\n");
    scanf("%d" , &opcao);
    getchar();

        switch (opcao) {
        case 1:
            criarConta();
            break;
        case 2:
            efetuarSaque();
            break;
        case 3:
            efetuarDeposito();
            break;
        case 4:
            efetuarTransferencia();
            break;
        case 5:
            listarContas();
            break;
        case 6:
            printf("Volte sempre!\n");
            esperar(2);
            exit(0);     
        default:
            printf("Opcao invalida!\n");
            esperar(2);
            break;
    }

    menu(); 
}

void infoCliente(Cliente cliente){
    printf("Codigo: %d\nNome: %s\nData de Nascimento: %s\nCadastro: %s\n" , cliente.codigo, strtok(cliente.nome , "\n"),strtok(cliente.dataNascimento , "\n"),strtok(cliente.dataCadastro , "\n"));

}

void infoConta(Conta conta){
    printf("Numero da conta: %d \nCliente: %s \nData Nascimento: %s \n Data cadastro: %s \n Saldo total: %.2f\n",conta.numero ,strtok(conta.cliente.nome , "\n"),strtok(conta.cliente.dataNascimento , "\n"),strtok(conta.cliente.dataCadastro , "\n") , conta.saldoTotal);
}

void criarConta(){

}

void efetuarSaque(){

}

void efetuarDeposito(){

}

void efetuarTransferencia(){

}

void listarContas(){

}

float atualizaSaldoTotal(Conta conta){
    return conta.saldo + conta.limite;

}

Conta buscarContaPorNumero(int numero){
    Conta c;
    if(contador_contas > 0){
        for(int i = 0 ; i < contador_contas ; i++){
            if(contas[i].numero == numero){
                c = contas[i];
            }
        }
    }
    return c;
}

void sacar(Conta conta , float valor){
    if(valor > 0 && conta.saldoTotal >= valor){
        for(int i =0 ; i < contador_contas; i++){
            if(contas[i].numero == conta.numero){
                if(contas[i].saldo >= valor){
                    contas[i].saldo = contas[i].saldo - valor;
                    contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);
                    printf("Saque efetuado com sucesso\n");
                }
            }
        }

    }else{
        printf("Saque indisponivel. Verifique o seu saldo!\n");
        esperar(2);
        menu();
    }
}

void depositar(Conta conta , float valor){

}

void transferir(Conta conta_origem, Conta conta_destino , float valor){

}