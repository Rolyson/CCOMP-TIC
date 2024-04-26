#include <stdio.h>
#include <time.h>
#include "megasena.h"

int main() {
    int opcao = 3, QD, QM;

    do{
        QD = solicita_valor("Informe a quantidade de dezenas que deseja jogar na aposta (Valores validos de 6 a 15): ", 6, 15);
        QM = solicita_valor("Informe a quantidade de apostas manuais (Valores validos de 0 a 3): ", 0, 3);
        
        if(QM > 0){
            aposta_manual(QM, QD);
        }
        
    printf("fim");
    }while(opcao <= 2);


    
    return 0;
}