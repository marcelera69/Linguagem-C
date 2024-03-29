#include<stdio.h>
#include<string.h>
#define limite_max 5

//QUESTAO 1 DO EXERCICIO FEITo NA LINHA 72 

struct tipoAluno
{
    char nome[10];
    float nota1;
    float nota2;
    float media;
};

void cadastroAluno (struct tipoAluno alunos[], int *quantidade){
    char nomeAux[10];    
    
    if (*quantidade < limite_max)
    {
        printf("Existem %d aluno(s) na lista\n\n", *quantidade);

        printf("Qual o nome do aluno: ");
        scanf("%s", nomeAux);

        if (*quantidade == 0)
            strcpy(alunos[*quantidade].nome, nomeAux);
        else
            if (strcmp(alunos[*quantidade - 1].nome, nomeAux) == -1)
                strcpy(alunos[*quantidade].nome, nomeAux);
            else
            {
                printf("FAVOR INSEIR EM ORDEM ALFABETICA\n");
                printf("O nome anterior: %s\n",alunos[*quantidade - 1].nome);
                printf("---------------------------------\n\n");
                return;
            }
                
        printf("Qual a nota 1 do aluno: ");
        scanf("%f", &alunos[*quantidade].nota1);

        printf("Qual a nota 2 do aluno: ");
        scanf("%f", &alunos[*quantidade].nota2);

        alunos[*quantidade].media = (alunos[*quantidade].nota1 + alunos[*quantidade].nota2) /2;
        

        *quantidade += 1;
        system("cls");
    }
    else {
        printf("A LISTA ESTA CHEIA !!!\n");
        printf("---------------------------------\n\n");
    }
}


void mostrarAlunos(struct tipoAluno alunos[], int quantidade){ 
    
    int i;

    for ( i = 0; i < quantidade; i++)
    {
        printf("-Aluno %d \nNome: %s \nNota 1: %.1f  Nota 2: %.1f \nMedia Final: %.1f", i+1, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
        printf("\n\n");
    }
    printf("---------------------------------\n\n");

}


int alunosAcimaMedia(struct tipoAluno alunos[], int quantidade, int media){

    int i, contador=0;

    for (i = 0; i < quantidade; i++)
    {
        if (alunos[i].media >= media)
        {
            contador++;
        }
    }
    return contador;
}

//QUETAO 1 DO EXERCICIO (BUSCA BINARIA RECURSIVA)
int buscarAluno(struct tipoAluno alunos[], int inicio, int final, char nome[]){
    int meio;
    
    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (strcmp(nome, alunos[meio].nome) == 0)
            return meio;
        else
            if (strcmp(nome, alunos[meio].nome) == -1){
                final = meio - 1;
                return buscarAluno(alunos, inicio, final, nome);
            }
            else {
                inicio = meio + 1;
                return buscarAluno(alunos, inicio, final, nome);
            }
    }

    return -1;
}

int main(){

    struct tipoAluno alunos[limite_max];
    int comando, quantidadeAlunos=0;
    int media;
    char nome[10];

    do
    {   
        printf("1- Cadastro de Aluno \n2- Mostras Alunos \n3-Calcular alunos acima da media \n4-Buscar nome na lista \n5-Limpar tela \n6-Sair do program \n=");
        scanf("%d", &comando);
        switch (comando)
        {
        case 1:
            system("cls");
            printf("--------Cadastro alunos------- \n");
            cadastroAluno(alunos, &quantidadeAlunos);
            break;

        case 2:
            system("cls");
            printf("--------Mostrar alunos------- \n");
            mostrarAlunos(alunos, quantidadeAlunos);
            break;

        case 3: //QUETAO 1 DO EXERCICIO 
            system("cls");
            printf("------Alunos acima da media------- \n");
            printf("Digite a media: ");
            scanf("%d", &media);

            printf("\n Existem %d aluno(s) acima da media", alunosAcimaMedia(alunos, quantidadeAlunos, media));
            printf("\n---------------------\n\n");
            break;

        case 4: //QUETAO 2 DO EXERCICIO 
            system("cls");
            printf("--------Buscar aluno------- \n");
            printf("Digite o nome a ser procurado: ");
            scanf("%s", nome);

            int inicio = 0;
            if (buscarAluno(alunos, inicio, quantidadeAlunos, nome) == -1)
                printf("O aluno NAO esta presente na lista");
            else
                printf("O aluno se encontra na lista, na posicao %d do vetor\n\n", buscarAluno(alunos, inicio, quantidadeAlunos, nome));
            
            printf("\n---------------------\n\n");
            break;

        case 5:
            system("cls");
            printf("--------Limpar Tela------- \n");
            printf("---------------------------------\n\n");
            break;

        case 6:
            printf("\nFim do programa !!!");
            break;

        default:
            system("cls");
            printf("Tecla invalida!!!\n");
            printf("---------------------------------\n\n");
            break;
        }
    } while (comando != 6);
    

    return 0;
}