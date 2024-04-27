#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "megasena.h"


int main() {
    int **apostasManuais, **apostasSurpresinhas;
    int QT, VD, QD, QM, QS;
    char opcao = 1;

    do{
        QD = solicitaValor("Informe a quantidade de dezenas que deseja jogar na aposta (Valores validos de 6 a 15): ", 6, 15);
        QM = solicitaValor("Informe a quantidade de apostas manuais (Valores validos de 0 a 3): ", 0, 3);
        
        if(QM > 0){
            apostasManuais = aposta(QM, QD, apostasManuais, 1);
        }

        QS = solicitaValor("Digite a quantidade de Surpresinhas que deseja apostar (valores possíveis: 0 a 7): ", 0, 3);

        if(QS > 0){
            apostasSurpresinhas = aposta(QS, QD, apostasSurpresinhas, 2);
        }

        exibirApostaManual(apostasManuais, QM, QD);
        exibirApostaManual(apostasSurpresinhas, QS, QD);
        printf("\nDeseja continuar (S/N)? \n");
        scanf("%s", &opcao);
        
    }while(toupper(opcao) != 'N');

    printf("Obrigado por participar das Loterias Caixa");

    
    return 0;
}