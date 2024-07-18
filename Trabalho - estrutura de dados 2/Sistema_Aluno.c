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
        printf("\n\n");
    }
    
}

void removeUltimo (TipoAluno **listaAlunos){
    TipoAluno *atual = aloca_aluno();
    TipoAluno *anterior = aloca_aluno();
    
    atual = *listaAlunos;
    anterior = *listaAlunos;

    if(atual == NULL){
        printf("LISTA VAZIA!!!\n\n");
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
    printf("Aluno removido da fila com sucesso!\n\n");
}


int main(){

    TipoAluno *listaAlunos = NULL;
    int opcoes, controle;
    char nome[50];
    int idade;
    float mediaNota;
    do
    {
        printf("1-Adicionar um aluno \n2-Mostrar alunos \n3-Remover o ultimo aluno");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcoes);
        switch (opcoes)
        {
        case 1:
            system("cls");
            printf("*** Opcao 1 escolhida ***\n\n");
            printf("Digite o nome: ");
            scanf("%s", nome);
            system("cls");
            printf("Digite a idade: ");
            scanf("%d", &idade);
            system("cls");
            printf("Entre com a media: ");
            scanf("%f", &mediaNota);
            system("cls");

            if (listaAlunos == NULL){
                 addAlunoFim(&listaAlunos, nome, idade, mediaNota);
                 printf("Primeiro aluno adicionado com sucesso!\n");
                 break;
            }

            printf("Deseja adicionar no inicio ou no fim da lista ? (1-Inicio / 2-Fim): ");
            scanf("%d", &controle);

            while (controle == 1 || controle == 2) {
                if (controle == 1) {
                    addAlunoInicio(&listaAlunos, nome, idade, mediaNota);
                    controle = 0;
                    printf("Aluno adicionado no FIM da fila com sucesso!\n\n");
                } else {
                    if (controle == 2) {
                        addAlunoFim(&listaAlunos, nome, idade, mediaNota);
                        controle = 0;
                        printf("Aluno adicionado no INICIO da fila com sucesso!\n\n");
                    } else {
                        printf("DIGITE UM NÚMERO VÁLIDO!!!\n\n");
                    }
                }
            }
            break;

        case 2:
            system("cls");
            printf("*** Opcao 2 escolhida ***\n\n");
            mostrarAlunos(&listaAlunos);
            break;

        case 3:
            system("cls");
            printf("*** Opcao 3 escolhida ***\n\n");
            removeUltimo(&listaAlunos);
            mostrarAlunos(&listaAlunos);
            break;
        
        default:
        system("cls");
        printf("***Digite uma opcao valida !!!***\n\n");
            break;
        }
    } while (opcoes != 5);
    
    return 0;
}
