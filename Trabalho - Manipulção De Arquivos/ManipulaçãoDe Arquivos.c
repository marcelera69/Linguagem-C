#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    

    float maiorNota=0, menorNota=10, nota, contadorNotas=0, contadorAprovados=0, contadorReprovados=0;
    FILE *arqEntrada, *arqResultado, *arqAprovados, *arqReprovados, *arqPorcentagem;

    arqEntrada = fopen("Notas.txt","r");
    arqResultado = fopen("Resultado.txt", "w");
    arqAprovados = fopen("Aprovados.txt", "w");
    arqReprovados = fopen("Reprovados.txt", "w");
    arqPorcentagem = fopen("Porcentagem.txt", "w");

    if(arqEntrada == NULL){
        printf("error !!!\n");
        return 1;
    } 

    //Parte 1(resultado)
    while (!feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota);
        if(nota > maiorNota){
            maiorNota = nota;
        }
        if (nota < menorNota){
            menorNota = nota;
        }
        contadorNotas++;
    }
    printf("%f  %f", maiorNota, menorNota);
    fprintf(arqResultado, "%f  %f", maiorNota, menorNota);
    rewind(arqEntrada);


    //Parte2 (Aprovados)
    float media = 7.0;
    while (!feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota);  
        if (nota >= media){
            fprintf(arqAprovados, "Aprovado \n");
            contadorAprovados++;
        } else{
            fprintf(arqAprovados, ". \n");
        }
    }
    fprintf(arqAprovados, "Quantidade de Aprovados: %1.f", contadorAprovados);
    rewind(arqEntrada);


    //Parte 3 e 4 (Reprovados)(Porcentagem)
    float somaNotasRep;
    while (!feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota); 
        if (nota < media){
            somaNotasRep += nota;
            contadorReprovados++;
        }
    }
    fprintf(arqReprovados, "Media dos Reprovados: %2.f", somaNotasRep/contadorReprovados);
    fprintf(arqPorcentagem, "Porcentagem de Aprovados: %1.f%%\n", (contadorAprovados/contadorNotas)*100);
    fprintf(arqPorcentagem, "Porcentagem de Aprovados: %1.f%%", (contadorReprovados/contadorNotas)*100);
    rewind(arqEntrada);
    
    fclose(arqEntrada);
    printf("\n\n");
    return 0;
}