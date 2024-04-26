#include <stdio.h>
#include <time.h>
#include "megasena.h"

int main() {
    // int res = soma(10, 5);
    int opcao = 3, QD, QM;
    char str_qt_dezenas[] = "Informe a quantidade de dezenas que deseja jogar na aposta (Valores validos de 6 a 15): ";
    char str_qt_apostas_manuais[] = "Informe a quantidade de apostas manuais (Valores validos de 0 a 3): ";

    do{
        QD = solicita_valor(str_qt_dezenas, 6, 15);
        QM = solicita_valor(str_qt_apostas_manuais, 0, 3);
        
        if(QM > 0){
            // aposta [QM][QD]
            aposta_manual(QM, QD);
        }
        
    printf("fim");
    }while(opcao <= 2);


    
    return 0;
}