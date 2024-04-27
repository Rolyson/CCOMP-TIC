#include <stdio.h>
#include <stdlib.h>
#include "megasena.h"

int solicita_valor(char enunciado[], int vl_min, int vl_max){
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

void aposta_manual(int qm, int qd){
    int matriz[qm][qd];
    printf("Informe o valor (Valores validos de 1 a 60):\n");
    for ( int i=0; i < qm; i++ ){
        printf("Aposta %d\n", i+1);
        for (int j=0; j < qd; j++ ){
            int nrAposta, validado;
            do{
                nrAposta = solicita_valor("", 1, 60);
                validado = numeroRepetido(nrAposta, matriz[i] ,qd);

                if(validado){
                    printf("Esse numero ja foi jogado na aposta\n");
                }
            }while(validado);
            matriz[ i ][ j ] = nrAposta;
        }
    }
    
    for (int i=0; i<qm; i++ ){
        for (int j=0; j<qd; j++ ){
            printf ("[%d]", matriz[ i ][ j ]);
        }
        printf("\n");
    }
}