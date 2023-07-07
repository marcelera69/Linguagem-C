#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "FILA.H.H"

int main()
{

    FilaClientes filaNormal, filaPrioritaria;
    qinit(&filaNormal);
    qinit(&filaPrioritaria);
    int opcao;
    char letra;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar Atendimento Comum\n");
        printf("2. Cadastrar Prioridade\n");
        printf("3. Liberar Atendimento\n");
        printf("4. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            letra = 's';

            system("cls");
            printf("\n       Opcao 1 selecionada: cadastrar atendimento comum.\n");
            enqueue(&filaNormal);

            while (letra != 'n')
            {
                printf("\n       deseja cadastrar outro cliente ? (s/n)\n");
                scanf("%c", &letra);
                system("cls");
                if (letra == 's')
                {
                    enqueue(&filaNormal);
                }
            }
            system("cls");
            break;

        case 2:
            letra = 's';

            system("cls");
            printf("\n       ====Opcao 2 selecionada: cadastrar prioridade====.\n\n");
            enqueue(&filaPrioritaria);

            while (letra != 'n')
            {
                printf("\n       deseja cadastrar outro cliente ? (s/n)\n");
                scanf("%c", &letra);
                system("cls");
                if (letra == 's')
                {
                    enqueue(&filaPrioritaria);
                }
            }
            system("cls");
            break;

        case 3:
            letra = 's';
            int i;

            while (letra != 'n')
            {
                system("cls");
                printf("Liberando atendimento NORMAL :\n");
                if (filaNormal.total == 0)
                {
                    printf("Sem clientes na fila normal.\n");
                }
                else if (filaNormal.total < 2)
                {
                    sleep(5);
                    dequeue(&filaNormal);
                }
                else
                {
                    for (i = 0; i < 2; i++)
                    {
                        sleep(5);
                        dequeue(&filaNormal);
                        sleep(2);
                    }
                }

                printf("\n\nLiberando atendimento PRIORITARIO :\n");
                if (filaPrioritaria.total == 0)
                {
                    printf("Sem clientes na fila prioritaria.\n");
                }
                else
                {
                    sleep(5);
                    dequeue(&filaPrioritaria);
                }

                printf("\nDeseja proseguir ? (S/N)\n");
                scanf(" %c", &letra);

                system("cls");
            }
            break;

        case 4:
            system("cls");
            printf("\n \n\n\n\n      ====Opcao 4 selecionada: sair.====\n");
            return 0; // encerrar o programa

        default:
            printf("\n      ====Opcao invalida. Tente novamente====.\n");
            sleep(3);
            system("cls");
            break;
        }
    }

    return 0;
}