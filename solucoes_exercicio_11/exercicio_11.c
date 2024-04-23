#include <stdio.h>

int main(){
	int numero, resultado;

	do{
		printf("\nInforme o numero de de linhas e colunas no quadriculado: ");
		scanf("%d", &numero);

		if (numero >= 0){
			resultado = (numero * ( numero + 1) * ((2 * numero) + 1)) /6;
			printf("A quantidade de quadrados existente em um quadriculado de %dx%d eh igual a %d\n", numero, numero, resultado);
		}else{
			printf("Informe um numero >= 0");
		}
	}while(resultado > 0);

	printf("Programa encerrado");

	return 0;
}
