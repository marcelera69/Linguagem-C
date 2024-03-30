#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct aluno{
    char nome[20];
    int idade;
    float media;
    struct aluno *prox;
} TipoAluno;

TipoAluno *listaAlunos = NULL;

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

void addAlunoFim(char nome[], int idade, float media){

    TipoAluno *novoAluno = CriarNovoAluno(nome, idade, media);

    if (listaAlunos == NULL)
        listaAlunos = novoAluno;
    else{

        TipoAluno* atual = listaAlunos;

        while (atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novoAluno;
    }
    
}

void addAlunoInicio(char nome[], int idade, float media){
    
    TipoAluno *novoAluno = CriarNovoAluno(nome, idade, media);
    TipoAluno *aux = aloca_aluno();

    aux = listaAlunos;
    listaAlunos = novoAluno;
    novoAluno->prox = aux;
}

void mostrarAlunos(){
    int contador=0;
    TipoAluno *atual = listaAlunos;

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

void removeUltimo (){
    TipoAluno *atual = aloca_aluno();
    TipoAluno *anterior = aloca_aluno();
    
    atual = listaAlunos;
    anterior = listaAlunos;

    if(atual == NULL){
        printf("LISTA VAZIA!!!");
    }
    else{
        if (atual->prox == NULL)
            listaAlunos = NULL;
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

void escolherAddFimOuInicio(char nome[50], int idade, float media){
    char controle;

    printf("Digite 'i' para adicionar no inicio ou 'f' para adicionar no fim: ");
    scanf("%c", &controle);
    if (controle == "i")
        addAlunoInicio(nome, idade, media);
    else if (controle == "f")
        addAlunoFim(nome, idade, media);
        else{
            printf("Digite um caracter valido!!!\n");
            escolherAddFimOuInicio(nome, idade, media);
        }
}

void adicionarAluno(){
    int idade;
    float media;
    char nome[50];
    
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    printf("Digite a idade dele: ");
    scanf("%d", &idade);
    printf("Digite a nota do mesmo: ");
    scanf("%f", &media);
    
    escolherAddFimOuInicio(nome, idade, media);
    system("cls");
}

int main(){

    int opcoes;

    do
    {
        printf("1-Adicionar um aluno na lista \n2-Mostrar alunos \n3-Remover o ultimo aluno \n4-Sair do aplicativo");
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
            printf("*** Fim do aplicativo ***\n\n");
            break;
        
        default:
        system("cls");
        printf("***Digite uma opcao valida !!!***\n\n");
            break;
        }
    } while (opcoes != 4);
    
    return 0;
}
