import random

def menu():
    print("--------------------------")
    print("Bem-vindo ao jogo do adivinha\nEscolha uma das opções")
    print("1- Adição")
    print("2- Subtração")
    print("3- Multiplicação")
    print("4- Divisão")
    while True:
        try:
            opcao = int(input(": "))
            if 1 <= opcao <= 4:
                break
            else:
                print("Digite um número entre 1 e 4!")
        except ValueError:
            print("Digite um número inteiro válido!")

    print("--------------------------")
    if opcao == 1:
        adicao()
    elif opcao == 2:
        sub()
    elif opcao == 3:
        multi()
    elif opcao == 4:
        divisao()
    else:
        print("Opção invalida!!")

def nivel():
    print("--------------------------")
    print("Escolha o nível do jogo: ")
    print("1- Fácil")
    print("2- Médio")
    print("3- Dificil")
    print("4- Extremo")
    while True:
        try:
            opcaoNivel = int(input(": "))
            if 1 <= opcaoNivel <= 4:
                return opcaoNivel
            else:
                print("Digite um número entre 1 e 4!")
        except ValueError:
            print("Digite um número inteiro válido!")

def adicao():
    nivelEscolhido = nivel()
    contadorAcertos = 0
    contadorWhile = 0
    if nivelEscolhido == 1:
        while contadorWhile < 3:
            n1 = random.randint(1,10)
            n2 = random.randint(1,10)
            res = n1 + n2
            print(f"Qual o número faltante de {n1} + ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 2:
        while contadorWhile < 3:
            n1 = random.randint(1,100)
            n2 = random.randint(1,100)
            res = n1 + n2
            print(f"Qual o número faltante de {n1} + ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile +=1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 3:
        while contadorWhile < 3:
            n1 = random.randint(1,1000)
            n2 = random.randint(1,1000)
            res = n1 + n2
            print(f"Qual o número faltante de {n1} + ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 4:
        while contadorWhile < 3:
            n1 = random.randint(1,100000)
            n2 = random.randint(1,100000)
            res = n1 + n2
            print(f"Qual o número faltante de {n1} + ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")
    else:
        print("Opção invalida!!")

# -------------------------------------
# Subtração
def sub():
    nivelEscolhido = nivel()
    contadorAcertos = 0
    contadorWhile = 0
    if nivelEscolhido == 1:
        while contadorWhile < 3:
            n1 = random.randint(1,10)
            n2 = random.randint(1,10)
            res = n1 - n2
            print(f"Qual o número faltante de {n1} - ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 2:
        while contadorWhile < 3:
            n1 = random.randint(1,100)
            n2 = random.randint(1,100)
            res = n1 - n2
            print(f"Qual o número faltante de {n1} - ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile +=1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 3:
        while contadorWhile < 3:
            n1 = random.randint(1,1000)
            n2 = random.randint(1,1000)
            res = n1 - n2
            print(f"Qual o número faltante de {n1} - ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 4:
        while contadorWhile < 3:
            n1 = random.randint(1,100000)
            n2 = random.randint(1,100000)
            res = n1 - n2
            print(f"Qual o número faltante de {n1} - ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")
    else:
        print("Opção invalida!!")

# -------------------------------------
# Multiplicação
def multi():
    nivelEscolhido = nivel()
    contadorAcertos = 0
    contadorWhile = 0
    if nivelEscolhido == 1:
        while contadorWhile < 3:
            n1 = random.randint(1,10)
            n2 = random.randint(1,10)
            res = n1 * n2
            print(f"Qual o número faltante de {n1} * ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 2:
        while contadorWhile < 3:
            n1 = random.randint(1,100)
            n2 = random.randint(1,100)
            res = n1 * n2
            print(f"Qual o número faltante de {n1} * ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile +=1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 3:
        while contadorWhile < 3:
            n1 = random.randint(1,1000)
            n2 = random.randint(1,1000)
            res = n1 * n2
            print(f"Qual o número faltante de {n1} * ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 4:
        while contadorWhile < 3:
            n1 = random.randint(1,100000)
            n2 = random.randint(1,100000)
            res = n1 * n2
            print(f"Qual o número faltante de {n1} * ? = {res}: ")
            resposta = int(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")
    else:
        print("Opção invalida!!")

# -------------------------------------
# Divisão
def divisao():
    nivelEscolhido = nivel()
    contadorAcertos = 0
    contadorWhile = 0
    if nivelEscolhido == 1:
        while contadorWhile < 3:
            n1 = random.randint(1,10)
            n2 = random.randint(1,10)
            res = n1 / n2
            print(f"Qual o número faltante de {n1} / ? = {res}: ")
            resposta = float(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 2:
        while contadorWhile < 3:
            n1 = random.randint(1,100)
            n2 = random.randint(1,100)
            res = n1 / n2
            print(f"Qual o número faltante de {n1} / ? = {res}: ")
            resposta = float(input(": "))
            contadorWhile +=1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 3:
        while contadorWhile < 3:
            n1 = random.randint(1,1000)
            n2 = random.randint(1,1000)
            res = n1 / n2
            print(f"Qual o número faltante de {n1} / ? = {res}: ")
            resposta = float(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")

    elif nivelEscolhido == 4:
        while contadorWhile < 3:
            n1 = random.randint(1,100000)
            n2 = random.randint(1,100000)
            res = n1 / n2
            print(f"Qual o número faltante de {n1} / ? = {res}: ")
            resposta = float(input(": "))
            contadorWhile += 1
            if resposta == n2:
                contadorAcertos += 1
        print("----Fim de jogo----")
        print(f"Você acertou {contadorAcertos} exercicios!!")
    else:
        print("Opção invalida!!")

if __name__ == "__main__":
    menu()