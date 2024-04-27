#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "megasena.h"

int solicitaValor(char enunciado[], int vl_min, int vl_max){
    int variavel;
    do{
        printf("%s", enunciado);
        scanf("%d", &variavel);
        if(variavel < vl_min || variavel > vl_max){
            printf("Valor invalido!\n");
        }
    }while(variavel < vl_min || variavel > vl_max);

    return variavel;
}

int numeroRepetido(int numero, int array[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == numero) {
            return 1;
        }
    }
    return 0;
}

void numerosAleatorios(int* array, int tamanho){
    for (int i = 0; i < tamanho; i++){
        int numero;
        do{
            numero = 1+ rand() % 60;
        }while(numeroRepetido(numero, array, tamanho));
        array[i] = numero;
    }
}

int** apostaManual(int qm, int qd, int** matriz){
    matriz = (int **)malloc(qm * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        return NULL;
    }

    for (int i = 0; i < qm; i++) {
        matriz[i] = (int *)malloc(qd * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da matriz.\n");
            return NULL;
        }
    }

    printf("Informe os numeros das apostas manuais (Valores validos de 1 a 60):\n");
    for ( int i=0; i < qm; i++ ){
        printf("Aposta %d\n", i+1);
        for (int j=0; j < qd; j++ ){
            int nrAposta, validado;
            do{
                nrAposta = solicitaValor("", 1, 60);
                validado = numeroRepetido(nrAposta, matriz[i] ,qd);

                if(validado){
                    printf("Esse numero ja foi jogado na aposta\n");
                }
            }while(validado);
            matriz[ i ][ j ] = nrAposta;
        }
    }
    
    return matriz;
}

void exibirApostaManual(int** matriz, int qm, int qd){
        for (int i=0; i<qm; i++ ){
            for (int j=0; j<qd; j++ ){
                printf ("[%d]", matriz[ i ][ j ]);
            }
            printf("\n");
        }
}