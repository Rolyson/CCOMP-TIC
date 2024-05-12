#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "megasena.h"


int main() {
    int **apostasManuais, **apostasSurpresinhas;
    int QT = 0, QD = 0, QM = 0, QS = 0;
    char opcao = 1;

    
    QD = solicitaValor("Informe a quantidade de dezenas que deseja jogar na aposta (Valores validos de 6 a 15): ", 6, 15);
    QM = solicitaValor("Informe a quantidade de apostas manuais (Valores validos de 0 a 3): ", 0, 3);
    
    if(QM > 0){
        apostasManuais = aposta(QM, QD, apostasManuais, 1);
    }

    QS = solicitaValor("Digite a quantidade de Surpresinhas que deseja apostar (valores possiveis: 0 a 7): ", 0, 7);

    if(QS > 0){
        apostasSurpresinhas = aposta(QS, QD, apostasSurpresinhas, 2);
    }

    do{
        printf("Digite a quantidade de Teimosinhas (concursos que deseja participar com as mesmas apostas. Valores vAlidos: 1, 2, 4, 8): ");
        scanf("%d", &QT);
    }while(QT != 1 && QT != 2 && QT != 4 && QT != 8);

    float valor_apostas = revisarAposta(QT, QM, QS, QD, apostasManuais, apostasSurpresinhas);
    
    // Não sei o pq mas QT muda para 0 a partir daqui
    int tempQT = QT;

    printf("\nDeseja continuar (S/N)? \n");
    scanf("%s", &opcao);
    
    if(toupper(opcao) == 'N'){
        printf("Obrigado por participar das Loterias Caixa");
        return 0;
    }

    float resultadoAposta[tempQT];
    for(int i = 0; i < tempQT; i++){
        printf("\nConcurso: 000%d\n", i+1);
        resultadoAposta[i] = sorteio(apostasManuais, apostasSurpresinhas, QD, QM, QS);
    }

    printf("\nTotal da aposta:\n%.2f\nTotal dos premios:\n", valor_apostas);
    
    printf("R$ ");
    float valorTotal = 0;
    for(int i = 0; i < tempQT; i++){
        valorTotal += resultadoAposta[i];
        printf("%.2f ", resultadoAposta[i]);
        if((i+1) != tempQT){
            printf("+ ");
        }
    }
    printf(" = %.2f", valorTotal);

    printf("\nValor liquido: %.2f", valorTotal - valor_apostas);

    printf("\nObrigado por participar das Loterias Caixa!");
    
    return 0;
}