#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char op;

void getch(){
    system("read b");
}

typedef struct{
    char logradouro[10];
    char complemento[20];
    char cep[10];
    char bairro[20];
    char cidade[20];
    char estado[3];
}End;

typedef struct{
    int codigo;
    char nome[30];
    char cnpj[20], cpf[20];
    char telefone[10];
    End endereco;
}Cli;

typedef struct{
    int codigo;
    char nome[30];
    char fornecedor[30];
    char categoria[30];
    int quant;
    float valorUnit;
}Prod;

typedef struct{
    int codigo;
    int dia;
    int mes;
    int ano;
    Cli clienteQuePediu;
    Prod *produtoPedido;
    int *qtdProdutoPedido;
    int qtd;
}Ped;

void menu();

void gerenciaDeClientes(Cli*, int*, FILE*);
    Cli cadastrarCliente(Cli, int);
    void listarCliente(Cli*, int);
        void ordenarClientePorOrdemAlfabetica(Cli*, int);
    void buscarCliente(Cli*, int);
    void atualizarCliente(Cli*, int);
    void excluirCliente(Cli*, int);
    void imprimirCliente(Cli);

void gerenciaDeProdutos(Prod*, int*, FILE*);
    Prod cadastrarProduto(Prod, int);
    void listarProdutosCadastrados(Prod*, int);
        void ordenarProdutoPorNome(Prod*, int);
        void filtrarCategoria();
    void buscarProdutosCadastrados(Prod*, int);
    void atualizarProdutoCadastrado(Prod*, int);
    void atualizarEstoqueProduto(Prod*, int);
    void imprimirProduto(Prod);

void gerenciaDePedidos(Ped*, Cli*, int*, int, int);
    void cadastrarPedido(Ped*, Cli*, int*, int, int);
        void obterData(Ped*);
    void listarPedidosDeUmCliente(Ped*, int);
        void ordenarPedidosPorData(Ped*, int);
    void listarPedidosDeUmDia(Ped*, int);
        void ordenarPorNomeCliente(Ped*, int);
    void imprimirPedido(Ped);

int main (){
    FILE *arquivo;
    Prod *produto;
    Cli *cliente;
    Ped *pedido;
    int contCliente=0, contProduto=0, contPedido=0;

    return 0;
}