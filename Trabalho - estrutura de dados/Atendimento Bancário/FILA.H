#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTES 5

typedef struct
{
    char nome[50];
} Cliente;

typedef struct
{
    Cliente fila[MAX_CLIENTES];
    int inicio;
    int fim;
    int total;
} FilaClientes;


void qinit(FilaClientes *fila);
int qisEmpty(FilaClientes *fila);
int qisFull(FilaClientes *fila);
void enqueue(FilaClientes *fila);
void dequeue(FilaClientes *fila);


void qinit(FilaClientes *fila)
{
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

int qisEmpty(FilaClientes *fila)
{
    return (fila->total == 0);
}

int qisFull(FilaClientes *fila)
{
    return (fila->total == MAX_CLIENTES);
}

void enqueue(FilaClientes *fila)
{
    if (qisFull(fila))
    {
        printf("\n\n !!!LIMITES DE CLIENTES ALCANCADO !!!\n\n");
        sleep(3);
        system("cls");
        return;
    }

    Cliente novoCliente;
    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);
    
    fila->fila[fila->fim] = novoCliente;
    fila->fim++;
    fila->total++;

    printf("\n===== NOME CADASTRADO NA FILA NORMAL =====\n");
}

void dequeue(FilaClientes *fila)
{
    if (qisEmpty(fila))
    {
        printf("Erro: fila vazia.\n");
        return;
    }

    Cliente cliente = fila->fila[fila->inicio];
    printf("Cliente %s liberado para atendimento.\n", cliente.nome);

    // para tirar a pessoa do início da fila
    for (int i = 0; i < fila->fim - 1; i++)
    {
        fila->fila[i] = fila->fila[i + 1];
    }
    fila->fim--;
    fila->total--;
}