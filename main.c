#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fila.h"

// Constantes
enum {
    OP_NAO_SELECIONADO = 0,
    OP_GERAR_SENHA = 1,
    OP_ATENDER = 2,
    OP_SAIR = 3
};

// Protótipos
int menu();
int gerarSenha();

int main() {
    int opcao = OP_NAO_SELECIONADO;
    int numero;
    int deuCerto;

    srand(time(NULL));

    while(opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao) {
            case OP_GERAR_SENHA:
                numero = gerarSenha();
                deuCerto = inserir(numero);
                if(!deuCerto)
                {
                    printf("Fila cheia!\n");
                }
                else
                {
                    printf("Sua senha eh: %d\n", numero);
                }
                break;
            case OP_ATENDER:
                deuCerto = retirar(&numero);
                if(deuCerto)
                {
                    printf("Senha %d guiche 1\n", numero);
                }
                else
                {
                    printf("Fila vazia!\n");
                }
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADO;
    printf("Menu de Opcoes\n");
    printf("1 - Retirar Senha\n");
    printf("2 - Atender Cliente\n");
    printf("3 - Sair\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &op);

    return op;
}

int gerarSenha()
{
    int valor;

    do {
        valor = rand() % 1000;
    } while(existir(valor));

    return valor;
}