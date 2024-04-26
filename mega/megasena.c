#include <stdio.h>
#include <stdlib.h>
#include "megasena.h"

int soma(int num1, int num2) {
    
    return num1 + num2;
}

int solicita_valor(char enunciado[], int vl_min, int vl_max){
    int variavel;
    printf("%s", enunciado);
    scanf("%d", &variavel);

    if(variavel < vl_min || variavel > vl_max){
        printf("Valor invalido!\n");
        solicita_valor(enunciado, vl_min, vl_max);
    }

    return variavel;
}

void aposta_manual(int qm, int qd){
    int matriz[qm][qd];
    char enunciado[] = "Informe o valor (Valores validos de 1 a 60): ";

    for ( int i=0; i < qm; i++ ){
        printf("Aposta %d\n", i+1);
        for (int j=0; j < qd; j++ ){
            // scanf ("%d", &matriz[ i ][ j ]);
            matriz[ i ][ j ] = solicita_valor(enunciado, 1, 60);
        }
    }
    
    for (int i=0; i<qm; i++ ){
        for (int j=0; j<qd; j++ ){
            printf ("[%d]", matriz[ i ][ j ]);
        }
        printf("\n");
    }
}