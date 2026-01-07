#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char op;

/* ===== UTIL ===== */
void getch(){
    system("read b");
}

/* ===== STRUCTS ===== */
typedef struct{
    char logradouro[10];
    char complemento[20];
    char cep[10];
    char bairro[20];
    char cidade[20];
    char estado[3];
} End;

typedef struct{
    int codigo;
    char nome[30];
    char cnpj[20], cpf[20];
    char telefone[10];
    End endereco;
} Cli;

typedef struct{
    int codigo;
    char nome[30];
    char fornecedor[30];
    char categoria[30];
    int quant;
    float valorUnit;
} Prod;

typedef struct{
    int codigo;
    int dia, mes, ano;
    Cli clienteQuePediu;
    Prod *produtoPedido;
    int *qtdProdutoPedido;
    int qtd;
} Ped;

/* ===== PROTÓTIPOS ===== */
void menu();

/* CLIENTES */
void gerenciaDeClientes(Cli*, int*, FILE*);
Cli cadastrarCliente(Cli, int);
void listarCliente(Cli*, int);
void ordenarClientePorOrdemAlfabetica(Cli*, int);
void buscarCliente(Cli*, int);
void atualizarCliente(Cli*, int);
void excluirCliente(Cli*, int);
void imprimirCliente(Cli);

/* PRODUTOS */
void gerenciaDeProdutos(Prod*, int*, FILE*);
Prod cadastrarProduto(Prod, int);
void listarProdutosCadastrados(Prod*, int);
void ordenarProdutoPorNome(Prod*, int);
void filtrarCategoria();
void buscarProdutosCadastrados(Prod*, int);
void atualizarProdutoCadastrado(Prod*, int);
void atualizarEstoqueProduto(Prod*, int);
void imprimirProduto(Prod);

/* PEDIDOS (⚠️ corrigido) */
void gerenciaDePedidos(
    Ped*, Cli*, Prod*,
    int*, int, int
);

void cadastrarPedido(
    Ped*, Cli*, Prod*,
    int*, int, int
);

void obterData(Ped*);
void listarPedidosDeUmCliente(Ped*, int);
void ordenarPedidosPorData(Ped*, int);
void listarPedidosDeUmDia(Ped*, int);
void ordenarPorNomeCliente(Ped*, int);
void imprimirPedido(Ped);

/* ===== MAIN ===== */
int main (){
    FILE *arquivo;
    Prod *produto;
    Cli *cliente;
    Ped *pedido;

    int contCliente = 0;
    int contProduto = 0;
    int contPedido  = 0;

    /* Alocação */
    produto = calloc(10, sizeof(Prod));
    cliente = calloc(10, sizeof(Cli));
    pedido  = calloc(10, sizeof(Ped));

    if (!produto || !cliente || !pedido){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }

    /* Abertura do arquivo */
    arquivo = fopen("dados.bin", "ab+");
    if (arquivo == NULL){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    menu();

    do{
        switch(op){
            case 'C':
            case 'c':
                gerenciaDeClientes(cliente, &contCliente, arquivo);
                break;

            case 'P':
            case 'p':
                gerenciaDeProdutos(produto, &contProduto, arquivo);
                break;

            case 'E':
            case 'e':
                gerenciaDePedidos(
                    pedido,
                    cliente,
                    produto,
                    &contPedido,
                    contCliente,
                    contProduto
                );
                break;

            case 'S':
            case 's':
                fclose(arquivo);
                free(produto);
                free(cliente);
                free(pedido);
                exit(0);

            default:
                printf("!! COMANDO INVALIDO !!\n");
                sleep(2);
                system("clear");
                menu();
        }
    } while (1);

    return 0;
}
