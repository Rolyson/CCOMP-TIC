#include <stdio.h>

int main(){
  int opcao;
  float mph, kph;

  do{
    printf("\nDigite uma das opcoes abaixo:\n1- Transformar KPH para MPH;\n2- Transformar MPH para KPH.\n");
    scanf("%d", & opcao);
    
    if(opcao == 1){
      printf("\nInforme a velocidade em quilometros por hora: ");
      scanf("%f",& kph);
      mph = kph / 1.609;
      printf("A velocidade em milhas corresponde ah: %.2f\n", mph);
    }else if(opcao == 2){
      printf("\nInforme a velocidade em milhas por hora: ");
      scanf("%f",& mph);
      kph = mph * 1.609;
      printf("A velocidade em quilometros corresponde ah: %.2f\n", kph);
    }
  } while(opcao <= 2);

  printf("Encerrado");

  return 0;
}