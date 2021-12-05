#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTES 5

struct s_cliente {
    char nome[256];
    char rg[15];
    char cpf[15];
    int idade;
    float saldo;
    char sexo;
};

struct s_cliente clientes[MAX_CLIENTES];
int i;
int n_clientes = 0;


void cadastraCliente(struct s_cliente cliente) {
    clientes[n_clientes] = cliente;
    n_clientes++;
    setlocale(LC_ALL, "Portuguese");
}


struct s_cliente leDados() {
    system("cls");
    struct s_cliente auxiliar;
    printf("\n\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(auxiliar.nome, 256, stdin);
    printf("RG: ");
    fflush(stdin);
    fgets(auxiliar.rg, 15, stdin);
    printf("CPF: ");
    fflush(stdin);
    fgets(auxiliar.cpf, 15, stdin);
    printf("Sexo: ");
    fflush(stdin);
    scanf("%c", &auxiliar.sexo);
    printf("Idade: ");
    fflush(stdin);
    scanf("%d", &auxiliar.idade);

    auxiliar.saldo = 0;

    return auxiliar;
}

void imprimeClientes() {
    system("cls");
    for (i=0; i<n_clientes; i++) {
        printf("Codigo: %d\n", i+1);
        printf("Nome..: %s", clientes[i].nome);
        printf("RG....: %s", clientes[i].rg);
        printf("CPF...: %s", clientes[i].cpf);
        printf("Sexo..: %c", clientes[i].sexo);
        printf("\nIdade.: %d", clientes[i].idade);
        printf("\nSaldo.: %.2f", clientes[i].saldo);
        printf("\n+++++++++++++++++++\n");
    }

    printf("\nAperte qualquer tecla para retornar ao menu principal");
    getch();
}

int menu() {
    fflush(stdin);
    system("cls");
    int opcao;

    printf("\n\n ==== MENU DE OPCOES ====\n");
    printf("0 - SAIR \n");
    printf("1 - INSERIR \n");
    printf("2 - DEPOSITAR \n");
    printf("3 - SACAR \n");
    printf("4 - EXIBIR \n");
    printf("5 - EXCLUIR \n");
    printf("\nO que deseja fazer? ");
    scanf("%d", &opcao);

    return opcao;
}

void depositar(posicao) {// DEPOSITAR DINHEIRO
    int indice  = posicao - 1;
    int i       = 0;
    float valor = 0;
    float saldo = clientes[indice].saldo;

    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosicao invalida, aperte qualquer tecla para voltar ao menu!\n");
        getch();
        return;
    }

    printf("digite o valor do depósito: ");
    scanf("%f", &valor);
    clientes[indice].saldo = saldo + valor;

    system("cls");
}
void sacar(int posicao){ //SACAR DINHEIRO
    int indice  = posicao - 1;
    int i       = 0;
    float valor = 0;
    float saldo = clientes[indice].saldo;

    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosicao invalida, aperte qualquer tecla para voltar ao menu!\n");
        getch();
        return;
    }

    printf("digite o valor do saque: ");

    scanf("%f", &valor);

    // While para evitar saldo negativo
    while (valor > saldo){
        printf("O valor do saque não pode ser maior que o saldo, por favor digite novamente: ");
        scanf("%f", &valor);
    }

    clientes[indice].saldo = clientes[indice].saldo - valor;

    system("cls");

}

void remover(int posicao) {// EXCLUIR CONTA
    system("cls");
    int indice = posicao - 1;
    int i = 0;

    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosicao invalida, aperte qualquer tecla para voltar ao menu!\n");
        getch();
        return;
    }


    if (posicao == n_clientes) {
        n_clientes--;
        return;
    }


    for (i=indice; i<n_clientes; i++) {
        clientes[i] = clientes[i+1];
        system("cls");
    }
    printf("Cliente removido com sucesso");
    printf("Aperte qualquer tecla para retornar ao mennu principal");
    n_clientes--;
    getch();
}


int main()
{
    system("cls");
    int opcao_selecionada;
    int rem = 0;
    struct s_cliente novo_cliente;
    int r;

    do {
        opcao_selecionada = menu();
        switch(opcao_selecionada) {
            case 0: break;

            case 1:
                if (n_clientes == MAX_CLIENTES) {
                    printf("\nBANCO DE DADOS LOTADO!\n");
                    break;
                }
                novo_cliente = leDados();
                cadastraCliente(novo_cliente);
                break;
            case 2:
                printf("Digite a posicao do cliente que deseja realizar o depósito: ");
                scanf("%d", &r);
                depositar(r);
                break;
            case 3:
                printf("Digite a posicao do cliente que deseja realizar o saque: ");
                scanf("%d", &r);
                sacar(r);
                break;
            case 4:
                imprimeClientes();
                break;
            case 5:
                printf("Digite a posicao que deseja excluir: ");
                scanf("%d", &r);
                remover(r);
                break;
            default:
                system("cls");
                printf("----- OPCAO INVALIDA -----");
        }
    }
    while (opcao_selecionada != 0);
    getch();
    return 0;
}

