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

void ordenaArray(int array_length, int numeros[] ){
	for (int i = 0; i < array_length; i++){
        for (int j = i + 1; j < array_length; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
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
    ordenaArray(tamanho, array);
}

int** aposta(int linhas, int qd, int** matriz, int type){
    matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(qd * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da matriz.\n");
            return NULL;
        }
    }

    if(type == 1){
        printf("Informe os numeros das apostas manuais (Valores validos de 1 a 60):\n");
        for ( int i=0; i < linhas; i++ ){
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
                matriz[i][j] = nrAposta;
            }
            ordenaArray(qd, matriz[i]);
        }
    }else{
        for (int i=0; i<linhas; i++ ){
            numerosAleatorios(matriz[i], qd);
        }
    }
    
    return matriz;
}

void exibirAposta(int** matriz, int qt_aposta, int qd, char tipo[], int qt_aposta_anterior){
    
    for (int i=0; i<qt_aposta; i++ ){
        printf("\nAposta %d (%s):\n", i + 1 + qt_aposta_anterior, tipo);
        for (int j=0; j<qd; j++ ){
            if(matriz[ i ][ j ] <= 9){
                printf ("[0%d]", matriz[ i ][ j ]);
            }else{
                printf ("[%d]", matriz[ i ][ j ]);
            }
        }
        printf("\n");
    }
}

int valorQuantidadeDezenas(int QD){
    if(QD == 6){
        return 5;
    }else if(QD == 7){
        return 35;
    }else if(QD == 8){
        return 140;
    }else if(QD == 9){
        return 420;
    }else if(QD == 10){
        return 1050;
    }else if(QD == 11){
        return 2310;
    }else if(QD == 12){
        return 4620;
    }else if(QD == 13){
        return 8580;
    }else if(QD == 14){
        return 15015;
    }else if(QD == 15){
        return 25025;
    }
}

int revisarAposta(int QT, int QM, int QS, int QD, int** apostasManuais, int** apostasSurpresinhas){
    printf("Revise suas apostas:\n");

    exibirAposta(apostasManuais, QM, QD, "manual", 0);
    exibirAposta(apostasSurpresinhas, QS, QD, "surpresinha", QM);

    printf("\nTeimosinhas: %d\n", QT);

    int VD = valorQuantidadeDezenas(QD);
    float vl_aposta =  QT * (VD * (QM + QS));

    printf("Valor total as apostas: R$ %.2f\n", vl_aposta);

    return vl_aposta;
}

int compararApostas(int* aposta, int* sorteio, int QD){
    int acertos = 0;

    for(int i = 0; i < QD; i++){
        for(int j = 0; j < 6; j++){
            if(aposta[i] == sorteio[j]){
                acertos ++;
                break;
            }
        }
    }
    
    return acertos;
}

float calcularPremio(int acertos, int QD){
    float vl_sena = 118265926.76;
    float vl_quina = 32797.02;
    float vl_quadra = 834.93;
    // Tabela 2 do exemplo:
    int premios[10][6]= {
        {1, 0 , 0  , 1 , 0  , 1}, // 6 Dezesnas
        {1, 6 , 0  , 2 , 5  , 3}, // 7 Dezesnas
        {1, 12, 15 , 3 , 15 , 6}, // 8 Dezesnas
        {1, 18, 45 , 4 , 30 , 10}, // 9 Dezesnas
        {1, 24, 90 , 5 , 50 , 15}, // 10 Dezesnas
        {1, 30, 150, 6 , 75 , 21}, // 11 Dezesnas
        {1, 36, 225, 7 , 105, 28}, // 12 Dezesnas
        {1, 42, 315, 8 , 140, 36}, // 13 Dezesnas
        {1, 48, 420, 9 , 180, 45}, // 14 Dezesnas
        {1, 54, 540, 10, 225, 55}, // 15 Dezesnas
    };

    if(acertos == 6){
        return (premios[QD - 6][0] * vl_sena) + (premios[QD - 6][1] * vl_quina) + (premios[QD - 6][2] * vl_quadra);
    }else if(acertos == 5){
        return (premios[QD - 6][3] * vl_quina) + (premios[QD - 6][4] * vl_quadra);
    }else if(acertos == 4){
        return premios[QD - 6][5] * vl_quadra;
    }else{
        return 0.0;
    }
}


int sorteio(int** apostasManuais, int** apostasSurpresinhas, int QD, int QM, int QS){
    int dezenas_sorteadas[6];
    numerosAleatorios(dezenas_sorteadas, 6);
    // int dezenas_sorteadas[6] = {1,2,3,4,50,60};

    printf("Dezenas sorteadas:\n\n");
    for(int i=0; i<6; i++ ){
        printf("[%d]", dezenas_sorteadas[i]);
    }
    printf("\n\n");

    float total_aposta = 0;
    for(int i = 0; i < QM; i++){
        int acertos = compararApostas(apostasManuais[i], dezenas_sorteadas, QD);
         
        if(acertos >= 4){
            total_aposta += calcularPremio(acertos, QD);
        }
        if(acertos == 4){
            printf("QUADRA!\n");
        }else if(acertos == 5){
            printf("QUINA!\n");
        }else if(acertos == 6){
            printf("SENA!\n");
        }
    }

    for(int i = 0; i < QS; i++){
        int acertos = compararApostas(apostasSurpresinhas[i], dezenas_sorteadas, QD);

        printf("Aposta %d: %d/6\n", i+1+QM, acertos);
        if(acertos >= 4){
            total_aposta += calcularPremio(acertos, QD);
        }
        if(acertos == 4){
            printf("QUADRA!\n");
        }else if(acertos == 5){
            printf("QUINA!\n");
        }else if(acertos == 6){
            printf("SENA!\n");
        }
    }

    
    return total_aposta;
        
}