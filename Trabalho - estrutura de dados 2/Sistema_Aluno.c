#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct aluno{
    char nome[20];
    int idade;
    float media;
    struct aluno *prox;
} TipoAluno;

TipoAluno* aloca_aluno(){

    TipoAluno *novo_aluno = (TipoAluno*)malloc(sizeof(TipoAluno));

    if (novo_aluno == NULL){
        printf("Erro ao alocar memoria !!!");
        exit(1);
    }

    return novo_aluno;
}

TipoAluno* CriarNovoAluno (char nome[], int idade, float media){

    TipoAluno *novoAluno = aloca_aluno();
    
    strcpy(novoAluno->nome, nome);
    novoAluno->idade = idade;
    novoAluno->media = media;
    novoAluno->prox = NULL;

    return novoAluno;
}

void addAlunoFim(TipoAluno **listaAlunos, char nome[], int idade, float media){

    TipoAluno *novoAluno = CriarNovoAluno(nome, idade, media);

    if (*listaAlunos == NULL)
        *listaAlunos = novoAluno;
    else{

        TipoAluno* atual = *listaAlunos;

        while (atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novoAluno;
    }
    
}

void addAlunoInicio(TipoAluno **listaAlunos, char nome[], int idade, float media){
    
    TipoAluno *novoAluno = CriarNovoAluno(nome, idade, media);
    TipoAluno *aux = aloca_aluno();

    aux = *listaAlunos;
    *listaAlunos = novoAluno;
    novoAluno->prox = aux;
}

void mostrarAlunos(TipoAluno **listaAlunos){
    int contador=0;
    TipoAluno *atual = *listaAlunos;

    if (atual == NULL)
        printf("LISTA VAZIA!!!");

    else{
        while (atual != NULL){
            contador++;
            printf("  ->  Aluno %d: %s, idade: %d, nota: %.1f", contador, atual->nome, atual->idade, atual->media);
            atual = atual->prox;
        }
    }
    
}

void removeUltimo (TipoAluno **listaAlunos){
    TipoAluno *atual = aloca_aluno();
    TipoAluno *anterior = aloca_aluno();
    
    atual = *listaAlunos;
    anterior = *listaAlunos;

    if(atual == NULL){
        printf("LISTA VAZIA!!!");
    }
    else{
        if (atual->prox == NULL)
            *listaAlunos = NULL;
        else{

            atual = atual->prox;
            if (atual->prox == NULL)
                anterior->prox = NULL;

            else{

                while (atual->prox != NULL){
                    atual = atual->prox;
                    anterior = anterior->prox;
                }
                anterior->prox = NULL;
            }
        }
    }
}

void adicionarAluno(){
    int idade;
    float media;
    char nome[50];

    printf("Digite com o nome do aluno: ");
    scanf("%s", nome);
    printf("Digite com o nome do aluno: ");
    scanf("%d", &idade);
    printf("Digite com o nome do aluno: ");
    scanf("%s", nome);
    
    
}

int main(){

    TipoAluno *listaAlunos = NULL;
    int opcoes;

    do
    {
        printf("1-Adicionar um aluno no inicio \n2-Adicionar um aluno no fim \n2-Mostrar alunos \n4-Remover o ultimo aluno \n5-Sair do aplicativo");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcoes);
        switch (opcoes)
        {
        case 1:
            system("cls");
            printf("*** Opcao 1 escolhida ***\n\n");
            adicionarAluno();
            break;

        case 2:
            system("cls");
            printf("*** Opcao 2 escolhida ***\n\n");
            break;

        case 3:
            system("cls");
            printf("*** Opcao 3 escolhida ***\n\n");
            break;

        case 4:
            system("cls");
            printf("*** Opcao 4 escolhida ***\n\n");
            break;

        case 5:
            system("cls");
            printf("*** App finalizado ***\n\n");
            break;
        
        default:
        system("cls");
        printf("***Digite uma opcao valida !!!***\n\n");
            break;
        }
    } while (opcoes != 5);
    
    return 0;
}
