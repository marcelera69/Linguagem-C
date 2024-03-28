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

void addAlunoFim(TipoAluno **listaAlunos, char nome[], int idade, float media){

    TipoAluno *novoAluno = aloca_aluno();

    strcpy(novoAluno->nome, nome);
    novoAluno->idade = idade;
    novoAluno->media = media;
    novoAluno->prox = NULL;

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
    
    TipoAluno *aux = aloca_aluno();
    TipoAluno *novoAluno = aloca_aluno();


    strcpy(novoAluno->nome, nome);
    novoAluno->idade = idade;
    novoAluno->media = media;
    novoAluno->prox = NULL;

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


int main(){

    TipoAluno *listaAlunos = NULL;
    

    addAlunoFim(&listaAlunos, "Marcelo Soares", 20, 7.9);
    addAlunoFim(&listaAlunos, "Luan Maia", 21, 6.1);

    printf("Primeira lista:\n");
    mostrarAlunos(&listaAlunos);

    addAlunoInicio(&listaAlunos, "Jandrei Jesus", 22, 4.5);
    printf("\n\nSegunda lista lista:\n\n");
    mostrarAlunos(&listaAlunos);


    
    return 0;
}
